#pragma once
#include<iostream>
#include<exception>
#include"cavallo.h"
#include"re.h"
#include"regina.h"
#include"alfiere.h"
#include"torre.h"
#include"traduttore.h"


class scacchiera {
    char board[8][8] = {{'T', 'C', 'A', 'D', 'R', 'A', 'C', 'T'},
    { 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P' },
    { 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20 },
    { 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20 },
    { 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20 },
    { 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20 },
    { 'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p' },
    { 't', 'c', 'a', 'd', 'r', 'a', 'c', 't' } };

public:
    scacchiera();

    bool movePedina(int fromLetter, int fromNumber, int toLetter, int toNumber);

    void printScacchiera();

    char getPiece(int orizz, int vert);
};


