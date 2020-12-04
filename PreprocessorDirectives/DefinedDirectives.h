//
// Created by cigan on 02.12.2020.
//

#ifndef EPLUSPLUS_DEFINEDDIRECTIVES_H
#define EPLUSPLUS_DEFINEDDIRECTIVES_H

#ifndef STANDARD_LENGTH
#define STANDARD_LENGTH 1000
#endif

#ifndef NEWLINE
#define NEWLINE() std::cout << std::endl;
#endif

#ifndef LOG_BUG
#define LOG_BUG(parameter) std::cerr << parameter << std::endl;
#endif

#endif //EPLUSPLUS_DEFINEDDIRECTIVES_H
