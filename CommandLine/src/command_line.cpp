#include "command_line.hpp"
#include <tclap/CmdLine.h>

usage Command::initialize(int argc, char** argv) {
	
	TCLAP::CmdLine cmd("Command description message", ' ', "0.1");
	
	TCLAP::ValueArg<std::string> sequenceArg("s", "sequence", "Name of the .fasta containing the sequence", true, "default.fasta", "string");
	cmd.add(sequenceArg);
	
	TCLAP::ValueArg<std::string> matrixArg("m", "matrix", "Name of the .pmw containing the matrix", false, "default.pmw", "string");
	cmd.add(matrixArg);
	
	TCLAP::ValueArg<std::string> thresholdArg("t", "threshold", "Minimum value for a sequence to be taken into account", false, "0.0", "double");
	cmd.add(thresholdArg);
	
	TCLAP::ValueArg<std::string> lengthArg("l", "length", "Length of the searched motif", false, "3", "int");
	cmd.add(lengthArg);
	
	TCLAP::ValueArg<std::string> bedArg("b", "bedfile", "Name of the bed file that needs to be read", false, "default.bed", "string");
	cmd.add(bedArg);
	
	cmd.parse(argc, argv);

	setArgs[0] = matrixArg.isSet();
	setArgs[1] = thresholdArg.isSet();
	setArgs[2] = lengthArg.isSet();
	setArgs[3] = bedArg.isSet();
	
	parameters.insert(std::make_pair(0, matrixArg.getValue()));
	parameters.insert(std::make_pair(1, thresholdArg.getValue()));
	parameters.insert(std::make_pair(2, lengthArg.getValue()));
	parameters.insert(std::make_pair(3, bedArg.getValue())); 
	
	bool known_usages(setArgs[0] && setArgs[1] && !setArgs[2] && !setArgs[3]);
	if (known_usages) {
		return usage::FINDING_POSITIONS;
	}else if (!known_usages) {
		return usage::CREATING_MATRIX;
	}else {
		return usage::UNDEFINED_USAGE;
	}
	
}

void Command::inform_user() {
	
	
	std::cout << "Unknown combination of paramters" << std::endl;

}


