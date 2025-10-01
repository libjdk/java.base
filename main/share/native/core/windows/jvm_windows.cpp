/*
 * Copyright (c) 2025, Yao Yuan <yeaya@163.com>. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 *
 * This code is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License version 2 only, as
 * published by the Free Software Foundation.  This file as subject to the
 * "Classpath" exception in the LICENSE file that accompanied this code.
 *
 * This code is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
 * version 2 for more details (a copy is included in the LICENSE file that
 * accompanied this code).
 *
 * You should have received a copy of the GNU General Public License version
 * 2 along with this work; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA.
 */

#include "jvm.h"
#include "interfaceSupport.h"
#include "JavaThread.h"
#include <signal.h>

JVM_LEAF(void*, JVM_GetThreadInterruptEvent())
	return JavaThread::sureCurrentThread()->getOsThread()->getInterruptEvent();
JVM_LEAF_END

JVM_ENTRY(void*, JVM_RegisterSignal(jint sig, void* handler))
	void* newHandler = (handler == (void*)2) ? OS::getUserHandler() : handler;
	switch (sig) {
	case SIGFPE:
		return (void*)-1;
	case SIGBREAK:
		return (void*)-1;

	case SHUTDOWN1_SIGNAL:
	case SHUTDOWN2_SIGNAL:
		break;
	}

	void* oldHandler = OS::signal(sig, newHandler);
	if (oldHandler == OS::getUserHandler()) {
		return (void*)2;
	} else {
		return oldHandler;
	}
JVM_END(nullptr)

JVM_ENTRY(jboolean, JVM_RaiseSignal(jint sig))
	OS::raiseSignal(sig);
	return JNI_TRUE;
JVM_END(JNI_FALSE)