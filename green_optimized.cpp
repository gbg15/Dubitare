#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <sstream>
#include <map>
#include <vector>

using namespace std;

typedef map<string, short> wordMap;

void mapSort(map<string, short>&someMap, vector<pair<string, short> >&someVector);

int main(){
    short T, L, a, b, freq; //Test, Lines, lower bound, upper bound, and frequency
    wordMap someMap;
    string word, str;

    ifstream fin;
    fin.open("test.in");

    fin >> T;

    for(short i = 1; i <= T; ++i){
        cout << "Testcase #" << i << ":" << endl;
        fin >> L >> a >> b;
        freq = 0;
        getline(fin, str);
        
        while(freq < L){
            getline(fin, str);
            stringstream ss(str);

            while(ss >> word){
                someMap[word]++;
            }

            ++freq;
        }
        
        vector<pair<string, short> > someVector;
        mapSort(someMap, someVector);
        someMap.clear();

        for(unsigned short j = someVector.size()-a; j > someVector.size()-b - 1; --j){
            cout << someVector[j].first << ":" << someVector[j].second << endl;
        }

        cout << endl;

    }

    fin.close();

    return 0;
}

bool comp(const pair<string,short> &x, const pair<string,short> &y){
    if(x.second == y.second) return (x.first > y.first);
    else return(x.second < y.second);
}

void mapSort(map<string, short> &someMap, vector<pair<string, short> > &someVector)
{
    for(map<string, short> :: iterator itr = someMap.begin(); itr != someMap.end(); itr++)
        someVector.push_back(make_pair(itr->first, itr->second));

    sort(someVector.begin(), someVector.end(), comp);
}