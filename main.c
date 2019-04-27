#include <stdio.h>


//    char str[200];
//    int i;
//    FILE *input;
//    input = fopen("input.txt", "r");
//    if(input == NULL){
//        perror("fopen()");
//        return 0;
//    }
//    for (i = 0; !feof(input); i++){
//        fscanf(input, "%[^\n]s", str);
//        printf("%s", str);
//    }


void rot_enc(void);
void rot_dec(void);
void sub_enc(void);
void sub_dec(void);
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
        case 3:
            sub_enc();
        break;
        case 4:
            sub_dec();
        break;
        default:
            printf("\nERROR: INVALID OPTION NUMBER");
    }
}
void rot_enc(void){
    int x, i, k;
    char fileName[50];
    char str[200];
    printf("\nPlease enter the name of the text file containing the plain text you wish to encrypt: ");
    scanf("%s",fileName);
    printf("\nEnter the key with which you wish to encrypt (a number from 1-25): ");
    scanf("%d", &k);
    printf("\nYour encrypted text is: ");
    
    FILE *input;
    input = fopen(fileName, "r");
    if(input == NULL)
    {
        perror("fopen()");
        return;
    }       
    while(!feof(input))
    {
                fscanf(input, "%[^\n]s", str);
    }
    for(i = 0; str[i] != '\0'; i++)
    {         
        if(str[i] <= 90 && str[i] >= 65)
        {          
            x = str[i] - 65;
            x = (x + k)%26;
            x = x + 65;
            printf("%c", x);
        }
        else
        {
            printf("%c", str[i]);
        }
    }
    printf("\n");
        
}

void rot_dec(void){
    int x, i, k;
    char str[200];
    char fileName[50];
    printf("\nPlease enter the name of the encrypted text file you wish to decrypt: ");
    scanf("%s",fileName);
    printf("\nEnter the key used to encrypt the text (a number from 1-25): ");
    scanf("%d", &k);
    printf("\nYour decrypted text is: ");
    FILE *input;
    input = fopen(fileName, "r");
    if(input == NULL)
    {
        perror("fopen()");
        return;
    }       
    while(!feof(input))
    {
        fscanf(input, "%[^\n]s", str);
    }
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
    printf("\n");
}

void sub_enc(void){
    int x, i;
    char sub[25];
    char str[200];
    char fileName[50];
    printf("\nPlease enter the name of the plain text file you wish to encrypt: ");
    scanf("%s",fileName);
    printf("\nEnter the substitution key you wish to use to encrypt the text (26 unique capital letters and no spaces): ");
    scanf("%s", sub);
    printf("\nYour encrypted text is: ");
    FILE *input;
    input = fopen(fileName, "r");
    if(input == NULL)
    {
        perror("fopen()");
        return;
    }       
    while(!feof(input))
    {
                fscanf(input, "%[^\n]s", str);
    }
    for(i = 0; str[i] != '\0'; i++)
    { 
        if(str[i] <= 90 && str[i] >= 65)
        {  
            x = str[i] - 65; 
            printf("%c", sub[x]);
        }
        else
        {
            printf("%c", str[i]);
        }
    }
    printf("\n");
}

void sub_dec(void){
    int x, i, n, j;
    char sub[25];
    char str[200];
    char fileName[50];
    printf("\nPlease enter the name of the encrypted text file you wish to decrypt: ");
    scanf("%s",fileName);
    printf("\nEnter the substitution key used to encrypt the text (26 unique capital letters): ");
    scanf("%s", sub);
    printf("\nYour encrypted text is: ");
    FILE *input;
    input = fopen(fileName, "r");
    if(input == NULL)
    {
        perror("fopen()");
        return;
    }       
    while(!feof(input))
    {
                fscanf(input, "%[^\n]s", str);
    }
    for (i = 0; str[i] != '\0'; i++)  
    {
      if(str[i] <= 90 && str[i] >= 65)
        {
            for(n = 0; n <= 26; n++)
            {
        
                x = str[i] - 65;
                j = sub[n] - 65;
                if (x == j)
                {
                    j = n + 65;
                    printf("%c", j);
                }
            }    
        }
        else 
        {
            printf("%c", str[i]);
        }
    }
    printf("\n");
}
