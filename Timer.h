//
// Created by jojo on 2020/5/3.
//

#ifndef JOJO_WEBSERVER_TIMER_H
#define JOJO_WEBSERVER_TIMER_H

#include<iostream>
#include<functional>
#include<chrono> //Clock
#include<queue>
#include<mutex>
#include<cassert>
#include<vector>

class HttpRequest;

using TimeoutFunction = std::function<void()>;
using Clock = std::chrono::high_resolution_clock;
using MS = std::chrono::milliseconds;
using TimeStamp = Clock::time_point;

class Timer {
public:
    Timer(const TimeStamp& when, const TimeoutFunction& func)
            : _expire_time(when),
              _call_back(func),
              _delete(false) {}
	~Timer(){}
	
	void Del_This() {_delete = true;}
	bool Is_Deleted() const {return _delete;}
	TimeStamp Get_Expire_Time() const {return _expire_time;}
	void Call_Back() {_call_back();}
	
private:
	TimeStamp _expire_time;
	TimeoutFunction _call_back;
	bool _delete;
};

struct cmp
{
	bool operator()(Timer* a, Timer* b)
	{
		assert(a && b);
		return (a -> Get_Expire_Time() > b -> Get_Expire_Time());
	}
};

class TimerManager
{
public:
	TimerManager():_cur_time(Clock::now()){}
	~TimerManager(){}
	
	void Update_Time() {_cur_time = Clock::now();}
	void Add_Timer(HttpRequest* request, const int& timeout, const TimeoutFunction& func);
	void Del_Timer(HttpRequest* request);
	
	void Handle_Expire_Timers();
	int Get_Next_Expire_Time();
	
private:
	using TimerQueue = std::priority_queue<Timer*, std::vector<Timer*>, cmp>;
	
	TimerQueue _timer_queue;
	TimeStamp _cur_time;
	std::mutex _lock;
};


#endif //JOJO_WEBSERVER_TIMER_H
