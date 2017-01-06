#include <iostream>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <time.h>
#include <vector>
using namespace std;

//**********************************************************************
//*                         Symbolic Constants                         *
//**********************************************************************
#define pMIN_PRIME 400  // Min prime number
#define pMAX_PRIME 500  // Max prime number


//**********************************************************************
//*                         Function Prototypes                        *
//**********************************************************************
int is_prime(int number);
   // Checks if a number is prime.
int are_relatively_prime(int number, int k);
   // Checks if two numbers have any common factors
int generate_random_prime(int min, int max);
   // Generates a random prime within a range(Not crypto safe)
int calculate_n(int p, int q);
   // Calculates the product of primes p and q
int calculate_totient(int p, int q);
   // Calculates the totient of primes p and q
int inverse_mod(int e,int k);
   // Calculates the inverse of e in mod k
void generate_keys(int *p_encrypt, int *p_decrypt, int *p_mod);
  // Generates RSA keys


//**********************************************************************
//*                           Main Function                            *
//**********************************************************************
int main()
{
   int encrypt, decrypt, mod;
   srand(time(NULL));
   // Print the program heading
   cout << "\n\n\n\n\n";
   generate_keys(&encrypt, &decrypt, &mod);
   
   cout << "\n\nThanks for encrypting ;)";
   cout << "\n\n\n\n\n";
   return 0;
}

//**********************************************************************
//*                  Check if a number is prime                        *
//**********************************************************************
int is_prime(int number)
{ 
   int factors     = 2,
       is_it_prime = 1;

   
   if(number%factors == 0)
   {
      
      is_it_prime = 0;
   }
   else
      // Maybe make this a different style loop
      for(factors = 3; factors <= int(sqrt(number)); factors+=2)
      {
         if(number%factors == 0)
         {
            is_it_prime = 0;
            
            break;
         }
      }
   
      
   return is_it_prime;
}

//**********************************************************************
//*            Check if a number and k are relatively prime            *
//**********************************************************************
int are_relatively_prime(int e, int k)
{

   int is_it = 1,
   a, b, c, x; 
   a = k;
   b = e;
   x = int(a / b);
   c = a - (b * x);
   
   while(c > 1)
   {
      a = b;
      b = c;
      x = int(a / b);
      c = a - (b * x);
   } 

   if (c != 1)
      is_it = 0;
  
   return is_it;
}

//**********************************************************************
//*                        inverse of E in mod K                       *
//**********************************************************************
//Will return a negative
int inverse_mod(int e,int k){
   int temp,
       x,
       y,
       q,
       prex,
       prey;
   
   x    = 0;
   prex = 1;
   y    = 1;
   prey = 0;
   while(e) 
      {
         // q
         q    = int(k/e);
         // x and prex
         temp = x;
         x    = prex - (q * temp);
         prex = temp;
         // y and prey
         temp = y;
         y    = prey - (q * temp);
         prey = temp;
         // k and e
         temp = k;
         k    = e;
         e    = temp % e;
      }   
   return prey;
}

//**********************************************************************
//*                        calculate n                                 *
//**********************************************************************
int calculate_n(int p, int q)
{
   return p * q;
}

//**********************************************************************
//*                         calculate totient                          *
//**********************************************************************
int calculate_totient(int p, int q)
{
   return (p-1) * (q-1);
}

//**********************************************************************
//*                         Generate RSA keys                          *
//**********************************************************************
void generate_keys(int *p_encrypt, int *p_decrypt, int *p_mod)
{
   int p = generate_random_prime(pMIN_PRIME, pMAX_PRIME); // First prime 
   cout << "\n           P: "  << p;
   cout << "\n           P: "  << p;
   int    q = generate_random_prime(100, p/2); // Second prime
   cout << "\n           Q: "  << q;
   cout << "\n           Q: "  << q;
   int    n = calculate_n(p, q);                     // product of p and q
   cout << "\n           N: "  << n;
   int    k = calculate_totient(p, q);               // Totient of p and q
   cout << "\n           K: "  << k;
   int    e = generate_random_prime(100, k); // relatively prime 
   cout << "\n           E: "  << e;
                                                       // to k
   int    d = inverse_mod(e, k);                     // inverse of e in mod k
   cout << "\n           D: "  << d;
   if(d<0)
      d+=k;
   cout << "\n           P: "  << p;
   cout << "\n           Q: "  << q;
   cout << "\n           N: "  << n;
   cout << "\n           K: "  << k;
   cout << "\n           E: "  << e;
   cout << "\n           D: "  << d;
   cout << "\n D * E MOD K: "  << (d*e)%k;
   *p_encrypt = e;
   *p_decrypt = d;
   *p_mod     = n;

}

//**********************************************************************
//*                         Generate random prime                      *
//**********************************************************************
int generate_random_prime(int min, int max)
{
   int random;
   
   do
   {
      random = rand() % max;
   }while(!is_prime(random) || random < min);
   return random;
}
