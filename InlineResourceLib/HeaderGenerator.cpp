#include "stdafx.h"
#include "HeaderGenerator.h"
#include <sstream>

HeaderGenerator::HeaderGenerator()
{
}


HeaderGenerator::~HeaderGenerator()
{
}

std::string HeaderGenerator::GetHeader(std::vector<uint8_t> binaryContent)
{
	std::string header = R"(
#pragma once;
#include <vector>;
class FileResource{
private:
    std::vector<uint8_t> _content {%BODY%};
}
)";
	std::stringstream ss;
	for (auto & item : binaryContent) {
		ss << "0x"<<std::hex << static_cast<int>(item) << ", ";
	}
	std::string body = "%BODY%";
	std::string values = ss.str().substr(0, ss.str().size() - 2);
	header.replace(header.find(body, body.size()), body.size(), values);
	return header;
}
