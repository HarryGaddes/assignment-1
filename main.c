#include <stdio.h>


int main(){
    
    int i, x, k, j, n; 
    char sub[26] = "QWERTYUIOPASDFGHJKLZXCVBNM"; //this is the substitue cipher key
    char tst[] = "TESTING TESTING"; //gonna get rid of this once i code the .txt file reading
    char tstdec[4]; //this is going to get written onto a .txt file
    char dec[4]; //the string encrypted with the rotation cipher 
    
    

for(i = 0; i <= 14; i++){ //gonna replace the 3 with a variable containing string length 
    if(tst[i] <= 90 && tst[i] >= 65){          
          x = tst[i] - 65;
          k = 5;
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
for(i = 0; i <= 14; i++){ //gonna replace the 3 with a variable containing string length 
    if(tst[i] <= 90 && tst[i] >= 65){          
          x = dec[i] - 65;
          k = 5;
          x = (x - k)%26;
          x = x + 65;
          printf("%c", x);
          }
    else {
        printf("%c", tst[i]);
    }
}

printf("\n");
for(i = 0; i <= 14; i++){ //gonna replace the 3 with a variable containing string length 
    if(tst[i] <= 90 && tst[i] >= 65){        
        x = tst[i] - 65;
        j = sub[x];
        tstdec[i] = j;
        printf("%c", j);
        }
    else{
        printf("%c", tst[i]);
    }
}

printf("\n");

for (i = 0; i <= 14; i++) //gonna replace the 3 with a variable containing string length 
{
    for(n = 0; n <= 26; n++)
    {
        if(tst[i] <= 90 && tst[i] >= 65)
        {
            x = tstdec[i] - 65;
            j = sub[n] - 65;
            if (tstdec[i] == sub[n])
            {
                tstdec[i] = n + 65;
                printf("%c", tstdec[i]);
            }
        }
    

        else{
            printf("%c", tst[i]);
            }
        
    }    
}

// ok maybe for the rotation cipher i could find 3 letter words (if there are any) and see if the letters e.g. t and h are the same distance apart 
// and if they are, adjust the cipher accordingly. and if they aren't i can test the first two letters again for a & n this time (testing for and)
// if both of these don't work then idk they should work. it's only a question of writing the code now. i think first i should make these algorythms work 
// for strings on an unknown length first which shouldn't be too hard. 
}