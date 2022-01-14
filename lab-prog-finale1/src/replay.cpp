#include "replay.h"


using namespace std;

int main(int argCount, char* argVec[])
{
    //Controllo numero argomenti da riga di comando
    if (argCount > 3)
    {
        cout << "Numero di argomenti troppo alto";
        return 1;
    }
    if (argCount == 0)
    {
        cout << "Inserire gli argomenti da riga di comando";
        return 1;
    }

    scacchiera board;

    fstream fileReader;
//---------------DA CAMBIARE IN argVec[0] il path del file!!!!!!!!!!!!!!!!!!!!!!!!!!!
    fileReader.open(argVec[1], ios::in);
    if (fileReader.is_open()) {
        string myText;
        while (getline(fileReader, myText)) { //read data from file object and put it into string.
            //cout << (string)myText << endl;

            std::vector<int> input = traduttore::traduci(myText);
            board.movePedina(input.at(0), input.at(1), input.at(2), input.at(3));
            if (argCount == 2) {
             board.printScacchieraVideo();
         }
        if (argCount == 3) {
         board.printScacchieraFile(argVec[2]);
     }
    }
        fileReader.close();
    }       	 
}




