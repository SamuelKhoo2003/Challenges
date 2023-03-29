#include <iostream>
#include <sstream>
#include <vector>

int compareVersions(const std::string& v1, const std::string& v2) {
    std::vector<int> nums1, nums2;
    std::stringstream ss1(v1), ss2(v2);
    std::string tmp;

    //store each string into a vector to compare
    while(getline(ss1, tmp, '.')){
        nums1.push_back(stoi(tmp));
    }

    while(getline(ss2, tmp, '.')){
        nums2.push_back(stoi(tmp));
    }

    int i = 0;
    while(i < nums1.size() && i < nums2.size()){
        if(nums1[i] < nums2[i]){
            //return -1 as if v2 > v1 we return -1
            return -1;
        } else if(nums1[i] > nums2[i]){
            //return 1 as if v1 > v2 we return 1
            return 1;
        }
        i++;
    }

    //extra cases if there are more numbers in one string than another
    while(i < nums1.size()){
        if(nums1[i] > 0){
            return 1;
        }
        i++;
    }

    while(i < nums2.size()){
        if(nums2[i] > 0){
            return -1;
        }
        i++;
    }

    // if all numbers are equal, return 0
    return 0;
}

int main() {
    std::cout << compareVersions("1.3", "3.1") << std::endl; // expected output: -1
    std::cout << compareVersions("2.12.1", "2.3") << std::endl; //expected output: 1
    std::cout << compareVersions("3.1.34", "3.1.2") << std::endl; //epxpected output: 1

    // extra test case to see if equal: 
    std::cout << compareVersions("3.14", "3.14") << std::endl; 
}
    