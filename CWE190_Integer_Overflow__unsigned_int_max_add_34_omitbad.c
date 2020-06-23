/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE190_Integer_Overflow__unsigned_int_max_add_34.c
Label Definition File: CWE190_Integer_Overflow.label.xml
Template File: sources-sinks-34.tmpl.c
*/
/*
 * @description
 * CWE: 190 Integer Overflow
 * BadSource: max Set data to the max value for unsigned int
 * GoodSource: Set data to a small, non-zero number (two)
 * Sinks: add
 *    GoodSink: Ensure there will not be an overflow before adding 1 to data
 *    BadSink : Add 1 to data, which can cause an overflow
 * Flow Variant: 34 Data flow: use of a union containing two methods of accessing the same data (within the same function)
 *
 * */

#include "std_testcase.h"

typedef union
{
    unsigned int unionFirst;
    unsigned int unionSecond;
} CWE190_Integer_Overflow__unsigned_int_max_add_34_unionType;


#ifndef OMITGOOD

/* goodG2B() uses the GoodSource with the BadSink */
static void goodG2B()
{
    unsigned int data;
    CWE190_Integer_Overflow__unsigned_int_max_add_34_unionType myUnion;
    data = 0;
    /* FIX: Use a small, non-zero value that will not cause an overflow in the sinks */
    data = 2;
    myUnion.unionFirst = data;
    {
        unsigned int data = myUnion.unionSecond;
        {
            /* POTENTIAL FLAW: Adding 1 to data could cause an overflow */
            unsigned int result = data + 1;
            printUnsignedLine(result);
        }
    }
}

/* goodB2G() uses the BadSource with the GoodSink */
static void goodB2G()
{
    unsigned int data;
    CWE190_Integer_Overflow__unsigned_int_max_add_34_unionType myUnion;
    data = 0;
    /* POTENTIAL FLAW: Use the maximum size of the data type */
    data = UINT_MAX;
    myUnion.unionFirst = data;
    {
        unsigned int data = myUnion.unionSecond;
        /* FIX: Add a check to prevent an overflow from occurring */
        if (data < UINT_MAX)
        {
            unsigned int result = data + 1;
            printUnsignedLine(result);
        }
        else
        {
            printLine("data value is too large to perform arithmetic safely.");
        }
    }
}

void CWE190_Integer_Overflow__unsigned_int_max_add_34_good()
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
    CWE190_Integer_Overflow__unsigned_int_max_add_34_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
    return 0;
}

#endif