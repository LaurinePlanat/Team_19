
#include <string>
#include <sstream>
#include <fstream>
#include "BEDreader.h"
#include <iostream>

int main(int argc, char** argv)
{
	bedreader myReader(argv[1]);
	std::vector<std::vector<std::string>> ligne;
	std::string concatenefichier("");
	if (argc<3)
	{
		std::cout<<"Nombre d'arguments incorrect. Veuillez entrer un nom de fichier et un nom de séquence"<<std::endl;
	}
	else
	{
		std::string fichier(argv[2]);
		concatenefichier = fichier;
		if (argc>3)
		{
			char espace(' ');
			for (int i=3;i<argc;++i)
			{
				concatenefichier=concatenefichier+espace+argv[i];
			}
		}

		myReader.setName(concatenefichier);
		myReader.Read();
		myReader.FindAndParse();
		ligne=myReader.getlignes();
		for(std::size_t i(0);i<ligne.size();++i)
		{
			for(std::size_t k(0);k<ligne[i].size();++k)
			{
				std::cout<<ligne[i][k]<<std::endl;
			}
		}
	}
return 0;

}
