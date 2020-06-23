#include <iostream>
/* NOTE - eventually this file will be automatically updated using a Perl script that understand
 * the naming of test case files, functions, and namespaces.
 */

#include <time.h>   /* for time() */
#include <stdlib.h> /* for srand() */

#include "std_testcase.h"
#include "testcases.h"


int main(int argc, char * argv[]) {

    /* seed randomness */

    srand( (unsigned)time(NULL) );

    globalArgc = argc;
    globalArgv = argv;


    /* Calling C good functions */
    /* BEGIN-AUTOGENERATED-C-GOOD-FUNCTION-CALLS */
    printLine("Calling CWE190_Integer_Overflow__char_max_square_67_good();");
    CWE190_Integer_Overflow__char_max_square_67_good();


    return 0;

}