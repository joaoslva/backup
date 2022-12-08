#include "funStackQueueProblem.h"
#include "cell.h"

FunStackQueueProblem::FunStackQueueProblem() {}


//-----------------------------------------------------------------

// TODO
vector<string> FunStackQueueProblem::binaryNumbers(int n) {
    vector<string> res;
    queue<string> waiting;
    waiting.push("1");
    for(int i = 0; i < n; i++) {
        string num = waiting.front();
        waiting.pop();
        res.push_back(num);
        waiting.push(num + "0");
        waiting.push(num + "1");
    }
    return res;
}


//TODO
vector<int> FunStackQueueProblem::calculateSpan(vector<int> prices)
{
    vector<int> res;
    if (prices.empty()) {
        return res;
    }
    res.push_back(1);
    stack<int> st;
    st.push(0);
    for (int i = 1; i < prices.size(); i++) {
        if (st.empty()) {
            res.push_back(i);
            st.push(i+1);
        }
        else if (prices.at(i) <= prices.at(st.top())) {
            st.push(i);
            res.push_back(1);
        }
        else {
            while (!st.empty() && prices.at(i) > prices.at(st.top())) {
                st.pop();
            }
            if (st.empty()) {
                res.push_back(i+1);
                st.push(i);
            }
            else {
                res.push_back(i - st.top());
                st.push(i);
            }
        }
    }
    return res;
}


//TODO
int FunStackQueueProblem::knightJumps(int initialPosx, int initialPosy, int targetPosx, int targetPosy, int n) {

    return -1;
}






