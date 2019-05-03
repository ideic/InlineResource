#include "pch.h"
#include <iostream>
#include <vector>
#include "../InlineResourceLib/FileHandler.h"
#include "../InlineResourceLib/HeaderGenerator.h"

class InputParser {
public:
	InputParser(int &argc, char **argv) {
		for (int i = 1; i < argc; ++i)
			this->tokens.push_back(std::string(argv[i]));
	}
	const std::string& getCmdOption(const std::string &option) const {
		std::vector<std::string>::const_iterator itr;
		itr = std::find(this->tokens.begin(), this->tokens.end(), option);
		if (itr != this->tokens.end() && ++itr != this->tokens.end()) {
			return *itr;
		}
		static const std::string empty_string("");
		return empty_string;
	}
	bool cmdOptionExists(const std::string &option) const {
		return std::find(this->tokens.begin(), this->tokens.end(), option)
			!= this->tokens.end();
	}
private:
	std::vector <std::string> tokens;
};

int main(int argc, char* argv[])
{
	for (int i = 0; i < argc; i++)
		std::cout << "Param" << i << ":" << argv[i] << std::endl;

	InputParser parser(argc, argv);

	// Validate the parameters
	if (argc != 5) {
		printf("usage: -in inputFileLocation -out outputfile\n");
		return 1;
	}

	auto inputFile = parser.getCmdOption("-in");
	auto outputFile = parser.getCmdOption("-out");

	FileHandler fh;
	auto content = fh.GetContent(inputFile);
	HeaderGenerator gen;
	auto header = gen.GetHeader(content);
	fh.WriteContent(outputFile, header);

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
