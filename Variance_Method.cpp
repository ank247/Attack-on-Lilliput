#include<iostream>
using namespace std;
#include<string.h>

void XOR(uint64_t A, uint64_t B)
{
  if(A == B)
   {
    return 0;
   }
  else if(A != B)
   {
    return 1;
   }
}

void Encrypted_Number(uint64_t *EncryptedNumber, uint64_t *b, int l, int m, uint64_t key, uint64_t S_Box) 
{
  static int j ;                                               /* static int to let add on 1 on each call. */
  int l, m, mid;                                               
  mid = (l + m)/ 2;
  uint64_t *J ;                                                /* An rough Array to store the Jth inter-mediate XOR output. */
  int n = mid - 1 - j;
  
  if(n == l+1)                                                /* Break in order to call next 16 bits. */
  {
    break;
  }
  
  J[mid - 1 - j] = XOR(b[mid - 1 - j], key[j]);              /* Key XOR for 1st Jth bit from mid-1. */
  J[mid - 1 - j] = XOR(S[j], J[mid - 1 - j]);                /* S-Box XOR for the same 2nd Jth of the same bit from mid-1. */
  EncryptedNumber[mid - 1 - j] = b[mid - 1 - j];             /* Finally stored for Permutation. */
  
  if(n + 1 == l + 8)                                         /* Mid-point case. */
  {
    J[mid + j] = XOR(b[mid + j], J[mid - 1 - j]); 
    EncryptedNumber[mid + j] = J[mid + j];
  }
  else if(n == l)                                            /* End-point case. */
  {
    J[mid + j] = XOR(b[mid + j], J[mid - 1 - j]);
    J[mid + j] = XOR(J[mid + j], J[mid - 1]);
    J[mid + j] = XOR(J[mid + j], J[mid - 2]);
    J[mid + j] = XOR(J[mid + j], J[mid - 3]);
    J[mid + j] = XOR(J[mid + j], J[mid - 4]);
    J[mid + j] = XOR(J[mid + j], J[mid - 5]);
    J[mid + j] = XOR(J[mid + j], J[mid - 6]);
    J[mid + j] = XOR(J[mid + j], J[mid - 7]);
    EncryptedNumber[mid + j] = J[mid + j];
  }
  else                                                     /* General cases. */
  {
    J[mid + j] = XOR(b[mid + j], J[mid - 1 - j]);
    J[mid + j] = XOR(J[mid + j], J[mid - 1]);
    EncryptedNumber[mid + j] = J[mid + j];
  }
  j++;
  return Encrypted_Number(EncryptedNumber, b, l, m, key, S_Box);    /* Recursion function call. */
}

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
  for(i = 0; i < 16; i++)               /* For now as a convenience taken as an user input. */
  {
    cin >> SBox[i]; 
  }
  Encrypted_Number(EncryptNumber, BitString, l, m, key, SBox);
  return 0;
}
