#pragma once
#include <string>
#include"Article.h"


class Client {
public:
	Client() : id_(0) {};
	Client(std::string nom, std::string numero, std::string adress, std::string email);
	Client(unsigned id, std::string nom, std::string numero, std::string adress, std::string email);
	std::string getnom();
	unsigned getid();
	std::string getnumero();
	std::string getadress();
	std::string getemail();
	void setNum(unsigned num);
	void setMail(std::string mail);
	void setaddress(std::string adress);
private:
	std::string nom_;
	unsigned id_;
	std::string numero_;
	std::string adress_;
	std::string email_;
	double solde=0;

	
};