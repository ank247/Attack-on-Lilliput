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
  uint64_t EncryptNumber[16], permuterd_key[16];
  uint64_t key1[16], key2[16];
  int i;
  for(int i = 0; i < 16; i++)                     /* For sake of understanding EncryptNumber is taken as a user input. */
  {
   cin >> EncryptNumber[i];
  }
  for(int i = 0; i < 16; i++)                      /* But key1 Scheme is taken as a user input. */
  {
    cin >> key1[i];
  }
  return 0;
}
