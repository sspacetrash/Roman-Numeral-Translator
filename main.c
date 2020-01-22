//
//  login:hn92
//  Name:HOI CHING NG
//
//  Roman to arabic translator
//  Version 5
//


//#include "stdafx.h"
#include <stdio.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS

int main() {
    //initialize varaibles (function of each variables is explained in pdf)
    char Roman[20];
    int Value[20];
    int i, final_value;
    int length;
    int selection;
    char filename[20];
    FILE *infile;
    FILE *outfile;
    
    printf("Enter 1 if you wish to enter number in program, enter 0 if you wish to read from a txt.file\n");
    scanf("%d",&selection);
    if (selection = 0){
        printf("You are in user input mode, enter Roman character:\n"); //promtpt user to enter Roman character
        gets(Roman);//get the Roman numeral and store in array
    }
    else
    {
        printf("You are in batch mode, enter file name to be read.");
        gets(filename);
        infile =  fopen(filename, "r");
        fscanf(infile,"%s",Roman);
        fclose(infile);
    }
    
    length = strlen(Roman); //calculate length
    //get user to enter Roman numerals and calculate word length
    
    //convert roman to arabic
    for (i = 0; i<length; i++) {
        switch (Roman[i])
        {
            case 'M':
                Value[i] = 1000; //store the corresponding number in a new array
                break; //end loop after condition is met
            case 'D':
                Value[i] = 500;
                break;
            case 'C':
                Value[i] = 100;
                break;
            case 'L':
                Value[i] = 50;
                break;
            case 'X':
                Value[i] = 10;
                break;
            case 'V':
                Value[i] = 5;
                break;
            case 'I':
                Value[i] = 1;
                break;
            default:
                printf("Invalid character");
        }
        
        printf("The %d value is %d\n", i, Value[i]); //print out numeric numbers
    }
    
    //do subtraction
    final_value = 0; //initialize final_value as 0
    for (i = 0; i<length; i++) //for loop to do addition and subtraction
    {
        if (Value[i] >= Value[i + 1]) //when the number is larger that the one after it
        {
            final_value = final_value + Value[i]; //it does addition
        }
        
        else
        {
            final_value = final_value + (Value[i + 1] - Value[i]); //if not,it does subtraction
            i = 1 + i; //as after subtraction, the number following should not be added. So adding one will skip the following one to prevent overadding
        }
    }
    if (selection = 1){
    printf("The value is %d\n", final_value); //show final answer
    }
    else{
        printf("Please enter output file name");
        gets(filename);
        outfile = fopen(filename,"w");
        fprintf(outfile,"The value is %d\n",final_value);
        fclose(outfile);
    }
    return 0;
}
