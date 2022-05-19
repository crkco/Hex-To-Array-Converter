#include <iostream>

int main(int argc, char* argv[])
{
	char argument = argv[1][1];
	char* hexcode = argv[2];

	if (argc != 3)
	{
		std::cout << "Two arguments required: hextoarray <arg> <hexcode>\n";
		std::cout << "\t\t-a\tInsert '0x' before every char and add '{' and '}' before and after array.\n";
		std::cout << "\t\t-b\tOnly add commas between chars." << std::endl;

		return 0x1;
	}

	bool extraChars = argument == 'a';
	bool addCommas = extraChars || argument == 'b';

	if (extraChars)
	{
		std::cout << "{";
	}

	for (int i = 0; hexcode[i] != 0x0 && hexcode[i + 1] != 0x0; i+=2)
	{
		if (i != 0 && addCommas)
		{
			std::cout << ",";
		}

		if (extraChars)
		{
			std::cout << " 0x";
		}

		std::cout << hexcode[i] << hexcode[i + 1];
	}

	if (extraChars)
	{
		std::cout << " }";
	}

	return 0;
}