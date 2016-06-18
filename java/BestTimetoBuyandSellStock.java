package leetcode;

public class BestTimetoBuyandSellStock {
	public static void main(String[] args) {
		int[] prices = {2,3,4,1,2,4,5,2};
		System.out.println(maxProfit(prices));
	}
	// this question is very like the question "IncreasingTripletSubsequence"
    public static int maxProfit(int[] prices) {
    	if(prices.length == 0)
    		return 0;
        int lower = prices[0];// lower record the potentially best price to buy in
        int difference = 0;// difference is the former best price difference
        for(int i = 1;i < prices.length;i++){
        	if(prices[i] < lower){
        		lower = prices[i];
        	}
        	else if(prices[i] - lower > difference){
        		difference = prices[i] - lower;
        	}
        }
        return difference;
    }
}
