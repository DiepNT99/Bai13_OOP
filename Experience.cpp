#include"Experience .h"
Experience::Experience():Employee() {
	this->nExpInYear = 0;
	sProSkill = "";
}

void Experience::SetExpInYear(int ExpInYear){
	this->nExpInYear = ExpInYear;
}
int Experience::GetExpInYear(){
	return this->nExpInYear;
}

void Experience::SetProSkill(string ProSkill){
	this->sProSkill = ProSkill;
}
string Experience::GetProSkill() { return this->sProSkill; }

void Experience::InputInfor(){
	this->SetEmployee_type(0);
	Employee::InputInfor();
	int nTemp{0};
	cout << "Enter Experiance in year: "; cin >> nTemp; this->SetExpInYear(nTemp);
	cout << "Enter Professional Skill: "; cin.ignore(); string sTemp{ "" }; 
	getline(cin, sTemp); this->SetProSkill(sTemp);
}
void Experience::OutputInfor(){
	cout << "--------------Information of Experiance--------------" << endl;
	Employee::OutputInfor();
	cout << "Experiance in year: " << this->GetExpInYear() << endl;
	cout << "Professional skill: " << this->GetProSkill() << endl;
}

Experience::~Experience(){}