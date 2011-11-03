#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

#define WINDOW_TITLE    "Out of Sight 0.0.0.0.0.0.0.0.0.0.1"
#define DIE(...)        { fprintf(stderr, __VA_ARGS__); exit(1); }

int main(int argc, char *argv[])
{
    if(SDL_Init(SDL_INIT_AUDIO|SDL_INIT_VIDEO) < 0)
        DIE("Unable to init SDL: %s\n", SDL_GetError());
    atexit(SDL_Quit);

    SDL_Surface *screen = SDL_SetVideoMode(640, 480, 16, SDL_HWSURFACE | SDL_DOUBLEBUF);
    SDL_WM_SetCaption(WINDOW_TITLE, 0);
    if(screen == NULL)
        DIE("Unable to set 640x480 video: %s\n", SDL_GetError());

    SDL_Surface *temp, *sprite;
    temp = IMG_Load("assets/girl-stick-figure.jpg");
    if(temp == NULL)
        DIE("Unable to load sprite\n");
    sprite = SDL_DisplayFormatAlpha(temp);
    SDL_FreeSurface(temp);

    SDL_Rect src;
    src.x = 0;
    src.y = 0;
    src.w = 300;
    src.h = 400;

    SDL_Rect dest;
    dest.x = 20;
    dest.y = 20;
    dest.w = 300;
    dest.h = 400;

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

        SDL_BlitSurface(sprite, &src, screen, &dest);
        SDL_Flip(screen);
    }   // End while

    SDL_FreeSurface(sprite);
    return(0);
}

