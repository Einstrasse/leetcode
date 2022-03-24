class Logger {
private:
    map<string, int> lastLogged;
public:
    Logger() {
        lastLogged.clear();
    }
    
    bool shouldPrintMessage(int timestamp, string message) {
        if (lastLogged.find(message) == lastLogged.end()) {
            //Not logged yet
            lastLogged[message] = timestamp;
            return true;
        } else {
            int lastTime = lastLogged[message];
            if (lastTime + 10 <= timestamp) {
                lastLogged[message] = timestamp;
                return true;
            } else {
                return false;
            }
        }
    }
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger* obj = new Logger();
 * bool param_1 = obj->shouldPrintMessage(timestamp,message);
 */