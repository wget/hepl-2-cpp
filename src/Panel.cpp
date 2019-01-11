#include "Panel.hpp"

using namespace std;

/*
 * Constructors / destructors
 */
// We are using constructor chaining, a C++11 feature.
// src.: https://stackoverflow.com/a/308318/3514658
Panel::Panel()
    : m_name("Unknown panel"), m_x(0), m_y(0), m_width(0), m_height(0), m_color(Color::SILVER) {
#ifdef WITH_DEBUG
    cout << "In default constructor: Panel::Panel()" << endl;
#endif
}

Panel::Panel(const HeplString name, unsigned int x, unsigned int y,
             unsigned int width, unsigned int height, Color color)
    : m_x(x), m_y(y), m_width(width), m_height(height), m_color(color) {
#ifdef WITH_DEBUG
    cout << "In initialization constructor: Panel::Panel(const HeplString name, unsigned int x, unsigned int y, unsigned int width, unsigned int height, Color& color)" << endl;
#endif
    // We shouldn't call a virtual method from a constructor, this is considered bad practise.
    // Also, calling this method would mean the verification would be done for
    // subclasses as well like Button, where as the verification is not the
    // same for these subclasses.
    // src.: https://stackoverflow.com/a/962148/3514658
    // The solution we had was to avoid calling this constructor from subclass.
    setName(name);
}

Panel::Panel(const Panel& rhs)
    : Panel(rhs.getName(), rhs.getX(), rhs.getY(), rhs.getWidth(), rhs.getHeight(), rhs.getColor()) {
#ifdef WITH_DEBUG
    cout << "In copy constructor: Panel::Panel(const Panel& rhs)" << endl;
#endif
}

Panel::~Panel() {
#ifdef WITH_DEBUG
    cout << "In destructor: Panel::~Panel()" << endl;
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

HeplString Panel::getName() const {
    return m_name;
}

Color Panel::getColor() const {
    return m_color;
}

HeplString Panel::getType() const {
    return Panel::CLASS_NAME;
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
    setName(HeplString(name));
}

void Panel::setName(HeplString name) {
    if (name[0] != 'P' || name.size() < 2 || ! name.substr(1, name.size() - 1).isNumber()) {
        throw BaseException("Panel name invalid");
    }
    m_name = name;
}

void Panel::setColor(const Color &color) {
    m_color = color;
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
    m_color.display();
}

void Panel::draw() const {
    WindowSDL::fillRectangle(
        m_color.getRed(),
        m_color.getGreen(),
        m_color.getBlue(),
        m_x,
        m_y,
        m_width,
        m_height);
}

/*
 * Stream management
 */
ostream& operator<<(ostream& lhs, const Panel& rhs) {
    lhs << "{ name: \"" << rhs.getName()
        << "\", x: " << rhs.getX()
        << ", y: " << rhs.getY()
        << ", width: " << rhs.getWidth()
        << ", height: " << rhs.getHeight()
        << ", red: " << rhs.getColor().getRed()
        << ", green: " << rhs.getColor().getGreen()
        << ", blue: " << rhs.getColor().getBlue()
        << ", colorName: \"" << rhs.getColor().getName()
        << "\" }";
    return lhs;
}

istream& operator>>(istream& lhs, Panel& rhs) {
    HeplString userInput;
    HeplList<HeplString> exploded;
    int x, y, width, height, red, green, blue;
    HeplString panelName, colorName;
    Color color;

    do {
        cout << "Specify the panel value under the following format:" << endl
             << "\"panel name\" x y width height red green blue \"color name\": ";
        lhs >> userInput;

        exploded = userInput.explode(" ");
        if (exploded.getNumberItems() != 9 ||
            ((HeplString)exploded[0])[0] != '"' ||
            ((HeplString)exploded[0])[exploded[0].size() - 1] != '"' ||
            ! exploded[1].isNumber() ||
            ! exploded[2].isNumber() ||
            ! exploded[3].isNumber() ||
            ! exploded[4].isNumber() ||
            ! exploded[5].isNumber() ||
            ! exploded[6].isNumber() ||
            ! exploded[7].isNumber() ||
            ((HeplString)exploded[8])[0] != '"' ||
            ((HeplString)exploded[8])[exploded[8].size() - 1] != '"') {
            cout << "The syntax is incorrect. Ensure you used the following valid format:" << endl
                 << "\"panel name\" x y width height red green blue \"color name\"." << endl;
            continue;
        }

        panelName = exploded[0].substr(1, exploded[0].size() - 2);
        x = exploded[1].atoi();
        y = exploded[2].atoi();
        width = exploded[3].atoi();
        height = exploded[4].atoi();
        red = exploded[5].atoi();
        green = exploded[6].atoi();
        blue = exploded[7].atoi();
        colorName = exploded[8].substr(1, exploded[8].size() - 2);

        try {
            rhs.setName(panelName);
            rhs.setX((unsigned int)x);
            rhs.setY((unsigned int)y);
            rhs.setWidth((unsigned int)width);
            rhs.setHeight((unsigned int)height);
            color.setRed(red);
            color.setGreen(green);
            color.setBlue(blue);
            color.setName(colorName);
            rhs.setColor(color);

        } catch (InvalidColorException &e) {
            cout << "An InvalidColorException has been caught: " + e.what() << endl;
            continue;
        }

        break;

    } while (true);

    return lhs;
}

void Panel::save(ofstream& out) const {
    m_name.save(out);
    out.write((char*)&m_x, sizeof(m_x));
    out.write((char*)&m_y, sizeof(m_y));
    out.write((char*)&m_width, sizeof(m_width));
    out.write((char*)&m_height, sizeof(m_height));
    m_color.save(out);
}

void Panel::load(ifstream& in) {
    m_name.load(in);
    in.read((char*)&m_x, sizeof(m_x));
    in.read((char*)&m_y, sizeof(m_y));
    in.read((char*)&m_width, sizeof(m_width));
    in.read((char*)&m_height, sizeof(m_height));
    m_color.load(in);
}

const HeplString Panel::CLASS_NAME = "PANEL";
