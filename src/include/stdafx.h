#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <map>


//simple blunt solution for output only in debug build
#ifdef DEBUG
#define dout std::cout
#else
#define dout 0 && std::cout
#endif