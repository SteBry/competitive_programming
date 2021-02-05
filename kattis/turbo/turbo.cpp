#include <bits/stdc++.h>

//#define REP(var, k) for (int var = 0; var < (int) k; ++var)
using namespace std;

class FenwickTree
{
private:
    int *tree;
    int MaxIdx;

public:
    FenwickTree(int n);
    FenwickTree(int arr[], int n);
    ~FenwickTree();

    int readCu(int idx);
    void update(int idx, int val);
};

FenwickTree::FenwickTree(int n)
{
    tree = new int[n + 1];
    MaxIdx = n + 1;

    for (int i = 1; i <= n; i++)
        tree[i] = 0;
}

FenwickTree::FenwickTree(int arr[], int n)
{
    tree = new int[n + 1];
    MaxIdx = n;

    for (int i = 1; i <= n; i++)
        tree[i] = 0;

    for (int i = 0; i < n; i++)
        update(i, arr[i]);
}

FenwickTree::~FenwickTree()
{
    delete[] tree;
}

int FenwickTree::readCu(int idx)
{
    idx += 1;
    int sum = 0;
    while (idx > 0)
    {
        sum += tree[idx];
        idx -= (idx & -idx);
    }
    return sum;
}

void FenwickTree::update(int idx, int val)
{
    idx += 1;
    while (idx <= MaxIdx)
    {
        tree[idx] += val;
        idx += (idx & -idx);
    }
}
//using vi=vector<int>;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int length{};
    cin >> length;

    // Numbers in order
    int numbers[100001];

    // The index of the number [n]
    int indexes[100001];

    //Values used to initialize the fenwick tree
    int fen[100001];

    for (int i = 0; i < length; i++)
    {

        cin >> numbers[i];
        indexes[numbers[i]] = i;
        fen[i] = 1;
    }
    FenwickTree fw_tree{fen, length};

    // Calculate mount of swaps needed
    for (int i = 1; i <= length; i++)
    {
        // The number we want to shift
        int num = i % 2 == 1 ? (i + 1) / 2 : length - (int)((i - 1) / 2);

        // The index of the number we want to shift
        int index = indexes[num];

        // The goal index we want to shift the number to

        fw_tree.update(index, -1);
        int res = i % 2 == 1 ? fw_tree.readCu(index) : fw_tree.readCu(length - 1) - fw_tree.readCu(index);

        cout << res << endl;
    }

    return 0;
}
