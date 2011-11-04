#include <SDL/SDL.h>

#ifndef __OOS_ASSETS__
#define __OOS_ASSETS__

/**
    Random utility functions having to do with SDL.
 **/
namespace outOfSight
{   
    /**
        Load images that are well used
        
        @return     1 on success, 0 on error
     **/
    int             loadImages();
    
    /**
        Free all images
     **/
    void            freeImages();
}

#endif

