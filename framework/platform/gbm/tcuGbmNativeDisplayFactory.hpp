/*-----------------------------------------
 * drawElements Quality Program Tester Core
 * ----------------------------------------
 *
 * Copyright 2016 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#pragma once

#include <gbm.h>

#include "egluNativeDisplay.hpp"
#include "tcuGbmNativeDisplay.hpp"
#include "tcuGbmNativePixmapFactory.hpp"
#include "tcuGbmNativeWindowFactory.hpp"

namespace tcu
{
namespace gbm
{

class NativeDisplayFactory final : public eglu::NativeDisplayFactory
{
public:
	NativeDisplayFactory (void)
		: eglu::NativeDisplayFactory("default",
									 "Default display",
									 NativeDisplay::CAPABILITIES,
									 EGL_PLATFORM_GBM_KHR,
									 "EGL_KHR_platform_gbm")
	{
		m_nativeWindowRegistry.registerFactory(new NativeWindowFactory());
		m_nativePixmapRegistry.registerFactory(new NativePixmapFactory());
	}

	~NativeDisplayFactory (void) override {}

	NativeDisplay* createDisplay (const eglw::EGLAttrib* attribList) const override
	{
		DE_UNREF(attribList);
		return new NativeDisplay();
	}

private:
							NativeDisplayFactory	(const NativeDisplayFactory&) = delete;
	NativeDisplayFactory&	operator=				(const NativeDisplayFactory&) = delete;
};

} // gbm
} // tcu
