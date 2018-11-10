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
		while(!myfile.eof() )
		{
			try {
				myfile.exceptions(myfile.failbit | myfile.badbit); //Check if there is a problem concerning the reading of the file

				getline(myfile,line);
				std::string delimiter = "	";
				std::size_t pos = 0;
				std::string token;

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
			} catch (std::ifstream::failure &e) {
				if(!myfile.eof()) {
					throw (std::runtime_error(std::string("Error ") + e.what())); //give the nature of the error that occurred
					myfile.close();
				}
			}
		}
		if(lignes.size()==0)
			{
				std::cout << "Aucune séquence de ce nom n'a été trouvée" << std::endl;
			}
	}
	myfile.close();
}

std::vector<std::vector<std::string>>  bedreader::getlignes()
{
	return lignes;
}
