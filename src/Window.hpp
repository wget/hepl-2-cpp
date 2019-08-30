#ifndef WINDOW_HPP_DEFINED
#define WINDOW_HPP_DEFINED

#include "./WindowSDL/WindowSDL.hpp"
#include "Color.hpp"

class Window {

    protected:
        int m_width;
        int m_height;
        Color m_backgroundColor;

    public:
        /* Constructors */
        Window();
        Window(int width, int height, Color backgroundColor);
        Window(Window const& other);

        /* Getters */
        int getWidth() const;
        int getHeight() const;
        Color getColor() const;

        /* Setters */
        void setWidth(int width);
        void setHeight(int height);
        void setColor(Color const& color);

        /* Other methods */
        void setVisible(bool visibility);
        virtual void draw();

};

#endif // WINDOW_HPP_DEFINED
