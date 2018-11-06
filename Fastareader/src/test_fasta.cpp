#include "fastareader.h"


int main (int argc, char** argv) {
	
	std::string the_sequence, file_name; //the_sequence = sequence asked to display, file_name = name of the file we should extract the sequence

	if (argc > 2) {
		for(int i(2); i < argc; ++i) {
			the_sequence +=std::string(argv[i]) + std::string(" "); //We add a space at the end to include the sequences that have several arguments like "SeqB no2"
		}

		the_sequence.erase(the_sequence.size()-1,1);  //We erase the last space in order to have the same header of the map.

	file_name = std::string(argv[1]);
	
	std::ifstream file(file_name);

	Fastareader reader(the_sequence, file_name); //We create a Fastareader which will read the file and extract the right sequence
	
	std::string seq(reader.readSeq());
	
	reader.display();

	} else { 
        
        std::cerr << "You didn't give enough arguments ! try ./ExtractFasta filename sequence." << std::endl;

		return 0; } //Considering the error where there are not enough arguments


	return 0;	
}

