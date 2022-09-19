#pragma once
#include"Fresher.h"
#include"Experience .h"
#include"Intern.h"

class EmployeeManagerment
{
public:
	EmployeeManagerment();

	void AddEmployee();
	void ShowEmployee();
	void RepairEmployee();
	void SearchEmployee();
	void DeleteEmployee();

	~EmployeeManagerment();
	void CheckDup();
private:
	vector<unique_ptr<Employee>> employee;
};
