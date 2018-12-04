#include "Color.hpp"

using namespace std;

int Color::m_instanceCounter = 0;

Color::Color()
    : Color(0, 0, 0, "Black") {
#ifdef WITH_DEBUG
    cout << "In default constructor: Color::Color()" << endl;
#endif
}

Color::Color(int greyValue)
    : Color(greyValue, greyValue, greyValue, "Grey " + HeplString(greyValue)) {
#ifdef WITH_DEBUG
    cout << "In initialization constructor: Color::Color(int greyValue)" << endl;
#endif
}

Color::Color(int red, int green, int blue)
    : Color(red, green, blue, "Default color") {
#ifdef WITH_DEBUG
    cout << "In initialization constructor: Color::Color(int red, int green, int blue)" << endl;
#endif
}

Color::Color(int red, int green, int blue, HeplString name)
    : m_name(name) {
#ifdef WITH_DEBUG
    cout << "In initialization constructor: Color::Color(int red, int green, int blue, HeplString name)" << endl;
#endif
    m_instanceCounter++;
    setRed(red);
    setGreen(green);
    setBlue(blue);
}

Color::Color(const Color *other) 
    : Color(other->m_red, other->m_green, other->m_blue, other->m_name) {
#ifdef WITH_DEBUG
    cout << "In copy constructor: Color::Color(const Color *other)" << endl;
#endif
}

Color::Color(Color const& other) 
    : Color(other.m_red, other.m_green, other.m_blue, other.m_name) {
#ifdef WITH_DEBUG
    cout << "In copy constructor: Color::Color(Color const& other)" << endl;
#endif
}

Color::~Color() {
#ifdef WITH_DEBUG
    cout << "In destructor: Color::~Color()" << endl;
#endif
    m_instanceCounter--;
}

int Color::getRed() const {
    return m_red;
}

int Color::getGreen() const {
    return m_green;
}

int Color::getBlue() const {
    return m_blue;
}

HeplString Color::getName() const {
    return m_name;
}

int Color::getLuminance() const {
    return (m_red + m_green + m_blue) / 3;
}

Color& Color::operator=(Color const& other) {
    // Avoid infinite loops
    if (this == &other) {
        return *this;
    }
    setRed(other.m_red);
    setGreen(other.m_green);
    setBlue(other.m_blue);
    setName(other.m_name);
    return *this;
}

Color& Color::operator+=(Color const& other) {
    if (m_name.size()) {
        if (other.m_name.size()) {
            // If this is the same color (we cannot use the == operator on the
            // color since the latter is redefined on the luminance which can
            // be the same for two different colors).
            if (m_name == other.m_name) {
                m_name = "Mix of " + m_name;
            } else {
                m_name = "Mix of " + m_name + " with " + other.m_name;
            }
        } else {
            m_name = "Mix of " + m_name + " with an unknown color";
        }
    } else {
        if (other.m_name.size()) {
            m_name = "Mix of an unknown color with " + other.m_name;
        } else {
            m_name = "Unknown mix of color";
        }
    }

    // If this is the same color, we shouldn't technically add the same RGB
    // color value.
    setRed(m_red + other.m_red);
    setGreen(m_green + other.m_green);
    setBlue(m_blue + other.m_blue);
    return *this;
}

Color Color::operator+(Color const& other) {
    Color newColor(*this);
    newColor += other;
    return newColor;
}

Color operator+(Color const& lhs, Color const& rhs) {
    Color newColor(lhs);
    newColor += rhs;
    return newColor;
}

Color& Color::operator+=(const int luminance) {
    if (m_name.size()) {
        setName(m_name + " (lighter " + HeplString(luminance) + ")");
    }
    setRed(m_red + luminance);
    setGreen(m_green + luminance);
    setBlue(m_blue + luminance);
    return *this;
}

Color Color::operator+(const int luminance) {
    Color newColor(this);
    newColor += luminance;
    return newColor;
}

Color operator+(const int luminance, Color const& other) {
    Color newColor(other);
    newColor += luminance;
    return newColor;
}

Color& Color::operator-=(Color const& other) {
    // Lets keep the color name, we are just subtracting RGB values.

    // If this is the same color, we shouldn't technically add the same RGB
    // color value.
    setRed(m_red + other.m_red);
    setGreen(m_green + other.m_green);
    setBlue(m_blue + other.m_blue);
    return *this;
}

Color Color::operator-(Color const& other) {
    Color newColor(*this);
    newColor -= other;
    return newColor;
}

Color operator-(Color const& lhs, Color const& rhs) {
    Color newColor(lhs);
    newColor -= rhs;
    return newColor;
}

Color Color::operator-(const int luminance) {
    Color newColor(*this);
    if (m_name.size()) {
        newColor.setName(m_name + " (darker " + HeplString(luminance) + ")");
    }
    newColor.setRed(m_red - luminance);
    newColor.setGreen(m_green - luminance);
    newColor.setBlue(m_blue - luminance);
    return newColor;
}

Color operator-(const int luminance, Color const& other) {
    Color newColor(other);
    newColor - luminance;
    return newColor;
}

bool Color::operator==(const Color& rhs) const {
    if (getLuminance() == rhs.getLuminance()) {
        return true;
    }
    return false;
}

bool Color::operator>(const Color& rhs) const {
    if (getLuminance() > rhs.getLuminance()) {
        return true;
    }
    return false;
}

bool Color::operator<(const Color& rhs) const {
    if (*this > rhs) {
        return false;
    }
    return true;
}

bool Color::operator<=(const Color& rhs) const {
    if (*this < rhs || *this == rhs) {
        return true;
    }
    return false;
}

bool Color::operator>=(const Color& rhs) const {
    if (*this > rhs || *this == rhs) {
        return true;
    }
    return false;
}

// Prefix ++Color;
Color Color::operator++() {
    return (*this) + 10;
}

// Postfix Color++;
Color Color::operator++(int) {
    Color newColor(*this);
    *this = (*this) + 10;
    return newColor;
}

// Prefix --Color;
Color Color::operator--() {
    return (*this) - 10;
}

// Postfix Color--;
Color Color::operator--(int) {
    Color newColor(*this);
    *this = (*this) - 10;
    return newColor;
}

ostream& operator<<(ostream& lhs, const Color& rhs) {
    if (rhs.getName().size()) {
        lhs << "{ red: " << rhs.getRed()
            << ", green: " << rhs.getGreen()
            << ", blue: " << rhs.getBlue()
            << ", name: \"" << rhs.getName()
            << "\" }";
    } else {
        lhs << "{ red: " << rhs.getRed()
            << ", green: " << rhs.getGreen()
            << ", blue: " << rhs.getBlue()
            << ", name: \"Not specified\" }";
    }
    return lhs;
}

istream& operator>>(istream& lhs, Color& rhs) {
    HeplString userInput;
    HeplList<HeplString> exploded;
    int red, green, blue;
    HeplString colorName;

    do {
        cout << "Specify the color value under the following format:" << endl
             << "red green blue \"color name\": ";
        lhs >> userInput;

        exploded = userInput.explode(" ");
        if (exploded.getNumberItems() != 4 ||
            ! exploded[0].isNumber() ||
            ! exploded[1].isNumber() ||
            ! exploded[2].isNumber() ||
            // Make sure to cast to an HeplString, otherwise this will be the
            // operator[] we redefined for HeplList which will be called.
            ((HeplString)exploded[3])[0] != '"' ||
            ((HeplString)exploded[3])[exploded[3].size() - 1] != '"') {
            cout << "The syntax is incorrect. Ensure you used the following valid format:" << endl
                 << "red green blue \"color name\"." << endl;
            continue;
        }

        red = exploded[0].atoi();
        green = exploded[1].atoi();
        blue = exploded[2].atoi();
        // The BaseList operator[] returns a pointer. We need its value in
        // order to deep copy the color name (our custom string).
        colorName = exploded[3].substr(1, exploded[3].size() - 2);

        try {
            rhs.setRed(red);
            rhs.setGreen(green);
            rhs.setBlue(blue);
            rhs.setName(colorName);

        } catch (InvalidColorException &e) {
            cout << "An InvalidColorException has been caught: " + e.what() << endl;
            continue;
        }

        break;

    } while (true);

    return lhs;
}

void Color::setRed(int value) {
    if (value < 0 || value > 255) {
        throw new InvalidColorException(HeplString("Red is out of range: ") + HeplString(m_red), this);
    }
    m_red = value;
}

void Color::setGreen(int value) {
    if (value < 0 || value > 255) {
        throw new InvalidColorException(HeplString("Green is out of range: ") + HeplString(m_green), this);
    }
    m_green = value;
}

void Color::setBlue(int value) {
    if (value < 0 || value > 255) {
        throw new InvalidColorException(HeplString("Blue is out of range: ") + HeplString(m_blue), this);
    }
    m_blue = value;
}

void Color::setGrey(int value) {
    setRed(value);
    setGreen(value);
    setBlue(value);
}

void Color::setName(HeplString name) {
    m_name = name;
}

int Color::getInstanceCounter() {
    return m_instanceCounter;
}

void Color::display() const {
    cout << "Color name: " << m_name << endl;
    cout << "red       : " << m_red << endl;
    cout << "green     : " << m_green << endl;
    cout << "blue      : " << m_blue << endl;
}

void Color::save(ofstream& out) const {
    out.write((char*)&m_red, sizeof(m_red));
    out.write((char*)&m_green, sizeof(m_green));
    out.write((char*)&m_blue, sizeof(m_blue));
    m_name.save(out);
}

void Color::load(ifstream& in) {
    in.read((char*)&m_red, sizeof(m_red));
    in.read((char*)&m_green, sizeof(m_green));
    in.read((char*)&m_blue, sizeof(m_blue));
    m_name.load(in);
}

const Color Color::RED = Color(255, 0, 0, "Red");
const Color Color::GREEN = Color(0, 255, 0, "Green");
const Color Color::BLUE = Color(0, 0, 255, "Blue");
const Color Color::GREY = Color(128, 128, 128, "Grey");
const Color Color::SILVER = Color(192, 192, 192, "Silver");
