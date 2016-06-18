package leetcode;

public class BestTimetoBuyandSellStockII {
	public static void main(String[] args) {
		int[] prices = {1,2};
		System.out.println(maxProfit(prices));
	}
    public static int maxProfit(int[] prices) {
        if(prices.length <= 1)
        	return 0;
        int buyinPrice = prices[0];
        int currentPrice = prices[0];
        int maxProfit = 0;
        for(int i = 1;i < prices.length;i++){
        	if(prices[i] >= currentPrice){
        		currentPrice = prices[i];
        	}
        	else{
        		maxProfit += currentPrice - buyinPrice;
        		buyinPrice = currentPrice = prices[i];
        	}
        }
        if(currentPrice > buyinPrice)
        	maxProfit += currentPrice - buyinPrice;
        return maxProfit;
    }
}
