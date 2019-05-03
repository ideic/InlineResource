#include "stdafx.h"
#include "FileHandler.h"
#include <fstream>
#include <filesystem>

namespace fs = std::experimental::filesystem;

FileHandler::FileHandler()
{
}


FileHandler::~FileHandler()
{
}

std::vector<uint8_t> FileHandler::GetContent(std::string filePath)
{
	fs::path path = fs::current_path() / filePath;

	auto fileSize = 0; 
	try {
		fileSize = fs::file_size(path);
	}
	catch (fs::filesystem_error& e) {
		throw;
	}

	std::ifstream inputFile;
	inputFile.open(path, std::ifstream::binary | std::ifstream::in);
	if (inputFile.bad()) {
		throw std::runtime_error("open file error");
	}

	
	std::vector<uint8_t> result(fileSize);
	inputFile.read(reinterpret_cast<char*>( result.data()), fileSize);
	inputFile.close();
	return result;
}

void FileHandler::WriteContent(std::string filePath, std::string content)
{
	fs::path path = /*fs::current_path() /*/ filePath;

	std::ofstream outputFile;
	outputFile.open(path, std::ofstream::out);
	if (outputFile.bad()) {
		throw std::runtime_error("open file error");
	}

	outputFile << content;
	outputFile.close();
}
