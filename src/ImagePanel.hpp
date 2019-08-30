#ifndef IMAGE_PANEL_HPP_DEFINED
#define IMAGE_PANEL_HPP_DEFINED

#include "./WindowSDL/WindowSDL.hpp"
#include "./WindowSDL/WindowSDLimage.hpp"
#include "Panel.hpp"

class ImagePanel: public virtual Panel {

    protected:
        HeplString m_filename;
        WindowSDLimage *m_image;

    public:
        // Constructors/destructors
        ImagePanel();
        ImagePanel(const HeplString name, unsigned int x, unsigned int y, HeplString filename);
        ImagePanel(const HeplString name, unsigned int x, unsigned int y,
              unsigned int width, unsigned int height, HeplString filename = "No file");
        ImagePanel(const ImagePanel &rhs);
        ~ImagePanel();

        // Getters
        HeplString getFilename() const;

        // Setters
        void setFilename(HeplString filename);

        // Other methods
        void display() const;
        HeplString getType() const;
        void draw() const;

        // Operators
        ImagePanel& operator=(const ImagePanel&) = default;

        // Stream management
        friend std::ostream& operator<<(std::ostream& lhs, const ImagePanel& rhs);
        friend std::istream& operator>>(std::istream& lhs, ImagePanel& rhs);
        void save(std::ofstream& out) const;
        void load(std::ifstream& in);

        // Static attributes
        static const HeplString CLASS_NAME;
};

#endif // IMAGE_PANEL_HPP_DEFINED
