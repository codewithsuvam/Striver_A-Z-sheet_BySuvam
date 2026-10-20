// formula used here 
// Water at position [i]=max(0,min(L_max,R_max)-height[i])
// Algo covers in 6 steps and concept of this question is Two Pointers + Greedy Approach
// 1. Initialize left and right pointers at the beginning and end of the height array.
// 2. Initialize leftMax, rightMax, and total water to 0.
// 3. Compare the current heights at the left and right pointers.
// 4. Process the side with the smaller or equal height, update its maximum height, and add trapped water if the current height is below that maximum.
// 5. Move the processed pointer inward and repeat until both pointers meet.
// 6. Return the total trapped water.
//here is the code for this question 
class Solution{
    public:
    int trap(vector<int>&height){  //same logic of container with most water 
        int left=0;
        int right= height.size()-1;
        int leftMax=0;
        int rightMax=0;
        int water =0;
        while (left<right){
            //left size process 
            if(height[left]<=height[right]){
                if(height[left]>=leftMax){
                    leftMax=height[left];

                }
                else{
                    water+= leftMax-height[left];
                }
                left++;
            }
            else{
                //right size process 
                if(height[right]>=rightMax){
                    rightMax=height[right];
                }else{
                    water += rightMax-height[right];
                }
                right--;
            }
        }
        return water;

    }

};
// time complexity : O (n) each pointer is move in a single direction 


