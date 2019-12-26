/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

 /*
  * File:   Log.h
  * Author: Alex Reis
  *
  * Created on 21 de novembro de 2019, 21:43
  */

#ifndef LOG_H
#define LOG_H

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

#endif /* LOG_H */

