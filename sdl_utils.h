#include <SDL/SDL.h>

//  namespace to prevent overriding similar function
namespace outOfSight
{
    /**
        Load images with SDL_image.  Works with BMP, PNG, and JPEF

        @param filename The file to load
        @return Surface representing the image
     **/
    SDL_Surface*    loadImage(const char* filename);
}
