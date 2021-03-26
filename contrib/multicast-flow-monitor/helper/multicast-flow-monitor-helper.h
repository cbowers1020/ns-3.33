/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */
#ifndef MULTICAST_FLOW_MONITOR_HELPER_H
#define MULTICAST_FLOW_MONITOR_HELPER_H

#include "ns3/node-container.h"
#include "ns3/object-factory.h"
#include "ns3/ipv4-address.h"
#include "ns3/multicast-flow-monitor.h"
#include "ns3/multicast-flow-classifier.h"
#include <string>

namespace ns3 {

class AttributeValue;
class Ipv4MulticastFlowClassifier;

/* 
* \ingroup multicast-flow-monitor
* \brief Helper to enable IP multicast flow monitoring on a set of Nodes
*/

class MulticastFlowMonitorHelper
{
public:
	MulticastFlowMonitorHelper ();
	~MulticastFlowMonitorHelper ();

	void SetMulticastMonitorAttribute (std::string n1, const AttributeValue &v1);

	Ptr<MulticastFlowMonitor> Install (NodeContainer nodes, std::map<Ipv4Address, std::vector<uint32_t>> addressGroups);

	Ptr<MulticastFlowMonitor> Install (Ptr<Node> node, std::map<Ipv4Address, std::vector<uint32_t>> addressGroups);

	Ptr<MulticastFlowMonitor> InstallAll (std::map<Ipv4Address, std::vector<uint32_t>> addressGroups);

	Ptr<MulticastFlowMonitor> GetMonitor ();

	Ptr<MulticastFlowClassifier> GetClassifier ();

private:

	MulticastFlowMonitorHelper (const MulticastFlowMonitorHelper&);

	MulticastFlowMonitorHelper& operator= (const MulticastFlowMonitorHelper&);

	ObjectFactory m_monitorFactory;
	Ptr<MulticastFlowMonitor> m_multicastFlowMonitor;
	Ptr<MulticastFlowClassifier> m_multicastFlowClassifier;
};

}

#endif /* MULTICAST_FLOW_MONITOR_HELPER_H */

