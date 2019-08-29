#include <iostream>
#include "WindowSDL/WindowSDL.hpp"
#include "Calculator.hpp"
#include "WindowCalculator.hpp"
#include "Controller.hpp"

using namespace std;

int main() {

    Calculator calculator;
    WindowCalculator windowCalculator;

    Controller controller(&calculator, &windowCalculator);

    windowCalculator.setListener(&controller);
    windowCalculator.setCalculator(&calculator);

    windowCalculator.setVisible(true);
    windowCalculator.draw();

    // Event loop
    while (true) {
        WindowSDLclick click = WindowSDL::waitClick();
        if (click.getX() == -1) {
            windowCalculator.setVisible(false);
            exit(EXIT_SUCCESS);
        }
        windowCalculator.click(click.getX(), click.getY());
    }
}

