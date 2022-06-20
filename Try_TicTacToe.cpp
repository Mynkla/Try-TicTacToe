#include <stdio.h>
#include <iostream>

#include <conio.h>
#include <string>
#include <random>

using namespace std;

void inputType_In(char typin[3][3], int x, int y) {
    typin[x][y] = 'x';
}

bool cndtnWn(char boxId[3][3]) {
    if (boxId[0][0] == 'x' && boxId[1][0] == 'x' && boxId[2][0] == 'x') return true;
    else if (boxId[0][0] == 'x' && boxId[1][1] == 'x' &&boxId[2][2] == 'x') return true;
    else if (boxId[0][0] == 'x' && boxId[0][1] == 'x' && boxId[0][2] == 'x') return true;
    else if (boxId[1][0] == 'x' && boxId[1][1] == 'x' && boxId[1][2] == 'x') return true;
    else if (boxId[2][0] == 'x' && boxId[2][1] == 'x' && boxId[2][2] == 'x') return true;
    else if (boxId[2][0] == 'x' && boxId[1][1] == 'x' && boxId[0][0] == 'x') return true;
    else return false;
}

int main() {
    char blnkspcs[3][3];
    bool plyIn, wIn;

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

        if (inputRow != NULL && inputColoumn != NULL) printf("Computer chance \n");

        if (cndtnWn(blnkspcs) == true) printf("You Win \n");

    } while (true);
}