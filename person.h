#ifndef PERSON_H
#define PERSON_H
#pragma once
#include<iostream>
#include<string>
#include"controlPhone.h"
#include"controlcode.h"

class Person
{
protected:
	std::string Name, Family, Phone, Code;
public:
	Person() {}
	Person(std::string Name, std::string Family, std::string Phone, std::string Code);
	
	void set_Name(std::string Name);
	void set_Family(std::string Family);
	void set_Phone(std::string Phone);
	void set_Code(std::string Code);
	

	std::string get_Name()const { return Name; }
	std::string get_Family()const { return Family; }
	std::string get_Phone()const { return Phone; }
	std::string get_Code()const { return Code; }
	


};

Person::Person(std::string Name, std::string Family, std::string Phone, std::string Code) {
	set_Name(Name);
	set_Family(Family);
	set_Phone(Phone);
	set_Code(Code);
	//set_Pass(Pass);
}

void Person::set_Name(std::string Name) {
	this->Name = Name;
}
void Person::set_Family(std::string Family) {
	this->Family = Family;
}
void Person::set_Phone(std::string Phone) {
	//controlPhone ph(Phone);
	this->Phone =Phone;
}
void Person::set_Code(std::string Code) {
	//controlcode c(Code);
	this->Code = Code;
}

#endif // !PERSON_H
