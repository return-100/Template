#size of first dimension = max_length_of_a_word * total_number_of_words
#size of second dimension = max_number_of_unique_characters

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
