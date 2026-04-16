// 2410. Maximum Matching of Players With Trainers
// You are given a 0-indexed integer array players, where players[i] represents the ability of the ith player. You are also given a 0-indexed integer array trainers, where trainers[j] represents the training capacity of the jth trainer.
// The ith player can match with the jth trainer if the player's ability is less than or equal to the trainer's training capacity. Additionally, the ith player can be matched with at most one trainer, and the jth trainer can be matched with at most one player.
// Return the maximum number of matchings between players and trainers that satisfy these conditions.

#include <iostream>
#include <vector>
#include <queue>
using namespace std;
class Solution
{
public:
    int matchPlayersAndTrainers(vector<int> &players, vector<int> &trainers)
    {
        int p = players.size();
        int t = trainers.size();
        vector<pair<int, int>> pairs;
        sort(players.begin(), players.end());
        sort(trainers.begin(), trainers.end());
        int i = 0, j = 0, count = 0;
        while (i < p && j < t) {
            if (players[i] <= trainers[j]) {
                pairs.push_back(make_pair(players[i], trainers[j]));
                count += 1;
                i++;
                j++;
                continue;
            }
            j++;
        }
        for (auto it : pairs) {
            cout << it.first << " " << it.second << endl;
        }
        return count;
    }
};

int main()
{
    Solution sol;
    vector<int> players = {4, 7, 9, 6, 4, 12, 15, 23};
    vector<int> trainers = {8, 2, 5, 8, 23, 15, 7, 45, 3, 8, 9};
    int res = sol.matchPlayersAndTrainers(players, trainers);
    cout << res << endl;
}