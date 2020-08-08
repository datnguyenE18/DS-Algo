#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define faster() ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define mp make_pair
#define pb push_back

using namespace std;

// note: Write a module not program

vector<vector<int>> matrix_multi(vector<vector<int>> a ,int p, int n /*size*/){
	vector<vector<int>> tmp;
	vector<vector<int>> res;
	p--;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			res[i][j] = a[i][j];
		}
	}
	while(p--) {
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < n; j++) {
				tmp[i][j] = res[i][j];
			}
		}
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < n; j++) {
				res[i][j] = 0;
				for(int k = 0; k < n; k++) {
					res[i][j] += tmp[i][k]*a[k][j];
				}
			}
		}	
	}
	return res;
}

// Test succesfully