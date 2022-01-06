#include "scacchiera.h"


/*TODO: - aggiungere funzioni di check situazioni speciali
        - aggiungere distruttore*/


//scacchiera per debug funzione di check scacco
/*scacchiera::scacchiera() : board{
    {'T', 'C', 'A', 'D', 0x20, 'A', 'C', 'T'},
    { 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
    { 0x20, 0x20, 'A', 0x20, 0x20, 0x20, 0x20, 0x20},
    { 0x20, 0x20, 0x20, 'r', 0x20, 0x20, 0x20, 0x20},
    { 0x20, 0x20, 0x20, 'R', 0x20, 0x20, 0x20, 0x20},
    { 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20},
    { 'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p' },
    { 't', 'c', 'a', 'd', 0x20, 'a', 'c', 't' },
} {
}*/

scacchiera::scacchiera() : board{
    {'T', 'C', 'A', 'D', 'R', 'A', 'C', 'T'},
    { 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P' },
    { 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20 },
    { 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20 },
    { 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20 },
    { 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20 },
    { 'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p' },
    { 't', 'c', 'a', 'd', 'r', 'a', 'c', 't' },
} {
}

void scacchiera::movePedina(int fromLetter, int fromNumber, int toLetter, int toNumber) {
    board[toNumber][toLetter] = board[fromNumber][fromLetter];
    board[fromNumber][fromLetter] = 0x20;
}

void scacchiera::printScacchiera() {
    for (auto i = 0; i < 8; i++) {
        for (auto j = 0; j < 8; j++) {
            std::cout << board[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

char scacchiera::getPiece(int vert, int orizz) {
    return scacchiera::board[vert][orizz];
    
}

std::vector<int> scacchiera::findRe(char re) {
    std::vector<int> posizioneRe;
    for (auto i = 0; i < 8; i++) {
        for (auto j = 0; j < 8; j++) {
            if (board[i][j] == re) {
                posizioneRe.push_back((int)i);
                posizioneRe.push_back((int)j);
            }
        }
    }
    return posizioneRe;
}






