int findSquareSide ( vector<int> x, vector<int> y ) {
	double temp1 = sqrt ( pow ( ( x[2] - x[1] ), 2 ) + pow ( ( y[2] - y[1] ), 2 ) );
	double temp2 = sqrt ( pow ( ( x[2] - x[3] ), 2 ) + pow ( ( y[2] - y[3] ), 2 ) );
	double temp3 = sqrt ( pow ( ( x[1] - x[3] ), 2 ) + pow ( ( y[1] - y[3] ), 2 ) );
	if ( temp1 < temp2 ) return pow ( temp1, 2 );
	else if ( temp1 = temp2 ) {
		if ( temp1 < temp3 ) return pow ( temp1, 2 );
		else return pow ( temp1, 2 );
	} else return pow ( temp2, 2 );
}
