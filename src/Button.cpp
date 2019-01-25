#include "Button.hpp"

using namespace std;

/*
 * Constructors / destructors
 */
// We are using constructor chaining, a C++11 feature.
// src.: https://stackoverflow.com/a/308318/3514658
Button::Button()
    : Button("B00", 0, 0, 0, 0) {
#ifdef WITH_DEBUG
    cout << "In default constructor: Button::Button()" << endl;
#endif
}

Button::Button(
    const HeplString name, unsigned int x, unsigned int y,
    unsigned int width, unsigned int height, const Color& color) {
#ifdef WITH_DEBUG
    cout << "In initialization constructor: Button::Button(const HeplString name, unsigned int x, unsigned int y, unsigned int width, unsigned int height, HeplString filename)" << endl;
#endif
    setName(name);
    setX(x);
    setY(y);
    setWidth(width);
    setHeight(height);
    setColor(color);
}

Button::Button(const Button& rhs)
    : Button(rhs.getName(), rhs.getX(), rhs.getY(), rhs.getWidth(), rhs.getHeight()) {
#ifdef WITH_DEBUG
    cout << "In copy constructor: Button::Button(const Panel& rhs)" << endl;
#endif
}

Button::~Button() {
#ifdef WITH_DEBUG
    cout << "In destructor: Button::~Button()" << endl;
#endif
}

/*
 * Setters
 */
void Button::setName(HeplString name) {
    // if (name[0] != 'B' || name.size() < 2 || ! name.substr(1, name.size() - 1).isNumber()) {
    //     throw BaseException("Button name invalid");
    // }
    m_name = name;
}

/*
 * Other methods
 */
void Button::display() const {
    cout << "Name  : " << "Button " << m_name << endl;
    cout << "X     : " << m_x << endl;
    cout << "Y     : " << m_y << endl;
    cout << "Width : " << m_width << endl;
    cout << "Height: " << m_height << endl;
    m_color.display();
}

void Button::click(int x, int y) const {
    if (x <= (int)m_x && x <= (int)m_x + (int)m_width &&
        y <= (int)m_y && y <= (int)m_y + (int)m_height) {
        cout << "Click missed" << endl;
    } else {
        cout << "Click OK" << endl;
    }
}

HeplString Button::getType() const {
    return Button::CLASS_NAME;
}

/*
 * Stream management
 */
ostream& operator<<(ostream& lhs, const Button& rhs) {
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

istream& operator>>(istream& lhs, Button& rhs) {
    HeplString userInput;
    HeplList<HeplString> exploded;
    int x, y, width, height;
    HeplString panelName;

    do {
        cout << "Specify the button value under the following format:" << endl
             << "\"button name\" x y width height: ";
        lhs >> userInput;

        exploded = userInput.explode(" ");
        if (exploded.getNumberItems() != 5 ||
            ((HeplString)exploded[0])[0] != '"' ||
            ((HeplString)exploded[0])[exploded[0].size() - 1] != '"' ||
            ! exploded[1].isNumber() ||
            ! exploded[2].isNumber() ||
            ! exploded[3].isNumber() ||
            ! exploded[4].isNumber()) {
            cout << "The syntax is incorrect. Ensure you used the following valid format:" << endl
                 << "\"button name\" x y width height." << endl;
            continue;
        }

        panelName = exploded[0].substr(1, exploded[0].size() - 2);
        x = exploded[1].atoi();
        y = exploded[2].atoi();
        width = exploded[3].atoi();
        height = exploded[4].atoi();

        try {
            rhs.setName(panelName);
            rhs.setX((unsigned int)x);
            rhs.setY((unsigned int)y);
            rhs.setWidth((unsigned int)width);
            rhs.setHeight((unsigned int)height);
            rhs.setColor(Color::BLUE);

        } catch (InvalidColorException &e) {
            cout << "An InvalidColorException has been caught: " + e.what() << endl;
            continue;
        }

        break;

    } while (true);

    return lhs;
}

const HeplString Button::CLASS_NAME = "BUTTON";
