vector<int> makeArrayConsecutive(vector<int> sequence){
    vector <int> result;
	sort ( sequence.begin ( ), sequence.end ( ));
    for (int i = 0; i < sequence.size() - 1; i++){
        int j = 1;
        while(sequence[i] + j != sequence[i + 1]){
            result.push_back(sequence[i] + j);
            j++;
        }
    } return result;
}
