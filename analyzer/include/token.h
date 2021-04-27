#ifndef TOKEN_H
#define TOKEN_H

#include "../../include/keystance.h"



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

struct _Token{
  int data;
  int type;
  int line;
};
typedef struct _Token Token;

Token *token_create(int type, int data, int line);
void token_destory(Token *tok);

struct _TokenList{
  Token **data;
  int ptr;
  int size;
};
typedef struct _TokenList TokenList;

void token_list_create(TokenList** list, int size);
void token_list_add(TokenList *list, Token *tok);
Token* token_list_get(TokenList* list, int index);
void token_list_destroy(TokenList* list);


#endif //TOKEN_H
