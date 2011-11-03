#include <SDL/SDL.h>

/**
    Random utility functions having to do with SDL.
 **/
namespace outOfSight
{
    /**
        Load images with SDL_image.  Works with BMP, PNG, and JPEF

        @param filename The file to load
        @return Surface representing the image
     **/
    SDL_Surface*    loadImage(const char* filename);
}
