#pragma once
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
		time_t secondes;
		struct tm instant;

		time(&secondes);
		instant = *localtime(&secondes);
		date_.year_ = instant.tm_year + 1;
		date_.month_ = instant.tm_mon + 1;
		date_.day_ = instant.tm_mday + 1;
	}
	Time(Date date)
	{
		date.year_ = date.year_;
		date_.month_ = date.month_;
		date_.day_= date.day_;
	};


	unsigned getIdFromtime() {
		return(((date_.year_ - 2000) * 1000000) + (date_.month_ * 10000) + date_.day_ * 100) + 100 + (int)((float)rand() / (RAND_MAX - 1));
	};
	std::string getDateString() { return std::to_string(date_.year_) + "/" + std::to_string(date_.month_) + "/" + std::to_string(date_.day_); };
	Date getdate() { return date_; }
	Date date_;
};