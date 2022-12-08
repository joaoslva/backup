// AED 2022/2023 - Aula Pratica 01
// Pedro Ribeiro (DCC/FCUP) [ultimo update: 18/09/2022]

#include "funWithCycles.h"

// ----------------------------------------------------------
// Exercicio 1: Palindromos
// ----------------------------------------------------------
// TODO
bool FunWithCycles::palindrome(const std::string & s) {
    int begin = 0;
    int end = s.size() - 1;
    bool result = true;
    while(begin < end){
        if(s[begin] != s[end]){
            result = false;
            break;
        }
        begin++;
        end--;
    }
    return result;
}

// ----------------------------------------------------------
// Exercicio 2: Frases Palindromo
// ----------------------------------------------------------
// TODO
bool FunWithCycles::palindromeSentence(const std::string & s) {
    string help;
    for(char c: s){
        if(('a'<=c && c<='z') || ('A'<=c && c <='Z')){
            help += toupper(c);
        }
    }
    int begin = 0;
    int end = help.size() - 1;
    bool result = true;
    while(begin < end){
        if(help[begin] != help[end]){
            result = false;
            break;
        }
        begin++;
        end--;
    }
    return result;
}

// ----------------------------------------------------------
// Exercicio 3: Numeros Interessantes
// ----------------------------------------------------------
// TODO
int FunWithCycles::nextInterestingNumber(int n, int sum) {
    n++;
    while(true){
        int help = digitSum(n);
        if(help == sum) break;
        n++;
    }
    return n;
}

// Esta funcao auxiliar devera devolver a soma dos digitos de n
// TODO
int FunWithCycles::digitSum(int n) {
    int result = 0;
    while(n > 0){
        int help = n % 10;
        result += help;
        n /= 10;
    }
    return result;
}

// ----------------------------------------------------------
// Exercicio 4: O Inverno esta a chegar
// ----------------------------------------------------------
// TODO
int FunWithCycles::winter(const vector<int> & v) {
    int max_seq = 0;
    int help = 0;
    for(int i = 0; i < v.size()-1; i++){
        if(v[i+1] - v[i] < 0){
            help++;
            if(max_seq < help){
                max_seq = help;
            }
        }
        else{
            help = 0;
        }
    }
    return max_seq;
}


// ----------------------------------------------------------
// Exercicio 5: Brincando com vectores
// ----------------------------------------------------------

// a) count
// TODO
int FunWithCycles::count(const vector<int> & v, int n) {
    int count = 0;
    for(int number: v){
        if(number == n) count++;
    }
    return count;
}

// b) hasDuplicates
// TODO
bool FunWithCycles::hasDuplicates(const vector<int> & v) {
    bool hasDup = false;
    for(int i = 0; i < v.size()-1; i++){
        for(int j = i+1; j < v.size();j++){
            if(v[i] == v[j]){
                hasDup = true;
                break;
            }
        }
        if(hasDup) break;
    }
    return hasDup;
}

// c) removeDuplicates
// TODO
void FunWithCycles::removeDuplicates(vector<int> & v) {
    for(int i = 0; i < v.size()-1; i++){
        for(int j = i+1; j < v.size();j++){
            if(v[i] == v[j]){
                v.erase(v.begin()+j);
                j--;
            }
        }
    }
}

// d) merge
// TODO
vector<int> FunWithCycles::merge(const vector<int> & v1, const vector<int> & v2) {
    vector<int> ans;
    int total_size = v1.size() + v2.size();
    int v1_it = 0;
    int v2_it = 0;
    for(int i = 0; i < total_size; i++){
        if(v1.size() == v1_it){
            ans.push_back(v2[v2_it]);
            v2_it++;
        }
        else if(v2.size() == v2_it){
            ans.push_back(v1[v1_it]);
            v1_it++;
        }
        else{
            if(v1[v1_it] < v2[v2_it]){
                ans.push_back(v1[v1_it]);
                v1_it++;
            }
            else{
                ans.push_back(v2[v2_it]);
                v2_it++;
            }
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
    for(int i = 0; i < sqrt(n); i++){
        if(n % i == 0) return false;
    }
    return true;
}

// b) factorize
// TODO
vector<int> FunWithCycles::factorize(int n) {
    vector<int> ans;
    for(int i = 2; i < n; i++){
        if(isPrime(i) && n % i == 0){
            ans.push_back(i);
            i = 1;
        }
    }
    return ans;
}

// c) listPrimes
// TODO
vector<int> FunWithCycles::listPrimes(int n) {
    vector<int> ans;

    return ans;
}


// ----------------------------------------------------------
// Exercicio 7: Numeros interessantes (versao desafio)
// ----------------------------------------------------------
// TODO
long long FunWithCycles::fastNextInterestingNumber(long long n, int sum) {
    return 0;
}
