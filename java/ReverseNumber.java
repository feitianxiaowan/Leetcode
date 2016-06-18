package leetcode;

public class ReverseNumber {
	public static void main(String[] args){
		int input = 134236469;
		System.out.println(new ReverseNumber().reverse(input));
	}
	public int reverse(int x) {
		int max = 0x7fffffff;  //min value of int
        int min = 0x80000000;  //max value of int
        long sum = 0;   
          
        while(x != 0)  
        {  
            int temp = x % 10;  
            sum = sum * 10 + temp;  
            if (sum > max || sum < min)   //Òç³ö´¦Àí  
            {  
                sum = sum > 0 ? max : min;    
                return 0;
            }  
            x = x / 10;  
        }  
        return new Long(sum).intValue();  
    }
}
