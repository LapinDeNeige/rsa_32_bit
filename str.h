#include <cstdlib>
#include <string>
#include <sstream>
#include "base_32_lib/base.h"
#include <vector>
#include "rsa.h"

#ifndef _STR_H_
#define _STR_H_

//this module is dedicated for encoding and decoding of keys and messages
//to base 32 

std::vector<string>encd (struct key k);

void decd(std::vector <string>  st,struct key *k);

std::vector <string> encd_mes(unsigned int *ms,size_t sz);

void decd_mes(unsigned int *ms,std::vector <string> en);

#endif
