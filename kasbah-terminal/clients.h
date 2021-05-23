#include <string>
#include<map>
#include"transaction.h"
#include"Article.h"


class Client {
public:
	Client(std::string nom, unsigned numero, std::string adress, std::string email);
	std::string getnom();
	unsigned getid();
	unsigned getnumero();
	std::string getadress();
	std::string getemail();
	void setNum(unsigned num);
	void setMail(std::string mail);
	void setaddress(std::string adress);
private:
	std::string nom;
	unsigned id;
	unsigned numero;
	std::string adress;
	std::string email;
	std::map<unsigned, Transaction*> historique;
private:
	
};