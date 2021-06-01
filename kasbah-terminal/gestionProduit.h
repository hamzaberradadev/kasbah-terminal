#pragma once
#include<map>
#include<vector>
#include<set>
#include"Article.h"
#include<string>
#include<fstream>
class gestionProduit
{
public:
	gestionProduit(std::string soursPath);
	~gestionProduit();
	Article* getArticleByid(unsigned id);
	Article* getArticleByName(std::string nam);
	void addArticle(Article article, unsigned stock);
	void addArticle(std::string nom, unsigned type, double prix, double coup, double multiplicateurLivraison);
	void sort();


private:
	std::vector<Article> articles_;
	std::map<unsigned, unsigned> idToLigne;// position ligne dans le fichier
	std::map<unsigned, Article*> sortById_;
	std::map<unsigned, Article*> sortByType_;
	std::map<std::string, Article*> sortByNam_;
	std::string soursPath_;
	std::vector<Article*> toBeAdded_;
	std::set<unsigned> ligneToBe_delet;


};

