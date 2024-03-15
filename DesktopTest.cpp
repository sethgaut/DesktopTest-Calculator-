#include <windows.h>
#include <string>
#include <sstream>

LRESULT CALLBACK Calculator(HWND calc, UINT uMsg, WPARAM wParam, LPARAM lParam);

HWND hDisplay;
HWND hTrace;

std::string displayText;
std::string displayTrace;
bool trace = false;

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    // Register window class
    const wchar_t CLASS_NAME[] = L"Calculator Class";

    WNDCLASS wc = {};

    wc.lpfnWndProc = Calculator;
    wc.hInstance = hInstance;
    wc.lpszClassName = CLASS_NAME;

    RegisterClass(&wc);

    // Create window
    HWND calc = CreateWindowEx(0, CLASS_NAME, L"Calculator", WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, 660, 360, NULL, NULL, hInstance, NULL);


    if (calc == NULL)
    {
        return 0;
    }

    // Display window
    ShowWindow(calc, nCmdShow);

    // Run message loop
    MSG msg = {};
    while (GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return 0;
}

LRESULT CALLBACK Calculator(HWND calc, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg)
    {
    case WM_CREATE:
    {
        // Create display area
        hDisplay = CreateWindowEx(0, L"STATIC", L"", WS_CHILD | WS_VISIBLE | SS_RIGHT,10, 10, 310, 30, calc, NULL, NULL, NULL);
        hTrace = CreateWindowEx(0, L"STATIC", L"", WS_CHILD | WS_VISIBLE | SS_RIGHT, 340, 10, 290, 290, calc, NULL, NULL, NULL);

        // Create buttons
        CreateWindow(L"BUTTON", L"7", WS_CHILD | WS_VISIBLE, 10, 100, 50, 50, calc, (HMENU)7, NULL, NULL);
        CreateWindow(L"BUTTON", L"8", WS_CHILD | WS_VISIBLE, 70, 100, 50, 50, calc, (HMENU)8, NULL, NULL);
        CreateWindow(L"BUTTON", L"9", WS_CHILD | WS_VISIBLE, 130, 100, 50, 50, calc, (HMENU)9, NULL, NULL);

        CreateWindow(L"BUTTON", L"4", WS_CHILD | WS_VISIBLE, 10,150, 50, 50, calc, (HMENU)4, NULL, NULL);
        CreateWindow(L"BUTTON", L"5", WS_CHILD | WS_VISIBLE, 70, 150, 50, 50, calc, (HMENU)5, NULL, NULL);
        CreateWindow(L"BUTTON", L"6", WS_CHILD | WS_VISIBLE, 130, 150, 50, 50, calc, (HMENU)6, NULL, NULL);

        CreateWindow(L"BUTTON", L"1", WS_CHILD | WS_VISIBLE, 10, 200, 50, 50, calc, (HMENU)1, NULL, NULL);
        CreateWindow(L"BUTTON", L"2", WS_CHILD | WS_VISIBLE, 70, 200, 50, 50, calc, (HMENU)2, NULL, NULL);
        CreateWindow(L"BUTTON", L"3", WS_CHILD | WS_VISIBLE, 130, 200, 50, 50, calc, (HMENU)3, NULL, NULL);

        CreateWindow(L"BUTTON", L"0", WS_CHILD | WS_VISIBLE, 10, 250, 110, 50, calc, (HMENU)0, NULL, NULL);
        CreateWindow(L"BUTTON", L".", WS_CHILD | WS_VISIBLE, 130, 250, 50, 50, calc, (HMENU)10, NULL, NULL);

        CreateWindow(L"BUTTON", L"C", WS_CHILD | WS_VISIBLE, 210, 100, 50, 50, calc, (HMENU)11, NULL, NULL);
        CreateWindow(L"BUTTON", L"CE", WS_CHILD | WS_VISIBLE, 270, 100, 50, 50, calc, (HMENU)12, NULL, NULL);

        CreateWindow(L"BUTTON", L"+", WS_CHILD | WS_VISIBLE, 210, 150, 50, 50, calc, (HMENU)13, NULL, NULL);
        CreateWindow(L"BUTTON", L"-", WS_CHILD | WS_VISIBLE, 270, 150, 50, 50, calc, (HMENU)14, NULL, NULL);

        CreateWindow(L"BUTTON", L"*", WS_CHILD | WS_VISIBLE, 210, 200, 50, 50, calc, (HMENU)15, NULL, NULL);
        CreateWindow(L"BUTTON", L"/", WS_CHILD | WS_VISIBLE, 270, 200, 50, 50, calc, (HMENU)16, NULL, NULL);

        CreateWindow(L"BUTTON", L"=", WS_CHILD | WS_VISIBLE, 210, 250, 50, 50, calc, (HMENU)17, NULL, NULL);
        CreateWindow(L"BUTTON", L"%", WS_CHILD | WS_VISIBLE, 270, 250, 50, 50, calc, (HMENU)18, NULL, NULL);

        CreateWindow(L"BUTTON", L"Intro Trace On", WS_CHILD | WS_VISIBLE, 70, 50, 110, 50, calc, (HMENU)19, NULL, NULL);
        CreateWindow(L"BUTTON", L"Intro Trace Off", WS_CHILD | WS_VISIBLE, 210, 50, 110, 50, calc, (HMENU)20, NULL, NULL);
        CreateWindow(L"BUTTON", L"CT", WS_CHILD | WS_VISIBLE, 10, 50, 50, 50, calc, (HMENU)21, NULL, NULL);

        break;
    }
    case WM_COMMAND:
    {
        int buttonId = LOWORD(wParam);
        if (buttonId >= 0 && buttonId <= 9)
        {
            // numbers
            displayText += std::to_string(buttonId);
            if (trace == true)
            {
                displayTrace += " " + std::to_string(buttonId) + "\n";
            }
            else
            {
                displayTrace += "";
            }
            
        }
        else if (buttonId == 10)
        {
            // decimal point
            displayText += ".";
            if (trace == true)
            {
                displayTrace += " . \n";
            }
            else
            {
                displayTrace += "";
            }
            
        }
        else if (buttonId == 11)
        {
            // clear entire calculator state
            displayText = "";
            if (trace == true)
            {
                displayTrace += " clear \n";
            }
            else
            {
                displayTrace += "";
            }
        }
        else if (buttonId == 12)
        {
            // clear current entry
            displayText.pop_back();
            if (trace == true)
            {
                displayTrace += " clear entry \n";
            }
            else
            {
                displayTrace += "";
            }
        }
        else if (buttonId == 13)
        {
            // addition button
            displayText += " + ";
            if (trace == true)
            {
                displayTrace += " + \n";
            }
            else
            {
                displayTrace += "";
            }
        }
        else if (buttonId == 14)
        {
            // subtraction & negative button
            if (displayText.empty() || displayText.back() == '+' || displayText.back() == '-' || displayText.back() == '*' || displayText.back() == '/')
            {
                displayText += "-";
                if (trace == true)
                {
                    displayTrace += " - \n";
                }
                else
                {
                    displayTrace += "";
                }
            }
            else
            {
                displayText += " - ";
                if (trace == true)
                {
                    displayTrace += " - \n";
                }
                else
                {
                    displayTrace += "";
                }
            }
        }
        else if (buttonId == 15)
        {
            // multiplication button
            displayText += " * ";
            if (trace == true)
            {
                displayTrace += " * \n";
            }
            else
            {
                displayTrace += "";
            }
        }
        else if (buttonId == 16)
        {
            // division button
            displayText += " / ";
            if (trace == true)
            {
                displayTrace += " / \n";
            }
            else
            {
                displayTrace += "";
            }
        }
        else if (buttonId == 18)
        {
            // tax addition button
            displayText += " % ";
            if (trace == true)
            {
                displayTrace += " % \n";
            }
            else
            {
                displayTrace += "";
            }
        }
        else if (buttonId == 19)
        {
            trace = true;
        }
        else if (buttonId == 20)
        {
            trace = false;
        }
        else if (buttonId == 21)
        {
            displayTrace = "";
        }
        else if (buttonId == 17)
        {
            // result
            std::istringstream iss(displayText);
            float result = 0.0;
            float operand = 0.0;
            int count = 0;
            std::string token;
            char op = '+';
            bool isPercentage = false;
            while (iss >> token)
            {
                if (isdigit(token[0]) || (token[0] == '.' && isdigit(token[1])))
                {
                    operand = std::stod(token);
                    if (isPercentage == true)
                    {
                        operand = result * (operand / 100.0);
                        if (trace == true)
                        {
                            displayTrace += "If (isPercentage == true)\n";
                            count += 1;
                        }
                        else 
                        {
                        }
                        
                    }
                    switch (op)
                    {
                    case '+':
                        result += operand;
                        if (trace == true)
                        {
                            displayTrace += "operand '+': switch (op): case '+'\n";
                            count += 1;
                        }
                        else
                        {
                        }
                        
                        break;
                    case '-': 
                        result -= operand;
                        if (trace == true)
                        {
                            displayTrace += "operand '+': switch (op): case '-'\n";
                            count += 1;
                        }
                        else
                        {
                        }
                        break;
                    case '*':
                        result *= operand;
                        if (trace == true)
                        {
                            displayTrace += "operand '+': switch (op): case '*'\n";
                            count += 1;
                        }
                        else
                        {
                        }
                        break;
                    case '/':
                        result /= operand;
                        if (trace == true)
                        {
                            displayTrace += "operand '+': switch (op): case '/'\n";
                            count += 1;
                        }
                        else
                        {
                        }
                        break;
                    }
                    count += 1;
                }
                else if (token[0] == '-' && isdigit(token[1]))
                {
                    operand = std::stod(token);
                    switch (op)
                    {
                    case '+':
                        result += operand;
                        if (trace == true)
                        {
                            displayTrace += "operand '-'\n";
                            count += 1;
                        }
                        else
                        {
                        }
                        break;
                    case '-':
                        result -= operand;
                        if (trace == true)
                        {
                            displayTrace += "operand '-'\n";
                            count += 1;
                        }
                        else
                        {
                        }
                        break;
                    case '*':
                        result *= operand;
                        if (trace == true)
                        {
                            displayTrace += "operand '-'\n";
                            count += 1;
                        }
                        else
                        {
                        }
                        break;
                    case '/':
                        result /= operand;
                        if (trace == true)
                        {
                            displayTrace += "operand '-'\n";
                            count += 1;
                        }
                        else
                        {
                        }
                        break;
                    }
                }
                else if (token == "%")
                {
                    // Token is percent operator
                    isPercentage = true;
                    if (trace == true)
                    {
                        displayTrace += "isPercentage = true;\n";
                        count += 1;
                    }
                    else
                    {
                    }
                }
                else
                {
                    // Token is operator
                    op = token[0];
                    if (trace == true)
                    {
                        displayTrace += "operator: op = token[0]\n";
                        count += 1;
                    }
                    else
                    {
                    }
                }
            }
            // Convert result to string and update display
            displayText = std::to_string(result) + "\n";
            if (trace == true)
            {
                displayTrace += "result: " + std::to_string(result) + "\n";
                displayTrace += "count: " + std::to_string(count) + "\n";
            }
            else
            {
                displayTrace += "";
            }
            
        }
        SetWindowTextA(hDisplay, displayText.c_str());
        SetWindowTextA(hTrace, displayTrace.c_str());
        break;
    }
    case WM_DESTROY:
    {
        PostQuitMessage(0);
        return 0;
    }
    default:
        return DefWindowProc(calc, uMsg, wParam, lParam);
    }
    return 0;
}
