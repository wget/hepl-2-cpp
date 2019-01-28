#include "WindowCalculator.hpp"

WindowCalculator::WindowCalculator()
    : m_clearInputButton("B_ClearSaisie", 330, 240, 90, 40, Color(250, 0, 0)) {
    m_isInit = true;

    setWidth(440);
    setHeight(470);
    setColor(Color::GREY);

    m_panelList.add(Panel("PANEL_TOP", 10, 10, 420, 210));
    m_panelList.add(Panel("PANEL_MIDDLE", 10, 230, 420, 60));
    m_panelList.add(Panel("PANEL_BOTTOM", 10, 300, 420, 160));

    resetDisplay();
    resetInput();

    m_buttonList.add(ImageButton("BUTTON_0",  20, 310, 40, 40, "images/button_0.bmp"));
    m_buttonList.add(ImageButton("BUTTON_1",  70, 310, 40, 40, "images/button_1.bmp"));
    m_buttonList.add(ImageButton("BUTTON_2", 120, 310, 40, 40, "images/button_2.bmp"));
    m_buttonList.add(ImageButton("BUTTON_3", 170, 310, 40, 40, "images/button_3.bmp"));
    m_buttonList.add(ImageButton("BUTTON_4", 220, 310, 40, 40, "images/button_4.bmp"));
    m_buttonList.add(ImageButton("BUTTON_5",  20, 360, 40, 40, "images/button_5.bmp"));
    m_buttonList.add(ImageButton("BUTTON_6",  70, 360, 40, 40, "images/button_6.bmp"));
    m_buttonList.add(ImageButton("BUTTON_7", 120, 360, 40, 40, "images/button_7.bmp"));
    m_buttonList.add(ImageButton("BUTTON_8", 170, 360, 40, 40, "images/button_8.bmp"));
    m_buttonList.add(ImageButton("BUTTON_9", 220, 360, 40, 40, "images/button_9.bmp"));

    m_buttonList.add(ImageButton("BUTTON_ERASE", 20, 410, 40, 40, "images/button_erase.bmp"));
    m_buttonList.add(ImageButton("BUTTON_ENTER", 145, 410, 40, 40, "images/button_enter.bmp"));
    m_buttonList.add(ImageButton("BUTTON_PLUS", 330, 310, 40, 40, "images/button_plus.bmp"));
    m_buttonList.add(ImageButton("BUTTON_MINUS", 380, 310, 40, 40, "images/button_minus.bmp"));
    m_buttonList.add(ImageButton("BUTTON_MULTIPLY", 330, 360, 40, 40, "images/button_multiply.bmp"));
    m_buttonList.add(ImageButton("BUTTON_DIVIDE", 380, 360, 40, 40, "images/button_divide.bmp"));
    m_buttonList.add(ImageButton("BUTTON_PLUS_OR_MINUS", 380, 410, 40, 40, "images/button_plus_or_minus.bmp"));
    m_buttonList.add(ImageButton("BUTTON_DIGITAL", 330, 410, 40, 40, "images/button_digit.bmp"));
    m_buttonList.add(ImageButton("BUTTON_CONFIG", 275, 410, 40, 40, "images/button_config.bmp"));
}

void WindowCalculator::resetDisplay() {
    for (unsigned int i = 0; i < CALC_DISPLAY_ROWS; i++) {
        for (int j = 0; j < CALC_DISPLAY_COLUMNS; j++) {
            m_display[i][j] = ImagePanel("Empty", m_displayPositionsX[j], m_displayPositionsY[i], 40, 40, "images/empty.bmp");
        }
    }
}

void WindowCalculator::resetInput() {
    for (unsigned int i = 0; i < CALC_INPUT_COLUMNS; i++) {
        m_input[i] = ImagePanel("Empty", m_inputPositionsX[i], 240, 40, 40, "images/empty.bmp");
    }
}

void WindowCalculator::redrawDisplay() {
    for (unsigned int i = 0; i < CALC_DISPLAY_ROWS; i++) {
        for (int j = 0; j < CALC_DISPLAY_COLUMNS; j++) {
            m_display[i][j].draw();
        }
    }
}

void WindowCalculator::redrawInput() {
    for (unsigned int i = 0; i < CALC_INPUT_COLUMNS; i++) {
        m_input[i].draw();
    }
}

void WindowCalculator::stringToDigitRow(HeplString string, ImagePanel *array, size_t size, int positionY) {
    for (size_t i = 0; i < string.size() && i < size; i++) {
        switch (string[i]) {
            case '0':
                array[i] = ImagePanel("DIGIT_0", m_displayPositionsX[i], positionY, 40, 40, "images/0.bmp");
                break;
            case '1':
                array[i] = ImagePanel("DIGIT_1", m_displayPositionsX[i], positionY, 40, 40, "images/1.bmp");
                break;
            case '2':
                array[i] = ImagePanel("DIGIT_2", m_displayPositionsX[i], positionY, 40, 40, "images/2.bmp");
                break;
            case '3':
                array[i] = ImagePanel("DIGIT_3", m_displayPositionsX[i], positionY, 40, 40, "images/3.bmp");
                break;
            case '4':
                array[i] = ImagePanel("DIGIT_4", m_displayPositionsX[i], positionY, 40, 40, "images/4.bmp");
                break;
            case '5':
                array[i] = ImagePanel("DIGIT_5", m_displayPositionsX[i], positionY, 40, 40, "images/5.bmp");
                break;
            case '6':
                array[i] = ImagePanel("DIGIT_6", m_displayPositionsX[i], positionY, 40, 40, "images/6.bmp");
                break;
            case '7':
                array[i] = ImagePanel("DIGIT_7", m_displayPositionsX[i], positionY, 40, 40, "images/7.bmp");
                break;
            case '8':
                array[i] = ImagePanel("DIGIT_8", m_displayPositionsX[i], positionY, 40, 40, "images/8.bmp");
                break;
            case '9':
                array[i] = ImagePanel("DIGIT_9", m_displayPositionsX[i], positionY, 40, 40, "images/9.bmp");
                break;
            case '/':
                array[i] = ImagePanel("FRACTION_BAR", m_displayPositionsX[i], positionY, 40, 40, "images/fraction_bar.bmp");
                break;
            case '-':
                array[i] = ImagePanel("MINUS", m_displayPositionsX[i], positionY, 40, 40, "images/minus.bmp");
                break;
            case '.':
                array[i] = ImagePanel("COMMA", m_displayPositionsX[i], positionY, 40, 40, "images/comma.bmp");
                break;
        }
    }
}

void WindowCalculator::draw() {

    if (m_isInit) {
        // Redraw window background
        Window::draw();

        // Redraw the 3 panels
        BaseListIterator<Panel> panelListIt(m_panelList);
        for (panelListIt.reset(); !panelListIt.end(); panelListIt++) {
            (&panelListIt)->draw();
        }

        // Redraw the buttons
        BaseListIterator<ImageButton> buttonListIt(m_buttonList);
        for (buttonListIt.reset(); !buttonListIt.end(); buttonListIt++) {
            (&buttonListIt)->draw();
        }

        redrawDisplay();
        redrawInput();

        m_isInit = false;
        return;
    }

    // Update display
    resetDisplay();
    for (int i = 0; i < CALC_DISPLAY_ROWS; i++) {
        try {
            stringToDigitRow(m_calculator->getStack(i, CALC_DISPLAY_COLUMNS), m_display[CALC_DISPLAY_ROWS - i - 1], CALC_DISPLAY_COLUMNS, m_displayPositionsY[i]);
        } catch (BaseListItemNotFoundException *e) {
            break;
        }
    }
    redrawDisplay();

    // Update input
    HeplString input = m_calculator->getInput();
    if (input.empty()) {
        resetInput();
    } else {
        stringToDigitRow(input, m_input, CALC_INPUT_COLUMNS, 240);
    }
    redrawInput();
}

void WindowCalculator::click(int x, int y) {
    BaseListIterator<ImageButton> buttonListIt(m_buttonList);
    for (buttonListIt.reset(); !buttonListIt.end(); buttonListIt++) {
        (&buttonListIt)->click(x, y);
    }
}

Calculator *WindowCalculator::getCalculator() {
    return m_calculator;
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

void WindowCalculator::setCalculator(Calculator *calculator) {
    m_calculator = calculator;
}

void WindowCalculator::setListener(Listener *listener) {
    BaseListIterator<ImageButton> buttonListIt(m_buttonList);
    for (buttonListIt.reset(); !buttonListIt.end(); buttonListIt++) {
        (&buttonListIt)->setListener(listener);
    }
}
