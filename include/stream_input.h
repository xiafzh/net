#ifndef __STREAM_INPUT_H__
#define __STREAM_INPUT_H__

#include "base.h"
#include "mem_stream.h"
#include "socket.h"

namespace summit
{
	namespace network
	{
		class CStreamInput
		{
		public:
			bool Init(TUInt32 BuffSize, TUInt32 MaxBuffSize);
			TInt32 Recv(CSocket& FD);
		public:
			bool ReadMem(CMemStream& Mem, TUInt32 Len);
			bool Peek(char* Buff, TUInt32 Len);
			bool Skip(TUInt32 Len);
			bool Read(char* Dest, TUInt32 Len);
			TUInt32 Length() const;
		private:
			bool __Resize(TUInt32 AddLen);
		public:
			CStreamInput();
			~CStreamInput();
		private:
			char*		m_Buff;
			TUInt32		m_Head;
			TUInt32		m_Tail;
			TUInt32		m_BuffLen;
			TUInt32		m_MaxBuffLen;
		};
	}
}

#endif