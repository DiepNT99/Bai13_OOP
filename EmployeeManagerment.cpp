#include"EmployeeManagerment.h"
EmployeeManagerment::EmployeeManagerment() { employee.clear(); }

void EmployeeManagerment::AddEmployee(){
	int nChoine{ 0 };
	system("cls");

	do
	{
		std::cout << "Type of employee: \n" << "0. Experiance\n" << "1. Fresher\n" << "2. Intern" << std::endl;
		std::cout << "Enter your choice: "; std::cin >> nChoine; cin.ignore();
	} while (nChoine < 0 || nChoine>2);

	if (nChoine == 0)
	{
		system("cls");
		std::unique_ptr<Experience> experience(new Experience);
		experience->InputInfor();
		employee.push_back(move(experience));
	}
	else if (nChoine == 1)
	{
		system("cls");
		std::unique_ptr<Fresher> fresher(new Fresher);
		fresher->InputInfor();
		employee.push_back(move(fresher));
	}
	else
	{
		system("cls");
		std::unique_ptr<Intern> intern(new Intern);
		intern->InputInfor();
		employee.push_back(move(intern));
	}
}
void EmployeeManagerment::ShowEmployee(){
	for (int i = 0; i < employee.size(); i++)
	{
		employee[i]->OutputInfor();
	}
	system("pause");
}
void EmployeeManagerment::RepairEmployee(){
	system("cls");
	int nChoice{ 0 };
	std::string sChoine = "";
	do
	{
		std::cout << "Do you want to repair employee: \n" << "1. Enter ID\n" << "2. Exit" << std::endl;
		std::cin >> nChoice;
	} while (nChoice < 1 || nChoice>2);
	switch (nChoice)
	{
	case 1:
	{
		system("cls");
		std::cout << "Enter Id of employee here: "; std::cin.ignore(); getline(std::cin, sChoine);
		for (int i = 0; i < employee.size(); i++)
		{
			if (employee[i]->GetID() == sChoine)
			{

				employee[i]->InputInfor();
				break;
			}
			else
			{
				std::cout << "Don't have ID you add in database!" << std::endl;
			}
		}
		break;
	}
	case 2:
		break;
	}
}
void EmployeeManagerment::SearchEmployee(){
	int nChoine{ 0 };
	system("cls");
	do
	{
		std::cout << "Type of employee: \n" << "0. Experiance\n" << "1. Fresher\n" << "2.Intern" << std::endl;
		std::cout << "Enter your choice: "; std::cin >> nChoine;
	} while (nChoine < 1 || nChoine>3);

	if (nChoine == 0)
	{
		system("cls");
		for (int i = 0; i < employee.size(); i++)
		{
			if (employee[i]->GetEmployee_type() == 0)
			{
				employee[i]->OutputInfor();
				system("pause");
			}
			/*	std::unique_ptr<Sach> s = ;*/
		}
	}
	else if (nChoine == 1)
	{
		system("cls");
		for (int i = 0; i < employee.size(); i++)
		{
			if (employee[i]->GetEmployee_type() == 1)
			{
				employee[i]->OutputInfor();
				system("pause");
			}
			/*	std::unique_ptr<Sach> s = ;*/
		}
	}
	else
	{
		system("cls");
		for (int i = 0; i < employee.size(); i++)
		{
			if (employee[i]->GetEmployee_type() == 2)
			{
				employee[i]->OutputInfor();
				system("pause");
			}
			/*	std::unique_ptr<Sach> s = ;*/
		}
	}
}
void EmployeeManagerment::DeleteEmployee(){
	system("cls");
	int nChoice{ 0 };
	std::string sChoine = "";
	do
	{
		std::cout << "Do you want to delete employee: \n" << "1. Enter ID\n" << "2. Exit" << std::endl;
		std::cin >> nChoice;
	} while (nChoice < 1 || nChoice>2);
	switch (nChoice)
	{
	case 1:
	{
		system("cls");
		std::cout << "Enter Id of employee here: "; std::cin.ignore(); getline(std::cin, sChoine);
		for (int i = 0; i < employee.size(); i++)
		{
			if (employee[i]->GetID() == sChoine)
			{

				employee.erase(employee.begin() + i);
				i--;
				break;
			}
			else
			{
				std::cout << "Don't have ID you add in database!" << std::endl;
			}
		}
		break;
	}
	case 2:
		break;
	}
}
void EmployeeManagerment::CheckDup()
{
	for (int i = 0; i < employee.size() - 1; i++)
	{
		for (int j = i + 1; j < employee.size(); j++)
		{
			if (employee[i]->GetID() == employee[j]->GetID())
			{
				std::string sTemp = "";
				std::cout << "Duplicate ID of employee! pls,enter again:";
				/*std::cin.ignore();*/ std::getline(std::cin, sTemp);
				employee[j]->SetID(sTemp);
			}
		}
	}
}
EmployeeManagerment::~EmployeeManagerment(){}
