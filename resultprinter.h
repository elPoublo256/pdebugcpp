#ifndef RESULTPRINTER_H
#define RESULTPRINTER_H
#include <string>
#include <fstream>
//#include <chrono>
#include <memory>
#include <iostream>
#include <sys/time.h>
#include <map>
#include <list>
#include <sstream>
/*
struct timespec {
        time_t   tv_sec;
};
*/
class FunctionLogs
{
public:

 FunctionLogs(std::string name);
 FunctionLogs(FunctionLogs* parent, std::string name);


void printLogs(std::ostream& out);
void printLogsInFile();
void addLineLog(std::string logline);
std::string name() {return name_;}
FunctionLogs* parent() {return parent_;}
std::string fulltreefunctions();
private:
  FunctionLogs* parent_;
  std::map<int, std::string> logs;
  std::string name_;


};

class Loger
{
public:
  Loger();
template <class T>
  void printItemState(std::string item_name,T item_value);
  void startFunction(std::string name);
  void finishFunction();
  void showFunctionsTree();
private:
  std::list<FunctionLogs*> functlist;


};


template <class T>
void Loger::printItemState(std::string item_name,T item_value)
{
  std::ostringstream sstream(" ");
  sstream << item_value;
 functlist.back()->addLineLog(item_name + " = "+std::string(sstream.str()));
}


#endif // RESULTPRINTER_H
