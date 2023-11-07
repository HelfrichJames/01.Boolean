/***********************************************************************
 * Header:
 *    Boolean
 * Summary:
 *    This class contains the notion of a Boolean
 * Author
 *    James Helfrich
 ************************************************************************/

#pragma once

#include <stdexcept>
#include <iostream>

// corresponding to true and false
#define TRUE  Boolean(1)
#define FALSE Boolean(0)

namespace custom
{
#define TRUE_VALUE 0xff
/************************************************
 * Boolean
 * A class that contains a Boolean data type
 ***********************************************/
class Boolean
{
public:
	// Constructors
	Boolean() { setFalse();  }
	Boolean(char value)
	{ 
		if (value != 0x00)
			setTrue(); 
		else 
			setFalse();                      
	}
	Boolean(int value)
	{ 
		if (value != 0)
			setTrue(); 
		else 
			setFalse();                      
	}
	Boolean(bool value)
	{ 
		if (value != false) 
			setTrue(); 
		else 
			setFalse();                      
	}
	Boolean(const std::string& value) 
	{ 
		if (!value.empty() && value != std::string("false"))
			setTrue(); 
		else 
			setFalse(); 
	}
	Boolean(const Boolean& rhs) : data(rhs.data) {}

	// Assignment 
	Boolean& operator= (const Boolean& rhs)
	{ 
      data = rhs.data;
		return *this; 
	}
	Boolean& operator= (unsigned char rhs)
	{ 
		if (rhs == 0x00)
			setFalse();
		else 
			setTrue();  
		return *this; 
	}
   Boolean& operator= (int rhs)
   {
      if (rhs == 0)
         setFalse();
      else
         setTrue();
      return *this;
   }
   Boolean& operator= (const std::string& rhs)
   {
      if (!rhs.empty() && rhs != std::string("false")) 
         setTrue();
      else
         setFalse();
      return *this;
   }
   
	// Explicit conversion
	explicit operator bool() const { return isTrue();         }
	explicit operator int()  const { return isTrue() ? 1 : 0; }

	// Equivalent
	Boolean operator== (const Boolean& rhs) const
	{ 
		return (isTrue() == rhs.isTrue()) ? TRUE : FALSE; 
	}
	Boolean operator!= (const Boolean& rhs) const
	{
		return (isTrue() == rhs.isTrue()) ? FALSE : TRUE;
	}

	// Logical operators
	Boolean operator! () const
	{
		return isTrue() ? FALSE : TRUE;
	}
	Boolean operator|| (const Boolean& rhs) const
	{ 
		return (isTrue() || rhs.isTrue()) ? TRUE : FALSE;
	}
	Boolean operator&& (const Boolean& rhs) const
	{
		return (isTrue() && rhs.isTrue()) ? TRUE : FALSE;
	}
	Boolean operator^  (const Boolean& rhs) const
	{ 
		return (isTrue() == rhs.isTrue()) ? FALSE : TRUE;
	}

	// Stream
	inline friend std::ostream& operator<< (std::ostream& out, const custom::Boolean& rhs);
	inline friend std::istream& operator>> (std::istream& in, custom::Boolean& rhs);

#ifdef DEBUG
public:
#else
private:
#endif // DEBUG

   unsigned char data; // store our Boolean value here

	// Utilities. Only these know the value of TRUE and FALSE
   void setTrue()      { data = TRUE_VALUE;         } // set the boolean to true
   void setFalse()     { data = 0x00;               } // set the boolean to false
   bool isTrue() const { return data == TRUE_VALUE; } // check the value of the boolean

}; // class Boolean

// Stream insertion, sending output to a stream
inline std::ostream& operator<< (std::ostream& out, const custom::Boolean& rhs)
{
	if (out.flags() & out.boolalpha)
		out << (rhs.isTrue() ? "true" : "false");
	else
		out << (rhs.isTrue() ? 1 : 0);

	return out;
}

// Stream extraction, accepting input from a stream
inline std::istream& operator>> (std::istream& in, custom::Boolean& rhs)
{
	// accept the string - one word
	std::string s;
	in >> s;

	// 0 and false are FALSE...
	if (s == "0" || s == "false")
		rhs.setFalse();
	// ...everything else is TRUE
	else
		rhs.setTrue();

	return in;
}

}; // namespace custom
