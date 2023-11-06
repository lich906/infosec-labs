#include <argparse/argparse.hpp>
#include <set>
#include "FileInputStream.h"
#include "modular_math_lib.h"
#include "set_intersection.hpp"

using SetOfChars = std::set<uint8_t>;

SetOfChars ReadSetOfChars(FileInputStream& input);

std::string DetermineKey(
	FileInputStream& input,
	int keyLength,
	const SetOfChars& msgAlph,
	const SetOfChars& keyAlph);

int main(int argc, char** argv)
{
	argparse::ArgumentParser prog("key_finder", "1.0");

	prog.add_argument("-l", "--key-length")
		.scan<'i', int>()
		.required()
		.help("specify key length");
	prog.add_argument("input_file")
		.help("path to input file that will be encrypted");

	try
	{
		prog.parse_args(argc, argv);
	}
	catch (const std::exception& err)
	{
		std::cout << err.what() << std::endl;
		std::cout << prog;
		return 1;
	}

	int keyLength = prog.get<int>("-l");
	std::string inFilePath = prog.get<std::string>("input_file");

	std::cout << "Looking for key (length " << keyLength << ") for encrypted text " << inFilePath << " ..." << std::endl;

	FileInputStream inKeyAlphabetFile("key_alphabet.txt");
	auto keyAlphabet = ReadSetOfChars(inKeyAlphabetFile);
	FileInputStream inMsgAlphabetFile("msg_alphabet.txt");
	auto msgAlphabet = ReadSetOfChars(inMsgAlphabetFile);

	FileInputStream cipherInput(inFilePath);

	try
	{
		std::string key = DetermineKey(cipherInput, keyLength, msgAlphabet, keyAlphabet);
		std::cout << "Found key: " << key << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
		return 1;
	}

	return 0;
}

SetOfChars ReadSetOfChars(FileInputStream& input)
{
	std::set<uint8_t> res;

	while (!input.IsEOF())
	{
		res.insert(input.ReadByte());
	}

	return res;
}

std::string DetermineKey(
	FileInputStream& input,
	int keyLength,
	const SetOfChars& msgAlph,
	const SetOfChars& keyAlph)
{
	std::vector<SetOfChars> keyElements(keyLength, keyAlph);

	int k = 0;
	while (!input.IsEOF())
	{
		uint8_t encrByte = input.ReadByte();

		SetOfChars possibleKeyEls;

		for (auto& msgCh : msgAlph)
		{
			uint8_t keyEl = (uint8_t)modular_sub(encrByte, msgCh, 256);
			possibleKeyEls.insert(keyEl);
		}

		keyElements[k] = keyElements[k] * possibleKeyEls;

		k = ++k % keyLength;
	}

	std::string key;
	for (auto& keyEl : keyElements)
	{
		if (keyEl.size() != 1)
		{
			std::cout << "[";
			for (auto& el : keyEl)
			{
				std::cout << el << " ";
			}
			std::cout << "]" << std::endl;
			throw std::exception("Key element has no unambiguous value or any value at all.");
		}
		else
		{
			std::cout << *keyEl.begin() << " ";
			key.push_back(*keyEl.begin());
		}
	}
	std::cout << std::endl;

	return key;
}
