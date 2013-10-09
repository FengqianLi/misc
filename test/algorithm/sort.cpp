#include <algorithm>
#include <utility>
#include <vector>
#include <cstdint>

typedef uint64_t UInt64;

using std::vector;
using std::pair;

vector < pair < UInt64, UInt64 > >loc_meta;

static bool CompareUInt64Pair(pair <UInt64, UInt64> d1, pair <UInt64, UInt64> d2)
{
	if (d1.first < d2.first)
		return true;
	else if (d1.first > d2.first)
		return false;
	else
		return d1.second < d2.second;
}

void sort_locations()
{
	std::sort(loc_meta.begin(), loc_meta.end(), CompareUInt64Pair);
}
