/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE190_Integer_Overflow__int_max_add_12.c
Label Definition File: CWE190_Integer_Overflow__int.label.xml
Template File: sources-sinks-12.tmpl.c
*/
/*
 * @description
 * CWE: 190 Integer Overflow
 * BadSource: max Set data to the max value for int
 * GoodSource: Set data to a small, non-zero number (two)
 * Sinks: add
 *    GoodSink: Ensure there will not be an overflow before adding 1 to data
 *    BadSink : Add 1 to data, which can cause an overflow
 * Flow Variant: 12 Control flow: if(globalReturnsTrueOrFalse())
 *
 * */

#include "std_testcase.h"


#ifndef OMITGOOD

/* goodB2G() - use badsource and goodsink by changing the first "if" so that
   both branches use the BadSource and the second "if" so that both branches
   use the GoodSink */
static void goodB2G()
{
    int data;
    /* Initialize data */
    data = 0;
    if(globalReturnsTrueOrFalse())
    {
        /* POTENTIAL FLAW: Use the maximum value for this type */
        data = INT_MAX;
    }
    else
    {
        /* POTENTIAL FLAW: Use the maximum value for this type */
        data = INT_MAX;
    }
    if(globalReturnsTrueOrFalse())
    {
        /* FIX: Add a check to prevent an overflow from occurring */
        if (data < INT_MAX)
        {
            int result = data + 1;
            printIntLine(result);
        }
        else
        {
            printLine("data value is too large to perform arithmetic safely.");
        }
    }
    else
    {
        /* FIX: Add a check to prevent an overflow from occurring */
        if (data < INT_MAX)
        {
            int result = data + 1;
            printIntLine(result);
        }
        else
        {
            printLine("data value is too large to perform arithmetic safely.");
        }
    }
}

/* goodG2B() - use goodsource and badsink by changing the first "if" so that
   both branches use the GoodSource and the second "if" so that both branches
   use the BadSink */
static void goodG2B()
{
    int data;
    /* Initialize data */
    data = 0;
    if(globalReturnsTrueOrFalse())
    {
        /* FIX: Use a small, non-zero value that will not cause an integer overflow in the sinks */
        data = 2;
    }
    else
    {
        /* FIX: Use a small, non-zero value that will not cause an integer overflow in the sinks */
        data = 2;
    }
    if(globalReturnsTrueOrFalse())
    {
        {
            /* POTENTIAL FLAW: Adding 1 to data could cause an overflow */
            int result = data + 1;
            printIntLine(result);
        }
    }
    else
    {
        {
            /* POTENTIAL FLAW: Adding 1 to data could cause an overflow */
            int result = data + 1;
            printIntLine(result);
        }
    }
}

void CWE190_Integer_Overflow__int_max_add_12_good()
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
    CWE190_Integer_Overflow__int_max_add_12_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
    return 0;
}

#endif