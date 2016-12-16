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

namespace tcu
{
namespace gbm
{

class NativePixmap;

class NativePixmapFactory final : public eglu::NativePixmapFactory
{
public:
	NativePixmapFactory (void);
	~NativePixmapFactory (void) override {}

	eglu::NativePixmap* createPixmap (eglu::NativeDisplay* nativeDisplay,
									  int width, int height) const override;

	eglu::NativePixmap* createPixmap (eglu::NativeDisplay* nativeDisplay,
									  eglw::EGLDisplay display,
									  eglw::EGLConfig config,
									  const eglw::EGLAttrib* attribList,
									  int width, int height) const override;

private:
	NativePixmapFactory	(const NativePixmapFactory&) = delete;
	NativePixmapFactory& operator=(const NativePixmapFactory&) = delete;

	eglu::NativePixmap* createPixmap (eglu::NativeDisplay* nativeDisplay,
									  int width, int height,
									  uint32_t gbm_format) const;
};

} // gbm
} // tcu
