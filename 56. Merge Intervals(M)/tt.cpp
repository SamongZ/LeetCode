/*
Given a collection of intervals, merge all overlapping intervals.

For example,
Given [1,3],[2,6],[8,10],[15,18],
return [1,6],[8,10],[15,18].
*/

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval> result;
        int total = intervals.size();
        if (total == 0)
            return result;
        if (total == 1)
            return intervals;
        sort(intervals.begin(), intervals.end(), isSmaller);
        Interval pre = intervals[0];
        for (int i = 1; i < total; ++i) {
            if (intervals[i].start <= pre.end) {
                if (intervals[i].end <= pre.end)
                    pre = Interval(pre.start, pre.end);
                else
                    pre = Interval(pre.start, intervals[i].end);
            }
            else {
                result.push_back(pre);
                pre = intervals[i];
            }
        }
        result.push_back(pre);
        return result;
    }
    static bool isSmaller(Interval a, Interval b) {
        return a.start < b.start;
    }
};
