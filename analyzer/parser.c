#include "./include/parser.h"

Cerrors c_parser_start(TokenList* list, const char *source){
  char lex[256];
  int lexi = 0;
  int i = 0;
  int line = 1;

  while(true){
    while(source[i] != ' ' && source[i] != '\n' && source[i] != '\0' && source[i] != '\t' && source[i] != '\r' && source[i] != source[i] != '\v' && source[i] != '\f'){
      lex[lexi++] = source[i++];
    }

    lex[lexi] = '\0';

    /*CHECKS*/
    if(c_check_semicolon(source) == NO_ERROR){
      printf("Semicolons checked\n");
    }



    if(source[i] == '\n'){
      line++;
    }
    else if(source[i] == '\0'){
      break;
    }

    lexi = 0;
    i++;
  }

  return NO_ERROR;
}



Cerrors c_check_semicolon(const char *buf){

  printf("SEMICOLON CHECKING\n");

  return NO_ERROR;
}
