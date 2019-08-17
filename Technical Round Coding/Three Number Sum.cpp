#include <bits/stdc++.h>
using namespace std;

vector<vector<int> > threeNumberSum(vector<int> array, int targetSum) {
  // Write your code here.
	vector<vector<int> > ans;
	int l,r,i,j;
	int n = array.size();
	
	sort(array.begin(),array.end());
	
	for(i=0;i<n-2;i++){
		l=i+1;
		r=n-1;
		while(l<r){
			if(array[i]+array[l]+array[r] == targetSum){
				vector<int> vec;
				vec.push_back(array[i]);
				vec.push_back(array[l]);
				vec.push_back(array[r]);
				//sort(vec.begin(),vec.end());
				ans.push_back(vec);
				l++;
				r--;
			}
			else if(array[i] + array[l] + array[r] > targetSum){
				r--;
			}
			else if(array[i] + array[l] + array[r] < targetSum){
				l++;
			}
			
		}
	}
	
	// sort(ans.begin(),ans.end());
	return ans;
}
