#include "./include/analyzer.h"

Token* token_create(int type, int data, int line){
    Token* tok = (Token*)malloc(sizeof(Token));
    tok->type = type;
    tok->data = data;
    tok->line = line;

    return tok;
}

void token_destroy(Token *tok){
    free(tok);
}

void token_list_create(TokenList *list, int size){
    list->data = (Token**)malloc(sizeof(Token*) * size);
    list->ptr = 0;
    list->size = size;
}

void token_list_add(TokenList* list, Token* tok){

    if(list->ptr >= list->size){
        list->size *= 2;
        list->data = (Token**) realloc(list->data, sizeof(Token*) * list->size);
    }

    list->data[list->ptr++] = tok;
}

Token* token_list_get(TokenList* list, int index){
    return list->data[index];
}

void token_list_destroy(TokenList* list){
    for(int i = 0; i < list->ptr; i++){
        free(list->data[i]);
    }

    free(list->data);
}




/*C*/

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




    if(source[i] == '\n'){
      if(c_check_semicolon(source, line, i) == NO_ERROR){
        printf("Semicolons checked\n");
      }
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



Cerrors c_check_semicolon(const char *buf, const int line, int i){


  if(buf[i] == '}' || buf[i] == '>' || buf[i] == ':'){
    return NO_ERROR;
  }
  else if(buf[i] != ';'){
    printf("\nERROR: No semicolon at line %d\n", line);
    return SYNTAX_ERROR;
  }


  return NO_ERROR;
}
