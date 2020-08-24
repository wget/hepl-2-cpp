#include "WindowCalculator.hpp"

WindowCalculator::WindowCalculator()
    : m_clearInputButton("B_ClearSaisie", 330, 240, 90, 40, Color(250, 0, 0)) {

    m_cwd = this->getCurrentWorkingDirectory();

    setWidth(440);
    setHeight(470);
    setColor(Color::GREY);

    m_panelList.add(Panel("PANEL_TOP", 10, 10, 420, 210));
    m_panelList.add(Panel("PANEL_MIDDLE", 10, 230, 420, 60));
    m_panelList.add(Panel("PANEL_BOTTOM", 10, 300, 420, 160));

    // // Init model
    // resetDisplay();
    // resetInput();

    m_buttonList.add(ImageButton("BUTTON_0",  20, 310, 40, 40, m_cwd + "/images/button_0.bmp"));
    m_buttonList.add(ImageButton("BUTTON_1",  70, 310, 40, 40, m_cwd + "/images/button_1.bmp"));
    m_buttonList.add(ImageButton("BUTTON_2", 120, 310, 40, 40, m_cwd + "/images/button_2.bmp"));
    m_buttonList.add(ImageButton("BUTTON_3", 170, 310, 40, 40, m_cwd + "/images/button_3.bmp"));
    m_buttonList.add(ImageButton("BUTTON_4", 220, 310, 40, 40, m_cwd + "/images/button_4.bmp"));
    m_buttonList.add(ImageButton("BUTTON_5",  20, 360, 40, 40, m_cwd + "/images/button_5.bmp"));
    m_buttonList.add(ImageButton("BUTTON_6",  70, 360, 40, 40, m_cwd + "/images/button_6.bmp"));
    m_buttonList.add(ImageButton("BUTTON_7", 120, 360, 40, 40, m_cwd + "/images/button_7.bmp"));
    m_buttonList.add(ImageButton("BUTTON_8", 170, 360, 40, 40, m_cwd + "/images/button_8.bmp"));
    m_buttonList.add(ImageButton("BUTTON_9", 220, 360, 40, 40, m_cwd + "/images/button_9.bmp"));

    m_buttonList.add(ImageButton("BUTTON_ERASE", 20, 410, 40, 40, m_cwd + "/images/button_erase.bmp"));
    m_buttonList.add(ImageButton("BUTTON_ENTER", 145, 410, 40, 40, m_cwd + "/images/button_enter.bmp"));
    m_buttonList.add(ImageButton("BUTTON_PLUS", 330, 310, 40, 40, m_cwd + "/images/button_plus.bmp"));
    m_buttonList.add(ImageButton("BUTTON_MINUS", 380, 310, 40, 40, m_cwd + "/images/button_minus.bmp"));
    m_buttonList.add(ImageButton("BUTTON_MULTIPLY", 330, 360, 40, 40, m_cwd + "/images/button_multiply.bmp"));
    m_buttonList.add(ImageButton("BUTTON_DIVIDE", 380, 360, 40, 40, m_cwd + "/images/button_divide.bmp"));
    m_buttonList.add(ImageButton("BUTTON_PLUS_OR_MINUS", 380, 410, 40, 40, m_cwd + "/images/button_plus_or_minus.bmp"));
    m_buttonList.add(ImageButton("BUTTON_DIGITAL", 330, 410, 40, 40, m_cwd + "/images/button_digit.bmp"));
    m_buttonList.add(ImageButton("BUTTON_CONFIG", 275, 410, 40, 40, m_cwd + "/images/button_config.bmp"));

    m_forceRedraw = true;
}

void WindowCalculator::resetDisplay() {
    for (size_t i = 0; i < CALC_DISPLAY_ROWS; i++) {
        for (size_t j = 0; j < CALC_DISPLAY_COLUMNS; j++) {
            m_display[i][j] = ImagePanel("Empty", m_displayPositionsX[j], m_displayPositionsY[i], 40, 40, m_cwd + "/images/empty.bmp");
        }
    }
}

void WindowCalculator::resetInput() {
    for (size_t i = 0; i < CALC_INPUT_COLUMNS; i++) {
        m_input[i] = ImagePanel("Empty", m_inputPositionsX[i], 240, 40, 40, m_cwd + "/images/empty.bmp");
    }
}

void WindowCalculator::redrawPanels() {
    HeplBaseListIterator<Panel> panelListIt(m_panelList);
    for (panelListIt.reset(); !panelListIt.end(); panelListIt++) {
        (&panelListIt)->draw();
    }
}

void WindowCalculator::redrawDisplay() {
    for (size_t i = 0; i < CALC_DISPLAY_ROWS; i++) {
        for (size_t j = 0; j < CALC_DISPLAY_COLUMNS; j++) {
            m_display[i][j].draw();
        }
    }
}

void WindowCalculator::redrawInput() {
    for (size_t i = 0; i < CALC_INPUT_COLUMNS; i++) {
        m_input[i].draw();
    }
}

void WindowCalculator::stringToDigitRow(HeplString string, ImagePanel *array, size_t size, int positionY) {
    for (size_t i = 0; i < string.size() && i < size; i++) {
        switch (string[i]) {
            case '0':
                array[i] = ImagePanel("DIGIT_0", m_displayPositionsX[i], positionY, 40, 40, m_cwd + "/images/0.bmp");
                break;
            case '1':
                array[i] = ImagePanel("DIGIT_1", m_displayPositionsX[i], positionY, 40, 40, m_cwd + "/images/1.bmp");
                break;
            case '2':
                array[i] = ImagePanel("DIGIT_2", m_displayPositionsX[i], positionY, 40, 40, m_cwd + "/images/2.bmp");
                break;
            case '3':
                array[i] = ImagePanel("DIGIT_3", m_displayPositionsX[i], positionY, 40, 40, m_cwd + "/images/3.bmp");
                break;
            case '4':
                array[i] = ImagePanel("DIGIT_4", m_displayPositionsX[i], positionY, 40, 40, m_cwd + "/images/4.bmp");
                break;
            case '5':
                array[i] = ImagePanel("DIGIT_5", m_displayPositionsX[i], positionY, 40, 40, m_cwd + "/images/5.bmp");
                break;
            case '6':
                array[i] = ImagePanel("DIGIT_6", m_displayPositionsX[i], positionY, 40, 40, m_cwd + "/images/6.bmp");
                break;
            case '7':
                array[i] = ImagePanel("DIGIT_7", m_displayPositionsX[i], positionY, 40, 40, m_cwd + "/images/7.bmp");
                break;
            case '8':
                array[i] = ImagePanel("DIGIT_8", m_displayPositionsX[i], positionY, 40, 40, m_cwd + "/images/8.bmp");
                break;
            case '9':
                array[i] = ImagePanel("DIGIT_9", m_displayPositionsX[i], positionY, 40, 40, m_cwd + "/images/9.bmp");
                break;
            case '/':
                array[i] = ImagePanel("FRACTION_BAR", m_displayPositionsX[i], positionY, 40, 40, m_cwd + "/images/fraction_bar.bmp");
                break;
            case '-':
                array[i] = ImagePanel("MINUS", m_displayPositionsX[i], positionY, 40, 40, m_cwd + "/images/minus.bmp");
                break;
            case '.':
                array[i] = ImagePanel("COMMA", m_displayPositionsX[i], positionY, 40, 40, m_cwd + "/images/comma.bmp");
                break;
        }
    }
}

HeplString WindowCalculator::getCurrentWorkingDirectory() {
    int dirnameLength;
    int length = wai_getExecutablePath(NULL, 0, &dirnameLength);
    if (length <= 0) {
        throw HeplBaseException("Unable to get current working directory length");
    }

    char *path = (char*)malloc(length + 1);
    if (!path) {
        throw HeplBaseException("Unable to get current working directory");
    }

    wai_getExecutablePath(path, length, &dirnameLength);
    path[dirnameLength] = '\0';

    HeplString workingDirectory(path);
    free(path);

    return workingDirectory;
}

void WindowCalculator::draw() {

    if (m_forceRedraw) {
        // Redraw window background
        Window::draw();

        redrawPanels();

        // Redraw the buttons
        HeplBaseListIterator<ImageButton> buttonListIt(m_buttonList);
        for (buttonListIt.reset(); !buttonListIt.end(); buttonListIt++) {
            (&buttonListIt)->draw();
        }

        m_forceRedraw = false;
    }

    // Update display
    resetDisplay();
    redrawDisplay();
    for (int i = 0; i < CALC_DISPLAY_ROWS; i++) {
        try {
            stringToDigitRow(m_calculator->getStack(i, CALC_DISPLAY_COLUMNS), m_display[CALC_DISPLAY_ROWS - i - 1], CALC_DISPLAY_COLUMNS, m_displayPositionsY[i]);
        } catch (HeplBaseListItemNotFoundException e) {
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

void WindowCalculator::drawAll() {
    m_forceRedraw = true;
    draw();
    m_forceRedraw = false;
}

void WindowCalculator::click(int x, int y) {
    HeplBaseListIterator<ImageButton> buttonListIt(m_buttonList);
    for (buttonListIt.reset(); !buttonListIt.end(); buttonListIt++) {
        (&buttonListIt)->click(x, y);
    }
}

Calculator *WindowCalculator::getCalculator() {
    return m_calculator;
}

void WindowCalculator::setColorPanelTop(const Color& color) {
    (&m_panelList[0])->setColor(color);
}

void WindowCalculator::setColorPanelMiddle(const Color& color) {
    (&m_panelList[1])->setColor(color);
}

void WindowCalculator::setColorPanelBottom(const Color& color) {
    (&m_panelList[2])->setColor(color);
}

void WindowCalculator::setCalculator(Calculator *calculator) {
    m_calculator = calculator;
}

void WindowCalculator::setListener(Listener *listener) {
    HeplBaseListIterator<ImageButton> buttonListIt(m_buttonList);
    for (buttonListIt.reset(); !buttonListIt.end(); buttonListIt++) {
        (&buttonListIt)->setListener(listener);
    }
}
