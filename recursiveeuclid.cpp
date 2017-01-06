#include <cstdlib>
#include <iostream>
using namespace std;
//**********************************************************************
//*                         Function Prototypes                        *
//**********************************************************************
int gcd(int e, int k);
   // Print the program heading
int regcd(int e, int k);
   // Print the program heading
int extend(int e, int k);
   // Checks if a number is prime.

//**********************************************************************
//*                           Main Function                            *
//**********************************************************************
int main(){
   int e,k;

   cout << "\n\n   Enter e: ";
   cin  >> e;
   cout << "   Enter k: ";
   cin  >> k;
   //extend(e,k);
   // cout << "\nnonrecursive ";
   // gcd(e,k);
   // cout << "\nrecursive ";
   k = regcd(k,e);
   // // cout << "\n   k: " << k;
   cout << "\n\n ";

   return 0;
}
//**********************************************************************
//*                         euclidean gcd              (iterative)     *
//**********************************************************************
int gcd(int e,int k){
	int temp;
	temp = k;
	while(e)
	   {
	   	temp = k;
	   	k = e;
	   	e = temp % e;
	   	cout << "\n   k: " << k;
	   	cout << "\n   e: " << e;
      } 
      
	return k;
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
//*                         euclidean gcd  (recursive)                 *
//**********************************************************************
int regcd(int k, int e)
{
   if (e == 0 || e == 1)
      return k;
   else
   {
   	cout << "\n" << k << " = " << e << "(" << int(k/e) << ") + " << (k - e*(int(k/e)));
      return regcd(e, k % e);
   }
}
