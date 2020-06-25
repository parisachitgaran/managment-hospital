#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include<iostream>
#include<string>
#include"person.h"

class employee :public Person
{
private:
	std::string post,Pass;
public:
	employee(std::string Name, std::string Family, std::string Phone, std::string Code, std::string post , std::string Pass ) :Person(Name, Family, Phone, Code) {
		set_post(post);
		set_Pass(Pass);
	}
	employee(std::string Name, std::string Family, std::string Phone, std::string Code, std::string post):Person(Name,Family,Phone,Code){
		set_post(post);
	}

	void set_post(std::string post);
	std::string get_post() { return post; }
	void set_Pass(std::string Pass);
	std::string get_Pass()const { return Pass; }

};

void employee::set_post(std::string post) {
	this->post = post;
}
void employee::set_Pass(std::string Pass) {
	this->Pass = Pass;
}

#endif // !EMPLOYEE_H



#pragma once
