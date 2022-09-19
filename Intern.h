#pragma once
/*Đối với nhân viên Intern có thêm thuộc tính: Chuyên ngành đang học (Majors), Học kì đang học (Semester), 
Tên trường đang học (University_name)*/
#include"Employee.h"
class Intern : public Employee
{
public:
	Intern();

	void SetMajors(string);
	string GetMajors();

	void SetUniversity_name(string);
	string GetUniversity_name();

	void SetSemester(string);
	string GetSemester();

	virtual void InputInfor();
	virtual void OutputInfor();

	~Intern();

private:
	string Majors, University_name, Semester;
};