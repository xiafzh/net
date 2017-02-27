#ifndef __STREAM_OUTPUT_H__
#define __STREAM_OUTPUT_H__

#include "base.h"

namespace summit
{
	namespace network
	{
		class CStreamOutput
		{
		public:
			bool Init(TUInt32 BuffSize, TUInt32 MaxBuffSize);
			TInt32 Send(TSocket& FD);
		public:
			bool WriteMem(CMemStream& MemStrem);
			TUInt32 Length();
		private:
			bool __Resize(TUInt32 AddLen);
			TInt32 __Write(const char* Buff, TInt32 Len);
		public:
			CStreamOutput();
			~CStreamOutput();
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