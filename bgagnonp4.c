/*------------------------------------------------------------------------------
Program file: bgagnonp4.c
Author:       Brett Gagnon
Date:         3/24/2019
Assignment:   Program #4
Objective:    Write a C program that prompts the user to enter a line of text (up to 50 characters). It
should then convert the text entered to uppercase letters and then to lowercase letters.
Your program should use a character array: text[51] to store text. It should use function
safer_gets() to prompt the user for the line of text.
Your program must use pointer notation and pointer math (i.e. no array index
notation other than in the declaration section).
              
------------------------------------------------------------------------------*/

#include <stdio.h>
#include <ctype.h>

/* Prototype for safer_gets */
/*--------------------------*/

void safer_gets (char array[ ], int max_chars);


int main(void)
{

/* Declare variables */
/*----------------------------------------------------------------------------*/

	char	text[51];
 	char	*text_ptr;

/* Prompt user for line of text */
/*----------------------------------------------------------------------------*/

	printf ("\nEnter a line of text (up to 50 characters):\n");
	safer_gets(text,50);
	fflush(stdin);
 

/* Convert and display the text in uppercase characters. */
/*----------------------------------------------------------------------------*/

    printf ("\nThe line of text in uppercase is:\n");

   	text_ptr = text;
    while (*text_ptr != '\0')  
	{     
		putchar( toupper(*text_ptr++) );
	}
         
/* Convert and display the text in uppercase characters. */
/*----------------------------------------------------------------------------*/

    printf ("\n\nThe line of text in lowercase is:\n");

  	text_ptr = text;
    while ( *text_ptr != '\0' )
    {
		putchar( tolower(*text_ptr++) );
    }
    
	putchar('\n');
    
    //getchar(); /* To pause output */


} /* End main */


/* Function safer_gets */
/*----------------------------------------------------------------------------*/
			
void safer_gets (char array[], int max_chars)
{
  /* Declare variables. */
  /* ------------------ */

  int i;

  /* Read info from input buffer, character by character,   */
  /* up until the maximum number of possible characters.    */
  /* ------------------------------------------------------ */

  for (i = 0; i < max_chars; i++)
  {
     array[i] = getchar();


     /* If "this" character is the carriage return, exit loop */
     /* ----------------------------------------------------- */

     if (array[i] == '\n')
        break;
  
   } /* end for */

   /* If we have pulled out the most we can based on the size of array, */
   /* and, if there are more chars in the input buffer,                 */
   /* clear out the remaining chars in the buffer.                      */
   /* This is equivalent to the fflush() function.                      */
   /* ----------------------------------------------------------------  */

   if (i == max_chars )

     if (array[i] != '\n')
       while (getchar() != '\n');

   /* At this point, i is pointing to the element after the last character */
   /* in the string. Terminate the string with the null terminator.        */
   /* -------------------------------------------------------------------- */

   array[i] = '\0';
 

} /* end safer_gets */
