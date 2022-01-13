#pragma once
#include<iostream>
#include<exception>
#include <string>
#include<vector>
#include"cavallo.h"
#include"re.h"
#include"regina.h"
#include"alfiere.h"
#include"torre.h"
#include"traduttore.h"
#include <windows.h>
#include "document.h" 
//PER MAC invece di windows.h
//#include<unistd.h>
#include<fstream>    




class scacchiera {
    char board[8][8];

public:
    scacchiera();

    bool movePedina(int fromLetter, int fromNumber, int toLetter, int toNumber);

    bool checkWin(char);

    bool pedoneCheck(std::string position, char frompiece, char topiece);

    void promozioneCheck();

    void printScacchiera();

    char getPiece(int orizz, int vert);

    std::vector<int> findRe(char re);

    void printScacchieraVideo();

    void printScacchieraFile(std::string outputFile);
};


