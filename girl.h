#include <SDL/SDL_image.h>

#ifndef __OOS_GIRL__
#define __OOS_GIRL__

namespace outOfSight
{
    /**
        Class of the main character
     **/
    class girl
    {
    public:
        /**
            Main constructor.  Takes in the position
            
            @param x    Initial x-position
            @param y    Initial y-position
         **/
        girl(Sint16 x, Sint16 y);
        
        /**
            Destructor
         **/
        ~girl();
        
        /**
            Draw sprite on screen.
            
            @param screen   Surface on which draw sprite
         **/
        void blit(SDL_Surface *screen);
        
     private:
        /**
            Holds position and size (for drawing)
         **/
        SDL_Rect    rect;
    };
}

#endif
