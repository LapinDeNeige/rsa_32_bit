#include "str.h"


std::vector <string> encd(struct key k) //encode key to string
{
std::vector <string>ret;

std::string k_e;
std::string k_mod;

std::stringstream ss;
std::stringstream s;

s<<k.e;
ss<<k.mod;

k_e=encode(s.str());//encode expoent
k_mod=encode(ss.str()); //encode modulo

ret.push_back(k_mod);
ret.push_back(k_e);

return ret;
}

void decd (vector <string> st,struct key *k) //decode key
{
k->e=atoi(st[0].c_str());
k->mod=atoi(st[1].c_str());
}

std::vector <string> encd_mes(unsigned int *ms,size_t sz) //encode encrypted message
{
std::vector <string> ret;
std::stringstream s;

for(size_t i=sz;i>0;i--)
{
s<<ms[i-1];
std::string cur=encode(s.str());
ret.push_back(cur);

}

return ret;
}

void decd_mes(unsigned int *ms,std::vector <string> en)
{
for(size_t i=0;i<en.size();i++)
{
std::string cr=decode(en[i]);
ms[i]=atoi(cr.c_str());

}

}
