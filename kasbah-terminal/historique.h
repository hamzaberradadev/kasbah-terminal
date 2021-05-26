#pragma once
#include<string>
class Historique
{
public:
	Historique(double monton, bool deboursement, std::string description) :
		monton_(monton),
		deboursement_(deboursement),
		description_(description)
	{};
	double monton_;
	bool deboursement_;
	std::string description_;

};

