#include "common.h"
#include "sdl_utils.h"
#include "girl.h"

namespace outOfSight
{
    // located in sdl_utils.cpp
    extern SDL_Surface     *spriteGirl;
    
    girl::girl(Sint16 x, Sint16 y)
    {
        rect.x = x;
        rect.y = y;
        rect.w = spriteGirl->w;
        rect.h = spriteGirl->h;
    }

    girl::~girl()
    {
    }

    void girl::blit(SDL_Surface* screen)
    {
        SDL_BlitSurface(spriteGirl, &spriteGirl->clip_rect, screen, &rect);
    }
}
