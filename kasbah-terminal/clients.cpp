#include "clients.h"
#include"utile.h"


Client::Client(std::string nom,std::string numero, std::string adress, std::string email)
{
	Time tm;
	nom_ = nom;
	numero_ = numero;
	adress_ = adress;
	email_ = email;
	id_ = tm.getIdFromtime();
}
Client::Client(unsigned id, std::string nom, std::string numero, std::string adress, std::string email)
{
	nom_ = nom;
	numero_ = numero;
	adress_ = adress;
	email_ = email;
	id_ = id;
}
;

std::string Client::getnom()
{
	return nom_;
}

unsigned Client::getid()
{
	return id_;
}

std::string Client::getnumero()
{
	return numero_;
}

std::string Client::getadress()
{
	return adress_;
}

std::string Client::getemail()
{
	return email_;
}

void Client::setNum(unsigned num)
{
	numero_ = num;
}

void Client::setMail(std::string mail)
{
	this->email_ = mail;
}

void Client::setaddress(std::string adress)
{
	adress_ = adress;
}
