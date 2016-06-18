package leetcode;

public class CoinChange {
	int[] changes;// store the answer of the subproblem 
	int[] coins;
	
	public static void main(String[] args) {
		int[] coins = {1,2,5};
		int amount = 100;
		CoinChange cc = new CoinChange();
		System.out.println(cc.coinChange(coins, amount));
//		for(int i : cc.changes)
//			System.out.println(i);
	}
    public int coinChange(int[] coins, int amount) {
    	this.coins = coins;
    	this.changes = new int[amount + 1];
    	return getStatus(amount);
    }
    // the main function of this dynamic programming problem
    private int getStatus(int amount){
    	// if the subproblem has be solved, take the answer
    	if(amount == 0)
    		return 0;
    	else if(changes[amount] != 0)
    		return changes[amount];
    	
    	int[] comp = new int[coins.length];
    	for(int i = 0;i < coins.length;i++){
    		comp[i] = Integer.MAX_VALUE;
    	}
    	// else solve it and store it
    	for(int i = 0;i < coins.length;i++){
    		if(coins[i] == amount){
    			changes[amount] = 1;
    			return 1;
    		}
    		else if(coins[i] > amount)
    			continue;
    		else{
    			comp[i] = getStatus(amount - coins[i]) == -1?Integer.MAX_VALUE : getStatus(amount - coins[i]) + 1;
    		}
    	}
    	int min = Integer.MAX_VALUE;
    	for(int i = 0;i < coins.length;i++){
    		if(min > comp[i])
    			min = comp[i];
    	}
    	if(min == Integer.MAX_VALUE){
    		changes[amount] = -1;
    		return -1;
    	}
    	else{
    		changes[amount] = min;
    		return min;
    	}
    }
}
