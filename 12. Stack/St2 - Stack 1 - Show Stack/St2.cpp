#include <bits/stdc++.h>
using namespace std;

void show(stack < int> s) {
	vector<int> tmp;
	while ( !s.empty() ) {
		tmp.push_back(s.top());
		s.pop();
	}
	if ( tmp.size() == 0 ) {
		cout << "empty" << '\n';
		return;
	}
	reverse(tmp.begin(), tmp.end());
	for ( int i = 0; i < tmp.size(); i++ )
		cout << tmp[i] << ' ';
	cout << '\n';
}

void Solve() {
	string s;
	int x;
	stack < int > st;
	while ( cin >> s ) {
		if ( s == "push" ) {
			int x; cin >> x;
			st.push(x);
		} else if ( s == "pop" ) {
			if ( !st.empty() ) st.pop();
		} else show(st);
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	Solve();
}

/*
push 3
push 5
show
3 5

push 7
show
3 5 7

pop
pop
show
3

pop
show
empty
*/