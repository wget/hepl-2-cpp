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

    m_forceRedraw = true;
    HeplList<HeplBaseException> errors;
    errors = isFileMalformed(m_cwd + "/buttons.conf");

    if (errors.getNumberItems()) {

        for (size_t i = 0; i < errors.getNumberItems(); i++) {
            std::cout << ((HeplBaseException)errors[i]).what() << std::endl;
        }

        std::cout << "The button mapping file is malformed. Overwriting it with the default configuration..." << std::endl;
        populateDefaultButtonMappingFile();

        // If we are running into issues despite the default config, there is
        // something plain wrong. Better to stop...
        errors = isFileMalformed(m_cwd + "/buttons.conf");
        if (errors.getNumberItems()) {
            throw errors[0];
        }
    }

    loadButtonMappingFileConfig();
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

HeplString WindowCalculator::getCurrentWorkingDirectory() const {
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

void WindowCalculator::populateDefaultButtonMappingFile() const {

    HeplString filename = HeplString(m_cwd) + HeplString("/buttons.conf");
    std::ofstream file(filename.c_str());

    if (!file.good()) {
        throw HeplBaseException("Unable to open buttons.conf for writing");
    }

    file << "BUTTON_0" << FILE_DELIMITER << "20" << FILE_DELIMITER << "310" << FILE_DELIMITER << "./images/button_0.bmp";
    file << "BUTTON_1" << FILE_DELIMITER << "70" << FILE_DELIMITER << "310" << FILE_DELIMITER << "./images/button_1.bmp";
    file << "BUTTON_2" << FILE_DELIMITER << "120" << FILE_DELIMITER << "310" << FILE_DELIMITER << "./images/button_2.bmp";
    file << "BUTTON_3" << FILE_DELIMITER << "170" << FILE_DELIMITER << "310" << FILE_DELIMITER << "./images/button_3.bmp";
    file << "BUTTON_4" << FILE_DELIMITER << "220" << FILE_DELIMITER << "310" << FILE_DELIMITER << "./images/button_4.bmp";
    file << "BUTTON_5" << FILE_DELIMITER << "20" << FILE_DELIMITER << "360" << FILE_DELIMITER << "./images/button_5.bmp";
    file << "BUTTON_6" << FILE_DELIMITER << "70" << FILE_DELIMITER << "360" << FILE_DELIMITER << "./images/button_6.bmp";
    file << "BUTTON_7" << FILE_DELIMITER << "120" << FILE_DELIMITER << "360" << FILE_DELIMITER << "./images/button_7.bmp";
    file << "BUTTON_8" << FILE_DELIMITER << "170" << FILE_DELIMITER << "360" << FILE_DELIMITER << "./images/button_8.bmp";
    file << "BUTTON_9" << FILE_DELIMITER << "220" << FILE_DELIMITER << "360" << FILE_DELIMITER << "./images/button_9.bmp";
    file << "BUTTON_ERASE" << FILE_DELIMITER << "20" << FILE_DELIMITER << "410" << FILE_DELIMITER << "./images/button_erase.bmp";
    file << "BUTTON_ENTER" << FILE_DELIMITER << "145" << FILE_DELIMITER << "410" << FILE_DELIMITER << "./images/button_enter.bmp";
    file << "BUTTON_PLUS" << FILE_DELIMITER << "330" << FILE_DELIMITER << "310" << FILE_DELIMITER << "./images/button_plus.bmp";
    file << "BUTTON_MINUS" << FILE_DELIMITER << "380" << FILE_DELIMITER << "310" << FILE_DELIMITER << "./images/button_minus.bmp";
    file << "BUTTON_MULTIPLY" << FILE_DELIMITER << "330" << FILE_DELIMITER << "360" << FILE_DELIMITER << "./images/button_multiply.bmp";
    file << "BUTTON_DIVIDE" << FILE_DELIMITER << "380" << FILE_DELIMITER << "360" << FILE_DELIMITER << "./images/button_divide.bmp";
    file << "BUTTON_PLUS_OR_MINUS" << FILE_DELIMITER << "380" << FILE_DELIMITER << "410" << FILE_DELIMITER << "./images/button_plus_or_minus.bmp";
    file << "BUTTON_DIGITAL" << FILE_DELIMITER << "330" << FILE_DELIMITER << "410" << FILE_DELIMITER << "./images/button_digit.bmp";
    file << "BUTTON_CONFIG" << FILE_DELIMITER << "275" << FILE_DELIMITER << "410" << FILE_DELIMITER << "./images/button_config.bmp";
}

HeplList<HeplBaseException> WindowCalculator::isFileMalformed(HeplString filename) const {

    HeplList<HeplBaseException> errorList;

    std::ifstream file(filename.c_str());
    if (!file.good()) {
        errorList.add(HeplBaseException("Unable to open the file " + filename + ": " + strerror(errno)));
        return errorList;
    }

    HeplList<HeplString> validButtonNames;
    validButtonNames.add("BUTTON_0");
    validButtonNames.add("BUTTON_1");
    validButtonNames.add("BUTTON_2");
    validButtonNames.add("BUTTON_3");
    validButtonNames.add("BUTTON_4");
    validButtonNames.add("BUTTON_5");
    validButtonNames.add("BUTTON_6");
    validButtonNames.add("BUTTON_7");
    validButtonNames.add("BUTTON_8");
    validButtonNames.add("BUTTON_9");
    validButtonNames.add("BUTTON_ERASE");
    validButtonNames.add("BUTTON_ENTER");
    validButtonNames.add("BUTTON_PLUS");
    validButtonNames.add("BUTTON_MINUS");
    validButtonNames.add("BUTTON_MULTIPLY");
    validButtonNames.add("BUTTON_DIVIDE");
    validButtonNames.add("BUTTON_PLUS_OR_MINUS");
    validButtonNames.add("BUTTON_DIGITAL");
    validButtonNames.add("BUTTON_CONFIG");

    HeplList<HeplString> specifiedButtonNames;

    HeplString line;
    for (size_t i = 1; file >> line; i++) {

        if (line.empty()) {
            errorList.add(HeplBaseException("Line " + HeplString(i) + " is empty"));
            continue;
        }

        HeplList<HeplString> lineExploded;
        lineExploded = line.explode(FILE_DELIMITER);

        size_t lineNumberFields = lineExploded.getNumberItems();
        if (lineNumberFields != BUTTON_FILE_MAPPING_MAX_FIELDS) {
            errorList.add(HeplBaseException("Line " + HeplString(i) + " has " + HeplString(lineNumberFields) + " instead of " + BUTTON_FILE_MAPPING_MAX_FIELDS));
            continue;
        }

        HeplString buttonName = lineExploded[0];
        if (!validButtonNames.find(buttonName)) {
            errorList.add(HeplBaseException("Line " + HeplString(i) + " has an invalid button name"));
        } else {
            specifiedButtonNames.add(buttonName);
        }

        HeplString buttonWidth = lineExploded[1];
        if (!buttonWidth.isNumber()) {
            errorList.add(HeplBaseException("Line " + HeplString(i) + " has button width which is not a number"));
        }

        HeplString buttonHeight = lineExploded[2];
        if (!buttonHeight.isNumber()) {
            errorList.add(HeplBaseException("Line " + HeplString(i) + " has button height which is not a number"));
        }

        HeplString buttonImageFilename(HeplString(m_cwd) + HeplString("/") + lineExploded[3]);
        std::ifstream buttonImage(buttonImageFilename.c_str());
        if (!buttonImage) {
            errorList.add(HeplBaseException("Line " + HeplString(i) + " has a button image file (" + buttonImageFilename + ") which cannot be read"));
        } else {
            buttonImage.close();
        }
    }

    for (size_t i = 0; i < validButtonNames.getNumberItems(); i++) {
        if (!specifiedButtonNames.find(validButtonNames[i])) {
            errorList.add(HeplBaseException("Configuration for button " + validButtonNames[i] + " is missing from the button file mapping"));
        }
    }

    return errorList;
}

void WindowCalculator::loadButtonMappingFileConfig() {

    HeplString filename = HeplString(m_cwd) + HeplString("/buttons.conf");
    std::ifstream file(filename.c_str());

    HeplString line;
    for (size_t i = 1; file >> line; i++) {

        HeplList<HeplString> lineExploded;
        lineExploded = line.explode(FILE_DELIMITER);
        HeplString buttonName = lineExploded[0];
        unsigned int buttonWidth = lineExploded[1].atoi();
        unsigned int buttonHeight = lineExploded[2].atoi();
        HeplString buttonImageFilename(HeplString(m_cwd) + HeplString("/") + lineExploded[3]);
        m_buttonList.add(ImageButton(buttonName, buttonWidth, buttonHeight, 40, 40, buttonImageFilename));
    }
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
