bool areSimilar ( vector<int> a, vector<int> b ) {
	int mark[2], j = 1, count = 0;
	for ( int i = 0; i < a.size (); i++ ) {
		if ( a[i] != b[i] ) {
			count++;
			if ( count > 2 ) return false;
			mark[j] = i;
			j++;
		}
	}
	if ( count == 0 ) return true;
	if ( count == 1 ) return false;
	std::swap ( a[mark[1]], a[mark[2]] );
	for ( int i = 0; i < a.size (); i++ )
	if ( a[i] != b[i] )
		return false;
	return true;
}