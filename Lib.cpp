#include"Lib.h"
bool CheckName(string& sText)
{
	if (sText.size()>0)
	{
		string sTemp{ "" };
		while ((sText.begin() < (sText.end() - 1)) && (*sText.begin() == ' '))
		{
			sTemp.clear();
			for (string::iterator it = (sText.begin() + 1); it < (sText.end()); it++)
			{
				sTemp.push_back(*it);
				//lenght--;
			}
			sText.clear();
			sText = sTemp;
		}
		while ((sText.begin() < (sText.end() - 1)) && (*(sText.end() - 1) == ' '))
		{
			sTemp.clear();
			for (string::iterator it = sText.begin(); it != sText.end() - 1; it++)
			{
				sTemp.push_back(*it);
				//lenght--;
			}
			sText.clear();
			sText = sTemp;
		}
		for (string::iterator it = sText.begin(); it != sText.end() - 1; it++)
		{
			// Đưa hết về chữ thường
			if (*it >= 'A' && *it <= 'Z') {
				*it += 32;
			}
			// Bỏ dấu trắng thừa ở giữa
		}
		for (string::iterator it = sText.begin(); it != sText.end() - 1; it++)
		{
			if ((*it == *(it + 1)) && (*it == ' '))
			{
				sText.erase(it);
				it--;
				//continue;
			}
		}
		for (string::iterator it = sText.begin(); it != sText.end() - 1; it++)
		{
			if ((*(it + 1) != ' ') && (*it == ' '))
			{
				*(it + 1) -= 32;
				//continue;
			}
		}

		if (*(sText.begin()) >= 'a' && *(sText.begin()) <= 'z')
		{
			*(sText.begin()) -= 32;
		}
	}
	else
	{
		return false;
	}
	return true;
}
bool CheckNum(string nText)
{
	if (nText.size()>0)
	{
		for (int i = 0; i < nText.length(); i++) {
			if ((nText[i] < 47) || (nText[i] > 58)) {
				return false;
			}
		}
	}
	else
	{
		return false;
	}

	return true;
}