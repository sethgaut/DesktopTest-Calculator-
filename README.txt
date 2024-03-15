My calculator was built in C++ using the Win32 API library in the Microsoft Visual Studio environment.

Overview:

My calculator is built to the specifications provided for the five function calculator. The trace logic window is not a popup window that is spawned when the trace logic button is on but rather a window that is prebuilt next to the buttons of the calculator for an easier to digest and analyze fashion. 

For the buttons of the calculator, I have implemented the digits 0-9, operators (+,-,*,/.%), C (clear) and CE (clear entry), trace logic on/off, and CT (clear trace). The CT button is a button that I created to clear the trace logic window as I found this window in particular can get fairly messy and I want to represent this data in a clean and easily digestable manner for my audience.

Implementation Details:

In this section of the documentation I will have bullet points for brief implementation details.

Libraries used:

	#include <windows.h>
	#include <string>
	#include <sstream>

Win32 API window usage:

	int WINAPI WinMain()
	For calculator creation:
		LRESULT CALLBACK Calculator()
		const wchar_t CLASS_NAME[] = L"Calculator Class";

		WNDCLASS wc = {};

		wc.lpfnWndProc = Calculator;
		wc.hInstance = hInstance;
		wc.lpszClassName = CLASS_NAME;
		RegisterClass(&wc);

		HWND calc = CreateWindowEx()

	Calculator button creation:
		CreateWindow(L"BUTTON", L"7", WS_CHILD | WS_VISIBLE, 10, 100, 50, 50, calc, (HMENU)7, NULL, NULL);
		(each button has this line for creation)
		
	Calculator operator handler:
		initialize operator (op) variable
		inputs are stored in the displayText string
		iterate through the displaytext string until the operator is found and then performs that operation on the operators (will go into further detail in demo)
		operators are handled through a switch case

	Trace logic:
		created another display window for the trace logic
		stores inputs in displayTrace string
		displays inputs, operand signs, operator case, when a operator is found, the result of equation, and the count for the decisions made
		boolean value determines whenever the trace table is displaying or not

Conclusion:

Like I mentioned previously, this is a very brief overview of the calculator and some implementation details that I wanted to provide for a glimpse into my decision making for this project. I enjoyed the challenge of using an environment that I was very unfamiliar with and knocking some rust off of my C++ coding skills. I hope that my project will give a better glimpse of my "super powers" as a software developer and I look forward to sharing what I have done to the team!





