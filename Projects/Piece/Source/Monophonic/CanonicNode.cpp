/**************************************************************************************************\
 MIT License
 Copyright (c) 2017 FXGuild
 See file "LICENSE.txt" at project root for complete license
 - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
 Creation  : February 25, 2017
 Namespace : FXG::Stretto::Piece::Monophonic
 Content   : class CanonicNode
\**************************************************************************************************/

#include <assert.h>

#include <FXG/Stretto/Piece/Monophonic/CanonicNode.h>

namespace FXG::Stretto::Piece::Monophonic
{
   /************************************************************************/
   /* Constructors / Destructor / Assignment Operators                     */
   /************************************************************************/

   CanonicNode::CanonicNode(Theory::CanonicNote const & a_Note, bool a_IsTied) noexcept
   : m_Note{ a_Note }
   , m_Type{ a_IsTied ? Type::TIED_NOTE : Type::STARTING_NOTE }
   {
   }

   CanonicNode::CanonicNode(Theory::NoteDuration a_RestDuration) noexcept
   : m_Note{ Theory::CanonicNote{ Theory::Pitch::A_440HZ, a_RestDuration } }
   , m_Type{ Type::REST }
   {
   }


   /************************************************************************/
   /* Getters                                                              */
   /************************************************************************/

   Theory::CanonicNote const & CanonicNode::getNote() const
   {
      assert(!isRest());
      return m_Note;
   }

   Theory::NoteDuration CanonicNode::getDuration() const
   {
      return m_Note.getDuration();
   }

   CanonicNode::Type CanonicNode::getType() const
   {
      return m_Type;
   }


   /************************************************************************/
   /* Status                                                               */
   /************************************************************************/

   bool CanonicNode::isRest() const
   {
      return m_Type == Type::REST;
   }
}