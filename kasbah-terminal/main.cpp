#include<string>
#include"gestionclient.h"
#include"gestionHistorique.h"
#include"gestionProduit.h"
#include"gestionTransactions.h"
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
	Article bijou ("bijou",1,9.99,6.87,2);
	Utilisateur utilisa("ab","mom",false);
	Transaction transaction(utilisa.Id_);
	Client client("hamza", "4384084283", "blabla", "blabla");
	//gestionClient gC("C:/Users/5hamz/OneDrive/Documents/MEGAsync/kasbah/clients.txt");
	//historique h(10099,1,"init");
	//gestionHistorique gH("C:/Users/5hamz/OneDrive/Documents/MEGAsync/kasbah/historique.txt");
	//gH.addhist(h);
	//gC.addClient(client);
	//gC.addClient("mohamed","34839328","blabla","lablab");
	//gestionProduit gP("C:/Users/5hamz/OneDrive/Documents/MEGAsync/kasbah/produits.txt");
	//gP.addArticle(bijou,unsigned (3));
	//std::string nom, unsigned type, double prix, double coup, double multiplicateurLivraison
	//std::cout << gP.getArticleByName(bijou.getNom())->getPrix();
	GestionTransaction gT("C:/Users/5hamz/OneDrive/Documents/MEGAsync/kasbah/transactions.txt");
	//gT.addTrans(transaction);
	gT.getTransactionByid(2106070290)->addarticle(bijou,3);
	gT.actualiserTr(2106070290);
	

};