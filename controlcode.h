#ifndef CONTROLCODE_H
#define CONTROLCODE_H

#include<iostream>
#include<string>

class controlcode {
private:
	std::string Code;
public:
	controlcode(){}
	std::string get_Code();

};

std::string controlcode::get_Code()
{

	std::string msg1= "National Code is not 10 digits . Try agian";
	std::string msg2 = "National Cod does not start with 0 . Try agian";
	std::string msg3 = "pleas enter just number . Try agian";

START:
	Code.clear();
	std::cin >> Code;

	try {

	
		for (int k = 0;k < Code.length();k++)
			for (int i = 58, j = 33;i <= 126, j <= 47;i++, j++)
			{
				if (Code[k]== i||Code[k]==j)
					throw msg3;
			}
		if (Code.length() != 10)
			throw msg1;

		if (Code[0] != '0')
			throw msg2;
	}
	catch (std::string msg)
	{
		std::cout << msg << std::endl;
		goto START;
	}


	return Code;
}
#endif // !CONTROLCODE_H
