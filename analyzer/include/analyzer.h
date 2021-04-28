#ifndef ANALYZER_H
#define ANALYZER_H



/*TOKENS*/
#include "./util.h"
#include "../analyze.h"
#include "../../errors/C/Cerrors.h"
#include "../../keywords/C/keywords.h"
#include "../../include/keystance.h"

struct _Token{
  int data;
  int type;
  int line;
};
typedef struct _Token Token;

struct _TokenList{
  Token **data;
  int ptr;
  int size;
};
typedef struct _TokenList TokenList;

enum _TokenType{
  KEYWORD,
  DATA_TYPE,
  COMMENT,
  NUMBER,
  FUNCTION,
  SEMICOLON,
  OP,
};
typedef enum _TokenType TokenType;


/*enum _TokenOp{
  PLUS,
  MINUS,
  MULTIPLY,
  DIVIDE,
  MODULUS
};
typedef enum _TokenOP TokenOP;
*/



Token *token_create(int type, int data, int line);
void token_destory(Token *tok);



void token_list_create(TokenList* list, int size);
void token_list_add(TokenList *list, Token *tok);
Token* token_list_get(TokenList* list, int index);
void token_list_destroy(TokenList* list);

/*TOKENS END*/




/*C*/
Cerrors c_parser_start(TokenList *list, const char *source);
Cerrors c_check_semicolon(const char *buf, const int line, int i);

/*C END*/

#endif //ANALYZER_H
