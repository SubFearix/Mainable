#include <iostream>
#include <math.h>
using namespace std;

int main(){
int a = 8;
int b = 13;
int c = 8;
int perimeter = a+b+c;
float halfper = perimeter / 2.0;
float spaceGer = sqrt(halfper * (halfper - a) * (halfper - b) * (halfper - c));
bool isIsosceles = ((a == b || a == c || b == c)?true:false);
if (isIsosceles) {
cout << "Равнобедренный"<<endl;
} else {cout <<"Не равнобедренный"<<endl;}
cout << "Площадь по формуле Герона равна: "<<  spaceGer<<endl;
cout <<"Периметр равен: "<<perimeter <<endl;
return 0;
}
