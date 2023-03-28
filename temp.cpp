#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

bool isPrime(int number)
{
    if (number < 2)
        return false;
    if (number == 2)
        return true;
    if (number % 2 == 0)
        return false;
    for (int i = 3; (i * i) <= number; i += 2)
    {
        if (number % i == 0)
            return false;
    }
    return true;
}

    int countSquares(vector<vector<int>>& A) {
        int res = 0;
        for (int i = 0; i < A.size(); ++i)
            for (int j = 0; j < A[0].size(); res += A[i][j++])
                if (A[i][j] && i && j)
                    A[i][j] += min({A[i - 1][j - 1], A[i - 1][j], A[i][j - 1]});
        return res;
    }
int main() {
  // Declare the variable
int n;
cin>>n;
//vector<bool>v(n,0);
 vector<vector<int>> v( n , vector<int> (n, 0));
int cnt=0;
for(int i=0;i<n;i++){
  for(int j=0;j<n;j++){
    int a;
    cin>>a;
    v[i][j]=isPrime(a);
    // if(v[i][j]){
    //   cnt++;
    // }
  }
}

cnt+=countSquares(v);

cout<<cnt<<endl;
  
  return 0;
}