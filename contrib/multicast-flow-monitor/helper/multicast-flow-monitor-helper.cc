/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */

#include "multicast-flow-monitor-helper.h"

#include "ns3/multicast-flow-monitor.h"
#include "ns3/ipv4-multicast-flow-classifier.h"
#include "ns3/ipv4-multicast-flow-probe.h"
#include "ns3/ipv4-l3-protocol.h"
#include "ns3/node.h"
#include "ns3/node-list.h"

namespace ns3 {

MulticastFlowMonitorHelper::MulticastFlowMonitorHelper ()
{
	m_monitorFactory.SetTypeId ("ns3::MulticastFlowMonitor");
}

MulticastFlowMonitorHelper::~MulticastFlowMonitorHelper ()
{
	if (m_multicastFlowMonitor)
	{
		m_multicastFlowMonitor->Dispose ();
		m_multicastFlowMonitor = 0;
		m_multicastFlowClassifier = 0;
	}
}

void
MulticastFlowMonitorHelper::SetMulticastMonitorAttribute (std::string n1, const AttributeValue &v1)
{
	m_monitorFactory.Set (n1, v1);
}

Ptr<MulticastFlowMonitor>
MulticastFlowMonitorHelper::GetMonitor ()
{
	if(!m_multicastFlowMonitor)
	{
		m_multicastFlowMonitor = m_monitorFactory.Create<MulticastFlowMonitor> ();
		m_multicastFlowClassifier = Create<Ipv4MulticastFlowClassifier> ();
		m_multicastFlowMonitor->AddMulticastFlowClassifier (m_multicastFlowClassifier);
	}
	return m_multicastFlowMonitor;
}

Ptr<MulticastFlowClassifier>
MulticastFlowMonitorHelper::GetClassifier ()
{
	if (!m_multicastFlowClassifier)
	{
		m_multicastFlowClassifier = Create<Ipv4MulticastFlowClassifier> ();
	}
	return m_multicastFlowClassifier;
}

Ptr<MulticastFlowMonitor>
MulticastFlowMonitorHelper::Install (Ptr<Node> node, std::map<Ipv4Address, std::vector<uint32_t>> addressGroups)
{
	Ptr<MulticastFlowMonitor> monitor = GetMonitor ();
	Ptr<MulticastFlowClassifier> classifier = GetClassifier ();
	Ptr<Ipv4L3Protocol> ipv4 = node->GetObject<Ipv4L3Protocol> ();
	if (ipv4)
    {
		Ptr<Ipv4MulticastFlowProbe> probe = Create<Ipv4MulticastFlowProbe> (monitor,
		                                                DynamicCast<Ipv4MulticastFlowClassifier> (classifier),
		                                                node,
		                                                addressGroups);
    }
    return m_multicastFlowMonitor;
}

Ptr<MulticastFlowMonitor>
MulticastFlowMonitorHelper::Install (NodeContainer nodes, std::map<Ipv4Address, std::vector<uint32_t>> addressGroups)
{
	for (NodeContainer::Iterator i = nodes.Begin (); i != nodes.End (); ++i)
	{
		Ptr<Node> node = *i;
		if (node->GetObject<Ipv4L3Protocol> ())
		{
			Install (node, addressGroups);
		}
	}
	return m_multicastFlowMonitor;
}

Ptr<MulticastFlowMonitor>
MulticastFlowMonitorHelper::InstallAll (std::map<Ipv4Address, std::vector<uint32_t>> addressGroups)
{
	for (NodeList::Iterator i = NodeList::Begin (); i != NodeList::End (); ++i)
	{
		Ptr<Node> node = *i;
		if(node->GetObject<Ipv4L3Protocol> ())
		{
			Install (node, addressGroups);
		}
	}
	return m_multicastFlowMonitor;
}





}

