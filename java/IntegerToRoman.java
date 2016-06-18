package leetcode;

public class IntegerToRoman {
	public static void main(String[] args){
		int input = 3999;
		System.out.println(new IntegerToRoman().intToRoman(input));
	}
	
	// every place can be replace by a specific string
    public String intToRoman(int num) {
        String output = "";
        String[][] place = 
        	{
        			{"","M","MM","MMM","","","","","",""},
        			{"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"},
        			{"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"},
        			{"","I","II","III","IV","V","VI","VII","VIII","IX"}
        	};
        output += place[0][num/1000];
        output += place[1][(num%1000)/100];
        output += place[2][(num%100)/10];
        output += place[3][(num%10)];
        return output;
    }
}
