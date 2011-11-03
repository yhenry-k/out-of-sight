#include <SDL/SDL.h>

#include "common.h"
#include "sdl_utils.h"

int main(int argc, char *argv[])
{
    // initialize everything
    if(SDL_Init(SDL_INIT_AUDIO|SDL_INIT_VIDEO) < 0)
        DIE("Unable to init SDL: %s\n", SDL_GetError());
    // set exit function
    atexit(SDL_Quit);

    // get window
    SDL_Surface *screen = SDL_SetVideoMode(640, 480, 16, SDL_HWSURFACE | SDL_DOUBLEBUF);
    SDL_WM_SetCaption(WINDOW_TITLE, 0);
    if(screen == NULL)
        DIE("Unable to set 640x480 video: %s\n", SDL_GetError());

    // get sprite
    SDL_Surface *sprite = outOfSight::loadImage("assets/girl-stick-figure.jpg");

    SDL_Rect src;
    src.x = 0;
    src.y = 0;
    src.w = sprite->w;
    src.h = sprite->h;

    SDL_Rect dest;
    dest.x = 20;
    dest.y = 20;
    dest.w = sprite->w;
    dest.h = sprite->h;

    // main game loop
    int done = 0;
    SDL_Event event;
    while(!done)
    {
        while(SDL_PollEvent(&event))
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
        }

        SDL_BlitSurface(sprite, &src, screen, &dest);
        SDL_Flip(screen);
    }   // End while

    SDL_FreeSurface(sprite);
    return(0);
}

