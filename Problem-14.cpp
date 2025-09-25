#include <vector>
#include <set>
#include <unordered_map>
using namespace std;

// Custom hash for pair<int,int>
struct pair_hash
{
    size_t operator()(const pair<int, int> &p) const
    {
        return hash<long long>()(((long long)p.first << 32) | p.second);
    }
};

class MovieRentingSystem
{
private:
    unordered_map<int, set<pair<int, int>>> available;
    set<tuple<int, int, int>> rented;
    unordered_map<pair<int, int>, int, pair_hash> priceMap;

public:
    MovieRentingSystem(int n, vector<vector<int>> &entries)
    {
        for (auto &e : entries)
        {
            int shop = e[0], movie = e[1], price = e[2];
            available[movie].insert({price, shop});
            priceMap[{shop, movie}] = price; // Works now
        }
    }

    vector<int> search(int movie)
    {
        vector<int> res;
        if (available.count(movie))
        {
            auto &s = available[movie];
            for (auto it = s.begin(); it != s.end() && res.size() < 5; ++it)
                res.push_back(it->second);
        }
        return res;
    }

    void rent(int shop, int movie)
    {
        int price = priceMap[{shop, movie}];
        available[movie].erase({price, shop});
        rented.insert({price, shop, movie});
    }

    void drop(int shop, int movie)
    {
        int price = priceMap[{shop, movie}];
        rented.erase({price, shop, movie});
        available[movie].insert({price, shop});
    }

    vector<vector<int>> report()
    {
        vector<vector<int>> res;
        for (auto it = rented.begin(); it != rented.end() && res.size() < 5; ++it)
        {
            int shop = get<1>(*it), movie = get<2>(*it);
            res.push_back({shop, movie});
        }
        return res;
    }
};
