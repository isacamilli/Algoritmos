#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main() {
    srand(time(NULL));
    int campo[5][5] = {
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0}
    };

    for(int i;i < 11;i++){
        int x = rand() %5;
        int y = rand() %5;
        campo[x][y] = -1;
    }
    
    
    for (int x = 0; x < 5; x++) {
        for (int y = 0; y < 5; y++) {
            int contador = 0;
            if (campo[x][y] == 0){
                if (campo[x][y+1]==-1) {
                    contador++;
                }
                if (campo[x+1][y]==-1 && x < 4) {
                    contador++;
                }
                if (campo[x+1][y+1]==-1) {
                    contador++;
                }
                if (campo[x][y-1]==-1) {
                    contador++;
                }
                if (campo[x][y+1]==-1) {
                    contador++;
                }
                if (campo[x+1][y]==-1 && x < 4) {
                    contador++;
                }
                if (campo[x+1][y+1]==-1) {
                    contador++;
                }
                if (campo[x][y-1]==-1) {
                    contador++;
                }
                if (campo[x-1][y]==-1) {
                    contador++;
                }
                if (campo[x-1][y-1]==-1) {
                    contador++;
                }
                if (campo[x+1][y-1]==-1) {
                    contador++;
                }
                if (campo[x-1][y+1]==-1) {
                    contador++;
                }
            }
                // else {
                //     if(campo[x-1][y]==-1) {
                //         contador++;
                //     }
                //     if (campo[x][y-1]==-1) {
                //         contador++;
                //     }
                //     if(campo[x-1][y-1]==-1) {
                //         contador++;
                //     }
                // }
                 campo[x][y] = contador;
            }
            
        }
    }

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            printf("[%d]", campo[i][j]);
        }
        printf("\n");
    }

    return 0;
}