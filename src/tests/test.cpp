#include <cmath>
#include <iostream>
#include "../lib/utils/src/HeplString.hpp"
#include "../lib/utils/src/HeplStack.hpp"
#include "../lib/utils/src/HeplBaseException.hpp"

using namespace std;

int main(int arc, char *argv[]) {

    HeplString helloString = "Hello";
    HeplString worldString(helloString);
    HeplString numbers = "455";
    // throw HeplBaseException("Hello world");
    // cout << helloString << endl;
    // cout << helloString + worldString << endl;
    // cout << helloString + " " + worldString << endl;
    // cout << helloString + " " + 42 << endl;
    // cout << helloString[1] << endl;
    // cout << helloString.atoi() << endl;

    // cout << numbers.isNumber() << endl;
    // cout << "arch" << endl <<
    //     "linux" << endl;
    //
    // HeplStack<HeplString> stack;
    // stack.push(helloString);
    // stack.push(worldString);
    // stack.push(numbers);
    // cout << "DEBUG : \"" << stack.pop() << "\"" << endl;
    // cout << "DEBUG : \"" << stack.top() << "\"" << endl;
    // cout << "DEBUG : \"" << stack.pop() << "\"" << endl;
    // cout << "DEBUG : \"" << stack.top() << "\"" << endl;
    // cout << "DEBUG : \"" << stack.pop() << "\"" << endl;
    // // cout << "DEBUG : \"" << stack.top() << "\"" << endl;
    // // cout << "DEBUG : \"" << stack.top() << "\"" << endl;
    // // cout << "DEBUG : \"" << stack.pop() << "\"" << endl;
    // // cout << "DEBUG : \"" << stack.pop() << "\"" << endl;
    // // cout << "DEBUG : \"" << stack.pop() << "\"" << endl;
    // int result = abs(static_cast<int>(36.89532131*10))%10;
    // cout << result << endl;
    // cout << helloString.ftoa(36.89532131) << endl;
    // cout << "\"" << helloString << "\"" << endl;
    // helloString += "will";
    // cout << "\"" << helloString << "\"" << endl;
}
