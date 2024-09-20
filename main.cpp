#include <iostream>
#include <numeric>
#include <ratio>

using namespace std;
typedef struct{
  int numerator;
  int denominator;
}rational;
int k = 0;
rational result2;
void printout(rational f){
  cout<<f.numerator;
  cout<<"/";
  cout<<f.denominator;
}


rational fadd(rational num1, rational num2){//Fraction Addition
  rational result;
  result.numerator = num1.numerator * num2.denominator + num2.numerator * num1.denominator;
  result.denominator = num1.denominator * num2.denominator;
  int g = __gcd((unsigned int)result.numerator, (unsigned int)result.denominator);
  result.numerator /= g;
  result.denominator /= g;
  return result;
}


rational fsub(rational num1, rational num2){//Fraction Subtraction
  rational result;
  result.numerator = num1.numerator * num2.denominator - num2.numerator * num1.denominator;
  result.denominator = num1.denominator * num2.denominator;
  int g = __gcd((unsigned int)result.numerator, (unsigned int)result.denominator);
  result.numerator /= g;
  result.denominator /= g;
  return result;
}


rational fmul(rational num1, rational num2){//Fraction Multiplication
  rational result;
  result.numerator = num1.numerator * num2.numerator;
  result.denominator = num1.denominator * num2.denominator;
  int g = __gcd((unsigned int)result.numerator, (unsigned int)result.denominator);
  result.numerator /= g;
  result.denominator /= g;
  return result;
}


rational fdiv(rational num1, rational num2){//Fraction Divide
  rational result;
  result.numerator = num1.numerator * num2.denominator;
  result.denominator = num1.denominator * num2.numerator;
  int g = __gcd((unsigned int)result.numerator, (unsigned int)result.denominator);
  result.numerator /= g;
  result.denominator /= g;
  return result;
}


bool fcmp(rational num1, rational num2){//Fraction Comparing
  return num1.numerator * num2.denominator - num2.numerator * num1.denominator > 0;
}


int main(){
  rational a, b;
  cin>>a.numerator;
  cin>>a.denominator;
  cin>>b.numerator;
  cin>>b.denominator;
  char oper;
  cin>>oper;
  if(oper == '+'){
    rational d = fadd(a, b);
    printout(d); 
  }
  if(oper == '-'){
    rational d = fsub(a, b);
     printout(d);
  }
  if(oper == '*'){
    rational d = fmul(a, b);
     printout(d);
  }
  if(oper == '/'){
    rational d = fdiv(a, b);
     printout(d);
  }
  if(oper == '>' || oper == '<' || oper == '='){
    if(fcmp(a, b)){
      cout<<a.numerator<<"/"<<a.denominator<<" is larger than "<<b.numerator<<"/"<<b.denominator<<endl;
    }
    else{
      cout<<a.numerator<<"/"<<a.denominator<<" is smaller than or equal to "<<b.numerator<<"/"<<b.denominator<<endl;
    }
  }


}
