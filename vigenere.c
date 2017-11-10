/* 
Author:.............Leyth

Date:...............Fall 2014

Class:..............cs50

File:...............vigenere.c 

 
*/ 
#include <ctype.h>
#include <stdio.h>
#include <cs50.h>
#include <string.h>


int main(int argc, string argv[])
{

    // var stores user message
    string msg = NULL; 
    // variable stores key
    string key = argv[1];
    // last character examined
    int lastChar = 0; 
    // counter
    int counter = 0; 
   

   
    // validate arguments
    if (argc != 2)
    {
        // warn user
        printf("You must enter a single command-line argument: \n");
        
        // value of 1 returns error
        return 1;
        
    }
    
    // make sure keyword is from A-Z
    for ( int n = 0; n < strlen(key); n++) 
    {
         // if it is not alphabetical
        if (!isalpha(argv[1][n]))
        {
            // warn the user
            printf("you've entered non-alphabetical chars\n"); 
             
            // return error
            return 1;  
                  
                  }
         }
         
    // loop through as long as message is NULL or empty 
    do 
    {
        // get message from user
        msg = GetString(); 
    
    }while(msg == '\0'); 
     
    
    // loop through message and manipulate string 
    // using functions from imported libraries
    for (int i = 0, j = strlen(msg); i < j; i++)
    { 
    
        // validate   
        if (isalpha(msg[i]))
        {
            // set counter to modulo length of keyword
            counter = lastChar % strlen(key);
            
            // preserve LOWERCASE
            if (islower(msg[i]))
            {
                if (islower(key[counter]))
                {
                    msg[i] = ((msg[i] - 'a' + key[counter] - 97) % 26) + 97;
                    printf("%c", msg[i]);
                }
                else
                {
                    msg[i] = ((msg[i] - 'a' + key[counter] - 65) % 26) + 97;
                    printf("%c", msg[i]);
                }
            }
            
            // preserve UPPERCASE
            if (isupper(msg[i]))
            {
                if (islower(key[lastChar]))
                {
                    
                    msg[i] = ((msg[i] - 'A' + key[counter] - 97) % 26) + 65;
                    printf("%c", msg[i]);
                }
                else
                {
                    msg[i] = ((msg[i] - 'A' + key[counter] - 65) % 26) + 65;
                    printf("%c", msg[i]);
                }
           
            }
            
        // increment last characters by 1    
        // results if not incremented: Meet at the park at eleven am 
        // (Nffu bu uif qbsl bu fmfwfo bn)
        // as opposed to when it is incremented 
        // (Negh zf av huf pcfx bt gzrwep oz)
            lastChar++;
        }
        else
        {   
            // print encryted message
            printf("%c", msg[i]);
        }
    }
    
    // print newline
    printf("\n");
    
    
    // No errors exist! 
    return 0; 
}


