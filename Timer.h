//
// Created by jojo on 2020/5/3.
//

#ifndef JOJO_WEBSERVER_TIMER_H
#define JOJO_WEBSERVER_TIMER_H

class HttpRequest;

class Timer {
public:
	Timer();
	~Timer();
	
	//void Add_Timer(HttpRequest* request, 1, 1);//TODO
	void Del_Timer(HttpRequest* request);//TODO
};


#endif //JOJO_WEBSERVER_TIMER_H
