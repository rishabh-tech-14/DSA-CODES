#include <iostream>
using namespace std;

// COUNT THE DIGITS IN A NUMBER
//  int cntDig(int n ){
//      int cnt = 0 ;
//      while(n>0){
//          cnt++;
//          n=n/10;
//      }
//      return cnt;
//  }

// REVERSE THE GIVEN NUMBER
//  int revNum(int a){
//      int digit=0 , rev;
//      while(a>0){
//          rev = a%10;
//          digit=(digit*10) + rev;
//          a=a/10;
//      }
//      return digit;
//  }

// CHECKS IF THE GIVEN NUMBER IS PALINDROME OR NOT
//  int pal(int a){
//      int digit=0 , rev , num;
//      num= a;
//      while(a>0){
//          rev = a%10;
//          digit=(digit*10) + rev;
//          a=a/10;
//      }
//      if(num==digit) return true;
//      else return false;
//  }

// FIND THE GCD Method 2
//  int gcd1(int a, int b){
//      int gd=1;
//      for(int i =1; i<=min(a,b);i++){
//          if(a%i==0 && b%i==0){
//              gd=i;
//          }
//      }
//      return gd;
//  }

// FIND THE GCD Method 2
//  int gcd2(int a , int b){
//      while(a>0 && b>0){
//          if(a>b) a=a%b;
//          else b=b%a;
//      }

//     if(a==0) return b;
//     else return a;
// }

// CHECK WHETHER THE GIVEN NUMBER IS ARMSTRONG OR NOT
//  int chkarm(int a){
//      int digit = 0 , arm , num;
//      num=a;
//      while(a>0){
//          arm=a%10;
//          digit=digit+(arm*arm*arm);
//          a=a/10;
//      }

//     if(digit==num) return true;
//     else return false;
// }

// PRINT ALL THE DIVISORS OF THE GIVEN NUMBER
//  int div(int n){
//      for(int i = 1 ; i<=n ; i++){
//          if(n%i==0) cout<<i<<" ";
//          else continue;
//      }
//  }

// CHECK WHETHER THE GIVEN NUMBER IS PRIME OR NOT
int chkprime(int n)
{
    int factors = 0;
    for (int i = 1; i <= n; i++)
    {
        if (n % i == 0)
        {
            factors=factors+1;
        }
        else continue;
    }
    if (factors == 2)
    {
        cout << "The number is prime";
    }
    else
    {
        cout << "The number is not prime";
    }
}

int main()
{
    int a;
    cin >> a;
    chkprime(a);
}