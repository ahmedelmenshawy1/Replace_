#ifndef _Replace_INTERFACE_H_ 
#define _Replace_INTERFACE_H_  
  
/*******************************************************/  
/***************** Public Definitions ******************/  
/*******************************************************/  
  
/*Comment!: */ 
/*
#define  
#define  
#define  
#define  
#define  
#define  
#define  
#define  
#define  
#define  
  */
  
/*******************************************************/  
/*****************  Public Functions  ******************/  
/*******************************************************/  
  
  

/*Comment!: If User Do not know how to use program*/
extern s8 Replace_VoidWordtNotFound(s8 *Copy_s8filename[]) ;

/*******************************************************/  
/*Comment!: Search in input file*/
extern s32 Replace_SearchInFile(u8 Copy_u8ArgumentCounter, s8 *Copy_ArrPtrArgv[] ) ;
/*******************************************************/  

/*Comment!: Search for word in file*/
extern s8* Replace_SearchWordInFile(s8 *Copy_s8ArrString, s8 *Copy_s8ArrSearch ) ;
/*******************************************************/  
/*Comment!: Get Char FromFile*/
extern s8 Replace_s8GetCharInFile(FILE *Copy_PtrFilefp);
/*******************************************************/  
//*Comment!: Search for word Last Occurance in file*/
extern s8 * Replace_SearchLastOccurance(s8 *Copy_s8ArrString, s8 *Copy_s8ArrSearch ) ;
/*******************************************************/  

/*Comment!:   
extern return_type Replace_(return_type+descriptive_name )  (INPUTS); 
  */
/*Comment!:  
extern return_type Replace_(return_type+descriptive_name )  (INPUTS); 
*/   
/*Comment!:   
extern return_type Replace_(return_type+descriptive_name )  (INPUTS); 
  */
/*Comment!:   
extern return_type Replace_(return_type+descriptive_name )  (INPUTS); 
  */
/*Comment!:   
extern return_type Replace_(return_type+descriptive_name )  (INPUTS); 
  */
/*Comment!:   
extern return_type Replace_(return_type+descriptive_name )  (INPUTS); 
  */
/*Comment!:   
extern return_type Replace_(return_type+descriptive_name )  (INPUTS); 
  */
/*Comment!:   
extern return_type Replace_(return_type+descriptive_name )  (INPUTS); 
  */
#endif  
