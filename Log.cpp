#include "Log.h"

Log::Log() {}

void Log::addLog(string log)
{
    Logs.push_back(log);
}

vector<string> Log::getLogs() { return Log::Logs; }