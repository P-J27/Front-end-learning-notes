/*
 * @Author: PJ
 * @Date: 2021-10-24 16:19:30
 * @Description: 
 * @Github: https://github.com/P-J27/vue-music
 * @Gitee: https://gitee.com/p_pj/vue-music
 */
#include <iostream>
#include <map>
using namespace std;
int main()
{
    int a[5];
    string aa[5][1005];
    for (int i = 0; i < 3; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < a[i]; j++)
        {
            getline(cin, aa[i][j]);
        }
    }
    int m;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        string s;
        getline(cin, s);
        

        /* code */
    }
}