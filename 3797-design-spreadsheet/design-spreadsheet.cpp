class Spreadsheet {
public:
    vector<vector<int>> v;
    Spreadsheet(int rows) { v.resize(rows, vector<int>(26, 0)); }

    void setCell(string cell, int value) {
        char column = cell[0];
        string row = "";
        for (int i = 1; i < cell.size(); i++) {
            if (isdigit(cell[i])) {
                row += cell[i];
            }
        }
        int rr = stoi(row)-1;
        int cc = column - 'A';
        v[rr][cc] = value;
    }

    void resetCell(string cell) {
        char column = cell[0];
        string row = "";
        for (int i = 1; i < cell.size(); i++) {
            if (isdigit(cell[i])) {
                row += cell[i];
            }
        }
        int rr = stoi(row)-1;
        int cc = column - 'A';
        v[rr][cc] = 0;
    }

    int solve(string s) {
        if (isdigit(s[0])) {
            return stoi(s);
        } else {
            char column = s[0];
            string row = "";
            for (int i = 1; i < s.size(); i++) {
                if (isdigit(s[i])) {
                    row += s[i];
                }
            }
            int rr = stoi(row)-1;
            int cc = column - 'A';
            return v[rr][cc];
        }
    }

    int getValue(string formula) {

        string s = formula.substr(1);

        string left;
        string right;
        int plusIndex = -1;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '+') {
                plusIndex = i;
                break;
            }
            left += s[i];
        }

        for (int i = plusIndex+1; i < s.size(); i++) {
            right += s[i];
        }

        return solve(left) + solve(right);
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */