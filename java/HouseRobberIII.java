package leetcode;

public class HouseRobberIII {
	public static void main(String[] args) {
		TreeNode n31 = new TreeNode(3);
		TreeNode n32 = new TreeNode(1);
//		TreeNode n33 = new TreeNode(1);
		TreeNode n21 = new TreeNode(2,null,n31);
		TreeNode n22 = new TreeNode(3,null,n32);
		TreeNode n11 = new TreeNode(3,n21,n22);
		
		System.out.println(rob(n11));
	}
	public static int rob(TreeNode root){
		int[] res = new int[2];
		res = dfs(root);
		return Math.max(res[0], res[1]);
	}
    private static int[] dfs(TreeNode x) {
        if (x == null) return new int[2];
        int[] left = dfs(x.left);
        int[] right = dfs(x.right);
        int[] res = new int[2];
        res[0] = left[1] + right[1] + x.val;
        res[1] = Math.max(left[0], left[1]) + Math.max(right[0], right[1]);
        return res;
    }
}

class TreeNode {
    int val = 0;
    TreeNode left = null;
    TreeNode right = null;
    
    TreeNode(int x) { 
    	val = x; 
    }
    TreeNode(int x,TreeNode left,TreeNode right){
    	val = x;
    	this.left = left;
    	this.right = right;
    }
}
