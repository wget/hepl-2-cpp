#include "Calculator.hpp"

Calculator::Calculator(): m_stack(), m_input(), m_mode(true) {
}

Calculator::Calculator(Calculator& other): m_stack(other.m_stack), m_input(other.m_input), m_mode(other.m_mode) {
}

void Calculator::display() const {
    std::cout << "[+] Stack content:" << std::endl;
    m_stack.display();
    std::cout << "[+] Input content:" << std::endl;
    std::cout << m_input << std::endl;
}

void Calculator::inputNumber(unsigned int val) {
    m_input += HeplString(val);
}

void Calculator::clearInput() {
    m_input.clear();
}

void Calculator::plus() {
    if (m_stack.getNumberItems() < 2) {
        throw CalculatorException("Not enough terms for plus");
    }
    Fraction b = m_stack.pop();
    Fraction a = m_stack.pop();
    Fraction result = a + b ;
    m_stack.push(result) ;
}

void Calculator::minus() {
    if (m_stack.getNumberItems() < 2) {
        throw CalculatorException("Not enough terms for minus");
    }
    Fraction b = m_stack.pop();
    Fraction a = m_stack.pop();
    Fraction result = a - b ;
    m_stack.push(result) ;
}

void Calculator::multiply() {
    if (m_stack.getNumberItems() < 2) {
        throw CalculatorException("Not enough terms for multiply");
    }
    Fraction b = m_stack.pop();
    Fraction a = m_stack.pop();
    Fraction result = a * b ;
    m_stack.push(result) ;
}

void Calculator::divide() {
    if (m_stack.getNumberItems() < 2) {
        throw CalculatorException("Not enough terms for divide");
    }
    Fraction b = m_stack.pop();
    Fraction a = m_stack.pop();
    try {
        Fraction result = a / b ;
        m_stack.push(result);
    } catch (FractionException e) {
        m_stack.push(a);
        throw CalculatorException("Invalid fraction division");
    }
}

void Calculator::plusOrMinus() {
    if (m_stack.getNumberItems() < 2) {
        throw CalculatorException("Not enough terms for plus or minus");
    }
    Fraction f = m_stack.pop();
    if (f.isPositive()) {
        f.setSign(Sign::NEGATIVE);
    } else {
        f.setSign(Sign::POSITIVE);
    }
    m_stack.push(f);
}

void Calculator::erase() {
    m_input.clear();
    m_stack = HeplStack<Fraction>();
}

void Calculator::changeMode() {
    m_mode = !m_mode;
}

void Calculator::enter() {
    Fraction f;
    f.setNumerator(m_input.atoi());
    m_stack.push(f);
    m_input.clear();
}

HeplString Calculator::getInput() {
    return m_input;
}

HeplString Calculator::getStack(int index, size_t size) {

    Fraction f = m_stack[index];

    if (m_mode) {
        return f.getAsString();
    }

    double divide;
    if (f.getSign() == Sign::NEGATIVE) {
        divide = -1 * ((double)f.getNumerator()) / ((double)f.getDenominator());
    } else {
        divide = ((double)f.getNumerator()) / ((double)f.getDenominator());
    }

    // If debugging purpose, we need to specify the precision
    // std::cout << "DEBUG double :\"" << std::setprecision(10) << divide << "\"" << std::endl;
    // don't foget to include <stdio> and <iomanip>

    // We can't use our own function here string.ftoa(<float>, <precision>)
    // because we are loosing to much precision
    char buffer[size + 1];
    snprintf(buffer, size + 1, "%f", divide);
    buffer[size + 1] = '\0';
    HeplString string(buffer);
    return string;
}
