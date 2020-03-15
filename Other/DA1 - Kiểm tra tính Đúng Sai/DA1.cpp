#include<iostream>
using namespace std;

int main(){
	char s[8];
	gets_s(s);
	int a = s[0] - '0', b = s[4] - '0', c = s[8] - '0';
	if( a + b == c) cout << "YES";
	else cout << "NO";
	
	system("pause");
	return 0;
}
