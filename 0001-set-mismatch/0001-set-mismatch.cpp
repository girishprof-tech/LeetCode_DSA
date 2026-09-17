class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int miss=-1,dup=-1;
        int i=1;
        while(i<=nums.size()){
            if(count(nums.begin(), nums.end(), i)>1)    dup=i;
            if(count(nums.begin(),nums.end(),i)==0) miss=i;
            if(dup!=-1 && miss!=-1) return {dup,miss};
            i++;
        }
        return {dup,miss};
    }
};