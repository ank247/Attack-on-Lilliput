#include<iostream>
using namespace std;

void permutation(uint64_t *EncryptedNumber, uint64_t key1[])
{
  uint64_t key2[16], permuted_number[16];                           /* Final output is permuted_number Array. */
  for(int i = 0; i < 16; i++)
  {
    key2[key[i]] = EncryptNumber[i];                                /* Stored key1 Array will instruct permutation. */
  }
  for(int i = 0; i < 16; i++)
  {
     EncryptNumber[i] = key2[i] ;                                  /* For next round EncryptNumber Array will serve as an initial Array. */
  }
  for(int i = 0; i < 16; i++)
  {
     permuted_number[i] = key2[16-i] ;
  }
}

int main()
{
 
  return 0;
}
