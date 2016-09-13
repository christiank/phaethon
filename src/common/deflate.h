/* xoreos-tools - Tools to help with xoreos development
 *
 * xoreos-tools is the legal property of its developers, whose names
 * can be found in the AUTHORS file distributed with this source
 * distribution.
 *
 * xoreos-tools is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 3
 * of the License, or (at your option) any later version.
 *
 * xoreos-tools is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with xoreos-tools. If not, see <http://www.gnu.org/licenses/>.
 */

/** @file
 *  Compress (deflate) and decompress (inflate) using zlib's DEFLATE algorithm.
 */

#ifndef COMMON_DEFLATE_H
#define COMMON_DEFLATE_H

#include "src/common/types.h"

namespace Common {

/* TODO (should be need it):
 * - Compression
 * - Decompress dynamically, without needing to know the size
 *   of the decompressed data beforehand
 */

class ReadStream;
class SeekableReadStream;

static const int kWindowBitsMax    =  15;
static const int kWindowBitsMaxRaw = -kWindowBitsMax;

/** Decompress (inflate) using zlib's DEFLATE algorithm.
 *
 *  @param  data       The compressed input data.
 *  @param  inputSize  The size of the input data in bytes.
 *  @param  outputSize The size of the decompressed output data.
 *                     It is assumed that this information is known and that
 *                     the whole decompressed data will fit into a buffer of
 *                     this size.
 *  @param windowBits  The base two logarithm of the window size (the size of
 *                     the history buffer). See the zlib documentation on
 *                     inflateInit2() for details.
 *  @return The decompressed data.
 */
byte *decompressDeflate(const byte *data, size_t inputSize,
                        size_t outputSize, int windowBits);

/** Decompress (inflate) using zlib's DEFLATE algorithm.
 *
 *  @param  stream     The compressed input data.
 *  @param  inputSize  The size of the input data to read in bytes.
 *  @param  outputSize The size of the decompressed output data.
 *                     It is assumed that this information is known and that
 *                     the whole decompressed data will fit into a buffer of
 *                     this size.
 *  @param windowBits  The base two logarithm of the window size (the size of
 *                     the history buffer). See the zlib documentation on
 *                     inflateInit2() for details.
 *  @return A stream of the decompressed data.
 */
SeekableReadStream *decompressDeflate(ReadStream &input, size_t inputSize,
                                      size_t outputSize, int windowBits);

} // End of namespace Common

#endif // COMMON_DEFLATE_H
