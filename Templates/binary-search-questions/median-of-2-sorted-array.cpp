float findMedianSortedArrays(self, nums1, List[int], nums2, List[int])
{
    A = nums1;
    B = nums2;
    total = len(nums1) + len(nums2);
    half = total / 2;

    if (B.length() < A.length())
    {
        swap(A, B);
    }

    // log(min(n, m))
    l = 0;
    r = A.length() - 1;
    while (true)
    {
        i = (l + r) / 2;  // A
        j = half - i - 2; // B

        Aleft = (i >= 0) ? A[i] : INT_MIN;
        Aright = ((i + 1) < len(A)) ? A[i + 1] : INT_MAX;
        Bleft = (j >= 0) ? B[j] : INT_MIN;
        Bright = ((j + 1) < len(B)) ? B[j + 1] : INT_MAX;

        // partition is correct
        if ((Aleft <= Bright) && (Bleft <= Aright))
        {
            // odd
            if (total % 2)
                return min(Aright, Bright);
            // even
            return (max(Aleft, Bleft) + min(Aright, Bright)) / 2;
        }
        else if (Aleft > Bright)
            r = i - 1;
        else
            l = i + 1;
    }
}
