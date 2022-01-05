#pragma once
#include<iostream>
#include<random>
#include<string>
#include<vector>
#include<algorithm>
#include"scacchiera.h"
#include"traduttore.h"

struct computer {
	computer();
	computer(char);

	class NoCorrectInfoConstructor{}; //classe per lanciare eccezioni
	static std::string returnValue(int);
	void removePiece(std::string);
	int getSize();
	std::string autoMove(scacchiera &);
private:
	//vettore contenente coordinate dei pezzi
	std::vector <std::string> coordinate{};
	
	
};

//HELPER FUNCTION
std::string randomPosition();
