#pragma once
#include<string>
class historique
{
public:
	historique(unsigned long monton, bool deboursement, std::string description) :
		montonX100_(monton),
		deboursement_(deboursement),
		description_(description)
	{};
	unsigned long montonX100_;
	bool deboursement_;
	std::string description_;

};

