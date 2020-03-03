// WordCount.cpp
// Written by Richert Wang for CS 32, F18.

#include "WordCount.h"
#include <algorithm> 
#include <vector>
#include <sstream>
using namespace std;

// Default constructor
WordCount::WordCount() {}

// Simple hash function. Do not modify.
size_t WordCount::hash(std::string word) const {
	size_t accumulator = 0;
	for (size_t i = 0; i < word.size(); i++) {
		accumulator += word.at(i);
	}
	return accumulator % CAPACITY;
}

int WordCount::getTotalWords() const {

  size_t total=0;
  for(size_t i =0 ; i < CAPACITY ; i++){
    for ( size_t j =0; j < table[i].size(); j++){
    total += table[i][j].second;
  }
  //cout << total << endl;
}
        return total;
}

int WordCount::getNumUniqueWords() const {

  int total=0;
  for(size_t i =0 ; i < CAPACITY ; i++){
    total +=table[i].size();
}
return total;
}

int WordCount::getWordCount(std::string word) const {
  transform(word.begin(), word.end(), word.begin(), ::toupper);

  size_t wordC =0;   
  for(size_t i =0 ; i < CAPACITY ; i++){
    for ( size_t j =0; j < table[i].size(); j++){
      if (table[i][j].first == word){
        wordC = table[i][j].second; 
      }
  }
}
return wordC;
}
	

int WordCount::incrWordCount(std::string word) {
  // check if empty string f
  if(word == ""){
    return 0; 
  }
  string add = stripWord(word); 
  transform(add.begin(), add.end(), add.begin(), ::toupper);
  if(add == ""){
    return 0; 
  }

  size_t wordC=0; 
  bool found = false;
  //cout << word << CAPACITY<< endl;
  for(size_t i =0 ; i < CAPACITY ; i++){
    for ( size_t j =0; j < table[i].size(); j++){
      if (table[i][j].first == add){
        // increment count for word
        wordC = table[i][j].second; 
        wordC++;
        table[i][j].second = wordC; 
        found = true;
      }

  }
}
 if (found == false) {
        
        /// add word to vector + update the size
        string add = stripWord(word); 
        transform(add.begin(), add.end(), add.begin(), ::toupper);
        int arrayI = hash(add);
        table[arrayI].push_back(std::make_pair(add,1));
        wordC++;
      }
return wordC;
}


bool WordCount::isWordChar(char c) {
	// STUB

  if (isalpha(c) == false){
    return false;
  }
  else 
    return true;
}


std::string WordCount::stripWord(std::string word) {
	// STUB
  int size = word.size();
  int i =0;
  std::string create;
//       int j =0;
//     while(isWordChar(create[j])==false){
//       create.erase(j);
// cout << create << endl;
//       j++;
//     }
  while(word[i]){
    if(isWordChar(word[i]) == true ){
      create += word[i];
      size = word.size();
     // cout << create << endl;

    }
    else if((word[i] == '-' || word[i] == '\'') && (i != 0 && i != size-1 && create != "")  ){
      create += word[i];
      size = word.size();
      //cout << i <<" "<<  create << endl;
    }
   i++;
    } 
    if(create == "") {
      return "";
    }
    int size1 = create.size();   
    while(isWordChar(create[size1-1]) == false){
      create.erase(size1-1);
      size1 = create.size(); 
    }


    
	return create;
}
void WordCount::dumpWordsSortedByWord(std::ostream &out) const {

  vector<string> all;

  for(size_t i =0 ; i < CAPACITY ; i++){
    for ( size_t j =0; j < table[i].size(); j++){
      all.push_back(table[i][j].first);
    }
  }

  string temp;
  int size = all.size();
  for(int i = size-1; i>0; i--){
    for (int j =0;j<i; j++){
      if(all[j]>all[j+1]){
        temp = all[j];
        all[j]=all[j+1];
        all[j+1] = temp;
      }
    }
  }

  int k =0; 
  while(k != size){
  out << all[k] << "," << getWordCount(all[k]) << endl;
  k++;
  } 
  //out.str();      
}

void WordCount::dumpWordsSortedByOccurence(std::ostream &out) const {
  vector<pair<string, int> > number;
  
  for(size_t i =0 ; i < CAPACITY ; i++){
    for ( size_t j =0; j < table[i].size(); j++){  
      number.push_back(make_pair(table[i][j].first,table[i][j].second));
    }
  }

  int size = number.size(); 
  int temp;
  string temp1;
  for(int i = size-1; i>0; i--){
    for (int j =0;j<i; j++){
      if(number[j].second == number[j+1].second){
        if(number[j].first > number[j+1].first){
        temp = number[j].second;
        temp1 = number[j].first;
        number[j].second=number[j+1].second;
        number[j].first=number[j+1].first;
        number[j+1].second = temp;
        number[j+1].first = temp1;
        }
      }
      else if(number[j].second < number[j+1].second){
        temp = number[j].second;
        temp1 = number[j].first;
        number[j].second=number[j+1].second;
        number[j].first=number[j+1].first;
        number[j+1].second = temp;
        number[j+1].first = temp1;
      }
    }
  }

  for(int k =0; k < size ; k++){
    out << number[k].first << "," << number[k].second << endl;
  }                                                                
}

void WordCount::addAllWords(std::string text) {
        std::string word = "";
        int x =0;
        while(text[x]){
          if (text[x] == ' '){
           // cout << word << endl;
            incrWordCount(word);
            word = "";
          }
          else if(text[x] == '\n'){
           // cout << word << endl;
            incrWordCount(word);
            word = "";
           // x++;
          }
          else {
            word += text[x];
          }
          x++;
        } 
       // cout<< word << endl;  
        incrWordCount(word);                                                             
        
}
