#ifndef WINDOW_SDL_IMAGE_H
#define WINDOW_SDL_IMAGE_H

#include <SDL/SDL.h>
#include "WindowSDLexception.hpp"

class WindowSDL;

class WindowSDLimage
{
  private :
    SDL_Surface   *surface;

    SDL_Surface*  chargeSurface(const char *nomfichier);
    SDL_Surface*  copieSurface(SDL_Surface *surf);
    
  public:
    WindowSDLimage(void);
    WindowSDLimage(const char* nomFichier);
    WindowSDLimage(const WindowSDLimage &c);
    ~WindowSDLimage();

    void load(const char* nomFichier);

    int  getWidth() const;    // Largeur en pixels de l'image
    int  getHeight() const;   // Hauteur en pixels de l'image

    WindowSDLimage& operator=(const WindowSDLimage& i);

    friend class WindowSDL;
};

#endif
