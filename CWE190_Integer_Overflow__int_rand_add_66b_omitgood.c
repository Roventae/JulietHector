/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE190_Integer_Overflow__int_rand_add_66b.c
Label Definition File: CWE190_Integer_Overflow__int.label.xml
Template File: sources-sinks-66b.tmpl.c
*/
/*
 * @description
 * CWE: 190 Integer Overflow
 * BadSource: rand Set data to result of rand(), which may be zero
 * GoodSource: Set data to a small, non-zero number (two)
 * Sinks: add
 *    GoodSink: Ensure there will not be an overflow before adding 1 to data
 *    BadSink : Add 1 to data, which can cause an overflow
 * Flow Variant: 66 Data flow: data passed in an array from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#ifndef OMITBAD

void CWE190_Integer_Overflow__int_rand_add_66b_badSink(int dataArray[])
{
    /* copy data out of dataArray */
    int data = dataArray[2];
    {
        /* POTENTIAL FLAW: Adding 1 to data could cause an overflow */
        int result = data + 1;
        printIntLine(result);
    }
}

#endif /* OMITBAD */

