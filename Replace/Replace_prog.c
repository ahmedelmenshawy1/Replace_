#include <conio.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "Types.h" 
#include "Replace_interface.h"  
#include "Replace_config.h" 
#include "Replace_private.h"

/*******************************************************/  
/*Comment!: If User Do not know how to use program*/
extern s8 Replace_VoidWordtNotFound(s8 *Copy_ArrPtrArgv[]) 
{
	s8 Replace_S8Result=Replace_S32Error;
	
	u8 i,Local_u8FileCounter=Replace_S32MinNumberArgument;
	//for(i=0;i<5;i++)puts(Copy_ArrPtrArgv[i]);
	if(strcmp(Copy_ArrPtrArgv[2],"-f") == 0||strcmp(Copy_ArrPtrArgv[1],"-f") == 0)
	{
		Replace_S8Result=Replace_S32Success;
	}
	else if(strcmp(Copy_ArrPtrArgv[2],"-b") == 0 ||strcmp(Copy_ArrPtrArgv[1],"-b") == 0)
	{
		Replace_S8Result=Replace_S32Success;
	}
	else if(strcmp(Copy_ArrPtrArgv[2],"-l") == 0 ||strcmp(Copy_ArrPtrArgv[1],"-l") == 0)
	{
		Replace_S8Result=Replace_S32Success;
	}
	else if(strcmp(Copy_ArrPtrArgv[2],"-i") == 0 ||strcmp(Copy_ArrPtrArgv[1],"-i") == 0)
	{
		Replace_S8Result=Replace_S32Success;
	}
	else//error
	{
		Replace_S8Result=Replace_S32Error;
	}
	if(strcmp(Copy_ArrPtrArgv[4],"--") != 0)
	{
		Replace_S8Result=Replace_S32Error;
	}
	else;
	if(strcmp(Copy_ArrPtrArgv[2],"-f") == 0 || strcmp(Copy_ArrPtrArgv[2],"-l") == 0 )
	{
		Local_u8FileCounter++;
	}
	else;
	if(!Replace_SearchLastOccurance(Copy_ArrPtrArgv[Local_u8FileCounter],".txt") )
	{
		Replace_S8Result=Replace_S32Error;
	}
	//*/
	
	if(Replace_S8Result==Replace_S32Error)
	{	
		printf("Usage: %s OPT <from> <to> -- <filename> [<filename>]*\n", Copy_ArrPtrArgv[0]);
	}
	else;
	if(Replace_S8Result==Replace_S32Error)
	{	
		printf("Usage: %s OPT <from> <to> -- <filename> [<filename>]*\n", Copy_ArrPtrArgv[0]);
	}
	else;
	return  Replace_S8Result;
}
/*******************************************************/  
//*Comment!: Search for word in file*/
extern s8 * Replace_SearchWordInFile(s8 *Copy_s8ArrString, s8 *Copy_s8ArrSearch ) 
{
	s32 Local_s32Counter=0;
	s8 *Local_s8PtrResult=NULL;
	s32 Local_s32SearchCounter=0;
	u8 Local_u8CounterMatchedCh=0;
	
	//Local_s8Result=Copy_s8ArrString[0];
	//printf("sdsd=%d",strlen(Copy_s8ArrString));
	//getch();
	for(Local_s32Counter=0;Local_s32SearchCounter < strlen(Copy_s8ArrString) ;Local_s32Counter++,Local_s32SearchCounter++)
	{
		if(Copy_s8ArrSearch[Local_s32Counter] == Copy_s8ArrString[Local_s32SearchCounter] || toupper(Copy_s8ArrSearch[Local_s32Counter])== Copy_s8ArrString[Local_s32SearchCounter] || tolower(Copy_s8ArrSearch[Local_s32Counter])== Copy_s8ArrString[Local_s32SearchCounter]  )
		{
			Local_u8CounterMatchedCh++;
			if(Local_u8CounterMatchedCh == strlen(Copy_s8ArrSearch) )
			{
				//pointer to first accurance
				Local_s8PtrResult=Copy_s8ArrString+(Local_s32SearchCounter-Local_u8CounterMatchedCh)+1;
				break;
			}
			else
			{
				
			}
		}
		else
		{
			//when go to ++ will increment and will be zero
			Local_s32Counter=-1;
			Local_u8CounterMatchedCh=0;
		}
	}
	
	return Local_s8PtrResult;
}
/*******************************************************/  
//*Comment!: Search for word Last Occurance in file*/
extern s8 * Replace_SearchLastOccurance(s8 *Copy_s8ArrString, s8 *Copy_s8ArrSearch ) 
{
	s32 Local_s32Counter=0;
	s8 *Local_s8PtrResult=NULL;
	s32 Local_s32SearchCounter=0;
	u8 Local_u8CounterMatchedCh=0;
	
	for(Local_s32Counter=0;Local_s32SearchCounter < strlen(Copy_s8ArrString) ;Local_s32Counter++,Local_s32SearchCounter++)
	{
		if(Copy_s8ArrSearch[Local_s32Counter] == Copy_s8ArrString[Local_s32SearchCounter] )//|| toupper(Copy_s8ArrSearch[Local_s32Counter])== Copy_s8ArrString[Local_s32SearchCounter] || tolower(Copy_s8ArrSearch[Local_s32Counter])== Copy_s8ArrString[Local_s32SearchCounter]  )
		{
			Local_u8CounterMatchedCh++;
			if(Local_u8CounterMatchedCh == strlen(Copy_s8ArrSearch) )
			{
				//pointer to first accurance
				Local_s8PtrResult=Copy_s8ArrString+(Local_s32SearchCounter-Local_u8CounterMatchedCh)+1;
			}
			else
			{
				
			}
		}
		else
		{
			//when go to ++ will increment and will be zero
			Local_s32Counter=-1;
			Local_u8CounterMatchedCh=0;
		}
	}
	
	return Local_s8PtrResult;
}
/*******************************************************/  
/*Comment!: Search in input file*/
extern s32 Replace_SearchInFile(u8 Copy_u8ArgumentCounter, s8 *Copy_ArrPtrArgv[] ) 
{
	FILE *Local_PtrFilefp;
	s32 Local_s32line_num = Replace_S32FirstLine;
	s8 Local_s8find_result = Replace_S32WordNotFound,Local_s8_IsThereTwoUtility=0;
	s8 Local_s8Arrtemp[Replace_S32MaxBufferToScan]={0};
	u8 Local_u8Result=Replace_S32Success,Local_u8FromWordCounter=Replace_S32IfOneParamter,Local_u8FileCounter=Replace_S32MinNumberArgument;//,Local_u8IsFileFound=Replace_S32FileFound;
	
	// if two paramter added
	if(strcmp(Copy_ArrPtrArgv[2],"-f") == 0 || strcmp(Copy_ArrPtrArgv[2],"-l") == 0 )
	{
		Local_u8FileCounter++;
		Local_u8FromWordCounter++;
		Local_s8_IsThereTwoUtility=1;
	}
	else;
	// to take all (.txt)argument from user 
	while(Copy_u8ArgumentCounter >= Local_u8FileCounter )
	{	
		//open file for Reading
		Local_PtrFilefp = fopen(Copy_ArrPtrArgv[Local_u8FileCounter-1], Replace_S32OpenFileForReading);
		// if file does not found
		if(Local_PtrFilefp == NULL)
		{
			//Local_u8IsFileFound=Replace_S32FileNotFound;
			printf("No Such File with name -> %s\n",Copy_ArrPtrArgv[Local_u8FileCounter-1]);
			Local_u8Result=Replace_S32FileNotFound;
			Local_u8Result=Replace_S32Error;
		}
		//found
		else
		{	
			// read from file(Local_PtrFilefp) and put it in Local_s8Arrtemp
			while( fgets(Local_s8Arrtemp, Replace_S32MaxBufferToScan, Local_PtrFilefp) != NULL) 
			{
				if(!Local_s8_IsThereTwoUtility )
				{
					switch(Copy_ArrPtrArgv[1][1])
					{
						case 'l':
						{
							FILE *fp2;
							s8 temp[] = "temp.txt", *ptr1, *Replace_S8PtrString;
							
							/* open temporary file in write mode */
							fp2 = fopen(temp, "w");

							/* error handling */
							if (!fp2) {
									printf("Unable to open temporary file!!\n");
									return Replace_S32Error;
							}
							if (Replace_SearchLastOccurance(Local_s8Arrtemp, Copy_ArrPtrArgv[Local_u8FromWordCounter]))
							{
								Replace_S8PtrString = Local_s8Arrtemp;
								while (ptr1 = Replace_SearchLastOccurance(Replace_S8PtrString, Copy_ArrPtrArgv[Local_u8FromWordCounter])) 
								{
									/*
									 * letters present before
									 * before the word to be replaced
									 */
									while (Replace_S8PtrString != ptr1) 
									{
										fputc(*Replace_S8PtrString, fp2);
										Replace_S8PtrString++;
									}
									/* skip the word to be replaced */
									ptr1 = ptr1 + strlen(Copy_ArrPtrArgv[Local_u8FromWordCounter]);
									//Replace word
									fprintf(fp2, "%s", Copy_ArrPtrArgv[Local_u8FromWordCounter+1]);
									Replace_S8PtrString = ptr1;
									//break;
								}
								/* characters present after the word to be replaced */
								while (*Replace_S8PtrString != '\0') 
								{
									fputc(*Replace_S8PtrString, fp2);
									Replace_S8PtrString++;
								}
								Local_s8find_result=Replace_S32WordFound;
							}
							/* close the opened files */
							fclose(Local_PtrFilefp);
							fclose(fp2);

							
							if(Local_s8find_result == Replace_S32WordFound) 
							{	
								/* remove the input file */
								remove(Copy_ArrPtrArgv[Local_u8FileCounter-1]);
								/* rename temporary file name to input file name */
								rename(temp, Copy_ArrPtrArgv[Local_u8FileCounter-1]);
							}
							else
							{
								/* remove the input file */
								remove(temp);
							}
						}
						break;
						
						case 'b':
						{
								FILE *source, *target;
								s8 tempBackName[50],ch;
								sprintf(tempBackName, "BackUp_%s", Copy_ArrPtrArgv[Local_u8FileCounter-1]);
								/* create backup file name to input file name */
								target = fopen(tempBackName, "w");
								if (!target) {
									printf("Unable to create back up file!!\n");
									return Replace_S32Error;
								}
								source = fopen(Copy_ArrPtrArgv[Local_u8FileCounter-1], "r");
								if (!source) {
									printf("Unable to open input file!!\n");
									return Replace_S32Error;
								}
								//copy files
								while( ( ch = fgetc(source) ) != EOF )
									fputc(ch, target);
								
								fclose(source);
								fclose(target);
						}
						case 'f'://not case senstive
						{
							FILE *fp2;
							s8 temp[] = "temp.txt", *ptr1, *Replace_S8PtrString;
							
							/* open temporary file in write mode */
							fp2 = fopen(temp, "w");

							/* error handling */
							if (!fp2) {
									printf("Unable to open temporary file!!\n");
									return Replace_S32Error;
							}
							if (strstr(Local_s8Arrtemp, Copy_ArrPtrArgv[Local_u8FromWordCounter])) 
							{
								Replace_S8PtrString = Local_s8Arrtemp;
								while (ptr1 = strstr(Replace_S8PtrString, Copy_ArrPtrArgv[Local_u8FromWordCounter])) 
								{
									/*
									 * letters present before
									 * before the word to be replaced
									 */
									while (Replace_S8PtrString != ptr1) 
									{
										fputc(*Replace_S8PtrString, fp2);
										Replace_S8PtrString++;
									}
									/* skip the word to be replaced */
									ptr1 = ptr1 + strlen(Copy_ArrPtrArgv[Local_u8FromWordCounter]);
									//Replace word
									fprintf(fp2, "%s", Copy_ArrPtrArgv[Local_u8FromWordCounter+1]);
									Replace_S8PtrString = ptr1;
									//beacause this first occurance
									break;
								}
								/* characters present after the word to be replaced */
								while (*Replace_S8PtrString != '\0') 
								{
									fputc(*Replace_S8PtrString, fp2);
									Replace_S8PtrString++;
								}
								Local_s8find_result=Replace_S32WordFound;
							}
							/* close the opened files */
							fclose(Local_PtrFilefp);
							fclose(fp2);

							
							if(Local_s8find_result == Replace_S32WordFound) 
							{	
								/* remove the input file */
								remove(Copy_ArrPtrArgv[Local_u8FileCounter-1]);
								/* rename temporary file name to input file name */
								rename(temp, Copy_ArrPtrArgv[Local_u8FileCounter-1]);
							}
							else
							{
								/* remove the input file */
								remove(temp);
							}
						}
						break;
						
						case 'i':
						{
							FILE *fp2;
							s8 temp[] = "temp.txt", *ptr1, *Replace_S8PtrString;
							
							/* open temporary file in write mode */
							fp2 = fopen(temp, "w");

							/* error handling */
							if (!fp2) {
									printf("Unable to open temporary file!!\n");
									return Replace_S32Error;
							}
							if (Replace_SearchWordInFile(Local_s8Arrtemp, Copy_ArrPtrArgv[Local_u8FromWordCounter]))
							{
								Replace_S8PtrString = Local_s8Arrtemp;
								while (ptr1 = Replace_SearchWordInFile(Replace_S8PtrString, Copy_ArrPtrArgv[Local_u8FromWordCounter])) 
								{
										/*
										 * letters present before
										 * before the word to be replaced
										 */
										//copy to temp file until first accurance
										while (Replace_S8PtrString != ptr1) 
										{
											fputc(*Replace_S8PtrString, fp2);
											Replace_S8PtrString++;
										}
										/* skip the word to be replaced */
										ptr1 = ptr1 + strlen(Copy_ArrPtrArgv[Local_u8FromWordCounter]);
										//Replace word
										fprintf(fp2, "%s", Copy_ArrPtrArgv[Local_u8FromWordCounter+1]);
										Replace_S8PtrString = ptr1;
								}

								/* characters present after the word to be replaced */
								while (*Replace_S8PtrString != '\0') 
								{
										fputc(*Replace_S8PtrString, fp2);
										Replace_S8PtrString++;
								}
								Local_s8find_result=Replace_S32WordFound;
							}
							
							/* close the opened files */
							fclose(Local_PtrFilefp);
							fclose(fp2);

							if(Local_s8find_result == Replace_S32WordFound) 
							{	
								/* remove the input file */
								remove(Copy_ArrPtrArgv[Local_u8FileCounter-1]);
								/* rename temporary file name to input file name */
								rename(temp, Copy_ArrPtrArgv[Local_u8FileCounter-1]);
							}
							else
							{
								/* remove the input file */
								remove(temp);
							}
						}
						break;
						
						default:
						Local_u8Result=Replace_S32Error;
						break;
					}
				}
				else 
				{
					if(Copy_ArrPtrArgv[1][1]=='b'&&Copy_ArrPtrArgv[2][1]=='f')
					{
						{
								FILE *source, *target;
								s8 tempBackName[50],ch;
								sprintf(tempBackName, "BackUp_%s", Copy_ArrPtrArgv[Local_u8FileCounter-1]);
								/* create backup file name to input file name */
								target = fopen(tempBackName, "w");
								if (!target) {
									printf("Unable to create back up file!!\n");
									return Replace_S32Error;
								}
								source = fopen(Copy_ArrPtrArgv[Local_u8FileCounter-1], "r");
								if (!source) {
									printf("Unable to open input file!!\n");
									return Replace_S32Error;
								}
								//copy files
								while( ( ch = fgetc(source) ) != EOF )
									fputc(ch, target);
								
								fclose(source);
								fclose(target);
						}
						//case f
						{
							FILE *fp2;
							s8 temp[] = "temp.txt", *ptr1, *Replace_S8PtrString;
							
							/* open temporary file in write mode */
							fp2 = fopen(temp, "w");

							/* error handling */
							if (!fp2) {
									printf("Unable to open temporary file!!\n");
									return Replace_S32Error;
							}
							if (strstr(Local_s8Arrtemp, Copy_ArrPtrArgv[Local_u8FromWordCounter])) 
							{
								Replace_S8PtrString = Local_s8Arrtemp;
								while (ptr1 = strstr(Replace_S8PtrString, Copy_ArrPtrArgv[Local_u8FromWordCounter])) 
								{
									/*
									 * letters present before
									 * before the word to be replaced
									 */
									while (Replace_S8PtrString != ptr1) 
									{
										fputc(*Replace_S8PtrString, fp2);
										Replace_S8PtrString++;
									}
									/* skip the word to be replaced */
									ptr1 = ptr1 + strlen(Copy_ArrPtrArgv[Local_u8FromWordCounter]);
									//Replace word
									fprintf(fp2, "%s", Copy_ArrPtrArgv[Local_u8FromWordCounter+1]);
									Replace_S8PtrString = ptr1;
									//beacause this first occurance
									break;
								}
								/* characters present after the word to be replaced */
								while (*Replace_S8PtrString != '\0') 
								{
									fputc(*Replace_S8PtrString, fp2);
									Replace_S8PtrString++;
								}
								Local_s8find_result=Replace_S32WordFound;
							}
							/* close the opened files */
							fclose(Local_PtrFilefp);
							fclose(fp2);

							
							if(Local_s8find_result == Replace_S32WordFound) 
							{	
								/* remove the input file */
								remove(Copy_ArrPtrArgv[Local_u8FileCounter-1]);
								/* rename temporary file name to input file name */
								rename(temp, Copy_ArrPtrArgv[Local_u8FileCounter-1]);
							}
							else
							{
								/* remove the input file */
								remove(temp);
							}
						}
					}
					else if(Copy_ArrPtrArgv[1][1]=='f'&&Copy_ArrPtrArgv[2][1]=='l')
					{
						//case f
						{
							FILE *fp2;
							s8 temp[] = "temp.txt", *ptr1, *Replace_S8PtrString;
							
							/* open temporary file in write mode */
							fp2 = fopen(temp, "w");

							/* error handling */
							if (!fp2) {
									printf("Unable to open temporary file!!\n");
									return Replace_S32Error;
							}
							if (strstr(Local_s8Arrtemp, Copy_ArrPtrArgv[Local_u8FromWordCounter])) 
							{
								Replace_S8PtrString = Local_s8Arrtemp;
								while (ptr1 = strstr(Replace_S8PtrString, Copy_ArrPtrArgv[Local_u8FromWordCounter])) 
								{
									/*
									 * letters present before
									 * before the word to be replaced
									 */
									while (Replace_S8PtrString != ptr1) 
									{
										fputc(*Replace_S8PtrString, fp2);
										Replace_S8PtrString++;
									}
									/* skip the word to be replaced */
									ptr1 = ptr1 + strlen(Copy_ArrPtrArgv[Local_u8FromWordCounter]);
									//Replace word
									fprintf(fp2, "%s", Copy_ArrPtrArgv[Local_u8FromWordCounter+1]);
									Replace_S8PtrString = ptr1;
									//beacause this first occurance
									break;
								}
								/* characters present after the word to be replaced */
								while (*Replace_S8PtrString != '\0') 
								{
									fputc(*Replace_S8PtrString, fp2);
									Replace_S8PtrString++;
								}
								Local_s8find_result=Replace_S32WordFound;
							}
							/* close the opened files */
							fclose(Local_PtrFilefp);
							fclose(fp2);

							
							if(Local_s8find_result == Replace_S32WordFound) 
							{	
								/* remove the input file */
								remove(Copy_ArrPtrArgv[Local_u8FileCounter-1]);
								/* rename temporary file name to input file name */
								rename(temp, Copy_ArrPtrArgv[Local_u8FileCounter-1]);
							}
							else
							{
								/* remove the input file */
								remove(temp);
							}
						}
						//case 'l'
						{
							FILE *fp2;
							s8 temp[] = "temp.txt", *ptr1, *Replace_S8PtrString;
							
							/* open temporary file in write mode */
							fp2 = fopen(temp, "w");

							/* error handling */
							if (!fp2) {
									printf("Unable to open temporary file!!\n");
									return Replace_S32Error;
							}
							if (Replace_SearchLastOccurance(Local_s8Arrtemp, Copy_ArrPtrArgv[Local_u8FromWordCounter]))
							{
								Replace_S8PtrString = Local_s8Arrtemp;
								while (ptr1 = Replace_SearchLastOccurance(Replace_S8PtrString, Copy_ArrPtrArgv[Local_u8FromWordCounter])) 
								{
									/*
									 * letters present before
									 * before the word to be replaced
									 */
									while (Replace_S8PtrString != ptr1) 
									{
										fputc(*Replace_S8PtrString, fp2);
										Replace_S8PtrString++;
									}
									/* skip the word to be replaced */
									ptr1 = ptr1 + strlen(Copy_ArrPtrArgv[Local_u8FromWordCounter]);
									//Replace word
									fprintf(fp2, "%s", Copy_ArrPtrArgv[Local_u8FromWordCounter+1]);
									Replace_S8PtrString = ptr1;
									//break;
								}
								/* characters present after the word to be replaced */
								while (*Replace_S8PtrString != '\0') 
								{
									fputc(*Replace_S8PtrString, fp2);
									Replace_S8PtrString++;
								}
								Local_s8find_result=Replace_S32WordFound;
							}
							/* close the opened files */
							fclose(Local_PtrFilefp);
							fclose(fp2);

							
							if(Local_s8find_result == Replace_S32WordFound) 
							{	
								/* remove the input file */
								remove(Copy_ArrPtrArgv[Local_u8FileCounter-1]);
								/* rename temporary file name to input file name */
								rename(temp, Copy_ArrPtrArgv[Local_u8FileCounter-1]);
							}
							else
							{
								/* remove the input file */
								remove(temp);
							}
						}
					}
					else
					{
						Local_u8Result=Replace_S32Error;
					}
				}
				//Local_s32line_num++;
			}

			if(Local_s8find_result == Replace_S32WordNotFound) 
			{
				printf("\nSorry, couldn't find a match in file name->%s \n",Copy_ArrPtrArgv[Local_u8FileCounter-1] );
				Local_u8Result=Replace_S32Error;
			}
			else;
			//Close the file if still open.
			if(Local_PtrFilefp) 
			{
				fclose(Local_PtrFilefp);
			}
			else;
			
		}
		// add one to know did we take all argument from user
		Local_u8FileCounter++;
		
	}
	return(Local_u8Result);
}
/*******************************************************/  
/*******************************************************/  
/*******************************************************/  
/*******************************************************/  
/*******************************************************/  
/*******************************************************/  

/*
 return_type Replace_(return_type+descriptive_name )  (INPUTS) 
{  
return variable;  
}   */
/*  
extern return_type Replace_(return_type+descriptive_name )  (INPUTS) 
{  
return variable;  
}   */
/*  
extern return_type Replace_(return_type+descriptive_name )  (INPUTS) 
{  
return variable;  
}   */
/*  
extern return_type Replace_(return_type+descriptive_name )  (INPUTS) 
{  
return variable;  
}   */
/*  
extern return_type Replace_(return_type+descriptive_name )  (INPUTS) 
{  
return variable;  
}   */
/*  
extern return_type Replace_(return_type+descriptive_name )  (INPUTS) 
{  
return variable;  
}   */
/*  
extern return_type Replace_(return_type+descriptive_name )  (INPUTS) 
{  
return variable;  
}   */
/*  
extern return_type Replace_(return_type+descriptive_name )  (INPUTS) 
{  
return variable;  
}   */
/*  
extern return_type Replace_(return_type+descriptive_name )  (INPUTS) 
{  
return variable;  
}   */
/*  
extern return_type Replace_(return_type+descriptive_name )  (INPUTS) 
{  
return variable;  
}   */
/*  
static return_type Replace_(return_type+descriptive_name )  (INPUTS) 
{  
return variable;  
}  */
/*  
static return_type Replace_(return_type+descriptive_name )  (INPUTS) 
{  
return variable;  
}  */
/*  
static return_type Replace_(return_type+descriptive_name )  (INPUTS) 
{  
return variable;  
}  */
/*  
static return_type Replace_(return_type+descriptive_name )  (INPUTS) 
{  
return variable;  
}*/  
/*  
static return_type Replace_(return_type+descriptive_name )  (INPUTS) 
{  
return variable;  
}  
*/
/*  
static return_type Replace_(return_type+descriptive_name )  (INPUTS) 
{  
return variable;  
}  
*/  
