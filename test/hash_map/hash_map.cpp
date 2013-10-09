#include <cstring>
#include <ext/hash_map>

using namespace __gnu_cxx;

struct compare_str
{
    bool operator()(const char* p1, const char*p2) const
    {
        return strcmp(p1, p2) == 0;
    }
};

int main(int argc, char* argv[])
{
    hash_map<const char*, int, hash<const char*>, compare_str> StrIntMap;
    StrIntMap["a"] = 111;
}
