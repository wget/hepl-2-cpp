#include "WindowCalculator.hpp"


#include <iostream>
WindowCalculator::WindowCalculator()
    : m_clearInputButton("B_ClearSaisie", 330, 240, 90, 40, Color(250, 0, 0)) {
    setWidth(440);
    setHeight(470);
    setColor(Color::GREY);
    m_panelList.add(Panel("PANEL_TOP", 10, 10, 420, 210));
    m_panelList.add(Panel("PANEL_MIDDLE", 10, 230, 420, 60));
    m_panelList.add(Panel("PANEL_BOTTOM", 10, 300, 420, 160));

    int positionsX[CALC_DISPLAY_COLUMNS] =
        {20, 60, 100, 140, 180, 220, 260, 300, 340, 380};
    int positionsY[CALC_DISPLAY_ROWS] = 
        {170, 120, 70, 20};
    for (int i = 0; i < CALC_DISPLAY_ROWS; i++) {
        for (int j = 0; j < CALC_DISPLAY_COLUMNS; j++) {
            m_display[i][j] = ImagePanel("Empty", positionsX[j], positionsY[i], 40, 40,  "images/empty.bmp");
        }
    }

    int positionsInputX[CALC_INPUT_COLUMNS] = {20, 60, 100, 140, 180, 220};
    for (int i = 0; i < CALC_INPUT_COLUMNS; i++) {
        m_input[i] = ImagePanel("Empty", positionsX[i], 240, 40, 40, "images/empty.bmp");
    }

    m_buttonList.add(ImageButton("BUTTON_0",  20, 310, 40, 40, "images/0.bmp"));
    m_buttonList.add(ImageButton("BUTTON_1",  70, 310, 40, 40, "images/1.bmp"));
    m_buttonList.add(ImageButton("BUTTON_2", 120, 310, 40, 40, "images/2.bmp"));
    m_buttonList.add(ImageButton("BUTTON_3", 170, 310, 40, 40, "images/3.bmp"));
    m_buttonList.add(ImageButton("BUTTON_4", 220, 310, 40, 40, "images/4.bmp"));
    m_buttonList.add(ImageButton("BUTTON_5",  20, 360, 40, 40, "images/5.bmp"));
    m_buttonList.add(ImageButton("BUTTON_6",  70, 360, 40, 40, "images/6.bmp"));
    m_buttonList.add(ImageButton("BUTTON_7", 120, 360, 40, 40, "images/7.bmp"));
    m_buttonList.add(ImageButton("BUTTON_8", 170, 360, 40, 40, "images/8.bmp"));
    m_buttonList.add(ImageButton("BUTTON_9", 220, 360, 40, 40, "images/9.bmp"));

    m_buttonList.add(ImageButton("BUTTON_ERASE", 20, 410, 40, 40, "images/button_erase.bmp"));
    m_buttonList.add(ImageButton("BUTTON_ENTER", 145, 410, 40, 40, "images/button_enter.bmp"));
    m_buttonList.add(ImageButton("BUTTON_PLUS", 330, 310, 40, 40, "images/button_plus.bmp"));
    m_buttonList.add(ImageButton("BUTTON_MINUS", 380, 310, 40, 40, "images/button_minus.bmp"));
    m_buttonList.add(ImageButton("BUTTON_MULTIPLY", 330, 360, 40, 40, "images/button_multiply.bmp"));
    m_buttonList.add(ImageButton("BUTTON_DIVIDE", 380, 360, 40, 40, "images/button_divide.bmp"));
    m_buttonList.add(ImageButton("BUTTON_PLUS_OR_MINUS", 380, 410, 40, 40, "images/button_plus_or_minus.bmp"));
    m_buttonList.add(ImageButton("BUTTON_DIGITAL", 330, 410, 40, 40, "images/button_digit.bmp"));
    m_buttonList.add(ImageButton("BUTTON_CONFIG", 275, 410, 40, 40, "images/button_config.bmp"));
        std::cout << "in WindowCalculator constructor" << std::endl;
}

void WindowCalculator::draw() {
        std::cout << "WindowCalculator::draw()" << std::endl;
    Window::draw();
        std::cout << "back in WindowCalculator::draw()" << std::endl;
    BaseListIterator<Panel> panelListIt(m_panelList);
    for (panelListIt.reset(); !panelListIt.end(); panelListIt++) {
        ((Panel)panelListIt).draw();

        std::cout << "iterating" << std::endl;
    }
    BaseListIterator<ImageButton> buttonListIt(m_buttonList);
    for (buttonListIt.reset(); !buttonListIt.end(); buttonListIt++) {
        std::cout << "iterating imagebutton" << std::endl;
        ((ImageButton)buttonListIt).display();
        ((ImageButton)buttonListIt).draw();
    }

    for (int i = 0; i < CALC_DISPLAY_ROWS; i++) {
        for (int j = 0; j < CALC_DISPLAY_COLUMNS; j++) {
        std::cout << "iterating m_display" << i << " " << j << std::endl;
            m_display[i][j].draw();
        }
    }

    for (int i = 0; i < CALC_INPUT_COLUMNS; i++) {
        std::cout << "iterating m_input" << std::endl;
        m_input[i].draw();
    }
}

void WindowCalculator::setColorPanelTop(const Color& color) {
    ((Panel)m_panelList[0]).setColor(color);
}

void WindowCalculator::setColorPanelMiddle(const Color& color) {
    ((Panel)m_panelList[1]).setColor(color);
}

void WindowCalculator::setColorPanelBottom(const Color& color) {
    ((Panel)m_panelList[2]).setColor(color);
}
