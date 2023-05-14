#pragma once

#include "resource.h"
#include "string"
#include "vector"

using namespace std;


class Calc {
	double number1, number2, result;
public:
	void Buttons(LPARAM Button, HWND hWnd);
	double GetResult(LPSTR str)
	{
		string input = str;
		vector<string> signs;
		vector<double> numbers;

		for (int i = 0; i < input.length(); i++)
		{
			if (isdigit(input[i]))
			{
				string s(1, input[i]);
				//return std::stoi(s);
				numbers.push_back(std::stoi(s));
			}
			else
			{
				string s(1, input[i]);
				if (signs.size() > 0) {
					if ((s == "-" || s == "+") && (signs[signs.size() - 1] == "*" || signs[signs.size() - 1] == "/"))
					{
						int len = signs.size();
						for (int i = 0; i < len; i++)
						{
							double result = Calculate(signs[signs.size() - 1], numbers[numbers.size() - 1], numbers[numbers.size() - 2]);

							signs.pop_back();
							numbers.pop_back();
							numbers.pop_back();

							numbers.push_back(result);
						}
					}
				}

				signs.push_back(s);
			}
		}

		int len = signs.size();
		for (int i = 0; i < len; i++)
		{
			double result = Calculate(signs[signs.size() - 1], numbers[numbers.size() - 1], numbers[numbers.size() - 2]);

			signs.pop_back();
			numbers.pop_back();
			numbers.pop_back();

			numbers.push_back(result);
		}

		return numbers[numbers.size() - 1];
		//return numbers.size();	
	}

	double Calculate(string operand, double num1, double num2) 
	{
		if (operand == "+") 
		{
			return num1 + num2;
		}

		if (operand == "-")
		{
			return num2 - num1;
		}

		if (operand == "*")
		{
			return num1 * num2;
		}

		if (operand == "/")
		{
			return num2 / num1;
		}
		return num1;
	}
};