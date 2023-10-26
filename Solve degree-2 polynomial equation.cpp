#include <iostream>
#include <string>
#include <math.h>
#include <iomanip> 
using namespace std;

int main() {
   int a, b, c;
   cin >> a >> b >> c;
   float x0, x1, x2;
   if (a == 0) {
       x0 = -b / static_cast<float>(c); 
       cout << fixed << setprecision(2) << x0 << endl;
   } else {
       float delta;
       delta = b * b - 4 * a * c;
       if (delta > 0) {
           x1 = (-b - sqrt(delta)) / (2 * a);
           x2 = (-b + sqrt(delta)) / (2 * a);

           cout << fixed << setprecision(2) << x1 << " " << fixed << setprecision(2) << x2;
       } else if (delta < 0) {
           cout << "NO SOLUTION" << endl;
       } else if (delta == 0) {
           x0 = -b / (2 * a);
           cout << fixed << setprecision(2) << x0 << endl;
       }
   }
   return 0;
}

