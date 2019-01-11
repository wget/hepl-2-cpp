#include "Window.hpp"


/* Constructors */
Window::Window(): m_width(0), m_height(0) {
}

Window::Window(int width, int height, Color backgroundColor):
    m_width(width), m_height(height), m_backgroundColor(backgroundColor) {
}

Window::Window(Window const& other)
    : m_width(other.m_width), m_height(other.m_height), m_backgroundColor(other.m_backgroundColor) {
}

/* Getters */
int Window::getWidth() const {;
    return m_width;
}

int Window::getHeight() const {
    return m_height;
}

Color Window::getColor() const {
    return m_backgroundColor;
}

/* Setters */
void Window::setWidth(int width) {
    m_width = width;
}

void Window::setHeight(int height) {
    m_height = height;
}

void Window::setColor(Color const& color) {
    m_backgroundColor = color;
}

/* Other methods */
void Window::setVisible(bool visibility) {

    if (visibility) {
        WindowSDL::open(m_width, m_height);
        return;
    }
    WindowSDL::close();
}

void Window::draw() {
    WindowSDL::setBackground(
        m_backgroundColor.getRed(),
        m_backgroundColor.getGreen(),
        m_backgroundColor.getBlue());
}
