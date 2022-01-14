#include "document.h"

void document::add_line(std::string title, std::string arg) {
	std::fstream file;
	//file.open(title, std::ios::out);
	//file.close();
	file.open(title, std::ios::app);
	if (file.is_open()) {
		file << arg << std::endl;
	}
	file.close();
}
