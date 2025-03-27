int minCostClimbingStairs(int* cost, int costSize) {
    int a = cost[0];
    int b = cost[1];
    int ans = cost[1];

    for(int i = 2; i <= costSize; i++){
        if(i == costSize)
            return a<b ? a :  b;
        ans = a<b ? a+cost[i] : b+cost[i];
        a = b;
        b = ans;
    }
    return a<b;
}