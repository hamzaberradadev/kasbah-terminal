#include"transaction.h"

Transaction::Transaction(unsigned Idmarchand)
{
	Time tm;
	dateS_ = tm.getDateString();
	date_ = tm.getdate();
	idMarchand_ = Idmarchand;
	idClient_ = 0;
	idTransaction_ = tm.getIdFromtime();
	sousTotal_ = 0;
}

Transaction::Transaction(unsigned id, unsigned idclient, unsigned Idmarchand, Date date,unsigned st, std::map<unsigned, unsigned>& products)
{
	Time tm(date);
	idTransaction_ = id;
	idClient_ = idclient;
	idMarchand_ = Idmarchand;
	date_ = date;
	dateS_ = tm.getDateString();
	sousTotal_ = st;

	for (auto it : products) {
		listeProduit_[it.first] = it.second;
	}

}

void Transaction::addarticle(Article& article, unsigned nombre)
{
	if (listeProduit_.find(article.getId()) == listeProduit_.end()) {
		listeProduit_[article.getId()] = nombre;
	}
	else
	{
		listeProduit_[article.getId()] = listeProduit_[article.getId()] + nombre;
	}
	sousTotal_ += article.getPrix() * nombre;
}

bool Transaction::delitArticle(Article& article, unsigned nombre)
{
	if (listeProduit_.find(article.getId()) == listeProduit_.end()) {
		return false;
	}
	else
	{
		if (listeProduit_[article.getId()]>nombre)
		{
			listeProduit_[article.getId()]-=nombre;
			sousTotal_ -= nombre * article.getPrix();
		}
		else
		{
			sousTotal_ -= listeProduit_[article.getId()] * article.getPrix();
			listeProduit_.erase(listeProduit_.find(article.getId()));	
		}
		return true;
	}
	
}

void Transaction::payer(Client a)
{
	this->idClient_ = a.getid();
}



unsigned Transaction::getIdC()
{
	return idClient_;
}

unsigned Transaction::getIdM()
{
	return idMarchand_;
}

unsigned Transaction::getIdT()
{
	return idTransaction_;
}

unsigned Transaction::getNombreProduit(unsigned idP)
{
	return listeProduit_.find(idP)->second;
}

double Transaction::getS_T()
{
	return sousTotal_;
}

//double Transaction::getTaxes()
//{
//	return taxes_;
//}

Date Transaction::getDate()
{
	return date_;
}

std::map<unsigned, unsigned>& Transaction::getMapProd()
{
	return this->listeProduit_;
}

std::string Transaction::getdate()
{
	return dateS_;
}
