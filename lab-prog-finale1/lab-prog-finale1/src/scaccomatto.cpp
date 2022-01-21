#include "scaccomatto.h"
// Bisogna chiamare questa funzione solo quando si ha uno scacco
bool scaccomatto::check(scacchiera& board){
    //Eseguo due controlli, uno per il re nero e uno per il bianco
    /* RE NERO */
    std::vector <int> reNero = board.findRe('R');
    //controllo se il re ha possibilità o è sotto scaccomatto
    int count = 8;   //numero massimo di mosse di un re
    int riga = reNero.at(0);
    int colonna = reNero.at(1);
    bool flag = false;
    while(count>0){  //inizio il ciclo
        //#1
        if(count == 8)
            if(rangeCheck(colonna-1,riga-1))
                if(friendlyCheckU(board ,colonna-1,riga-1))
                    if(scacco::checkTwo(board,'R',(-1),(-1)))
                        flag =true;
                    else
                        {flag =false; break;}
                    
        //#2
        if(count == 7)
            if(rangeCheck(colonna,riga-1))
                if(friendlyCheckU(board ,colonna,riga-1))
                    if((scacco::checkTwo(board,'R',0,-1)))
                        flag =true;
                    else
                        {flag =false; break;}
        //#3
        if(count == 6)
            if(rangeCheck(colonna+1,riga-1))
                if(friendlyCheckU(board ,colonna+1,riga-1))
                    if(scacco::checkTwo(board,'R',+1,-1))
                        flag =true;
                    else
                        {flag =false; break;} 
        //#4
        if(count == 5)
            if(rangeCheck(colonna +1 ,riga))
                if(friendlyCheckU(board ,colonna+1,riga))
                    if(scacco::checkTwo(board,'R',+1,0))
                        flag =true;
                    else
                        {flag =false; break;}            
        //#5
        if(count == 4)
            if(rangeCheck(colonna+1,riga+1))
                if(friendlyCheckU(board ,colonna+1,riga+1))
                    if(scacco::checkTwo(board,'R',+1,+1))
                        flag =true;
                    else
                        {flag =false; break;}
        //#6
        if(count == 3)
            if(rangeCheck(colonna,riga+1))
                if(friendlyCheckU(board ,colonna,riga+1))
                    if(scacco::checkTwo(board,'R',0,+1))
                        flag =true;
                    else
                        {flag =false; break;}
        //#7
        if(count == 2)
            if(rangeCheck(colonna-1,riga+1))
                if(friendlyCheckU(board ,colonna-1,riga+1))
                    if(scacco::checkTwo(board,'R',-1,+1))
                        flag =true;
                    else
                        {flag =false; break;}
        //#8
        if(count == 1)
            if(rangeCheck(colonna-1,riga))
                if(friendlyCheckU(board ,colonna-1,riga))
                    if(scacco::checkTwo(board,'R',-1,0))
                        flag =true;
                    else
                        {flag =false; break;}
        count--;     //decremento
    }


    /* RE BIANCO */
    std::vector <int> reBianco = board.findRe('r');
    //controllo se il re ha possibilità o è sotto scaccomatto
    count = 8;   //numero massimo di mosse di un re
    riga = reBianco.at(0);
    colonna = reBianco.at(1);
    while(count>0){  //inizio il ciclo
        //#1
        if(count == 8)
            if(rangeCheck(colonna-1,riga-1))
                if(friendlyCheckL(board ,colonna-1,riga-1))
                    if(scacco::checkTwo(board,'r',(-1),(-1)))
                        flag =true;
                    else
                        {flag =false; break;}
                    
        //#2
        if(count == 7)
            if(rangeCheck(colonna,riga-1))
                if(friendlyCheckL(board ,colonna,riga-1))
                    if(scacco::checkTwo(board,'r',0,-1))
                        flag =true;
                    else
                        {flag =false; break;}
        //#3
        if(count == 6)
            if(rangeCheck(colonna+1,riga-1))
                if(friendlyCheckL(board ,colonna+1,riga-1))
                    if(scacco::checkTwo(board,'r',+1,-1))
                        flag =true;
                    else
                        {flag =false; break;}  
        //#4
        if(count == 5)
            if(rangeCheck(colonna +1 ,riga))
                if(friendlyCheckL(board ,colonna+1,riga))
                    if(scacco::checkTwo(board,'r',+1,0))
                        flag =true;
                    else
                        {flag =false; break;}           
        //#5
        if(count == 4)
            if(rangeCheck(colonna+1,riga+1))
                if(friendlyCheckL(board ,colonna+1,riga+1))
                    if(scacco::checkTwo(board,'r',+1,+1))
                        flag =true;
                    else
                        {flag =false; break;} 
        //#6
        if(count == 3)
            if(rangeCheck(colonna,riga+1))
                if(friendlyCheckL(board ,colonna,riga+1))
                    if(scacco::checkTwo(board,'r',0,+1))
                        flag =true;
                    else
                        {flag =false; break;}
        //#7
        if(count == 2)
            if(rangeCheck(colonna-1,riga+1))
                if(friendlyCheckL(board ,colonna-1,riga+1))
                    if(scacco::checkTwo(board,'r',-1,+1))
                        flag =true;
                    else
                        {flag =false; break;}
        //#8
        if(count == 1)
            if(rangeCheck(colonna-1,riga))
                if(friendlyCheckL(board ,colonna-1,riga))
                    if(scacco::checkTwo(board,'r',-1,0))
                        flag =true;
                    else
                        {flag =false; break;}

        count--;     //decremento
    }

    return flag;
}


