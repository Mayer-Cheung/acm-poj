#include <cstring>  
#include <string>  
#include <iostream>  
using namespace std;  
  
typedef long long LL;  
struct DimensionError{};  
struct Result{  
    //row, column and calculation already done to get the result matrix  
    LL row, col, cal;  
    Result(){}  
    Result(LL r, LL c, LL s) : row(r), col(c), cal(s){}  
    Result& operator *= (const Result& other){  
        if(col != other.row) throw DimensionError();  
        *this = Result(row, other.col, cal + other.cal + row * col * other.col);  
        return *this;  
    }  
};  
  
int matrix[26][2];  
  
string::size_type findMatch(const string& s, string::size_type left)  
{  
    int cnt = 0;  
    for(; true; ++left){  
        if(s[left] == '(') ++cnt;  
        else if(s[left] == ')' && --cnt == 0) break;  
    }  
    return left;  
}  
Result work(const string& s)  
{  
    string::size_type left = s.find('(');  
    if(left == string::npos){//"A" or "A..."  
        Result res(matrix[s[0] - 'A'][0], matrix[s[0] - 'A'][1], 0);  
        for(int i = 1; i < s.size(); ++i){  
            res *= Result(matrix[s[i] - 'A'][0], matrix[s[i] - 'A'][1], 0);  
        }  
        return res;  
    }  
    //find left's matcher  
    Result res;  
    string::size_type right = findMatch(s, left);  
    if(left != 0){  
        res = work(s.substr(0, left));  
        res *= work(s.substr(left + 1, right - left - 1));  
    }  
    else res = work(s.substr(1, right - 1));  
    if(right + 1 != s.size()) res *= work(s.substr(right + 1));  
    return res;  
}  
  
int main()  
{  
    int n, r, c, i;  
    string s;  
  
    memset(matrix, -1, sizeof(matrix));  
    cin >> n;  
    for(i = 0; i < n; ++i){  
        cin >> s >> r >> c;  
        matrix[s[0] - 'A'][0] = r;  
        matrix[s[0] - 'A'][1] = c;  
    }  
    while(cin >> s){  
        //check if s contains char that does not appear in input  
        for(i = 0; i < s.size(); ++i){  
            if(matrix[s[i] - 'A'][0] < 0 || matrix[s[i] - 'A'][1] < 0) break;  
        }  
        if(i != s.size()){  
            cout << "error\n";  
            continue;  
        }  
        //figure out total multiplications  
        try{  
            cout << work(s).cal << "\n";  
        }catch(DimensionError e){  
            cout << "error\n";  
        }  
    }  
    return 0;  
} 