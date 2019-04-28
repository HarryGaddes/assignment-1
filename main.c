/* High-level operation summary.

In order to operate this code an ./a.out command is required to be input to the terminal.
This is because of several scanf functions which require user input throughout the program.
This program uses (4) function prototypes in order to keep the main function concise and 
easy to read. Therefore when looking at the main function the user may get an idea of the 
program's functionality and structure. 
It is at the users discretion whether he or she decides to create a new text file to input 
their text or simply input text into the text file labeled "input.txt". The option of differing
text files is provided for those who may wish to encrypt/decrypt multiple blocks of test in
succession.  
NOTE: Please refrain from creating files with names exceeding 50 characters.
*/

#include <stdio.h>

//declaration of function prototypes
void rot_enc(void); //rot_enc = rotation encryption function
void rot_dec(void); //rot_dec = rotation decryption function
void sub_enc(void); //sub_enc = substitution encryption function
void sub_dec(void); //sub_dec = substitution decryption function
void rot_dec_noKey(void);
int main()
{
    int option; // initialization of integer used for menu selection
    printf("Cipher Menu:\n"); //************ prints menu options ************
    printf("1: Encryption of a rotation cipher (given a key)\n");    
    printf("2: Dectyption of a rotation cipher (given a key)\n");
    printf("3: Encryption of a substitution cipher (given a key)\n");
    printf("4: Dectyption of a substitution cipher (given a key)\n");
    printf("5: Decryption of a rotation cipher (with no given key)\n");
    printf("Please enter a number of the option you with to choose: ");
    scanf("%d", &option); //takes user input, selecting a menu option.
    switch (option){ //depending on user option, calls one of the functions declared above.
        case 1:
            rot_enc(); //calls the rot_enc function
        break;
        case 2:
            rot_dec(); //calls the rot_dec function
        break;
        case 3:
            sub_enc(); //calls the sub_enc function
        break;
        case 4:
            sub_dec(); //calls the sub_dec function
        break;
        case 5:
            rot_dec_noKey();
        break;
        default:
            printf("\nERROR: INVALID OPTION NUMBER");
    }
}

/* Function rot_enc summary:
 * This function's return type and arguments are both void.
 * The limitations of this function are a character limit of 50 on the user input 
 * of file name and 200 on the text read from the file, and that the encryption 
 * only works on capital letters.
 * This function reads user input from stdin to choose a file, reads that file
 * using FILE I/O, encrypts the text read from the file and prints said text.
 */

void rot_enc(void){ 
    int x; // initializes the int x for use in the encryption algorithm 
    int i; // initializes the int i for use as a counter variable and position 
    // indicator in the encryption algorithm
    int k; // initializes the int k for storing the key with which the string is
    // encrypted
    char fileName[50]; //initializes the string fileName to store the name if the
    // file the user wishes to read.
    char str[200]; //initializes the string str to store the text from the text file
    printf("\nPlease enter the name of the text file containing\nthe plain text you wish to encrypt: ");
    scanf("%s", fileName); //reads the users input until the end of the line and assigns it to the
    //string fileName
    printf("\nEnter the key with which you wish to encrypt (a number from 1-25): ");  
    scanf("%d", &k); //assigns the user input to k
    printf("\nYour encrypted text is: ");
    FILE *input; //initialize input with FILE datatype 
    input = fopen(fileName, "r"); //use the fopen() function to open the text file set to read only
    //with "r"
    if(input == NULL) //tests whether fopen has successfully opened a file
    {
        perror("fopen()"); //if fopen has not successfully opened a file perror will print a user 
        //friendly error message
        return; //returns a void value in order to conclude the rot_enc function
    }       
    while(!feof(input)) //while the position of input is not at the end of the file
    {
        fscanf(input, "%[^\n]s", str); //assign characters read from the file to str
    }
    for(i = 0; str[i] != '\0'; i++) //for each letter in str until it is null-terminated
    {         
        if(str[i] <= 90 && str[i] >= 65) //includes only capital letters in the encryption
        {          
            x = str[i] - 65; //takes 65 off the ASCII value of the character
            x = (x + k)%26; //using x and the key (k) the position of the encrypted character in
            //the alphabet is determined 
            x = x + 65; //add 65 to the letter's position (1-26) giving it the ASCII value of the
            //encrypted character
            printf("%c", x); //print said encrypted character.
        }
        else //bypasses the encryption process for characters, spaces and non-capital letters
        {
            printf("%c", str[i]); 
        }
    }
//    fclose(fileName); //closes the file
    printf("\n"); //print a new line so it looks better in the terminal
        
}

/* Function rot_dec summary:
 * This function's return type and arguments are both void.
 * The limitations of this function are a character limit of 50 on the user input 
 * of file name and 200 on the text read from the file, and that the decryption 
 * only works on capital letters.
 * This function reads user input from stdin to choose a file, reads that file
 * using FILE I/O, encrypts the text read from the file and prints said text.
 */

void rot_dec(void){
    int x; // initializes the int x for use in the encryption algorithm 
    int i; // initializes the int i for use as a counter variable and position 
    // indicator in the encryption algorithm
    int k; // initializes the int k for storing the key with which the string is
    // encrypted
    char fileName[50]; //initializes the string fileName to store the name if the
    // file the user wishes to read.
    char str[200]; //initializes the string str to store the text from the text file
    printf("\nPlease enter the name of the encrypted text file\nyou wish to decrypt: ");
    scanf("%s", fileName); //takes user input of a string, assigning it to fileName
    printf("\nEnter the key used to encrypt the text (a number from 1-25): ");
    scanf("%d", &k); //takes user input of an integer, assigning it to int k
    printf("\nYour decrypted text is: ");
    FILE *input; //initialize input with FILE datatype 
    input = fopen(fileName, "r"); //use the fopen() function to open the text file set to read only
    //with "r"
    if(input == NULL) //tests whether fopen has successfully opened a file
    {
        perror("fopen()"); //if fopen has not successfully opened a file perror will print a user 
        //friendly error message
        return; //returns a void value in order to conclude the rot_enc function
    }       
    while(!feof(input)) //while the position of input is not at the end of the file
    {
        fscanf(input, "%[^\n]s", str); //assign characters read from the file to str
    }
    for(i = 0; str[i] != '\0'; i++) //for each letter in str until it is null-terminated
    {         
        if(str[i] <= 90 && str[i] >= 65) //includes only capital letters in the encryption
        {          
            x = str[i] - 65; //takes 65 off the ASCII value of the character
            x = (x - k)%26; //deducts the key (k) from x, therefore "rotating" it backward to 
            //its unencrypted value
            if (x < 0) //in order to circumvent errors arising the value of x being less than k (resulting 
            // in a negative value for x)
            {
                x = x + 26 + 65; //perform a full rotation by adding 26 (resulting in a poisitive number
                // in the correct position) and add 65 to give it the correct ASCII value 
                printf("%c", x); //print the letter
            } 
            else //if it's not negative
            {
                x = x + 65; // add 65 to give it the correct ASCII value
                printf("%c", x); //print the letter
            }

          }
        else //if it's not a capital letter
        {
            printf("%c", str[i]); //print the un-changed character
        }
    }

    printf("\n"); //print a new line so it looks better in the terminal
}


/* Function sub_enc summary:
 * This function's return type and arguments are both void.
 * The limitations of this function are a character limit of 50 on the user input 
 * of file name and 200 on the text read from the file, and that the encryption 
 * only works on capital letters.
 * This function reads user input from stdin to choose a file, reads that file
 * using FILE I/O, encrypts the text read from the file and prints said text.
 */

void sub_enc(void){
    int x; // initializes the int x for use in the encryption algorithm 
    int i; // initializes the int i for use as a counter variable and position 
    // indicator in the encryption algorithm
    char sub[25]; //Initialized to store the user inputted substitution key
    char str[200]; //initializes the string str to store the text from the text file
    char fileName[50]; //initializes the string fileName to store the name if the
    // file the user wishes to read.
    printf("\nPlease enter the name of the encrypted text file\nyou wish to encrypt: ");
    scanf("%s", fileName); //takes user input of a string, assigning it to fileName
    printf("\nEnter the substitution key you wish to use to encrypt the text (26 unique capital letters and no spaces): ");
    scanf("%s", sub); //takes the user inputted substitution key
    printf("\nYour encrypted text is: ");
    FILE *input; //initialize input with FILE datatype 
    input = fopen(fileName, "r"); //use the fopen() function to open the text file set to read only
    //with "r"
    if(input == NULL) //tests whether fopen has successfully opened a file
    {
        perror("fopen()"); //if fopen has not successfully opened a file perror will print a user 
        //friendly error message
        return; //returns a void value in order to conclude the rot_enc function
    }       
    while(!feof(input)) //while the position of input is not at the end of the file
    {
        fscanf(input, "%[^\n]s", str); //assign characters read from the file to str
    }
    for(i = 0; str[i] != '\0'; i++) //for each letter in str until it is null-terminated
    {         
        if(str[i] <= 90 && str[i] >= 65) //includes only capital letters in the encryption
        {  
            x = str[i] - 65;  // uses the character at i position in the string (minus 65) to
            // give its position in the alphabet (1-26). 
            printf("%c", sub[x]); //this "position" x is then used to print the character in sub at
            //that poistion
        }
        else //ignore characters not within the ASCII range denoting capital letters
        {
            printf("%c", str[i]);
        }
    }

    printf("\n"); //print a new line so it looks better in the terminal
}

/* Function sub_dec summary:
 * This function's return type and arguments are both void.
 * The limitations of this function are a character limit of 50 on the user input 
 * of file name and 200 on the text read from the file, and that the encryption 
 * only works on capital letters.
 * This function reads user input from stdin to choose a file, reads that file
 * using FILE I/O, encrypts the text read from the file and prints said text.
 */

void sub_dec(void){
    int x; // initializes for use in the encryption algorithm 
    int i; // initializes for use as a counter variable and position indicator in the encryption algorithm
    int n; // initializes for use as a counter variable and position indicator in the encryption algorithm
    int j; // initializes for use in the encryption algorithm
    char sub[25]; //Initialized to store the user inputted substitution key
    char str[200]; //initializes the string str to store the text from the text file
    char fileName[50]; //initializes the string fileName to store the name if the
    // file the user wishes to read.
    printf("\nPlease enter the name of the encrypted text file\nyou wish to decrypt: ");
    scanf("%s", fileName);
    printf("\nEnter the substitution key used to encrypt the text (26 unique capital letters): ");
    scanf("%s", sub);
    printf("\nYour encrypted text is: ");
    FILE *input; //initialize input with FILE datatype 
    input = fopen(fileName, "r"); //use the fopen() function to open the text file set to read only
    //with "r"
    if(input == NULL) //tests whether fopen has successfully opened a file
    {
        perror("fopen()"); //if fopen has not successfully opened a file perror will print a user 
        //friendly error message
        return; //returns a void value in order to conclude the rot_enc function
    }       
    while(!feof(input)) //while the position of input is not at the end of the file
    {
        fscanf(input, "%[^\n]s", str); //assign characters read from the file to str
    }
    for(i = 0; str[i] != '\0'; i++) //for each letter in str until it is null-terminated
    {         
        if(str[i] <= 90 && str[i] >= 65) //includes only capital letters in the encryption
        {
            for(n = 0; sub[n] != '\0'; n++) //for each letter in the substitution key
            {
                x = str[i] - 65; //set x to the position of str at poisition i in the alphabet
                j = sub[n] - 65; //set j to the position of sub at poisition n in the alphabet 
                if (x == j) //at the point when x = j
                {
                    j = n + 65; //use the position n in sub plus 65 to give the correct ASCII number
                    printf("%c", j); //print the decrypted letter 
                }
            }    
        }
        else //ignore characters not within the ASCII range denoting capital letters
        {
            printf("%c", str[i]); 
        }
    }

    printf("\n"); //print a new line so it looks better in the terminal
}

void rot_dec_noKey(void){
    int i, count, sc, ph, k, x, n;
    char str[200];
    char fileName[50];
    printf("\nPlease enter the name of the encrypted text file\nyou wish to decrypt: ");
    scanf("%s", fileName);
    
    FILE *input; //initialize input with FILE datatype 
    input = fopen(fileName, "r"); //use the fopen() function to open the text file set to read only
    //with "r"
    if(input == NULL) //tests whether fopen has successfully opened a file
    {
        perror("fopen()"); //if fopen has not successfully opened a file perror will print a user 
        //friendly error message
        return; //returns a void value in order to conclude the rot_enc function
    }       
    while(!feof(input)) //while the position of input is not at the end of the file
    {
        fscanf(input, "%[^\n]s", str); //assign characters read from the file to str
    }
    for(n = 0; str[n] != '\0'; n++) 
    {         
        if(str[n] <= 90 && str[n] >= 65) 
        {
            count++;
        }
        else if(count == 3)
        {
            if ((str[n - 3] - str[n - 2]) == 'T' - 'H' || (str[n - 3] - str[n - 2] - 26) == 'T' - 'H'){
                ph = str[n - 3] - 'T';
                if (ph < 0)
                {
                    ph = ph + 26;
                }
                sc = 1;
                
            }
            else if ((str[n - 3] - str[n - 2]) == 'A' - 'N' || (str[n - 3] - str[n - 2] - 26) == 'A' - 'N'){
                ph = str[n - 3] - 'A';
                if (ph < 0)
                {
                    ph = ph + 26;
                }
                sc = 2;
            }
            else 
            {
            count = 0;
            }

        }
        else
        {
            count = 0;
        }
    }
    switch (sc){
    case 1:
        k = ph;
    break;
    case 2:
        k = ph;
    break;
    default:
        printf("decryption unavailable");
    }
    for(i = 0; str[i] != '\0'; i++) //for each letter in str until it is null-terminated
    {         
        if(str[i] <= 90 && str[i] >= 65) //includes only capital letters in the encryption
        {          
            x = str[i] - 65; //takes 65 off the ASCII value of the character
            x = (x - k)%26; //deducts the key (k) from x, therefore "rotating" it backward to 
            //its unencrypted value
            if (x < 0) //in order to circumvent errors arising the value of x being less than k (resulting 
            // in a negative value for x)
            {
                x = x + 26 + 65; //perform a full rotation by adding 26 (resulting in a poisitive number
                // in the correct position) and add 65 to give it the correct ASCII value 
                printf("%c", x); //print the letter
            } 
            else //if it's not negative
            {
                x = x + 65; // add 65 to give it the correct ASCII value
                printf("%c", x); //print the letter
            }

          }
        else //if it's not a capital letter
        {
            printf("%c", str[i]); //print the un-changed character
        }
    }
        
    printf("\n");
}



