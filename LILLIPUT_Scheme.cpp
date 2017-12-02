/* C++ for the following. */

#include<iostream>
using namespace std;
#include<stdlib.h>
#include<string.h>

uint64_t *Binary_Conversion(char *A)
{  
  int i;
   char *BinaryConversion ;
   BinaryConversion = '' ;
  for(i = 0; i < '\0'; i++)
  {
    int a;
    a = numeric(A[i]) ;                                       /* finding numeric value of letter, symbols for converting into bits.*/
    uint64_t b;
    b = binary(a) ;
    BinaryConversion = strcat(BinaryConversion, b) ;
  }
  return &BinaryConversion;
}

uint64_t XOR(uint64_t A, uint64_t B)                                             /* Exclusive-OR function. */
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

/* The key will be an array of 1-digit(0 or 1) consisting. */
/* SBox will be similar to key-generation, but with unique speciality of rounding. */
/* SBox and key are generated and sent by an array for XOR. */
/* Arrays will be known with length of 8. */
/* l is start and m is end. */

int j = 0;                                                     /* A global j. for static call. */

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
  char *A;                                   /* Input the PlainText. */
  uint64_t *b;                               /* Binary number stored. */
  uint8_t key[16], key1[16], RK[2] ;         /* RK are two binary digits[0,1] used as a key*/
  int round;                                 /* Number of rounds to be performed. */
  cin >> round;
  cin >> A ;                                 /* Input the Arbitrary String(including integers, symbols and so on) */
  b = Binary_Conversion(A);
  int n, i;
  n = strlen(b);
  if(int m = (n = n % 16) != 0)
  {
    for(i = 0; i < m; i++)
    {
      strcat(b,0);                           /* converting string to the multiple of 16 bits. */
    }
  }
  uint64_t *EncryptedNumber;
  n = strlen(b);
  do{
      Encrypted_Number(EncryptedNumber, b, n);
      permutation(EncryptedNumber, key1, permuted_number);
      round--;
  }while(round > 0)
  return 0;
}
