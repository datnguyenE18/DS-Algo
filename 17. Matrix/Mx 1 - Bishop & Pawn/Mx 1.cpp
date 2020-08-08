#include<bits/stdc++.h>
using namespace std;

bool bishopAndPawn ( std::string bishop, std::string pawn ) {
	int dist1, dist2; //distance
	dist1 = abs ( bishop[0] - pawn[0] );
	dist2 = abs ( bishop[1] - pawn[1] );
	if ( bishop == pawn ) return false;
	if ( dist1 == dist2 ) return true;
	return false;
}



int main () {
	string bishop = "a1";
	string pawn = "c3";
	if ( bishopAndPawn ( bishop, pawn ) ) {
		cout << "true";
		system ( "pause" );
		return 0;
	}
	cout << "false";
	system ( "pause" );
}