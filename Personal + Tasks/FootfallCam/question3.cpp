#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> consecutiveOrder(vector<int>& nums) {
    vector<string> result;
    if(nums.empty()){
        return result;
    }
    int start = nums[0];
    int end = nums[0];
    for(int i = 1; i < nums.size(); i++){
        if(nums[i] == end + 1){
            //this checks if consecutive and changes end to newest consecutive
            end = nums[i];
        } 
        else{
            if(start == end){
                //if the numbers are not consecutive and we havent found a chain we just add the digit in
                result.push_back(to_string(start));
            } 
            else{
                //if we have found a consecutive chain we add the digit in 
                result.push_back(to_string(start) + "->" + to_string(end));
            }
            start = nums[i];
            end = nums[i];
        }
    }

    // we need to run it one extra time for the final set of vaLues (we cannot do this within the loop as we will access invalid memory allocations)
    if(start == end){
        result.push_back(to_string(start));
    } 
    else{
        result.push_back(to_string(start) + "->" + to_string(end));
    }
    return result;
}

int main() {
    vector<int> nums1 = {0, 1, 2, 4, 5, 7};
    vector<string> result1 = consecutiveOrder(nums1);
    for(int i = 0; i < result1.size(); i++){
        cout << result1[i] + " "; 
    }
    cout << endl; 

    vector<int> nums2 = {0, 2, 3, 4, 6, 8, 9};
    vector<string> result2 = consecutiveOrder(nums2);
    for(int i = 0; i < result2.size(); i++){
        cout << result2[i] + " "; 
    }
    cout << endl; 

    return 0;
}