//AUTORE: MARCO SQUARCINA

#pragma once
#include<iostream>
#include<random>
#include<string>
#include<vector>
#include<sstream>
#include<algorithm>
#include"scacchiera.h"
#include"traduttore.h"
#include"middlePieces.h"
#include"randomMoves.h"

struct computer {
	//COSTRUTTORI
	computer();
	computer(char);
	
	//MEMBER FUNCTION
	class NoCorrectInfoConstructor{};       //Per lanciare eccezioni 	
	void removePiece(std::string);		//Rimuove la pedina mangiata
	int getSize();				//Restituisce la dimensione del vector
	std::string autoMove(scacchiera &);	//Esegue la mossa random
	//DA RIMUOVERE
	//static std::string returnValue(int);
private:
	//vettore contenente coordinate dei pezzi
	std::vector <std::string> coordinate{};
	
	
};

//Prima funzione random (Non usata nella versione finale del progetto).
std::string randomPosition(std::string s);


