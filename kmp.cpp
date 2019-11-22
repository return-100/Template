void failureFunction()
{
    for (int i = 1, j = 0; i < sz; ++i)
    {
        while (j > 0 && str[i] != str[j])
            j = lcp[j - 1];
 
        if (str[i] == str[j])
            lcp[i] = j + 1, ++j;
    }
}
