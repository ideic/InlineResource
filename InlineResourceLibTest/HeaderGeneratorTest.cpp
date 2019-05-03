#include "pch.h"
#include "..\InlineResourceLib\HeaderGenerator.h"
TEST(HeaderGeneratorTest, GetHeaderGivesBackExpextedContent) {
	std::string expectedResult = 
		R"(
#pragma once;
#include <vector>;
class FileResource{
private:
    std::vector<uint8_t> _content {0x15, 0x20};
}
)";
	HeaderGenerator gen;
	std::vector<uint8_t> content{0x15, 0x20};
	auto header = gen.GetHeader(content);

	EXPECT_EQ(expectedResult, header);
}