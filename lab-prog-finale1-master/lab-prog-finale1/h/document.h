//Autore: Giovanni Bellato

#pragma once
#include <iostream>
#include <fstream>
#include <istream>
#include <string>

struct document 
{
	static void add_line(std::string title, std::string arg);
	
	static void clear_doc(std::string title);
};
