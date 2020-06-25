#ifndef CONTROLPHONE_H
#define CONTROLPHONE_H
#include<iostream>
#include<string>


class controlPhone {

private:
	std::string mobile;

public:
	controlPhone(){}
	std::string get_mobile();
};

std::string controlPhone::get_mobile() {
	
	std::string msg1 = "Mobile number is 11 digits . Try agian";
	std::string msg2 = "Mobile does not start with 0 . Try agian";
	std::string msg3 = "pleas enter just number . Try agian";


START:
	mobile.clear();
	std::cin >> mobile;
	try {
		
		for (int k = 0;k < mobile.length();k++)
			for (int i = 58, j = 33;i <= 126, j <= 47;i++, j++)
		{
			if (mobile[k] == i || mobile[k] == j)
				throw msg3;
		}
		if (mobile.length() != 11)
			throw msg1;

		if (mobile[0] != '0')
			throw msg2;
	}
	catch (std::string msg)
	{
		std::cout << msg << std::endl;
		goto START;
	}
	
	
	return mobile;
}







#endif // !PHONE_H
