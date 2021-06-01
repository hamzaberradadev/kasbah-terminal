#include<string>
#include"gestionclient.h"
//#include"gestionTransactions.h"
//#include"gestionUtilisateur.h"
#include"Article.h"
#include"clients.h"
#include"transaction.h"
#include"utilisateur.h"
#include <iostream>
#include <ctime>
#include"utile.h"

#include <iostream>

int main()
{
	//Article bijou ("bijou",1,9.99,6.87,2);
	//Utilisateur utilisa("ab","mom",false);
	//Transaction transaction(utilisa.Id_);
	Client client("hamza", "4384084283", "blabla", "blabla");
	gestionClient gC("C:/Users/5hamz/OneDrive/Documents/MEGAsync/kasbah/clients.txt");
	//gC.addClient(client);
	//gC.addClient("mohamed","34839328","blabla","lablab");
	if (gC.getClientByNam("hamza").getid() == 0) 
	{ 
		std::cout << false;
	}
	else
	{
		std::cout << true;
	}
	

};