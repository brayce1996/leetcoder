class PassRecord {
public:
    int totalTime = 0;
    int totalPass = 0;

    PassRecord() {}

    void addPass(int time) {
        totalTime += time;
        totalPass++;
    }

    double getAverageTime() {
        return (double)totalTime / totalPass;
    }
};

class CheckInRecord {
public:
    int time;
    string station;

    CheckInRecord(int time, string station) {
        this->time = time;
        this->station = station;
    }
};

class UndergroundSystem {
public:
    unordered_map<string, PassRecord*> passRecordMap;
    unordered_map<int, CheckInRecord*> checkInMap;

    UndergroundSystem() {

    }

    void checkIn(int id, string stationName, int t) {
        checkInMap[id] = new CheckInRecord(t, stationName);
    }

    void checkOut(int id, string stationName, int t) {
        string inStation = checkInMap[id]->station;
        int inTime = checkInMap[id]->time;
        string hashcode = hash(inStation, stationName);
        if (passRecordMap.find(hashcode) == passRecordMap.end()) {
            passRecordMap[hashcode] = new PassRecord();
        }
        passRecordMap[hashcode]->addPass(t - inTime);
    }

    double getAverageTime(string startStation, string endStation) {
        return passRecordMap[hash(startStation, endStation)]->getAverageTime();
    }

    string hash(string startStation, string endStation) {
        return startStation + "->" + endStation;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */
