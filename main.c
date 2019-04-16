#include <stdio.h>
#include <stdlib.h>

int main(){
    
    int i, x, k, j, n; 
    char sub[26] = "QWERTYUIOPASDFGHJKLZXCVBNM"; //this is the substitue cipher key
    char tst[] = "THE QUICK BROWN FOX JUMPED OVER THE LAZY DOG"; //gonna get rid of this once i code the .txt file reading
    char tstdec[200]; //this is going to get written onto a .txt file
    char dec[200]; //the string encrypted with the rotation cipher 
    
    

for(i = 0; tst[i] != '\0'; i++){ 
    if(tst[i] <= 90 && tst[i] >= 65){          
          x = tst[i] - 65;
          k = 3;
          x = (x + k)%26;
          x = x + 65;
          dec[i]=x;
          printf("%c", x);
    }
    else{
        printf("%c", tst[i]);
    }
}

    
printf("\n");
for(i = 0; tst[i] != '\0'; i++){  
    if(tst[i] <= 90 && tst[i] >= 65){          
          x = dec[i] - 65;
          k = 3;
          x = (x - k)%26;
          if (x < 0){
              x = x + 26 + 65;
              printf("%c", x);
          } else {
          x = x + 65;
          printf("%c", x);
        }

          }
    else {
        printf("%c", tst[i]);
    }
}

printf("\n");
for(i = 0; tst[i] != '\0'; i++){ // for each letter in the string until '\0' (null) is returned
    if(tst[i] <= 90 && tst[i] >= 65){  // for capital letters only
        x = tst[i] - 65; // x is given a value of 0-25 by minusing 65 from the ASCII number at 'i' 
        //point in the string
        tstdec[i] = sub[x];
        printf("%c", tstdec[i]);
        }
    else{
        printf("%c", tst[i]);
    }
}

printf("\n");

for (i = 0; tstdec[i] != '\0'; i++){  //for each letter in the encrypted string
    if(tst[i] <= 90 && tst[i] >= 65){ //causes only capital letters to be changed
        for(n = 0; n <= 25; n++){ // 
            x = tstdec[i] - 65;
            j = sub[n] - 65;
            if (x == j){
                tstdec[i] = n + 65;
                printf("%c", tstdec[i]);
            }
        } 
    } else {
    printf("%c", tst[i]);
    }
}
/*
for (i = 0; tst[i] != '\0'; i++)  
{
    if(tst[i] <= 90 && tst[i] >= 65)
        {
        for(n = 0; n <= 26; n++)
        {
        
            x = tstdec[i] - 65;
            j = sub[n] - 65;
            if (x == j)
            {
                tstdec[i] = n + 65;
                printf("%c", tstdec[i]);
            }
            
        }    
        
    }
    else{
            printf("%c", tst[i]);
            }
    
}
*/
// ok maybe for the rotation cipher i could find 3 letter words (if there are any) and see if the letters e.g. t and h are the same distance apart 
// and if they are, adjust the cipher accordingly. and if they aren't i can test the first two letters again for a & n this time (testing for and)
// if both of these don't work then idk they should work. it's only a question of writing the code now. i think first i should make these algorythms work 
// for strings on an unknown length first which shouldn't be too hard. 
}