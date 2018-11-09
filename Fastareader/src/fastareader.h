#ifndef FASTAREADER_H
#define FASTAREADER_H

#include <sstream>
#include <string>
#include <fstream>
#include <iostream>

class Fastareader {

public:
	/*! Constructor
	 @param[in]: toSearch: sequence we want to extract, file: filename */
	Fastareader(std::string seq, std::string filename);
	/*! Read and returns a specific sequence, the one we want to study
			@param[out] : sequence we want to study*/
	std::string readSeq();
	/*! Read only the nucleotides we want
			@param[in]: size_t a (where we want to start), size_t b (where we want to end)
			@param[out]: std:string seq (the few nucleotides we want to study) */
	std::string readNucle(size_t a, size_t b);
	/*! Set the sequence to search
			@param[in]: std::string name */
	void setName(std::string name);
	/*! Set the sequence when it is found*/
	void setFound(std::string found);
	/*! Display the sequence we want*/
	void display() const;
	/*! Display the nucleotides we want to study*/
	void displayNucle() const;

private:
	std::ifstream file;
	std::string toSearch; //Sequence we want to search
	std::string nucle; //The nucleotides we want to read;
	std::string seqFound; //Sequence found


};

#endif
