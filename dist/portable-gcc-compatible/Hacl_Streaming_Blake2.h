/* MIT License
 *
 * Copyright (c) 2016-2020 INRIA, CMU and Microsoft Corporation
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */


#ifndef __Hacl_Streaming_Blake2_H
#define __Hacl_Streaming_Blake2_H

#if defined(__cplusplus)
extern "C" {
#endif

#include "evercrypt_targetconfig.h"
#include "libintvector.h"
#include "kremlin/internal/types.h"
#include "kremlin/lowstar_endianness.h"
#include <string.h>
#include "kremlin/internal/target.h"


#include "Hacl_Kremlib.h"
#include "Hacl_Spec.h"
#include "Hacl_Hash_Blake2.h"

/* SNIPPET_START: Hacl_Streaming_Blake2_blocks_state_len */

uint32_t
Hacl_Streaming_Blake2_blocks_state_len(Spec_Blake2_alg a, Hacl_Impl_Blake2_Core_m_spec m);

/* SNIPPET_END: Hacl_Streaming_Blake2_blocks_state_len */

/* SNIPPET_START: Hacl_Streaming_Blake2_blake2s_32_block_state */

typedef struct Hacl_Streaming_Blake2_blake2s_32_block_state_s
{
  uint32_t *fst;
  uint32_t *snd;
}
Hacl_Streaming_Blake2_blake2s_32_block_state;

/* SNIPPET_END: Hacl_Streaming_Blake2_blake2s_32_block_state */

/* SNIPPET_START: Hacl_Streaming_Blake2_blake2s_32_state */

typedef struct Hacl_Streaming_Blake2_blake2s_32_state_s
{
  Hacl_Streaming_Blake2_blake2s_32_block_state block_state;
  uint8_t *buf;
  uint64_t total_len;
}
Hacl_Streaming_Blake2_blake2s_32_state;

/* SNIPPET_END: Hacl_Streaming_Blake2_blake2s_32_state */

/* SNIPPET_START: Hacl_Streaming_Blake2_blake2s_32_no_key_create_in */

/*
  State allocation function when there is no key
*/
Hacl_Streaming_Blake2_blake2s_32_state *Hacl_Streaming_Blake2_blake2s_32_no_key_create_in();

/* SNIPPET_END: Hacl_Streaming_Blake2_blake2s_32_no_key_create_in */

/* SNIPPET_START: Hacl_Streaming_Blake2_blake2s_32_no_key_init */

/*
  (Re-)initialization function when there is no key
*/
void Hacl_Streaming_Blake2_blake2s_32_no_key_init(Hacl_Streaming_Blake2_blake2s_32_state *s1);

/* SNIPPET_END: Hacl_Streaming_Blake2_blake2s_32_no_key_init */

/* SNIPPET_START: Hacl_Streaming_Blake2_blake2s_32_no_key_update */

/*
  Update function when there is no key
*/
void
Hacl_Streaming_Blake2_blake2s_32_no_key_update(
  Hacl_Streaming_Blake2_blake2s_32_state *p,
  uint8_t *data,
  uint32_t len
);

/* SNIPPET_END: Hacl_Streaming_Blake2_blake2s_32_no_key_update */

/* SNIPPET_START: Hacl_Streaming_Blake2_blake2s_32_no_key_finish */

/*
  Finish function when there is no key
*/
void
Hacl_Streaming_Blake2_blake2s_32_no_key_finish(
  Hacl_Streaming_Blake2_blake2s_32_state *p,
  uint8_t *dst
);

/* SNIPPET_END: Hacl_Streaming_Blake2_blake2s_32_no_key_finish */

/* SNIPPET_START: Hacl_Streaming_Blake2_blake2s_32_no_key_free */

/*
  Free state function when there is no key
*/
void Hacl_Streaming_Blake2_blake2s_32_no_key_free(Hacl_Streaming_Blake2_blake2s_32_state *s1);

/* SNIPPET_END: Hacl_Streaming_Blake2_blake2s_32_no_key_free */

/* SNIPPET_START: Hacl_Streaming_Blake2_blake2b_32_block_state */

typedef struct Hacl_Streaming_Blake2_blake2b_32_block_state_s
{
  uint64_t *fst;
  uint64_t *snd;
}
Hacl_Streaming_Blake2_blake2b_32_block_state;

/* SNIPPET_END: Hacl_Streaming_Blake2_blake2b_32_block_state */

/* SNIPPET_START: Hacl_Streaming_Blake2_blake2b_32_state */

typedef struct Hacl_Streaming_Blake2_blake2b_32_state_s
{
  Hacl_Streaming_Blake2_blake2b_32_block_state block_state;
  uint8_t *buf;
  uint64_t total_len;
}
Hacl_Streaming_Blake2_blake2b_32_state;

/* SNIPPET_END: Hacl_Streaming_Blake2_blake2b_32_state */

/* SNIPPET_START: Hacl_Streaming_Blake2_blake2b_32_no_key_create_in */

/*
  State allocation function when there is no key
*/
Hacl_Streaming_Blake2_blake2b_32_state *Hacl_Streaming_Blake2_blake2b_32_no_key_create_in();

/* SNIPPET_END: Hacl_Streaming_Blake2_blake2b_32_no_key_create_in */

/* SNIPPET_START: Hacl_Streaming_Blake2_blake2b_32_no_key_init */

/*
  (Re)-initialization function when there is no key
*/
void Hacl_Streaming_Blake2_blake2b_32_no_key_init(Hacl_Streaming_Blake2_blake2b_32_state *s1);

/* SNIPPET_END: Hacl_Streaming_Blake2_blake2b_32_no_key_init */

/* SNIPPET_START: Hacl_Streaming_Blake2_blake2b_32_no_key_update */

/*
  Update function when there is no key
*/
void
Hacl_Streaming_Blake2_blake2b_32_no_key_update(
  Hacl_Streaming_Blake2_blake2b_32_state *p,
  uint8_t *data,
  uint32_t len
);

/* SNIPPET_END: Hacl_Streaming_Blake2_blake2b_32_no_key_update */

/* SNIPPET_START: Hacl_Streaming_Blake2_blake2b_32_no_key_finish */

/*
  Finish function when there is no key
*/
void
Hacl_Streaming_Blake2_blake2b_32_no_key_finish(
  Hacl_Streaming_Blake2_blake2b_32_state *p,
  uint8_t *dst
);

/* SNIPPET_END: Hacl_Streaming_Blake2_blake2b_32_no_key_finish */

/* SNIPPET_START: Hacl_Streaming_Blake2_blake2b_32_no_key_free */

/*
  Free state function when there is no key
*/
void Hacl_Streaming_Blake2_blake2b_32_no_key_free(Hacl_Streaming_Blake2_blake2b_32_state *s1);

/* SNIPPET_END: Hacl_Streaming_Blake2_blake2b_32_no_key_free */

/* SNIPPET_START: Hacl_Streaming_Blake2_blake2s_32_with_key_create_in */

/*
  State allocation function when using a (potentially null) key
*/
Hacl_Streaming_Blake2_blake2s_32_state
*Hacl_Streaming_Blake2_blake2s_32_with_key_create_in(uint32_t key_size, uint8_t *k1);

/* SNIPPET_END: Hacl_Streaming_Blake2_blake2s_32_with_key_create_in */

/* SNIPPET_START: Hacl_Streaming_Blake2_blake2s_32_with_key_init */

/*
  (Re-)initialization function when using a (potentially null) key
*/
void
Hacl_Streaming_Blake2_blake2s_32_with_key_init(
  uint32_t key_size,
  uint8_t *k1,
  Hacl_Streaming_Blake2_blake2s_32_state *s1
);

/* SNIPPET_END: Hacl_Streaming_Blake2_blake2s_32_with_key_init */

/* SNIPPET_START: Hacl_Streaming_Blake2_blake2s_32_with_key_update */

/*
  Update function when using a (potentially null) key
*/
void
Hacl_Streaming_Blake2_blake2s_32_with_key_update(
  uint32_t key_size,
  Hacl_Streaming_Blake2_blake2s_32_state *p,
  uint8_t *data,
  uint32_t len
);

/* SNIPPET_END: Hacl_Streaming_Blake2_blake2s_32_with_key_update */

/* SNIPPET_START: Hacl_Streaming_Blake2_blake2s_32_with_key_finish */

/*
  Finish function when using a (potentially null) key
*/
void
Hacl_Streaming_Blake2_blake2s_32_with_key_finish(
  uint32_t key_size,
  Hacl_Streaming_Blake2_blake2s_32_state *p,
  uint8_t *dst
);

/* SNIPPET_END: Hacl_Streaming_Blake2_blake2s_32_with_key_finish */

/* SNIPPET_START: Hacl_Streaming_Blake2_blake2s_32_with_key_free */

/*
  Free state function when using a (potentially null) key
*/
void
Hacl_Streaming_Blake2_blake2s_32_with_key_free(
  uint32_t key_size,
  Hacl_Streaming_Blake2_blake2s_32_state *s1
);

/* SNIPPET_END: Hacl_Streaming_Blake2_blake2s_32_with_key_free */

/* SNIPPET_START: Hacl_Streaming_Blake2_blake2b_32_with_key_create_in */

/*
  State allocation function when using a (potentially null) key
*/
Hacl_Streaming_Blake2_blake2b_32_state
*Hacl_Streaming_Blake2_blake2b_32_with_key_create_in(uint32_t key_size, uint8_t *k1);

/* SNIPPET_END: Hacl_Streaming_Blake2_blake2b_32_with_key_create_in */

/* SNIPPET_START: Hacl_Streaming_Blake2_blake2b_32_with_key_init */

/*
  (Re-)initialization function when using a (potentially null) key
*/
void
Hacl_Streaming_Blake2_blake2b_32_with_key_init(
  uint32_t key_size,
  uint8_t *k1,
  Hacl_Streaming_Blake2_blake2b_32_state *s1
);

/* SNIPPET_END: Hacl_Streaming_Blake2_blake2b_32_with_key_init */

/* SNIPPET_START: Hacl_Streaming_Blake2_blake2b_32_with_key_update */

/*
  Update function when using a (potentially null) key
*/
void
Hacl_Streaming_Blake2_blake2b_32_with_key_update(
  uint32_t key_size,
  Hacl_Streaming_Blake2_blake2b_32_state *p,
  uint8_t *data,
  uint32_t len
);

/* SNIPPET_END: Hacl_Streaming_Blake2_blake2b_32_with_key_update */

/* SNIPPET_START: Hacl_Streaming_Blake2_blake2b_32_with_key_finish */

/*
  Finish function when using a (potentially null) key
*/
void
Hacl_Streaming_Blake2_blake2b_32_with_key_finish(
  uint32_t key_size,
  Hacl_Streaming_Blake2_blake2b_32_state *p,
  uint8_t *dst
);

/* SNIPPET_END: Hacl_Streaming_Blake2_blake2b_32_with_key_finish */

/* SNIPPET_START: Hacl_Streaming_Blake2_blake2b_32_with_key_free */

/*
  Free state function when using a (potentially null) key
*/
void
Hacl_Streaming_Blake2_blake2b_32_with_key_free(
  uint32_t key_size,
  Hacl_Streaming_Blake2_blake2b_32_state *s1
);

/* SNIPPET_END: Hacl_Streaming_Blake2_blake2b_32_with_key_free */

#if defined(__cplusplus)
}
#endif

#define __Hacl_Streaming_Blake2_H_DEFINED
#endif
