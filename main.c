#include <stdio.h>
# include "stdlib.h"
#include "time.h"


// Berakja a ketteseket a matrixba
int * kettes(int matrix[4][4]){
    printf("\nkettes\n");

    int matrixkezd[2] = {6,6};

    // 4 elemű array random number
    int i =0;
    srand(time(NULL));

    // A két db kettes
    for (int j = 0; j<= 1; j++) {

        while (matrix[matrixkezd[0]][matrixkezd[1]] != 0 && i != 64) {
                // rand() % (max_number + 1 - minimum_number) + minimum_number
                matrixkezd[0] = rand() % 4;
                matrixkezd[1] = rand() % 4;

            i ++;

        }if(matrix[matrixkezd[0]][matrixkezd[1]] == 0) {
            // A kettesek berakása to a random place in the matrix 90% 2 10 % 4. 1. szám
            int szam = rand() % 101;
            if (szam < 90) {
                matrix[matrixkezd[0]][matrixkezd[1]] = 2;
            } else {
                matrix[matrixkezd[0]][matrixkezd[1]] = 4;
            }

            j++;
        }
    }


    return matrix;
}

// scanf fel le jobbra ballra
int * game(int matrix[4][4], char dir) {
    printf("\ngame\n");
    int i, j;

    printf("\n%c\n", dir);
    int ertek = 0;

    // HA LE j,i = j-1,i
    if (dir == 'l') {
        for (i = 0; i < 4; i++) {
            for (j = 1; j < 4; j++) {
                if (matrix[j][i] == 0 || matrix[j][i] == matrix[j - 1][i]) {
                    ertek = matrix[j - 1][i];
                    matrix[j - 1][i] = 0;
                    matrix[j][i] = matrix[j][i] + ertek;
                }
            }

            printf("\n");
        }

    // HA LE i,j = i,j+1
    }else if(dir == 'f'){
        for (i = 0; i < 4; i++) {
            for (j = 2; j >= 0; j--) {
                if (matrix[j][i] == 0 || matrix[j][i] == matrix[j + 1][i]) {
                    ertek = matrix[j + 1][i];
                    matrix[j + 1][i] = 0;
                    matrix[j][i] = matrix[j][i] + ertek;
                }
            }
            printf("\n");
        }
    // Ha JOBBRA megy i,j = i+1,j
    }else if(dir == 'b'){
        for (i = 0; i < 4; i++) {
            for (j = 2; j >= 0; j--) {
                if (matrix[i][j] == 0 || matrix[i][j] == matrix[i][j+1]) {
                    ertek = matrix[i][j +1];
                    matrix[i][j+1] = 0;
                    matrix[i][j] = matrix[i][j] + ertek;
                }
            }
            printf("\n");
        }


    }else if(dir == 'j'){
        for (i = 0; i < 4; i++) {
            for (j = 1; j < 4; j++) {
                if (matrix[i][j] == 0 || matrix[i][j] == matrix[i][j-1]) {
                    ertek = matrix[i][j-1];
                    matrix[i][j-1] = 0;
                    matrix[i][j] = matrix[i][j] + ertek;
                }
            }
            printf("\n");
        }
        // e mint error
    }else if(dir == 'e'){
        printf("Error");
    }
    return matrix;

}

// Kinyomtatja a matrixomat
void * printmatrix(int matrix[4][4]){
    printf("\nprint\n");
    int i,j;
    for(i = 0; i < 4; i ++){
        for(j = 0; j<4; j++){
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");

}


int main() {
    int matrix[4][4];
    int j, i = 0;

    // Feltölti 0 val
    for(i = 0; i < 4; i ++){
        for(j = 0; j<4; j++){
            matrix[i][j] = 0;
        }
    }

//////////////////////////////////

    int *n;
    int *h;


/////////////////////////////////

    h = matrix;
    char dir;
    int nemnulla = 0;
    int z = 1;

while(nemnulla != 5 && z != 2048) {
    nemnulla = 0;
    n = kettes(h);
    printmatrix(n);

    printf("Merre? le(l) fel(f) jobbra(j) ballra(b)\n");
    //scanf("%c", &dir);


    h = game(h, dir);
    printmatrix(h);

    for(i = 0; i < 4; i ++){
        for(j = 0; j<4; j++){
            if (matrix[i][j] == 2048){
                z = 2048;
                printf("NYERTÉL");
                break;
            }
            if (matrix[i][j] == 0){
                nemnulla = 1;
            }


        }
    }
    if (nemnulla == 0){
        printf("Vesztettél!");
        nemnulla = 5;
    }



}



















    return 0;
}