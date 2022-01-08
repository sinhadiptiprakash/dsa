#include <bits/stdc++.h>
using namespace std;
bool isValid(int r, int c, int n, int m)
{
    if (r >= 0 && c >= 0 && r < n && c < m)
        return true;
    return false;
}
vector<int> x = {0, 0, 1, -1};
vector<int> y = {1, -1, 0, 0};
bool exist(vector<vector<char>> &board, const string &word, string temp, int index, int r, int c, int n, int m)
{
    char tmp = board[r][c];
    temp.push_back(tmp);
    if (temp.size() == word.size())
        return true;
    board[r][c] = '0';
    for (int i = 0; i < 4; i++)
    {
        int nr = r + x[i];
        int nc = c + y[i];
        if (isValid(nr, nc, n, m) && index < word.size() && word[index + 1] == board[nr][nc])
        {
            if (exist(board, word, temp, index + 1, nr, nc, n, m))
                return true;
        }
    }
    temp.pop_back();
    board[r][c] = tmp;
    return false;
}
bool exist(vector<vector<char>> &board, string word)
{
    int n = board.size();
    int m = board[0].size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (board[i][j] == word[0])
            {
                if (exist(board, word, "", 0, i, j, n, m))
                    return true;
            }
        }
    }
    return false;
}
vector<string> findWords(vector<vector<char>> &board, vector<string> &words)
{
    int len = words.size();
    vector<string> res;
    for (int i = 0; i < len; i++)
    {
        if (exist(board, words[i]))
        {
            res.push_back(words[i]);
        }
    }
    return res;
}
int main()
{
    int n, m, l;
    cin >> n >> m >> l;

    vector<vector<char>> board(n, vector<char>(m));
    vector<string> words(l);
    for (int i = 0; i < l; i++)
        cin >> words[i];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> board[i][j];

    auto res = findWords(board, words);
    cout << "found words are" << endl;
    for (auto s : res)
        cout << s << endl;
    return 0;
}