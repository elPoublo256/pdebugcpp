#include "resultprinter.h"


FunctionLogs::FunctionLogs(std::string name)
{
  std::cout << "build FunctionLogs with name as "<< name <<std::endl;
  name_ = name;
  parent_ = NULL;
}

FunctionLogs::FunctionLogs(FunctionLogs* parent, std::string name)
{
  std::cout << "build FunctionLogs with name as "<< name <<
            " emited in "<<parent->name_ <<std::endl;
  parent_ = parent;
  name_ = name;
}

std::string FunctionLogs::fulltreefunctions()
{



  if(parent_ == NULL)
    {
      return name_;
    }
  else
    return parent_->fulltreefunctions() + "->" + name_;

}

void FunctionLogs::printLogs(std::ostream &out)
{
  int sec;
  int nanosec;
  //for(std::pair<time_t, std::string> log : logs)
  //  {
  //    nanosec = log.first % 1000000000;
  //    sec = (int)log.first / 1000000000;
  //    out<< sec <<"s "<<nanosec<<"ns"<<"::  -" << log.second << std::endl;
  //  }
}
void FunctionLogs::printLogsInFile()
{
  //std::ofstream out(fulltreefunctions(), std::ios::app);
  //printLogs(std::cout);
}

void FunctionLogs::addLineLog(std::string logline)
{
 struct timespec t;
  int err = clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &t);
  int key = t.tv_nsec + 1000000000 * t.tv_sec;
  switch (err) {
    case 0:
      logs[key] = logline;
      break;
//    case EFAULT:
//      logline = "error of clock_gettime = EFAULT";
      
//      break;
//    case EINVAL:
//      logline = "error of clock_gettime = EINVAL";
//      break;
    default:
      break;
    }


}
Loger::Loger()
{
  functlist.push_back(new FunctionLogs("int main()"));
}
void Loger::startFunction(std::string name)
{
  functlist.push_back(new  FunctionLogs(*functlist.rbegin(), name));
  functlist.back()->addLineLog("START");
}


void Loger::finishFunction()
{
  functlist.back()->addLineLog("FINISH");
  functlist.back()->printLogsInFile();
  if(*functlist.rbegin() != *functlist.begin()){
functlist.push_back(functlist.back()->parent());}
else
  {
    std::cout << "END OF PROGRAMM";
  }

}


void Loger::showFunctionsTree()
{
//  for(auto f : functlist)
//    {
//      std::cout<< f->fulltreefunctions() << std::endl;
//    }
}
