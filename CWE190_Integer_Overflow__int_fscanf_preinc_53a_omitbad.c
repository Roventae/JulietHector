/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE190_Integer_Overflow__int_fscanf_preinc_53a.c
Label Definition File: CWE190_Integer_Overflow__int.label.xml
Template File: sources-sinks-53a.tmpl.c
*/
/*
 * @description
 * CWE: 190 Integer Overflow
 * BadSource: fscanf Read data from the console using fscanf()
 * GoodSource: Set data to a small, non-zero number (two)
 * Sinks: increment
 *    GoodSink: Ensure there will not be an overflow before incrementing data
 *    BadSink : Increment data, which can cause an overflow
 * Flow Variant: 53 Data flow: data passed as an argument from one function through two others to a fourth; all four functions are in different source files
 *
 * */

#include "std_testcase.h"


#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE190_Integer_Overflow__int_fscanf_preinc_53b_goodG2BSink(int data);

static void goodG2B()
{
    int data;
    /* Initialize data */
    data = 0;
    /* FIX: Use a small, non-zero value that will not cause an integer overflow in the sinks */
    data = 2;
    CWE190_Integer_Overflow__int_fscanf_preinc_53b_goodG2BSink(data);
}

/* goodB2G uses the BadSource with the GoodSink */
void CWE190_Integer_Overflow__int_fscanf_preinc_53b_goodB2GSink(int data);

static void goodB2G()
{
    int data;
    /* Initialize data */
    data = 0;
    /* POTENTIAL FLAW: Read data from the console using fscanf() */
    fscanf(stdin, "%d", &data);
    CWE190_Integer_Overflow__int_fscanf_preinc_53b_goodB2GSink(data);
}

void CWE190_Integer_Overflow__int_fscanf_preinc_53_good()
{
    goodG2B();
    goodB2G();
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
    CWE190_Integer_Overflow__int_fscanf_preinc_53_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
    return 0;
}

#endif