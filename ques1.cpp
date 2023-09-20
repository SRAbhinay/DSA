#include <iostream>
using namespace std;

struct Complex {
  double real;
  double imag;
};

Complex add(Complex a, Complex b) {
  Complex result;
  result.real = a.real + b.real;
  result.imag = a.imag + b.imag;
  return result;
}

Complex subtract(Complex a, Complex b) {
  Complex result;
  result.real = a.real - b.real;
  result.imag = a.imag - b.imag;
  return result;
}

Complex multiply(Complex a, Complex b) {
  Complex result;
  result.real = a.real * b.real - a.imag * b.imag;
  result.imag = a.real * b.imag + a.imag * b.real;
  return result;
}

Complex divideByTwo(Complex a) {
  Complex result;
  result.real = a.real / 2;
  result.imag = a.imag / 2;
  return result;
}

Complex dccMultiply(Complex a, Complex b) {
  Complex a_plus_b = add(a, b);
  Complex a_minus_b = subtract(a, b);
  
  Complex a_plus_b_half = divideByTwo(a_plus_b);
  Complex a_minus_b_half = divideByTwo(a_minus_b);
  a_minus_b_half.imag = -a_minus_b_half.imag;
  
  Complex result1 = multiply(a_plus_b_half, b);
  Complex result2 = multiply(a_minus_b_half, b);
  
  return add(result1, result2);
}

int main() {
  Complex a, b;
  cout << "Enter real part of first complex number: ";
  cin >> a.real;
  cout << "Enter imaginary part of first complex number: ";
  cin >> a.imag;
  cout << "Enter real part of second complex number: ";
  cin >> b.real;
  cout << "Enter imaginary part of second complex number: ";
  cin >> b.imag;
  
  Complex result = dccMultiply(a, b);
  cout << "Result: " << result.real << " + " << result.imag << "i" << endl;
  
  return 0;
}
