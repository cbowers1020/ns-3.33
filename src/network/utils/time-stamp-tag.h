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
 * Author: Mathieu Lacage <mathieu.lacage@sophia.inria.fr>
 */
#ifndef TIME_STAMP_TAG_H
#define TIME_STAMP_TAG_H

#include "ns3/tag.h"
#include "ns3/nstime.h"

namespace ns3 {

class TimeStampTag : public Tag
{
public:
  /**
   * \brief Get the type ID.
   * \return the object TypeId
   */
  static TypeId GetTypeId (void);
  virtual TypeId GetInstanceTypeId (void) const;
  virtual uint32_t GetSerializedSize (void) const;
  virtual void Serialize (TagBuffer buf) const;
  virtual void Deserialize (TagBuffer buf);
  virtual void Print (std::ostream &os) const;
  TimeStampTag ();
  
  /**
   *  Constructs a TimeStampTag with the given flow id
   *
   *  \param timeStamp time to use for the tag
   */
  TimeStampTag (Time timeStamp);
  /**
   *  Sets the time stamp for the tag
   *  \param timeStamp time to assign to the tag
   */
  void SetTimeStamp (Time timeStamp);
  /**
   *  Gets the time stamp for the tag
   *  \returns current time stamp for this tag
   */
  Time GetTimeStamp (void) const;

private:
  Time m_timeStamp; //!< Time Stamp
};

} // namespace ns3

#endif /* TIME_STAMP_TAG_H */
