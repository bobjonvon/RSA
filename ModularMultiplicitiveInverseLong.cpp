#include <iostream>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <time.h>
#include <vector>
using namespace std;

int main()
{
	int e,k,d;
    
   cout << "\n\n   Enter the e: ";
   cin  >> e;
   cout << "   Enter the k: ";
   cin  >> k;

   for(d = 1; d <= k; d++)
   {
   	cout << "\nd: " << d <<"   d * e (mod k) = " << ((d*e) % k);
      if((d*e) % k == 1)
         break;
   }
   


   return 0;
}