#include <stdlib.h>
#include <SDL/SDL.h>

void DrawPixel(SDL_Surface *screen, Uint8 R, Uint8 G, Uint8 B, int x, int y);

int main(int argc, char *argv[])
{
    if(SDL_Init(SDL_INIT_AUDIO|SDL_INIT_VIDEO) < 0)
    {
        fprintf(stderr, "Unable to init SDL: %s\n", SDL_GetError());
        exit(1);
    }
    atexit(SDL_Quit);

    SDL_Surface *screen = SDL_SetVideoMode(640, 480, 16, SDL_SWSURFACE);
    if(screen == NULL)
    {
        fprintf(stderr, "Unable to set 640x480 video: %s\n", SDL_GetError());
        exit(1);
    }

    int x, y;
    for(x = 10; x < 20; x++)
    {
        for(y = 10; y < 20; y++)
            DrawPixel(screen, 255, 255, 255, x, y);
    }

    int done = 0;
    SDL_Event event;
    while((!done) && (SDL_WaitEvent(&event)))
    {
        switch(event.type)
        {
            case SDL_USEREVENT:
                break;

            case SDL_KEYDOWN:
                // Handle any key presses here.
                break;

            case SDL_MOUSEBUTTONDOWN:
                // Handle mouse clicks here.
                break;

            case SDL_QUIT:
                done = 1;
                break;

            default:
                break;
        }   // End switch        
    }   // End while

    return(0);
}

void DrawPixel(SDL_Surface *screen, Uint8 R, Uint8 G, Uint8 B, int x, int y)
{
    Uint32 color = SDL_MapRGB(screen->format, R, G, B);

    if ( SDL_MUSTLOCK(screen) ) {
        if ( SDL_LockSurface(screen) < 0 ) {
            return;
        }
    }
    switch (screen->format->BytesPerPixel) {
        case 1: { /* Assuming 8-bpp */
            Uint8 *bufp;

            bufp = (Uint8 *)screen->pixels + y*screen->pitch + x;
            *bufp = color;
        }
        break;

        case 2: { /* Probably 15-bpp or 16-bpp */
            Uint16 *bufp;

            bufp = (Uint16 *)screen->pixels + y*screen->pitch/2 + x;
            *bufp = color;
        }
        break;

        case 3: { /* Slow 24-bpp mode, usually not used */
            Uint8 *bufp;

            bufp = (Uint8 *)screen->pixels + y*screen->pitch + x;
            *(bufp+screen->format->Rshift/8) = R;
            *(bufp+screen->format->Gshift/8) = G;
            *(bufp+screen->format->Bshift/8) = B;
        }
        break;

        case 4: { /* Probably 32-bpp */
            Uint32 *bufp;

            bufp = (Uint32 *)screen->pixels + y*screen->pitch/4 + x;
            *bufp = color;
        }
        break;
    }
    if ( SDL_MUSTLOCK(screen) ) {
        SDL_UnlockSurface(screen);
    }
    SDL_UpdateRect(screen, x, y, 1, 1);
}

