#pragma once
#include<ctime>
#include <stdio.h>
class Time
{
public:
	Time() 
	{
		time_t secondes;
		struct tm instant;

		time(&secondes);
		instant = *localtime(&secondes);
		year_ = instant.tm_year+1;
		month_ = instant.tm_mon + 1;
		day_ = instant.tm_mday + 1;
	}
	unsigned year_, month_, day_;
};