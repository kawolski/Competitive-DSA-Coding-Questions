//      Time Complexity  : O(number_of_tasks)
//      Space Complexity : O(N)
//      where N = number_of_tasks + (number_of_tasks-1) * cooldown period
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        //  Count number of each element
        map<char,int> hashmap;
        for(char ch : tasks)
            hashmap[ch]++;
        //  Store tasks by their repetition number
        priority_queue<int,vector<int>> max_heap;
        for(auto ele : hashmap)
            max_heap.push(ele.second);
        //  Space Complexity for dq  : O(n)
        //  where n = cooldown period
        deque<pair<int,int>> dq;
        int time = 0;
        
        while(dq.empty() == false || max_heap.empty() == false){
            //  Increment the time by 1
            time += 1;
            
            //  If task present at max heap
            if(max_heap.empty() == false){
                //  Get & Pop from the max heap
                int front = max_heap.top();
                max_heap.pop();
                
                //  Push to queue if more of this task is left
                if(front-1 > 0)
                    dq.push_back({front-1,time + n});
            }
            //  If dequeue is not empty and the front task's cooldown period is over
            if(dq.empty() == false && dq.front().second == time){
                //  Push to max_heap and pop from dequeue
                max_heap.push(dq.front().first);
                dq.pop_front();
            }
        }
        //  Return time after completing all tasks
        return time;
    }
};