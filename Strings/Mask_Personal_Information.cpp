// Problem: Mask Personal Information
// Category: String Manipulation / Simulation
//
// Idea:
// - Check whether input is email or phone number
// - Email: keep first and last character of name, mask rest
// - Phone: extract digits and mask all except last 4
//
// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
public:
    string maskPII(string s) {
        // Check if input is an email
        for (char ch : s) {
            if (ch == '@')
                return maskEmail(s);
        }
        return maskPhone(s);
    }

private:
    string maskEmail(string s) {
        int pos = s.find('@');
        string name = s.substr(0, pos);
        string domain = s.substr(pos + 1);

        string res;
        res += tolower(name[0]);
        res += "*****";
        res += tolower(name.back());
        res += '@';

        for (char ch : domain)
            res += tolower(ch);

        return res;
    }

    string maskPhone(string s) {
        string digits;

        // Extract digits
        for (char ch : s) {
            if (isdigit(ch))
                digits += ch;
        }

        string res;
        int n = digits.size();

        if (n > 10) {
            res += '+';
            res += string(n - 10, '*');
            res += '-';
        }

        res += "***-***-";
        res += digits.substr(n - 4);

        return res;
    }
};
