//
// Created by jojo on 2020/5/3.
//

#include "ThreadPool.h"

ThreadPool::ThreadPool(int num_threads):_shutdown(true)
{
	num_threads = num_threads <= 0 ? 1 : num_threads;
	
	for(int i = 0; i < num_threads; ++ i)
		_threads.emplace_back(
		[this]()
		{
			while(true)
			{
				ThreadFunction func;
				{
				std::unique_lock<std::mutex> lock(_lock);
				while(_shutdown && _jobs.empty())
					_cond.wait(lock);
				if(_jobs.empty() && !_shutdown)
					return ;
				func = _jobs.front(); //Thread get a job
				_jobs.pop();  //Job lists pop first job out
				}//free lock
			if(func)
				func();
			}
		}
		);
}

ThreadPool::~ThreadPool()
{
	{
		std::unique_lock<std::mutex> lock(_lock);
		_shutdown = false;
	}//free lock
	_cond.notify_all();
	for(auto & thread : _threads)
		thread.join();
}

void ThreadPool::AssignJob(const ThreadFunction& job)
{
	{
		std::unique_lock<std::mutex> lock(_lock);
		_jobs.push(job); //It's not an atomic operation!Watch out your lock.
	}//free lock
	_cond.notify_one();
}