#ifndef CALCULATOR_HPP_INCLUDED
#define CALCULATOR_HPP_INCLUDED

#include <cstdio>
#include "./lib/utils/src/HeplStack.hpp"
#include "./lib/utils/src/HeplBaseException.hpp"
#include "Fraction.hpp"

class Calculator {

    protected:
        HeplStack<Fraction> m_stack;
        HeplString m_input;
        bool m_mode;

    public:
        // Constructor/destructors
        Calculator();
        Calculator(Calculator& other);

        // Other methods
        void display() const;
        void inputNumber(unsigned int val);
        void clearInput();
        void plus();
        void minus();
        void multiply();
        void divide();
        void plusOrMinus();
        void erase();
        void changeMode();
        void enter();
        HeplString getInput();
        HeplString getStack(int index, size_t size);

};

class CalculatorException: public HeplBaseException {
    using HeplBaseException::HeplBaseException;
};

#endif // CALCULATOR_HPP_INCLUDED
