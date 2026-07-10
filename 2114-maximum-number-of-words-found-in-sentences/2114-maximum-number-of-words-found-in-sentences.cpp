class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        int maxWc = 0;
        for(int i = 0;i<sentences.size();i++){
            int wc = 0;
            for(int j =0; j<sentences[i].size(); j++){
                if(sentences[i][j]==' ') wc++;
            }
            wc++;
            maxWc = max(maxWc,wc);
        }
        return maxWc;
    }
};