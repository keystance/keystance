#ifndef PARSER_H
#define PARSER_H

#include "./token.h"
#include "./util.h"
#include "../../errors/C/Cerrors.h"
#include "../../keywords/C/keywords.h"


/*C*/
Cerrors c_parser_start(TokenList *list, const char *source);
Cerrors c_check_semicolon(const char *buf);


#endif //PARSER_H
