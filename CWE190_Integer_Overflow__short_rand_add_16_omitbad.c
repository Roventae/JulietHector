/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE190_Integer_Overflow__short_rand_add_16.c
Label Definition File: CWE190_Integer_Overflow.label.xml
Template File: sources-sinks-16.tmpl.c
*/
/*
 * @description
 * CWE: 190 Integer Overflow
 * BadSource: rand Set data to result of rand()
 * GoodSource: Set data to a small, non-zero number (two)
 * Sinks: add
 *    GoodSink: Ensure there will not be an overflow before adding 1 to data
 *    BadSink : Add 1 to data, which can cause an overflow
 * Flow Variant: 16 Control flow: while(1)
 *
 * */

#include "std_testcase.h"


#ifndef OMITGOOD

/* goodB2G() - use badsource and goodsink by changing the sinks in the second while statement */
static void goodB2G()
{
    short data;
    data = 0;
    while(1)
    {
        /* POTENTIAL FLAW: Use a random value */
        data = (short)RAND32();
        break;
    }
    while(1)
    {
        /* FIX: Add a check to prevent an overflow from occurring */
        if (data < SHRT_MAX)
        {
            short result = data + 1;
            printIntLine(result);
        }
        else
        {
            printLine("data value is too large to perform arithmetic safely.");
        }
        break;
    }
}

/* goodG2B() - use goodsource and badsink by changing the sources in the first while statement */
static void goodG2B()
{
    short data;
    data = 0;
    while(1)
    {
        /* FIX: Use a small, non-zero value that will not cause an overflow in the sinks */
        data = 2;
        break;
    }
    while(1)
    {
        {
            /* POTENTIAL FLAW: Adding 1 to data could cause an overflow */
            short result = data + 1;
            printIntLine(result);
        }
        break;
    }
}

void CWE190_Integer_Overflow__short_rand_add_16_good()
{
    goodB2G();
    goodG2B();
}

#endif /* OMITGOOD */

/* Below is the main(). It is only used when building this testcase on
   its own for testing or for building a binary to use in testing binary
   analysis tools. It is not used when compiling all the testcases as one
   application, which is how source code analysis tools are tested. */

#ifdef INCLUDEMAIN

int main(int argc, char * argv[])
{
    /* seed randomness */
    srand( (unsigned)time(NULL) );
#ifndef OMITGOOD
    printLine("Calling good()...");
    CWE190_Integer_Overflow__short_rand_add_16_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
    return 0;
}

#endif
