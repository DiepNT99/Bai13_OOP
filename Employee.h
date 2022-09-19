#pragma once
/*Tất cả các Employee đều có các thuộc tính là: ID, FullName, BirthDay,Phone, Email, Employee_type,Employee_count
Employee_typecó giá trị tương ứng là 0: Experience, 1: Fresher , 2: Intern  (tùy vào người dùng nhập vào ứng viên loại nào)
Employee_count dùng để người dùng đếm số lượng nhân viên trong một đợt người dùng nhập nhân viên mới  vào cơ sở dữ liệu. 
(mỗi lần người dùng nhập thêm mới nhân viên thì thuộc tính Employee_count của class Employee sẽ tăng lên 1)
Viết các hàm kiểm tra tính hợp lệ của ngày sinh, email, tên và số điện thoại của nhân viên. Áp dụng các hàm này vào chức năng số 7.*/
#include"Certificate.h"
class Employee
{
public:
	Employee();

	void SetID(string);
	void SetFullName(string);
	void SetBirthDay(string);
	void SetPhone(string);
	void SetEmail(string);

	void SetEmployee_type(int);
	void SetEmployee_count(int);

	string GetID( );
	string GetFullName();
	string GetBirthDay();
	string GetPhone();
	string GetEmail();

	virtual int GetEmployee_type();
	int GetEmployee_count();

	bool BirthDayException(string);
	bool PhoneException(string);
	bool EmailException(string);
	bool FullNameException(string);


	virtual void InputInfor();
	virtual void OutputInfor();

	virtual ~Employee();

private:
	string sID, sFullName, sBirthDay, sPhone, sEmail;
	int nEmployee_type, nEmplyee_count;
	vector<unique_ptr<Certificate>> cetificate;
};
