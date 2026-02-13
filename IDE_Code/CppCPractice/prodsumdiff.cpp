#include <bits/stdc++.h> 
int findProductSumDifference(int n){
	// Write your code here
	int prod= 1; 
	int sum = 0;
	int num = n;
	while(num != 0){
        prod *= num % 10;
		sum += num % 10;
		num /= 10;
	}
	return prod - sum;
}
