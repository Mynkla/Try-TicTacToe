#include <stdio.h>
#include <iostream>

#include <conio.h>
#include <string>
#include <random>
#include <time.h>

using namespace std;

void inputType_In(char typin[3][3], int x, int y) {
    if (typin[x][y] != 'x' && typin[x][y] != 'o') typin[x][y] = 'x';
    else printf("Already Have Symbol, Try Again");
}

bool cndtnWn(char boxId[3][3], char smbl) {
    if (boxId[0][0] == smbl && boxId[1][0] == smbl && boxId[2][0] == smbl) return true;
    else if (boxId[0][0] == smbl && boxId[1][1] == smbl && boxId[2][2] == smbl) return true;
    else if (boxId[0][0] == smbl && boxId[0][1] == smbl && boxId[0][2] == smbl) return true;
    else if (boxId[1][0] == smbl && boxId[1][1] == smbl && boxId[1][2] == smbl) return true;
    else if (boxId[2][0] == smbl && boxId[2][1] == smbl && boxId[2][2] == smbl) return true;
    else if (boxId[2][0] == smbl && boxId[1][1] == smbl && boxId[0][0] == smbl) return true;
    else return false;
}

int main() {
    char blnkspcs[3][3];

    bool Wn;

    int inputRow = NULL;
    char inputColoumn = NULL;

    do {
        cout << ' ' << "ABC" << endl;
        cout << '1' << ' ' << blnkspcs[0][0] << '|' << blnkspcs[0][1] << '|' << blnkspcs[0][2] << endl;
        cout << ' ' << "----" << endl;
        cout << '2' << ' ' << blnkspcs[1][0] << '|' << blnkspcs[1][1] << '|' << blnkspcs[1][2] << endl;
        cout << ' ' << "----" << endl;
        cout << '3' << ' ' << blnkspcs[2][0] << '|' << blnkspcs[2][1] << '|' << blnkspcs[2][2] << endl;

        printf("Select Row 1,2,3 : ");
        cin >> inputRow;
        printf("Select Colom A,B,C : ");
        cin >> inputColoumn;

        if (inputRow == 1 && inputColoumn == 'A') inputType_In(blnkspcs, 0, 0);
        else if (inputRow == 1 && inputColoumn == 'B') inputType_In(blnkspcs, 0, 1);
        else if (inputRow == 1 && inputColoumn == 'C') inputType_In(blnkspcs, 0, 2);
        else if (inputRow == 2 && inputColoumn == 'A') inputType_In(blnkspcs, 1, 0);
        else if (inputRow == 2 && inputColoumn == 'B') inputType_In(blnkspcs, 1, 1);
        else if (inputRow == 2 && inputColoumn == 'C') inputType_In(blnkspcs, 1, 2);
        else if (inputRow == 3 && inputColoumn == 'A') inputType_In(blnkspcs, 2, 0);
        else if (inputRow == 3 && inputColoumn == 'B') inputType_In(blnkspcs, 2, 1);
        else if (inputRow == 3 && inputColoumn == 'C') inputType_In(blnkspcs, 2, 2);

        if (inputRow != NULL && inputColoumn != NULL) {
            srand(time(NULL));
            auto inputRow_rndm = 0, inputColoumn_rndm = 0;
            while (blnkspcs[inputRow_rndm][inputColoumn_rndm] == 'x' || blnkspcs[inputRow_rndm][inputColoumn_rndm] == 'o') {
                inputRow_rndm = rand() % 3;
                inputColoumn_rndm = rand() % 3;
            }
            cout << "Row : " << inputRow_rndm << ", Coloumn : " << inputColoumn_rndm << endl;
            blnkspcs[inputRow_rndm][inputColoumn_rndm] = 'o';
        }

        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 2; j++)
                cout << "Draw : " << (blnkspcs[i][j] != '\0') << endl;

        Wn = cndtnWn(blnkspcs, 'x') || cndtnWn(blnkspcs, 'o');

    } while (!Wn);

    printf("\n");
    cndtnWn(blnkspcs, 'x') ? printf("You Win") : printf("Computer Win");

}