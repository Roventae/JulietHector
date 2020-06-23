/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE190_Integer_Overflow__short_max_add_67b.c
Label Definition File: CWE190_Integer_Overflow.label.xml
Template File: sources-sinks-67b.tmpl.c
*/
/*
 * @description
 * CWE: 190 Integer Overflow
 * BadSource: max Set data to the max value for short
 * GoodSource: Set data to a small, non-zero number (two)
 * Sinks: add
 *    GoodSink: Ensure there will not be an overflow before adding 1 to data
 *    BadSink : Add 1 to data, which can cause an overflow
 * Flow Variant: 67 Data flow: data passed in a struct from one function to another in different source files
 *
 * */

#include "std_testcase.h"

typedef struct _CWE190_Integer_Overflow__short_max_add_67_structType
{
    short structFirst;
} CWE190_Integer_Overflow__short_max_add_67_structType;

#ifndef OMITBAD

void CWE190_Integer_Overflow__short_max_add_67b_badSink(CWE190_Integer_Overflow__short_max_add_67_structType myStruct)
{
    short data = myStruct.structFirst;
    {
        /* POTENTIAL FLAW: Adding 1 to data could cause an overflow */
        short result = data + 1;
        printIntLine(result);
    }
}

#endif /* OMITBAD */

