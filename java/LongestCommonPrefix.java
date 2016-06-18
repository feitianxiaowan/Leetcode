package leetcode;

public class LongestCommonPrefix {
	public static void main(String[] args) {
		String[] input = {"ahdasljflkasjf","ahdaajdknjj","ahdancnnsaeo"};
		System.out.println(new LongestCommonPrefix().longestCommonPrefix(input));
	}
    public String longestCommonPrefix(String[] strs) {
        String output = "";
        if(strs.length == 0)
        	return output;
        if(strs.length == 1)
        	return strs[0];
        int minLength = strs[0].length();
        for(int i = 1;i < strs.length;i++){
        	if(strs[i].length() < minLength)
        		minLength = strs[i].length();
        }
        char match = ' ';
        boolean matchFlag = true;
        for(int i = 0;i < minLength;i++){
        	match = strs[0].charAt(i);
        	for(int j = 1;j < strs.length;j++){
        		if(match != strs[j].charAt(i)){
        			matchFlag = false;
        			break;
        		}
        	}
        	if(matchFlag)
        		output += match;
        	else
        		break;
        }
        return output;
    }
}
