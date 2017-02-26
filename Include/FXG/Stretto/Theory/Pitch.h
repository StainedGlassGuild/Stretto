/**************************************************************************************************\
 MIT License
 Copyright (c) 2017 FXGuild
 See file "LICENSE.txt" at project root for complete license
 - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
 Creation  : February 25, 2017
 Namespace : FXG::Stretto::Theory
 Content   : class Pitch
\**************************************************************************************************/

#pragma once

#include <FXG/Stretto/Theory/Tone.h>

namespace FXG::Stretto::Theory
{
   class Pitch final
   {
   public:
      /************************************************************************/
      /* Constructors / Destructor / Assignment Operators                     */
      /************************************************************************/

      Pitch(Tone a_Tone, uint8_t a_Octave) noexcept;
      Pitch(Pitch const &) noexcept = default;
      Pitch(Pitch &&) noexcept      = default;
      ~Pitch() noexcept             = default;

      Pitch & operator=(Pitch const &) noexcept = default;
      Pitch & operator=(Pitch &&) noexcept = default;

      /************************************************************************/
      /* Getters                                                              */
      /************************************************************************/

      Tone const &    getTone() const;
      uint8_t const & getOctave() const;

   private:
      Tone    m_Tone;
      uint8_t m_Octave;
   };
}