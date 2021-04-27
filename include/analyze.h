#ifndef ANALYZE_H
#define ANALYZE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*#include "./parser.h"
#include "./token.h"
*/

enum _AnalyzeStatus{
  ANALYZE_SUCCES,
  ANALYZE_FAILURE,
};
typedef enum _AnalyzeStatus AnalyzeStatus;

AnalyzeStatus analyze_file(const char *path);

#endif //ANALYZE_H
