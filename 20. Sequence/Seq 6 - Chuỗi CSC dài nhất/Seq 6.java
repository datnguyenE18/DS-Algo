int longestSequence(int[] A){
    int len = A.length;
        int max = 1;
        int[][] dp = new int[len][len];
        for (int i = 0; i < len; i++) {
            dp[i][i] = 1;
            for (int j = i + 1; j < len; j++) {
                dp[i][j] = 2;
                int diff = A[j] - A[i];
// this loop is checking is there any element with the same distance
                for (int k = i - 1; k >= 0; k--) {
                    if (A[i] - A[k] == diff) {
                        dp[i][j] = Math.max(dp[i][j], dp[k][i] + 1);
                        break;
                    }
                } max = Math.max(max, dp[i][j]);
            }
        } return max;
}
