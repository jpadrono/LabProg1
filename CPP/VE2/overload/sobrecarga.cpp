#include <iostream>
#include <cmath>
using namespace std;

class Complex{
private:
 float a, b;
public:
 Complex(float a, float b):a(a), b(b){
 }

 Complex(Complex& c){
  a = c.a;
  b = c.b;
 }
 
 ~Complex(){
    //nada a fazer
  }

  void imprimir(){
    cout << a << " + " << b << "i" << endl;
  }

  float modulo(){
    return sqrt(a*a+b*b);
  }

  Complex operator++(){
    ++a;
    return *this;//ou Complex(a, b)
  }

  Complex operator--(){
    a--;
    return *this;
  }

  Complex operator++(int){
    Complex temp(*this);
    a++;
    return temp;//ou Complex(a-1,b);
  }

  Complex operator--(int){
    Complex temp(*this);
    --a;
    return temp;
  }

  Complex operator+(Complex ldo){
    return Complex(a+ldo.a, b+ldo.b);
  }

  Complex operator+(int ldo){
    return Complex(a+ldo, b);
  }

  Complex operator-(Complex ldo){
    return Complex(a-ldo.a, b-ldo.b);
  }

  Complex operator*(Complex ldo){
    return Complex(a*ldo.a - b*ldo.b, a*ldo.b + b*ldo.a);
  }

  bool operator==(Complex ldo){
    return a==ldo.a && b==ldo.b;
  }

  bool operator<(Complex ldo){
    return modulo() < ldo.modulo();
  }

  bool operator<=(Complex ldo){
    return modulo() <= ldo.modulo();
  }

  bool operator>(Complex ldo){
    return modulo() > ldo.modulo();
  }

  bool operator>=(Complex ldo){
    return modulo() >= ldo.modulo();
  }

  Complex operator=(Complex ldo){
    a = ldo.a;
    b = ldo.b;
    return *this;
  }

  Complex operator=(int ldo){
    a = ldo;
    b = 0;
    return *this;
  }

  Complex operator+=(Complex ldo){
    a += ldo.a;
    b += ldo.b;
    return *this;
  }
  
  Complex operator+=(int ldo){
    a += ldo;
    return *this;
  }

  float& operator[](int indice){
    if (indice==1)
      return b;
    else if (indice==0)
      return a;
    else
      throw "Inválido";
  }

  float operator()(){
    return modulo();  
  }

  bool operator&&(Complex ldo){
    return (a || b) && (ldo.a || ldo.b);
  }

  bool operator!(){
    return !(a || b);
  }

  operator float(){
    return a;
  }

  operator int(){
    return a;
  }
/*
operator Quaternio(){
return Quaternio(a,b,0,0);
}
Complex(Quaternio q){
a = q.a;
b = q.b;
}
*/
  friend Complex operator +(int leo, Complex ldo);
  friend istream& operator >> (istream &is, Complex &obj);
  friend ostream& operator << (ostream &os, const Complex &obj);

};

Complex operator +(int leo, Complex ldo){
  return Complex(leo + ldo.a, ldo.b);
}

istream& operator >> (istream &is, Complex &obj){
  is >> obj.a >> obj.b;
  return is;
}

ostream& operator << (ostream &os, const Complex &obj){
  os << obj.a << " + " << obj.b << "i" << endl;
  return os;
}

int main(){
  Complex a(1,1), b(2,2), c(0,0);
  cin >> a;
  c = a + b;cout << c;
  c = a - b;c.imprimir();
  c = a * b;c.imprimir();
  c = a + 2;c.imprimir();
  c = ++a;c.imprimir();
  c = --a;c.imprimir();
  c = a++;c.imprimir();
  c = a--;c.imprimir();
  cout << (a==b) << endl;
  cout << (a<b) << endl;
  cout << (a>b) << endl;
  cout << (a<=b) << endl;
  cout << (a>=b) << endl;
  c = a;c.imprimir();
  c = 3;c.imprimir();
  c += b;c.imprimir();
  c += 5;c.imprimir();
  cout << c[0] << "," << c[1] << endl;
  try{
    cout << c[2];
  }catch(const char *str){
    cout << str << endl;
  }
  cout << a() << endl;
  cout << (a && b) << endl;
  cout << (!a) << endl;
  Complex d(2.5, 3.2);
  cout << (int)d << endl;
  cout << (float)d << endl;
  Complex e = 5 + d;e.imprimir();

  return 0;
}