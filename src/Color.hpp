#ifndef COLOR_HPP_INCLUDED
#define COLOR_HPP_INCLUDED

#include <iostream>
#include <iostream>
#include <fstream>
#include "./lib/src/HeplString.hpp"
#include "./lib/src/HeplList.hpp"

class Color {

    private:
        // Attributes
        int m_red;
        int m_green;
        int m_blue;
        HeplString m_name;
        static int m_instanceCounter;

    public:
        // Constructors/destructors
        Color();
        Color(int greyValue);
        Color(int red, int green, int blue);
        Color(int red, int green, int blue, HeplString name);
        Color(const Color *other);
        Color(Color const& other);
        ~Color();

        // Getters
        int getRed() const;
        int getGreen() const;
        int getBlue() const;
        HeplString getName() const;
        int getLuminance() const;

        // Setters
        void setRed(int value);
        void setGreen(int value);
        void setBlue(int value);
        void setGrey(int value);
        void setName(HeplString name);

        // Other methods
        void display() const;
        static int getInstanceCounter();

        // Operators
        Color& operator=(Color const& other);
        Color& operator+=(Color const& other);
        Color operator+(Color const& other);
        friend Color operator+(Color const& lhs, Color const& rhs);
        Color& operator+=(const int luminance);
        Color operator+(const int luminance);
        friend Color operator+(const int luminance, Color const& other);
        Color& operator-=(Color const& other);
        Color operator-(Color const& other);
        friend Color operator-(Color const& lhs, Color const& rhs);
        Color operator-(const int luminance);
        friend Color operator-(const int luminance, Color const& other);
        bool operator==(const Color& rhs) const;
        bool operator>(const Color& rhs) const;
        bool operator<(const Color& rhs) const;
        bool operator<=(const Color& rhs) const;
        bool operator>=(const Color& rhs) const;
        Color operator++();
        Color operator++(int);
        Color operator--();
        Color operator--(int);

        // Stream management
        friend std::ostream& operator<<(std::ostream& lhs, const Color& rhs);
        friend std::istream& operator>>(std::istream& lhs, Color& rhs);
        void save(std::ofstream& out) const;
        void load(std::ifstream& in);

        // Static attributes
        static const Color RED;
        static const Color GREEN;
        static const Color BLUE;
        static const Color GREY;
        static const Color SILVER;
};

// Needed to have the declaration here to avoid circular dependencies:
// InvalidColorException requires Color but Color requires
// InvalidColorException.
#include "InvalidColorException.hpp"

#endif // COLOR_HPP_INCLUDED
