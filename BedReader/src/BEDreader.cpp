#include "BEDreader.h" 
#include <sstream> 
#include <fstream> 
#include <iostream>
#include <vector>
using namespace std;

bedreader::bedreader(string filename)
: monfichier(filename)
 
{}

void bedreader::setName(string nomEntre)
{
	nomCherche = nomEntre;
}

void bedreader::Read()
{
	string line;
	ifstream myfile(monfichier);
	
	if(not(myfile.is_open()))
	{ 
		cout<<"Votre fichier n'a pas pu être lu."<<endl;
	}
	else
	{
		while(!myfile.eof() )
		{
			getline(myfile,line);
			string nom(nomCherche);
			string delimiter = "	";
			size_t pos = 0;
			string token;
				
				pos = line.find(delimiter);
				token = line.substr(0, pos);
				
				if (token==nomCherche)
				{
					do {
						pos = line.find(delimiter);
						token = line.substr(0, pos);
						element.push_back(token);
						line.erase(0, pos + delimiter.length());
						
						
					} while ((pos = line.find(delimiter))!= std::string::npos);
					element.push_back(line);
					lignes.push_back(element);
					element.clear();
				} 
		}
		if(lignes.size()==0)
			{
				std::cout << "Aucune séquence de ce nom n'a été trouvée" << std::endl;
			}
	}
	myfile.close();
}	

vector<vector<string>>  bedreader::getlignes()
{
	return lignes;
}
