bool isArithmeticProgression(vector<int> sequence){
    double temp = sequence[1] - sequence[0];
    for(int i = 1; i < sequence.size(); i++){
        if((sequence[i] - sequence[i - 1]) == temp) continue;
        else return false;
    }  return true;
}
