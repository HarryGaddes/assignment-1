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

// ok maybe for the rotation cipher i could find 3 letter words (if there are any) and see if the letters e.g. t and h are the same distance apart 
// and if they are, adjust the cipher accordingly. and if they aren't i can test the first two letters again for a & n this time (testing for and)
// if both of these don't work then idk they should work. it's only a question of writing the code now. i think first i should make these algorythms work 
// for strings on an unknown length first which shouldn't be too hard. 
}