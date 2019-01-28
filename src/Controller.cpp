#include "Controller.hpp"

#include <iostream>

Controller::Controller() {
    m_calculator = nullptr;
    m_window = nullptr;
}

Controller::Controller(Calculator *calculator, WindowCalculator *window) {
    m_calculator = calculator;
    m_window = window;
}

Calculator *Controller::getCalculator() {
    return m_calculator;
}

WindowCalculator *Controller::getWindowCalculator() {
    return m_window;
}

void Controller::setCalculator(Calculator *calculator) {
    m_calculator = calculator;
}

void Controller::setWindowCalculator(WindowCalculator *window) {
    m_window = window;
}

void Controller::actionButton(const HeplString name) {

    try {
        if (name == "BUTTON_0") {
            m_calculator->inputNumber(0);
        } else if (name == "BUTTON_1") {
            m_calculator->inputNumber(1);
        } else if (name == "BUTTON_2") {
            m_calculator->inputNumber(2);
        } else if (name == "BUTTON_3") {
            m_calculator->inputNumber(3);
        } else if (name == "BUTTON_4") {
            m_calculator->inputNumber(4);
        } else if (name == "BUTTON_5") {
            m_calculator->inputNumber(5);
        } else if (name == "BUTTON_6") {
            m_calculator->inputNumber(6);
        } else if (name == "BUTTON_7") {
            m_calculator->inputNumber(7);
        } else if (name == "BUTTON_8") {
            m_calculator->inputNumber(8);
        } else if (name == "BUTTON_9") {
            m_calculator->inputNumber(9);
        } else if (name == "BUTTON_ERASE") {
            m_calculator->erase();
        } else if (name == "BUTTON_ENTER") {
            m_calculator->enter();
        } else if (name == "BUTTON_PLUS") {
            m_calculator->plus();
        } else if (name == "BUTTON_MINUS") {
            m_calculator->minus();
        } else if (name == "BUTTON_MULTIPLY") {
            m_calculator->multiply();
        } else if (name == "BUTTON_DIVIDE") {
            m_calculator->divide();
        } else if (name == "BUTTON_PLUS_OR_MINUS") {
            m_calculator->plusOrMinus();
        } else if (name == "BUTTON_DIGITAL") {
            m_calculator->changeMode();
        } else if (name == "BUTTON_CONFIG") {

        }

        m_window->draw();
    } catch (CalculatorException e) {
        std::cout << "CalculatorException caught: \"" << e.what() << "\"" << std::endl;
        m_window->setColorPanelTop(Color::RED);
        m_window->setColorPanelMiddle(Color::RED);
        m_window->setColorPanelBottom(Color::RED);
        m_window->draw();
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        m_window->setColorPanelTop(Color::SILVER);
        m_window->setColorPanelMiddle(Color::SILVER);
        m_window->setColorPanelBottom(Color::SILVER);
        m_window->draw();
    }
}
