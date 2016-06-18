package leetcode;

public class RomanToInteger {
	public static void main(String[] args){
		String input = "DCXXI";
		System.out.println(new RomanToInteger().romanToInt(input));
	}
    public int romanToInt(String s){
        int output = 0;
        int length = s.length();
        int preNum = 0,num = 0;
        for(int i = 0;i < length;i++){
        	preNum = num;
        	num = romanCharToInt(s.charAt(i));
        	if(preNum < num){
        		output += (num - preNum*2);
        	}
        	else{
        		output += num;
        	}
        }
        return output;
    }
    public int romanCharToInt(char c){
    	switch (c) {
		case 'I':return 1;
		case 'X':return 10;
		case 'C':return 100;
		case 'M':return 1000;
		case 'V':return 5;
		case 'L':return 50;
		case 'D':return 500;
		default:return 0;
		}
    }
}
