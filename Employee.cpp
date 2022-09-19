#include"Employee.h"
Employee::Employee() {
	cetificate.resize(0);
	this->sID = "";
	this->sBirthDay = "";
	this->sEmail = "";
	this->sFullName = "";
	this->sPhone = "";
	this->nEmployee_type = 0;
	this->nEmplyee_count = 0;
}

void Employee::SetID(string ID) { this->sID = ID; }
void Employee::SetFullName(string FullName) { this->sFullName = FullName; }
void Employee::SetBirthDay(string BirthDay) { this->sBirthDay = BirthDay; }
void Employee::SetPhone(string Phone) { this->sPhone = Phone; }
void Employee::SetEmail(string Email) { this->sEmail = Email; }

void Employee::SetEmployee_type(int Employee_type) { this->nEmployee_type = Employee_type; }
void Employee::SetEmployee_count(int Employee_count) { this->nEmplyee_count = Employee_count; }

string Employee::GetID() { return this->sID; }
string Employee::GetFullName() { return this->sFullName; }
string Employee::GetBirthDay() { return this->sBirthDay; }
string Employee::GetPhone() { return this->sPhone; }
string Employee::GetEmail() { return this->sEmail; }

int Employee::GetEmployee_type() { return this->nEmployee_type; }
int Employee::GetEmployee_count() { return this->nEmplyee_count; }

bool Employee::BirthDayException(string BirthDay){
	try
	{
		/*stringstream ss(BirthDay);
		string index;
		ss >> index;
		while (ss >> index)
		{*/
		if (BirthDay.length()>0)
		{
			for (int i = 0; i < BirthDay.length(); i++) {
				if ((BirthDay[i] < 47) || (BirthDay[i] > 58)) {
					throw Exception("Error Day Of Birth!");
				}
			}
		}
		else
		{
			throw Exception("Error Day Of Birth!");
		}
			
		/*}*/
	}
	catch (Exception& ex)
	{
		cout << ex.what() << endl;
		return false;
	}
	return true;
}
bool Employee::PhoneException(string Phone){
	try
	{
		/*stringstream ss(Phone);
		string index;
		ss >> index;
		while (ss >> index)*/
		//{i
		if (Phone.size()>0)
		{
			for (int i = 0; i < Phone.length(); i++) {
				if ((Phone[i] < 47) || (Phone[i] > 58)) {
					throw Exception("Error Phone number!");
				}
			}
		}
		else
		{
			throw Exception("Error Phone number!");
		}
			
		//}
	}
	catch (Exception& ex)
	{
		cout << ex.what() << endl;
		return false;
	}
	return true;
}
bool Employee::EmailException(string Email){
	string sTemp = "@gmail.com";
	int nTemp{ 0 };
	//@gmail.com is important if dont have it -> error
	//Don't have special keyword
	//Don't have space in email 
	try
	{
		if (Email.length()<=10)
		{
			throw Exception("Error Email!");
		}
		else
		{
			for (int i = 0; i < Email.length(); i++)
			{
				if (Email[i] == ' ')
				{
					throw Exception("Error Email!");
					break;
				}
			}
		}
	
		for (int i = Email.length() - 10; i < Email.length(); i++)
		{
			if (Email[i] == sTemp[nTemp])
			{
				nTemp++;
				continue;
			}
			else
			{
				throw Exception("You need to add @gmail.com for your Email!");
			}
		}
	}
	catch (Exception& ex)
	{
		cout << ex.what() << endl;
		return false;
	}
	return true;
}
bool Employee::FullNameException(string FullName)
{
	try
	{
		if (FullName.size()>0)
		{
			for (int i = 0; i < FullName.length(); i++) {
				if ((FullName[i] > 64 && FullName[i] < 91)) {
					continue;
				}
				if ((FullName[i] > 96) && (FullName[i] < 123))
				{
					continue;
				}
				if (FullName[i] == ' ')
				{
					continue;
				}
			/*	if (FullName[i] > 47 && FullName[i] < 58)
				{
					throw Exception("Error Name!");
				}*/
				else
				{
					throw Exception("Error Name!");
				}
			}
		}
		else
		{
			throw Exception("Error Name!");
		}
			
	}
	catch (Exception& ex)
	{
		cout << ex.what() << endl;
		return false;
	}
	return true;
}

void Employee::InputInfor(){
	string sTemp{ "" };
	cout << "Enter ID of Employee: "; getline(cin, sTemp); this->SetID(sTemp);
	do
	{
		cout << "Enter full name of employee: "; getline(cin, sTemp); CheckName(sTemp);
	} while (!FullNameException(sTemp)); this->SetFullName(sTemp)/*;cin.ignore()*/; string Arr[3]{ "" };
	for (int i = 0; i < 3; i++)
	{
		switch (i)
		{
		case 0:
		{
			do
			{
				cout << "Enter day of birth: "; getline(cin, Arr[i]);
			} while (!BirthDayException(Arr[i]));
			break;
		}
		case 1:
		{
			do
			{
				cout << "Enter month of birth: "; getline(cin, Arr[i]);
			} while (!BirthDayException(Arr[i]));
			break;
		}
		case 2:
		{
			do
			{
				cout << "Enter year of birth: "; getline(cin, Arr[i]);
			} while (!BirthDayException(Arr[i]));
			break;
		}
		}
	}
	sTemp = Arr[0] + "/" + Arr[1] + "/" + Arr[2]; this->SetBirthDay(sTemp);
	do
	{
		cout << "Enter email of employee: "; getline(cin, sTemp);
	} while (!EmailException(sTemp)); this->SetEmail(sTemp);
	cout << "Enter number of employee's certificate: "; int nTemp{ 0 }; cin >> nTemp; cin.ignore();
	if (nTemp!=0)
	{
		for (int i = 0; i < nTemp; i++)
		{
			system("cls");
			cout << "--------------Cer [" << i + 1 << "]-----------------" << endl;
			unique_ptr<Certificate> cer(new Certificate);
			cer->SetCertificate();
			this->cetificate.push_back(move(cer));
			cout << "--------------End [" << i + 1 << "]-----------------" << endl;
		}
	}
}
void Employee::OutputInfor(){
	cout << "ID of Employee: " << this->GetID() << endl;
	cout << "FullName of Employee: " << this->GetFullName() << endl;
	cout << "Birthday of Employee: " << this->GetBirthDay() << endl;
	cout << "Email of Employee: " << this->GetEmail() << endl;
	for (int i = 0; i < cetificate.size(); i++)
	{
		cout << "--------------Cer [" << i + 1 << "]-----------------" << endl;
		cetificate[i]->GetCertificate();
		cout << "--------------End [" << i + 1 << "]-----------------" << endl;
	}
}

Employee::~Employee(){}