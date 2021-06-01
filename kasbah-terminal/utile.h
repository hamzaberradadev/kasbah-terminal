#pragma once
#pragma warning(disable : 4996)
#include<ctime>
#include <stdio.h>
#include<string>
struct Date
{
	unsigned year_, month_, day_;
};
class Time
{
public:
	Time()
	{
		time_t now;
		// Renvoie l'heure actuelle
		time(&now);
		struct tm* local = localtime(&now);
		date_.year_ = local->tm_year + 1900;
		date_.month_ = local->tm_mon + 1;
		date_.day_ = local->tm_mday;
	}
	Time(Date date)
	{
		date.year_ = date.year_;
		date_.month_ = date.month_;
		date_.day_= date.day_;
	};


	static unsigned getIdFromtime() {
		time_t now;
		time(&now);
		struct tm* local = localtime(&now);
		return(((local->tm_year-100) * 100000000) + ((local->tm_mon+1) * 1000000) + (local->tm_mday * 10000) + ( ((local->tm_min+1)*(local->tm_hour+1))*(local->tm_sec+1)));
	};
	std::string getDateString() { return std::to_string(date_.year_) + "/" + std::to_string(date_.month_) + "/" + std::to_string(date_.day_); };
	Date getdate() { return date_; }
	Date date_;
};
