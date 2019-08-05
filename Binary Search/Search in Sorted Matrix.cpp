#include <vector>
using namespace std;

// O(ROW+COLUMN)
vector<int> searchInSortedMatrix(vector<vector<int> > matrix, int target) {
  // Write your code here.
	int r = matrix.size();
	int c = matrix[0].size();
	
	int i=0,j=c-1;
	bool found = 0;
	vector<int> vec;
	
	while(j>=0 && i<r){
		if(matrix[i][j] == target){
			found=1;
			vec.push_back(i);
			vec.push_back(j);
			break;
		}
		if(target>matrix[i][j])
			i++;
		else if(target<matrix[i][j])
			j--;
	}
	
	if(!found){
		vec.push_back(-1);
		vec.push_back(-1);
	}
	
	return vec;
}


// O(LOG(MAX(ROW,COLUMN))) --  Binary Search
// Source: https://www.geeksforgeeks.org/search-element-sorted-matrix/

// This function does Binary search for x in i-th 
// row. It does the search from mat[i][j_low] to 
// mat[i][j_high] 
void binarySearch(int mat[][MAX], int i, int j_low, 
                                int j_high, int x) 
{ 
    while (j_low <= j_high) 
    { 
        int j_mid = (j_low + j_high) / 2; 
  
        // Element found 
        if (mat[i][j_mid] == x) 
        { 
            cout << "Found at (" << i << ", "
                 << j_mid << ")"; 
            return; 
        } 
  
        else if (mat[i][j_mid] > x) 
            j_high = j_mid - 1; 
  
        else
            j_low = j_mid + 1; 
    } 
  
    // element not found 
    cout << "Element no found"; 
} 

void sortedMatrixSearch(int mat[][MAX], int n, 
                                  int m, int x) 
{ 
    // Single row matrix 
    if (n == 1) 
    { 
        binarySearch(mat, 0, 0, m-1, x); 
        return; 
    } 
  
    // Do binary search in middle column. 
    // Condition to terminate the loop when the 
    // 2 desired rows are found 
    int i_low = 0; 
    int i_high = n-1; 
    int j_mid = m/2; 
    while ((i_low+1) < i_high) 
    { 
        int i_mid = (i_low + i_high) / 2; 
  
        // element found 
        if (mat[i_mid][j_mid] == x) 
        { 
            cout << "Found at (" << i_mid << ", "
                 << j_mid << ")"; 
            return; 
        } 
  
        else if (mat[i_mid][j_mid] > x) 
            i_high = i_mid; 
  
        else
            i_low = i_mid; 
    } 
  
    // If element is present on the mid of the 
    // two rows 
    if (mat[i_low][j_mid] == x) 
        cout << "Found at (" << i_low << ","
             << j_mid << ")"; 
    else if (mat[i_low+1][j_mid] == x) 
        cout << "Found at (" << (i_low+1) 
             << ", " << j_mid << ")"; 
  
    // Ssearch element on 1st half of 1st row 
    else if (x <= mat[i_low][j_mid-1]) 
        binarySearch(mat, i_low, 0, j_mid-1, x); 
  
    // Search element on 2nd half of 1st row 
    else if (x >= mat[i_low][j_mid+1]  && 
             x <= mat[i_low][m-1]) 
       binarySearch(mat, i_low, j_mid+1, m-1, x); 
  
    // Search element on 1st half of 2nd row 
    else if (x <= mat[i_low+1][j_mid-1]) 
        binarySearch(mat, i_low+1, 0, j_mid-1, x); 
  
    // search element on 2nd half of 2nd row 
    else
        binarySearch(mat, i_low+1, j_mid+1, m-1, x); 
} 