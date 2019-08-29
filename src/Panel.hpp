#ifndef PANEL_HPP_INCLUDED
#define PANEL_HPP_INCLUDED

#include "HeplString.hpp"
#include "Color.hpp"
#include "BaseException.hpp"
#include "WindowSDL/WindowSDL.hpp"

class Panel {

    protected:
        HeplString m_name;
        unsigned int m_x;
        unsigned int m_y;
        unsigned int m_width;
        unsigned int m_height;
        Color m_color;

    public:
        // Constructors
        Panel();
        Panel(const HeplString name, unsigned int x, unsigned int y,
              unsigned int width, unsigned int height, Color color = Color::SILVER);

        Panel(const Panel &rhs);
        virtual ~Panel();

        // Getters
        unsigned int getX() const;
        unsigned int getY() const;
        unsigned int getWidth() const;
        unsigned int getHeight() const;
        HeplString getName() const;
        Color getColor() const;
        virtual HeplString getType() const;

        // Setters
        void setX(unsigned int x);
        void setY(unsigned int y);
        void setWidth(unsigned int width);
        void setHeight(unsigned int height);
        void setName(const char *name);
        virtual void setName(HeplString name);
        void setColor(const Color &color);

        // Other methods
        void display() const;
        void draw() const;

        // Operators
        Panel& operator=(const Panel&) = default;

        // Stream management
        friend std::ostream& operator<<(std::ostream& lhs, const Panel& rhs);
        friend std::istream& operator>>(std::istream& lhs, Panel& rhs);
        void save(std::ofstream& out) const;
        void load(std::ifstream& in);

        // Static attributes
        static const HeplString CLASS_NAME;
};

// Avoid to redeclare a whole class when we just want to have our own Exception
// without having to throw a generic exception.
// src.: https://stackoverflow.com/a/51313801/3514658
class PanelException: BaseException {
    using BaseException::BaseException;
};

#endif // PANEL_HPP_INCLUDED
