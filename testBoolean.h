/***********************************************************************
 * Header:
 *    TEST ARRAY
 * Summary:
 *    Unit tests for array
 * Author
 *    James Helfrich
 ************************************************************************/

#pragma once

#ifdef DEBUG

#include "boolean.h"     // class under test
#include "unitTest.h"    // unit test baseclass
#include <sstream>       // for string stream to verify the insertion and extraction operators

using std::cout;
using std::cin;
using custom::Boolean;

/***********************************************
 * TEST BOOLEAN
 * Unit tests for the Boolean class
 ***********************************************/
class TestBoolean : public UnitTest
{
public:
   void run()
   {
      reset();

      // Constants
      test_true();
      test_false();

      // Constructor
      test_construct_default();
      test_construct_nondefault_charFalse();
      test_construct_nondefault_charTrue();
      test_construct_nondefault_intZero();
      test_construct_nondefault_intPositive();
      test_construct_nondefault_intNegative();
      test_construct_nondefault_boolFalse();
      test_construct_nondefault_boolTrue();
      test_construct_nondefault_stringEmpty();
      test_construct_nondefault_stringTrue();
      test_construct_nondefault_stringFalse();
      test_construct_nondefault_stringStuff();
      test_construct_copyTrue();
      test_construct_copyFalse();

      // Assignment operator
      test_assignment_booleanTrue();
      test_assignment_booleanFalse();
      test_assignment_boolTrue();
      test_assignment_boolFalse();
      test_assignment_intPositive();
      test_assignment_intNegative();
      test_assignment_intZero();
      test_assignment_charNull();
      test_assignment_charA();
      test_assignment_stringEmpty();
      test_assignment_stringTrue();
      test_assignment_stringFalse();
      test_assignment_stringStuff();
      
      // Conversion
      test_conversion_boolTrue();
      test_conversion_boolFalse();
      test_conversion_ifTrue();
      test_conversion_ifFalse();
      test_conversion_intTrue();
      test_conversion_intFalse();

      // Equivalent
      test_equal_trueTrue();
      test_equal_trueFalse();
      test_equal_falseTrue();
      test_equal_falseFalse();
      test_notEqual_trueTrue();
      test_notEqual_trueFalse();
      test_notEqual_falseTrue();
      test_notEqual_falseFalse();

      // Logical Operators
      test_not_true();
      test_not_false();
      test_or_trueTrue();
      test_or_trueFalse();
      test_or_falseTrue();
      test_or_falseFalse();
      test_and_trueTrue();
      test_and_trueFalse();
      test_and_falseTrue();
      test_and_falseFalse();
      test_xor_trueTrue();
      test_xor_trueFalse();
      test_xor_falseTrue();
      test_xor_falseFalse();

      // STREAM
      test_insertion_false();
      test_insertion_true();
      test_insertion_falseAlpha();
      test_insertion_trueAlpha(); 
      test_extraction_0();
      test_extraction_1();
      test_extraction_false();
      test_extraction_true();

      report("Boolean");
    }

   /***************************************
    * CONSTANTS
    ***************************************/

   // constant TRUE
   void test_true()
   {  // setup
      // exercise
      // verify
      assertUnit((TRUE).data == 0xff);
   }  // teardown

   // constant FALSE
   void test_false()
   {  // setup
      // exercise
      // verify
      assertUnit((FALSE).data == 0x00);
   }  // teardown

   
   /***************************************
    * CONSTRUCTOR
    ***************************************/
   
   // default constructor
   void test_construct_default()
   {  // setup
      // exercise
      Boolean b;
      // verify
      assertUnit(b.data == 0x00);
   }  // teardown

   // non-default with a char, set to false
   void test_construct_nondefault_charFalse()
   {  // setup
      char c = '\0';
      // exercise
      Boolean b(c);
      // verify 
      assertUnit(b.data == 0x00);
   }// teardown

   // non-default with a char, set to true
   void test_construct_nondefault_charTrue()
   {   // setup
      char c = 'A';
      // exercise
      Boolean b(c);
      // verify 
      assertUnit(b.data == 0xff);
   }// teardown

   // non-default with an integer, set to zero
   void test_construct_nondefault_intZero()
   {  // setup
      int i = 0;
      // exercise
      Boolean b(i);  
      // verify 
      assertUnit(b.data == 0x00);
   }  // teardown

   // non-default with an integer, set to positive
   void test_construct_nondefault_intPositive()
   {  // setup
      int i = 42;
      // exercise
      Boolean b(i);
      // verify 
      assertUnit(b.data == 0xff);
   }  // teardown

   // non-default with an integer, set to negative
   void test_construct_nondefault_intNegative()
   {   // setup
      int i = -2; // maps to 0xfe
      // exercise
      Boolean b(i);
      // verify 
      assertUnit(b.data == 0xff);
   }  // teardown

   // non-default with a bool, set to false
   void test_construct_nondefault_boolFalse()
   {  // setup
      bool bSrc = false;
      // exercise
      Boolean bDes(bSrc); 
      // verify 
      assertUnit(bDes.data == 0x00);
   }  // teardown

   // non-default with a bool, set to true
   void test_construct_nondefault_boolTrue()
   {  // setup
      bool bSrc = true;
      // exercise
      Boolean bDes(bSrc);
      // verify 
      assertUnit(bDes.data == 0xff);
   }  // teardown

   // non-default with a string, set to empty
   void test_construct_nondefault_stringEmpty()
   {  // setup
      std::string s("");
      // exercise
      Boolean b(s);
      // verify     
      assertUnit(b.data == 0x00);
   }  // teardown

   // non-default with a string, set to true
   void test_construct_nondefault_stringTrue()
   {  // setup
      std::string s("true");
      // exercise
      Boolean b(s);
      // verify     
      assertUnit(b.data == 0xff);
   }  // teardown

   // non-default with a string, set to false
   void test_construct_nondefault_stringFalse()
   {  // setup
      std::string s("false");
      // exercise
      Boolean b(s);
      // verify     
      assertUnit(b.data == 0x00);
   }  // teardown

   // non-default with a string, set to random stuff
   void test_construct_nondefault_stringStuff()
   {  // setup
      std::string s("Boolean");
      // exercise
      Boolean b(s);
      // verify     
      assertUnit(b.data == 0xff);
   }  // teardown

   // copy constructor - true
   void test_construct_copyTrue()
   {  // setup
      Boolean bSrc(1); 
      // exercise
      Boolean bDes(bSrc);
      //  verify
      assertUnit(bSrc.data == 0xff);
      assertUnit(bDes.data == 0xff);
   }  // teardown

   // copy constructor - false
   void test_construct_copyFalse()
   {  // setup
      Boolean bSrc(0);
      // exercise
      Boolean bDes(bSrc);
      //  verify
      assertUnit(bSrc.data == 0x00);
      assertUnit(bDes.data == 0x00);
   }  // teardown

   /***************************************
    * ASSIGNMENT
    ***************************************/

   // assignment operator, boolean set to true
   void test_assignment_booleanTrue()
   {  // setup
      Boolean bSrc(1);
      Boolean bDes(0);
      Boolean bRet(0);
      // exercise
      bRet = bDes = bSrc;
      // verify
      assertUnit(bSrc.data == 0xff);
      assertUnit(bDes.data == 0xff);
      assertUnit(bRet.data == 0xff);
   }  // teardown

   // assignment operator, boolean set to false
   void test_assignment_booleanFalse()
   {  // setup
      Boolean bSrc(0);
      Boolean bDes(1);
      Boolean bRet(1);
      // exercise
      bRet = bDes = bSrc;
      // verify
      assertUnit(bSrc.data == 0x00);
      assertUnit(bDes.data == 0x00);
      assertUnit(bRet.data == 0x00);
   }  // teardown

   // assignment operator, bool set to true
   void test_assignment_boolTrue()
   {  // setup
      bool bSrc = true;
      Boolean bDes(0);
      Boolean bRet(0);
      // exercise
      bRet = bDes = bSrc;
      // verify
      assertUnit(bSrc == true);
      assertUnit(bDes.data == 0xff);
      assertUnit(bRet.data == 0xff);
   }  // teardown

   // assignment operator, bool set to false
   void test_assignment_boolFalse()
   {  // setup
      bool bSrc = false;
      Boolean bDes(1);
      Boolean bRet(1);
      // exercise
      bRet = bDes = bSrc;
      // verify
      assertUnit(bSrc == false);
      assertUnit(bDes.data == 0x00);
      assertUnit(bRet.data == 0x00);
   }  // teardown

   // assignment operator, int set to positive
   void test_assignment_intPositive()
   {  // setup
      int iSrc = 42;
      Boolean bDes(0);
      Boolean bRet(0);
      // exercise
      bRet = bDes = iSrc;
      // verify
      assertUnit(iSrc == 42);
      assertUnit(bDes.data == 0xff);
      assertUnit(bRet.data == 0xff);
   }  // teardown

   // assignment operator, int set to negative
   void test_assignment_intNegative()
   {  // setup
      int iSrc = -42;
      Boolean bDes(0);
      Boolean bRet(0);
      // exercise
      bRet = bDes = iSrc;
      // verify
      assertUnit(iSrc == -42);
      assertUnit(bDes.data == 0xff);
      assertUnit(bRet.data == 0xff);
   }  // teardown

   // assignment operator, int set to zero
   void test_assignment_intZero()
   {  // setup
      int iSrc = 0;
      Boolean bDes(1);
      Boolean bRet(1);
      // exercise
      bRet = bDes = iSrc;
      // verify
      assertUnit(iSrc == 0);
      assertUnit(bDes.data == 0x00);
      assertUnit(bRet.data == 0x00);
   }  // teardown

   // assignment operator, char set to NULL
   void test_assignment_charNull()
   {  // setup
      char cSrc = '\0';
      Boolean bDes(1);
      Boolean bRet(1);
      // exercise
      bRet = bDes = cSrc;
      // verify
      assertUnit(cSrc == '\0');
      assertUnit(bDes.data == 0x00);
      assertUnit(bRet.data == 0x00);
   }  // teardown

   // assignment operator, char set to A
   void test_assignment_charA()
   {  // setup
      char cSrc = 'A';
      Boolean bDes(0);
      Boolean bRet(0);
      // exercise
      bRet = bDes = cSrc;
      // verify
      assertUnit(cSrc == 'A');
      assertUnit(bDes.data == 0xff);
      assertUnit(bRet.data == 0xff);
   }  // teardown

   // = ""
   void test_assignment_stringEmpty()
   {  // setup
      std::string s;
      Boolean bDes(1);
      Boolean bRet(1);
      // exercise
      bRet = bDes = s;
      // verify
      assertUnit(s.empty());
      assertUnit(bDes.data == 0x00);
      assertUnit(bRet.data == 0x00);
   }  // teardown
   
   // = "true"
   void test_assignment_stringTrue()
   {  // setup
      std::string s("true");
      Boolean bDes(0);
      Boolean bRet(0);
      // exercise
      bRet = bDes = s;
      // verify
      assertUnit(s == std::string("true"));
      assertUnit(bDes.data == 0xff);
      assertUnit(bRet.data == 0xff);
   }  // teardown
   
   // = "false"
   void test_assignment_stringFalse()
   {  // setup
      std::string s("false");
      Boolean bDes(1);
      Boolean bRet(1);
      // exercise
      bRet = bDes = s;
      // verify
      assertUnit(s == std::string("false"));
      assertUnit(bDes.data == 0x00);
      assertUnit(bRet.data == 0x00);
   }  // teardown
   
   // = "stuff"
   void test_assignment_stringStuff()
   {  // setup
      std::string s("stuff");
      Boolean bDes(0);
      Boolean bRet(0);
      // exercise
      bRet = bDes = s;
      // verify
      assertUnit(s == std::string("stuff"));
      assertUnit(bDes.data == 0xff);
      assertUnit(bRet.data == 0xff);
   }  // teardown

   /***************************************
    * CONVERSION
    ***************************************/

   // convert from a Boolean to a bool, TRUE case
   void test_conversion_boolTrue()
   {  // setup
      Boolean bSrc(1); 
      bool bDes = false;
      // exercise
      bDes = bool(bSrc); // Boolean must be cast to a bool because 
                         // our conversion operator is explicit
      // verify
      assertUnit(bSrc.data == 0xff);
      assertUnit(bDes == true);
   }  // teardown

   // convert from a Boolean to a bool, FALSE case
   void test_conversion_boolFalse()
   {  // setup
      Boolean bSrc(0);
      bool bDes = true;
      // exercise
      bDes = bool(bSrc); 
      // verify
      assertUnit(bSrc.data == 0x00);
      assertUnit(bDes == false);
   }  // teardown

   // convert a Boolean so it can be used in an IF - TRUE case
   void test_conversion_ifTrue()
   {   // setup
       Boolean b(1);
       // exercise
       if (b) 
       // verify
           assertUnit(true);  // verify
       else
           assertUnit(false); // verify
   }   // teardown

   // convert a Boolean so it can be used in an IF - FALSE case
   void test_conversion_ifFalse()
   {   // setup
      Boolean b(0);
      // exercise
      if (b)
         // verify
         assertUnit(false);  // verify
      else
         assertUnit(true); // verify
   }   // teardown

   // convert from a Boolean to an int, FALSE case
   void test_conversion_intFalse()
   {  // setup
      Boolean bSrc(0);
      int iDes = 42;
      // exercise
      iDes = bool(bSrc);
      // verify
      assertUnit(bSrc.data == 0x00);
      assertUnit(iDes == 0);
   }  // teardown

   // convert from a Boolean to an int, TRUE case
   void test_conversion_intTrue()
   {  // setup
      Boolean bSrc(1);
      int iDes = 0;
      // exercise
      iDes = bool(bSrc);
      // verify
      assertUnit(bSrc.data == 0xff);
      assertUnit(iDes == 1);
   }  // teardown


   /***************************************
    * EQUIVALENT
    ***************************************/
   
   // TRUE == TRUE
   void test_equal_trueTrue()
   {   // setup
       Boolean bLHS(1);
       Boolean bRHS(1);
       Boolean bRet(0);
       // exercise
       bRet = (bLHS == bRHS);
       // verify
       assertUnit(bLHS.data == 0xff);
       assertUnit(bRHS.data == 0xff);
       assertUnit(bRet.data == 0xff);
   }   // teardown

   // TRUE == FALSE
   void test_equal_trueFalse()
   {   // setup
      Boolean bLHS(1);
      Boolean bRHS(0);
      Boolean bRet(1);
      // exercise
      bRet = (bLHS == bRHS);
      // verify
      assertUnit(bLHS.data == 0xff);
      assertUnit(bRHS.data == 0x00);
      assertUnit(bRet.data == 0x00);
   }   // teardown

   // FALSE == TRUE
   void test_equal_falseTrue()
   {   // setup
      Boolean bLHS(0);
      Boolean bRHS(1);
      Boolean bRet(1);
      // exercise
      bRet = (bLHS == bRHS);
      // verify
      assertUnit(bLHS.data == 0x00);
      assertUnit(bRHS.data == 0xff);
      assertUnit(bRet.data == 0x00);
   }   // teardown

   // FALSE == FALSE
   void test_equal_falseFalse()
   {   // setup
      Boolean bLHS(0);
      Boolean bRHS(0);
      Boolean bRet(0);
      // exercise
      bRet = (bLHS == bRHS);
      // verify
      assertUnit(bLHS.data == 0x00);
      assertUnit(bRHS.data == 0x00);
      assertUnit(bRet.data == 0xff);
   }   // teardown

   // TRUE != TRUE
   void test_notEqual_trueTrue()
   {   // setup
      Boolean bLHS(1);
      Boolean bRHS(1);
      Boolean bRet(1);
      // exercise
      bRet = (bLHS != bRHS);
      // verify
      assertUnit(bLHS.data == 0xff);
      assertUnit(bRHS.data == 0xff);
      assertUnit(bRet.data == 0x00);
   }   // teardown

   // TRUE == FALSE
   void test_notEqual_trueFalse()
   {   // setup
      Boolean bLHS(1);
      Boolean bRHS(0);
      Boolean bRet(0);
      // exercise
      bRet = (bLHS != bRHS);
      // verify
      assertUnit(bLHS.data == 0xff);
      assertUnit(bRHS.data == 0x00);
      assertUnit(bRet.data == 0xff);
   }   // teardown

   // FALSE != TRUE
   void test_notEqual_falseTrue()
   {   // setup
      Boolean bLHS(0);
      Boolean bRHS(1);
      Boolean bRet(0);
      // exercise
      bRet = (bLHS != bRHS);
      // verify
      assertUnit(bLHS.data == 0x00);
      assertUnit(bRHS.data == 0xff);
      assertUnit(bRet.data == 0xff);
   }   // teardown

   // FALSE != FALSE
   void test_notEqual_falseFalse()
   {   // setup
      Boolean bLHS(0);
      Boolean bRHS(0);
      Boolean bRet(1);
      // exercise
      bRet = (bLHS != bRHS);
      // verify
      assertUnit(bLHS.data == 0x00);
      assertUnit(bRHS.data == 0x00);
      assertUnit(bRet.data == 0x00);
   }   // teardown

   /***************************************
    * LOGICAL OPERATORS
    ***************************************/

   // !TRUE
   void test_not_true()
   {   // setup
      Boolean bSrc(1);
      Boolean bDes(1);
      // exercise
      bDes = !bSrc;
      // verify
      assertUnit(bSrc.data == 0xff);
      assertUnit(bDes.data == 0x00);
   }   // teardown

   // !FALSE
   void test_not_false()
   {   // setup
      Boolean bSrc(0);
      Boolean bDes(0);
      // exercise
      bDes = !bSrc;
      // verify
      assertUnit(bSrc.data == 0x00);
      assertUnit(bDes.data == 0xff);
   }   // teardown

   // TRUE || TRUE
   void test_or_trueTrue()
   {  // setup
      Boolean bLHS(1);
      Boolean bRHS(1);
      Boolean bRet(0);
      // exercise
      bRet = (bLHS || bRHS);
      // verify
      assertUnit(bLHS.data == 0xff);
      assertUnit(bRHS.data == 0xff);
      assertUnit(bRet.data == 0xff);
   }  // teardown

   // TRUE || FALSE
   void test_or_trueFalse()
   {  // setup
      Boolean bLHS(1);
      Boolean bRHS(0);
      Boolean bRet(0);
      // exercise
      bRet = (bLHS || bRHS);
      // verify
      assertUnit(bLHS.data == 0xff);
      assertUnit(bRHS.data == 0x00);
      assertUnit(bRet.data == 0xff);
   }  // teardown

   // FALSE || TRUE
   void test_or_falseTrue()
   {  // setup
      Boolean bLHS(0);
      Boolean bRHS(1);
      Boolean bRet(0);
      // exercise
      bRet = (bLHS || bRHS);
      // verify
      assertUnit(bLHS.data == 0x00);
      assertUnit(bRHS.data == 0xff);
      assertUnit(bRet.data == 0xff);
   }  // teardown

   // FALSE || FALSE
   void test_or_falseFalse()
   {  // setup
      Boolean bLHS(0);
      Boolean bRHS(0);
      Boolean bRet(1);
      // exercise
      bRet = (bLHS || bRHS);
      // verify
      assertUnit(bLHS.data == 0x00);
      assertUnit(bRHS.data == 0x00);
      assertUnit(bRet.data == 0x00);
   }  // teardown

   // TRUE && TRUE
   void test_and_trueTrue()
   {  // setup
      Boolean bLHS(1);
      Boolean bRHS(1);
      Boolean bRet(0);
      // exercise
      bRet = (bLHS && bRHS);
      // verify
      assertUnit(bLHS.data == 0xff);
      assertUnit(bRHS.data == 0xff);
      assertUnit(bRet.data == 0xff);
   }  // teardown

   // TRUE && FALSE
   void test_and_trueFalse()
   {  // setup
      Boolean bLHS(1);
      Boolean bRHS(0);
      Boolean bRet(1);
      // exercise
      bRet = (bLHS && bRHS);
      // verify
      assertUnit(bLHS.data == 0xff);
      assertUnit(bRHS.data == 0x00);
      assertUnit(bRet.data == 0x00);
   }  // teardown

   // FALSE && TRUE
   void test_and_falseTrue()
   {  // setup
      Boolean bLHS(0);
      Boolean bRHS(1);
      Boolean bRet(1);
      // exercise
      bRet = (bLHS && bRHS);
      // verify
      assertUnit(bLHS.data == 0x00);
      assertUnit(bRHS.data == 0xff);
      assertUnit(bRet.data == 0x00);
   }  // teardown

   // FALSE && FALSE
   void test_and_falseFalse()
   {  // setup
      Boolean bLHS(0);
      Boolean bRHS(0);
      Boolean bRet(1);
      // exercise
      bRet = (bLHS && bRHS);
      // verify
      assertUnit(bLHS.data == 0x00);
      assertUnit(bRHS.data == 0x00);
      assertUnit(bRet.data == 0x00);
   }  // teardown

   // TRUE ^ TRUE
   void test_xor_trueTrue()
   {  // setup
      Boolean bLHS(1);
      Boolean bRHS(1);
      Boolean bRet(1);
      // exercise
      bRet = (bLHS ^ bRHS);
      // verify
      assertUnit(bLHS.data == 0xff);
      assertUnit(bRHS.data == 0xff);
      assertUnit(bRet.data == 0x00);
   }  // teardown

   // TRUE ^ FALSE
   void test_xor_trueFalse()
   {  // setup
      Boolean bLHS(1);
      Boolean bRHS(0);
      Boolean bRet(0);
      // exercise
      bRet = (bLHS ^ bRHS);
      // verify
      assertUnit(bLHS.data == 0xff);
      assertUnit(bRHS.data == 0x00);
      assertUnit(bRet.data == 0xff);
   }  // teardown

   // FALSE ^ TRUE
   void test_xor_falseTrue()
   {  // setup
      Boolean bLHS(0);
      Boolean bRHS(1);
      Boolean bRet(0);
      // exercise
      bRet = (bLHS ^ bRHS);
      // verify
      assertUnit(bLHS.data == 0x00);
      assertUnit(bRHS.data == 0xff);
      assertUnit(bRet.data == 0xff);
   }  // teardown

   // FALSE ^ FALSE
   void test_xor_falseFalse()
   {  // setup
      Boolean bLHS(0);
      Boolean bRHS(0);
      Boolean bRet(1);
      // exercise
      bRet = (bLHS ^ bRHS);
      // verify
      assertUnit(bLHS.data == 0x00);
      assertUnit(bRHS.data == 0x00);
      assertUnit(bRet.data == 0x00);
   }  // teardown

   /***************************************
    * STREAM I/O
    ***************************************/

   // << FALSE
   void test_insertion_false()
   {  // setup
      Boolean b(0);
      std::ostringstream sout;
      // exercise
      sout << b;
      // verify
      assertUnit(b.data == 0x00);
      assertUnit(sout.fail() == false);
      auto s = sout.str();
      assertUnit(s == std::string("0"));
   }  // teardown

   // << TRUE
   void test_insertion_true()
   {  // setup
      Boolean b(1);
      std::ostringstream sout;
      // exercise
      sout << b;
      // verify
      assertUnit(b.data == 0xff);
      assertUnit(sout.fail() == false);
      auto s = sout.str();
      assertUnit(s == std::string("1"));
   }  // teardown

   // << FALSE
   void test_insertion_falseAlpha()
   {  // setup
      Boolean b(0);
      std::ostringstream sout;
      sout << std::boolalpha;
      // exercise
      sout << b;
      // verify
      assertUnit(b.data == 0x00);
      assertUnit(sout.fail() == false);
      auto s = sout.str();
      assertUnit(s == std::string("false"));
   }  // teardown

   // << TRUE
   void test_insertion_trueAlpha()
   {  // setup
      Boolean b(1);
      std::ostringstream sout;
      sout << std::boolalpha;
      // exercise
      sout << b;
      // verify
      assertUnit(b.data == 0xff);
      assertUnit(sout.fail() == false);
      auto s = sout.str();
      assertUnit(s == std::string("true"));
   }  // teardown


   // >> 0
   void test_extraction_0()
   {  // setup
      Boolean b(1);
      std::istringstream sin;
      std::string s = "0";
      sin.str(s);
      // exercise
      sin >> b;
      // verify
      assertUnit(b.data == 0x00);
      assertUnit(!sin.fail());
   }  // teardown

   // >> 1
   void test_extraction_1()
   {  // setup
      Boolean b(0);
      std::istringstream sin;
      std::string s = "1";
      sin.str(s);
      // exercise
      sin >> b;
      // verify
      assertUnit(b.data == 0xff);
      assertUnit(!sin.fail());
   }  // teardown

   // >> false
   void test_extraction_false()
   {  // setup
      Boolean b(1);
      std::istringstream sin;
      std::string s = "false";
      sin.str(s);
      // exercise
      sin >> b;
      // verify
      assertUnit(b.data == 0x00);
      assertUnit(!sin.fail());
   }  // teardown

   // >> true
   void test_extraction_true()
   {  // setup
      Boolean b(0);
      std::istringstream sin;
      std::string s = "true";
      sin.str(s);
      // exercise
      sin >> b;
      // verify
      assertUnit(b.data == 0xff);
      assertUnit(!sin.fail());
   }  // teardown


};

#endif // DEBUG
