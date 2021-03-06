/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE190_Integer_Overflow__unsigned_int_fscanf_preinc_66a.c
Label Definition File: CWE190_Integer_Overflow.label.xml
Template File: sources-sinks-66a.tmpl.c
*/
/*
 * @description
 * CWE: 190 Integer Overflow
 * BadSource: fscanf Read data from the console using fscanf()
 * GoodSource: Set data to a small, non-zero number (two)
 * Sinks: increment
 *    GoodSink: Ensure there will not be an overflow before incrementing data
 *    BadSink : Increment data, which can cause an overflow
 * Flow Variant: 66 Data flow: data passed in an array from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#ifndef OMITBAD

/* bad function declaration */
void CWE190_Integer_Overflow__unsigned_int_fscanf_preinc_66b_badSink(unsigned int dataArray[]);

void CWE190_Integer_Overflow__unsigned_int_fscanf_preinc_66_bad()
{
    unsigned int data;
    unsigned int dataArray[5];
    data = 0;
    /* POTENTIAL FLAW: Use a value input from the console */
    fscanf (stdin, "%u", &data);
    /* put data in array */
    dataArray[2] = data;
    CWE190_Integer_Overflow__unsigned_int_fscanf_preinc_66b_badSink(dataArray);
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
    CWE190_Integer_Overflow__unsigned_int_fscanf_preinc_66_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
