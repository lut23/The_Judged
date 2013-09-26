#include <stdlib.h>
#include<string.h>

#include "disemvowel.h"

char* disemvowel(char* str) { 
  int vcount=0;
  int i =0;
  char* constr ='';
  int skipped=0;
  for(i; i < strlen(str); i++){
    if(str[i]=='a'||str[i]=='A'||str[i]=='e'||str[i]=='E'||str[i]=='I'||str[i]=='i'||str[i]=='o'||str[i]=='O'||str[i]=='u'||str[i]=='U'){
      vcount++;
    }
  }
constr = (char*)calloc(strlen(str)-vcount, sizeof(char));

  for(i=0; i < strlen(str); i++){
    if(str[i]=='a'||str[i]=='A'||str[i]=='e'||str[i]=='E'||str[i]=='I'||str[i]=='i'||str[i]=='o'||str[i]=='O'||str[i]=='u'||str[i]=='U'){
      skipped++;
    }else{
      constr[i-skipped]=str[i];
  }
   
  
  return constr;
}
