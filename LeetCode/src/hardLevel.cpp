#include "hardLevel.h"

namespace leetcode {
    /**
     * **********************************************************************************
     *                       @brief Problems of Hard Levels                             *
     * **********************************************************************************
     */
    double hardLevel::findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        /*  Frist way */
        const int m = nums1.size();
        const int n = nums2.size();
        bool isEven = (m + n) % 2 == 0 ? true : false;
        int medianPos = isEven ? (m + n - 1) / 2 : (m + n) / 2;
        double _result = 0;
        vector<int> _res;
        vector<int>::iterator _itrNums1 = nums1.begin();
        vector<int>::iterator _itrNums2 = nums2.begin();

        while (_itrNums1 != nums1.end() && _itrNums2 != nums2.end())
        {
            if (*_itrNums1 < *_itrNums2)
            {
                _res.push_back(*_itrNums1);
                _itrNums1++;
            }
            else
            {
                _res.push_back(*_itrNums2);
                _itrNums2++;
            }
        }

        // pushing the rest of elems in vector1
        while (_itrNums1 != nums1.end())
        {
            _res.push_back(*_itrNums1);
            _itrNums1++;
        }

        // pushing the rest of elems in vector2
        while (_itrNums2 != nums2.end())
        {
            _res.push_back(*_itrNums2);
            _itrNums2++;
        }

        _result = isEven ? (_res[medianPos + 1] + _res[medianPos]) / 2.0 : _res[medianPos] / 1.0;
        return _result;
    }

    bool hardLevel::isMatch(string s, string p) {
        int len_s = s.length();
        int len_p = p.length();

        uint32_t _table[35][35];

        /**
         * Filling all of data to 0
         */
        for (uint32_t idex; idex <= len_p; idex++) {
            for (uint32_t jdex; jdex <= len_s; jdex++) {
                _table[idex][jdex] = 0;
            }
        }

        // for (uint32_t idex; idex < len_s; idex++) {
        //     _table[0][idex] = 0;
        // }

        _table[0][0] = 1;

        for (uint32_t index = 1; index <= len_p; index++) {
            if (p[index - 1] == '*') {
                if (index == 1) {
                    _table[1][0] == 1;
                }
                else if (_table[index - 2][0]) {
                    _table[index][0] = 1;
                }
                else {
                    _table[index][0] = 0;
                }
            }
            else {
                _table[index][0] = 0;
            }
        }

        uint32_t idex;
        uint32_t jdex;
        for (idex = 1; idex <= len_p; idex++) {
            for (jdex = 1; jdex <=  len_s; jdex++) {
                if ((p[idex-1]==s[jdex-1]) || p[idex - 1] == '.') {
                    _table[idex][jdex] = _table[idex - 1][jdex - 1];
                }
                else {
                    if (p[idex - 1] == '*') {
                        if (s[jdex - 1] == p[idex - 2] || p[idex - 2] == '.') {
                            _table[idex][jdex] = (_table[idex - 2][jdex] || _table[idex][jdex - 1]);
                        }
                        else {
                            _table[idex][jdex] = _table[idex - 2][jdex];
                        }
                    }
                    else {
                        _table[idex][jdex] = 0;
                    }
                }
            }
        }

        return _table[idex][jdex];
    }
};