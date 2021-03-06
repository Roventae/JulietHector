/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE190_Integer_Overflow__unsigned_int_fscanf_square_62b.cpp
Label Definition File: CWE190_Integer_Overflow.label.xml
Template File: sources-sinks-62b.tmpl.cpp
*/
/*
 * @description
 * CWE: 190 Integer Overflow
 * BadSource: fscanf Read data from the console using fscanf()
 * GoodSource: Set data to a small, non-zero number (two)
 * Sinks: square
 *    GoodSink: Ensure there will not be an overflow before squaring data
 *    BadSink : Square data, which can lead to overflow
 * Flow Variant: 62 Data flow: data flows using a C++ reference from one function to another in different source files
 *
 * */

#include "std_testcase.h"

namespace CWE190_Integer_Overflow__unsigned_int_fscanf_square_62
{

#ifndef OMITBAD

void badSource(unsigned int &data)
{
    /* POTENTIAL FLAW: Use a value input from the console */
    fscanf (stdin, "%u", &data);
}

#endif /* OMITBAD */


} /* close namespace */
