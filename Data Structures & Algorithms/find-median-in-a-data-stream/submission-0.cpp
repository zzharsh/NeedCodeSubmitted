class MedianFinder {
public:
    multiset<int> left, right;
    int ls = 0, rs = 0;
    int lmax, rmin;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(left.size() == 0 && right.size() == 0)
        {
            left.insert(num);
            ls++;
            auto it = left.end();
            --it;
            lmax = *it;
            return;
        }
        if(num > lmax)
        {
            right.insert(num);
            rs++;
        }
        else
        {
            left.insert(num);
            ls++;
        }
        if(ls < rs)
        {
            auto it = right.begin();
            int minr = *(it);
            left.insert(minr);
            right.erase(it);
            ls++;
            rs--;
        }
        else if(rs < ls - 1)
        {
            auto it = left.end();
            it--;
            int maxl = *(it);
            right.insert(maxl);
            left.erase(it);
            ls--;
            rs++;
        }
        auto it = left.end();
        --it;
        lmax = *it;
        it = right.begin();
        rmin = *it;
    }
    
    double findMedian() {
        if((ls + rs) % 2 != 0)
        {
            return lmax * 1.0;
        }
        else
        {
            return (lmax * 1.0 + rmin) / 2;
        }
    }
};
