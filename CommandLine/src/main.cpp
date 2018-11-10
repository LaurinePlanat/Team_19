#include "command_line.hpp"


int main( int argc, char** argv) {
	
	 // try {
	
	Command CommandLine;
	usage define(CommandLine.initialize(argc, argv));	
	
	switch(define) {
		 
	case(FINDING_POSITIONS) :
		// launch program to find the positions
		std::cout << "Finding Positions" << std::endl;
		break;
	
	case(CREATING_MATRIX) :
		// launch program to create the matrix
		std::cout << "Creating Matrix" << std::endl;
		break;
		
	case(UNDEFINED_USAGE) :
		CommandLine.inform_user();
		break;
		
	}
	
	
	
	//	} catch (ArgException &e)  // pas sur
	// { std::cerr << "error: " << e.error() << " for arg " << e.argId() << std::endl; }
	
}

