#include "gestionTransactions.h"

GestionTransaction::GestionTransaction(std::string soursPath)
{
	soursPath_ = soursPath;
	std::ifstream sourse(soursPath);
	if (sourse) {


		while (!sourse.eof())
		{


			std::string ligne;
			std::getline(sourse, ligne);
			std::string delimiter = " ";
			if (ligne == "") { break; }
			size_t pos = 0;
			std::string token[6];
			std::string toke[2];
			unsigned i = 0;
			while ((pos = ligne.find(delimiter)) != std::string::npos && i<=5) {
				token[i++] = ligne.substr(0, pos);
				ligne.erase(0, pos + delimiter.length());
			}
			std::map<unsigned, unsigned> products;
			while ((pos = ligne.find(delimiter)) != std::string::npos) {
				toke[0] = ligne.substr(0, pos);
				ligne.erase(0, pos + delimiter.length());
				toke[1] = ligne.substr(0, pos);
				ligne.erase(0, pos + delimiter.length());
				unsigned a = std::stoull(toke[0], &a, 10);
				unsigned b = std::stoull(toke[1], &b, 10);
				products[a] = b;
			}

			token[i++] = ligne;
			i = 0;
			unsigned a = std::stoull(token[i++], &a, 10);
			unsigned b = std::stoull(token[i++], &b, 10);
			unsigned c = std::stoull(token[i++], &c, 10);
			unsigned d = std::stoull(token[i++], &d, 10);
			unsigned e = std::stoull(token[i++], &e, 10);
			unsigned f = std::stoull(token[i++], &f, 10);
			//unsigned id , unsigned idclient  , unsigned Idmarchand , Date date , std::map<unsigned,unsigned> products
			Date date{ d, e, f };
			Transaction tr(a,b,c, date,products);
			transactions_.push_back(tr);

		}
		this->sort();
	}

}
