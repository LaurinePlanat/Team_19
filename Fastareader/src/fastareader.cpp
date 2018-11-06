#include "fastareader.h"

Fastareader::Fastareader(std::string seq, std::string filename) :
	file(filename)
	{
	 setName(seq);
		}

void Fastareader::setName(std::string name) {
	toSearch = std::string(">") + name;
}

void Fastareader::setFound(std::string found) {
	seqFound = found;
}
	

std::string Fastareader::readSeq() {

std::string line, seq(""); //line = line of the file, we'll use it with a getline; seq = sequence we want to return

	if (file.is_open()) {
		while (!file.eof()) {
			try {
				file.exceptions(file.failbit | file.badbit); //Check if there is a problem concerning the reading of the file
				std::getline(file, line); //Reading the file line by line
				if(line == toSearch) {
					do {
					  
						getline(file, line); //we only read the few lines that are composing the sequence
					  if(line[0] != '>') {	
						seq += line;
					  }
					} while ((line[0] != '>') && (!file.eof()));
				}
			} catch (std::ifstream::failure &e) {
				if(!file.eof()) {
					throw (std::runtime_error(std::string("Error ") + e.what())); //give the nature of the error that occurred
					file.close();
				}
			}
		}
	} else {
		std::cerr << "The file has not been found, don't forget to give the program the right path !" << std::endl;
	}
	setFound(seq);
	file.close();
	return seq;
}

std::string Fastareader::readNucle(size_t a, size_t b) {
	try {
		nucle = toSearch.substr(a,b);
		return nucle;
	} catch (std::out_of_range &e) {
		throw(std::runtime_error(std::string("Error ") + e.what()));
	}
}

void Fastareader::display() const {
	if(!seqFound.empty())
		std::cout << seqFound << std::endl;
}
