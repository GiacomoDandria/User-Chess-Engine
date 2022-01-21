//AUTORE: MARCO SQUARCINA

#include "scaccomatto.h"

/*La seguente funzione controlla se nella scacchiera e' presente uno scaccomatto. Viene chiamata dal main quando si ha uno scacco. Si 
  controlla se in ogni posizione dove il re in questione potrebbe muoversi (anche mangiando eventuali pedine) sarebbe in scacco. Questo
  e' possibile grazie alla funzione scacco::checkTwo 
  
  !I COMMENTI DEL CODICE SONO PRESENTI SOLO NELLA PRIMA PARTE DEL CODICE, POICHE' POI SI RIPETE PER IL RE BIANCO! */

bool scaccomatto::check(scacchiera& board){
    //Eseguo due controlli, uno per il re nero e uno per il bianco
    /* RE NERO */
    std::vector <int> reNero = board.findRe('R');   //Coordinate re nero
                                                    //controllo se il re ha possibilita' o e' sotto scaccomatto
    int count = 8;                                  //numero massimo di mosse di un re
    int riga = reNero.at(0);                        //posizione riga re
    int colonna = reNero.at(1);                     //posizione colonna re
    bool flag = false;                              //false = NoScaccoMatto | true = SiScaccoMatto
    
    /*Questo ciclo controlla in tutte le posizioni in cui il re puo' muoversi verificando se e' in scacco
      anche in esse. */
    while(count>0){  //inizio il ciclo
        //Controllo #1
        if(count == 8)          
            if(rangeCheck(colonna-1,riga-1))                        //Controllo che il range delle coordinate di controllo sia rispettato
                if(friendlyCheckU(board ,colonna-1,riga-1))         //Controllo presenza di pedine dello stesso colore
                    if(scacco::checkTwo(board,'R',(-1),(-1)))       //Controllo scacco nelle coordinate date
                        flag =true;   //E' scacco
                    else
                        {flag =false; break;}   //Non e' scacco puo' muovermi in quelle coordinate
                    
        //Controllo #2
        if(count == 7)
            if(rangeCheck(colonna,riga-1))
                if(friendlyCheckU(board ,colonna,riga-1))
                    if((scacco::checkTwo(board,'R',0,-1)))
                        flag =true;
                    else
                        {flag =false; break;}
        //Controllo #3
        if(count == 6)
            if(rangeCheck(colonna+1,riga-1))
                if(friendlyCheckU(board ,colonna+1,riga-1))
                    if(scacco::checkTwo(board,'R',+1,-1))
                        flag =true;
                    else
                        {flag =false; break;} 
        //Controllo #4
        if(count == 5)
            if(rangeCheck(colonna +1 ,riga))
                if(friendlyCheckU(board ,colonna+1,riga))
                    if(scacco::checkTwo(board,'R',+1,0))
                        flag =true;
                    else
                        {flag =false; break;}            
        //Controllo #5
        if(count == 4)
            if(rangeCheck(colonna+1,riga+1))
                if(friendlyCheckU(board ,colonna+1,riga+1))
                    if(scacco::checkTwo(board,'R',+1,+1))
                        flag =true;
                    else
                        {flag =false; break;}
        //Controllo #6
        if(count == 3)
            if(rangeCheck(colonna,riga+1))
                if(friendlyCheckU(board ,colonna,riga+1))
                    if(scacco::checkTwo(board,'R',0,+1))
                        flag =true;
                    else
                        {flag =false; break;}
        //Controllo #7
        if(count == 2)
            if(rangeCheck(colonna-1,riga+1))
                if(friendlyCheckU(board ,colonna-1,riga+1))
                    if(scacco::checkTwo(board,'R',-1,+1))
                        flag =true;
                    else
                        {flag =false; break;}
        //Controllo #8
        if(count == 1)
            if(rangeCheck(colonna-1,riga))
                if(friendlyCheckU(board ,colonna-1,riga))
                    if(scacco::checkTwo(board,'R',-1,0))
                        flag =true;
                    else
                        {flag =false; break;}
        
        count--;     //decremento per il cilco
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

    return flag;   //Se il flag alla fine del ciclo e' false non e' scacco matto, in caso contrario lo e'
}


