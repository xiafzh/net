#ifndef __MEM_STREAM_H__
#define __MEM_STREAM_H__

#include "platform.h"

namespace summit
{
	class CMemStream
	{
	public:
		static void ReclaimObj(CMemStream* Obj);
		static CMemStream* CreateMemStream();
	public:
		bool Insert(TUInt32 Pos, char* Data, TUInt32 Len);
		const char* GetData() const;

		TInt32 Fill(char* Buff, TInt32 Len, E_MSG_MODE Mode);
		TInt32 Length() const;
	public:
		CMemStream();
		~CMemStream();
	private:
		bool __Write(const char* Dest, TInt32 Len);
		bool __Read(char* Dest, TInt32 Len);
		bool __ReadSkip(TInt32 N);
	private:
		void __Clear(bool Clear);
		inline TInt32 __Size() CONST;
	private:
		static const TInt32	DEFAULT_SIZE = 0x10000;
	private:
		TInt32		m_PosRead;
		TInt32		m_PosWrite;
		TVecChar	m_Data;
	};

	TInt32 CMemStream::__Size() CONST
	{
		return m_Data.size();
	}
}

#endif