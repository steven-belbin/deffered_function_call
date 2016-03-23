#include <functional>
#include <deque>
#include <iostream>

typedef std::function<void(int)> func_t;
typedef std::deque<func_t> func_queue_t;

void foo(int x)
{
   std::cout << "foo(" << x << ")" << std::endl;
}

void bar(int x, int y)
{
   std::cout << "bar(" << x << ", " << y << ")" << std::endl;
}

int main(int, char*[])
{
   using namespace std::placeholders;

   func_queue_t queue;

   queue.push_back(std::bind(&foo, _1));
   queue.push_back(std::bind(&bar, _1, 10));

   for (const auto& func : queue)
   {
      func(5);
   }

   return 0;
}