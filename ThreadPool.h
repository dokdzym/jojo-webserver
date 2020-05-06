//
// Created by jojo on 2020/5/3.
//

#ifndef JOJO_WEBSERVER_THREADPOOL_H
#define JOJO_WEBSERVER_THREADPOOL_H

#include<functional>
#include<thread>
#include<queue>
#include<mutex>
#include <condition_variable>

using ThreadFunction = std::function<void()>;

class ThreadPool {
public:
	ThreadPool(int num_threads);
	~ThreadPool();
	
	void AssignJob(const ThreadFunction& job);

private:
	std::vector<std::thread> _threads;
	std::queue<ThreadFunction> _jobs;
	std::mutex _lock;
	std::condition_variable _cond;
	
	bool _shutdown;//whether turn off the thread-pool power or not
};


#endif //JOJO_WEBSERVER_THREADPOOL_H
