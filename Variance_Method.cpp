#include<iostream>
using namespace std;

int main()
{
  uint64_t *EncryptNumber ;              /* EncryptNumber is the array we get before permutation. */
  uint64_t key[16], SBox[16];            /* key and SBox is an array of length 16 consisting [1,0] arbitrary bits, an user input.  */
  int i;
  for(i = 0; i < 16; i++)
  {
    cin >> key[i]; 
  }
   for(i = 0; i < 16; i++)
  {
    cin >> SBox[i]; 
  }
  return 0;
}
