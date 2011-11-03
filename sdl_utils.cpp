#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

#include "common.h"
#include "sdl_utils.h"

namespace outOfSight
{
    SDL_Surface*    loadImage(const char* filename)
    {
        // load the image
        SDL_Surface *temp, *sprite;
        temp = IMG_Load(filename);
        if(temp == NULL)
            return(NULL);

        // convert the image to something we can use
        sprite = SDL_DisplayFormatAlpha(temp);

        // clean up
        SDL_FreeSurface(temp);
        return(sprite);
    }
}

