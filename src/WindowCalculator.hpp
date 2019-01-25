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

    public:
        WindowCalculator();
        void draw();
        void setColorPanelTop(const Color& color);
        void setColorPanelMiddle(const Color& color);
        void setColorPanelBottom(const Color& color);


};

#endif // WINDOWCALCULATOR_HPP_INCLUDED
