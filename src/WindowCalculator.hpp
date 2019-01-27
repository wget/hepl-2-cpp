#ifndef WINDOWCALCULATOR_HPP_INCLUDED
#define WINDOWCALCULATOR_HPP_INCLUDED

#include "Window.hpp"
#include "Calculator.hpp"
#include "HeplList.hpp"
#include "Panel.hpp"
#include "ImageButton.hpp"
#include "Button.hpp"
#include "ImagePanel.hpp"
#include "Color.hpp"


#define CALC_DISPLAY_ROWS 4
#define CALC_DISPLAY_COLUMNS 10
#define CALC_INPUT_COLUMNS 6

class WindowCalculator: public Window {
    private:
        HeplList<Panel> m_panelList;
        HeplList<ImageButton> m_buttonList;
        Button m_clearInputButton;
        ImagePanel m_display[CALC_DISPLAY_ROWS][CALC_DISPLAY_COLUMNS];
        ImagePanel m_input[CALC_INPUT_COLUMNS];
        Calculator *m_calculator;
        int m_displayPositionsX[CALC_DISPLAY_COLUMNS] =
            {20, 60, 100, 140, 180, 220, 260, 300, 340, 380};
        int m_displayPositionsY[CALC_DISPLAY_ROWS] =
            {170, 120, 70, 20};
        int m_inputPositionsX[CALC_INPUT_COLUMNS] =
            {20, 60, 100, 140, 180, 220};
        bool m_isInit;
        void resetDisplay();
        void resetInput();
        void redrawDisplay();
        void redrawInput();
        void stringToDigitRow(HeplString string, ImagePanel *array, size_t size, int positionY);

    public:
        WindowCalculator();
        void draw();
        void click(int x, int y);

        /* Getters */
        Calculator *getCalculator();

        /* Setters */
        void setColorPanelTop(const Color& color);
        void setColorPanelMiddle(const Color& color);
        void setColorPanelBottom(const Color& color);
        void setCalculator(Calculator *calculator);
        void setListener(Listener *listerner);
};

#endif // WINDOWCALCULATOR_HPP_INCLUDED
