#include <iostream>
#include <vector>
using namespace std;

/*
-----------------------------------------
Buy and Sell Stock (Print Index Also)
-----------------------------------------

Logic:
- Minimum price track karo along with index
- Jab better profit mile → buy & sell index store karo

Time Complexity: O(n)
Space Complexity: O(1)
*/

void maxProfitWithIndex(vector<int>& prices) {
    int n = prices.size();
    
    int minPrice = prices[0];
    int minIndex = 0;
    
    int maxProfit = 0;
    int buyIndex = -1;
    int sellIndex = -1;
    
    for(int i = 1; i < n; i++) {
        
        // Agar current price kam hai → update minimum
        if(prices[i] < minPrice) {
            minPrice = prices[i];
            minIndex = i;
        }
        
        // Profit calculate karo
        int profit = prices[i] - minPrice;
        
        // Agar better profit milta hai
        if(profit > maxProfit) {
            maxProfit = profit;
            buyIndex = minIndex;
            sellIndex = i;
        }
    }
    
    if(maxProfit > 0) {
        cout << "Buy at price " << prices[buyIndex]
             << " on index " << buyIndex << endl;
             
        cout << "Sell at price " << prices[sellIndex]
             << " on index " << sellIndex << endl;
             
        cout << "Maximum Profit: " << maxProfit << endl;
    }
    else {
        cout << "No profitable transaction possible" << endl;
    }
}

int main() {
    vector<int> prices = {7,1,5,3,6,4};
    
    maxProfitWithIndex(prices);
    
    return 0;
}
