//
// Created by Shaza Ali on 13/10/2024.
//

#ifndef CSE332LAB_LAB2HEADER_H
#define CSE332LAB_LAB2HEADER_H

enum index{
    name = 0,
    inputname = 1,
    expargc = 2
};

enum ReturnCode{
    success = 0,
    wrongsize =1,
    invalidargs = -1,
    filenotopen = -2,
    invalidformat = -3,
    fileopen = 2
};

void toLowerCase(std::string& st);


#endif //CSE332LAB_LAB2HEADER_H
