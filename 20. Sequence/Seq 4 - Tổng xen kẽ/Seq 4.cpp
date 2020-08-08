vector<int> alternatingSums(vector<int> a){
    vector <int> result;
    int team1 = 0, team2 = 0;
    for (int i = 0; i < a.size(); i+=2){
        team1 += a[i];
        int j = i + 1;
        if(j < a.size()) team2 += a[j];
    }
    result.push_back(team1); result.push_back(team2);
    return result;
}
