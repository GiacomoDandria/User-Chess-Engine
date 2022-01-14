#include "replay.h"


    using namespace std;

    int main(int argCount, char* argVec[])
    {
        //Controllo numero argomenti da riga di comando
        if (argCount > 2)
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
        fileReader.open("C:/Users/Giaco/source/repos/lab-prog-finale7/lab-prog-finale1/out/build/x64-Debug/log.txt", ios::in);
        if (fileReader.is_open()) {
            string myText;
            while (getline(fileReader, myText)) { //read data from file object and put it into string.
                //cout << myText << endl;

                std::vector<int> input = traduttore::traduci(myText);
                board.movePedina(input.at(0), input.at(1), input.at(2), input.at(3));
            }
            fileReader.close(); //close the file object.
        }

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


}