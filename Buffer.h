//
// Created by jojo on 2020/5/3.
//

#ifndef JOJO_WEBSERVER_BUFFER_H
#define JOJO_WEBSERVER_BUFFER_H

#include <vector>
#include <string>
#include <algorithm> // copy
#include <iostream>
#include <unistd.h> //close
#include <cassert>

#define BUFFER_SIZE 1024

class Buffer
{
public:
    Buffer();
    ~Buffer();
	
	//TODO in Buffer.cpp
	ssize_t Read_Fd(int fd, int* err_no);
	ssize_t Write_Fd(int fd, int* err_no);
	
	size_t Readable_Bytes() const {return writer_index - reader_index;}
	size_t Writable_Bytes() const {return BUFFER_SIZE - writer_index;}
	size_t Prependable_Bytes const {return reader_index;}
	
	//Get first readable/writable position
	const char* Read_Peek() const {return Buffer_Begin() + reader_index;}
	const char* Write_Peek() const {return Buffer_Begin() + writer_index;}
	char* Write_Peek() {return Buffer_Begin() + writer_index;}
	
	//Change reader_index 
	void Retrieve(size_t len){assert(len <= Readable_Bytes()); reader_index += len;}
	void Retrieve_Until(const char* end)
	{
		assert(Write_Peek() <= end);
		assert(end <=  Write_Peek());
		Retrieve(end - Read_Peek());
	}
	void Reset_Index(){reader_index = writer_index = 0;}
	
	std::string Retrieve_String()
	{
		std:: res(Read_Peek(), Readable_Bytes());
		Reset_Index();
		return res;
	}
	
	void Ensure_Enough_For_Write(size_t len)
	{
		if(Writable_Bytes() < len)
			Make_Space(len);
		assert(Writable_Bytes() >= len);
	}
	
	//Add data to buffer
	void Append(const char* data, size_t len)
	{
		Ensure_Enough_For_Write(len);
		std::copy(data, data + len, Write_Peek());
		writer_index += len;
	}
	
	void Append(std::string& str)
	{
		Append(str.data(), str.size());
	}
	
	void Append(const Buffer& b)
	{
		append(b.Read_Peek(), b.Readable_Bytes());
	}
	
private:
	char* Buffer_Begin(){return &*_buffer.begin();}
	
	void Make_Space(size_t len)
	{
		if(Writable_Bytes() + Prependable_Bytes() < len)
			_buffer.resize(writer_index + len);
		else
		{
			size_t readble = Readable_Bytes();
			std::copy(Buffer_Begin() + reader_index,
					  Buffer_Begin() + writer_index,
					  Buffer_Begin());
			reader_index = 0;
			writer_index = readble;
			assert(readble == Readable_Bytes());
		}
	}

private:
	std::vector<char> _buffer;
	size_t reader_index;
	size_t writer_index;
};


#endif //JOJO_WEBSERVER_BUFFER_H