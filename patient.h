#ifndef PATIENT_H
#define PATIENT_H
#pragma once
#include<iostream>
#include<iomanip>
#include"person.h"

class patient :public Person
{
private:
	std::string DoctorName, Sickness;

public:
	static int count;
	patient() {}
	patient(std::string Name, std::string Family, std::string Phone, std::string Code, std::string DoctorName, std::string Sickness) :Person(Name, Family, Phone, Code) {
		set_Sickness(Sickness);
		set_DoctorName(DoctorName);
		count++;
	}

	void set_DoctorName(std::string DoctorName);
	void set_Sickness(std::string Sickness);

	std::string get_DoctorName()const { return DoctorName; }
	std::string get_Sickness()const { return Sickness; }

	void pritCount() {
		std::cout << count;
	}
	void show()const;
};
int patient::count = 0;
void patient::set_DoctorName(std::string DoctorName) {
	this->DoctorName = DoctorName;
}
void patient::set_Sickness(std::string Sickness) {
	this->Sickness = Sickness;
}

void patient::show() const {

	std::cout << " " << Name << std::setw(10) << Family << std::setw(19) << Phone << std::setw(19) << Code << std::setw(19) << DoctorName << std::setw(19) << Sickness << std::endl;

}

#endif // !PATIENT_H

