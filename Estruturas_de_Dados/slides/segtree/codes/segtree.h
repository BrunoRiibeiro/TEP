#ifndef SEGMENT_TREE_H
#define SEGMENT_TREE_H

#include <vector>
#include <algorithm>

template<typename T>
class SegmentTree
{
    int N;
    std::vector<T> ns;

public:
    SegmentTree(const std::vector<T>& xs) : N(xs.size()), ns(2*N, -1)
    {
        std::copy(xs.begin(), xs.end(), ns.begin() + N);

        for (int i = N - 1; i > 0; --i)
            ns[i] = ns[2*i] + ns[2*i + 1];
    }

    T RSQ(int i, int j)
    {
        // As folhas estão na segunda metade de ns
        int a = i + N, b = j + N;
        T s = 0;

        while (a <= b)
        {
            if (a & 1)                  
                s += ns[a++];

            if (not (b & 1))
                s += ns[b--];

            a /= 2;
            b /= 2;
        }

        return s;
    }

/*    void add(int i, T v)                          // Adds v to position i
    {
        int a = i + n;

        tree[a] += v;                               // Update the leaf

        while (a >>= 1)
            tree[a] = tree[2*a] + tree[2*a + 1];    // Update its parents
    }
*/
};

#endif
