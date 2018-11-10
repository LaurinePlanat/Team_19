
#include <string> 
#include <sstream> 
#include <fstream> 
#include "BEDreader.h" 
#include <iostream>

int main(int argc, char** argv)
{
	bedreader myReader(argv[1]);
	vector<vector<string>> ligne;
	string concatenefichier("");
	if (argc<3)
	{
		cout<<"Nombre d'arguments incorrect. Veuillez entrer un nom de fichier et un nom de séquence"<<endl;
	}
	else
	{
		string fichier(argv[2]);
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
		ligne=myReader.getlignes();
		for(size_t i(0);i<ligne.size();++i)
		{
			for(size_t k(0);k<ligne[i].size();++k)	
			{
				cout<<ligne[i][k]<<endl;
			}
		}
	}
return 0;
	
}
