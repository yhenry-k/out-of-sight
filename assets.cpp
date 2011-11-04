#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

#include "common.h"
#include "sdl_utils.h"

namespace outOfSight
{
    SDL_Surface     *spriteGirl;
    
    int             loadImages()
    {
        if((spriteGirl = loadImage("assets/girl.png")) == NULL)
            return(0);
        return(1);
    }
    
    void            freeImages()
    {
        SDL_FreeSurface(spriteGirl);
    }
}


