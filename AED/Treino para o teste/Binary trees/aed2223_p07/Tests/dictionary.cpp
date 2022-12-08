#include <iostream>
#include <string>
#include <fstream>
#include "dictionary.h"

using namespace std;

WordMean::WordMean(string w, string m): word(w), meaning(m) {}

string WordMean::getWord() const {
    return word;
}

string WordMean::getMeaning() const {
    return meaning;
}

void WordMean::setMeaning(string m) {
    meaning = m;
}

void WordMean::setWord(string w) {
    word = w;
}

set<WordMean> Dictionary::getWords() const {
	return words;
}

void Dictionary::addWord(WordMean wm)  {
    words.insert(wm);
}

// ---------------------------------------------

//TODO
bool WordMean::operator< (const WordMean& wm2) const {
    return this->getWord() < wm2.getWord();
}


//TODO
void Dictionary::readFile(ifstream &f) {
    string line;
    int count = 0;
    WordMean wordMean = WordMean("", "");
    for(line; getline(f, line);){
        if(count % 2 == 0){
            if(*(line.end()-1) == '\r' || *(line.end()-1) == '\n') line.erase(line.end()-1);
            wordMean.setWord(line);
        }
        else{
            if(*(line.end()-1) == '\r' || *(line.end()-1) == '\n') line.erase(line.end()-1);
            wordMean.setMeaning(line);
            words.insert(wordMean);
            wordMean.setMeaning("");
            wordMean.setWord("");
        }
        count++;
    }
}

//TODO
string Dictionary::consult(string w1, WordMean& previous, WordMean& next) const {
    WordMean res(w1,"");
    auto it2 = words.begin();
    for(auto it=words.begin();it!=words.end();it++){
        it2 = it;
        if(it->getWord()==w1){
            return it->getMeaning();
        }
        if(it->getWord()>w1){
            break;
        }
    }
    auto nex = it2;
    auto prev=--it2;
    if(prev->getWord().empty()) {
        previous.setWord("");
        previous.setMeaning("");
    }
    else{
        previous.setWord(prev->getWord());
        previous.setMeaning(prev->getMeaning());
    }

    if(nex->getWord().empty()){
        next.setWord("");
        next.setMeaning("");
    }
    else{
        next.setWord(nex->getWord());
        next.setMeaning(nex->getMeaning());
    }
    return"word not found";
}

//TODO
bool Dictionary::update(string w1, string m1) {
    WordMean help = WordMean(w1, m1);
    auto it = words.find(help);
    if(it != words.end()){
        words.erase(it);
        words.insert(help);
        return true;
    }
    words.insert(help);
    return false;
}

//TODO
void Dictionary::print() const {
    for(WordMean wordMean: this->getWords()){
        string word = wordMean.getWord();
        string meaning = wordMean.getMeaning();
        cout << word << '\n';
        cout << meaning << '\n';
    }
}
