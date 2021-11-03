
bool cmp(const pair<string, long> &p1, const pair<string, long> &p2)
{
    if(p1.second!=p2.second)
        return p1.second < p2.second;
    return p1.first < p2.first;
}

// Usage - in sorting as comparator function
sort(vect.begin(), vect.end(), cmp);