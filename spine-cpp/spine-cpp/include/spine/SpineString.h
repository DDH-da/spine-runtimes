/******************************************************************************
 * Spine Runtimes License Agreement
 * Last updated April 5, 2025. Replaces all prior versions.
 *
 * Copyright (c) 2013-2025, Esoteric Software LLC
 *
 * Integration of the Spine Runtimes into software or otherwise creating
 * derivative works of the Spine Runtimes is permitted under the terms and
 * conditions of Section 2 of the Spine Editor License Agreement:
 * http://esotericsoftware.com/spine-editor-license
 *
 * Otherwise, it is permitted to integrate the Spine Runtimes into software
 * or otherwise create derivative works of the Spine Runtimes (collectively,
 * "Products"), provided that each user of the Products must obtain their own
 * Spine Editor license and redistribution of the Products in any form must
 * include this license and copyright notice.
 *
 * THE SPINE RUNTIMES ARE PROVIDED BY ESOTERIC SOFTWARE LLC "AS IS" AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL ESOTERIC SOFTWARE LLC BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES,
 * BUSINESS INTERRUPTION, OR LOSS OF USE, DATA, OR PROFITS) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THE
 * SPINE RUNTIMES, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *****************************************************************************/

#pragma once

#include <spine/Extension.h>
#include <spine/SpineObject.h>
#include <spine/dll.h>

#include <cstring>
#include <string>

namespace spine {

class SPINE_API SpineString : public SpineObject {
public:
	SpineString() : _data("") {}

	SpineString(const char *chars) : _data(chars ? chars : "") {}

	SpineString(const char *chars, size_t length) : _data(chars ? std::string(chars, length) : "") {}

	SpineString(const std::string &other) : _data(other) {}

	SpineString(const SpineString &other) : _data(other._data) {}

	SpineString(SpineString &&other) noexcept : _data(std::move(other._data)) {}

	~SpineString() {}

	SpineString &operator=(const char *chars) {
		_data = chars ? chars : "";
		return *this;
	}

	SpineString &operator=(const std::string &other) {
		_data = other;
		return *this;
	}

	SpineString &operator=(const SpineString &other) {
		_data = other._data;
		return *this;
	}

	SpineString &operator=(SpineString &&other) noexcept {
		_data = std::move(other._data);
		return *this;
	}

	bool operator==(const char *chars) const {
		if (!chars) return _data.empty();
		return _data == chars;
	}

	bool operator==(const std::string &other) const {
		return _data == other;
	}

	bool operator==(const SpineString &other) const {
		return _data == other._data;
	}

	bool operator!=(const char *chars) const {
		return !(*this == chars);
	}

	bool operator!=(const std::string &other) const {
		return _data != other;
	}

	bool operator!=(const SpineString &other) const {
		return _data != other._data;
	}

	bool operator<(const SpineString &other) const {
		return _data < other._data;
	}

	SpineString operator+(const SpineString &other) const {
		return SpineString(_data + other._data);
	}

	SpineString &operator+=(const SpineString &other) {
		_data += other._data;
		return *this;
	}

	operator const std::string &() const {
		return _data;
	}

	const char *buffer() const {
		return _data.c_str();
	}

	size_t length() const {
		return _data.length();
	}

	bool empty() const {
		return _data.empty();
	}

private:
	std::string _data;
};

} // namespace spine
