package leetcode;

public class RangeSumQuery2D {
	public static void main(String[] args) {
		int[][] matrix = {};
//		int[][] matrix = {{3, 0, 1, 4, 2},
//		                  {5, 6, 3, 2, 1},
//		                  {1, 2, 0, 1, 5},
//		                  {4, 1, 0, 1, 7},
//		                  {1, 0, 3, 0, 5}};
		NumMatrix nm = new NumMatrix(matrix);
		System.out.println(nm.sumRegion(2, 1, 4, 3));
	}
}

class NumMatrix {
	int[][] preSum;
	boolean emptyFlag = false;

    public NumMatrix(int[][] matrix) {
    	if(matrix.length == 0){
    		emptyFlag = true;
    		return;
    	}
    	emptyFlag = false;
        preSum = new int[matrix.length+1][matrix[0].length+1];
        for(int i = 0;i < matrix.length;i++){
        	for(int j = 0;j < matrix[0].length;j++){
        		preSum[i+1][j+1] = preSum[i+1][j] + preSum[i][j+1] - preSum[i][j] + matrix[i][j];
//        		System.out.print(preSum[i+1][j+1] + " ");
        	}
//        	System.out.println();
        }
    }

    public int sumRegion(int row1, int col1, int row2, int col2) {
    	if(emptyFlag)
    		return 0;
        return preSum[row2+1][col2+1] - preSum[row2+1][col1] - preSum[row1][col2+1] + preSum[row1][col1];
    }
}
