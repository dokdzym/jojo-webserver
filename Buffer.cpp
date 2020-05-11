//
// Created by jojo on 2020/5/3.
//

#include "Buffer.h"

#include <sys/uio.h> // readv
#include <cstring> // perror

Buffer::Buffer():
	_buffer(BUFFER_SIZE),
	_reader_index(0),
	_writer_index(0)
{
	assert(Readable_Bytes() == 0);
	assert(Writable_Bytes() == BUFFER_SIZE);
}

ssize_t Buffer::Read_Fd(int fd, int* err_no)
{
	char extra_buf[65536];
	struct iovec vec[2];
	const size_t writable_bytes = Writable_Bytes();
	
	vec[0].iov_base = Buffer_Begin() + _writer_index;
	vec[0].iov_len = writable_bytes;
	vec[1].iov_base = extra_buf;
	vec[1].iov_len = sizeof(extra_buf);
	
	const ssize_t n = readv(fd, vec, 2);
	
	if(n < 0)
	{
        std::cout << "Error occurs in Buffer.cpp! Read_Fd failed! errno = " << errno << std::endl;
		*err_no = errno;
	}
	else if(static_cast<size_t>(n) <= writable_bytes)
        _writer_index += n;
	else
	{
        _writer_index = _buffer.size();
		Append(extra_buf, n - writable_bytes);
	}
	return n;
}


ssize_t Buffer::Write_Fd(int fd, int* err_no)
{
	size_t n_left = Readable_Bytes();
	char* buf = Buffer_Begin() + _reader_index;
	ssize_t n;
	
	if((n = write(fd, buf, n_left)) <= 0)
	{
		if(n < 0 && n == EINTR)
			return 0;
		else
		{
			std::cout << "Error occurs in Buffer.cpp! Read_Fd failed! errno = " << errno << std::endl;
			*err_no = errno;
			return -1;
		}
	}
	else
	{
        _reader_index += n;
		return n;
	}
}

