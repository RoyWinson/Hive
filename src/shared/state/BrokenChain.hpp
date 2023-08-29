#include <state.hpp>
#include "vector"
#include <iostream>
#include <algorithm>
#include <list>
#include <sstream>
#include <unordered_map>

using namespace std;
using namespace state;

vector<Insect> List_X_Neighbour(vector<Insect> list_insect_placed, vector<Case> list_case,int X);

vector<Insect> Look_For_Neighbour(vector<Insect> list_insect_placed, vector<Case> list_case,Insect insect_to_start);

bool Test_Broken_Chain(vector<Insect> list_insect_placed, vector<Case> list_case);