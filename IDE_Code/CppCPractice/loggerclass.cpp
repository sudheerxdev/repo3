#include <iostream>
#include <string>
using namespace std;

class Logger {
private:
    static Logger* instance;
    Logger() {}
public:
    static Logger* getInstance() {
        if(!instance)
            instance = new Logger();
        return instance;
    }
    void log(const string& msg) {
        cout << "Log: " << msg << endl;
    }
};

Logger* Logger::instance = nullptr;

int main() {
    Logger* logger = Logger::getInstance();
    logger->log("Starting application.");
    logger->log("Application ended.");
    return 0;
}
