#include "Calculator.hpp"

Calculator::Calculator() {
}

Calculator::Calculator(Calculator const& other): m_input(other.m_input) {
    m_stack = other.m_stack;
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
        throw new CalculatorException("Not enough terms for plus");
    }
    Fraction b = m_stack.pop() ;
    Fraction a = m_stack.pop() ;
    Fraction result = a + b ;
    m_stack.push(result) ;
}

void Calculator::minus() {
    if (m_stack.getNumberItems() < 2) {
        throw new CalculatorException("Not enough terms for minus");
    }
    Fraction b = m_stack.pop() ;
    Fraction a = m_stack.pop() ;
    Fraction result = a - b ;
    m_stack.push(result) ;
}

void Calculator::multiply() {
    if (m_stack.getNumberItems() < 2) {
        throw new CalculatorException("Not enough terms for multiply");
    }
    Fraction b = m_stack.pop() ;
    Fraction a = m_stack.pop() ;
    Fraction result = a * b ;
    m_stack.push(result) ;
}

void Calculator::divide() {
    if (m_stack.getNumberItems() < 2) {
        throw new CalculatorException("Not enough terms for divide");
    }
    Fraction b = m_stack.pop() ;
    Fraction a = m_stack.pop() ;
    Fraction result = a / b ;
    m_stack.push(result) ;
}

void Calculator::plusOrMinus() {
    if (m_stack.getNumberItems() < 2) {
        throw new CalculatorException("Not enough terms for plus or minus");
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

HeplString Calculator::getStack(int index) {

    Fraction f = m_stack[index];
    HeplString string;

    if (m_mode) {
        if (f.getNumerator() == 0) {
            string << 0 << "\n";
            return string;
        }

        if (f.getSign() == Sign::NEGATIVE) {
            string << '-';
        }

        if (f.getDenominator() == 1) {
            string << f.getNumerator() << "\n";
        } else {
            string << f.getNumerator() << '/' << f.getDenominator() << "\n";
        }
        return string;
    }

    int sign = (f.getSign() == Sign::NEGATIVE) ? -1 : 1;
    float divide = sign * (f.getNumerator() / f.getDenominator());

    string = string.ftoa(divide);
}
