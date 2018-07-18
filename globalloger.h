#ifndef GLOBALLOGER_H
#define GLOBALLOGER_H

#include <resultprinter.h>
Loger globalLogger;


template <class T>
void printItemState(std::string item_name,T item_value)
{
 globalLogger.printItemState( item_name, item_value);
}

template <class T>
void printItemState(std::string item_name,T* item_value)
{
 int size_arr = sizeof(item_value) / sizeof(*item_value);
 for(int i = 0; i < size_arr; i++)
   {
     globalLogger.printItemState( item_name, item_value[i]);
   }
}
inline void start_function(std::string function_name)
{
 globalLogger.startFunction(function_name);
}

inline void finish_function()
{
 globalLogger.finishFunction();
}
#define SAVE_STATE_VAR(x) printItemState(std::string(#x), x)
#define START_FUNCTION() start_function(std::string(__PRETTY_FUNCTION__));
#define FINISH_FUNCTION() finish_function();
#define SHOW__FUNCTION_TREE() globalLogger.showFunctionsTree();

#endif // GLOBALLOGER_H
