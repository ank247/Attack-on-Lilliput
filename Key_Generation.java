/***** Generation of a set with combination of bit-string with each of 128-bit. *****/ 
/* Total nos. of key-generated is equivalent to pow(m, n). */
/* 'm' is the total nos. of variable to be used. */
/* 'n' is the length of the string of the key that to be generated. */
/* For the given set, n = 128 and m = 2. A[m] = {0, 1}. */

public class KeyGeneration
{
    static void pow(int a, int b)
    {
      double num = 1;                                                            /* Double for more than 32 bits. */
        for(int i = 0; i < b; i++)
        {
          num = num * a;                                                         /* Multiplication of 2 with each round. */
        }
        return num;
    }
    public static void main(String args[])
    {
       int i = 2;
       String Key_Generated[] = new String[pow(2, 128)];                         /* Max. size allocation of Array.*/
       Key_Generated[0] = '0';
       Key_Generated[1] = '1';
       for(double j = 1; j < Key_Generated.length; j++)                      /* Dynamic allocation of sizeof Key_Generated Array */
        {
           if(Key_Generated.length < pow(2, 128))
             {
                Key_Generated[i] = cate(Key_Generated[j], Key_Generated[0]);  /* String concatenation with 0's. */
                i++;
                Key_Generated[i] = cate(Key_Generated[j], Key_Generated[1]);  /* String concatenation with 1's. */
                i++;
             }
           else
             {
               break;
             }
        }
      for(i = 0; i < Key_Generated.length; i++)
        {
           while(length(Key_Generated[i] < 128))
             {
                 cate( '0', Key_Generated[i]);                                 /* Conversion into 128 bits-string. */
             }
        }
    }
}
