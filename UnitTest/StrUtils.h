/*
 * StrUtils.h
 *
 *  Created on: Oct 11, 2014
 *      Author: tpad
 */

#ifndef STRUTILS_H_
#define STRUTILS_H_


#include <string>
#include <vector>

class StrUtils
{
public:
    static void split(std::string const & src, std::string const & delimiter, std::vector<std::string> & dst);
    
private:
    StrUtils(void);
};

#endif /* STRUTILS_H_ */
