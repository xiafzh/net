#ifndef __SOCKET_STREAM_H__
#define __SOCKET_STREAM_H__

#include "stream_input.h"
#include "stream_output.h"

namespace summit
{
	namespace network
	{
		class CSocketStream
		{
		public:
			bool Init(TInt32 InLen, TInt32 InMax,
				TInt32 OutLen, TInt32 OutMax);
		public:
			CStreamInput&	GetStreamInput();
			CStreamOutput&	GetStreamOutput();
		public:
			TInt32	Recv();
			TInt32	Send();
		public:
			CSocketStream(CSocket& T);
			virtual ~CSocketStream();
		private:
			CSocketStream(const CSocketStream&);
		private:
			CSocket&		m_Socket;
			CStreamInput	m_StreamInput;
			CStreamOutput	m_StreamOutput;
		};
	}
}

#endif