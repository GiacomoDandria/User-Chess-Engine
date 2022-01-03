#include <iostream>
#include<vector>
#include "scacchiera.h"
#include "pedone.h"
#include "alfiere.h"
#include "regina.h"
#include "re.h"
#include "cavallo.h"
#include "torre.h"
#include"middlePieces.h"
#include"computer.h"



using namespace std;

int main() {
    
    scacchiera board;

    //bool flag = true;
    //int counter = 0;
    //int MAX_MOVES = 40;
    //while (flag) {
    //    string mossa;
    //    cout << "Inserire una mossa: ";
    //    cin >> mossa;

    //    vector<int> input = traduttore::traduci(mossa);
    //    int fromLetter = input.at(0);
    //    int fromNumber = input.at(1);
    //    char boardPiece = board.getPiece(fromLetter, fromNumber);

    //    cout << "Il pezzo che si vuole muovere è: " << boardPiece << endl;

    //    switch (boardPiece) {
    //        /*check pezzi maiuscoli (pezzi neri)*/
    //        case 'T':
    //            torre::moveTorreCheck(mossa);
    //            break;
    //        case 'C':
    //            break;
    //        case 'A':
    //            break;
    //        case 'D':
    //            break;
    //        case 'R':
    //            break;
    //        case 'P':
    //            break;

    //        /*check pezzi minuscoli (pezzi bianchi)*/
    //        case 't':
    //            break;
    //        case 'c':
    //            break;
    //        case 'a':
    //            break;
    //        case 'd':
    //            break;
    //        case 'r':
    //            break;
    //        case 'p':
    //            break;


    //    default:
    //        string input;
    //        cout << "Insert a valid move:  ";
    //        cin >> input;
    //    }

    //    counter++;
    //    if (counter == MAX_MOVES)
    //        flag = false;
    //}

    //cout << "Fine partita. Termino programma!" << endl;
    //return 0;
    
    

    board.printScacchiera();


    computer::autoMove();

    //cout << "" << endl;

    //entrambe 

    //traduzione input utente in input array 2d per effettuare il movimento nella scacchiera
    string inputMovement = "a1 b2";
    vector<int> input = traduttore::traduci(inputMovement);

    cout << "Check regina: " << regina::moveReginaCheck(inputMovement) << endl;
    cout << endl;
    cout << "Check torre: " << torre::moveTorreCheck(inputMovement) << endl;
    cout << endl;
    cout << input.at(0) << input.at(1) << input.at(2) << input.at(3) << endl;
    cout << endl;
    cout << "Pedine vuote: " << middlePieces::check(board, input.at(0), input.at(1), input.at(2), input.at(3)) << endl;

    //cout << "input movement: " << inputmovement << endl;



    //effettuo check precondizioni e, eventualmente, muovo la pedina
    /*if (pedone::movePedoneCapCheck(inputmovement) == true) {
        cout << pedone::movePedoneCapCheck(inputmovement) << endl;
        board.movePedina(input.at(0), input.at(1), input.at(2), input.at(3));
    }*/

    board.printScacchiera();
}
