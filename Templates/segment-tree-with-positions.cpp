
// by me....

pair<int, int> merge(pair<int, int> a, pair<int, int> b)
{
    if (a.first != b.first)
    {
        return (a.first < b.first ? a : b);
    }
    return (a.second < b.second ? a : b);
}

void constructTree(int input[], pair<int, int> segment[], int low, int high, int pos)
{
    if (low == high)
    {
        segment[pos] = {input[low], low};
        return;
    }
    int mid = (low + high) / 2;
    constructTree(input, segment, low, mid, 2 * pos + 1);
    constructTree(input, segment, mid + 1, high, 2 * pos + 2);
    segment[pos] = merge(segment[2 * pos + 1], segment[2 * pos + 2]);
}

pair<int, int> rangeMinQuery(pair<int, int> segment[], int qlow, int qhigh, int low, int high, int pos)
{
    if (qlow <= low && qhigh >= high) //Total overlap
        return segment[pos];

    if (qlow > high || qhigh < low) //No overlap
        return {INT_MAX, INT_MAX};

    int mid = (low + high) / 2;
    return merge(rangeMinQuery(segment, qlow, qhigh, low, mid, 2 * pos + 1),
                 rangeMinQuery(segment, qlow, qhigh, mid + 1, high, 2 * pos + 2));
}
