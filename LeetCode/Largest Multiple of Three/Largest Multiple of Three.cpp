class Solution {
public:
    string largestMultipleOfThree(vector<int>& digits) {
        int sum = 0;
        vector<int> freq(10, 0);
        for(int i=0; i<digits.size(); i++){
            sum+=digits[i];
            freq[digits[i]]++;       //value of [digit[i]]th term of freq vector incremented
        }
        string ans = "";
        bool flag = 1;
        if(sum%3==1){        //condition to checked if sum is a multiple of 3
            if(freq[1]>0){         //different cases checked 
                freq[1]--;
            } else if(freq[4]>0){
                freq[4]--;
            } else if(freq[7]>0){
                freq[7]--;
            } else if(freq[2]>1){
                freq[2]-=2;
            } else if(freq[5]>0 && freq[2]>0){
                freq[5]--;
                freq[2]--;
            } else if(freq[8]>0 && freq[2]>0){
                freq[8]--;
                freq[2]--;
            } else if(freq[5]>1){
                freq[5]-=2;
            } else if(freq[8]>0 && freq[5]>0){
                freq[8]--;
                freq[5]--;
            } else if(freq[8]>1){
                freq[8]-=2;
            } else{
                flag=0;
            }
        } else if(sum%3==2){
            if(freq[2]>0){
                freq[2]--;
            } else if(freq[5]>0){
                freq[5]--;
            } else if(freq[8]>0){
                freq[8]--;
            } else if(freq[1]>1){
                freq[1]-=2;
            } else if(freq[4]>0 && freq[1]>0){
                freq[4]--;
                freq[1]--;
            } else if(freq[7]>0 && freq[1]>0){
                freq[7]--;
                freq[1]--;
            } else if(freq[7]>0 && freq[4]>0){
                freq[7]--;
                freq[4]--;
            } else if(freq[7]>1){
                freq[7]-=2;
            } else{
                flag = 0;
            }
        }
        if(flag==0){
            return ans;                 // integer value returned
        }
        for(int i=9; i>=0; i--){
            if(freq[i]==0){
                continue;
            }
            if(i==0 && ans==""){         //for empty ans
                ans="0";
                break;
            }
            string s(freq[i], to_string(i)[0]);
            ans+=s;
        }
      return ans;            // integer value returned
     }
};
