#include<iostream>
#include<string>
//using namespace std;

int main()
{
	std::string name;
	std::cout << "Enter your name: ";
	std::getline(std::cin, name);
	std::cout << "Thank you, '" << name << "'." << std::endl;
}
