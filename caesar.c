/* 
Author:.............L. Adan  

Date:...............Fall 2014

Class:..............cs50

File:...............caesar.c 

 
*/ 
#include <stdlib.h>
#include <stdio.h>
#include <cs50.h>
#include <ctype.h> 
#include <string.h>

// argc contians argument count(length),argv conains name of program
int main(int argc, string argv[])
{
    // initialize variable for key
    // (i) prefixed to variable indicates integer
    int iKey = 0;
    
    // string which will store user message
    string msg; 
    
  
    
    // check argc and argv[] for correct entry: ./caesar and iKey 
    // make sure no more or less than 2 command line arguments are given'
    if (argc < 2 || atoi(argv[0]) < 0 || atoi(argv[1]) < 0)
    {   
        // warn user by returning and erorr
        printf("enter a single command-line arg: non-negative integer.\n"); 
        return 1; 
    } 
    else
    {   
        // convert key to integer then store the key
        iKey = atoi(argv[1]);
    }
    
    // get user message
    msg = GetString(); 
    
    // loop to start encipher of message
    for (int i = 0, j = strlen(msg); i < j; i++)
    {
        // for lowercase letters
        if (islower(msg[i]) && isalpha(msg[i]))
        {
            msg[i] = (msg[i] - 'a' + iKey) % 26 + 97;
        }
        
        // for uppercase letters
        else if(isupper(msg[i]) && isalpha(msg[i]))
        {
            msg[i] = (msg[i] - 'A' + iKey) % 26 + 65;
        }
        
        // print the encrypted characters
        printf("%c", msg[i]); 
        
    }
    // newline
    printf("\n"); 
    
    // No errors exist! 
    return 0; 
   

}
