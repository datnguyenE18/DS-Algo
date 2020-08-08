boolean chessBoardCellColor(String cell1, String cell2) {    
        return isWhite(cell1)==isWhite(cell2);
    }

boolean isWhite ( String digits ) {
	boolean state1 = false;
	boolean state2 = false;
	boolean white = false;
	char[] digs = digits.toCharArray ();
	switch ( digs[0] ) {
		case 'A': state1 = true;
			break;
		case 'C': state1 = true;
			break;
		case 'E': state1 = true;
			break;
		case 'G': state1 = true;
			break;
		default: state1 = false;
	}
	switch ( digs[1] ) {
		case '1': state2 = true;
			break;
		case '3': state2 = true;
			break;
		case '5': state2 = true;
			break;
		case '7': state2 = true;
			break;
		default: state2 = false;
	}
	if ( state1 == state2 ) { white = false; } else { white = true; }
	return white;
}