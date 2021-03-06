#ifndef TCP_CLIENT_H
#define TCP_CLIENT_H
#include<string>
#include"ns3/core-module.h"
#include"ns3/internet-module.h"
#include"ns3/network-module.h"
namespace ns3
{

class TcpClient
{
public:
	TcpClient(uint32_t clientid);
	void CreateSocket(Ptr<Node> node);
	void SetCongestionAlgo(std::string algo);
	void StartFlow(Ipv4Address servAddress,uint16_t servPort)
	{
		m_servAddr=servAddress;
		m_servPort=servPort;
		m_socket->Connect(InetSocketAddress (servAddress, servPort));
	}
	void SetWriteData(uint8_t *data,uint32_t len,uint64_t total){
		m_data=data;
		m_writeSize=len;
		m_total=total;
		}
	void StopTime(uint64_t duration){m_duration=duration;}//in seconds
	Ptr<Socket> GetSocket(){return m_socket;}
public:
uint64_t m_total;
uint64_t m_currentTxBytes;
Ipv4Address m_servAddr;
uint16_t m_servPort;
Ptr<Socket> m_socket;
uint8_t *m_data;
uint32_t m_writeSize;
uint64_t m_duration;
uint32_t m_cid;
};	
}

#endif
