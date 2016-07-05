#ifndef LOG_HPP
#define LOG_HPP

#include <stdio.h>
#include <stdarg.h>

#define Log(...) { fprintf(stderr, __VA_ARGS__); fprintf(stderr, "\n"); }

#define LogLine(...) { fprintf(stderr, __VA_ARGS__); }






#endif // LOG_HPP

