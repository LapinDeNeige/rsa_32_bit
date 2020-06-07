#include "rsa.h"
#include <iostream>
#include "str.h"
#include <string>
#include <time.h>
#include <vector>



//encrypt a word
//and code it in base_32

//closed key(for decrypting) 
//not share


/*TODO

1)To bring a code to the more final state
2)Create a terminal interaction
*/



int main(int argc,char **argv)
{




key open_key;
key close_key;

char msg[30]="qwrz";
size_t sz=strlen(msg);
unsigned int *ms=new unsigned int[sz+1];

std::vector <string> op_k; //open key in string
std::vector <string> cls_k; //close key in string 
std::vector <string> str_mes;

rsa_init_key(&open_key);//init a key

generate_open_key(&open_key);//genera
generate_close_key(&close_key,&open_key);

std::cout<<open_key.e<<open_key.mod<<"\n\n";

op_k=encd(open_key); //encode keys
cls_k=encd(close_key);

encr(msg,open_key,ms); //encrypt
str_mes=encd_mes(ms,strlen(msg)); //encode message

std::cout<<"encoded message ";
for(size_t i=0;i<strlen(msg);i++)
	std::cout<<str_mes[i]<<"\t";

memset(msg,0,strlen(msg));
decrypt(ms,close_key,msg,sz);

delete[]ms;

std::cout<<"decrypted message\t "<<msg<<"\n";


return 1;
}
