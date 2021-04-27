#ifndef PARSER_H
#define PARSER_H

#include "../../include/keystance.h"
#include "./token.h"
#include "./util.h"
#include "../analyze.h"
#include "../../errors/C/Cerrors.h"



/*C*/
Cerrors c_parser_start(TokenList *list, const char *source);
Cerrors c_check_semicolon(const char *buf);


#endif //PARSER_H
