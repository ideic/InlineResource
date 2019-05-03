#pragma once
#include <vector>
#include <string>
class FileHandler
{
public:
	FileHandler();
	~FileHandler();

	std::vector<uint8_t> GetContent(std::string filePath);

	void WriteContent(std::string filePath, std::string content);
};

