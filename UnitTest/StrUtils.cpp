/*
 * StrUtils.cpp
 *
 *  Created on: Nov 3, 2014
 *      Author: tpad
 */

#include "StrUtils.h"


void StrUtils::split(std::string const & src, std::string const & delimiter, std::vector<std::string> & dst)
{
    size_t fromIdx = 0;
    size_t i;

    while (std::string::npos != (i = src.find(delimiter, fromIdx)))
    {
        dst.push_back(std::string(src.begin() + fromIdx, src.begin() + i));

        fromIdx = i + delimiter.size();
    }

    dst.push_back(std::string(src.begin() + fromIdx, src.end()));
}
