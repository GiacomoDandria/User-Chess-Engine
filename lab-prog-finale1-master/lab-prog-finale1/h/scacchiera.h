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
#include "document.h"
//PER LINUX invece di windows.h togliere il commento dalla seguente riga
//#include <windows.h>
#include<unistd.h>
#include<fstream>    




class scacchiera {
    char board[8][8];
    bool t1 = false; //variabile torre bianca a sinistra per arrocco
    bool t2 = false; //variabile torre bianca a destra per arrocco
    bool r = false;  //variabile re bianco per arrocco
    bool T1 = false; //variabile torre nera a sinistra per arrocco
    bool T2 = false; //variabile torre nera a destra per arrocco
    bool R = false;  //variabile re nero per arrocco
    int cont = 0;      //conta quando i pedoni non vengono mossi

public:
    scacchiera();

    bool movePedina(int fromLetter, int fromNumber, int toLetter, int toNumber);

    bool checkWin(char);

    bool pedoneCheck(std::string position, char frompiece, char topiece);

    bool arroccoCheck(int fromLetter, int fromNumber, int toLetter, int toNumber);
    
    bool pattaCheck();

    void enPassantFlagPSet(bool flag);

    bool enPassantFlagPGet();

    void enPassantFlagpSet(bool flag);

    bool enPassantFlagpGet();

    void promozioneCheck();

    void printScacchiera();

    char getPiece(int orizz, int vert);

    std::vector<int> findRe(char re);

    void printScacchieraVideo();

    void printScacchieraFile(std::string outputFile);
};


