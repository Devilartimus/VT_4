/*
На промежутке от -128 до 127. 
Подсчитать количество таких пар чисел X и Y, что 50 < (Х - У) <= 80. Ответ вывести на экран. 
*/

#include <iostream>
using namespace std;
int main()
{
    short X = -128,
        Y = -128,
        C = 0,
        RX = 0, RY = 0;

    bool F = 0;

    __asm
    {
        MOV CX, X;
    M1:
        CMP CX, 127
            JG M2; // больше

        MOV BX, Y;
    M3:
        CMP BX, 127
            JG M4;

        MOV AX, CX; // AX = X

        SUB AX, BX; // AX = AX - BX = X - Y

        CMP AX, 50
            JLE M7;

        CMP AX, 80
            JG M5;

        INC C;
        //---Вторая часть задания---
        CMP C, 200
            JNE M6; //не равно

        MOV RX, CX;
        MOV RY, BX;
        INC F;
    M7:
        INC CX;
        JMP M1;
    M6:
    M5:
        INC CX;
        JMP M1;
    M2:
        INC BX;
        JMP M3;
    M4:
    }
    cout << "Number of pairs: " << C;
    if (F)
        cout << "\n200 X: " << RX << "\n200 Y: " << RY << endl;
    else
        cout << "\nNumber of pirs less than 200";
    return 0;
}
