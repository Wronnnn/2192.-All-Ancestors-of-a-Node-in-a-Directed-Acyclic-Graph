#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> answer(n);
        for(int i=0;i<edges.size();i++){
            answer.at(edges.at(i).at(1)).push_back(edges.at(i).at(0));
        }
        for(int i=0;i<answer.size();i++){
           unsigned int temp = answer.at(i).size();
           for(int j=0;j<temp;j++){
               answer.at(i).insert(answer.at(i).end(), answer.at(answer.at(i).at(j)).begin(), answer.at(answer.at(i).at(j)).end());
           }
           sort(answer.at(i).begin(), answer.at(i).end());
           auto last = unique(answer.at(i).begin(), answer.at(i).end());
           answer.at(i).erase(last, answer.at(i).end());
        }
        return answer;
    }
};

int main() {
    int n = 8;
    vector<vector<int>> edgeList = {{0,7},{7,6},{0,3},{6,3},{5,4},{1,5},{2,7},{3,5},{3,1},{0,5},{7,5},{2,1},{1,4},{6,1}};
    vector<vector<int>> answer;
    Solution sol;
    answer = sol.getAncestors(n, edgeList);
    for(int i=0;i<answer.size();i++){
        for(int j=0;j<answer.at(i).size();j++){
            printf("%d, ", answer.at(i).at(j));
        }
        printf("\n");
    }
    return 0;
}
