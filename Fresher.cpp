#include"Fresher.h"
Fresher::Fresher():Employee() {
	this->Graduation_date = "";
	this->Graduation_rank = "";
	this->Education = "";
}

void Fresher::SeGraduation_date(string Graduation_date){this->Graduation_date = Graduation_date;}
string Fresher::GetGraduation_date() { return this->Graduation_date; }

void Fresher::SetGraduation_rank(string Graduation_rank) { this->Graduation_rank = Graduation_rank; }
string Fresher::GetGraduation_rank() { return this->Graduation_rank; }

void Fresher::SetEducation(string Education) { this->Education = Education; }
string Fresher::GetEducation() { return Education; }

void Fresher::InputInfor(){
	this->SetEmployee_type(1);
	Employee::InputInfor();
	string sTemp{ "" };
	string Arr[3]{ "" };
	for (int i = 0; i < 3; i++)
	{
		switch (i)
		{
		case 1:
		{
			do
			{
				cout << "Enter day of graduation: "; getline(cin, Arr[i]);
			} while (!GraduationDateException(Arr[i]));
			break;
		}
		case 2:
		{
			do
			{
				cout << "Enter month of graduation: "; getline(cin, Arr[i]);
			} while (!GraduationDateException(Arr[i]));
			break;
		}
		case 3:
		{
			do
			{
				cout << "Enter year of graduation: "; getline(cin, Arr[i]);
			} while (!GraduationDateException(Arr[i]));
			break;
		}
		}
	}
	sTemp = Arr[0] + "/" + Arr[1] + "/" + Arr[2]; this->SeGraduation_date(sTemp);
	cout << "Enter graduation rank: "; getline(cin, sTemp); this->SetGraduation_rank(sTemp);
	cout << "Enter Education of employee: "; getline(cin, sTemp); this->SetEducation(sTemp);
}
void Fresher::OutputInfor(){
	cout << "--------------Information of Fresher--------------" << endl;
	Employee::OutputInfor();
	cout << "Graduation date: " << this->GetGraduation_date() << endl;
	cout << "Graduation rank: " << this->GetGraduation_rank() << endl;
	cout << "Education: " << this->GetEducation() << endl;
}

bool Fresher::GraduationDateException(string Graduation_date)
{
	try
	{
		if (Graduation_date.size() > 0)
		{

			for (int i = 0; i < Graduation_date.length(); i++) {
				if ((Graduation_date[i] < 47) || (Graduation_date[i] > 58)) {
					throw Exception("Error date of graduation!");
				}
			}

		}
		else
		{
			throw Exception("Error date of graduation!");
		}
	}
	
		
	catch (Exception& ex) {
		cout << ex.what() << endl;
		return false;
	}
	return true;
}
Fresher::~Fresher(){}