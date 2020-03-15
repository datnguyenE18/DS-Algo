bool insideCircle(std::vector<int> point, std::vector<int> center, int radius){
    double temp = sqrt(pow((point[0] - center[0]), 2)+pow((point[1] - center[1]), 2) );
    if(temp <= radius) return true;
    else return false;
}
