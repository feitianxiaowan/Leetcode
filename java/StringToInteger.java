package leetcode;

public class StringToInteger {
	public static void main(String[] args){
		String input = "-1";
		System.out.println(new StringToInteger().myAtoi(input));
	}
    public int myAtoi(String str) {
		int max = 0x7fffffff;  //min value of int
        int min = 0x80000000;  //max value of int
    	long output = 0;
    	int length = str.length();
    	if (length == 0)
    		return 0;
    	boolean negFlag = false;
    	int cursor = 0;
    	// skip the space
    	while(cursor < length&&str.charAt(cursor) == ' ')
    		cursor++;
    	// check the signal
    	if(cursor < length&&str.charAt(cursor) == '+')
    		cursor++;
    	else if(cursor < length&&str.charAt(cursor) == '-'){
    		cursor++;
    		negFlag = true;
    	}
    	// readin the number
    	while(cursor < length&&str.charAt(cursor) >= '0'&&str.charAt(cursor) <= '9'){
    		if(negFlag)
    			output = output*10 - str.charAt(cursor) + '0';
    		else
    			output = output*10 + str.charAt(cursor) - '0';
    		// if output is large than the max or is smaller than the min
    		if(output >= max){
    			output = max;
    			break;
    		}
    		if(output <= min){
    			output = min;
    			break;
    		}
    		cursor++;
    	}
		return new Long(output).intValue();     
    }
}
