/* 
 * File: BaseHostInfoPimpl.cpp
 * 
 * Author: Akira Sugiura (urasandesu@gmail.com)
 * 
 * 
 * Copyright (c) 2014 Akira Sugiura
 *  
 *  This software is MIT License.
 *  
 *  Permission is hereby granted, free of charge, to any person obtaining a copy
 *  of this software and associated documentation files (the "Software"), to deal
 *  in the Software without restriction, including without limitation the rights
 *  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 *  copies of the Software, and to permit persons to whom the Software is
 *  furnished to do so, subject to the following conditions:
 *  
 *  The above copyright notice and this permission notice shall be included in
 *  all copies or substantial portions of the Software.
 *  
 *  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 *  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 *  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 *  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 *  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 *  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 *  THE SOFTWARE.
 */


#include "stdafx.h"

#ifndef URASANDESU_SWATHE_HOSTING_BASECLASSPIMPL_BASEHOSTINFOPIMPL_HPP
#include <Urasandesu/Swathe/Hosting/BaseClassPimpl/BaseHostInfoPimpl.hpp>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_HOSTING_DEFAULTCLASSPIMPLAPIHOLDER_DEFAULTHOSTINFOPIMPLAPIHOLDER_H
#include <Urasandesu/Swathe/AutoGen/Hosting/DefaultClassPimplApiHolder/DefaultHostInfoPimplApiHolder.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_HOSTING_DEFAULTCLASSAPIHOLDER_DEFAULTHOSTINFOAPIHOLDER_H
#include <Urasandesu/Swathe/AutoGen/Hosting/DefaultClassApiHolder/DefaultHostInfoApiHolder.h>
#endif

#ifndef URASANDESU_SWATHE_HOSTING_BASECLASS_BASEHOSTINFO_H
#include <Urasandesu/Swathe/Hosting/BaseClass/BaseHostInfo.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_HOSTING_DEFAULTCLASSPERSISTEDHANDLERAPIHOLDER_DEFAULTHOSTINFOPERSISTEDHANDLERAPIHOLDER_H
#include <Urasandesu/Swathe/AutoGen/Hosting/DefaultClassPersistedHandlerApiHolder/DefaultHostInfoPersistedHandlerApiHolder.h>
#endif

#ifndef URASANDESU_SWATHE_HOSTING_BASECLASSPERSISTEDHANDLER_BASEHOSTINFOPERSISTEDHANDLER_H
#include <Urasandesu/Swathe/Hosting/BaseClassPersistedHandler/BaseHostInfoPersistedHandler.h>
#endif

#ifndef URASANDESU_SWATHE_DEFAULTCLASSAPIHOLDER_DEFAULTSWATHESTORAGEAPIHOLDER_H
#include <Urasandesu/Swathe/DefaultClassApiHolder/DefaultSwatheStorageApiHolder.h>
#endif

#ifndef URASANDESU_SWATHE_BASECLASS_BASESWATHESTORAGE_H
#include <Urasandesu/Swathe/BaseClass/BaseSwatheStorage.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_HOSTING_DEFAULTCLASSAPIHOLDER_DEFAULTRUNTIMEHOSTAPIHOLDER_H
#include <Urasandesu/Swathe/AutoGen/Hosting/DefaultClassApiHolder/DefaultRuntimeHostApiHolder.h>
#endif

#ifndef URASANDESU_SWATHE_HOSTING_BASECLASS_BASERUNTIMEHOST_H
#include <Urasandesu/Swathe/Hosting/BaseClass/BaseRuntimeHost.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_HOSTING_DEFAULTCLASSPERSISTEDHANDLERAPIHOLDER_DEFAULTRUNTIMEHOSTPERSISTEDHANDLERAPIHOLDER_H
#include <Urasandesu/Swathe/AutoGen/Hosting/DefaultClassPersistedHandlerApiHolder/DefaultRuntimeHostPersistedHandlerApiHolder.h>
#endif

#ifndef URASANDESU_SWATHE_HOSTING_BASECLASSPERSISTEDHANDLER_BASERUNTIMEHOSTPERSISTEDHANDLER_H
#include <Urasandesu/Swathe/Hosting/BaseClassPersistedHandler/BaseRuntimeHostPersistedHandler.h>
#endif

extern template class Urasandesu::Swathe::Hosting::BaseClass::BaseHostInfo<>;
extern template class Urasandesu::Swathe::Hosting::BaseClassPersistedHandler::BaseHostInfoPersistedHandler<>;
extern template class Urasandesu::Swathe::BaseClass::BaseSwatheStorage<>;
extern template class Urasandesu::Swathe::Hosting::BaseClass::BaseRuntimeHost<>;
extern template class Urasandesu::Swathe::Hosting::BaseClassPersistedHandler::BaseRuntimeHostPersistedHandler<>;
template class Urasandesu::Swathe::Hosting::BaseClassPimpl::BaseHostInfoPimpl<>;
SWATHE_DECLARE_BASE_HOST_INFO_PIMPL_ADDITIONAL_INSTANTIATION

