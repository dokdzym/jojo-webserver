//
// Created by jojo on 2020/5/3.
//

#ifndef JOJO_WEBSERVER_BUFFER_H
#define JOJO_WEBSERVER_BUFFER_H

#include <iostream>
#include <vector>
#include <string>
#include <algorithm> // copy
#include <unistd.h> //close
#include <cassert>

#define BUFFER_SIZE 1024

class Buffer
{
public:
    Buffer();
    ~Buffer(){}
	
	//TODO in Buffer.cpp
	ssize_t Read_Fd(int fd, int* err_no);
	ssize_t Write_Fd(int fd, int* err_no);
	
	size_t Readable_Bytes() const {return _writer_index - _reader_index;}
	size_t Writable_Bytes() const {return BUFFER_SIZE - _writer_index;}
	size_t Prependable_Bytes( )const {return _reader_index;}
	
	//Get first readable/writable position
	const char* Read_Peek() const {return Buffer_Begin() + _reader_index;}
	const char* Write_Peek() const {return Buffer_Begin() + _writer_index;}
	char* Write_Peek() {return Buffer_Begin() + _writer_index;}
	
	//Change reader_index 
	void Retrieve(size_t len){assert(len <= Readable_Bytes()); _reader_index += len;}
	void Retrieve_Until(const char* end)
	{
		assert(Write_Peek() <= end);
		assert(end <=  Write_Peek());
		Retrieve(end - Read_Peek());
	}
	void Reset_Index(){_reader_index = _writer_index = 0;}
	
	std::string Retrieve_String()
	{
		std::string res(Read_Peek(), Readable_Bytes());
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
        _writer_index += len;
	}
	
	void Append(const std::string& str)
	{
		Append(str.data(), str.size());
	}
	
	void Append(const Buffer& b)
	{
		Append(b.Read_Peek(), b.Readable_Bytes());
	}
	
	const char* Find_CRLF() const
    {
        const char CRLF[] = "\r\n";
        const char* crlf = std::search(Read_Peek(), Write_Peek(), CRLF, CRLF+2);
        return crlf == Write_Peek() ? nullptr : crlf;
    }

    const char* Find_CRLF(const char* start) const
    {
        assert(Read_Peek() <= start);
        assert(start <= Write_Peek());
        const char CRLF[] = "\r\n";
        const char* crlf = std::search(start, Write_Peek(), CRLF, CRLF + 2);
        return crlf == Write_Peek() ? nullptr : crlf;
    }
	
private:
	char* Buffer_Begin(){return &*_buffer.begin();}
    const char* Buffer_Begin() const {return &*_buffer.begin();}
	
	void Make_Space(size_t len)
	{
		if(Writable_Bytes() + Prependable_Bytes() < len)
			_buffer.resize(_writer_index + len);
		else
		{
			size_t readble = Readable_Bytes();
			std::copy(Buffer_Begin() + _reader_index,
					  Buffer_Begin() + _writer_index,
					  Buffer_Begin());
            _reader_index = 0;
            _writer_index = readble;
			assert(readble == Readable_Bytes());
		}
	}

private:
	std::vector<char> _buffer;
	size_t _reader_index;
	size_t _writer_index;
};


#endif //JOJO_WEBSERVER_BUFFER_H
