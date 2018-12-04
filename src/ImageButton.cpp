#include "ImageButton.hpp"

using namespace std;

/*
 * Constructors / destructors
 */
// We are using constructor chaining, a C++11 feature.
// src.: https://stackoverflow.com/a/308318/3514658
ImageButton::ImageButton()
    : ImageButton("B00", 0, 0, 0, 0, "No file") {
#ifdef WITH_DEBUG
    cout << "In default constructor: ImageButton::ImageButton()" << endl;
#endif
}

ImageButton::ImageButton(
    const HeplString name, unsigned int width, unsigned int height, HeplString filename) 
    : ImageButton(name, 0, 0, width, height, filename) {
#ifdef WITH_DEBUG
    cout << "In initialization constructor: ImageButton::ImageButton(const HeplString name, unsigned int x, unsigned int y, unsigned int width, unsigned int height, HeplString filename)" << endl;
#endif
}

ImageButton::ImageButton(
    const HeplString name, unsigned int x, unsigned int y,
    unsigned int width, unsigned int height, HeplString filename) {
#ifdef WITH_DEBUG
    cout << "In initialization constructor: ImageButton::ImageButton(const HeplString name, unsigned int x, unsigned int y, unsigned int width, unsigned int height, HeplString filename)" << endl;
#endif
    setName(name);
    setX(x);
    setY(y);
    setWidth(width);
    setHeight(height);
    setColor(Color::SILVER);
    setFilename(filename);
}

ImageButton::ImageButton(const ImageButton& rhs)
    : ImageButton(rhs.ImagePanel::getName(), rhs.ImagePanel::getX(), rhs.ImagePanel::getY(), rhs.ImagePanel::getWidth(), rhs.ImagePanel::getHeight(), rhs.ImagePanel::getFilename()) {
#ifdef WITH_DEBUG
    cout << "In copy constructor: ImageButton::ImageButton(const Panel& rhs)" << endl;
#endif
}

ImageButton::~ImageButton() {
#ifdef WITH_DEBUG
    cout << "In destructor: ImagePanel::~ImagePanel()" << endl;
#endif
}

/*
 * Setters
 */
void ImageButton::setName(HeplString name) {
    cout << "set name imagebutton called" << endl;
    if (name[0] != 'B' || name.size() < 2 || ! name.substr(1, name.size() - 1).isNumber()) {
        throw BaseException("ImageButton name invalid");
    }
    m_name = name;
}

/*
 * Other methods
 */
void ImageButton::display() const {
    cout << "Image Button Name : " << ImagePanel::m_name << endl;
    cout << "Position(" << ImagePanel::m_x << ", " << ImagePanel::m_y << ")" << endl;
    cout << "Filename=\"" << ImagePanel::m_filename << "\"" << endl;
}

HeplString ImageButton::getType() const {
    return ImageButton::CLASS_NAME;
}

/*
 * Stream management
 */
ostream& operator<<(ostream& lhs, const ImageButton& rhs) {
    lhs << "{ name: \"" << rhs.ImagePanel::getName()
        << "\", x: " << rhs.ImagePanel::getX()
        << ", y: " << rhs.ImagePanel::getY()
        << ", filename: \"" << rhs.ImagePanel::getFilename()
        << "\" }";
    return lhs;
}

istream& operator>>(istream& lhs, ImageButton& rhs) {
    HeplString userInput;
    HeplList<HeplString> exploded;
    int x, y, width, height;
    HeplString panelName, filename;

    do {
        cout << "Specify the imagebutton value under the following format:" << endl
             << "\"panel name\" x y width height \"filename\": ";
        lhs >> userInput;

        exploded = userInput.explode(" ");
        if (exploded.getNumberItems() != 6 ||
            ((HeplString)exploded[0])[0] != '"' ||
            ((HeplString)exploded[0])[exploded[0].size() - 1] != '"' ||
            ! exploded[1].isNumber() ||
            ! exploded[2].isNumber() ||
            ! exploded[3].isNumber() ||
            ! exploded[4].isNumber() ||
            ((HeplString)exploded[5])[0] != '"' ||
            ((HeplString)exploded[5])[exploded[5].size() - 1] != '"') {
            cout << "The syntax is incorrect. Ensure you used the following valid format:" << endl
                 << "\"panel name\" x y width height \"filename\"." << endl;
            continue;
        }

        panelName = exploded[0].substr(1, exploded[0].size() - 2);
        x = exploded[1].atoi();
        y = exploded[2].atoi();
        width = exploded[3].atoi();
        height = exploded[4].atoi();
        filename = exploded[5].substr(1, exploded[5].size() - 2);

        try {
            rhs.ImagePanel::setName(panelName);
            rhs.ImagePanel::setX((unsigned int)x);
            rhs.ImagePanel::setY((unsigned int)y);
            rhs.ImagePanel::setWidth((unsigned int)width);
            rhs.ImagePanel::setHeight((unsigned int)height);
            rhs.ImagePanel::setColor(Color::BLUE);
            rhs.ImagePanel::setFilename(filename);

        } catch (InvalidColorException &e) {
            cout << "An InvalidColorException has been caught: " + e.what() << endl;
            continue;
        }

        break;

    } while (true);

    return lhs;
}

const HeplString ImageButton::CLASS_NAME = "IMAGE_BUTTON";
