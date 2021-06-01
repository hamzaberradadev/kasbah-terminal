#pragma once
#include"utile.h"
#include<string>
class historique
{
public:
	historique(unsigned id, unsigned long monton, bool deboursement, std::string description) :
		id_(id),
		montonX100_(monton),
		deboursement_(deboursement),
		description_(description)
	{};
	historique(unsigned long monton, bool deboursement, std::string description) :
		montonX100_(monton),
		deboursement_(deboursement),
		description_(description)
	{
		id_ = Time::getIdFromtime();
	};
	unsigned id_;
	unsigned long montonX100_;
	bool deboursement_;
	std::string description_;

};

