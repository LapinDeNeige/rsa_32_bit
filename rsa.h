#include <stdio.h>
#include "binpow.h"
#include "gen_prm.h"
#include <math.h>

#ifndef RSA_H
#define RSA_H
struct key
{
unsigned int e; //exponent
unsigned int mod; //

};




void rsa_init_key(key *k);
void generate_open_key(struct key *k);
void generate_close_key(key *cls_key,key *op_key);
void decrypt (unsigned int *ms,key cls_key,char * out,size_t siz);

void encr(char *mes,key open_key,unsigned int* enc );

template <typename A>
void print(A* in,bool st);

#endif
