#ifndef DOCTOR_H
#define DOCTOR_H

#pragma once
#include<iostream>
#include"person.h"
#include<iomanip>

class doctor :public Person
{
private:
	std::string Expertise;

public:
	static int count;
	doctor() {}
	doctor(std::string Name, std::string Family, std::string Phone, std::string Code, std::string Expertise) :Person(Name, Family, Phone, Code) {
		set_Expertise(Expertise);
		count++;
	}

	void set_Expertise(std::string Expertise);
	std::string get_Expertise()const { return Expertise; }

	void pritCount()const {
		std::cout << count;
	}
	void show()const;
};
int doctor::count = 0;
void doctor::set_Expertise(std::string Expertise) {
	this->Expertise = Expertise;
}
void doctor::show() const
{

	std::cout << Name << std::setw(10) << " " << Family << std::setw(8) << Phone << std::setw(9) << Code  << std::setw(9) << Expertise << std::endl;

}



#endif // !DOCTOR_H