/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE190_Integer_Overflow__unsigned_int_rand_square_22a.c
Label Definition File: CWE190_Integer_Overflow.label.xml
Template File: sources-sinks-22a.tmpl.c
*/
/*
 * @description
 * CWE: 190 Integer Overflow
 * BadSource: rand Set data to result of rand()
 * GoodSource: Set data to a small, non-zero number (two)
 * Sinks: square
 *    GoodSink: Ensure there will not be an overflow before squaring data
 *    BadSink : Square data, which can lead to overflow
 * Flow Variant: 22 Control flow: Flow controlled by value of a global variable. Sink functions are in a separate file from sources.
 *
 * */

#include "std_testcase.h"

#ifndef OMITBAD

/* The global variable below is used to drive control flow in the sink function */
int CWE190_Integer_Overflow__unsigned_int_rand_square_22_badGlobal = 0;

void CWE190_Integer_Overflow__unsigned_int_rand_square_22_badSink(unsigned int data);

void CWE190_Integer_Overflow__unsigned_int_rand_square_22_bad()
{
    unsigned int data;
    data = 0;
    /* POTENTIAL FLAW: Use a random value */
    data = (unsigned int)RAND32();
    CWE190_Integer_Overflow__unsigned_int_rand_square_22_badGlobal = 1; /* true */
    CWE190_Integer_Overflow__unsigned_int_rand_square_22_badSink(data);
}

#endif /* OMITBAD */


/* Below is the main(). It is only used when building this testcase on
   its own for testing or for building a binary to use in testing binary
   analysis tools. It is not used when compiling all the testcases as one
   application, which is how source code analysis tools are tested. */

#ifdef INCLUDEMAIN

int main(int argc, char * argv[])
{
    /* seed randomness */
    srand( (unsigned)time(NULL) );
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE190_Integer_Overflow__unsigned_int_rand_square_22_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
