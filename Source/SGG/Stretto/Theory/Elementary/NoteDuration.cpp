#include <SGG/Stretto/Theory/Elementary/NoteDuration.h>

namespace SGG::Stretto::Theory
{
   /************************************************************************/
   /* Conversions                                                          */
   /************************************************************************/

   TimeUnit convertDurationToTimeunit ( NoteDuration i_DurationToDivide,
                                        NoteDuration i_SubDuration )
   {
      uint8_t const subDur  = static_cast< uint8_t > ( i_SubDuration );
      uint8_t const dur2Div = static_cast< uint8_t > ( i_DurationToDivide );
      int8_t const  delta   = subDur - dur2Div;
      return delta >= 0 ? 1 << delta : 0;
   }


   /************************************************************************/
   /* Serialization                                                        */
   /************************************************************************/

   std::wostream & operator<< ( std::wostream & io_OS, NoteDuration const & i_Note )
   {
      switch ( i_Note )
      {
      case NoteDuration::WHOLE: io_OS << 'w'; break;
      case NoteDuration::HALF: io_OS << 'h'; break;
      case NoteDuration::QUARTER: io_OS << 'q'; break;
      case NoteDuration::EIGHT: io_OS << 'e'; break;
      case NoteDuration::SIXTEENTH: io_OS << 's'; break;
      case NoteDuration::THIRTYSECOND: io_OS << 't'; break;
      case NoteDuration::SIXTYFOURTH: io_OS << 'x'; break;
      }
      return io_OS;
   }
}
