#include"Intern.h"
/*string Majors, University_name, Semester;*/
Intern::Intern() :Majors(""), University_name(""), Semester("") {}

void Intern::SetMajors(string Majors) { this->Majors = Majors; }
string Intern::GetMajors() { return this->Majors; }

void Intern::SetUniversity_name(string University_name) { this->University_name = University_name; }
string Intern::GetUniversity_name() { return University_name; }

void Intern::SetSemester(string Semestier) { this->Semester = Semestier; }
string Intern::GetSemester() { return this->Semester; }

void Intern::InputInfor(){
	this->SetEmployee_type(2);
	Employee::InputInfor();
	string sTemp{""};
	cout << "Enter Major: "; getline(cin, this->Majors);
	cout << "Enter university name: "; getline(cin, this->University_name);
	cout << "Enter semester:"; getline(cin, this->Semester);
}
void Intern::OutputInfor(){
	cout << "--------------Information of Intern--------------" << endl;
	Employee::OutputInfor();
	cout << "Majors: " << this->GetMajors() << endl;
	cout << "University name: " << this->GetUniversity_name() << endl;
	cout << "Semester: " << this->GetSemester() << endl;
}

Intern::~Intern(){}