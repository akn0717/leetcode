class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int count = 0;
        int max_idx = 0;
        for(int i=0; i<arr.size(); ++i){
            if(arr[i]==max_idx || (arr[i]<max_idx&&i==max_idx)){
                ++count;
                max_idx = i+1;
            }else{
                max_idx = max(max_idx, arr[i]);
            }
        }
        return count;
    }
};
