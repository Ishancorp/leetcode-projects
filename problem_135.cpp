// Problem 135
// Return minimum number of candies to be distributed such that each child has at least 1 
// candy, and children with higher ratings have more than neighbours

class Solution {
public:
    int candy(vector<int>& ratings) {
        vector<int> arr(ratings.size());
        arr[0] = 1;
        if(ratings.size()==1)
            return 1;
        for(int i = 1; i < ratings.size(); i++) {
            if(ratings[i] > ratings[i-1])
                arr[i] = 1 + arr[i-1];
            else
                arr[i] = 1;
        }
        for(int i = ratings.size()-2; i >= 0; i--) {
            if(ratings[i] > ratings[i+1] && arr[i] < 1 + arr[i+1])
                arr[i] = 1 + arr[i+1];
        }
        int count = 0;
        for(int i = 0; i < ratings.size(); i++)
            count = count + arr[i];
        
        return count;
    }
};
