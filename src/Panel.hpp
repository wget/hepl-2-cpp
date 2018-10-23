#ifndef PANEL_HPP_INCLUDED
#define PANEL_HPP_INCLUDED

#include "HeplString.hpp"

class Panel {

    private:
        HeplString m_name;
        unsigned int m_x;
        unsigned int m_y;
        unsigned int m_width;
        unsigned int m_height;

    public:
        // Constructors
        Panel();
        Panel(unsigned int x, unsigned int y);
        Panel(const char *name, unsigned int x, unsigned int y);
        Panel(unsigned int x, unsigned int y, unsigned int width, unsigned int height);
        Panel(const char *name, unsigned int x, unsigned int y, unsigned int width, unsigned int height);
        ~Panel();

        // Getters
        unsigned int getX() const;
        unsigned int getY() const;
        unsigned int getWidth() const;
        unsigned int getHeight() const;
        char* getName() const;

        // Setters
        void setX(unsigned int x);
        void setY(unsigned int y);
        void setWidth(unsigned int width);
        void setHeight(unsigned int height);
        void setName(const char *name);
        void setName(HeplString name);

        // Other methods
        void display() const;
};

#endif // PANEL_HPP_INCLUDED
