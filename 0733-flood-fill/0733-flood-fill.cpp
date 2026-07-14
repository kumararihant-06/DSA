class Solution {
public:
    void fillFlood(vector<vector<int>>& image, int sr, int sc, int color, int startingColor){
        int n = image.size();
        int m = image[0].size();
        int drow[] = {-1,0,1,0};
        int dcol[] = {0,-1,0,1};
        if(sr>=0 && sr<n && sc>=0 &&sc<m){
            if(image[sr][sc] == color) return;
            if( image[sr][sc] == startingColor){
                image[sr][sc] = color;
                for(int j =0; j<4;j++){
                    int newSr = sr+drow[j];
                    int newSc = sc+dcol[j];
                    fillFlood(image, newSr, newSc, color, startingColor);
                }
            }
        }else{
            return;
        }  
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int startingColor = image[sr][sc];
        fillFlood(image, sr, sc, color, startingColor);
        return image;
    }
};