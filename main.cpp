#include <SDL/SDL.h>

#include "common.h"
#include "assets.h"
#include "sdl_utils.h"
#include "girl.h"

Uint32 drawCallback(Uint32 interval, void *param)
{
    SDL_Event event;
    SDL_UserEvent userevent;

    /* In this example, our callback pushes an SDL_USEREVENT event
    into the queue, and causes ourself to be called again at the
    same interval: */

    userevent.type = SDL_USEREVENT;
    userevent.code = 0;
    userevent.data1 = NULL;
    userevent.data2 = NULL;

    event.type = SDL_USEREVENT;
    event.user = userevent;

    SDL_PushEvent(&event);
    return(interval);
}

int main(int argc, char *argv[])
{
    // initialize everything
    if(SDL_Init(SDL_INIT_AUDIO|SDL_INIT_VIDEO|SDL_INIT_TIMER) < 0)
        DIE("Unable to init SDL: %s\n", SDL_GetError());
    // set exit function
    atexit(SDL_Quit);

    // get window
    SDL_Surface *screen = SDL_SetVideoMode(640, 480, 16, SDL_HWSURFACE | SDL_DOUBLEBUF);
    SDL_WM_SetCaption(WINDOW_TITLE, 0);
    if(screen == NULL)
        DIE("Unable to set 640x480 video: %s\n", SDL_GetError());

    // get sprite
    if(!outOfSight::loadImages())
        DIE("Unable to load sprites: %s\n", SDL_GetError());

    Uint32 delay = (Uint32)(1000.0 / GAME_FPS) / 10 * 10;
    SDL_TimerID timerID = SDL_AddTimer(delay, drawCallback, NULL);
    if(timerID == NULL)
        DIE("Unable to make timer: %s\n", SDL_GetError());

    outOfSight::girl girl(10, 10);
    
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
                    SDL_FillRect(screen, &screen->clip_rect, SDL_MapRGB(screen->format, 255, 255, 255));
                    girl.blit(screen);
                    SDL_Flip(screen);
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
    }   // End while

    outOfSight::freeImages();
    return(0);
}

