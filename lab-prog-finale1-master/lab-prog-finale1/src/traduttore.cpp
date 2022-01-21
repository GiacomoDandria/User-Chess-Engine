//Autore: Giovanni Bellato

#include "traduttore.h"

//traduce soltanto le lettere ammesse come indici nella scacchiera
//in numeri, per farle diventare delle coordinate per muoversi
//nella scacchiera
int traduttore::traduttoreLetter(char letter) 
{
    int convertedFrom = 0;
    try 
    {
        if(letter == 'a' || letter == 'A')
        {
            convertedFrom = 0;
        }
        else if(letter == 'b' || letter == 'B')
        {
            convertedFrom = 1;
        }
        else if(letter == 'c' || letter == 'C')
        {
            convertedFrom = 2;
        }
        else if(letter == 'd' || letter == 'D')
        {
            convertedFrom = 3;
        }
        else if(letter == 'e' || letter == 'E')
        {
            convertedFrom = 4;
        }
        else if(letter == 'f' || letter == 'F')
        {
            convertedFrom = 5;
        }
        else if(letter == 'g' || letter == 'G')
        {
            convertedFrom = 6;
        }
        else if(letter == 'h' || letter == 'H')
        {
            convertedFrom = 7;
        }
    }
    catch(std::exception&) 
    {
        std::cout << "Exeption: sono stati inseriti dei valori di movimento non validi." << std::endl;
    }
    return convertedFrom;
}

//conversione del numero passato come input dall'utente in un numero comprensibile
//dal computer per muoversi all'interno della scacchiera
int traduttore::traduttoreNumber(int number) 
{
    return 8 - number;
}

/*la funzione traduci effettua tutti i controlli necessari per le stringhe di input, ovvero:
      - controlla che le lettere siano valide (non importa che siano maiuscole o minuscole)
      - controlla che i numeri appartengano al range 1-8
      - controlla che la stringa sia della giusta lunghezza -> len=5
una volta terminati i controlli viene restituito un vector contenente le coordinate (x, y)
direttamente interpretabili dal computer per eseguire un movimento, dove si ha che
      - input.at(0) -> lettera di partenza
      - input.at(1) -> numero di partenza
      - input.at(2) -> lettera di arrivo
      - input.at(3) -> numero di arrivo
*/

std::vector<int> traduttore::traduci(std::string inputMovement) 
{
    const std::string validLetters = "ABCDEFGHabcdefgh";
    const std::string validNumbers = "12345678";

    int fromLetter = -1;
    int fromNumber = -1;
    int toLetter = -1;
    int toNumber = -1;

    try 
    {
        if(inputMovement.length() > 5) 
        {
            std::cout << "Exeption: Input string too long: cannot contain valid moves." << std::endl;
            throw std::invalid_argument("");
        }
        if(inputMovement.length() < 5) 
        {
            std::cout << "Exeption: Input string too short: cannot contain moves." << std::endl;
            throw std::invalid_argument("");
        }
        if((validLetters.find(inputMovement[0]) == std::string::npos) || (validLetters.find(inputMovement[3]) == std::string::npos)) 
        {
            std::cout << "Exeption: Input letters are not valid positions in the board." << std::endl;
            throw std::invalid_argument("");
        }
        if(validNumbers.find(inputMovement[1]) == std::string::npos || validNumbers.find(inputMovement[4]) == std::string::npos) 
        {
            std::cout << "Exeption: Input numbers are not valid positions in the board." << std::endl;
            throw std::invalid_argument("");
        }
        
        fromLetter = traduttore::traduttoreLetter(inputMovement[0]);
        fromNumber = traduttore::traduttoreNumber(inputMovement[1] - '0');
        toLetter = traduttore::traduttoreLetter(inputMovement[3]);
        toNumber = traduttore::traduttoreNumber(inputMovement[4] - '0');
    }
    catch(std::invalid_argument e) 
    {
        std::vector<int> vector{ -1, -1, -1, -1 };
    }

    std::vector<int> vettore{ fromLetter, fromNumber, toLetter, toNumber };
    return vettore;
}

/*La funzione traduciReverse prende come input 4 int (contenuti in un vector)
e restituisce le coordinate in "stile utente"*/
std::string traduttore::traduttoreLetterRev(int n)
{
    std::string letter;
    if(n == 0)
    {
        letter = "A";
    }
    else if(n == 1)
    {
        letter = "B";
    }
    else if(n == 2)
    {
        letter = "C";
    }
    else if(n == 3)
    {
        letter = "D";
    }
    else if(n == 4)
    {
        letter = "E";
    }
    else if(n == 5)
    {
        letter = "F";
    }
    else if(n == 6)
    {
        letter = "G";
    }
    else if(n == 7)
    {
        letter = "H";
    }
    return letter;
}

std::string traduttore::traduttoreNumberRev(int n) 
{
    return std::to_string(8 - n);
}

std::string traduttore::traduciReverse(int fromLetter, int fromNumber, int toLetter, int toNumber) 
{
    std::string s1=traduttore::traduttoreLetterRev(fromLetter)+traduttoreNumberRev(fromNumber);
    std::string s2=traduttore::traduttoreLetterRev(toLetter) + traduttoreNumberRev(toNumber);
    
    return s1+" "+s2;
}
