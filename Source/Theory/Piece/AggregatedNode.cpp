/**************************************************************************************************\
 MIT License
 Copyright (c) 2017 FXGuild
 See file "LICENSE.txt" at project root for complete license
 - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
 Creation  : February 25, 2017
 Namespace : FXG::Stretto::Theory::Piece
 Content   : class AggregatedNode
\**************************************************************************************************/

#include <assert.h>
#include <sstream>

#include <FXG/Stretto/Theory/Piece/AggregatedNode.h>

namespace FXG::Stretto::Theory::Piece
{
   /************************************************************************/
   /* Constructors / Destructor / Assignment Operators                     */
   /************************************************************************/

   AggregatedNode::AggregatedNode(Theory::AggregatedNote const & a_Note) noexcept
   : m_Note{ a_Note }
   , m_IsRest{ false }
   {
   }

   AggregatedNode::AggregatedNode(uint32_t a_RestDuration) noexcept
   : m_Note{ Theory::AggregatedNote{ Theory::Pitch::A_440HZ, a_RestDuration } }
   , m_IsRest{ true }
   {
   }


   /************************************************************************/
   /* Getters                                                              */
   /************************************************************************/

   Theory::AggregatedNote const & AggregatedNode::getNote() const
   {
      assert(!isRest());
      return m_Note;
   }

   uint32_t AggregatedNode::getDurationTU() const
   {
      return m_Note.getDurationTU();
   }


   /************************************************************************/
   /* Status                                                               */
   /************************************************************************/

   bool AggregatedNode::isRest() const
   {
      return m_IsRest;
   }


   /************************************************************************/
   /* Serialization                                                        */
   /************************************************************************/

   std::ostream & operator<<(std::ostream & a_OS, AggregatedNode const & a_Node)
   {
      if (a_Node.isRest())
      {
         a_OS << "-R- " << a_Node.getDurationTU();
      }
      else
      {
         a_OS << a_Node.getNote();
      }
      return a_OS;
   }
}