#include <stdio.h>

int main(){
    /*
    int i, x, k;
    //int alph[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
    char test[] = "TEST";
    char dec[4];
    for(i = 0; i <= 3; i++){
          x = test[i] - 65;
          k = 5;
          x = (x + k)%26;
          x = x + 65;
          dec[i]=x;
          printf("%c\n", x);
       
    }
     for(i = 0; i <= 3; i++){
          x = dec[i] - 65;
          k = 5;
          x = (x - k)%26;
          x = x + 65;
          printf("%c\n", x);
       
    }
    
*/
int i;

char sub[26] = "QWERTYUIOPASDFGHJKLZXCVBNM";
    char tst[] = "TEST";
    
    char tstdec[4];
    int x, j, n;
    for(i = 0; i <= 3; i++){
        x = tst[i] - 65;
        j = sub[x];
        tstdec[i] = j;
        printf("%c", j);

}
printf("\n");
for (i = 0; i <= 3; i++){
    for(n = 0; n <= 26; n++){
        x = tstdec[i] - 65;
        j = sub[n] - 65;
        if (tstdec[i] == sub[n]){
            tstdec[i] = n + 65;
            printf("%c", tstdec[i]);
        }
    }
}
 /*x = i+65;
        x = (x + 1) % 26;
        printf("%c %d %c %d %c\n", i, i, x+65, x, alph[i] );
        //printf("%c\n", alph[x]);
int subenc(){
    //char alph[26] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char sub[26] = "QWERTYUIOPASDFGHJKLZXCVBNM";
    char tst[] = "TEST";
    int x, j;
    for(i = 0; i <= 3; i++){
        x = test[i] - 65;
        j = sub[x]; 
        printf("%c\n", j);
    }*/
}