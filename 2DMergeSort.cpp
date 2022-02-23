//https://www.codechef.com/problems/DAA002

#include<vector>
#include <iostream>

using namespace std;

void print(vector<vector<int>> mat, int m, int n)
{
    for (int i = 0;i < m;i++)
    {
        for (int x : mat[i])
        {
            cout << x << " ";
        }
        cout << endl;
    }
}

void mergeRowWise(vector<vector<int>>& v, int startRow, int startCol, int mid, int m, int n)
{
     vector<int> temp;

    for (int i = startRow;i <= m;i++)
    {
        int x = startCol, y = mid + 1;
        while (x <= mid && y <= n)
        {
            if (v[i][x] < v[i][y])
            {
                temp.push_back(v[i][x]);
                x++;
            }
            else
            {
                temp.push_back(v[i][y]);
                y++;
            }
        }

        while (x <= mid)
        {
            temp.push_back(v[i][x]);
            x++;
        }

        while (y <= n)
        {
            temp.push_back(v[i][y]);
            y++;
        }

        int k = 0;
        for (int idx = startCol;idx <= n;idx++)
        {
            v[i][idx] = temp[k++];
        }
        temp.clear();
    }
    
}

void mergeColWise(vector<vector<int>>& v, int startRow, int startCol, int mid, int m, int n)
{
    vector<int> temp;
   
    for (int i = startCol;i <= n;i++)
    {
        temp.clear();
        int x = startRow, y = mid + 1;
        while (x <= mid && y <= m)
        {
            if (v[x][i] < v[y][i])
            {
                temp.push_back(v[x][i]);
                x++;
            }
            else
            {
                temp.push_back(v[y][i]);
                y++;
            }
        }

        while (x <= mid)
        {
            temp.push_back(v[x][i]);
            x++;
        }

        while (y <= m)
        {
            temp.push_back(v[y][i]);
            y++;
        }

        int k = 0;
        for (int idx = startRow;idx <= m;idx++)
        {
            v[idx][i] = temp[k++];
        }

    }
    

}

void mergeUtil(vector<vector<int>>& v, int startRow, int startCol, int m, int n)
{
    if ((startRow >= m) and (startCol >= n))
    {
         return;
    }

    int midRow = (startRow + m) / 2;
    int midCol = (startCol + n) / 2;


    mergeUtil(v, startRow, startCol, midRow, midCol);
    mergeUtil(v, startRow, midCol + 1, midRow, n);
    mergeUtil(v, midRow + 1, startCol, m, midCol);
    mergeUtil(v, midRow + 1, midCol + 1, m, n);

  
    mergeRowWise(v, startRow, startCol, midCol, m, n);
    mergeColWise(v, startRow, startCol, midRow, m, n);

}

void mergeSort(int m, int n, vector<vector<int>> & v) {
  
    mergeUtil(v, 0, 0, m - 1, n - 1);


}



#include <iostream>

int main()
{
    vector<vector<int>> mat{ {18,4,16,8},{23,13,20,11},{28,24,26,25},{1,30,15,19} };

    print(mat, 4, 4);
    mergeSort(4, 4, mat);
    print(mat, 4, 4);

    return 0;

}

