//An email address such as "John.Smith@example.com" is made up of a local part("John.Smith"),
//an "@" symbol, then a domain part("example.com").
//
//The domain name part of an email address may only consist of letters, digits, hyphensand dots.The local part, however, also allows a lot of different special characters.Here you can look at several examples of correctand incorrect email addresses.
//
//Given a valid email address, find its domain part.
//
//Example
//
//For address = "prettyandsimple@example.com", the output should be
//findEmailDomain(address) = "example.com";
//For address = "fully-qualified-domain@codesignal.com", the output should be
//findEmailDomain(address) = "codesignal.com".


#include <iostream>
#include <string>

std::string findEmailDomain(std::string address) {
	
	// Frist way:
	/*
	int Pos = address.find_last_of("@") + 1;
	int Len = address.length() - Pos;
	char buffer[20];
	std::size_t length = address.copy(buffer, Len, Pos);
	buffer[length] = '\0';
	std::cout << "buffer contains: " << buffer << '\n';
	return buffer;
	*/
	
	// the second way: more power
	int Pos = address.find_last_of("@") + 1;
	int Len = address.length() - Pos;
	std::string res = "";

	for (int i = Pos; i < address.length(); i++)
	{
		res += address[i];
	}
	std::cout << res;

	return res;
}


int main()
{
	std::string address = "better@teen@gmail.com";
	findEmailDomain(address);

	return 0;
}
