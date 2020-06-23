/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE190_Integer_Overflow__int64_t_rand_multiply_65a.c
Label Definition File: CWE190_Integer_Overflow.label.xml
Template File: sources-sinks-65a.tmpl.c
*/
/*
 * @description
 * CWE: 190 Integer Overflow
 * BadSource: rand Set data to result of rand()
 * GoodSource: Set data to a small, non-zero number (two)
 * Sinks: multiply
 *    GoodSink: Ensure there will not be an overflow before multiplying data by 2
 *    BadSink : If data is positive, multiply by 2, which can cause an overflow
 * Flow Variant: 65 Data/control flow: data passed as an argument from one function to a function in a different source file called via a function pointer
 *
 * */

#include "std_testcase.h"

#ifndef OMITBAD

/* bad function declaration */
void CWE190_Integer_Overflow__int64_t_rand_multiply_65b_badSink(int64_t data);

void CWE190_Integer_Overflow__int64_t_rand_multiply_65_bad()
{
    int64_t data;
    /* define a function pointer */
    void (*funcPtr) (int64_t) = CWE190_Integer_Overflow__int64_t_rand_multiply_65b_badSink;
    data = 0LL;
    /* POTENTIAL FLAW: Use a random value */
    data = (int64_t)RAND64();
    /* use the function pointer */
    funcPtr(data);
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
    CWE190_Integer_Overflow__int64_t_rand_multiply_65_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
