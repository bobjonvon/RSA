#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
	int base,
       exponent,
       mod,
       power;
  long int answer;
   cout << "\n\n\n\n";
   cout << "\n\n   Modular Exponentiation";
   cout <<   "\n   ------------------";
   
   // Get the input/starting values
   cout << "\n\n   Enter the base: ";
   cin  >> base;
   cout << "   Enter the exponent: ";
   cin  >> exponent;
   cout << "   Enter the mod: ";
   cin  >> mod;

   // Display input
   cout << "\n   " << base
        << " ^"    << exponent
        << " mod(" << mod << ")";

   // Solve
   answer = base;
   for(power = 1; power < exponent; power++)
   {
      cout << "\npower" << power;
      answer *= base;
      if(answer > mod)
         answer = answer %  mod;
      cout << "\n   Answer: " << answer;

   }

   
   cout << "\n   Answer: " << answer;
   // Exit
   cout << "\n\n   Finished";
   cout << "\n\n\n\n";
	return 0;
}