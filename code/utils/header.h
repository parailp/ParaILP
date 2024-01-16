#pragma once

#include <cassert>
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <limits>
#include <unordered_set>
#include <random>
#include <algorithm>
#include <cmath>
#include <sstream>
#include <fstream>
#include <sys/time.h>
#include <stdlib.h>
#include <boost/thread.hpp>
#include <boost/thread/thread.hpp>
#include <atomic>
using namespace std;
using Integer = __int128_t; // for coefficient and variable value
const Integer MaxValue = std::numeric_limits<Integer>::max();
long long const ZoomTimes = 1000000000000000;
int const Power = 15;
const Integer DefaultUpperBound = 1;
const Integer DefaultLowerBound = 0;
const Integer InfiniteUpperBound = 1000000;
const Integer InfiniteLowerBound = -1000000;
extern string itos(__int128_t v);
enum class VarType
{
    Binary,
    Integer,
    Fixed
};
