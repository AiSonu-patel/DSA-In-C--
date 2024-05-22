#include<iostream>
#include <vector>
using namespace std;

// T.C -> O(n*n!)
// S.C -> (n)

void permut(int arr[], vector<vector<int>>&ans, vector<int>&temp, vector<bool>&visit)
{
    if(visit.size()==temp.size())
    {
        ans.push_back(temp);
        return;
    }

    for(int i=0; i<visit.size(); i++)
    {
        if(visit[i]==0)
        {
            visit[i]=1;
            temp.push_back(arr[i]);
            permut(arr, ans, temp, visit);
            visit[i]=0;
            temp.pop_back();
        }
    }
}

int main()
{
    int arr[] = {1,2,3};
    vector<vector<int>> ans;
    vector<int> temp;
    vector<bool> visit(3, 0);

    permut(arr, ans, temp, visit);
    for(int i=0; i<ans.size(); i++)
    {
        for(int j=0; j<ans[i].size(); j++)
        cout<<ans[i][j]<<" ";
        cout<<endl; // {1,2,3}, {1,3,2}, {2,1,3}, {2,3,1}, {3,1,2}, {3,2,1}
    }
}