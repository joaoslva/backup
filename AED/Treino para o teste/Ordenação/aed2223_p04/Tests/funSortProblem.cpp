#include "funSortProblem.h"
#include <algorithm>
#include <limits.h>

FunSortProblem::FunSortProblem() {}


//-----------------------------------------------------------------

// TODO
void FunSortProblem::expressLane(vector<Product> &products, unsigned k) {
    sort(products.begin(), products.end());

    if(products.size() > k){
        products.erase(products.begin() + k, products.end());
    }
}

// TODO
int FunSortProblem::minDifference(const vector<unsigned> &values, unsigned nc) {
    if(values.size() < nc) return -1;
    vector<unsigned > helper = values;
    int min, max, help;
    int ans = INT32_MAX;
    sort(helper.begin(), helper.end());
    for(int i = 0; i < helper.size(); i++){
        if(i >= nc-1){
            min = helper[i-nc+1];
            max = helper[i];
            help = max - min;
            if(ans > help) ans = help;
        }
    }
    return ans;
}


// TODO
unsigned FunSortProblem::minPlatforms (const vector<float> &arrival, const vector<float> &departure) {
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
    return 0;
}

//TODO
unsigned FunSortProblem::numInversions(vector <int> v) {
    unsigned inversions = 0;
    for(int i = 0; i < v.size()-1; i++){
        if(v[i] > v[i+1]){
            int temp = v[i];
            v[i] = v[i+1];
            v[i+1] = temp;
            i = -1;
            inversions++;
        }
    }
    return inversions;
}

// TODO
void FunSortProblem::nutsBolts(vector<Piece> &nuts, vector<Piece> &bolts) {

}

