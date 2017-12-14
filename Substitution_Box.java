/***** Generation of Random Function before XOR with the parsed other side block. *****/
/* In general, len(key) has the largest bit-length among the len(tweak), len(EncryptedSide) and so on*/
/* Max. len(PlainText) = 128 Bits. */
/* Max. len(key) = 128 Bits. */
/* tweak is an user input at every instance of requirement. */
/* 'k' is the no. of round the encryption is passing by. */

public class String function(String key, String tweak, int k, int n, String EncryptedSide, int BlockSize)
   {   
                                                                           /* Function-Key generation. */
     String FunctionOut;
     int padding, padding_;
     key = key * k;
     EncryptedSide = EncryptedSide * k;
     EncryptedSide = ("\0", key, EncryptedSide); 
     FunctionOut = BinaryConversion(EncryptedSide);
     FunctionOut = strcat(FunctionOut, tweak);
     padding_ = length(FunctionOut);
     padding = padding_ % n;
   
     if(padding_ > n)
      {
          for(i = 0; i < n - padding; i++)
             {
                 FunctionOut = FunctionOut +  '0';                         /* Concatenating with 0's. Now, key2 is multiple of 'n'. */
             }
      }   
   
     int l, count = 0, m;
     padding_ = length(FunctionOut);
     String Function;
     m = 2 * n;
    /* Parsing the Bit-String into multiple of n-length. */
     for(i = 0; i < n; i++)
     {
        Function[i] = XOR(FunctionOut[i], FunctionOut[m + i]);
     }
    while(i < padding_)
    {
      int j = 0;
      for(i = m; i < m + n; i++)
      {
        Function[j] = XOR(Function[j], FunctionOut[i]);
        j++;
      }
      m = m + n;
    }
 }

