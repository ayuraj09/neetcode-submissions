class Solution {
public:
   string multiply(string num1, string num2) {
    if (num1 == "0" || num2 == "0")
        return "0";

    int n = num1.length();
    int m = num2.length();

    vector<int> ans(n + m, 0);

    for (int i = n - 1; i >= 0; i--) {
        for (int j = m - 1; j >= 0; j--) {

            int mul = (num1[i] - '0') * (num2[j] - '0');

            int pos1 = i + j;
            int pos2 = i + j + 1;

            int sum = mul + ans[pos2];

            ans[pos2] = sum % 10;
            ans[pos1] += sum / 10;

            // Carry from pos1
            if (ans[pos1] >= 10) {
                ans[pos1 - 1] += ans[pos1] / 10;
                ans[pos1] %= 10;
            }
        }
    }

    string result = "";

    int i = 0;
    while (i < ans.size() && ans[i] == 0)
        i++;

    while (i < ans.size()) {
        result += char(ans[i] + '0');
        i++;
    }

    return result;

    }
};

