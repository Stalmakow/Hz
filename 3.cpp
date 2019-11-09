#include <iostream>
#include <fstream>

int main () {

    std::string str;
	std::ifstream file ("/dev/ttyUSB0");
	
		 if(file.is_open())
	 	{
		 std::cout << "open" << std::endl;
	 	}
	 	else
	 	{
	 	 std::cout << "eror" << std::endl;
		 }
		 while(true){
		 			 for(file >> str; !file.eof(); file >> str){
  					 											std::cout << str << std::endl;
																}
					}
}