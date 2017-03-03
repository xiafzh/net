#ifndef __PACKET_FACTORY_MGR_H__
#define __PACKET_FACTORY_MGR_H__

#include "platform.h"

namespace summit
{
	namespace network
	{
		class CPacket;
		class CPacketFactory;
		class CPacketFactoryMgr;

		struct SPacketHead
		{
			TInt32	m_PacketID;
			TInt32	m_PacketLen;
		}; 

		class CPacketFactoryMgr
		{
		public:
			bool IsPacketIDValid(TPacketID ID) const;
			CPacket* NewPacket(TPacketID ID);
			void RemovePacket(CPacket& Packet);
		public:
			bool AddFactory(CPacketFactory& Factory);
		public:
			CPacketFactoryMgr();
			~CPacketFactoryMgr();
		private:
			bool __InitInnerPacket();
			bool __IsHave(CPacketFactory* Factory);
		private:
			typedef std::map<TPacketID, CPacketFactory*>
				TPacketFactoryMap;
		private:
			TPacketFactoryMap		m_FactoryArray;
		};
	}
}
#endif