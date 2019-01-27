#include "ImagePanel.hpp"

using namespace std;

/*
 * Constructors / destructors
 */
// We are using constructor chaining, a C++11 feature.
// src.: https://stackoverflow.com/a/308318/3514658
ImagePanel::ImagePanel()
    : ImagePanel("P00", 0, 0, "No file") {
#ifdef WITH_DEBUG
    cout << "In default constructor: ImagePanel::ImagePanel()" << endl;
#endif
}

ImagePanel::ImagePanel(
    const HeplString name, unsigned int x, unsigned int y, HeplString filename) 
    : ImagePanel(name, x, y, 0, 0, filename) {
#ifdef WITH_DEBUG
    cout << "In initialization constructor: ImagePanel::ImagePanel(const HeplString name, unsigned int x, unsigned int y, unsigned int width, unsigned int height, HeplString filename)" << endl;
#endif
}

ImagePanel::ImagePanel(
    const HeplString name, unsigned int x, unsigned int y,
    unsigned int width, unsigned int height, HeplString filename) {
#ifdef WITH_DEBUG
    cout << "In initialization constructor: ImagePanel::ImagePanel(const HeplString name, unsigned int x, unsigned int y, unsigned int width, unsigned int height, HeplString filename)" << endl;
#endif
    setName(name);
    setX(x);
    setY(y);
    setWidth(width);
    setHeight(height);
    setColor(Color::SILVER);
    setFilename(filename);
    // m_image = nullptr;
}

ImagePanel::ImagePanel(const ImagePanel& rhs)
    : ImagePanel(rhs.getName(), rhs.getX(), rhs.getY(), rhs.getWidth(), rhs.getHeight(), rhs.getFilename()) {
#ifdef WITH_DEBUG
    cout << "In copy constructor: ImagePanel::ImagePanel(const Panel& rhs)" << endl;
#endif
}

ImagePanel::~ImagePanel() {
#ifdef WITH_DEBUG
    cout << "In destructor: ImagePanel::~ImagePanel()" << endl;
#endif
}

/**
 * Getters
 */
HeplString ImagePanel::getFilename() const {
    return m_filename;
}

/*
 * Setters
 */
void ImagePanel::setFilename(HeplString filename) {
    m_filename = filename;
    try {
        m_image = new WindowSDLimage(filename.c_str());
        m_width = m_image->getWidth();
        m_height = m_image->getHeight();

    } catch (WindowSDLexception e) {
        m_image = nullptr;
    }
}

/*
 * Other methods
 */
void ImagePanel::display() const {
    cout << "Image Panel Name : " << m_name << endl;
    cout << "Position(" << m_x << ", " << m_y << ")" << endl;
    cout << "Filename=\"" << m_filename << "\"" << endl;
}

HeplString ImagePanel::getType() const {
    return ImagePanel::CLASS_NAME;
}

void ImagePanel::draw() const {

    if (m_image == nullptr) {

        WindowSDL::drawRectangle(
            // Color black
            0, 0, 0,
            // Position
            m_x, m_y,
            // Size
            m_width, m_height
        );
        return;
    }
    WindowSDL::drawImage(*(m_image), (int)m_x, (int)m_y);
}


/*
 * Stream management
 */
ostream& operator<<(ostream& lhs, const ImagePanel& rhs) {
    lhs << "{ name: \"" << rhs.getName()
        << "\", x: " << rhs.getX()
        << ", y: " << rhs.getY()
        << ", filename: \"" << rhs.getFilename()
        << "\" }";
    return lhs;
}

istream& operator>>(istream& lhs, ImagePanel& rhs) {
    HeplString userInput;
    HeplList<HeplString> exploded;
    int x, y, width, height;
    HeplString panelName, filename;

    do {
        cout << "Specify the imagepanel value under the following format:" << endl
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
            rhs.setName(panelName);
            rhs.setX((unsigned int)x);
            rhs.setY((unsigned int)y);
            rhs.setWidth((unsigned int)width);
            rhs.setHeight((unsigned int)height);
            rhs.setColor(Color::BLUE);
            rhs.setFilename(filename);

        } catch (InvalidColorException &e) {
            cout << "An InvalidColorException has been caught: " + e.what() << endl;
            continue;
        }

        break;

    } while (true);

    return lhs;
}

void ImagePanel::save(ofstream& out) const {
    Panel::save(out);
    m_filename.save(out);
}

void ImagePanel::load(ifstream& in) {
    Panel::load(in);
    m_filename.load(in);
}

const HeplString ImagePanel::CLASS_NAME = "IMAGE_PANEL";
