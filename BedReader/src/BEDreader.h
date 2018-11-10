#ifndef BEDREADER_H
#define BEDREADER_H
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include <iostream>
#include <vector>

/*!
  This is a class allowing to read a BED file and to access to each one of the elements it contains.
 */

class bedreader
{
	private :
	std::string sequence;
	std::string monfichier;
	std::string nomCherche;
	std::vector<std::vector<std::string>> lignes;
	std::vector<std::string> element;



	public :

	/*! Constructor
		@param[in] the name of the file given by the user */
	bedreader(std::string filename);

	/*! Reads the file and stocks the elements corresponding to the sequence name given by the user in a vector<vector<string>> */
	void Read();

	/*! Sets the name of the sequence the user is looking for.
		@param[in] the name of the sequence the user is looking for */
	void setName(std::string nomEntre);

	/*! Get lignes.
		@param[out] lignes : vector<vector<string>> cointaining each line corresponding to the sequence we want parsed into a vector<string> */
	std::vector<std::vector<std::string>> getlignes();

};
#endif
