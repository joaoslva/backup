// AED 2022/2023 - Aula Pratica 01
// Pedro Ribeiro (DCC/FCUP) [ultimo update: 18/09/2022]

#include "funWithCycles.h"

// ----------------------------------------------------------
// Exercicio 1: Palindromos
// ----------------------------------------------------------
// TODO
bool FunWithCycles::palindrome(const std::string & s) {
    int size = s.length();
    for(int i = 0; i < size / 2; i++){
        if(s[i] != s[size - i -1]){
            return false;
        }
    }
    return true;
}

// ----------------------------------------------------------
// Exercicio 2: Frases Palindromo
// ----------------------------------------------------------
// TODO
bool FunWithCycles::palindromeSentence(const std::string & s) {
    std::string result = "";
    for(char c : s){
        if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')){
            result.push_back(tolower(c));
        }
    }

    int size2 = result.length();
    for(int i = 0; i < size2 / 2; i++){
        if(result[i] != result[size2 - i -1]){
            return false;
        }
    }
    return true;
}

// ----------------------------------------------------------
// Exercicio 3: Numeros Interessantes
// ----------------------------------------------------------
// TODO
int FunWithCycles::nextInterestingNumber(int n, int sum) {
    n++;

    while(FunWithCycles::digitSum(n) != sum){
        n++;
    }
    return n;
}

// Esta funcao auxiliar devera devolver a soma dos digitos de n
// TODO
int FunWithCycles::digitSum(int n) {
    long long res = 0;
    while(n > 0){
        res += n % 10;
        n = n / 10;
    }
    return res;
}

// ----------------------------------------------------------
// Exercicio 4: O Inverno esta a chegar
// ----------------------------------------------------------
// TODO
int FunWithCycles::winter(const vector<int> & v) {
    int tamanho = v.size();
    int res = 0;
    int negative = 0;
    for(int i = 0; i < tamanho - 1; i++){
        if(v[i+1] - v[i] < 0){
            negative++;
            if(res < negative){
                res = negative;
            }
        }
        else{
            negative = 0;
        }
    }
    return res;
}


// ----------------------------------------------------------
// Exercicio 5: Brincando com vectores
// ----------------------------------------------------------

// a) count
// TODO
int FunWithCycles::count(const vector<int> & v, int n) {
    int res = 0;
    for(int i = 0; i < v.size(); i++){
        if(v[i] == n) {
            res = res + 1;
        }
    }
    return res;
}

// b) hasDuplicates
// TODO
bool FunWithCycles::hasDuplicates(const vector<int> & v) {
    bool ans = false;
    for(int i = 0; i < v.size() - 1; i++){
        for(int j = i + 1; j < v.size(); j++){
            if(v[i] == v[j]){
                ans = true;
                break;
            }
        }
        if(ans == true){
            break;
        }
    }
    return ans;
}

// c) removeDuplicates
// TODO
void FunWithCycles::removeDuplicates(vector<int> & v){
    for (int i = 0; i < v.size() - 1; i++) {
        for (int j = i + 1; j < v.size(); j++) {
            if (v[i] == v[j]) {
                v.erase(v.begin() + j);
                j--;
            }
        }
    }
}

// d) merge
// TODO
vector<int> FunWithCycles::merge(const vector<int> & v1, const vector<int> & v2) {
    vector<int> ans;
    int v1_s = v1.size();
    int v2_s = v2.size();
    int big_size = v1_s +v2_s;

    int v1_index = 0;
    int v2_index = 0;

    for(int i = 0; i < big_size; i++){
        if(v1_s == 0){
            ans.push_back(v2[v2_index]);
            v2_index++;
            v2_s--;
        }
        else if (v2_s == 0){
            ans.push_back(v1[v1_index]);
            v1_index++;
            v1_s--;
        }

        else if(v1[v1_index] < v2[v2_index]){
            ans.push_back(v1[v1_index]);
            v1_index++;
            v1_s--;
        }

        else if(v1[v1_index] > v2[v2_index]){
            ans.push_back(v2[v2_index]);
            v2_index++;
            v2_s--;
        }

        else{
            ans.push_back(v1[v1_index]);
            v1_index++;
            v1_s--;
        }

    }
    return ans;
}

// ----------------------------------------------------------
// Exercicio 6: Brincando com numeros primos
// ----------------------------------------------------------

// a) isPrime
// TODO
bool FunWithCycles::isPrime(int n) {
    for(int i = 2; i <= sqrt(n); i++){
        if(n % i == 0){
            return false;
        }
    }
    return true;
}

// b) factorize
// TODO
vector<int> FunWithCycles::factorize(int n) {
    vector<int> ans;
    int num = n;
    bool flag = false;
    for(int i = 2; i <= n; i++){
        while(n % i == 0){
            ans.push_back(i);
            n /= i;
            flag = true;
        }
    }
    if(flag == false){
        ans.push_back(num);
    }
    return ans;
}

// c) listPrimes
// TODO
vector<int> FunWithCycles::listPrimes(int n) {
    vector<int> ans;
    vector<bool> help;
    for(int i = 1; i <= n; i++){
        help.push_back(true);
    }

    for(int i = 2; i <= sqrt(n); i++){
        if(help[i] == 1){
            for(int j = i*i; j <= n; j = j + i){
                help[j] = false;
            }
        }
    }
    for(int i = 2; i <= help.size(); i++){
        if(help[i] == true){
            ans.push_back(i);
        }
    }
    return ans;
}


// ----------------------------------------------------------
// Exercicio 7: Numeros interessantes (versao desafio)
// ----------------------------------------------------------
// TODO
long long FunWithCycles::fastNextInterestingNumber(long long n, int sum) {
    n++;
    long long num = n;
    long long sum2;

    while (true) {
        if(num % 10 > 0){
            sum2 += num % 10 > 0;
            num /= 10;
        }

        else if(sum2 == sum){
            return n;
        }

        else{
            n++;
            num = n;
            sum2 = 0;
        }
    }
}
/*
int FunWithCycles::digitSum(int n) {
    int res = 0;
    while(n > 0){
        res += n % 10;
        n = n / 10;
    }
    return res;
*/