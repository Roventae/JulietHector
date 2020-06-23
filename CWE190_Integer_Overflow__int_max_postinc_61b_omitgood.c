/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE190_Integer_Overflow__int_max_postinc_61b.c
Label Definition File: CWE190_Integer_Overflow__int.label.xml
Template File: sources-sinks-61b.tmpl.c
*/
/*
 * @description
 * CWE: 190 Integer Overflow
 * BadSource: max Set data to the max value for int
 * GoodSource: Set data to a small, non-zero number (two)
 * Sinks: increment
 *    GoodSink: Ensure there will not be an overflow before incrementing data
 *    BadSink : Increment data, which can cause an overflow
 * Flow Variant: 61 Data flow: data returned from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#ifndef OMITBAD

int CWE190_Integer_Overflow__int_max_postinc_61b_badSource(int data)
{
    /* POTENTIAL FLAW: Use the maximum value for this type */
    data = INT_MAX;
    return data;
}

#endif /* OMITBAD */

