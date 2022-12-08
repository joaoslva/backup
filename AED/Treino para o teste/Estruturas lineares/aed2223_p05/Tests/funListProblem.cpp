#include "funListProblem.h"
#include <algorithm>

FunListProblem::FunListProblem() {}


//-----------------------------------------------------------------

// TODO
list<int> FunListProblem::removeHigher(list<int> &values, int x) {
    list<int> l1;
    list<int> help;
    /*
    auto i = values.begin();
    while(i != values.end()){
        if(values.front() > x){
            l1.push_back(values.front());
            values.erase(i);
        }
        i++;
    }
    */
    for(int i: values){
        if(i > x){
            l1.push_back(i);
        }
        else{
            help.push_back(i);
        }
    }
    values = help;
    return l1;
}



//TODO
bool comp(pair<int, int> x, pair<int, int> y) {
    return x.first < y.first;
}
list<pair<int,int>> FunListProblem::overlappingIntervals(list<pair<int,int>> values) {
    list<pair<int,int>> res;
    values.sort(comp);
    auto start = values.begin();
    res.push_back(*start);
    start++;
    for (start; start != values.end(); start++) {
        if (start->first <= res.back().second) {
            res.back().second = max(res.back().second, start->second);
        }
        else {
            res.push_back(*start);
        }
    }
    return res;
}
}
