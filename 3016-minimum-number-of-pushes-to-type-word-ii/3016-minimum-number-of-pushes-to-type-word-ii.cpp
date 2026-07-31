class Solution {
public:
    int minimumPushes(string word) {
        // Due to duplicate characters we should find the freq of characters first 
        // and then assign them costs.
        vector<int> freq(26,0);
        for(char ch: word){
            freq[ch-'a']++;
        }
        
        //Highest freq should get lowest cost;
        sort(freq.rbegin(),freq.rend());

        int answer = 0;
        for(int i = 0; i<26; i++){
            //Character not present no need to assign any cost now
            if(freq[i]==0)break;
            
            //Assign highly frequent keys to lowest cost i.e 1 first (0-7), then 2(8-15).....
            int pushes = (i/8)+1;

            //how many times we actually need to push the key.
            answer+=freq[i]*pushes;
        }
        return answer;
    }
};