bool AreSimilar ( int[] A, int[] B ) {
	var Difference = 0;//Số điểm khác biệt giữa A và B
	var First = 0;//2 biến này để lưu 2 vị trí mà A và B cần swap (nếu có)
	var Second = 0;
	for ( int i = 0; i < A.Length; i += 1 )
	if ( A[i] != B[i] ) {
		Difference += 1;
		if ( Difference == 1 ) First = i;
		else
			if ( Difference == 2 ) 
				Second = i;
	}
	if ( Difference == 0 ) return true;
	if ( Difference != 2 ) return false;
	if ( A[First] != B[Second] ) return false;
	if ( A[Second] != B[First] ) return false;
	return true;
}
