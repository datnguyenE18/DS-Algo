function areSimilar ( a, b ) {
	if ( a.length !== b.length ) return false;
	var tempArr = [];
	
	for ( var i = 0; i < b.length; i++ ) {
		if ( a[i] !== b[i] ) {
			tempArr.push ( i );
		}
	}
	
	if ( tempArr.length === 0 ) return true;

	if ( tempArr.length === 1 || tempArr.length > 2 ) return false;
	else return a[tempArr[0]] === b[tempArr[1]] && a[tempArr[1]] === b[tempArr[0]]
}