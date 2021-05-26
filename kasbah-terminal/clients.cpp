#include "clients.h"
#include"utile.h"
Client::Client(std::string nom, unsigned numero, std::string adress, std::string email)
{
	Time tm;
	nom_ = nom;
	numero_ = numero;
	adress_ = adress;
	email_ = email;
	id = tm.getIdFromtime();
}

std::string Client::getnom()
{
	return nom_;
}

unsigned Client::getid()
{
	return id;
}

unsigned Client::getnumero()
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
