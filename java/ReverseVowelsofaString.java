package leetcode;

public class ReverseVowelsofaString {
	public static void main(String[] args) {
		String input = "leetcode";
		System.out.println(reverseVowels(input));
	}
	
	// use two cursor, move them to find the vowels, 
	// when both found, exchange them
    public static String reverseVowels(String s) {
        int forwardCursor = 0,backwardCursor = s.length() - 1;
        char[] cs = s.toCharArray();
        while(forwardCursor < backwardCursor){
        	while((!isVowel(cs[forwardCursor]))){
        		if(forwardCursor >= backwardCursor)
        			break;
        		forwardCursor++;
        	}
        	while(!(isVowel(cs[backwardCursor]))){
        		if(forwardCursor >= backwardCursor)
        			break;
        		backwardCursor--;
        	}
        	if(isVowel(cs[forwardCursor])&&isVowel(cs[backwardCursor])){
	        	char temp = cs[forwardCursor];
	        	cs[forwardCursor] = cs[backwardCursor];
	        	cs[backwardCursor] = temp;
	        	forwardCursor++;
	        	backwardCursor--;
        	}
        }
        return new String(cs);
    }
    public static boolean isVowel(char c){
    	switch (c) {
		case 'a':
		case 'e':
		case 'i':
		case 'o':
		case 'u':
		case 'A':
		case 'E':
		case 'I':
		case 'O':
		case 'U':return true;
		default:return false;
		}
    }
}
