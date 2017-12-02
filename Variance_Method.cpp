#include<iostream>
using namespace std;

int main()
{
  uint64_t *EncryptNumber ;              /* EncryptNumber is the array we get before permutation. */
  uint64_t key[16], SBox[16];            /* key and SBox is an array of length 16 consisting [1,0] arbitrary bits, an user input.  */
  uint64_t BitString[16];                /* Considering Array with 16 Bits as a PlainText. */
  int i;
   for(i = 0; i < 16; i++)
  {
    cin >> BitString[i]; 
  }
  for(i = 0; i < 16; i++)              
  {
    cin >> key[i]; 
  }
  for(i = 0; i < 16; i++)              /* For now as a convenience taken as an user input. */
  {
    cin >> SBox[i]; 
  }
  
  return 0;
}
