#ifndef BEDREADER_H
#define BEDREADER_H
#include <string> 
#include <vector>
using namespace std;


class bedreader
{
	private :
	string sequence;
	string monfichier;
	string nomCherche;
	vector<vector<string>> lignes;
	vector<string> element;
	
	
	
	public :
	bedreader(string filename);
	void Read();
	void setName(string nomEntre);
	vector<vector<string>> getlignes();
	
	
	
};
#endif
