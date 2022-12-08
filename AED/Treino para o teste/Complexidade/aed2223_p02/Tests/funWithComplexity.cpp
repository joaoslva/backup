// AED 2022/2023 - Aula Pratica 02
// Pedro Ribeiro (DCC/FCUP) [ultimo update: 25/09/2022]

#include "funWithComplexity.h"

// ----------------------------------------------------------
// Exercicio 4: Sequencias
// ----------------------------------------------------------
// TODO
int FunWithComplexity::maxSubArray(const vector<int> & v) {
    unsigned n = v.size();
    int best_sum = -99999;
    int curr_sum = 0;

    for (unsigned i=0; i<n; i++) { // todas as posicoes iniciais possiveis
        curr_sum = max(v[i], curr_sum + v[i]);
        best_sum = max(best_sum, curr_sum);
    }
    return best_sum;
}


// ----------------------------------------------------------
// Exercicio 5: Analisando um rio
// ----------------------------------------------------------
// TODO
int FunWithComplexity::river(const vector<int> & v, int k, int t) {
    int count = 0;
    int valid = 0;
    int ans = 0;
    for(int i = 0; i < v.size(); i++){
        if(count == k){
            if(v[i-k] >= t) valid--;
            if(v[i] >= t) valid++;
            if(valid >= k/2.0) ans++;
        }
        else{
            if(v[i] >= t) valid++;
            count++;
            if(count == k){
                if(valid >= k/2.0) ans++;
            }
        }
    }
    return ans;
}

// ----------------------------------------------------------
// Exercicio 6: Espiral de Números
// ----------------------------------------------------------
// TODO
pair<int, int> FunWithComplexity::spiral(int n) {
    pair<int, int> ans = {0, 0};
    return ans;
}

// ----------------------------------------------------------
// Exercicio 8: Caderno Quadriculado
// ----------------------------------------------------------
// TODO
long long FunWithComplexity::gridSum(int a, int b) {
    return 0;
}