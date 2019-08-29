#ifndef WINDOW_SDL_H
#define WINDOW_SDL_H

#include <SDL/SDL.h>
#include <pthread.h>
#include "WindowSDLexception.hpp"
#include "WindowSDLimage.hpp"
#include "WindowSDLclick.hpp"

class WindowSDL
{
  private:
    static SDL_Surface      *screen;
    static int              width;
    static int              height;
    static pthread_t        threadEventSDL;
    static char             alive;
    static void*            FctThreadEventSDL(void *);

    // Gestion du Click
    static WindowSDLclick   click;
    static char             clicked;
    static pthread_mutex_t  mutexClick;
    static pthread_cond_t   condClick;

  public:
    static void open(int w,int h);
    static char isAlive();
    static void close();
    static void setBackground(int R,int G,int B);
    static void setPixel(int R,int G,int B,int x,int y);
    static void drawLine(int R,int G,int B,int x1,int y1, int x2,int y2);
    static void drawRectangle(int R,int G,int B,int x,int y,int w,int h);
    static void fillRectangle(int R,int G,int B,int x,int y,int w,int h);
    static void drawImage(const WindowSDLimage& image,int x,int y);
    static WindowSDLclick waitClick();
};

#endif


