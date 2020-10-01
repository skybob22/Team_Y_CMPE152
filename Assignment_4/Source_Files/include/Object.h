/**
 * <h1>Object</h1>
 *
 * <p>Typedef Object as Object</p>
 *
 * <p>Copyright (c) 2020 by Ronald Mak</p>
 * <p>For instructional purposes only.  No warranties.</p>
 */
#ifndef OBJECT_H_
#define OBJECT_H_

#include <string>
#include <functional>

#include "antlr4-runtime.h"

typedef antlrcpp::Any Object;

using namespace std;

/**
 * Return a copy of a string with all the letters shifted to upper case.
 * @param str the original string.
 * @return a copy of the string with shifted letters.
 */
inline string toUpperCase(const string str)
{
    string upperCase(str);
    transform(upperCase.begin(), upperCase.end(),
              upperCase.begin(), ::toupper);
    return upperCase;
}

/**
 * Return a copy of a string with all the letters shifted to lower case.
 * @param str the original string.
 * @return a copy of the string with shifted letters.
 */
inline string toLowerCase(const string str)
{
    string lowerCase(str);
    transform(lowerCase.begin(), lowerCase.end(),
              lowerCase.begin(), ::tolower);
    return lowerCase;
}

/**
 * Convert a Pascal string to an equivalent C++ string.
 * @parm pascalString the Pascal string.
 * @parm needBackslash true if need to backslash-quote double-quotes
 * @return the C++ string.
 */
inline string convertString(const string pascalString, bool needBackslash)
{
    string unquoted = pascalString.substr(1, pascalString.length()-2);
    size_t pos = 0;

    while ((pos = unquoted.find("''", pos)) != string::npos)
    {
        unquoted.replace(pos, 2, "'");
        pos++;
    }

    pos = 0;
    while ((pos = unquoted.find("\"", pos)) != string::npos)
    {
        if (needBackslash) unquoted.replace(pos, 1, "\\\"");
        else               unquoted.replace(pos, 1, "\"");

        pos+=2;
    }

    return unquoted;
}



//Only works for ints, doubles, boolean
template<typename T>
T castObjTo(const Object &obj) {
    T retVal;

    if (obj.is<int>()) {
        int val = obj.as<int>();
        retVal = static_cast<T>(val);
    } else if (obj.is<double>()) {
        double val = obj.as<double>();
        retVal = static_cast<T>(val);
    } else if (obj.is<bool>()) {
        bool val = obj.as<bool>();
        retVal = static_cast<T>(val);
    } else {
        throw std::bad_cast();
    }
    return retVal;
}

//Inline to prevent multiple-definition error
namespace custOp {
//Define operators for the ANY objects
    Object operator+(Object lhs, Object rhs);
    Object operator-(Object lhs, Object rhs);
    Object operator*(Object lhs, Object rhs);
    Object operator/(Object lhs, Object rhs);
    Object operator&&(Object lhs, Object rhs);
    Object operator||(Object lhs, Object rhs);

//Only works for ints, doubles, and bools
    bool operator==(Object lhs, Object rhs);
    bool operator!=(Object lhs, Object rhs);
    bool operator>(Object lhs, Object rhs);
    bool operator>=(Object lhs, Object rhs);
    bool operator<(Object lhs, Object rhs);
    bool operator<=(Object lhs, Object rhs);
}

#endif /* OBJECT_H_ */
