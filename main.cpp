
#include <stack>
#include <string>
#include <sstream>
#include <vector>
#include <iostream>

class Prefix
{
public:
std::string evaluate(std::string input)
{


	// std::string operators;
	// int expressionArray[input.length()];
	// int ArrayIncrement = 0;
	int digit =0;

	for (int i = input.length() -1; i >= 0; i--)
	{
		int hundreds= 0;
		if (isdigit(input[i]) )
		{
			while(isdigit(input[i]))
			{
				hundreds++;
				i--;
			
			}
			if(hundreds > 2 || input[i] == '-' )
			{
				return "Error";
			}
			digit++;
		}

		else if(input[i] == '+' ||input[i] == '-' ||input[i] == '*' ||input[i] == '/' )
		{
			digit--;
		}
		else if (input[i] != ' ' )
		{
			return "Error";
		}
	}
	if (digit != 1)
	{
		return "Error";
	}



	std::stack<int> sta;
	std::string expression;
	std::string FIRST;
	std::string SECOND;
	std::string operators;
	int check = 0;
	for(int i = input.length() -1; i >= 0; i--)
		{
			std::string curent = "";
			
			if (isdigit(input[i] ))
			{
				while (isdigit(input[i]))
				{

					curent = input[i]+ curent;
					i--;

				}
				
				int num = stoi(curent);
				// expressionArray[ArrayIncrement] = i;
				sta.push(num);
				// ArrayIncrement++;
			}






			if (input[i] == '+' ||input[i] == '-' ||input[i] == '*' ||input[i] == '/' )
			{
				std::string operators = "";
				// operators =input[i]+ operators;
				int first =sta.top();
				sta.pop();
				int second =sta.top();
				sta.pop();

						FIRST = std::to_string(first);
						SECOND = std::to_string(second);

				if (input[i]=='+')
				{
					operators = " + ";
					first = first + second;
					sta.push(first);
				}
				else if (input[i]=='-')
				{
					operators = " - ";
					first = first - second;
					sta.push(first);
				}
				if (input[i] == '*')
				{
					operators = " * ";
					first = first*second;
					sta.push(first);
				}
				if (input[i] == '/')
				{
					if(second == 0)
					{
						return "Error";
					}
					operators = " / ";
					first = first/second;
					sta.push(first);
				}


					if (check == 0)
					{
						check = 1;
						expression = FIRST + operators + SECOND;
					}
					else
					{
						expression = "(" +expression+ ")" + operators + SECOND;
					}
					
			}

		


	

		}

		
		
		std::string end =std::to_string(sta.top());
		expression = expression + " =" + end;
	return expression;
}
};




int main ()
{
	Prefix Hi;

	std::string str;

	getline(std::cin, str);
	std::cout << Hi.evaluate(str) << std::endl;
	return 0;
}