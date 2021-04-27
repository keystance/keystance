#ifndef ANALYZE_H
#define ANALYZE_H


#include "./include/parser.h"
#include "./include/token.h"
#include "./include/util.h"
#include "../errors/C/Cerrors.h"
#include "../include/keystance.h"


enum _AnalyzeStatus{
  ANALYZE_SUCCES,
  ANALYZE_FAILURE,
};
typedef enum _AnalyzeStatus AnalyzeStatus;

AnalyzeStatus analyze_file(const char *path);

#endif //ANALYZE_H
