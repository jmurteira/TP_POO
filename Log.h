#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Log
{
    vector<string> Logs;
public:
    Log();
    void addLog(string log);
    vector<string> getLogs();
};