// Time Complexity - O(m*n)
// Space Complexity - O(m+n)


class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<int> row(n,0);
        vector<int> col(m,0);

        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                if(matrix[i][j]==0){
                    row[i]=1;
                    col[j]=1;
                }
            }
        }

        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                if(col[j] || row[i])
                    matrix[i][j]=0;
            }
        }

        return;
    }
};





// Space Optimised Solution 
// Time Complexity - O(2N)
// Space Complexity - o(1)

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        // to get the optimal approach code here

        // we will use the first row of matrix ax coloumn flag - matrix[0][..]
        // similarly we will use the first coloumn as row flag - matrix[..][0]

        int m = matrix.size();
        int n = matrix[0].size();
        
        int col0 = matrix[0][0];

        for(int i=0;i<n;++i){
            if(matrix[0][i]==0)
                matrix[0][0]= 0;
        }
        for(int i=1;i<m;++i){
            if(matrix[i][0]==0)
                col0 = 0;
        }


        for(int i=1;i<m;++i){
            for(int j=1;j<n;++j){
                if(matrix[i][j]==0){
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }

        for(int i = m-1;i>0;--i){
            for(int j = n-1;j>0;--j){
                if(matrix[0][j]==0 || matrix[i][0]==0)
                    matrix[i][j]=0;
            }
        }


        for(int j=0;j<n;++j){
            if(matrix[0][0]==0){
                matrix[0][j]=0;
            }
        }

        for(int j=0;j<m;++j){
            if(col0==0){
                matrix[j][0]=0;
            }
        }

        

        // return matrix;
    }
};
