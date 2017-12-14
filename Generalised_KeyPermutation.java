/*****  Key Permutation with each i-th round before Function call. *****/
/* 'a' is a large number. */
/* 'b' is equal to Array_Size. */
/* main function is ignored. Just function for KeyPermutation is shown. */

public class KeyPermutation
{
   public static power                                                               /* object creation as power. */
    {
      double number;
    } 
   static void modulus(double a, int Round, double b, power s1)
   {
     double num = 1;    
     for(i = 0; i < Round; i++)
     {
       num = num * a;                                                                /* Calculation of power of 'a'. */
     }
     s1.number = num % b;                                                            /* Mod with respect to Array_Size. */
   }
   static void Key_Permutation(String[] Key_Generated, int Round, double a, double b, )
     {
        modulus(a, Round, b, s1);
        s1.number = Key_Generated[s1.number];                                       /* s1.number is the Returned KeyPermuted value.*/
     }

//  public static void main(String args[])
//    {
//       power s1 = new power();                                                     /* s1 assigned as object named power. */
//       Key_Permutation(Key_Generated, Round, a, b, s1);                            /* Permutation call; all the types provided are considered to be defined. */
//    }    
}
