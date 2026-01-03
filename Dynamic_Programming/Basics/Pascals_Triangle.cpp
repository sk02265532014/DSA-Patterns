// Problem: Pascal's Triangle
// Pattern: Dynamic Programming (Row Construction)
// Key idea: Each element is sum of two elements from previous row
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        vector<int> prev={1};
        ans.push_back(prev);
        for(int i=1;i<numRows;i++){
            vector<int> temp(i+1);
            for(int j=1;j<i;j++){
                temp[j]=prev[j-1]+prev[j];
            }
            temp[0]=temp[i]=1;
            prev=temp;
            ans.push_back(temp);
        }
        return ans;
    }
};
