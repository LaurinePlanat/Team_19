#ifndef COMMAND_LINE_H
#define COMMAND_LINE_H
#include <array>
#include <map>
#include <string>
#include <iostream>

enum usage {
	
	FINDING_POSITIONS,
	CREATING_MATRIX,
	UNDEFINED_USAGE,
	
};

class Command {
	
public: 

	usage initialize(int argc, char** argv);
	void inform_user();

private:

	usage way;
	std::array<bool, 4> setArgs;
	std::map<size_t, std::string> parameters;
	
};


#endif

