/*******************************************************************
 * Steven Ortiz 
 * ECGR 3090 Data Structure
 * Assignment 10- Anagrams 
 * the assignment was completed with unordered_maps 
 *
 * 
 * ******************************************************************/


#include <iostream>
#include <unordered_map> // unordered_map hash table
#include <vector>
#include <algorithm>  // sort

using namespace std;
vector<vector<string>> findAnagrams(const vector<string>& dict);

int main() 
{
 vector<string> word_list = {"debitcard", "elvis", "silent", "badcredit", "lives", "freedom",    "listen", "levis"};
  
   vector<vector<string>> result = findAnagrams(word_list);
   for (auto anagrams: result) {
      for (auto words: anagrams)
         cout << words << " ";
         cout << endl;
    }
   return 0;
}
/************************************************************
 * function returns a vector with anagrams that are inside the parameter 
 * the hash table key_type is the sorted characters of each entry and the mapped_type
 * is the word at that specific index  
 * ***********************************************************/ 
vector<vector<string>> findAnagrams(const vector<string>& dict)
{
	
//a vector of type vector<string> created to hold anagrams 
vector<vector<string>> Anagram_result; 

// the hash table with string key_type and vector<int> as mapped_type
// the vector<int> will hold the indexs of the parameter dict 
unordered_map <string,vector<string>> T; 
int word_list_num = dict.size();

// if findAnagrams parameter entry less than 2 
if(dict.size() < 2) {
	cout << "No anagrams possible" << endl; 
	return Anagram_result;}
else{
//this for-loop will sort each entry by characters and place into a hash table
// and each entry will hold the word at the dict[index]
for(int index=0; index < word_list_num; index++)
{
	string Copied_String = dict[index];
	sort(Copied_String.begin(),Copied_String.end());
	vector<string> dict_string_vector; 
	
	//hash each entry with string as key and word from dict as mapped_type
	T.emplace(Copied_String,dict_string_vector);
	// will add the word to matched key 
	T[Copied_String].push_back(dict[index]); 
}
}
// will only add the words from a key that has a mapped_type vector<string> size greater than 2 
for(auto element : T) {
	if(element.second.size() >= 2)
		Anagram_result.push_back(element.second);
	}
	 
return Anagram_result; 
}
