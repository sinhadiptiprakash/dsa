int i, j, gap = n + m;
    //until the gap is 0 we always compare two gap distanced element and if first is greater then we swap them 
    //obviously until the two pointers are within the array index
    //i.e. if one pointer is at i then the another pointer would be i+gap
    for (gap = nextGap(gap);gap > 0; gap = nextGap(gap)){//this runs in O(long(n+m))
        // comparing elements in the first array.
        // while the second pointer i.e. the pointer at i+gap is within the range of n
        for (i = 0; i + gap < n; i++)
            if (a[i] > a[i + gap])
                swap(a[i], a[i + gap]);
 
        // comparing elements in both arrays.
        // while the second poiner i.e. pointer at i+gap is within the range of n to m but the first pointer is within the range n
        for (j = gap > n ? gap - n : 0;i < n && j < m;i++, j++)
            if (a[i] > b[j])
                swap(a[i],b[j]);
        //while the first pointer is out of n and the second pointer is within m
        if (j < m) {
            // comparing elements in the second array.
            for (j = 0; j + gap < m; j++)
                if (b[j] > b[j + gap])
                    swap(b[j], b[j + gap]);
        }
    }