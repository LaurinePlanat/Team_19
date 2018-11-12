#include "BEDreader.h"

bedreader::bedreader(std::string filename)
: monfichier(filename)
{}

void bedreader::setName(std::string nomEntre)
{
	nomCherche = nomEntre;
}

void bedreader::Read()
{
	std::string line;
	std::ifstream myfile(monfichier);

	if(not(myfile.is_open()))
	{
		std::cout<<"Votre fichier n'a pas pu être lu."<<std::endl;
	}
	else
	{
		try {
		while(!myfile.eof() )
		{

				myfile.exceptions(myfile.failbit | myfile.badbit); //Check if there is a problem concerning the reading of the file
				getline(myfile,line);
				fichier_entier.push_back(line);
					}
		} catch (std::ifstream::failure &e)
			{
				if(!myfile.eof())
				{
					throw (std::runtime_error(std::string("Error ") + e.what())); //give the nature of the error that occurred
					myfile.close();
				}
			}
		}
	myfile.close();
}

std::vector<std::vector<std::string>>  bedreader::getlignes()
{
	return lignes;
}

void bedreader::FindAndParse()
{
	std::string delimiter = "\t";
	std::size_t pos = 0;
	std::string token;
	for(size_t i(0);i<fichier_entier.size();++i)
	{
		pos = fichier_entier[i].find(delimiter);
		token = fichier_entier[i].substr(0, pos);
		if (token==nomCherche)
		{
			do {
				pos = fichier_entier[i].find(delimiter);
				token = fichier_entier[i].substr(0, pos);
				element.push_back(token);
				fichier_entier[i].erase(0, pos + delimiter.length());
				} while ((pos = fichier_entier[i].find(delimiter))!= std::string::npos);
				element.push_back(fichier_entier[i]);
				lignes.push_back(element);
				element.clear();
		}
	if(lignes.size()==0)
		{
			std::cout << "Aucune séquence de ce nom n'a été trouvée" << std::endl;
		}
}
