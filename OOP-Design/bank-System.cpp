#include <vector>
using namespace std;

/*
    Problem Type:
    - Object Oriented Design
    - Simulation
    - State Management

    Concept Used:
    - Class Design
    - Index Validation
    - Boundary Checking
    - Long Long for handling large money values
*/

class Bank {
private:
    vector<long long> balance;  // Stores balance of each account
    int n;                      // Total number of accounts

public:
    // Constructor
    // Initializes bank with given account balances
    Bank(vector<long long>& balance) {
        this->balance = balance;
        n = balance.size();
    }

    /*
        transfer:
        Transfers money from account1 to account2
        Conditions:
        - Accounts must exist (1-based indexing)
        - account1 must have sufficient balance
    */
    bool transfer(int account1, int account2, long long money) {
        // Check invalid account numbers
        if (account1 <= 0 || account2 <= 0 || account1 > n || account2 > n)
            return false;

        int i = account1 - 1;
        int j = account2 - 1;

        // Check sufficient balance
        if (balance[i] < money)
            return false;

        balance[i] -= money;
        balance[j] += money;

        return true;
    }

    /*
        deposit:
        Adds money to the given account
        Conditions:
        - Account must exist
    */
    bool deposit(int account, long long money) {
        if (account <= 0 || account > n)
            return false;

        balance[account - 1] += money;
        return true;
    }

    /*
        withdraw:
        Deducts money from the given account
        Conditions:
        - Account must exist
        - Must have sufficient balance
    */
    bool withdraw(int account, long long money) {
        if (account <= 0 || account > n)
            return false;

        int x = account - 1;

        if (balance[x] < money)
            return false;

        balance[x] -= money;
        return true;
    }
};
