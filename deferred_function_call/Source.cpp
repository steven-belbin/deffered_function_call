#include <functional>
#include <deque>
#include <iostream>

typedef std::function<void()> func_t;
typedef std::deque<func_t> func_queue_t;

void foo()
{
   std::cout << "foo()" << std::endl;
}

void bar(int value)
{
   std::cout << "bar(" << value << ")" << std::endl;
}

int main(int, char*[])
{
   func_queue_t queue;

   queue.push_back(std::bind(&foo));
   queue.push_back(std::bind(&bar, 10));

   for (const auto& func : queue)
   {
      func();
   }

   return 0;
}