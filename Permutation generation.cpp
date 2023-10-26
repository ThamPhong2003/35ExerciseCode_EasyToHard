#include <bits/stdc++.h>
using namespace std;
int main (){
	int n;
	cin>>n;
	vector<int> per;
	for (int i = 1; i<=n; i++){
		per.push_back(i);
	}
	do {
		for(int i = 0; i< n ; i++){
			cout << per[i];
			cout << " ";			
			
		}
		cout <<endl;
	}
	while (next_permutation(per.begin(),per.end()));
	return 0;
}

