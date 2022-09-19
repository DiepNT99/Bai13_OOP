#pragma once
/*Đối với nhân viênn Fresher có thêm thuộc tính: Thời gian tốt nghiệp(Graduation_date), Xếp loại tốt nghiệp (Graduation_rank) , 
Trường tốt nghiệp (Education)*/
#include"Employee.h"
class Fresher : public Employee
{
public:
	Fresher();

	void SeGraduation_date(string);
	string GetGraduation_date();

	void SetGraduation_rank(string);
	string GetGraduation_rank();

	void SetEducation(string);
	string GetEducation();

	virtual void InputInfor();
	virtual void OutputInfor();

	bool GraduationDateException(string);
	~Fresher();

private:
	string Graduation_date, Graduation_rank, Education;
};