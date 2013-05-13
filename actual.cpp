#include <iostream>
using namespace std;

int factorial(int i)  {
          int j;
          j = i;
          if (i <= 0)
          {
              j = 1;
          }
          else
          {
              i = factorial(i - 1);
              j = j * i;
          }
          return j;
}

int main() {
	  int a;
	  a = factorial(5);
          a = a / 2;
	  cout << "a final is " << a << endl;
		return a;
}


