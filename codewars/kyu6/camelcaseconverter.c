#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

//returned buffer should be dynamically allocated and will be freed by a caller
char* solution(const char *camelCase) {
  
  int wordSize = strlen(camelCase);
  int resultSize= wordSize+1;
  char* result = NULL;
  result =(char*)malloc(resultSize);
  
  int i, j = 0;
  for(i=0;i<wordSize;i++){
    if(isupper(camelCase[i+1])){
      resultSize++;
      result = realloc(result,resultSize*sizeof(char));
      result[j]=camelCase[i];
      j++;
      result[j]=' ';
    }
    else{ result[j]=camelCase[i]; }
    j++;
  }
  result[resultSize] = '\0';
  printf("wordsize = %d, resultSize = %d word = %s\n",wordSize,resultSize, result);
  return result;
}

int main() {
    const char* camelCase = "camelCaseString";
    char* converted = solution(camelCase);
    if (converted != NULL) {
        printf("Converted: %s\n", converted);
        free(converted); // Free dynamically allocated memory
    }
    return 0;
}
