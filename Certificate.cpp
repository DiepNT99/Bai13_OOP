#include"Certificate.h"
Certificate::Certificate() :CertificatedID(""), CertificateName(""), CertificateRank(""), CertificatedDate(""){};

void Certificate::SetCertificatedID(string CertificatedID) { this->CertificatedID = CertificatedID; }
string Certificate::GetCertificatedID() { return this->CertificatedID; }

void Certificate::SetCertificateName(string CertificateName) { this->CertificateName = CertificateName; }
string Certificate::GetCertificateName() { return this->CertificateName; }

void Certificate::SetCertificateRank(string CertificateRank) { this->CertificateRank = CertificateRank; }
string Certificate::GetCertificateRank() { return this->CertificateRank; }

void Certificate::SetCertificatedDate(string CertificatedDate) { this->CertificatedDate = CertificatedDate; }
string Certificate::GetCertificatedDate() { return this->CertificatedDate; }

void Certificate::SetCertificate()
{
	string sTemp{ "" };
	cout << "Enter Certificated ID: "; getline(cin, sTemp); this->SetCertificatedID(sTemp);
	cout << "Enter Certificated Name: "; getline(cin, sTemp); CheckName(sTemp); this->SetCertificateName(sTemp);
	cout << "Enter Certificated Rank: "; getline(cin, sTemp); this->SetCertificateRank(sTemp);
	string Arr[3]{ "" };
	for (int i = 0; i < 3; i++)
	{
		switch (i)
		{
		case 0:
		{
			do
			{
				cout << "Enter day of cetificate: "; getline(cin,Arr[i]);
			} while (!CertificatedDateException(Arr[i]));
			break;
		}
		case 1:
		{
			do
			{
				cout << "Enter month of cetificate: "; getline(cin, Arr[i]);
			} while (!CertificatedDateException(Arr[i]));
			break;
		}
		case 2:
		{
			do
			{
				cout << "Enter year of cetificate: "; getline(cin, Arr[i]);
			} while (!CertificatedDateException(Arr[i]));
			break;
		}
		}
	}
	sTemp = Arr[0] + "/" + Arr[1] + "/" + Arr[2]; this->SetCertificatedDate(sTemp);
}
void Certificate::GetCertificate()
{
	cout << "Certificated ID: "<< this->GetCertificatedID() << endl;
	cout << "Certificated Name: "<< this->GetCertificateName() << endl;;
	cout << "Certificated Rank: "<< this->GetCertificateRank() << endl;;
	cout << "Certificated Date: "<< this->GetCertificatedDate() << endl;;
}
bool Certificate::CertificatedDateException(string CertificatedDate)
{
	try {

		if (CertificatedDate.size()>0)
		{
			for (int i = 0; i < CertificatedDate.length(); i++) {
				if ((CertificatedDate[i] < 47) || (CertificatedDate[i] > 58)) {
					throw Exception("Error date of Certificate!");
				}
			}
		}
		else
		{
			throw Exception("Error date of Certificate!");
		}
	}
	catch (Exception& ex) {
		cout << ex.what() << endl;
		return false;
	}
	return true;
}

Certificate::~Certificate(){}