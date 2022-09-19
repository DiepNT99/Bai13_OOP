#pragma once
#include"Lib.h"
class Certificate
{
public:
	Certificate();

	void SetCertificatedID(string);
	string GetCertificatedID();

	void SetCertificateName(string);
	string GetCertificateName();

	void SetCertificateRank(string);
	string GetCertificateRank();

	void SetCertificatedDate(string);
	string GetCertificatedDate();

	void SetCertificate();
	void GetCertificate();

	bool CertificatedDateException(string);

	~Certificate();

private:
	string CertificatedID, CertificateName, CertificateRank, CertificatedDate;
};
