#ifndef __PACKET_FACTORY_H__
#define __PACKET_FACTORY_H__

#include "platform.h"
#include "packet.h"

namespace summit
{
	namespace network
	{
		class CPacketFactory
		{
		public:
			virtual TPacketID PacketId() const = 0;
		private:
			virtual CPacket* __Create() = 0;
		public:
			CPacket* CreatePacket();
			bool RemovePacket(CPacket& Packet);
		public:
			CPacketFactory();
			virtual ~CPacketFactory();
		private:
			CPacket*		m_PacketCache;
			TInt32			m_NewCount;
			TInt32			m_CreateCount;
		};

	}
}
#endif