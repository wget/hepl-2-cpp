#ifndef BUTTON_HPP_DEFINED
#define BUTTON_HPP_DEFINED

#include "Panel.hpp"
#include "Listener.hpp"

class Button: public virtual Panel {

    protected:
        Listener *m_listener;

    public:
        // Constructors
        Button();
        Button(const HeplString name, unsigned int x, unsigned int y,
              unsigned int width, unsigned int height, const Color& color = Color::BLUE);
        Button(const Button &rhs);
        ~Button();

        // Getters
        Listener* getListener() const;

        // Setters
        void setName(HeplString name) override;
        void setListener(Listener *listener);

        // Other methods
        void display() const;
        void click(int x, int y) const;
        HeplString getType() const;

        // Operators
        Button& operator=(const Button&) = default;

        // Stream management
        friend std::ostream& operator<<(std::ostream& lhs, const Button& rhs);
        friend std::istream& operator>>(std::istream& lhs, Button& rhs);

        // Static attributes
        static const HeplString CLASS_NAME;
};

#endif // BUTTON_HPP_DEFINED
