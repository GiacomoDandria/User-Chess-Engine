#include "replay.h"

namespace NMSP1 {

    using namespace std;

    int main(int argCount, char* argVec[])
    {
        //Controllo numero argomenti da riga di comando
        if (argCount > 2)
        {
            std::cout << "Numero di argomenti troppo alto";
            return 1;
        }
        if (argCount == 0)
        {
            std::cout << "Inserire gli argomenti da riga di comando";
            return 1;
        }

        fstream fileReader;
        fileReader.open(argVec[0], std::fstream::in);
        string myText;
        scacchiera board;

        //lettore file che legge riga per riga
        while (getline(fileReader, myText))
        {
            std::vector<int> input = traduttore::traduci(myText);
            board.movePedina(input.at(0), input.at(1), input.at(2), input.at(3));

            //se viene inserito solo una stringa da riga di comando stampa a video
            if (argCount == 1)
            {
                board.printScacchieraVideo();
            }

            //se vengono inserite più stringhe da riga di comando stampa su file
            if (argCount == 2)
            {
                board.printScacchieraFile(argVec[1]);
            }
        }
        fileReader.close();
    }

}