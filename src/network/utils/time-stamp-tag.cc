/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */
/*
 * Copyright (c) 2008 INRIA
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation;
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 * Author: Caleb Bowers <czb3@georgetown.edu>
 */
#include "time-stamp-tag.h"
#include "ns3/log.h"

namespace ns3 {

NS_LOG_COMPONENT_DEFINE ("TimeStampTag");

NS_OBJECT_ENSURE_REGISTERED (TimeStampTag);

TypeId 
TimeStampTag::GetTypeId (void)
{
  static TypeId tid = TypeId ("ns3::TimeStampTag")
    .SetParent<Tag> ()
    .SetGroupName("Network")
    .AddConstructor<TimeStampTag> ()
  ;
  return tid;
}
TypeId 
TimeStampTag::GetInstanceTypeId (void) const
{
  return GetTypeId ();
}
uint32_t 
TimeStampTag::GetSerializedSize (void) const
{
  NS_LOG_FUNCTION (this);
  return 4;
}
void 
TimeStampTag::Serialize (TagBuffer buf) const
{
  NS_LOG_FUNCTION (this << &buf);
  buf.WriteU32 (m_timeStamp.GetNanoSeconds ());
}
void 
TimeStampTag::Deserialize (TagBuffer buf)
{
  NS_LOG_FUNCTION (this << &buf);
  m_timeStamp = Time ( NanoSeconds(buf.ReadU32 ()));
}
void 
TimeStampTag::Print (std::ostream &os) const
{
  NS_LOG_FUNCTION (this << &os);
  os << "TimeStamp=" << m_timeStamp;
}
TimeStampTag::TimeStampTag ()
  : Tag () 
{
  NS_LOG_FUNCTION (this);
}

TimeStampTag::TimeStampTag (Time timeStamp)
  : Tag (),
    m_timeStamp (timeStamp)
{
  NS_LOG_FUNCTION (this << timeStamp);
}

void
TimeStampTag::SetTimeStamp (Time timeStamp)
{
  NS_LOG_FUNCTION (this << timeStamp);
  m_timeStamp = timeStamp;
}

Time
TimeStampTag::GetTimeStamp (void) const
{
  NS_LOG_FUNCTION (this);
  return m_timeStamp;
}

} // namespace ns3

