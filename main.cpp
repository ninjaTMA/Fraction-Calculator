#include <bits/stdc++.h>
using namespace std;
typedef struct{
  int numerator;
  int denominator;
}rational;
int k = 0;
struct result;
void simplify(rational frac){
  if(frac.numerator < frac.denominator){
    result.numerator = frac.numerator;
  result.denominator = result.denominator;
  }
  else{
  int k = frac.numerator / frac.denominator;
  frac.numerator -= k * frac.denominator;
  result.numerator = frac.numerator;
  result.denominator = result.denominator;
    return;
}
rational fadd(rational num1, rational num2){
  rational result;
  result.numerator = num1.numerator * num2.denominator + num2.numerator * num1.denominator;
  result.denominator = num1.denominator * num2.denominator;
  int g = __gcd(result.numerator, result.denominator);
  result.numerator /= g;
  result.denominator /= g;
  simplify(result);
}
rational fsub(rational num1, rational num2){
  rational result;
  result.numerator = num1.numerator * num2.denominator - num2.numerator * num1.denominator;
  result.denominator = num1.denominator * num2.denominator;
  int g = __gcd(result.numerator, result.denominator);
  result.numerator /= g;
  result.denominator /= g;
  return result;
}
rational fmul(rational num1, rational num2){
  rational result;
  result.numerator = num1.numerator * num2.numerator;
  result.denominator = num1.denominator * num2.denominator;
  int g = __gcd(result.numerator, result.denominator);
  result.numerator /= g;
  result.denominator /= g;
  return result;
}
rational fdiv(rational num1, rational num2){
  rational result;
  result.numerator = num1.numerator * num2.denominator;
  result.denominator = num1.denominator * num2.numerator;
  int g = __gcd(result.numerator, result.denominator);
  result.numerator /= g;
  result.denominator /= g;
  return result;
}
bool fcmp(rational num1, rational num2){
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
    fadd(a, b);
    if(k == 0){
      cout<<result.numerator<<"/"<<result.denominator<<endl;
  }
  if(oper == '-'){
    rational d = fsub(a, b);
     cout<<d.numerator<<"/"<<d.denominator<<endl;
  }
  if(oper == '*'){
    rational d = fmul(a, b);
     cout<<d.numerator<<"/"<<d.denominator<<endl;
  }
  if(oper == '/'){
    rational d = fdiv(a, b);
     cout<<d.numerator<<"/"<<d.denominator<<endl;
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
