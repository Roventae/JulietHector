/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE190_Integer_Overflow__char_fscanf_multiply_15.c
Label Definition File: CWE190_Integer_Overflow.label.xml
Template File: sources-sinks-15.tmpl.c
*/
/*
 * @description
 * CWE: 190 Integer Overflow
 * BadSource: fscanf Read data from the console using fscanf()
 * GoodSource: Set data to a small, non-zero number (two)
 * Sinks: multiply
 *    GoodSink: Ensure there will not be an overflow before multiplying data by 2
 *    BadSink : If data is positive, multiply by 2, which can cause an overflow
 * Flow Variant: 15 Control flow: switch(6) and switch(7)
 *
 * */

#include "std_testcase.h"

#ifndef OMITBAD

void CWE190_Integer_Overflow__char_fscanf_multiply_15_bad()
{
    char data;
    data = ' ';
    switch(6)
    {
    case 6:
        /* POTENTIAL FLAW: Use a value input from the console */
        fscanf (stdin, "%c", &data);
        break;
    default:
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        printLine("Benign, fixed string");
        break;
    }
    switch(7)
    {
    case 7:
        if(data > 0) /* ensure we won't have an underflow */
        {
            /* POTENTIAL FLAW: if (data*2) > CHAR_MAX, this will overflow */
            char result = data * 2;
            printHexCharLine(result);
        }
        break;
    default:
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        printLine("Benign, fixed string");
        break;
    }
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
    CWE190_Integer_Overflow__char_fscanf_multiply_15_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
