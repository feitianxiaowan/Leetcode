package leetcode;

public class BestTimetoBuyandSellStockIII {	
	public static void main(String[] args) {
		int[] prices = {2,1,2,0,1};
		System.out.println(new BestTimetoBuyandSellStockIII().maxProfit(prices));
	}
    public int maxProfit(int[] prices) {
    	if(prices.length <= 1)
    		return 0;
    	
    	int[] subMaxProfit = new int[prices.length];
        int[] reserveSubMaxProfit = new int[prices.length];// use space change for time
        
    	// almost the same as "BestTimetoBuyandSellStock"
    	subMaxProfit[0] = 0;// difference is the former best price difference
        int lower = prices[0];// lower record the potentially best price to buy in
        for(int i = 1;i < prices.length;i++){
        	if(prices[i] < lower){
        		lower = prices[i];
        		subMaxProfit[i] = subMaxProfit[i-1];
        	}
        	else if(prices[i] - lower > subMaxProfit[i-1])
        		subMaxProfit[i] = prices[i] - lower;
        	else 
				subMaxProfit[i] = subMaxProfit[i-1];
        }
        
        reserveSubMaxProfit[prices.length-1] = 0;
        int higher = prices[prices.length-1];
        for(int i = prices.length - 2;i >= 0;i--){
        	if(prices[i] > higher){
        		higher = prices[i];
        		reserveSubMaxProfit[i] = reserveSubMaxProfit[i+1];
        	}
        	else if(higher - prices[i] > reserveSubMaxProfit[i+1])
        		reserveSubMaxProfit[i] = higher - prices[i];
        	else 
        		reserveSubMaxProfit[i] = reserveSubMaxProfit[i+1];
        }
        
        int max = 0;
        for(int i = 0;i < prices.length;i++){
        	if(max < subMaxProfit[i] + reserveSubMaxProfit[i])
        		max = subMaxProfit[i] + reserveSubMaxProfit[i];
        }   
        
        return max;
    }
}
