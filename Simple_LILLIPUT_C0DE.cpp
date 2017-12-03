/* Sample Input:
   BinaryInput:                 1 0 1 0 1 1 0 1 0 1 1 1 0 1 1 0
   key_before_Sbox:             0 1 1 0 1 1 1 0 1 1 0 0 1 0 1 1
   permutation_arrangement:     14 10 15 9 11 12 13 16 5 6 4 2 3 7 1 8
   SBox:                        1 0 1 0 1 0 0 1 0 1 0 1 0 0 1 1 
*/


#include<iostream>
using namespace std;
#include<stdlib.h>
#include<string.h>

int XOR(int A, int B)                                             
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

void Encrypted_Number(int EncryptedNumber[], int b[], int l, int m, int key[], int S[], int j) 
{
  int mid;                                               
  mid = (l + m)/ 2;
  int J[16] ;
  int n = mid - 1 - j;
  if(n > l - 1)
  {
  J[mid - 1 - j] = XOR(b[mid - 1 - j], key[j]);              
  J[mid - 1 - j] = XOR(S[j], J[mid - 1 - j]);                
  EncryptedNumber[mid - 1 - j] = b[mid - 1 - j];             
  if(n + 1 == l + 8)                                         
  {
    J[mid + j] = XOR(b[mid + j], J[mid - 1 - j]); 
    EncryptedNumber[mid + j] = J[mid + j];
  }
  
  else if(n == l)                                             
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
  else                                                     
  {
    J[mid + j] = XOR(b[mid + j], J[mid - 1 - j]);
    J[mid + j] = XOR(J[mid + j], J[mid - 1]);
    EncryptedNumber[mid + j] = J[mid + j];
  }
 
    j++;
    return Encrypted_Number(EncryptedNumber, b, l, m, key, S, j); 
  }
}

void permutation(int EncryptNumber[], int key[], int permuted_number[])
{
  int key2[16];                            
  for(int i = 0; i < 16; i++)
  {
    key2[key[i]] = EncryptNumber[i];                                 
  }
  for(int i = 0; i < 16; i++)
  {
     EncryptNumber[i] = key2[i] ;
     cout << EncryptNumber[i] << ' ';
  }
  
  cout << '\n';
  
  for(int i = 0; i < 16; i++)
  {
     permuted_number[i] = key2[16-i] ;
     cout << permuted_number[i] << ' ';
  }
}

int main()
{
  int EncryptedNumber[16];                  
  int key[16], key1[16], SBox[16];                  
  int round = 1;                                  
  int BinaryString[16];
  int i, j = 0;
  for(i = 0; i < 16; i++)
  {
      cin >> BinaryString[i];
  }
  cout << '\n';
  int permuted_number[16];
  for(i = 0; i < 16; i++)
  {
      cin >> key[i];
  }
  for(i = 0; i < 16; i++)
  {
      cin >> key1[i];
  }
  for(i = 0; i < 16; i++)
  {
      cin >> SBox[i];
  }
   int l = 0, m = 15;           
   int ReverseEncrypt[16];
   Encrypted_Number(EncryptedNumber, BinaryString, l, m, key, SBox, j);
   for(i = 0; i < 16; i++)
  {
      ReverseEncrypt[i] = EncryptedNumber[15-i];
  }
  for(i = 0; i < 16; i++)
  {
    EncryptedNumber[i] = ReverseEncrypt[i];
    cout << EncryptedNumber[i] << ' ';
  }
   cout << '\n';
  
   permutation(EncryptedNumber, key1, permuted_number);
   return 0; 
}
