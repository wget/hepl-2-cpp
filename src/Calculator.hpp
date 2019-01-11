#ifndef CALCULATOR_HPP_INCLUDED
#define CALCULATOR_HPP_INCLUDED

#include "HeplStack.hpp"
#include "Fraction.hpp"
#include "BaseException.hpp"
#include <iostream>

class Calculator {

    protected:
        HeplStack<Fraction> m_stack;
        HeplString m_input;
        bool m_mode;

    public:
        Calculator();
        Calculator(Calculator const& other);
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
        HeplString getStack(int index);

};

class CalculatorException: BaseException {
    using BaseException::BaseException;
};

#endif // CALCULATOR_HPP_INCLUDED
