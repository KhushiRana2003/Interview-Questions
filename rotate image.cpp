class Solution {
public:
    void transpose(vector<vector<int>> &arr){
        for(int i = 0; i < arr.size(); i++){
            for(int j = 0; j < i; j++){
                int temp = arr[i][j];
                arr[i][j] = arr[j][i];
                arr[j][i] = temp;
            }
        }
    }
    void reverseRow(vector<vector<int>> &arr){
        for(int r =0 ; r < arr.size(); r++){

            int left = 0;
            int right = arr.size()-1;
            while(left < right){
                int temp = arr[r][left];
                arr[r][left] = arr[r][right];
                arr[r][right] = temp;

                left++;
                right--;
            }
        }
    }
    void rotate(vector<vector<int>>& matrix) {
        // 1. transpose
        // 2. reverse every row

        transpose(matrix);
        reverseRow(matrix);
    }
};
