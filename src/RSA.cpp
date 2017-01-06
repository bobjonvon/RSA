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
#define MAX_MESSAGE_LENGTH 150 // arbitrary length for memory allocation 
                               // purposes
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
       n, // Product of p and q and modulus
       k, // range
       d, // relatively prime to kinverse of mod k 
       e; // inverse of d mod k
       
   srand(time(NULL));
   
   // Generate primes p and q
   cout << "\n\n   Generating p and q and";
   cout <<   "\n   checking if they are prime";
   cout <<   "\n   ==========================";
   cout << "\n\n   Looking for p";
   do
   {
   p = rand() % 100;
   }while(!is_prime(p) || p < 3);
  
  cout << "\n\n   Looking for q";
  do
   {
   q = rand() % 100;
   }while(!is_prime(q) || q < 3 || q == p);

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

   // Get e relatively prime to k
   cout <<  "\n\n   Generating e relatively prime to k";
   cout <<    "\n   ==================================";
   do
   {	
      e = (rand() % k);
   }while(!are_relatively_prime(e,k));

   //Generate d the inverse to of e in mod k
   cout <<  "\n\n   Generating d inverse of e mod k";
   cout <<    "\n   ===============================";
   d = inverse_modk(e, k);
   // if((d * e) % k != 1)
   // {
   //    d = inverse_modk(k,e);
   //    cout << "\n\n    WAS REVERSED";
   // } Had a theory things were backwards. doesnt seem to be the problem though

  
   
   cout << "\n\n   p: " << p;
   cout <<   "\n   q: " << q;
   cout <<   "\n   n: " << n;
   cout <<   "\n   k: " << k;
   cout <<   "\n   e: " << e;
   cout <<   "\n   d: " << d;
   cout << "\n   d * e = " << (d*e); 

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
{ /////////////////////25 was called prime so...............

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
         //cout << "\n Checking if " << factors << " is a factor"; 
         if(number%factors == 0)
         {
            //cout << "\n      " << factors << " is a factor of " << number;
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
   // DONT CHANGE THIS LIKE EVER. IT WORKS......KINDA
   // nah man clean this garb up. // Actually it doesnt work when it finishes on the right !!!!!!!!!!!!!!!!!!!!!!!!!!!! 
   vector<int> v_a,v_b, // Integer vectors to store needed info to extend 
               v_c,v_x; // euclid. could probably do this with just 2
   int a, b, c, x, d,i,j,y =1;  // If I had to guess it looks like the x vector is depleted before the algorithm finishes
   a = e;                       // It looks like the left sides simplification isnt affected by it but the right sides
   b = k;
   // a = 77;
   // b = 37;
   x = int(a / b);
   c = a - (b * x);
   cout << "\n      " << b << " = " << a << "(" << x << ")" << " + " << c;
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
   
   cout << "\n\n      Extending the euclidean algorithm";
   for(i = 0; i < v_a.size(); i++)
      cout << "\n      "<< v_c[i] << " = " << v_a[i] << "(" << y << ")" << " - " << v_b[i] << "(" << v_x[i] << ")";

   cout << "\n\n      Getting 1 in terms of e and k";
   x = *(v_x.rbegin());
   y = 1;

   // cout << "\n A";
   // show_vector(v_a);
   // cout << "\n B";
   // show_vector(v_b);
   // cout << "\n C";
   // show_vector(v_c);
   // cout << "\n X";
   // show_vector(v_x);
 
   
   
   // Print basic equation 
   cout << "\n      1 = " << *(v_a.rbegin()) << "(" << y << ")" << " - " 
                          << *(v_b.rbegin()) << "(" << x << ")";

   while( v_a.size() > 1 && v_b.size() > 1 ) 
   {
      if(v_b.size() > 1)
      {
         
         v_b.pop_back();

      // Extend/Substitute
      cout << "\n      1 = " << *(v_a.rbegin()) << "(" << y << ")"  << " - "                                    
           << "[" << *(v_a.rbegin() + 1)        << "(" << 1 << ")"  << " - " 
                  << *(v_b.rbegin())            << "(" << *(v_x.rbegin() + 1) << ")" 
           << "]"                               << "("<< x <<")";
      // Simplify
      //cout << "\n here -> " << *(v_x.rbegin());
      y += *(v_x.rbegin() + 1) * x;
      v_b.pop_back();
      v_x.pop_back();
      // Display
      cout << "\n      1 = " << *(v_a.rbegin())     << "(" << y << ")" 
                             << " - " 
                             << *(v_a.rbegin() + 1) << "(" << x << ")";
      cout << "\n    size of x: " << v_x.size();
      }

      if( v_a.size() > 2)
      {
         v_a.pop_back();
         

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
         v_a.pop_back();
         if (v_x.size() > 3)
            v_x.pop_back();


           
          
      }
      
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