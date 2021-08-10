#include <iostream>
#include <string>
#include <stack>


/**
 * 给定两个字符串str1和str2，输出两个字符串的最长公共子序列。如果最长公共子序列为空，则返回"-1"。目前给出的数据，仅仅会存在一个最长的公共子序列
 */

/**
 * 输入："1A2C3D4B56","B1D23A456A"
 * 输出："123456"
 * 
 * 输入："abc","def"
 * 输出："-1"
 * 
 * 输入："abc","abc"
 * 输出："abc"
 */

using namespace std;

class Solution {
public:
    /**
     * longest common subsequence
     * @param s1 string字符串 the string
     * @param s2 string字符串 the string
     * @return string字符串
     */
    string LCS(string s1, string s2) {
        const size_t s1_size = s1.size();
        const size_t s2_size = s2.size();
        if (s1_size <= 0 || s2_size <= 0)
        {
            return "-1";
        }
        /*
        i: s1的下标；
        j: s2的下标；
        c[i][j]: 保存当前公共子串的长度；
        1、当i=j=0时，c[0][0] = 0;
        2、当s1[i]==s2[j]，c[i][j]= c[i-1][j-1]+1;
        3、当s1[i]!=s2[j]，当c[i-1][j]>c[i][j-1]，c[i][j]=c[i-1][j]；否则c[i][j]=c[i][j-1]
        */
        int c[s1_size+1][s2_size+1];
        bzero(c, sizeof(int) * (s1_size+1) * (s2_size+1));
        for (int i = 1; i <= s1_size; i++)
        {
            for (int j = 1; j <= s2_size; j++) {
                if(s1[i-1] == s2[j-1]) {
                    c[i][j] = c[i-1][j-1]+1;
                } else if (c[i-1][j] >= c[i][j-1]){
                    c[i][j] = c[i-1][j];
                } else {
                    c[i][j] = c[i][j-1];
                }
            }
        }

        string result;
        int i = s1_size, j = s2_size;
        while (i >= 1 && j >= 1)
        {
            if (s1[i-1] == s2[j-1]) {
                result.push_back(s1[i-1]);
                i--;
                j--;
            } else if (c[i-1][j] >= c[i][j-1]) {
                i--;
            } else {
                j--;
            }
        }
        reverse(result.begin(), result.end());
        return result.size() <= 0 ? "-1" : result;     
    }
};

int main(int argc, const char* argv[]) {
    Solution s;
    string result = s.LCS("1A2C3D4B56", "B1D23A456A");
    cout<<result<<endl;
    /*
    "JGIHa76X06Mx330MtfiNafgpQfj0sJVop2nrMb7Gx2i3RIA72UIIXWA2NoPjRN1jwMNVawJrsn3obxhKDINaHLMJT4JnxHo43xf7CUjh77Pae1UUi3GIiH4ponfV6HRzbk1pp7ehACa2ephI6kVb46FR0irx4tVmDjpks0VRonMe3keeVJ83Z8N2eUJoIN4WGd0GQWDn1jnM4MsojgFIbXs7Nu3jnFHrWi3fbNiWRIfxUzr23yb4NGrj1XhkJMbj42DXeUAeifpMNHFx6AGu962ATDV3kkJfAjeJj4Xs0oxq4pGxm2xrrZf4MGJfin4boMzhNFrYGf3sRpafUXIOUAkfU7bas2pHkViihorlhwd7njxefBMpnCWR4rqX76GrW27R1HIna09Dhkfirtpn1F6A2Gr4rbc3MFrtzVrfCxntVh3nHra0I4xNaWi7bVphjoIiGWhIzoiAfkMMdzyVfQoHAw4Gr4M6CC4TGar118GhJS6GfR6HIopGDpzxmkS11nC4sXxoeaA77bAzWsJJ9W10Xnae4Vk2zIHUxUVJiGr62J1B45NhHp41A726WqJNaI7UbjRr1GkX0jChibFW6Chn1i3boIBpfVAf4Wa37sX4J9CjWrhG174rXixexFs9JAn3NVWGnWokWnCs1jfRI36xiIWfCXUj7bsbKeJtpxri2AzsskRJhUVzaNNA2iHR6iGHI0er34n6axnbrWis6o4H70VipGy7CH5fTqJakNI3MnuRvqbskBX8kXHpAbVNHN07ooGnrPrUCItRoRH1bco4VUVXrxHIoqM6ahzjGFh1h37ibpoXhX00b3iGaxG6XfVVeAVJoKfFVieI6zWrairpCRNRniVr0HWGKNWFRxTxRRGN1xBNXgrreeaNFWpz7637joijexGRAspXnRnQoU6bab4R7afC3C1k3NxiRX72kjARUGeMRMaR6k0wNxHj2kzHWH0XjtkrxJM0IhU4eaohWF8UCpCGjhXeAUse1piLGFl7x2J3VkVVnMr6UhR9nzUF473TNFXip35j3sR4nNws4hzU7p6IWWIR4Nf2Q3yFRf1RUz2sRhJG1aSxaffQAz7apoxIXJaX0nXa6Ffj3IkV0zxjUTVdkGUx","K8dqDTE5Z5lgtvv9m9Qg8ugmYu9qDwaDgtKl5vylPLyLPLwlKETQ8v5YvTMwBKQKyT3Pl8tuKvmqgwEOQlx5vZLKgT5ABdw7yqPdZPmcuugDqOZwtNYgLcwBgTrEqlhKummLgmZDcHwcmm5LvmTvDLxlQyttK7DPgTucUq5DdlmKiSE8mBt93tOgTQKTGhCPBDudBLmgPtLvYTuydmcqD5EtEQZmwmmBLc5SEd89TyOlDYdwol8lDZl8cucOB9ggldm5QZPuPl58qttLQDP1TELyMtgggdutTuy9wZL8YwZqvw8EtgqqYK5LvK4yYwjBXSODNcDQHmEE8uvdZP9lQutwPcYyvQSwTLD8PcdgKE5DE89ZqdPBycc5wmQgLZT2B8ZE9wBzE58P9EOqYLTw5OUrSlTQPOqOTqtZBvwOv5yDwSddQY9BTqT8DY59BYQy9gPEl9gLZtEdvLuLByOB9S79DgrBtvZQqmyBr98y9tqc5cTcvP3mt9VE5mtEZuBaivBywYSO59YZEBgyISBYqBl8TZd8vSOETQZy8Qwl8g9BTvKBvS8LQSvYLqD9ZmYgTSQOdStmlqtTROYuOQDPuEuuS8gm5BlmPuEcZSydCc9tggu8cQmmXOxSTEvmBDKtd59LbqLlTPd9EcSKEwVIy58wgBDlwlQxTBTc5KmB8uZSqdjBLBYtmqlmGQKigTcdOmZKgOB9quvgcOWqBwuZmtw5KPZE9LlvtdluoS1SBRZuKQKlmtlsKgw85KuuOBqdKmYcgD8cQPtZLBvtugY5TrEqkvBTllqy5tEiuTZPvTPw7855L9diqEDyygCtmZ5BODKY8OuZSLEuwETZuLQqvTqODuKSy8qDvuRwqS8v
    */
    return 0;
}