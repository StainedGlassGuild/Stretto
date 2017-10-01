/**************************************************************************************************\
 MIT License
 Copyright (c) 2017 StainedGlassGuild
 See file "LICENSE.txt" at project root for complete license
 - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
 Creation    : February 25, 2017
 Project     : Theory
 Summary     : NA
 Description : NA
\**************************************************************************************************/

#pragma once

#include <SGG/Stretto/Theory/Elementary/CanonicNote.h>

namespace SGG::Stretto::Theory
{
   class CanonicNode final
   {
   public:
      /************************************************************************/
      /* Nested types                                                         */
      /************************************************************************/

      enum class Type
      {
         STARTING_NOTE,
         TIED_NOTE,
         REST
      };


      /************************************************************************/
      /* Constructors / Destructor / Assignment Operators                     */
      /************************************************************************/

      CanonicNode ( Theory::CanonicNote const & i_Note, bool i_IsTied ) noexcept;
      CanonicNode ( Theory::NoteDuration i_RestDuration ) noexcept;
      CanonicNode ( CanonicNode const & ) noexcept = default;
      CanonicNode ( CanonicNode && ) noexcept      = default;
      ~CanonicNode () noexcept                     = default;

      CanonicNode & operator= ( CanonicNode const & ) noexcept = default;
      CanonicNode & operator= ( CanonicNode && ) noexcept = default;


      /************************************************************************/
      /* Getters                                                              */
      /************************************************************************/

      Theory::CanonicNote const & getNote () const;
      Theory::NoteDuration        getDuration () const;
      Type                        getType () const;


      /************************************************************************/
      /* Status                                                               */
      /************************************************************************/

      bool isRest () const;

   private:
      Theory::CanonicNote m_Note;
      Type                m_Type;
   };


   /************************************************************************/
   /* Serialization                                                        */
   /************************************************************************/

   std::ostream & operator<< ( std::ostream & io_OS, CanonicNode const & i_Node );
}