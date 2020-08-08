boolean isRectangle(int[][] points){
    if( dist(points, 0, 1) == dist(points, 2, 3) &&
                dist(points, 1, 2) == dist(points, 0, 3) &&
                dist(points, 0, 2) == dist(points, 1, 3) &&
                dist(points, 1, 2) + dist(points, 2, 3) == dist(points, 1,3)
                ) return true;
        return false;
}

int dist( int[][] a, int p1, int p2) {
        return ( a[p1][0] - a[p2][0] ) * ( a[p1][0] - a[p2][0] ) +
                ( a[p1][1] - a[p2][1] ) * ( a[p1][1] - a[p2][1] ) ;
    }
