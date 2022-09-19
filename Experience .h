#pragma once
/*Đối với nhân viên Experience có thêm thuộc tính: Số năm kinh nghiệm (ExpInYear), Kỹ năng chuyên môn (ProSkill)*/
#include"Employee.h"
class Experience: public Employee
{
public:
	Experience();

	void SetExpInYear(int);
	int GetExpInYear();

	void SetProSkill(string);
	string GetProSkill();

	virtual void InputInfor();
	virtual void OutputInfor();

	~Experience();

private:
	int nExpInYear;
	string sProSkill;
};

