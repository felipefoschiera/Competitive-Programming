#include <iostream>
#include <set>
#include <bitset>
#include <vector>
#include <random>
using namespace std;

const int SIZE = 80000000;

struct Mixer {
    std::minstd_rand rng_;
    Mixer(const string &val) : rng_(std::hash<string>()(val)) {}
    std::size_t operator()() { return rng_() % SIZE; }
};

bitset<SIZE> bits_;

const int NumHashes = 3;

void Add(string key){
    Mixer mixer(key);
    for(int i = 0; i < NumHashes; i++){
        bits_.set(mixer());
    }
}
bool MaybeContains(const string &key){
    Mixer mixer(key);
    for(int i = 0; i < NumHashes; i++){
        if(!bits_[mixer()]) return false;
    } 
    return true;
}
