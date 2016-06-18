package leetcode;

import java.util.List;

public class ReconstructItinerary {
	public static void main(String[] args) {
		String[][] tickets = {{"JFK","SFO"},{"JFK","ATL"},{"SFO","ATL"},{"ATL","JFK"},{"ATL","SFO"}};
		for(String s : findItinerary(tickets))
			System.out.print(s+" ");
	}
    public static List<String> findItinerary(String[][] tickets) {
     	 
    }
}
