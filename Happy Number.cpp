// using linked list in happy number question
class Solution {
public:
    bool isHappy(int n) {
        int slow = n;
        int fast = n;

        do{
            slow = findSquare(slow); //one step forward 
            fast = findSquare(findSquare(fast)); //two step forward
        } while(slow != fast);

        if(slow == 1){
            return true;
        }

        return false;
    }

    int findSquare(int num)
    {
        int ans = 0;
        while(num > 0){
            int rem = num%10;
            ans += rem*rem;
            num /= 10; 
        }

        return ans;
    }

};

// without using linked list
class Solution {
public:
    bool isHappy(int n) {
        
        float sum=0;
        int digit=0;
        
        while(true){
            while(n>0){
                digit=n%10;
                sum=sum+pow(digit,2);
                n=n/10;
            }
            if(sum==1){
                return true;
            }
            else if(sum==4){
                return false;
            }
            else{
                n=sum;
                sum=0;
            }
        }
        return false;
    }
};

