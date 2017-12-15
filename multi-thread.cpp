#include <iostream>
#include <thread>
#include <chrono>
#include <vector>
#include <future>

void task1() {

  //occupy the cpu for certain time (at least 5 secs but depends on the grant from OS
  auto start = std::chrono::high_resolution_clock::now(); //print time stamp;
  std::this_thread::sleep_for (std::chrono::seconds(5))
  auto end = std::chrono::high_resolution_clock::now();
  
  //std::this_thread::get_id return id of the thread (this_thread is the library)
  std::cout << "[" << std::this_thread::get_id() << "]" << "Hello!" << std::endl;
  
  std::chrono::duration<double, std::milli> duration = end - start;
  std::cout << "   The thread was busy for [" << duration.count() << "]" std::endl;
}

std::mutex g_mutVal; //mutual exclusive,an object that is managed by the OS, to guard no more than one thread access the variable, act like a lock to guard
long long g_val = 0;

void task2() {
    for (int i = 0; i < 100; ++i) {
       std::this_thread::sleep_for (std::chrono::second(0));   
       g_mutVal.lock(); //dead-lock happenes when we forgot to unlock, everything free indefinitely 
       g_val = g_val + 1;
       g_mutVal.unlock();
    }
}

void task3(std::promise<long long>& p, std::future<std::string> f) {
    long long val = 101;
    std::this_thread::sleep_for(std::chrono::seconds(2));
    
    std::cout << "[" << std::this_thread::get_id() << "] sending "
              << "[" << val << "] to parent thread.";
    p.set_value(val) ;
    
     std::cout << "[" << std::this_thread::get_id() << "] Got [" << f.get() 
                << "] from child thread." << std::endl;
    
}

//stack belong to a thread, it does not share between threads
//heap is share between all thread of application
//global area??

//every promise has a future, promise to dit it now, future is do sth in the future
int main() {

    std::cout << "[" << std::this_thread::get_id() << "]" << "Main thread!" << std::endl;
    {
      std::promise<long long> prom; 
      std::promise<std::string> prom2;
      std::future <std::string> f = prom2.get_future().
      std::thread aThread(task3, std::ref(prom));
      
      //get_future().get() will wait until it get a value that was promise otherwise it would stuck forever
      std::cout << "[" << std::this_thread::get_id() << "] Got [" << prom.get_future().get() 
                << "] from child thread." << std::endl;
                
      prom2.set_value("Got it");
      aThread.join();
    }
    std::thread aThread (task1); //pointer to function
    
    athread.join(); //join means wait for other thread to finish, blocking the program until other threadsfinish
                    //aThread would be finishes at this line
                    
    std::vector <std::thread> arrThreads;
    for (int i = 0; i < 10; i++)
      arrThreads.push_back(std::thread(task2));
      
     for (auto& thread : arrThreads)
      thread.join();
      
     std::cout << g_val << std::endl; 
    return 0;
    
}
