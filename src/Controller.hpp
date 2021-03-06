#ifndef CONTROLLER_HPP_DEFINED
#define CONTROLLER_HPP_DEFINED

#include "Listener.hpp"
#include "Calculator.hpp"
#include "WindowCalculator.hpp"
#include "./lib/utils/src/HeplString.hpp"
#include <iostream>
#include <thread>
#include <chrono>

class Controller : public Listener {

    private:
        Calculator *m_calculator;
        WindowCalculator *m_window;
        void configureCalculator();

    public:
        /* Constructors */
        Controller();
        Controller(Calculator *calculator, WindowCalculator *window);

        /* Getters */
        Calculator *getCalculator();
        WindowCalculator *getWindowCalculator();

        /* Setters */
        void setCalculator(Calculator *calculator);
        void setWindowCalculator(WindowCalculator *window);

        /* Other methods */
        void actionButton(const HeplString name);

};

#endif // CONTROLLER_HPP_DEFINED
