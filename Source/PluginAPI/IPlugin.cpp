/**************************************************************************************************\
 MIT License
 Copyright (c) 2017 FXGuild
 See file "LICENSE.txt" at project root for complete license
 - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
 Creation  : March 25, 2017
 Namespace : FXG::Stretto::PluginAPI
 Content   : Abstract class IPlugin
\**************************************************************************************************/

#include <FXG/Stretto/PluginAPI/IPlugin.h>

namespace FXG::Stretto::PluginAPI
{
   /************************************************************************/
   /* Constructors / Destructor / Assignment Operators                     */
   /************************************************************************/

   IPlugin::IPlugin(std::string const & a_Name) noexcept
   : m_Name{ a_Name }
   , m_AnalysisModules{}
   {
   }


   /************************************************************************/
   /* Initialize                                                           */
   /************************************************************************/

   void IPlugin::registerComponents(StringMap<StructuralHierarchy> & a_Hierarchies)
   {
      registerAnalysisModules();
      createAndUpgradeStructualHierarchies(a_Hierarchies);
   }


   /************************************************************************/
   /* Getters                                                              */
   /************************************************************************/

   std::string const & IPlugin::getName() const
   {
      return m_Name;
   }

   std::vector<AnalysisModule> const & IPlugin::getAnalysisModules() const
   {
      return m_AnalysisModules;
   }
}