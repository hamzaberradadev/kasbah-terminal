#include<string>
//#include"gestionclient.h"
//#include"gestionTransactions.h"
//#include"gestionUtilisateur.h"
#include <iostream>
#include <ctime>
#include"utile.h"

#include <iostream>

int main()
{
	Time date;
	for (size_t i = 0; i < 10000; i++)
	{
		std::cout << std::to_string(date.getIdFromtime())<< std::endl;
	}
	std::cout<<std::to_string(date.getIdFromtime());
	return 0;
};