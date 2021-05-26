#pragma once
#include<map>
#include<vector>
#include"Article.h"
#include<string>

class gestionProduit
{
public:
	gestionProduit(std::string soursPath);
	Article* getArticleByid(unsigned id);
	Article* getArticleByName(std::string nam);
	void addArticle(Article article);
	void addArticle(std::string nom, unsigned type, double prix, double coup, double multiplicateurLivraison);



private:
	std::vector<Article> articles_;
	std::map<unsigned, Article*> sortById_;
	std::map<unsigned, Article*> sortByType_;
	std::map<std::string, Article*> sortByNam_;


};

