#include<string>
#include<iostream>
using namespace std;
class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1 || s.size() <= numRows) return s;
        string res;
        int n = s.size();
        
        int cycleLen = 2 * numRows - 2;
        int diff;
        for (int row = 0; row < numRows; row++) {
            diff = row * 2;
            if (row == numRows - 1) diff = 0; //handles last row
            for (int i = row; i < n;i += cycleLen) {
                res += s[i];
                int j = i + cycleLen - diff;
                if (j < n) {
                    if (diff != 0) res += s[j];
                } else break;
            }
        }
        return res;
    }
};

//3 rows, cycle is 4: 
            //1, 5, 9, 13 //_+4+4+4 //1+c+c
            //2, 4, 6, 8, 10, 12, 14//_+2+2+2+2+2+2+2 //2+(c-2)+2+(c-2)
            //3, 7, 11//_+4+4+4
        //4 rows, cycle is 6
            //1, 7, 13//_+6+6
            //2, 6, 8, 12, 14//_+4+2+4+2 (2+(c-2)+2+(c-2)+2)
            //3, 5, 9, 11//_+2+4+2+4 (3+2+(c-2)+2+)
            //4, 10//_+6
        //5 rows, cycle is 8
            //1, 9//_+8 //1+c
            //2, 8, 10//_+6+2 //2+(c-2)+2
            //3, 7, 11//_4+4 //3+(c-4)+4
            //4, 6, 12, 14//_+2+6+2 //4+(c-6)+6
            //5, 13//_+8
        //n rows, cycle is 2n-2
            //1+c until end
            //2+c-2+2+c-2+c
            //3+c-3+c-3
            //...
            //c-1+
            //c+c
