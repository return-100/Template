void insert(char ch)
{
    if (!trie[nxt][ch - 97])
        trie[nxt][ch - 97] = ++idx;

    nxt = trie[nxt][ch - 97];
}

bool get(char ch)
{
    if (trie[nxt][ch - 97])
    {
        nxt = trie[nxt][ch - 97];
        return true;
    }

    return false;
}
