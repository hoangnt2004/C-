#include <bits/stdc++.h>

using namespace std;
int k, n , a[100], ok ;
void ktao(){
	for(int i = 1; i <= k; i++){
		a[i] = i;
	}
}
void sinh(){
	int i = k;
	while( i >= 1 && a[i] == n - k + i){
		--i;
	}
	if(i == 0){
		ok = 0;
	}else{
		a[i]++;
		for(int j = i + 1; j <= k; j++){
			a[j] = a[j - 1] + 1;
		}
	}
}
int main(){
	int t;
	cin >> t;
	while(t--){
		cin >> n >> k;
		ktao();
		ok = 1;
		vector<vector<int>> result ;
		while(ok){
			vector<int> comb;
			for(int i = 1; i <=k; i++){
				comb.push_back(a[i]);
			}
			result.push_back(comb);
			sinh();
		}
		cout << result.size() <<endl;
		
		for(auto comb:result){
			cout<<"[";
			for(int i = 0; i < comb.size(); i++){
				if(i != 0 ) cout <<" ";
				cout << comb[i];
			}
			cout <<"]" <<endl;
		}
	}
	return 0;
}