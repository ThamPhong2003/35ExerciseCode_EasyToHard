//C/C++ 
#include <bits/stdc++.h>
using namespace std;
int main() 
{ 
    int n;
    cin >>n;
    int a[1000000];
    for (int i =1; i<=n;i++){
        cin >> a[i];
    }
    int sum =0;
    for (int i = 1; i<=n;i++){
        sum += a[i];
    }
    cout << sum <<endl;
    return 0;
}

