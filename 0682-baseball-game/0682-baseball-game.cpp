class Solution {
public:
    int calPoints(vector<string>& operations){
        stack<int> record;
        int sum=0;
        for(int i=0;i<operations.size();i++){
            if(operations[i] == "+"){
                int top1 = record.top();
                record.pop();
                int top2 = record.top();
                record.push(top1);
                record.push(top1 + top2);
            }
            else if(operations[i] == "D"){
                record.push(2 * record.top());
            }
            else if(operations[i] == "C"){
                record.pop();
            }
            else{
                record.push(stoi(operations[i]));
            }
        }
        while(!record.empty()){
            sum += record.top();
            record.pop();
        }
        return sum;
    }
};