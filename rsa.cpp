//#include <stdio.h>
//#include "binpow.h"
//#include "gen_prm.h"
//#include <math.h>

#include "rsa.h"

#define NUM 65534
#define RANG 65334


//RSA lib
//64 bit key
//32 bit modulus

/*
struct key
{
unsigned int e; //exponent
unsigned int mod; //

};
*/


unsigned int eul_m=0;


unsigned int get_d (unsigned int a , unsigned int b ) //Euclid Alghoritm
{//get GCD

unsigned int c=1;

while(c!=0)
{
c=a%b;
a=b;
b=c;
}

return a;
}


int ext_d(int a,int b) //exteded Euclid alghoritm
{                      //for finding inverse number modulo mod n=(a^-1)mod m
int p=1,q=0,r=0,s=1;
int x,y;

while(a&&b)
{
if(a>=b)
{
a=a-b;
p=p-r;
q=q-s;

}

else
{
b=b-a;
r=r-p;
s=s-q;
}

}

if(a)
	y=q;
else
	y=s;

return y;

}


//find open exponent coprime with 
void generate_open_key(struct key *k)
{

k->e=gen_prime(RANG); //generate exponent
unsigned int q=::eul_m;

//must be coprime with (p-1)*(q-1)
while(1)
{
if(get_d(q,k->e)==1) //if coprime 
	break;

k->e=gen_prime(RANG);
//k->e=k->e+2;

}
}


void generate_close_key(key *cls_key,key *op_key)
{

 cls_key->mod=op_key->mod;

unsigned int c=ext_d(::eul_m,op_key->e);//find inverse number modulo 

cls_key->e=c;

}




////////////////////////////////////////////////////////////////////////////////



////////////////////////////////////////////////////////////////////////////////



void decrypt (unsigned int *ms,key cls_key,char * out,size_t siz)
{

//int siz=sizeof(ms);
for(int i=0;i<siz;i++)
{
unsigned int tmp=binpow(ms[i],cls_key.e,cls_key.mod);

out[i]=(char)tmp;
}



}




void encr(char *mes,key open_key,unsigned int* enc )
{

for(int i=0;i<strlen(mes);i++)
{
unsigned int tmp=(int)mes[i]; //message
enc[i]=binpow(tmp,open_key.e,open_key.mod); //mes^open_exp mod m

}


}



void rsa_init_key(key *k) //initiate modulus
{ 
unsigned int p=gen_prime(NUM);
unsigned int q=gen_prime(NUM);

k->mod=p*q;//modulus
::eul_m=(p-1)*(q-1); //


}

template < typename A>
void print(A *in,bool st)
{
int siz=sizeof(in)/sizeof(A);

for(int i=0;i<siz;i++)
	std::cout<<in[i];
if(st)
	std::cout<<"\n";
}


/*
int main()
{

key one;
key two;

rsa_init_key(&one);


generate_open_key(&one);
generate_close_key(&two,&one);

std::cout<<"open key:\t"<<one.e<<one.mod<<"\n";
std::cout<<"open key bit\t"<<(int)(log2(one.e)+log2(one.mod))<<"\n";

std::cout<<"close key:\t"<<two.e<<two.mod<<"\n";
std::cout<<"close key bit\t"<<(int)(log2(two.e)+log2(two.mod))<<"\n";



unsigned int ho[10]={0};
char m[11]="lurk ma";

std::cout<<"message\t";
print(m);

encr(m,one,ho);
std::cout<<"encrypted \t";
print(ho);




std::cout<<"\n\n";

memset(m,0,5);

decrypt(ho,two,m);

std::cout<<"\ndecrypted message\t";
print(m);


return 0;
}
*/
