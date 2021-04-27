#ifndef PARSER_H
#define PARSER_H

#include "../../include/keystance.h"

enum _TokenType{
  KEYWORD,
  DATA_TYPE,
  COMMENT,
  NUMBER,
  FUNCTION,
  SEMICOLON,
};
typedef enum _TokenType TokenType;

#endif //PARSER_H
