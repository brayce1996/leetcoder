class Transaction {
public:
    string name;
    int time;
    int amount;
    string city;
    bool isInvalid;
    string originStr;
    
    Transaction(string transString) {
        this->originStr = transString;
        vector<string> values;
        string delimiter = ",";
        int pos;
        
        while ((pos = transString.find(delimiter)) != string::npos) {
            values.push_back(transString.substr(0, pos));
            transString.erase(0, pos + delimiter.length());
        }
        this->name = values[0];
        this->time = stoi(values[1]);
        this->amount = stoi(values[2]);
        this->city = transString;
        this->isInvalid = false;
    }
};

class Solution {
public:
    vector<string> invalidTransactions(vector<string>& transactions) {
        unordered_map<string, vector<Transaction*>*> querySys;
        vector<string> invalidTrans;
        
        for (int i = 0; i < transactions.size(); i++) {
            Transaction* newTrans = new Transaction(transactions[i]);
            
            if (newTrans->amount > 1000) {
                newTrans->isInvalid = true;
            }
            if (querySys.find(newTrans->name) == querySys.end()) { // not exist any history
                vector<Transaction*>* history = new vector<Transaction*>({newTrans});
                querySys[newTrans->name] = history;
            } else {
                vector<Transaction*>* history = querySys[newTrans->name];
                
                // check all record in history to find out invalid trans
                // worst case: O(n)
                for (int i = 0; i < history->size(); i++) {
                    Transaction* hisTrans = history->at(i);
                    if (hisTrans->city != newTrans->city && abs(hisTrans->time - newTrans->time) <= 60) {
                        newTrans->isInvalid = true;
                        if (hisTrans->isInvalid == false) {
                            hisTrans->isInvalid = true;
                            invalidTrans.push_back(hisTrans->originStr);
                        }
                    }
                }
                history->push_back(newTrans);
                //querySys[newTrans.name] = history;
            }
            

            if (newTrans->isInvalid) {
                invalidTrans.push_back(newTrans->originStr);
            }
        }
        return invalidTrans;
    }
    
    void printHistory(vector<Transaction> history) {
        for (int i = 0; i < history.size(); i++) {
            cout << "[" << i << "] " << history[i].originStr << endl;
        }
    }
};
