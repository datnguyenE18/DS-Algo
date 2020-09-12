// Không nộp trên SPOJ
#include<bits/stdc++.h>
using namespace std;

void init(string str, vector<int> &v) {
	for ( int i = str.size() - 1; i >= 0; i-- )
		v.push_back(str[i] - '0');
}

void print(vector<int> v) {
	for ( int i = v.size() - 1; i >= 0; i-- )
		cout << v[i];
	cout << endl;
}

bool nega(vector<int> v1, vector<int> v2) {
	int s1 = v1.size();
	int s2 = v2.size();

	if ( s1 > s2 ) return true;
	else if ( s1 < s2 ) return false;
	else {
		for ( int i = 0; i < s1; i++ ) {
			if ( v1[i] < v2[i] ) return false;
			else return true;
		}
	}
}

void sub(vector<int> v1, vector<int> v2) {
	vector<int> res;
	int l = v1.size();
	v2.resize(l);

	int extra = 0,
		temp;

	for ( int i = 0; i < l; i++ ) {
		if ( v1[i] < v2[i] + extra ) {
			res.push_back(v1[i] - v2[i] - extra + 10);
			extra = 1;
		} else {
			res.push_back(v1[i] - v2[i] - extra);
			extra = 0;
		}
	}

	while ( res[res.size() - 1] == 0 && res.size() > 1 )
		res.pop_back();
	print(res);
}

int main() {
	int t; cin >> t;
	string a, b;
	while ( t-- ) {
		cin >> a;
		cin >> b;

		vector<int> v1, v2;
		init(a, v1);
		init(b, v2);

		if ( nega(v1, v2) )
			sub(v1, v2);
		else
			sub(v2, v1);
	}

}