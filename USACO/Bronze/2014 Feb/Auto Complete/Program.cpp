#include <bits/stdc++.h>
using namespace std;

int W, N;
struct word
{
    int place;
    string content;
} words[1001];

string words2[1001];

bool substr(string prefix, string b)
{
    int n = prefix.length();
    for (int i = 0; i < n; i++)
    {
        if (prefix[i] == b[i])
            continue;
        else
            return false;
    }
    return true;
}

int find(int term, string prefix)
{
    int inPlace;
    inPlace = lower_bound(words2, words2 + W, prefix) - words2;
    if (substr(prefix, words2[inPlace + term - 1]))
        return words[inPlace + term - 1].place;
    else
        return -1;
}

bool cmp(word a, word b)
{
    return a.content < b.content;
}

int main()
{
    ifstream fin;
    fin.open("auto.in");
    ofstream fout("auto.out");
    fin >> W >> N;

    for (int i = 1; i < W + 1; i++)
    {
        words[i].place = i;
        string temp;
        fin >> temp;
        words[i].content = words2[i] = temp;
    }

    sort(words, words + W, cmp);
    sort(words2, words2 + W);

    int term;
    string prefix;
    for (int i = 0; i < N; i++)
    {
        fin >> term >> prefix;
        int ans = find(term, prefix);
        if (i == N - 1)
            fout << ans;
        else
            fout << ans << endl;
    }
    return 0;
}
