#include "Panel.hpp"

using namespace std;

/*
 * Constructors / destructors
 */
Panel::Panel()
    : m_name("Unknown panel"), m_x(0), m_y(0) {
#ifdef WITH_DEBUG
    cout << "In constructor Panel::Panel()" << endl;
#endif
}

Panel::Panel(unsigned int x, unsigned int y)
    : m_name("Unknown panel"), m_x(x), m_y(y) {
#ifdef WITH_DEBUG
    cout << "In constructor Panel::Panel(unsigned int x, unsigned int y)" << endl;
#endif
}

Panel::Panel(const char *name, unsigned int x, unsigned int y)
    : m_name(name), m_x(x), m_y(y)  {
#ifdef WITH_DEBUG
    cout << "In constructor Panel::Panel(unsigned int x, unsigned int y, char *name)" << endl;
#endif
}

Panel::Panel(unsigned int x, unsigned int y, unsigned int width, unsigned int height)
    : m_name("Unknown panel"), m_x(x), m_y(y), m_width(width), m_height(height) {
#ifdef WITH_DEBUG
    cout << "In constructor Panel::Panel(unsigned int x, unsigned int y, unsigned int width, unsigned int height)" << endl;
#endif
}

Panel::Panel(const char *name, unsigned int x, unsigned int y, unsigned int width, unsigned int height)
    : m_name(name), m_x(x), m_y(y), m_width(width), m_height(height) {
#ifdef WITH_DEBUG
    cout << "In constructor Panel::Panel(unsigned int x, unsigned int y, unsigned int width, unsigned int height, char *name)" << endl;
#endif
    m_name = name;
}

Panel::~Panel() {
#ifdef WITH_DEBUG
    cout << "In destructor Panel::~Panel()" << endl;
#endif
}

/**
 * Getters
 */
unsigned int Panel::getX() const {
    return m_x;
}

unsigned int Panel::getY() const {
    return m_y;
}

unsigned int Panel::getWidth() const {
    return m_width;
}

unsigned int Panel::getHeight() const {
    return m_height;
}

char* Panel::getName() const {
    return m_name.c_str();
}

/*
 * Setters
 */
void Panel::setX(unsigned int x) {
    m_x = x;
}

void Panel::setY(unsigned int y) {
    m_y = y;
}

void Panel::setWidth(unsigned int width) {
    m_width = width;
}

void Panel::setHeight(unsigned int height) {
    m_height = height;
}

void Panel::setName(const char *name) {
    m_name = HeplString(name);
}

void Panel::setName(HeplString name) {
    m_name = name;
}

/*
 * Other methods
 */
void Panel::display() const {
    cout << "Name  : " << m_name << endl;
    cout << "X     : " << m_x << endl;
    cout << "Y     : " << m_y << endl;
    cout << "Width : " << m_width << endl;
    cout << "Height: " << m_height << endl;
}
