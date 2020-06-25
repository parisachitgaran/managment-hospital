// hoospital.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<fstream>
#include<map>
#include<iomanip>
#include<string>
#include<vector>
#include"person.h"
#include"patient.h"
#include"doctor.h"
#include"employee.h"
//#include"reception.h"
#include"controlname_family.h"
using namespace std;



//************************************ patient  ****************************************
//**************************************************************************************

vector<patient>list_Patient, list_Patient2;
fstream Patient;
int j = 0;

void write_pateint() {
	string name, family, phone, code, doctorName, sickness, password;

	cout << "\n\t    Name: ";
	controlname_family n;
	name = n.get_namefamily();

	cout << "\n\t    Family: ";
	controlname_family f;
	family = f.get_namefamily();

	cout << "\n\t    National Code: ";
	controlcode c;
	code = c.get_Code();

	cout << "\n\t    phone Number: ";
	controlPhone ph;
	phone =ph.get_mobile();

	cout << "\n\t    Sickness: ";
	cin >> sickness;

	cout << "\n\t    Doctor Name: ";
	controlname_family d;
	doctorName = d.get_namefamily();


	list_Patient.push_back(patient(name, family, phone, code, doctorName, sickness));

	Patient.open("Patient.csv", ios::app);
	Patient << list_Patient[j].get_Name() + "," + list_Patient[j].get_Family() + "," + list_Patient[j].get_Phone() + "," + list_Patient[j].get_Code() + "," + list_Patient[j].get_Sickness() + "," + list_Patient[j].get_DoctorName() << endl;
	j++;
}

void edit_patient(string code)
{
	char c;
	int a;
	string name, family, phone, sickness, Doctorname;

	//int size = list_doctor2.size();
	for (int i = 0; i <list_Patient.size(); i++)
	{
		if (code == list_Patient[i].get_Code())
		{
			system("cls");
			do {
				cout << "\n\tEDIT PATIENT ";
				cout << "\n\t1.  Name";
				cout << "\n\t2.  Family";
				cout << "\n\t3.  Phone Number";
				cout << "\n\t4.  National Code";
				cout << "\n\t5.  Sickness";
				cout << "\n\t6.  Doctor Name";
				cout << "\n\t7.  Back to Patinet Menu";


				cout << "\n\tENTER PATEINT NATIONAL CODE: ";
				cin >> a;

				switch (a)
				{
				case 1:
					cout << "\n\t    Name: ";
					cin >> name;
					list_Patient[i].set_Name(name);
					break;
				case 2:
					cout << "\n\t   Family: " << endl;
					cin >> family;
					list_Patient[i].set_Family(family);
					break;
				case 3:
					cout << "\n\t   Phone Number: ";
					cin >> phone;
					list_Patient[i].set_Phone(phone);
					break;
				case 4:
					cout << "\n\t   National Code: ";
					cin >> code;
					list_Patient[i].set_Code(code);
					break;
				case 5:
					cout << "\n\t    Sickness: ";
					cin >> sickness;
					list_Patient[i].set_Sickness(sickness);
					break;
				case 6:
					cout << "\n\t    Doctor Name: ";
					cin >> Doctorname;
					list_Patient[i].set_DoctorName(Doctorname);
					break;
				case 7:
					//patient_menu();
					break;
				}
				//system("cls");
				cout << "\n\n\tDo you want to come back to Edit Menu ? (Y/N)";
				cin >> c;
			} while (c == 'y' || c == 'Y');
		}
	}

	ofstream np("Patient2.csv", ios::app);
	if (!np) {
		cout << "file2 can not be opened!";
		return;
	}
	//int size1 = list_doctor2.size();
	for (int k = 0; k <list_Patient.size(); k++) {
		np << list_Patient[k].get_Name() + "  " + list_Patient[k].get_Family() + "  " + list_Patient[k].get_Phone() + "  " + list_Patient[k].get_Code() + "  " + list_Patient[k].get_Sickness() + "  " + list_Patient[k].get_DoctorName() << endl;

	}
	np.close();
	Patient.close();

	if (remove("Patient.csv") != 0)
		cout << "errorin deleting original file!" << endl;
	if (rename("Patient2.csv", "Patient.csv") != 0)
		cout << "error in renaming output file!" << endl;
}
void show_allPatient() {
	string name, family, phone, code, sickness, Doctorname;
	int i = 0;
	system("cls");
	cout << "\n\n\t\tALL PATEINT RESULT \n\n";
	cout << "=========================================================================================================\n";
	cout << "  Name       Family          Phone           Code National          Doctor Name         Sickness" << endl;
	cout << "=========================================================================================================\n";
	Patient.open("Patient.csv", ios::in);

	if (!Patient)
		cout << "not open" << endl;
	patient list;
	while (Patient >> name)
	{

		list_Patient2.push_back(list);
		list.set_Name(name);
		Patient >> family; list.set_Family(family);
		Patient >> phone; list.set_Phone(phone);
		Patient >> code; list.set_Code(code);
		Patient >> sickness; list.set_Sickness(sickness);
		Patient >> Doctorname; list.set_DoctorName(Doctorname);

	}
	cout << list_Patient2.size();

	//int size = list_doctor2.size();
	for (int k = 0; k <list_Patient2.size(); k++)
	{
		list_Patient2[k].show();
	}
	list_Patient2.clear();
	Patient.close();
}
void show_OnePatient(string codeNational) {
	string name, family, phone, code, sickness, Doctorname;

	system("cls");
	cout << "\n\n\t\tALL STUDENTS RESULT \n\n";
	cout << "=========================================================================================================\n";
	cout << "  Name       Family          Phone           Code National          Doctor Name         Sickness" << endl;
	cout << "=========================================================================================================\n";
	Patient.open("Patient.csv", ios::in);

	if (!Patient)
		cout << "not open " << endl;
	patient list;
	while (Patient >> name)
	{

		list_Patient2.push_back(list);
		list.set_Name(name);
		Patient >> family; list.set_Family(family);
		Patient >> phone; list.set_Phone(phone);
		Patient >> code; list.set_Code(code);
		Patient >> sickness; list.set_Sickness(sickness);
		Patient >> Doctorname; list.set_DoctorName(Doctorname);

	}
	//	cout<<list_Patient.size();
	//int size = list_doctor2.size();
	for (int k = 0; k < list_Patient2.size(); k++) {
		cout << list_Patient2[0].get_Code();
		cout << list_Patient2[1].get_Code();
		if (list_Patient2[k].get_Code() == codeNational) {

			list_Patient2[k].show();
		}
	}
}

void count_patient() {
	string name, family, phone, code, sickness, Doctorname;
	int count = 0;

	Patient.open("Patient.csv", ios::in);

	if (!Patient)
		cout << "not open " << endl;
	patient list;
	while (Patient >> name)
	{

		list_Patient2.push_back(list);
		list.set_Name(name);
		Patient >> family; list.set_Family(family);
		Patient >> phone; list.set_Phone(phone);
		Patient >> code; list.set_Code(code);
		Patient >> sickness; list.set_Sickness(sickness);
		Patient >> Doctorname; list.set_DoctorName(Doctorname);
		count++;
	}
	cout << "\n\tCount of Patient: " << count << endl;
}

//************************************ DOCTOR ***********************************************
//*******************************************************************************************

vector<doctor>list_doctor, list_doctor2;
//fstream Doctor;
int t = 0;

void write_doctor() {
	string name, family, phone, code, expertise,password;

	cout << "\n\t    Name: ";
	controlname_family n;
	name = n.get_namefamily();

	cout << "\n\t    Family: ";
	controlname_family f;
	family = f.get_namefamily();

	cout << "\n\t    National Code: ";
	controlcode c;
	code = c.get_Code();

	cout << "\n\t    phone Number: ";
	controlPhone ph;
	phone = ph.get_mobile();

	cout << "\n\t    Expertise: ";
	cin >> expertise;


	list_doctor.push_back(doctor(name, family, phone, code, expertise));


	ofstream Doctor("Doctor.csv", ios::app);
	Doctor << list_doctor[t].get_Name() + "  " + list_doctor[t].get_Family() + "  " + list_doctor[t].get_Phone() + "  " + list_doctor[t].get_Code() + "  " + list_doctor[t].get_Expertise() << endl;
	t++;

}
void edit_doctor(string codeNational)
{
	char ch;
	int a, i = 0;
	string name, family, phone, code, expertise;
	doctor listdoc;
	ifstream Doctor("Doctor.csv", ios::app);
	while (Doctor >> name)
	{

		list_doctor2.push_back(listdoc);
		listdoc.set_Name(name);
		Doctor >> family; listdoc.set_Family(family);
		Doctor >> phone; listdoc.set_Phone(phone);
		Doctor >> code; listdoc.set_Code(code);
		Doctor >> expertise; listdoc.set_Expertise(expertise);

	}

	//int size = list_doctor2.size();
	for (int i = 0; i <list_doctor2.size(); i++)
	{
		if (codeNational == list_doctor2[i].get_Code())
		{
			system("cls");

			do {
				cout << "\n\tEDIT DOCTOR ";
				cout << "\n\t1.  Name";
				cout << "\n\t2.  Family";
				cout << "\n\t3.  Phone Number";
				cout << "\n\t4.  National Code";
				cout << "\n\t5.  Expertise";
				cout << "\n\t7.  Back to DOCTOR MENU";


				cout << "\n\tENTER DOCTOR NATIONAL CODE: ";
				cin >> a;

				switch (a)
				{
				case 1:
					cout << "\n\t    Name: ";
					cin >> name;
					list_doctor2[i].set_Name(name);
					break;
				case 2:
					cout << "\n\t   Family: " << endl;
					cin >> family;
					list_doctor2[i].set_Family(family);
					break;
				case 3:
					cout << "\n\t   Phone Number: ";
					cin >> phone;
					list_doctor2[i].set_Phone(phone);
					break;
				case 4:
					cout << "\n\t   National Code: ";
					cin >> code;
					list_doctor2[i].set_Code(code);
					break;
				case 5:
					cout << "\n\t    Expertise: ";
					cin >> expertise;
					list_doctor2[i].set_Expertise(expertise);
					break;

				case 7:
					//doctor_menu();
					break;
				}
				//system("cls");
				cout << "\n\n\tDo you want to come back to Edit Menu ? (Y/N)";
				cin >> ch;
			} while (ch == 'y' || ch == 'Y');
		}
	}
	// Doctor("Doctor.csv");

	ofstream nd("Doctor2.csv");
	if (!nd) {
		cout << "file2 can not be opened!";
		return;
	}

	//int size = list_doctor2.size();
	for (int k = 0; k <list_doctor2.size(); k++) {
		nd << list_doctor2[k].get_Name() + "  " + list_doctor2[k].get_Family() + "  " + list_doctor2[k].get_Phone() + "  " + list_doctor2[k].get_Code() + "  " + list_doctor2[k].get_Expertise() << endl;

	}
	nd.close();
	Doctor.close();

	if (remove("Doctor.csv") != 0)
		cout << "errorin deleting original file!" << endl;
	if (rename("Doctor2.csv", "Doctor.csv") != 0)
		cout << "error in renaming output file!" << endl;

	list_doctor2.clear();
}
void show_alldoctor() {
	string name, family, phone, code, expertise;
	system("cls");
	cout << "\n\n\t\tALL DOCTOR RESULT \n\n";
	cout << "======================================================================================\n";
	cout << "  Name       Family        Phone       Code National      Expertise" << endl;
	cout << "======================================================================================\n";
	//	Doctor.open("Doctor.csv");
	ifstream Doctor("Doctor.csv", ios::in);
	if (!Doctor)
		cout << "not open " << endl;
	doctor da;
	while (Doctor >> name)
	{

		list_doctor2.push_back(da);
		da.set_Name(name);
		Doctor >> family; da.set_Family(family);
		Doctor >> phone; da.set_Phone(phone);
		Doctor >> code; da.set_Code(code);
		Doctor >> expertise; da.set_Expertise(expertise);


	}


	//int size = list_doctor2.size();
	for (int k = 0; k <list_doctor2.size(); k++)
	{
		list_doctor2[k].show();
	}

	list_doctor2.clear();
	Doctor.close();
}

void show_OneDoctor(string codeNational) {
	string name, family, phone, code, expertise;
	system("cls");
	cout << "\n\n\t\tALL DOCTOR RESULT \n\n";
	cout << "======================================================================================\n";
	cout << "  Name       Family        Phone       Code National      Expertise" << endl;
	cout << "======================================================================================\n";
	ifstream Doctor("Doctor.csv", ios::in);
	if (!Doctor)
		cout << "not open " << endl;
	doctor da;
	while (Doctor >> name)
	{
		list_doctor2.push_back(da);
		da.set_Name(name);
		Doctor >> family; da.set_Family(family);
		Doctor >> phone; da.set_Phone(phone);
		Doctor >> code; da.set_Code(code);
		Doctor >> expertise; da.set_Expertise(expertise);
	}
	//int size = list_doctor2.size();
	for (int i = 0; i <list_doctor2.size(); i++)
	{
		if (list_doctor2[i].get_Code() == codeNational)
			list_doctor2[i].show();
	}
	list_doctor2.clear();
	Doctor.close();

}
void show_PatientsOfDoctor(string doctorname)
{

	string name, family, phone, code, expertise;
	ifstream Doctor("Doctor.csv", ios::in);
	if (!Doctor)
		cout << "not open " << endl;
	doctor da;
	while (Doctor >> name)
	{
		list_doctor2.push_back(da);
		da.set_Name(name);
		Doctor >> family; da.set_Family(family);
		Doctor >> phone; da.set_Phone(phone);
		Doctor >> code; da.set_Code(code);
		Doctor >> expertise; da.set_Expertise(expertise);
	}
	for (int i = 0; i <list_doctor2.size(); i++)
	{
		if (list_Patient[i].get_DoctorName() == doctorname)
		{
			Patient >> list_Patient[i].get_Name() + " " + list_Patient[i].get_Family() + "     " + list_Patient[i].get_Sickness();
		}
	}
}

void count_doctor() {
	int count = 0;
	string name, family, phone, code, expertise;
	ifstream Doctor("Doctor.csv", ios::in);
	if (!Doctor)
		cout << "not open " << endl;
	doctor da;
	while (Doctor >> name)
	{

		list_doctor2.push_back(da);
		da.set_Name(name);
		Doctor >> family; da.set_Family(family);
		Doctor >> phone; da.set_Phone(phone);
		Doctor >> code; da.set_Code(code);
		Doctor >> expertise; da.set_Expertise(expertise);

		count++;
	}
	cout << "\n\tCount of Doctor: " << count << endl;
}
//************************************ receptionist  ****************************************
//*******************************************************************************************

vector<employee>list_reception, list_reception2;
fstream receptionist;

int j = 0;
void write_receptionist() {

	string name, family, phone, code, expertise, password,post;

	cout << "\n\t    Name: ";
	controlname_family n;
	name = n.get_namefamily();

	cout << "\n\t    Family: ";
	controlname_family f;
	family = f.get_namefamily();

	cout << "\n\t    National Code: ";
	controlcode c;
	code = c.get_Code();

	cout << "\n\t    phone Number: ";
	controlPhone ph;
	phone = ph.get_mobile();

	cout << "\n\t    post: ";
	cin >> post;

	cout << "\n\t    password: ";
	cin >> password;

	list_reception.push_back(employee(name, family, phone, code,  post,password));

	receptionist.open("Receptionist.csv", ios::app);

	receptionist<< list_reception[j].get_Name() + "," + list_reception[j].get_Family() + "," + list_reception[j].get_Phone() + "," + list_reception[j].get_Code() + "," + list_reception[j].get_post() + "," + list_reception[j].get_Pass() << endl;
	j++;
}



void edit_reseptionist(string code)
{
	char c;
	int a;
	string name, family, phone, post, password;

	//int size = list_doctor2.size();
	for (int i = 0; i <list_reception.size(); i++)
	{
		if (code == list_reception[i].get_Code())
		{
			system("cls");
			do {
				cout << "\n\tEDIT RECEPTIONIST ";
				cout << "\n\t1.  Name";
				cout << "\n\t2.  Family";
				cout << "\n\t3.  Phone Number";
				cout << "\n\t4.  National Code";
				cout << "\n\t5.  Post";
				cout << "\n\t6.  Password";
				cout << "\n\t7.  Back to Patinet Menu";


				cout << "\n\tENTER PATEINT NATIONAL CODE: ";
				cin >> a;

				switch (a)
				{
				case 1:
					cout << "\n\t    Name: ";
					cin >> name;
					list_reception[i].set_Name(name);
					break;
				case 2:
					cout << "\n\t   Family: " << endl;
					cin >> family;
					list_reception[i].set_Family(family);
					break;
				case 3:
					cout << "\n\t   Phone Number: ";
					cin >> phone;
					list_reception[i].set_Phone(phone);
					break;
				case 4:
					cout << "\n\t   National Code: ";
					cin >> code;
					list_reception[i].set_Code(code);
					break;
				case 5:
					cout << "\n\t    Post: ";
					cin >> post;
					list_reception[i].set_post(post);
					break;
				case 6:
					cout << "\n\t    Doctor Name: ";
					cin >> password;
					list_reception[i].set_Pass(password);
					break;
				case 7:
					//patient_menu();
					break;
				}
				//system("cls");
				cout << "\n\n\tDo you want to come back to Edit Menu ? (Y/N)";
				cin >> c;
			} while (c == 'y' || c == 'Y');
		}
	}

	ofstream nr("reception2.csv", ios::app);
	if (!nr) {
		cout << "file2 can not be opened!";
		return;
	}
	//int size1 = list_doctor2.size();
	for (int k = 0; k <list_reception.size(); k++) {
		nr << list_reception[k].get_Name() + "," + list_reception[k].get_Family() + "," + list_reception[k].get_Phone() + "," + list_reception[k].get_Code() + "," + list_reception[k].get_post() + "," + list_reception[k].get_Pass() << endl;

	}
	nr.close();
	receptionist.close();

	if (remove("reception.csv") != 0)
		cout << "errorin deleting original file!" << endl;
	if (rename("reception2.csv", "reception.csv") != 0)
		cout << "error in renaming output file!" << endl;
}



//************************************ employee  ****************************************
//*******************************************************************************************

vector<employee>list_employee, list_employee2;
fstream Employee;

int j = 0;
void write_employee() {

	string name, family, phone, code, expertise, post,password;

	cout << "\n\t    Name: ";
	controlname_family n;
	name = n.get_namefamily();

	cout << "\n\t    Family: ";
	controlname_family f;
	family = f.get_namefamily();

	cout << "\n\t    National Code: ";
	controlcode c;
	code = c.get_Code();

	cout << "\n\t    phone Number: ";
	controlPhone ph;
	phone = ph.get_mobile();

	cout << "\n\t    post: ";
	cin >> post;


	list_employee.push_back(employee(name, family, phone, code,password, post));

    Employee.open("Receptionist.csv", ios::app);

	Employee << list_employee[j].get_Name() + "," + list_employee[j].get_Family() + "," + list_employee[j].get_Phone() + "," + list_employee[j].get_Code() + "," + list_employee[j].get_post() << endl;
	j++;
}



void edit_employee(string code)
{
	char c;
	int a;
	string name, family, phone, post;

	//int size = list_doctor2.size();
	for (int i = 0; i <list_employee.size(); i++)
	{
		if (code == list_employee[i].get_Code())
		{
			system("cls");
			do {
				cout << "\n\tEDIT PATIENT ";
				cout << "\n\t1.  Name";
				cout << "\n\t2.  Family";
				cout << "\n\t3.  Phone Number";
				cout << "\n\t4.  National Code";
				cout << "\n\t5.  Post";
				cout << "\n\t6.  Back to Patinet Menu";


				cout << "\n\tENTER PATEINT NATIONAL CODE: ";
				cin >> a;

				switch (a)
				{
				case 1:
					cout << "\n\t    Name: ";
					cin >> name;
					list_employee[i].set_Name(name);
					break;
				case 2:
					cout << "\n\t   Family: " << endl;
					cin >> family;
					list_employee[i].set_Family(family);
					break;
				case 3:
					cout << "\n\t   Phone Number: ";
					cin >> phone;
					list_employee[i].set_Phone(phone);
					break;
				case 4:
					cout << "\n\t   National Code: ";
					cin >> code;
					list_employee[i].set_Code(code);
					break;
				case 5:
					cout << "\n\t    Post: ";
					cin >> post;
					list_employee[i].set_post(post);
					break;
				
				case 6:
					//patient_menu();
					break;
				}
				//system("cls");
				cout << "\n\n\tDo you want to come back to Edit Menu ? (Y/N)";
				cin >> c;
			} while (c == 'y' || c == 'Y');
		}
	}

	ofstream ne("employee2.csv", ios::app);
	if (!ne) {
		cout << "file2 can not be opened!";
		return;
	}
	//int size1 = list_doctor2.size();
	for (int k = 0; k <list_employee.size(); k++) {
		ne << list_reception[k].get_Name() + "," + list_reception[k].get_Family() + "," + list_reception[k].get_Phone() + "," + list_reception[k].get_Code() + "," + list_reception[k].get_post() << endl;

	}
	ne.close();
	Employee.close();

	if (remove("employee.csv") != 0)
		cout << "errorin deleting original file!" << endl;
	if (rename("employee2.csv", "employee.csv") != 0)
		cout << "error in renaming output file!" << endl;
}
//************************************ PATIENT MENU  ****************************************
//*******************************************************************************************

void patient_menu() {
	int choice;
	string code1, code;
	char h;
	do {
		system("cls");
		cout << "\n\n\tPATIENT MENU";
		cout << "\n\t1.  ADD PATIENT";
		cout << "\n\t2.  EDIT PATIENT";
		cout << "\n\t3.  COUNT OF PATIENT";
		cout << "\n\t4.  SHOW ALL PATIENTS";
		cout << "\n\t5.  SHOW ONE PATIENT";
		cout << "\n\t6.  MAIN MENU";

		cout << "\n\tYOUR CHOICE:";
		cin >> choice;

		switch (choice)
		{
		case 1:
			write_pateint();
			break;
		case 2:
			cout << "\n\tPatient National Code: ";
			cin >> code1;
			edit_patient(code1);
			break;
		case 3:
			count_patient();
			break;
		case 4:
			show_allPatient();
			break;
		case 5:
			cout << "\n\tPatient National Code: ";
			cin >> code;
			show_OnePatient(code);
			break;
		case 6:
			//Menu();
			break;

		}//system("cls");
		cout << "\n\n\tDo you want to come back to PATIENT MENU ? (Y/N)";
		cin >> h;
	} while (h == 'y' || h == 'Y');
}

//************************************ DOCTOR MENU  *****************************************
//*******************************************************************************************

void doctor_menu() {

	int choice;
	string code1, code2, doctorname;
	char b;
	do {
		system("cls");
		cout << "\n\n\tDOCTOR MENU";
		cout << "\n\t1.  ADD DOCTOR";
		cout << "\n\t2.  EDIT DOCTOR";
		cout << "\n\t3.  COUNT OF DOCTOR";
		cout << "\n\t4.  SHOW ALL DOCTOR";
		cout << "\n\t5.  SHOW ONE DOCTOR";
		cout << "\n\t6.  MAIN MENU";

		cout << "\n\tYOUR CHOICE:";
		cin >> choice;

		switch (choice)
		{
		case 1:
			write_doctor();
			break;
		case 2:
			cout << "\n\tDoctor National Code: ";
			cin >> code1;
			edit_doctor(code1);
			break;
		case 3:
			count_doctor();
			break;
		case 4:
			show_alldoctor();
			break;
		case 5:

			cout << "\n\tDoctor National Code: ";
			cin >> code2;
			show_OneDoctor(code2);
			break;
		case 6:
			cout << "\n\tDoctor Name & Family: ";
			cin >> doctorname;
			show_PatientsOfDoctor(doctorname);
			break;
		case 7:
			//	Menu();
			break;
		}
		//system("cls");
		cout << "\n\n\tDo you want to come back to DOCTOR MENU ? (Y/N)";
		cin >> b;
	} while (b == 'y' || b == 'Y');

}
//************************************ EMPLOYEE MENU  ****************************************
//********************************************************************************************


void employee_menu() {

	int choise1, choise2;
	string a;
	cout << "\n\t1. Reseptionist";
	cout << "\n\t2. Other Emloyee";

	cin >> choise1;

	switch (choise1)
	{

	case 1:
	{
		cout << "\n\t1. Add Reseptionist";
		cout << "\n\t2. Edit Reseptionist";
		cout << "\n\t3. Exit";

		cin >> choise2;

		switch (choise2)
		{
		case 1:
		{
			write_receptionist();
			break;
		}
		case 2:
		{
			cout << "\n\Reseptionist National Code: ";
			cin >> a;
			edit_reseptionist(a);
			break;
		}
		}
		break;
	}

	case 2:
	{
		cout << "\n\t1. Add Employee";
		cout << "\n\t2. Edit Employee";
		cout << "\n\t3. Exit";

		cin >> choise2;

		switch (choise2)
		{
		case 1:
		{
			write_employee();
			break;
		}
		case 2:
		{
			cout << "\n\Employee National Code: ";
			cin >> a;
			edit_employee(a);
			break;
		}
		case 3:
			break;
		}
	}
	}
}


//************************************ main menu  ****************************************
//****************************************************************************************



int main()
{
	int choice;
	char cha;
	do {
		system("cls");
		cout << "\n\n\tMAIN MENU";
		cout << "\n\t1.  PATIENT MENU";
		cout << "\n\t2.  DOCTOR MENU";
		cout << "\n\t3.  EMPLOYEE MENU";
		cout << "\n\t4.  EXIT";

		cout << "\n\tYOUR CHOICE:";
		cin >> choice;
		switch (choice)
		{
		case 1:
			patient_menu();
			break;
		case 2:
			doctor_menu();
			break;
		case 3:
		

			break;
		case 4:
			break;
		}
		//	system("cls");
		cout << "\n\n\tDo you want to come back to MAIN MENU ? (Y/N)";
		cin >> cha;
	} while (cha == 'y' || cha == 'Y');
	return 0;
}

