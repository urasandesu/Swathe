#pragma once
#ifndef URASANDESU_SWATHE_METADATA_CALLINGCONVENTIONS_H
#define URASANDESU_SWATHE_METADATA_CALLINGCONVENTIONS_H

#ifndef URASANDESU_SWATHE_SAFEENUM_H
#include <Urasandesu/Swathe/SafeEnum.h>
#endif

namespace Urasandesu { namespace Swathe { namespace Metadata {

    namespace CallingConventionsDetail {

        class ATL_NO_VTABLE CallingConventionsDef
        {
        public:
            enum type
            {
                CC_NO_VALUE,
                CC_STANDARD, 
                CC_VAR_ARGS, 
                CC_ANY, 
                CC_HAS_THIS, 
                CC_EXPLICIT_THIS, 
                CC_UNREACHED
            };

            std::vector<COR_SIGNATURE> const &GetSignatures() const
            {
                if (m_sigs.empty())
                {
                    typedef SafeEnum<CallingConventionsDef> CallingConventions;
                
                    CallingConventions const *this_ = static_cast<CallingConventions const *>(this);
                    switch (this_->Value())
                    {
                        case CC_STANDARD: 
                            m_sigs.push_back(IMAGE_CEE_CS_CALLCONV_DEFAULT);
                            break;
                        case CC_VAR_ARGS: 
                            BOOST_THROW_EXCEPTION(SwatheNotImplementedException());
                        case CC_ANY: 
                            BOOST_THROW_EXCEPTION(SwatheNotImplementedException());
                        case CC_HAS_THIS: 
                            m_sigs.push_back(IMAGE_CEE_CS_CALLCONV_HASTHIS);
                            break;
                        case CC_EXPLICIT_THIS: 
                            BOOST_THROW_EXCEPTION(SwatheNotImplementedException());
                        default:
                            BOOST_THROW_EXCEPTION(SwatheNotImplementedException());
                    }
                }
                return m_sigs;
            }
        
        protected:
            CallingConventionsDef() { }
        
        private:
            mutable std::vector<COR_SIGNATURE> m_sigs;
        };

    }   // namespace CallingConventionsDetail {

    typedef SafeEnum<CallingConventionsDetail::CallingConventionsDef> CallingConventions;

}}}   // namespace Urasandesu { namespace Swathe { namespace Metadata {

#endif  // #ifndef URASANDESU_SWATHE_METADATA_CALLINGCONVENTIONS_H