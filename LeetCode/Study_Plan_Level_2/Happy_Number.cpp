//      Time Complexity  : O(N)
//      Space Complexity : O(N)
//      where   N = length of number
class Solution {
public:
    //  Function to square and add all digits of the given number
    int get_next(int num){
        int res = 0;
        while(num){
            res += pow(num%10,2);
            num /= 10;
        }
        return res;
    }
    bool isHappy(int n) {
        //  To keep track of visited number
        set<int> visited;
        
        //  Keep going until we start to loop again
        while(n != 1 && visited.count(n) == 0){
            visited.insert(n);
            //  Get next number
            n = get_next(n);
        }
        //  Check if we reached 1
        if(n == 1)
            return true;
        else
            return false;
    }
};