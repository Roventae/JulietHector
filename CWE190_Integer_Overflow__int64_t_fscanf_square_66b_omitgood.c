/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE190_Integer_Overflow__int64_t_fscanf_square_66b.c
Label Definition File: CWE190_Integer_Overflow.label.xml
Template File: sources-sinks-66b.tmpl.c
*/
/*
 * @description
 * CWE: 190 Integer Overflow
 * BadSource: fscanf Read data from the console using fscanf()
 * GoodSource: Set data to a small, non-zero number (two)
 * Sinks: square
 *    GoodSink: Ensure there will not be an overflow before squaring data
 *    BadSink : Square data, which can lead to overflow
 * Flow Variant: 66 Data flow: data passed in an array from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <math.h>
#include <inttypes.h>

#ifndef OMITBAD

void CWE190_Integer_Overflow__int64_t_fscanf_square_66b_badSink(int64_t dataArray[])
{
    /* copy data out of dataArray */
    int64_t data = dataArray[2];
    {
        /* POTENTIAL FLAW: if (data*data) > LLONG_MAX, this will overflow */
        int64_t result = data * data;
        printLongLongLine(result);
    }
}

#endif /* OMITBAD */

