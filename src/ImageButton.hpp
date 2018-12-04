#ifndef IMAGE_BUTTON_HPP_DEFINED
#define IMAGE_BUTTON_HPP_DEFINED

#include <iostream>
#include "Button.hpp"
#include "ImagePanel.hpp"
#include "Color.hpp"

class ImageButton : public virtual Button, public virtual ImagePanel {

    public:
        /* Constructors */
        ImageButton();
        ImageButton(const HeplString name, unsigned int x, unsigned int y, HeplString filename);
        ImageButton(const HeplString name, unsigned int x, unsigned int y,
              unsigned int width, unsigned int height, HeplString filename = "No file");
        ImageButton(const ImageButton &rhs);
        ~ImageButton();

        /* Setters */
        void setName(HeplString name) override;

        /* Other methods */
        void display() const;
        HeplString getType() const;

        /* Stream management */
        friend std::ostream& operator<<(std::ostream& lhs, const ImageButton& rhs);
        friend std::istream& operator>>(std::istream& lhs, ImageButton& rhs);

        /* Static attributes */
        static const HeplString CLASS_NAME;
};

#endif // IMAGE_BUTTON_HPP_DEFINED
