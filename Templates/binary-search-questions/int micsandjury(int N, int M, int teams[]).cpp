
// *********************************** //

int micsandjury(int N, int M, int teams[])
{
    int l = 1, r = 1e9, mid, i, groups, ans;

    while (l <= r)
    {
        mid = (l + r) / 2;
        groups = 0;
        i = 0;

        for (i = 0; i < M; i++)
        {
            if (teams[i] % mid == 0)
                groups += teams[i] / mid;
            else
                groups += teams[i] / mid + 1;
        }
        
        
        if (groups > N)
            l = mid + 1;
        else
        {
            ans = mid;
            r = mid - 1;
        }
    }

    return ans;
}

