#ifndef ANALYZE_H
#define ANALYZE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "./include/parser.h"
#include "./include/token.h"
#include "./include/util.h"
#include "../errors/C/Cerrors.h"


enum _AnalyzeStatus{
  ANALYZE_SUCCES,
  ANALYZE_FAILURE,
};
typedef enum _AnalyzeStatus AnalyzeStatus;

AnalyzeStatus analyze_file(const char *path);

#endif //ANALYZE_H
