#include<fstream>
#include"gestionHistorique.h"

gestionHistorique::gestionHistorique(std::string soursPath)
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
			std::string token[5];
			unsigned i = 0;
			while ((pos = ligne.find(delimiter)) != std::string::npos) {
				token[i++] = ligne.substr(0, pos);
				ligne.erase(0, pos + delimiter.length());
			}
			token[i++] = ligne;
			i = 0;

			unsigned a = std::stoull(token[0], &a, 10);
			unsigned b = std::stoull(token[1], &b, 2);
			historique his(a, bool(b), token[2]);
			hitoriques_.push_back(his);


		}
		this->sort();
	}
}
