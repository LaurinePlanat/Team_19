#ifndef BEDREADER_H
#define BEDREADER_H
#include <string> 
#include <vector>

/*!
  This is a class allowing to read a BED file and to access to each one of the elements it contains.
 */
 
class bedreader
{
	private :
	string sequence;
	string monfichier;
	string nomCherche;
	vector<vector<string>> lignes;
	vector<string> element;
	
	
	
	public :
	
	/*! Constructor 
		@param[in] the name of the file given by the user */
	bedreader(string filename);
	
	/*! Reads the file and stocks the elements corresponding to the sequence name given by the user in a vector<vector<string>> */
	void Read();
	
	/*! Sets the name of the sequence the user is looking for.
		@param[in] the name of the sequence the user is looking for */
	void setName(string nomEntre);
	
	/*! Get lignes.
		@param[out] lignes : vector<vector<string>> cointaining each line corresponding to the sequence we want parsed into a vector<string> */
	vector<vector<string>> getlignes();
	
};
#endif
