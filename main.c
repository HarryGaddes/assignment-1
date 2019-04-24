#include <stdio.h>
void rot_enc(void);
void rot_dec(void);
int main()
{
    int option;
    printf("Cipher Menu:\n");
    printf("1: Encryption of a rotation cipher (given a key)\n");
    printf("2: Dectyption of a rotation cipher (given a key)\n");
    printf("3: Encryption of a substitution cipher (given a key)\n");
    printf("4: Dectyption of a substitution cipher (given a key)\n");
    printf("Please enter a number of the option you with to choose: ");
    scanf("%d", &option);
    switch (option){
        case 1:
            rot_enc();
        break;
        case 2:
            rot_dec();
        break;
        default:
            printf("ERROR: INVALID OPTION NUMBER");
    }
}
void rot_enc(void){
    int x, i, k;
    char str[200];
    printf("\nPlease enter the plain text you wish to encrypt: ");
    scanf("%s", str);
    printf("\nEnter the key with which you wish to encrypt (a number from 1-25): ");
    scanf("%d", &k);
    printf("\nYour encrypted text is: ");
    for(i = 0; str[i] != '\0'; i++){ 
        if(str[i] <= 90 && str[i] >= 65){          
            x = str[i] - 65
            x = (x + k)%26;
            x = x + 65;
            printf("%c", x);
        }
        else{
            printf("%c", str[i]);
        }
    }
    printf("\n");
}

void rot_dec(void){
    int x, i, k;
    char str[200];
    printf("\nPlease enter the encrypted text you wish to decrypt: ");
    scanf("%s", str);
    printf("\nEnter the key used to encrypt the text (a number from 1-25): ");
    scanf("%d", &k);
    printf("\nYour decrypted text is: ");
    for(i = 0; str[i] != '\0'; i++)
    {  
        if(str[i] <= 90 && str[i] >= 65)
        {          
            x = str[i] - 65;
            x = (x - k)%26;
            if (x < 0)
            {
                x = x + 26 + 65;
                printf("%c", x);
            } 
            else 
            {
                x = x + 65;
                printf("%c", x);
            }

          }
        else
        {
            printf("%c", str[i]);
        }
    }
    
}
