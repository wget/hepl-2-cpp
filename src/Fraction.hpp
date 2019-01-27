#ifndef FRACTION_HPP_DEFINED
#define FRACTION_HPP_DEFINED

#include <cmath>
#include "FractionException.hpp"
#include "HeplList.hpp"
#include "HeplString.hpp"

enum Sign {
    POSITIVE = +1,
    NEGATIVE = -1
};

class EuclidException: public BaseException {
    using BaseException::BaseException;
};

class Fraction {
    private:
        unsigned int m_numerator;
        unsigned int m_denominator;
        Sign m_sign;

    public:
        /* Constructors/destructors */
        Fraction();
        Fraction(unsigned int n, unsigned int d, Sign s);
        Fraction(int n, int d);
        Fraction(int n);
        Fraction(Fraction const& other);

        /* Getters */
        unsigned int getNumerator() const;
        unsigned int getDenominator() const;
        Sign getSign() const;
        HeplString getAsString() const;

        /* Setters */
        void setNumerator(unsigned int numerator);
        void setDenominator(unsigned int denominator);
        void setSign(Sign sign);

        /* Other methods */
        bool isPositive() const;
        bool isNegative() const;
        bool isNull() const;
        void simplify();

        /* Operators overloading */
        Fraction& operator=(Fraction const& other);
        Fraction operator+(Fraction const& other);
        Fraction operator+(const int rhs);
        friend Fraction operator+(const int lhs, Fraction const& rhs);
        Fraction operator-(Fraction const& other);
        Fraction operator*(Fraction const& other);
        Fraction operator/(Fraction const& other);
        bool operator==(Fraction const& other) const;
        bool operator<(Fraction const other) const;
        bool operator<=(Fraction const& other) const;
        bool operator>(Fraction const other) const;
        bool operator>=(Fraction const& other) const;
        Fraction operator++();
        Fraction operator++(int);

        /* Stream management */
        friend std::ostream& operator<<(std::ostream& lhs, const Fraction& rhs);
        friend std::istream& operator>>(std::istream& lhs, Fraction& rhs);

        /* Static attributes */
        static const Fraction ONE;
        static const Fraction ZERO;
        static const Sign NEGATIVE = Sign::NEGATIVE;
        static const Sign POSITIVE = Sign::POSITIVE;

        /* Static methods */
        static unsigned int gcd(unsigned int m, unsigned int n);
};

#endif // FRACTION_HPP_DEFINED
