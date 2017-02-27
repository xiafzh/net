#ifndef __PACKET_FILTER_H__
#define __PACKET_FILTER_H__

#include "mem_stream.h"

namespace summit
{
	namespace network
	{
		class CPacket;
		class CStreamInput;
		class CPacketFactoryMgr;

		class CPacketFilter
		{
		public:
			TInt32 PacketRead(CStreamInput& Input, CPacketFactoryMgr& PacketMgr);
			CMemStream* PacketWrite(CPacket& Packet);
			CPacket* GetCachePacket();
		public:
			CPacketFilter();
			~CPacketFilter();
		private:
			CMemStream		m_MemStream;
			CPacket*		m_CachePacket;
		};
	}
}
#endif