#include "pch.h"
#include "..\InlineResourceLib\FileHandler.h"

TEST(FileHandlerTest, GetContentGivesBackContent) {
	FileHandler parser;
	auto result = parser.GetContent("TestFiles\\favicon.ico");
    EXPECT_EQ(result.size(), 1150);
}