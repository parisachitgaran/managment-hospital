#ifndef  CONTROLNAME_FAMILY_H
#define CONTROLNAME_FAMILY_H

#include<iostream>
#include<string>

class controlname_family {

private:
	std::string name;
public:
	controlname_family(){}
    std::string get_namefamily();
};

std::string controlname_family::get_namefamily() {

	std::string msg1 = "you can't use number. Try agian";

		START:
		name.clear();
		std::cin >> name;
		
		try {
			for (int i = 0;i < name.length();i++)
			{
				for (int j = 33;j <= 64;j++)
					if (name[i] == j || name[i] == 95)
						throw msg1;
			}
		}
			catch (std::string msg){
				std::cout << msg << std::endl;
				goto START;
			}
			return name;
}


#endif // ! CONTROLNAME_FAMILY_H


#pragma once
