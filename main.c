//this code from  geeksforgeeks.org  and  modified it 
//Author by :Ahmed samir elmenshawy 

#include "Types.h"
#include <conio.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "Replace/Replace_interface.h"  
#include "Replace/Replace_config.h" 

#define  Main_S32Success 0
#define  Replace_S32Error  1

//Our main function.
s32 main(s32 argc, s8 *argv[]) 
{
	///*
	char word[Replace_S32MaxBufferToScan], fname[Replace_S32MaxBufferToScan]="file1.txt";
    char string[Replace_S32MaxBufferToScan], replace[Replace_S32MaxBufferToScan];
    s8 temp[] = "temp.txt", *ptr1, *ptr2;
		
	s32 Local_s32result;
	if(argc < 7 && Replace_VoidWordtNotFound(argv)== Replace_S32Error) 
	{
		printf("Paramter less than %d\n",Replace_S32MinNumberArgument);
		//Replace_VoidWordtNotFound(argv);
		return;
	}
	else
	{
		system("cls");

		Local_s32result = Replace_SearchInFile(argc, argv);
		if(Local_s32result != Main_S32Success) 
		{
			printf("Error \n");
			exit(1);
		}
		else{
			printf("SUCCESS \n");
		}
	}
	//*/
	/*
		FILE *fp1, *fp2;
        char word[256]="Hi", fname[256]="file1.txt";
        char string[256], replace[256]="Hello";
        s8 temp[] = "temp.txt", *ptr1, *ptr2;
		
        
        // open input file in read mode //
        fp1 = fopen(fname, "r");

        // error handling //
        if (!fp1) {
                printf("Unable to open the input file!!\n");
                return 0;
        }

        // open temporary file in write mode //
        fp2 = fopen(temp, "w");

        // error handling //
        if (!fp2) {
                printf("Unable to open temporary file!!\n");
                return 0;
        }
	//	
	//printf("%c",fgetc(fp1));
	// delete the given word from the file //
    while (!feof(fp1)) {
            strcpy(string, "\0");
            // read line by line from the input file //
            fgets(string, 256, fp1);
			 //
             //* check whether the word to delete is
             //* present in the current scanned line
             //*
			//getch();
			if (Replace_SearchWordInFile(string, word)) 
			{
					ptr2 = string;
					while (ptr1 = Replace_SearchWordInFile(ptr2, word)) 
					{
                            //
                             //* letters present before
                             //* before the word to be replaced
                             //*
							// getch();
							//copy to temp file until first accurance
                            while (ptr2 != ptr1) 
							{
                                    fputc(*ptr2, fp2);
                                    ptr2++;
							}
                            // skip the word to be replaced //
                            ptr1 = ptr1 + strlen(word);
                            fprintf(fp2, "%s", replace);
                            ptr2 = ptr1;
                    }

                    // characters present after the word to be replaced //
                    while (*ptr2 != '\0') 
					{
                            fputc(*ptr2, fp2);
                            ptr2++;
                    }
            } else {
                    //
                    // * current scanned line doesn't 
                    // * have the word that need to be replaced
                     //*
                    fputs(string, fp2);
            }
    }

    // close the opened files //
    fclose(fp1);
    fclose(fp2);

    // remove the input file //
    remove(fname);
    // rename temporary file name to input file name //
    rename(temp, fname);
	return(0);
	*/
}