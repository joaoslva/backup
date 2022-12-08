#include "funHashingProblem.h"
#include <unordered_set>

FunHashingProblem::FunHashingProblem() {}

// -------------------------------------

// TODO
vector<int> FunHashingProblem::findDuplicates(const vector<int>& values, int k) {
    vector<int> res;
    unordered_set<int> helper;
    for(int i = 0; i < values.size()-k; i++){
        if(i <= k){
            if(helper.find(values[i]) != helper.end()) res.push_back(values[i]);
            helper.insert(values[i]);
        }
        helper.erase(values[i-k-1]);
        if(helper.find(values[i]) != helper.end()) res.push_back(values[i]);
        helper.insert(values[i]);
        helper.insert(values[i]);
    }
    return res;
}