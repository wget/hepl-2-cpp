#include "Fraction.hpp"

using namespace std;

Fraction::Fraction()
    : Fraction(Fraction::ONE) {
#ifdef WITH_DEBUG
    cout << "In default constructor: Fraction::Fraction()" << endl;
#endif
}

Fraction::Fraction(unsigned int n, unsigned int d, Sign s)
    : m_numerator(n), m_denominator(d), m_sign(s) {
#ifdef WITH_DEBUG
    cout << "In initialization constructor: Fraction::Fraction(unsigned int n, unsigned int d, Sign s)" << endl;
#endif
}

Fraction::Fraction(int n, int d)
    : m_numerator(abs(n)), m_denominator(abs(d)) {
#ifdef WITH_DEBUG
    cout << "In initialization constructor: Fraction::Fraction(int n, int d)" << endl;
#endif
    if (n * d >= 0) {
        m_sign = Sign::POSITIVE;
    } else {
        m_sign = Sign::NEGATIVE;
    }
}

Fraction::Fraction(int n)
    : m_numerator(abs(n)), m_denominator(1) {
#ifdef WITH_DEBUG
    cout << "In initialization constructor: Fraction::Fraction(int n)" << endl;
#endif
    if (n >= 0) {
        m_sign = Sign::POSITIVE;
    } else {
        m_sign = Sign::NEGATIVE;
    }
}

Fraction::Fraction(Fraction const& other)
    : Fraction(other.getNumerator(), other.getDenominator(), other.getSign()) {
#ifdef WITH_DEBUG
    cout << "In copy constructor: Fraction::Fraction(Fraction const& other)" << endl;
#endif
}

/**
 * Getters
 */
unsigned int Fraction::getNumerator() const {
    return m_numerator;
}

unsigned int Fraction::getDenominator() const {
    return m_denominator;
}

Sign Fraction::getSign() const {
    return m_sign;
}

/**
 * Setters
 */
void Fraction::setNumerator(unsigned int numerator) {
    m_numerator = numerator;
}
    
void Fraction::setDenominator(unsigned int denominator) {
    if (denominator == 0) {
        throw InvalidFractionException("Denominator cannot be 0");
    }
    m_denominator = denominator;
}

void Fraction::setSign(Sign sign) {
    m_sign = sign;
}

/**
 * Other methods
 */
bool Fraction::isPositive() const {
    if (getNumerator() != 0 && getSign() == Sign::POSITIVE) {
        return true;
    }
    return false;
}

bool Fraction::isNegative() const {
    if (getNumerator() != 0 && getSign() == Sign::NEGATIVE) {
        return true;
    }
    return false;
}

bool Fraction::isNull() const {
    if (getNumerator() == 0) {
        return true;
    }
    return false;
}

void Fraction::simplify() {
    unsigned int gcdValue = Fraction::gcd(getNumerator(), getDenominator());
    m_numerator /= gcdValue;
    m_denominator /= gcdValue;
}

/**
 * Operators overloading
 */
Fraction& Fraction::operator=(Fraction const& other) {
    // Avoid infinite loops
    if (this == &other) {
        return *this;
    }
    setNumerator(other.getNumerator());
    setDenominator(other.getDenominator());
    setSign(other.getSign());
    return *this;
}

Fraction Fraction::operator+(Fraction const& other) {
    Fraction newFraction = *this;
    Fraction otherFraction = other;
    // Force same denominator when fractions are not equivalent
    if (newFraction.getDenominator() != other.getDenominator()) {
        unsigned int newFractionDenominator = newFraction.getDenominator();
        newFraction.setNumerator(newFraction.getNumerator() * other.getDenominator());
        newFraction.setDenominator(newFraction.getDenominator() * other.getDenominator());
        otherFraction.setNumerator(otherFraction.getNumerator() * newFractionDenominator);
        // Not really needed since we are only making use of newFraction any way.
        otherFraction.setDenominator(otherFraction.getDenominator() * newFractionDenominator);
    }
    int newFractionSign = (newFraction.getSign() == Sign::NEGATIVE) ? -1 : 1;
    int otherFractionSign = (otherFraction.getSign() == Sign::NEGATIVE) ? -1 : 1;
    int newValue = newFractionSign * newFraction.getNumerator() + otherFractionSign * otherFraction.getNumerator();
    newFraction.setNumerator(abs(newValue));
    if (newValue < 0) {
        newFraction.setSign(Sign::NEGATIVE);
    } else {
        newFraction.setSign(Sign::POSITIVE);
    }
    newFraction.simplify();
    return newFraction;
}

Fraction Fraction::operator+(const int rhs) {
    Fraction newFraction = *this;
    int newFractionSign = (newFraction.getSign() == Sign::NEGATIVE) ? -1 : 1;
    int newValue = newFractionSign * newFraction.getNumerator() + rhs * newFraction.getDenominator();
    newFraction.setNumerator(abs(newValue));
    if (newValue < 0) {
        newFraction.setSign(Sign::NEGATIVE);
    } else {
        newFraction.setSign(Sign::POSITIVE);
    }
    //newFraction.setDenominator(newFraction.getDenominator());
    newFraction.simplify();
    return newFraction;
}

Fraction operator+(const int lhs, Fraction const& rhs) {
    Fraction newFraction;
    newFraction.setNumerator(abs(lhs));
    newFraction.setDenominator(1);
    newFraction.setSign((lhs < 0)? Sign::NEGATIVE: Sign::POSITIVE);
    return newFraction + rhs;
}

Fraction Fraction::operator-(Fraction const& other) {
    Fraction newFraction = *this;
    Fraction otherFraction = other;
    // Same as +, let's just change the sign of the fraction.
    if (otherFraction.getSign() == Sign::NEGATIVE) {
        otherFraction.setSign(Sign::POSITIVE);
    } else {
        otherFraction.setSign(Sign::NEGATIVE);
    }
    return newFraction + otherFraction;
}

Fraction Fraction::operator*(Fraction const& other) {
    Fraction newFraction = *this;
    int newFractionSign = (newFraction.getSign() == Sign::NEGATIVE) ? -1 : 1;
    int otherFractionSign = (other.getSign() == Sign::NEGATIVE) ? -1 : 1;
    int newValue = newFractionSign * newFraction.getNumerator() * otherFractionSign * other.getNumerator();
    newFraction.setNumerator(abs(newValue));
    newFraction.setDenominator(newFraction.getDenominator() * other.getDenominator());
    if (newValue < 0) {
        newFraction.setSign(Sign::NEGATIVE);
    } else {
        newFraction.setSign(Sign::POSITIVE);
    }
    newFraction.simplify();
    return newFraction;
}

Fraction Fraction::operator/(Fraction const& other) {
    Fraction newFraction = *this;
    Fraction otherFraction = other;
    // Same as A * B, except B has been numerator and denominator values
    // swapped.
    unsigned int invertValue = otherFraction.getNumerator();
    otherFraction.setNumerator(otherFraction.getDenominator());
    otherFraction.setDenominator(invertValue);
    return newFraction * otherFraction;
}

bool Fraction::operator==(Fraction const& other) {
    int fractionSign = (getSign() == Sign::NEGATIVE) ? -1 : 1;
    int otherFractionSign = (other.getSign() == Sign::NEGATIVE) ? -1 : 1;
    if (fractionSign * getNumerator() * other.getDenominator() ==
        otherFractionSign * getDenominator() * other.getNumerator()) {
        return true;
    }
    return false;
}

bool Fraction::operator<(Fraction const& other) {
    Fraction newFraction = *this;
    Fraction otherFraction = other;
    // Force same denominator when fractions are not equivalent
    if (newFraction.getDenominator() != other.getDenominator()) {
        unsigned int newFractionDenominator = newFraction.getDenominator();
        newFraction.setNumerator(newFraction.getNumerator() * other.getDenominator());
        newFraction.setDenominator(newFraction.getDenominator() * other.getDenominator());
        otherFraction.setNumerator(otherFraction.getNumerator() * newFractionDenominator);
        // Not really needed since we are only making use of newFraction any way.
        otherFraction.setDenominator(otherFraction.getDenominator() * newFractionDenominator);
    }
    int newFractionSign = (newFraction.getSign() == Sign::NEGATIVE)? -1 : 1;
    int otherFractionSign = (otherFraction.getSign() == Sign::NEGATIVE)? -1 : 1;

    if (newFractionSign * newFraction.getNumerator() <
        otherFractionSign * otherFraction.getNumerator()) {
        return true;
    }
    return false;
}

bool Fraction::operator>(Fraction const& other) {
    if (*this == other) {
        return false;
    }

    if (*this < other) {
        return false;
    }

    return true;
}

// Prefix ++Fraction;
Fraction Fraction::operator++() {
    return (*this) + 1;
}

// Postfix Fraction++;
Fraction Fraction::operator++(int) {
    Fraction newFraction(*this);
    *this = (*this) + 1;
    return newFraction;
}

/**
 * Stream management
 */
std::ostream& operator<<(std::ostream& lhs, const Fraction& rhs) {

    if (rhs.getNumerator() == 0) {
        lhs << 0 << endl;
        return lhs;
    }

    if (rhs.getSign() == Sign::NEGATIVE) {
        lhs << '-';
    }

    if (rhs.getDenominator() == 1) {
        lhs << rhs.getNumerator() << endl;
    } else {
        lhs << rhs.getNumerator() << '/' << rhs.getDenominator() << endl;
    }
    return lhs;
}

istream& operator>>(istream& lhs, Fraction& rhs) {
    HeplString userInput;
    HeplList<HeplString> exploded;
    unsigned int numerator, denominator;
    Sign sign;

    do {
        cout << "Specify the fraction value under the following format:" << endl
             << "numerator denominator sign: ";
        lhs >> userInput;

        exploded = userInput.explode(" ");
        if (exploded.getNumberItems() != 3 ||
            ! exploded[0]->isNumber() ||
            ! exploded[1]->isNumber() ||
            (((HeplString)exploded[2])[0] != '+' && ((HeplString)exploded[2])[0] != '-')) {
            cout << "The syntax is incorrect. Ensure you used the following valid format:" << endl
                 << "numerator denominator sign." << endl;
            continue;
        }

        numerator = exploded[0]->atoi();
        denominator = exploded[1]->atoi();
        if (((HeplString)exploded[2])[0] == '+') {
            sign = Sign::POSITIVE;
        } else {
            sign = Sign::NEGATIVE;
        }

        try {
            rhs.setNumerator(numerator);
            rhs.setDenominator(denominator);
            rhs.setSign(sign);

        } catch (InvalidFractionException &e) {
            cout << "An InvalidFractionException has been caught: " + e.what() << endl;
            continue;
        }

        break;

    } while (true);

    return lhs;
}

/**
 * Static attributes
 */
const Fraction Fraction::ONE = Fraction(1, 1, Sign::POSITIVE);
const Fraction Fraction::ZERO = Fraction(0, 1, Sign::POSITIVE);

/**
 * Static methods
 */
// src.: https://codereview.stackexchange.com/a/37200
unsigned int Fraction::gcd(unsigned int m, unsigned int n) {

    // Input validation. No need to check whether input is negative because we
    // are using unsigned int.
    if (m == 0 || n == 0) {
        throw EuclidException();
    }

    int r;
    while (n) {
        r = m % n;
        m = n;
        n = r;
    }
    return m;
}
