/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE190_Integer_Overflow__int_listen_socket_square_81_goodB2G.cpp
Label Definition File: CWE190_Integer_Overflow__int.label.xml
Template File: sources-sinks-81_goodB2G.tmpl.cpp
*/
/*
 * @description
 * CWE: 190 Integer Overflow
 * BadSource: listen_socket Read data using a listen socket (server side)
 * GoodSource: Set data to a small, non-zero number (two)
 * Sinks: square
 *    GoodSink: Ensure there will not be an overflow before squaring data
 *    BadSink : Square data, which can lead to overflow
 * Flow Variant: 81 Data flow: data passed in a parameter to an virtual method called via a reference
 *
 * */