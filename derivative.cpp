//Сравниваем формулу для приближения производной по 3-м узлам для многочленов степени <=2 с точной производной
#include <iostream>
#include <math.h>

double derivative(double k2, double k1, double k0, double x);
double interp(double k2, double k1, double k0, double h, double x);

int main(int argc, char* argv[]){
	
	if (argc < 6)
{
   std::cout << "No arguments" << "\n";
   return 1;
}

double k2, k1, k0, h, x;

try
{
   k2 = std :: stod(argv[1]);
   k1 = std :: stod(argv[2]);
   k0 = std :: stod(argv[3]);
   h = std :: stod(argv[4]);
   x = std :: stod(argv[5]);
}
catch(...)
{
   std::cout << "Not able to parse arguments" << "\n";
   return 1;
}

std::cout << " Derivative is " << derivative(k2, k1, k0, x) << "\n";
std::cout << "Intep is " << interp(k2, k1, k0, h, x) << "\n";
std::cout << derivative(k2, k1, k0, x) - interp(k2, k1, k0, h, x) << "\n";
	
return 0;
}

double derivative(double k2, double k1, double k0, double x){
	return 2.0*k2*x + k1;
}

double interp(double k2, double k1, double k0, double h, double x){
	return 1.0/(2.0*h)*(-3.0*(k2*x*x + k1*x + k0) + 4.0*(k2*(x+h)*(x+h) + k1*(x+h) + k0) - (k2*(x+2*h)*(x+2*h) + k1*(x+2*h) + k0));
}
