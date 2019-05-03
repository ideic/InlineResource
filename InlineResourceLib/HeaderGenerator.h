#pragma once
#include <vector>
#include <string>

class HeaderGenerator
{
public:
	HeaderGenerator();
	~HeaderGenerator();

	std::string GetHeader(std::vector<uint8_t> binaryContent);
};

