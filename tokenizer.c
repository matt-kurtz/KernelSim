#include <stdlib.h>
#include <stdio.h>
#include "tokenizer.h"

//Declarations are made in the "tokenizer.h" file

/*int makearg(char *s, char ***args);
int LengthOfString(char *s);
int NumOfWords(char *s);


int main() {
   char *s, **argsv;
   printf("Gimme an input: ");
   fgets(s, 256, stdin);
   int argc = makearg(s, &argsv);
   
   if (argc == -1) {
      printf("Error. Input failed. Rerun the program again.\n");
   }

   //printf("We made it out of the function!\n");

   printf("There are %i word(s) in that line:\n", argc);
   for (int i = 0; i < argc; i++) {
      printf("%s\n", argsv[i]);
      free(argsv[i]); // make sure we deallocate what we're using
   }
   free(argsv); // final deallocate
   return 0;

}*/

int makearg(char *s, char ***args) {
   //printf("Array passed in is: %s\n", s);

   //int stringLength = LengthOfString(s); 
   int words = NumOfWords(s);
   int start = 0;
   int end = 0;
   int length_of_word = 0;

   if (LengthOfString(s) > 256) {
      printf("Error, too big of an input.\n");
      return -1;
   }
   //printf("Num of Words: %i\n", words); // used to make sure we had the correct amount of words
   *args = (char**)malloc(words*sizeof(char *)); // allocate for every word we have
   if (*args == NULL) {
      printf("Allocation failed.\n");
      return -1;
   }

   while (s[end] == ' ') // This takes care of spaces before our line of commands
      end++;
   //printf("Location of first word in string is: %i\n", end); // used to make sure we're starting in the right place

   start = end; // start is at the beginning of the first word

   // incrementing through the words and placing each character into it's appropriate word
   for (int i = 0; i < words; i++) {
      int wordSize = 0;
      while (s[end] == ' ') // skip the spaces the user might put in the input
         end++;

      start = end; // have start where there's not space.

      while (s[end] != ' ' && s[end] != '\0') { // keep incrementing until we find the end of the word/string
         end++;
      }
      /*if (s[end] == '\0') // if end is at end of string, decrement end by 1
         end--; */
      wordSize = end-start; // created to make create the size of the worth between the indices of end and start

      //printf("Word Size: %i\n", wordSize); // make sure we have the right size of the word for allocation

      (*args)[i] = (char *)malloc((wordSize + 1) * sizeof(char));

      // this goes through the word and assigns to the appropriate memory location each character of the word
      int j = 0;
      while (start < end) {
      (*args)[i][j] = s[start];
         start++;
         j++;
      }
      (*args)[i][j] = '\0';
      end++;
      start = end;
   }


   return words;

}
// Calculates length of a given string
int LengthOfString(char *s) {
   int count;
   while (*s != '\0') {
      count++;
      s++;
   }
   return count;
}
// Calculates number of words in a given string
int NumOfWords(char *s) {
   int num = 0;
   int InWord = 0; // used to make sure we're actually in the word and not counting spaces
   while (*s != '\0') {
      if (*s == ' ') {
         if (InWord){
            num++;
            InWord = 0;
         }
      } else {
         InWord = 1;
      }
      s++;
   }
   if (InWord) {
      num++;
   }

   return num;
}
