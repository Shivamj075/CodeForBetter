class Solution {
public:
    int orderOfLargestPlusSign(int N, vector<vector<int>>& mines) {
        int maxi=0;
        vector<vector<int>> m(N,vector<int>(N,1));
        for (auto &v: mines) m[v[0]][v[1]]=0;
        for (int i=0; i<N; ++i){
            for (int j=0,k=0; j<N; ++j,k=0){
                while (canExpand(N,i,j,k,m)) ++k;
                maxi=max(maxi,k);
            }
        }
        return maxi;
    }
private:
    bool canExpand(int N, int x, int y, int k, vector<vector<int>>& m){
        if (x-k<0 || y-k<0 || x+k>=N || y+k>=N) return false;
        return m[x-k][y] && m[x][y+k] && m[x+k][y] && m[x][y-k];
    }
};
