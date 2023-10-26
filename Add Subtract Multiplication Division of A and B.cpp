//C/C++ 
#include <bits/stdc++.h> 

#include <iostream>
using namespace std;

int main() {
    int a,b;
    cin >>a>>b;
    int tong = 0;
    int tich = 0;
    int hieu =0;
    int chia = 0;
    tong = a+b;
    tich = a*b;
    hieu = a-b;
    chia = a/b;
    cout<<tong<<" "<<hieu<<" "<<tich<<" "<<chia<<endl;
    return 0;
}

