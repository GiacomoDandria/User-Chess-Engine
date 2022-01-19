#include "document.h"

//aggiunge una stringa (arg) passata come argomento della funzione al file passato
//anch'esso come argomento (title)
void document::add_line(std::string title, std::string arg) {
	std::fstream file;
	file.open(title, std::ios::app);
	if (file.is_open()) {
		file << arg << std::endl;
	}
	file.close();
	
void document::clear_doc(std::string title) {
	std::fstream file;
	file.open(title, std::ios::out);
	if(file.is_open()) {
		file << "";
	}
	file.close();
}
