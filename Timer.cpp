//
// Created by jojo on 2020/5/3.
//

#include "Timer.h"
#include "HttpRequest.h"

void TimerManager::Add_Timer(HttpRequest* request, const int& timeout, const TimeoutFunction& func)
{
	std::unique_lock<std::mutex> lock(_lock);
	
	assert(request != nullptr);
	
	Update_Time();
	Timer* timer = new Timer(_cur_time + MS(timeout), func);
	_timer_queue.push(timer);//push a new timer
	
	if(request -> Get_Timer() != nullptr) //Already got a timer
		Del_Timer(request); //Delete old timer
		
	request -> Set_Timer(timer);
}
					 
void TimerManager::Del_Timer(HttpRequest* request)
{
	//Watch out ! Don't lock in this function
	assert(request != nullptr);
	
	Timer* timer = request -> Get_Timer(); //copy this Timer* pointer
	if(timer == nullptr)
		return ;
	//Lazy delete
	timer -> Del_This(); //Set delete status
	request -> Set_Timer(nullptr); //Avoid  "request -> Get_Timer()"  use a dangling pointer
}

void TimerManager::Handle_Expire_Timers()
{
	std::unique_lock<std::mutex> lock(_lock);
	
	Update_Time();
	
	while(!_timer_queue.empty())
	{
		Timer* timer = _timer_queue.top();
		assert(timer != nullptr);
		
		if(timer -> Is_Deleted())
		{
			_timer_queue.pop();//pop this timer
			delete timer;
			continue;
		}
		
		if(std::chrono::duration_cast<MS>(timer -> Get_Expire_Time() - _cur_time).count() > 0)//Head timer not expire ---> all timer not expire
			return ;
		
		timer -> Call_Back();
		_timer_queue.pop();
		delete timer;
	}
}

int TimerManager::Get_Next_Expire_Time()
{
	std::unique_lock<std::mutex> lock(_lock);
	
	Update_Time();
	
	int res = -1; //return -1 when timer_queue is empty
	while(!_timer_queue.empty())
	{
		Timer* timer = _timer_queue.top();
		if(timer -> Is_Deleted())
		{
			_timer_queue.pop();
			delete timer;
			continue;
		}
		res = std::chrono::duration_cast<MS>(timer -> Get_Expire_Time() - _cur_time).count();
		res = (res < 0) ? 0 : res;
		break;
	}
	return res;
}








