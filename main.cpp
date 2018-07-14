#include <iostream>
#include "globalloger.h"

void foo()
{
START_FUNCTION();

FINISH_FUNCTION();
}

void bar()
{
  START_FUNCTION();
int i =0;
SAVE_STATE_VAR(i);
  FINISH_FUNCTION();

}

void emfoo()
{
  START_FUNCTION();
   foo();
  FINISH_FUNCTION();

}

void embar()
{
  START_FUNCTION();
  bar();
  FINISH_FUNCTION();

}
int main()
{

  std::cout << double(4D12.4);

  return 0;
}
