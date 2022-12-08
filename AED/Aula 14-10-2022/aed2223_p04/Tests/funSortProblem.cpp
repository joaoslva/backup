#include "funSortProblem.h"
#include <algorithm>
#include <limits.h>

FunSortProblem::FunSortProblem() {}


//-----------------------------------------------------------------

// TODO

void FunSortProblem::expressLane(vector<Product> &products, unsigned k) {
    sort(products.begin(), products.end());

    if(products.size() > k){
        while (products.size() != k) {
            products.erase(products.begin() + k, products.end());
        }
    }
}

// TODO
int FunSortProblem::minDifference(const vector<unsigned> &values, unsigned nc) {
    if(values.size() < nc){
        return -1;
    }
    vector<unsigned> helper = values;
    sort(helper.begin(), helper.end());
    int compare = 100000;
    int min = 0;
    int max = 0;
    int help = 0;

    for(int i = 0; i < helper.size(); i++){
        if(i >= nc - 1){
            max = helper[i];
            min = helper[i - nc + 1];
            help = max - min;
            if(help < compare) compare = help;
        }
    }
    return compare;
}


// TODO
unsigned FunSortProblem::minPlatforms (const vector<float> &arrival, const vector<float> &departure){
    int len = (int) arrival.size();
    unsigned usedPlatforms = 1;
    unsigned final = 1;
    int a = 1;
    int d = 0;
    vector<float> order_A = arrival;
    vector<float> order_D = departure;
    sort(order_A.begin(), order_A.end());
    sort(order_D.begin(), order_D.end());

    while (a < len && d < len) {
        if (order_A[a] <= order_D[d]) {
            usedPlatforms += 1;
            a++;
        }
        else if (order_A[a] > order_D[d]) {
            usedPlatforms -= 1;
            d++;
        }

        if (usedPlatforms > final) {
            final = usedPlatforms;
        }
    }
    return final;
}

//TODO
unsigned mergeSort(vector<int>&v){
    if(v.size()==1){
        return 0;
    };

    vector<int>left(v.begin(),v.begin()+(v.size()-1)/2+1);
    vector<int>right(v.begin()+(v.size() - 1)/2+1,v.end());
    unsigned res =0;
    res+=mergeSort(left);
    res+=mergeSort(right);

    int i=0,j=0;

    while(i<left.size()||j<right.size()){
        if((left[i]<=right[j]&&i<left.size())||j==right.size()){
            v[i+j]=left[i];
            i++;
        }
        else{
            v[i+j]=right[j];
            j++;
            res+=(left.size()-i);
        }
    }
    return res;
}

unsigned FunSortProblem::numInversions(vector <int> v) {
    return mergeSort(v);
}

// TODO
void FunSortProblem::nutsBolts(vector<Piece> &nuts, vector<Piece> &bolts) {
}

