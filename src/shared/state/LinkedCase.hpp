#include <state.hpp>
#include "vector"
#include <iostream>
#include <algorithm>
#include <list>
#include <sstream>
#include <unordered_map>

using namespace std;
using namespace state;



vector<vector<int>> Linked_Cases(vector<vector<int>> list_case_possibilities,vector<int> case_to_test);

vector<vector<int>> Linked_To_Ant(vector<vector<int>> list_case_possibilities,vector<int> ant_coord);