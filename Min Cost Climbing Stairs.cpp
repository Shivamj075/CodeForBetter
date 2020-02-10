//LeetCode
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
         cost.push_back(0);
        for (int i  = 2; i <= cost.size(); ++i){
            if (i == cost.size()){cost[i] = min(cost[i-1], cost[i-2]);}
            else{cost[i] += min(cost[i-1], cost[i-2]);}
        }
       return cost[cost.size()-1];
    }
};
