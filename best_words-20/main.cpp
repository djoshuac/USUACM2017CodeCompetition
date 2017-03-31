#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>

using namespace std;

int main() {

    unordered_map<string,vector<int>> words;

    int numSongs, numWords;
    string word;
    cin >> numSongs;

    for(int i = 0; i < numSongs; ++i){
        cin >> numWords;
        for(int j = 0; j < numWords; ++j){
            cin >> word;
            if(words[word].size() <= i){
                for(int k = words[word].size(); k <= i; ++k){
                    words[word].push_back(0);
                }
            }
            words[word][i] += 1;
        }
    }
    for(int i = 0; i < numSongs; ++i){
        string bestWord = "";
        int bestWordCount = 0;
        bool changeWord;
        for(auto&& x: words){
            if(x.second[i] >= bestWordCount){
                changeWord = true;
                for(int j = 0; j < x.second.size(); ++j){
                    if(j != i && x.second[j] > 0){
                        changeWord = false;
                        break;
                    }
                }
                if(changeWord){
                    if(x.second[i] == bestWordCount) {
                        if (x.first.size() > bestWord.size()) {
                            bestWord = x.first;
                            bestWordCount = x.second[i];
                        } else if (x.first.size() == bestWord.size()) {
                            for (int k = 0; k < bestWord.size(); ++k) {
                                if (x.first[k] < bestWord[k]) break;
                                else if (x.first[k] == bestWord[k]) continue;
                                else {
                                    bestWord = x.first;
                                    bestWordCount = x.second[i];
                                    break;
                                }
                            }
                        }
                    }
                    else{
                        bestWord = x.first;
                        bestWordCount = x.second[i];
                    }
                }
            }
        }
        if(bestWord == ""){
            cout << "Track " << i << " has no unique words" << endl;
        }
        else {
            cout << "Track " << i << "'s best word is " << bestWord << endl;
        }
    }

    return 0;
}