// OAEP ! find out about it next.
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

//**********************************************************************
//*                         Function Prototypes                        *
//**********************************************************************
void print_heading();
   // Print the program heading
int is_prime(int number);
   // Checks if a number is prime.
int are_relatively_prime(int number, int k);
   // Checks if two numbers have any common factors
int inverse_modk(int e,int k);
   // Calculates the inverse of a number to a mod
void show_vector(vector<int> &v);
   // Displays vector details
void generate_key();
int extend(int e,int k);
int lcm(int a, int b);
int gcdExtended(int a, int b, int *p_x, int *p_y);
   // Determines the least common multiple of two numbers

//**********************************************************************
//*                           Main Function                            *
//**********************************************************************
int main()
{
   // Print the program heading
   cout << "\n\n\n\n\n";
   print_heading();

   // Generate keys
   cout << "\n\nGenerating the keys";
   cout <<   "\n===================";
   int p, // Prime number
       q, // Other prime
       n, // product of primes
       k, // totient of primes
       d, // inverse of e mod k
       e, x, y, g; // relatively prime to k and randomly generated. 
       
   srand(time(NULL));
   
   // Generate primes p and q
   cout << "\n\n   Generating p and q and";
   cout <<   "\n   checking if they are prime";
   cout <<   "\n   ==========================";
   cout << "\n\n   Looking for p";
   do
   {
      p = rand() % 200;
   }while(!is_prime(p) || p < 150);
  
  cout << "\n\n   Looking for q";
  do
   {
      q = rand() % 200;
   }while(!is_prime(q) || q > int(p/2) || q < 50);


   // make p the bigger number
   
   // Calculate n product of p and q
   cout << "\n\n   Calculating n product of p and q";
   cout <<   "\n   ================================";
   n = p * q;
   cout <<   "\n   n = " << p << " * " << q << " = " << n;


   // Calculate k 
   cout <<  "\n\n   Calculating k product of p - 1 and q - 1";
   cout <<    "\n   ========================================";
   k = (p-1)*(q-1);
   cout <<   "\n   k = " << (p - 1) << " * " << (q - 1) << " = " << k;

   // cout <<  "\n\n   Calculating l LCM of the factors of k";
   // cout <<    "\n   =====================================";

   //k = lcm(p-1,q-1);
 
      // Get e random prime less than k
      cout <<  "\n\n   Generating e relatively prime to k";
      cout <<    "\n   ==================================";
      do
      {	
         e = (rand() % k);
      }while(!is_prime(e) || e >= k || !are_relatively_prime(e, k));

      //Generate d the inverse to of e in mod k
      cout <<  "\n\n   Generating d inverse of e mod k";
      cout <<    "\n   ===============================";
      //g = gcdExtended(e, k, &x, &y);
      g = extend(e, k);
      cout << "\n\n   G: " << x;
      d = inverse_modk(e, k);
      if(x<0)
        d = x + k;
      cout << "\n\n   p: " << p;
      cout <<   "\n   q: " << q;
      cout <<   "\n   n: " << n;
      cout <<   "\n   k: " << k;
      cout <<   "\n   e: " << e;
      cout <<   "\n   d: " << d;
      cout <<   "\n   d * e = " << (d*e); 
      cout << "\n   d * e (mod k) = " << ((d*e) % k);

   // Say goodbye and terminate
   cout << "\n\nThanks for encrypting ;)";
   cout << "\n\n\n\n\n";
   return 0;
}

//**********************************************************************
//*                          Print heading                             *
//**********************************************************************
void print_heading()
{
   cout << "\n\n\n\n\n\n\n";
   cout << "\n==================================================";
   cout << "\n   This program synthesizes messaging encrypted";
   cout << "\nby RSA. Enter a message and watch it be translated";
   cout << "\nto integers, encrypted, sent, decrypted, and then";
   cout << "\nturned back into characters";

}

//**********************************************************************
//*                  Check if a number is prime                        *
//**********************************************************************
int is_prime(int number)
{ 
   int factors     = 2,
       is_it_prime = 1;

   cout << "\n      Checking if " << number << " is prime.";
   if(number%factors == 0)
   {
      cout << "\n         Even number";
      is_it_prime = 0;
   }
   else
      // Maybe make this a different style loop
      for(factors = 3; factors <= int(sqrt(number)); factors+=2)
      {
         if(number%factors == 0)
         {
            is_it_prime = 0;
            cout << "\n         Not prime";
            break;
         }
      }
   if(is_it_prime)
      cout << "\n         Prime!";
   return is_it_prime;
}

//**********************************************************************
//*            Check if a number and k are relatively prime            *
//**********************************************************************
int are_relatively_prime(int e, int k)
{
   // doesnt work when equation is only one deep!!!!!!!!!!!!!!!!!!

   int is_it = 1,
   a, b, c, x; 

   cout << "\n\n   Checking if e: " << e << " and k: " << k 
        << " are relatively prime.";
   a = k;
   b = e;
   x = int(a / b);
   c = a - (b * x);
   
   cout << "\n      " << a << " = " << b << "(" << x << ")" << " + " << c;
   while(c > 1)
   {
      a = b;
      b = c;
      x = int(a / b);
      c = a - (b * x);
      cout << "\n      " << a << " = " << b << "(" << x << ")" << " + " << c;
   } 
   if (c != 1)
      is_it = 0;
   else
      cout << "\n      Relatively prime!";
   return is_it;
}

//**********************************************************************
//*              Find the inverse of a number in a mod                 *
//**********************************************************************
int inverse_modk(int e, int k)
{
   /*e = 157;
   k = 2668;*/
   // DONT CHANGE THIS LIKE EVER. IT WORKS......KINDA
  
   vector<int> v_a,v_b, 
               v_c,v_x; 
   int a, b, c, x, d,i,j,y =1;  
   a = k;                       
   b = e;
   // a = 77;
   // b = 37;
   x = int(a / b);
   c = a - (b * x);
   cout << "\n      " << a << " = " << b << "(" << x << ")" << " + " << c;
   v_a.push_back(a);
   v_b.push_back(b);
   v_c.push_back(c);
   v_x.push_back(x);

   while(c > 1)
   {
      a = b;
      b = c;
      x = int(a / b);
      c = a - (b * x);
      cout << "\n      " << a << " = " << b << "(" << x << ")" << " + " << c;
      v_a.push_back(a);
      v_b.push_back(b);
      v_c.push_back(c);
      v_x.push_back(x);
   }
   
   //cout << "\n\n      Extending the euclidean algorithm";
   for(i = 0; i < v_a.size(); i++)
      cout << "\n      "<< v_c[i] << " = " << v_a[i] << "(" << y << ")" << " - " << v_b[i] << "(" << v_x[i] << ")";
   
   cout << "\n\n      Getting 1 in terms of e and k";
   x = *(v_x.rbegin());
   y = 1;
   
   // Print basic equation 
   cout << "\n      1 = " << *(v_a.rbegin()) << "(" << y << ")" << " - " 
                          << *(v_b.rbegin()) << "(" << x << ")";
   while( v_a.size() > 1 && v_b.size() > 2 ) 
   {
      if(v_b.size() > 2)
      {
         
         v_b.pop_back();

      // Extend/Substitute
      cout << "\n      1 = " << *(v_a.rbegin()) << "(" << y << ")"  << " - "                                    
           << "[" << *(v_a.rbegin() + 1)        << "(" << 1 << ")"  << " - " 
                  << *(v_b.rbegin())            << "(" << *(v_x.rbegin() + 1) << ")" 
           << "]"                               << "("<< x <<")";
      
      // Simplify
      y += *(v_x.rbegin() + 1) * x;
      v_b.pop_back();
      v_x.pop_back();

      // Display
      cout << "\n      1 = " << *(v_a.rbegin())     << "(" << y << ")" 
                             << " - " 
                             << *(v_a.rbegin() + 1) << "(" << x << ")";
      
      }

      if( v_a.size() >= 2)
      {
         v_a.pop_back();
         //show_vector(v_a);
         //show_vector(v_b);

         // Extend
         cout << "\n      1 = [" << *(v_a.rbegin() + 1) << "(1)" 
                                 << " - "
                                 << *(v_b.rbegin())     << "(" << *(v_x.rbegin() + 1) 
                                 << ")]" << "(" << y << ")"
                                 << " - "
                                 << *(v_b.rbegin()) << "(" << x << ")";
            

         // Simplify
         x += y * *(v_x.rbegin() + 1);

         cout << "\n      1 = " << *(v_a.rbegin() + 1)     << "(" << y << ")" 
                             << " - " 
                             << *(v_a.rbegin()) << "(" << x << ")";
      

       
         if(v_a.size() > 1)
            v_a.pop_back();
         v_x.pop_back();


           
          
      }
      
   }
   
   if(v_a.size() == 2 && v_b.size() == 2)
   {
       cout << "\n      1 = " << *(v_a.rbegin()) << "(" << y << ")"  << " - "                                    
           << "[" << *(v_a.rbegin() + 1)        << "(" << 1 << ")"  << " - " 
                  << *(v_b.rbegin())            << "(" << *(v_x.rbegin() + 1) << ")" 
           << "]"   << "("<< x <<")";
   y += *(v_x.rbegin() + 1) * x;
   cout << "\n      1 = " << *(v_a.rbegin() + 1)     << "(" << x << ")" 
                             << " - " 
                             << *(v_a.rbegin()) << "(" << y << ")";
   }
   else
   {
      
   }

   
   return y;
}
 
//**********************************************************************
//*                            Show Vector                             *
//**********************************************************************
void show_vector(vector<int> &v)
{
   int i;      // Increments through vector
       
   cout << "\n\n  Size: "     << v.size()      << " - "
        <<       "Capacity: " << v.capacity()  << " - "
        <<       "Max size: " << v.max_size();
   
   // Loop printing contents of the vector
   for(i = 0; i < v.size(); i++)
   {
      if(i == 0)
         cout << "\n ";
      cout << " " << v[i];
   }
   return;
}

//**********************************************************************
//*                         extend euclidean          (iterative)      *
//**********************************************************************
int extend(int e,int k){
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
         cout << "\n   k   : " << k;
         cout << "\n   e   : " << e;
         cout << "\n   prey: " << prey;
         cout << "\n   prex: " << prex;
      } 
   return 0;
}

//**********************************************************************
//*                      Determine LCD of two numbers                  *
//**********************************************************************
int lcm(int a, int b) 
{
   int oa, ob ,x,c, l ,prec; // pre c is the c before c == 0. so the gcd
   if( b > a)
   {
      x = b;
      b = a;
      a = x;
   }
   oa = a;
   ob = b;
   x = int(a / b);
   c = a - (b * x);
   
   cout << "\n      " << a << " = " << b << "(" << x << ")" << " + " << c;
   while(c > 0)
   {
      a = b;
      b = c;
      x = int(a / b);// make sure this works properly
      prec = c;
      c = a - (b * x);

      cout << "\n      " << a << " = " << b << "(" << x << ")" << " + " << c;
   } 
   l = int((oa*ob)/prec);
   return l;
}

int gcdExtended(int a, int b, int *p_x, int *p_y)
{
    // Base Case
    if (a == 0)
    {
        *p_x = 0;
        *p_y = 1;
        return b;
    }
 
    int x1, y1; // To store results of recursive call
    int gcd = gcdExtended(b%a, a, &x1, &y1);
 
    // Update x and y using results of recursive
    // call
    *p_x = y1 - (b/a) * x1;
    *p_y = x1;
 
    return y1;
}