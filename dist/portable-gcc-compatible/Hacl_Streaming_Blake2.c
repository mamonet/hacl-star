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


#include "Hacl_Streaming_Blake2.h"

/* SNIPPET_START: Hacl_Streaming_Functor_state_s__K____uint32_t___uint32_t____ */

typedef struct Hacl_Streaming_Functor_state_s__K____uint32_t___uint32_t_____s
{
  K____uint32_t___uint32_t_ block_state;
  uint8_t *buf;
  uint64_t total_len;
}
Hacl_Streaming_Functor_state_s__K____uint32_t___uint32_t____;

/* SNIPPET_END: Hacl_Streaming_Functor_state_s__K____uint32_t___uint32_t____ */

/* SNIPPET_START: Hacl_Streaming_Blake2_blake2s_32_no_key_create_in */

/*
  State allocation function when there is no key
*/
Hacl_Streaming_Functor_state_s__K____uint32_t___uint32_t____
*Hacl_Streaming_Blake2_blake2s_32_no_key_create_in()
{
  uint8_t *buf = KRML_HOST_CALLOC((uint32_t)64U, sizeof (uint8_t));
  uint32_t *wv = KRML_HOST_CALLOC((uint32_t)16U, sizeof (uint32_t));
  uint32_t *b0 = KRML_HOST_CALLOC((uint32_t)16U, sizeof (uint32_t));
  K____uint32_t___uint32_t_ block_state = { .fst = wv, .snd = b0 };
  Hacl_Streaming_Functor_state_s__K____uint32_t___uint32_t____
  s1 = { .block_state = block_state, .buf = buf, .total_len = (uint64_t)0U };
  KRML_CHECK_SIZE(sizeof (Hacl_Streaming_Functor_state_s__K____uint32_t___uint32_t____),
    (uint32_t)1U);
  Hacl_Streaming_Functor_state_s__K____uint32_t___uint32_t____
  *p = KRML_HOST_MALLOC(sizeof (Hacl_Streaming_Functor_state_s__K____uint32_t___uint32_t____));
  p[0U] = s1;
  uint8_t b[64U] = { 0U };
  uint32_t *r00 = block_state.snd + (uint32_t)0U * (uint32_t)4U;
  uint32_t *r10 = block_state.snd + (uint32_t)1U * (uint32_t)4U;
  uint32_t *r20 = block_state.snd + (uint32_t)2U * (uint32_t)4U;
  uint32_t *r30 = block_state.snd + (uint32_t)3U * (uint32_t)4U;
  uint32_t iv0 = Hacl_Impl_Blake2_Constants_ivTable_S[0U];
  uint32_t iv1 = Hacl_Impl_Blake2_Constants_ivTable_S[1U];
  uint32_t iv2 = Hacl_Impl_Blake2_Constants_ivTable_S[2U];
  uint32_t iv3 = Hacl_Impl_Blake2_Constants_ivTable_S[3U];
  uint32_t iv4 = Hacl_Impl_Blake2_Constants_ivTable_S[4U];
  uint32_t iv5 = Hacl_Impl_Blake2_Constants_ivTable_S[5U];
  uint32_t iv6 = Hacl_Impl_Blake2_Constants_ivTable_S[6U];
  uint32_t iv7 = Hacl_Impl_Blake2_Constants_ivTable_S[7U];
  r20[0U] = iv0;
  r20[1U] = iv1;
  r20[2U] = iv2;
  r20[3U] = iv3;
  r30[0U] = iv4;
  r30[1U] = iv5;
  r30[2U] = iv6;
  r30[3U] = iv7;
  uint32_t kk_shift_8 = (uint32_t)0U;
  uint32_t iv0_ = iv0 ^ ((uint32_t)0x01010000U ^ (kk_shift_8 ^ (uint32_t)32U));
  r00[0U] = iv0_;
  r00[1U] = iv1;
  r00[2U] = iv2;
  r00[3U] = iv3;
  r10[0U] = iv4;
  r10[1U] = iv5;
  r10[2U] = iv6;
  r10[3U] = iv7;
  if (!((uint32_t)0U == (uint32_t)0U))
  {
    memcpy(b, NULL, (uint32_t)0U * sizeof (NULL[0U]));
    uint64_t totlen = (uint64_t)(uint32_t)0U + (uint64_t)(uint32_t)64U;
    uint8_t *b1 = b + (uint32_t)0U * (uint32_t)64U;
    uint32_t m_w[16U] = { 0U };
    for (uint32_t i = (uint32_t)0U; i < (uint32_t)16U; i++)
    {
      uint32_t *os = m_w;
      uint8_t *bj = b1 + i * (uint32_t)4U;
      uint32_t u = load32_le(bj);
      uint32_t r1 = u;
      uint32_t x = r1;
      os[i] = x;
    }
    uint32_t mask[4U] = { 0U };
    uint32_t wv_14 = (uint32_t)0U;
    uint32_t wv_15 = (uint32_t)0U;
    mask[0U] = (uint32_t)totlen;
    mask[1U] = (uint32_t)(totlen >> (uint32_t)32U);
    mask[2U] = wv_14;
    mask[3U] = wv_15;
    memcpy(block_state.fst,
      block_state.snd,
      (uint32_t)4U * (uint32_t)4U * sizeof (block_state.snd[0U]));
    uint32_t *wv3 = block_state.fst + (uint32_t)3U * (uint32_t)4U;
    for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
    {
      uint32_t *os = wv3;
      uint32_t x = wv3[i] ^ mask[i];
      os[i] = x;
    }
    for (uint32_t i0 = (uint32_t)0U; i0 < (uint32_t)10U; i0++)
    {
      uint32_t start_idx = i0 % (uint32_t)10U * (uint32_t)16U;
      KRML_CHECK_SIZE(sizeof (uint32_t), (uint32_t)4U * (uint32_t)4U);
      uint32_t m_st[(uint32_t)4U * (uint32_t)4U];
      memset(m_st, 0U, (uint32_t)4U * (uint32_t)4U * sizeof (m_st[0U]));
      uint32_t *r01 = m_st + (uint32_t)0U * (uint32_t)4U;
      uint32_t *r12 = m_st + (uint32_t)1U * (uint32_t)4U;
      uint32_t *r21 = m_st + (uint32_t)2U * (uint32_t)4U;
      uint32_t *r31 = m_st + (uint32_t)3U * (uint32_t)4U;
      uint32_t s0 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx];
      uint32_t s11 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)1U];
      uint32_t s2 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)2U];
      uint32_t s3 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)3U];
      uint32_t s4 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)4U];
      uint32_t s5 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)5U];
      uint32_t s6 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)6U];
      uint32_t s7 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)7U];
      uint32_t s8 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)8U];
      uint32_t s9 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)9U];
      uint32_t s10 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)10U];
      uint32_t s111 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)11U];
      uint32_t s12 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)12U];
      uint32_t s13 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)13U];
      uint32_t s14 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)14U];
      uint32_t s15 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)15U];
      uint32_t uu____0 = m_w[s2];
      uint32_t uu____1 = m_w[s4];
      uint32_t uu____2 = m_w[s6];
      r01[0U] = m_w[s0];
      r01[1U] = uu____0;
      r01[2U] = uu____1;
      r01[3U] = uu____2;
      uint32_t uu____3 = m_w[s3];
      uint32_t uu____4 = m_w[s5];
      uint32_t uu____5 = m_w[s7];
      r12[0U] = m_w[s11];
      r12[1U] = uu____3;
      r12[2U] = uu____4;
      r12[3U] = uu____5;
      uint32_t uu____6 = m_w[s10];
      uint32_t uu____7 = m_w[s12];
      uint32_t uu____8 = m_w[s14];
      r21[0U] = m_w[s8];
      r21[1U] = uu____6;
      r21[2U] = uu____7;
      r21[3U] = uu____8;
      uint32_t uu____9 = m_w[s111];
      uint32_t uu____10 = m_w[s13];
      uint32_t uu____11 = m_w[s15];
      r31[0U] = m_w[s9];
      r31[1U] = uu____9;
      r31[2U] = uu____10;
      r31[3U] = uu____11;
      uint32_t *x = m_st + (uint32_t)0U * (uint32_t)4U;
      uint32_t *y = m_st + (uint32_t)1U * (uint32_t)4U;
      uint32_t *z = m_st + (uint32_t)2U * (uint32_t)4U;
      uint32_t *w = m_st + (uint32_t)3U * (uint32_t)4U;
      uint32_t a = (uint32_t)0U;
      uint32_t b20 = (uint32_t)1U;
      uint32_t c0 = (uint32_t)2U;
      uint32_t d0 = (uint32_t)3U;
      uint32_t r02 = Hacl_Impl_Blake2_Constants_rTable_S[0U];
      uint32_t r13 = Hacl_Impl_Blake2_Constants_rTable_S[1U];
      uint32_t r22 = Hacl_Impl_Blake2_Constants_rTable_S[2U];
      uint32_t r32 = Hacl_Impl_Blake2_Constants_rTable_S[3U];
      uint32_t *wv_a0 = block_state.fst + a * (uint32_t)4U;
      uint32_t *wv_b0 = block_state.fst + b20 * (uint32_t)4U;
      for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
      {
        uint32_t *os = wv_a0;
        uint32_t x1 = wv_a0[i] + wv_b0[i];
        os[i] = x1;
      }
      for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
      {
        uint32_t *os = wv_a0;
        uint32_t x1 = wv_a0[i] + x[i];
        os[i] = x1;
      }
      uint32_t *wv_a1 = block_state.fst + d0 * (uint32_t)4U;
      uint32_t *wv_b1 = block_state.fst + a * (uint32_t)4U;
      for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
      {
        uint32_t *os = wv_a1;
        uint32_t x1 = wv_a1[i] ^ wv_b1[i];
        os[i] = x1;
      }
      uint32_t *r110 = wv_a1;
      for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
      {
        uint32_t *os = r110;
        uint32_t x1 = r110[i];
        uint32_t x10 = x1 >> r02 | x1 << ((uint32_t)32U - r02);
        os[i] = x10;
      }
      uint32_t *wv_a2 = block_state.fst + c0 * (uint32_t)4U;
      uint32_t *wv_b2 = block_state.fst + d0 * (uint32_t)4U;
      for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
      {
        uint32_t *os = wv_a2;
        uint32_t x1 = wv_a2[i] + wv_b2[i];
        os[i] = x1;
      }
      uint32_t *wv_a3 = block_state.fst + b20 * (uint32_t)4U;
      uint32_t *wv_b3 = block_state.fst + c0 * (uint32_t)4U;
      for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
      {
        uint32_t *os = wv_a3;
        uint32_t x1 = wv_a3[i] ^ wv_b3[i];
        os[i] = x1;
      }
      uint32_t *r111 = wv_a3;
      for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
      {
        uint32_t *os = r111;
        uint32_t x1 = r111[i];
        uint32_t x10 = x1 >> r13 | x1 << ((uint32_t)32U - r13);
        os[i] = x10;
      }
      uint32_t *wv_a4 = block_state.fst + a * (uint32_t)4U;
      uint32_t *wv_b4 = block_state.fst + b20 * (uint32_t)4U;
      for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
      {
        uint32_t *os = wv_a4;
        uint32_t x1 = wv_a4[i] + wv_b4[i];
        os[i] = x1;
      }
      for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
      {
        uint32_t *os = wv_a4;
        uint32_t x1 = wv_a4[i] + y[i];
        os[i] = x1;
      }
      uint32_t *wv_a5 = block_state.fst + d0 * (uint32_t)4U;
      uint32_t *wv_b5 = block_state.fst + a * (uint32_t)4U;
      for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
      {
        uint32_t *os = wv_a5;
        uint32_t x1 = wv_a5[i] ^ wv_b5[i];
        os[i] = x1;
      }
      uint32_t *r112 = wv_a5;
      for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
      {
        uint32_t *os = r112;
        uint32_t x1 = r112[i];
        uint32_t x10 = x1 >> r22 | x1 << ((uint32_t)32U - r22);
        os[i] = x10;
      }
      uint32_t *wv_a6 = block_state.fst + c0 * (uint32_t)4U;
      uint32_t *wv_b6 = block_state.fst + d0 * (uint32_t)4U;
      for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
      {
        uint32_t *os = wv_a6;
        uint32_t x1 = wv_a6[i] + wv_b6[i];
        os[i] = x1;
      }
      uint32_t *wv_a7 = block_state.fst + b20 * (uint32_t)4U;
      uint32_t *wv_b7 = block_state.fst + c0 * (uint32_t)4U;
      for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
      {
        uint32_t *os = wv_a7;
        uint32_t x1 = wv_a7[i] ^ wv_b7[i];
        os[i] = x1;
      }
      uint32_t *r113 = wv_a7;
      for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
      {
        uint32_t *os = r113;
        uint32_t x1 = r113[i];
        uint32_t x10 = x1 >> r32 | x1 << ((uint32_t)32U - r32);
        os[i] = x10;
      }
      uint32_t *r14 = block_state.fst + (uint32_t)1U * (uint32_t)4U;
      uint32_t *r23 = block_state.fst + (uint32_t)2U * (uint32_t)4U;
      uint32_t *r33 = block_state.fst + (uint32_t)3U * (uint32_t)4U;
      uint32_t *r114 = r14;
      uint32_t x00 = r114[1U];
      uint32_t x10 = r114[((uint32_t)1U + (uint32_t)1U) % (uint32_t)4U];
      uint32_t x20 = r114[((uint32_t)1U + (uint32_t)2U) % (uint32_t)4U];
      uint32_t x30 = r114[((uint32_t)1U + (uint32_t)3U) % (uint32_t)4U];
      r114[0U] = x00;
      r114[1U] = x10;
      r114[2U] = x20;
      r114[3U] = x30;
      uint32_t *r115 = r23;
      uint32_t x01 = r115[2U];
      uint32_t x11 = r115[((uint32_t)2U + (uint32_t)1U) % (uint32_t)4U];
      uint32_t x21 = r115[((uint32_t)2U + (uint32_t)2U) % (uint32_t)4U];
      uint32_t x31 = r115[((uint32_t)2U + (uint32_t)3U) % (uint32_t)4U];
      r115[0U] = x01;
      r115[1U] = x11;
      r115[2U] = x21;
      r115[3U] = x31;
      uint32_t *r116 = r33;
      uint32_t x02 = r116[3U];
      uint32_t x12 = r116[((uint32_t)3U + (uint32_t)1U) % (uint32_t)4U];
      uint32_t x22 = r116[((uint32_t)3U + (uint32_t)2U) % (uint32_t)4U];
      uint32_t x32 = r116[((uint32_t)3U + (uint32_t)3U) % (uint32_t)4U];
      r116[0U] = x02;
      r116[1U] = x12;
      r116[2U] = x22;
      r116[3U] = x32;
      uint32_t a0 = (uint32_t)0U;
      uint32_t b2 = (uint32_t)1U;
      uint32_t c = (uint32_t)2U;
      uint32_t d = (uint32_t)3U;
      uint32_t r0 = Hacl_Impl_Blake2_Constants_rTable_S[0U];
      uint32_t r1 = Hacl_Impl_Blake2_Constants_rTable_S[1U];
      uint32_t r24 = Hacl_Impl_Blake2_Constants_rTable_S[2U];
      uint32_t r34 = Hacl_Impl_Blake2_Constants_rTable_S[3U];
      uint32_t *wv_a = block_state.fst + a0 * (uint32_t)4U;
      uint32_t *wv_b8 = block_state.fst + b2 * (uint32_t)4U;
      for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
      {
        uint32_t *os = wv_a;
        uint32_t x1 = wv_a[i] + wv_b8[i];
        os[i] = x1;
      }
      for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
      {
        uint32_t *os = wv_a;
        uint32_t x1 = wv_a[i] + z[i];
        os[i] = x1;
      }
      uint32_t *wv_a8 = block_state.fst + d * (uint32_t)4U;
      uint32_t *wv_b9 = block_state.fst + a0 * (uint32_t)4U;
      for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
      {
        uint32_t *os = wv_a8;
        uint32_t x1 = wv_a8[i] ^ wv_b9[i];
        os[i] = x1;
      }
      uint32_t *r117 = wv_a8;
      for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
      {
        uint32_t *os = r117;
        uint32_t x1 = r117[i];
        uint32_t x13 = x1 >> r0 | x1 << ((uint32_t)32U - r0);
        os[i] = x13;
      }
      uint32_t *wv_a9 = block_state.fst + c * (uint32_t)4U;
      uint32_t *wv_b10 = block_state.fst + d * (uint32_t)4U;
      for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
      {
        uint32_t *os = wv_a9;
        uint32_t x1 = wv_a9[i] + wv_b10[i];
        os[i] = x1;
      }
      uint32_t *wv_a10 = block_state.fst + b2 * (uint32_t)4U;
      uint32_t *wv_b11 = block_state.fst + c * (uint32_t)4U;
      for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
      {
        uint32_t *os = wv_a10;
        uint32_t x1 = wv_a10[i] ^ wv_b11[i];
        os[i] = x1;
      }
      uint32_t *r118 = wv_a10;
      for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
      {
        uint32_t *os = r118;
        uint32_t x1 = r118[i];
        uint32_t x13 = x1 >> r1 | x1 << ((uint32_t)32U - r1);
        os[i] = x13;
      }
      uint32_t *wv_a11 = block_state.fst + a0 * (uint32_t)4U;
      uint32_t *wv_b12 = block_state.fst + b2 * (uint32_t)4U;
      for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
      {
        uint32_t *os = wv_a11;
        uint32_t x1 = wv_a11[i] + wv_b12[i];
        os[i] = x1;
      }
      for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
      {
        uint32_t *os = wv_a11;
        uint32_t x1 = wv_a11[i] + w[i];
        os[i] = x1;
      }
      uint32_t *wv_a12 = block_state.fst + d * (uint32_t)4U;
      uint32_t *wv_b13 = block_state.fst + a0 * (uint32_t)4U;
      for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
      {
        uint32_t *os = wv_a12;
        uint32_t x1 = wv_a12[i] ^ wv_b13[i];
        os[i] = x1;
      }
      uint32_t *r119 = wv_a12;
      for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
      {
        uint32_t *os = r119;
        uint32_t x1 = r119[i];
        uint32_t x13 = x1 >> r24 | x1 << ((uint32_t)32U - r24);
        os[i] = x13;
      }
      uint32_t *wv_a13 = block_state.fst + c * (uint32_t)4U;
      uint32_t *wv_b14 = block_state.fst + d * (uint32_t)4U;
      for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
      {
        uint32_t *os = wv_a13;
        uint32_t x1 = wv_a13[i] + wv_b14[i];
        os[i] = x1;
      }
      uint32_t *wv_a14 = block_state.fst + b2 * (uint32_t)4U;
      uint32_t *wv_b = block_state.fst + c * (uint32_t)4U;
      for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
      {
        uint32_t *os = wv_a14;
        uint32_t x1 = wv_a14[i] ^ wv_b[i];
        os[i] = x1;
      }
      uint32_t *r1110 = wv_a14;
      for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
      {
        uint32_t *os = r1110;
        uint32_t x1 = r1110[i];
        uint32_t x13 = x1 >> r34 | x1 << ((uint32_t)32U - r34);
        os[i] = x13;
      }
      uint32_t *r15 = block_state.fst + (uint32_t)1U * (uint32_t)4U;
      uint32_t *r2 = block_state.fst + (uint32_t)2U * (uint32_t)4U;
      uint32_t *r3 = block_state.fst + (uint32_t)3U * (uint32_t)4U;
      uint32_t *r11 = r15;
      uint32_t x03 = r11[3U];
      uint32_t x13 = r11[((uint32_t)3U + (uint32_t)1U) % (uint32_t)4U];
      uint32_t x23 = r11[((uint32_t)3U + (uint32_t)2U) % (uint32_t)4U];
      uint32_t x33 = r11[((uint32_t)3U + (uint32_t)3U) % (uint32_t)4U];
      r11[0U] = x03;
      r11[1U] = x13;
      r11[2U] = x23;
      r11[3U] = x33;
      uint32_t *r1111 = r2;
      uint32_t x04 = r1111[2U];
      uint32_t x14 = r1111[((uint32_t)2U + (uint32_t)1U) % (uint32_t)4U];
      uint32_t x24 = r1111[((uint32_t)2U + (uint32_t)2U) % (uint32_t)4U];
      uint32_t x34 = r1111[((uint32_t)2U + (uint32_t)3U) % (uint32_t)4U];
      r1111[0U] = x04;
      r1111[1U] = x14;
      r1111[2U] = x24;
      r1111[3U] = x34;
      uint32_t *r1112 = r3;
      uint32_t x0 = r1112[1U];
      uint32_t x1 = r1112[((uint32_t)1U + (uint32_t)1U) % (uint32_t)4U];
      uint32_t x2 = r1112[((uint32_t)1U + (uint32_t)2U) % (uint32_t)4U];
      uint32_t x3 = r1112[((uint32_t)1U + (uint32_t)3U) % (uint32_t)4U];
      r1112[0U] = x0;
      r1112[1U] = x1;
      r1112[2U] = x2;
      r1112[3U] = x3;
    }
    uint32_t *s0 = block_state.snd + (uint32_t)0U * (uint32_t)4U;
    uint32_t *s11 = block_state.snd + (uint32_t)1U * (uint32_t)4U;
    uint32_t *r0 = block_state.fst + (uint32_t)0U * (uint32_t)4U;
    uint32_t *r1 = block_state.fst + (uint32_t)1U * (uint32_t)4U;
    uint32_t *r2 = block_state.fst + (uint32_t)2U * (uint32_t)4U;
    uint32_t *r3 = block_state.fst + (uint32_t)3U * (uint32_t)4U;
    for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
    {
      uint32_t *os = s0;
      uint32_t x = s0[i] ^ r0[i];
      os[i] = x;
    }
    for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
    {
      uint32_t *os = s0;
      uint32_t x = s0[i] ^ r2[i];
      os[i] = x;
    }
    for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
    {
      uint32_t *os = s11;
      uint32_t x = s11[i] ^ r1[i];
      os[i] = x;
    }
    for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
    {
      uint32_t *os = s11;
      uint32_t x = s11[i] ^ r3[i];
      os[i] = x;
    }
  }
  Lib_Memzero0_memzero(b, (uint32_t)64U * sizeof (b[0U]));
  return p;
}

/* SNIPPET_END: Hacl_Streaming_Blake2_blake2s_32_no_key_create_in */

/* SNIPPET_START: Hacl_Streaming_Blake2_blake2s_32_no_key_update */

/*
  Update function when there is no key
*/
void
Hacl_Streaming_Blake2_blake2s_32_no_key_update(
  Hacl_Streaming_Functor_state_s__K____uint32_t___uint32_t____ *p,
  uint8_t *data,
  uint32_t len
)
{
  Hacl_Streaming_Functor_state_s__K____uint32_t___uint32_t____ s1 = *p;
  uint64_t total_len = s1.total_len;
  uint32_t sz;
  if (total_len % (uint64_t)(uint32_t)64U == (uint64_t)0U && total_len > (uint64_t)0U)
  {
    sz = (uint32_t)64U;
  }
  else
  {
    sz = (uint32_t)(total_len % (uint64_t)(uint32_t)64U);
  }
  if (len <= (uint32_t)64U - sz)
  {
    Hacl_Streaming_Functor_state_s__K____uint32_t___uint32_t____ s2 = *p;
    K____uint32_t___uint32_t_ block_state1 = s2.block_state;
    uint8_t *buf = s2.buf;
    uint64_t total_len1 = s2.total_len;
    uint32_t sz1;
    if (total_len1 % (uint64_t)(uint32_t)64U == (uint64_t)0U && total_len1 > (uint64_t)0U)
    {
      sz1 = (uint32_t)64U;
    }
    else
    {
      sz1 = (uint32_t)(total_len1 % (uint64_t)(uint32_t)64U);
    }
    uint8_t *buf2 = buf + sz1;
    memcpy(buf2, data, len * sizeof (data[0U]));
    uint64_t total_len2 = total_len1 + (uint64_t)len;
    *p
    =
      (
        (Hacl_Streaming_Functor_state_s__K____uint32_t___uint32_t____){
          .block_state = block_state1,
          .buf = buf,
          .total_len = total_len2
        }
      );
    return;
  }
  if (sz == (uint32_t)0U)
  {
    Hacl_Streaming_Functor_state_s__K____uint32_t___uint32_t____ s2 = *p;
    K____uint32_t___uint32_t_ block_state1 = s2.block_state;
    uint8_t *buf = s2.buf;
    uint64_t total_len1 = s2.total_len;
    uint32_t sz1;
    if (total_len1 % (uint64_t)(uint32_t)64U == (uint64_t)0U && total_len1 > (uint64_t)0U)
    {
      sz1 = (uint32_t)64U;
    }
    else
    {
      sz1 = (uint32_t)(total_len1 % (uint64_t)(uint32_t)64U);
    }
    if (!(sz1 == (uint32_t)0U))
    {
      uint64_t prevlen = total_len1 - (uint64_t)sz1;
      uint32_t nb = (uint32_t)1U;
      for (uint32_t i0 = (uint32_t)0U; i0 < nb; i0++)
      {
        uint64_t ite;
        if ((uint32_t)0U == (uint32_t)0U)
        {
          ite = prevlen;
        }
        else
        {
          ite = prevlen + (uint64_t)(uint32_t)64U;
        }
        uint64_t totlen = ite + (uint64_t)((i0 + (uint32_t)1U) * (uint32_t)64U);
        uint8_t *b = buf + i0 * (uint32_t)64U;
        uint32_t m_w[16U] = { 0U };
        for (uint32_t i = (uint32_t)0U; i < (uint32_t)16U; i++)
        {
          uint32_t *os = m_w;
          uint8_t *bj = b + i * (uint32_t)4U;
          uint32_t u = load32_le(bj);
          uint32_t r = u;
          uint32_t x = r;
          os[i] = x;
        }
        uint32_t mask[4U] = { 0U };
        uint32_t wv_14 = (uint32_t)0U;
        uint32_t wv_15 = (uint32_t)0U;
        mask[0U] = (uint32_t)totlen;
        mask[1U] = (uint32_t)(totlen >> (uint32_t)32U);
        mask[2U] = wv_14;
        mask[3U] = wv_15;
        memcpy(block_state1.fst,
          block_state1.snd,
          (uint32_t)4U * (uint32_t)4U * sizeof (block_state1.snd[0U]));
        uint32_t *wv3 = block_state1.fst + (uint32_t)3U * (uint32_t)4U;
        for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
        {
          uint32_t *os = wv3;
          uint32_t x = wv3[i] ^ mask[i];
          os[i] = x;
        }
        for (uint32_t i1 = (uint32_t)0U; i1 < (uint32_t)10U; i1++)
        {
          uint32_t start_idx = i1 % (uint32_t)10U * (uint32_t)16U;
          KRML_CHECK_SIZE(sizeof (uint32_t), (uint32_t)4U * (uint32_t)4U);
          uint32_t m_st[(uint32_t)4U * (uint32_t)4U];
          memset(m_st, 0U, (uint32_t)4U * (uint32_t)4U * sizeof (m_st[0U]));
          uint32_t *r00 = m_st + (uint32_t)0U * (uint32_t)4U;
          uint32_t *r10 = m_st + (uint32_t)1U * (uint32_t)4U;
          uint32_t *r20 = m_st + (uint32_t)2U * (uint32_t)4U;
          uint32_t *r30 = m_st + (uint32_t)3U * (uint32_t)4U;
          uint32_t s0 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx];
          uint32_t s11 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)1U];
          uint32_t s21 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)2U];
          uint32_t s3 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)3U];
          uint32_t s4 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)4U];
          uint32_t s5 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)5U];
          uint32_t s6 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)6U];
          uint32_t s7 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)7U];
          uint32_t s8 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)8U];
          uint32_t s9 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)9U];
          uint32_t s10 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)10U];
          uint32_t s111 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)11U];
          uint32_t s12 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)12U];
          uint32_t s13 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)13U];
          uint32_t s14 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)14U];
          uint32_t s15 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)15U];
          uint32_t uu____0 = m_w[s21];
          uint32_t uu____1 = m_w[s4];
          uint32_t uu____2 = m_w[s6];
          r00[0U] = m_w[s0];
          r00[1U] = uu____0;
          r00[2U] = uu____1;
          r00[3U] = uu____2;
          uint32_t uu____3 = m_w[s3];
          uint32_t uu____4 = m_w[s5];
          uint32_t uu____5 = m_w[s7];
          r10[0U] = m_w[s11];
          r10[1U] = uu____3;
          r10[2U] = uu____4;
          r10[3U] = uu____5;
          uint32_t uu____6 = m_w[s10];
          uint32_t uu____7 = m_w[s12];
          uint32_t uu____8 = m_w[s14];
          r20[0U] = m_w[s8];
          r20[1U] = uu____6;
          r20[2U] = uu____7;
          r20[3U] = uu____8;
          uint32_t uu____9 = m_w[s111];
          uint32_t uu____10 = m_w[s13];
          uint32_t uu____11 = m_w[s15];
          r30[0U] = m_w[s9];
          r30[1U] = uu____9;
          r30[2U] = uu____10;
          r30[3U] = uu____11;
          uint32_t *x = m_st + (uint32_t)0U * (uint32_t)4U;
          uint32_t *y = m_st + (uint32_t)1U * (uint32_t)4U;
          uint32_t *z = m_st + (uint32_t)2U * (uint32_t)4U;
          uint32_t *w = m_st + (uint32_t)3U * (uint32_t)4U;
          uint32_t a = (uint32_t)0U;
          uint32_t b10 = (uint32_t)1U;
          uint32_t c0 = (uint32_t)2U;
          uint32_t d0 = (uint32_t)3U;
          uint32_t r01 = Hacl_Impl_Blake2_Constants_rTable_S[0U];
          uint32_t r12 = Hacl_Impl_Blake2_Constants_rTable_S[1U];
          uint32_t r21 = Hacl_Impl_Blake2_Constants_rTable_S[2U];
          uint32_t r31 = Hacl_Impl_Blake2_Constants_rTable_S[3U];
          uint32_t *wv_a0 = block_state1.fst + a * (uint32_t)4U;
          uint32_t *wv_b0 = block_state1.fst + b10 * (uint32_t)4U;
          for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
          {
            uint32_t *os = wv_a0;
            uint32_t x1 = wv_a0[i] + wv_b0[i];
            os[i] = x1;
          }
          for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
          {
            uint32_t *os = wv_a0;
            uint32_t x1 = wv_a0[i] + x[i];
            os[i] = x1;
          }
          uint32_t *wv_a1 = block_state1.fst + d0 * (uint32_t)4U;
          uint32_t *wv_b1 = block_state1.fst + a * (uint32_t)4U;
          for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
          {
            uint32_t *os = wv_a1;
            uint32_t x1 = wv_a1[i] ^ wv_b1[i];
            os[i] = x1;
          }
          uint32_t *r110 = wv_a1;
          for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
          {
            uint32_t *os = r110;
            uint32_t x1 = r110[i];
            uint32_t x10 = x1 >> r01 | x1 << ((uint32_t)32U - r01);
            os[i] = x10;
          }
          uint32_t *wv_a2 = block_state1.fst + c0 * (uint32_t)4U;
          uint32_t *wv_b2 = block_state1.fst + d0 * (uint32_t)4U;
          for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
          {
            uint32_t *os = wv_a2;
            uint32_t x1 = wv_a2[i] + wv_b2[i];
            os[i] = x1;
          }
          uint32_t *wv_a3 = block_state1.fst + b10 * (uint32_t)4U;
          uint32_t *wv_b3 = block_state1.fst + c0 * (uint32_t)4U;
          for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
          {
            uint32_t *os = wv_a3;
            uint32_t x1 = wv_a3[i] ^ wv_b3[i];
            os[i] = x1;
          }
          uint32_t *r111 = wv_a3;
          for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
          {
            uint32_t *os = r111;
            uint32_t x1 = r111[i];
            uint32_t x10 = x1 >> r12 | x1 << ((uint32_t)32U - r12);
            os[i] = x10;
          }
          uint32_t *wv_a4 = block_state1.fst + a * (uint32_t)4U;
          uint32_t *wv_b4 = block_state1.fst + b10 * (uint32_t)4U;
          for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
          {
            uint32_t *os = wv_a4;
            uint32_t x1 = wv_a4[i] + wv_b4[i];
            os[i] = x1;
          }
          for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
          {
            uint32_t *os = wv_a4;
            uint32_t x1 = wv_a4[i] + y[i];
            os[i] = x1;
          }
          uint32_t *wv_a5 = block_state1.fst + d0 * (uint32_t)4U;
          uint32_t *wv_b5 = block_state1.fst + a * (uint32_t)4U;
          for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
          {
            uint32_t *os = wv_a5;
            uint32_t x1 = wv_a5[i] ^ wv_b5[i];
            os[i] = x1;
          }
          uint32_t *r112 = wv_a5;
          for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
          {
            uint32_t *os = r112;
            uint32_t x1 = r112[i];
            uint32_t x10 = x1 >> r21 | x1 << ((uint32_t)32U - r21);
            os[i] = x10;
          }
          uint32_t *wv_a6 = block_state1.fst + c0 * (uint32_t)4U;
          uint32_t *wv_b6 = block_state1.fst + d0 * (uint32_t)4U;
          for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
          {
            uint32_t *os = wv_a6;
            uint32_t x1 = wv_a6[i] + wv_b6[i];
            os[i] = x1;
          }
          uint32_t *wv_a7 = block_state1.fst + b10 * (uint32_t)4U;
          uint32_t *wv_b7 = block_state1.fst + c0 * (uint32_t)4U;
          for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
          {
            uint32_t *os = wv_a7;
            uint32_t x1 = wv_a7[i] ^ wv_b7[i];
            os[i] = x1;
          }
          uint32_t *r113 = wv_a7;
          for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
          {
            uint32_t *os = r113;
            uint32_t x1 = r113[i];
            uint32_t x10 = x1 >> r31 | x1 << ((uint32_t)32U - r31);
            os[i] = x10;
          }
          uint32_t *r13 = block_state1.fst + (uint32_t)1U * (uint32_t)4U;
          uint32_t *r22 = block_state1.fst + (uint32_t)2U * (uint32_t)4U;
          uint32_t *r32 = block_state1.fst + (uint32_t)3U * (uint32_t)4U;
          uint32_t *r114 = r13;
          uint32_t x00 = r114[1U];
          uint32_t x10 = r114[((uint32_t)1U + (uint32_t)1U) % (uint32_t)4U];
          uint32_t x20 = r114[((uint32_t)1U + (uint32_t)2U) % (uint32_t)4U];
          uint32_t x30 = r114[((uint32_t)1U + (uint32_t)3U) % (uint32_t)4U];
          r114[0U] = x00;
          r114[1U] = x10;
          r114[2U] = x20;
          r114[3U] = x30;
          uint32_t *r115 = r22;
          uint32_t x01 = r115[2U];
          uint32_t x11 = r115[((uint32_t)2U + (uint32_t)1U) % (uint32_t)4U];
          uint32_t x21 = r115[((uint32_t)2U + (uint32_t)2U) % (uint32_t)4U];
          uint32_t x31 = r115[((uint32_t)2U + (uint32_t)3U) % (uint32_t)4U];
          r115[0U] = x01;
          r115[1U] = x11;
          r115[2U] = x21;
          r115[3U] = x31;
          uint32_t *r116 = r32;
          uint32_t x02 = r116[3U];
          uint32_t x12 = r116[((uint32_t)3U + (uint32_t)1U) % (uint32_t)4U];
          uint32_t x22 = r116[((uint32_t)3U + (uint32_t)2U) % (uint32_t)4U];
          uint32_t x32 = r116[((uint32_t)3U + (uint32_t)3U) % (uint32_t)4U];
          r116[0U] = x02;
          r116[1U] = x12;
          r116[2U] = x22;
          r116[3U] = x32;
          uint32_t a0 = (uint32_t)0U;
          uint32_t b1 = (uint32_t)1U;
          uint32_t c = (uint32_t)2U;
          uint32_t d = (uint32_t)3U;
          uint32_t r0 = Hacl_Impl_Blake2_Constants_rTable_S[0U];
          uint32_t r1 = Hacl_Impl_Blake2_Constants_rTable_S[1U];
          uint32_t r23 = Hacl_Impl_Blake2_Constants_rTable_S[2U];
          uint32_t r33 = Hacl_Impl_Blake2_Constants_rTable_S[3U];
          uint32_t *wv_a = block_state1.fst + a0 * (uint32_t)4U;
          uint32_t *wv_b8 = block_state1.fst + b1 * (uint32_t)4U;
          for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
          {
            uint32_t *os = wv_a;
            uint32_t x1 = wv_a[i] + wv_b8[i];
            os[i] = x1;
          }
          for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
          {
            uint32_t *os = wv_a;
            uint32_t x1 = wv_a[i] + z[i];
            os[i] = x1;
          }
          uint32_t *wv_a8 = block_state1.fst + d * (uint32_t)4U;
          uint32_t *wv_b9 = block_state1.fst + a0 * (uint32_t)4U;
          for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
          {
            uint32_t *os = wv_a8;
            uint32_t x1 = wv_a8[i] ^ wv_b9[i];
            os[i] = x1;
          }
          uint32_t *r117 = wv_a8;
          for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
          {
            uint32_t *os = r117;
            uint32_t x1 = r117[i];
            uint32_t x13 = x1 >> r0 | x1 << ((uint32_t)32U - r0);
            os[i] = x13;
          }
          uint32_t *wv_a9 = block_state1.fst + c * (uint32_t)4U;
          uint32_t *wv_b10 = block_state1.fst + d * (uint32_t)4U;
          for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
          {
            uint32_t *os = wv_a9;
            uint32_t x1 = wv_a9[i] + wv_b10[i];
            os[i] = x1;
          }
          uint32_t *wv_a10 = block_state1.fst + b1 * (uint32_t)4U;
          uint32_t *wv_b11 = block_state1.fst + c * (uint32_t)4U;
          for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
          {
            uint32_t *os = wv_a10;
            uint32_t x1 = wv_a10[i] ^ wv_b11[i];
            os[i] = x1;
          }
          uint32_t *r118 = wv_a10;
          for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
          {
            uint32_t *os = r118;
            uint32_t x1 = r118[i];
            uint32_t x13 = x1 >> r1 | x1 << ((uint32_t)32U - r1);
            os[i] = x13;
          }
          uint32_t *wv_a11 = block_state1.fst + a0 * (uint32_t)4U;
          uint32_t *wv_b12 = block_state1.fst + b1 * (uint32_t)4U;
          for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
          {
            uint32_t *os = wv_a11;
            uint32_t x1 = wv_a11[i] + wv_b12[i];
            os[i] = x1;
          }
          for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
          {
            uint32_t *os = wv_a11;
            uint32_t x1 = wv_a11[i] + w[i];
            os[i] = x1;
          }
          uint32_t *wv_a12 = block_state1.fst + d * (uint32_t)4U;
          uint32_t *wv_b13 = block_state1.fst + a0 * (uint32_t)4U;
          for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
          {
            uint32_t *os = wv_a12;
            uint32_t x1 = wv_a12[i] ^ wv_b13[i];
            os[i] = x1;
          }
          uint32_t *r119 = wv_a12;
          for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
          {
            uint32_t *os = r119;
            uint32_t x1 = r119[i];
            uint32_t x13 = x1 >> r23 | x1 << ((uint32_t)32U - r23);
            os[i] = x13;
          }
          uint32_t *wv_a13 = block_state1.fst + c * (uint32_t)4U;
          uint32_t *wv_b14 = block_state1.fst + d * (uint32_t)4U;
          for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
          {
            uint32_t *os = wv_a13;
            uint32_t x1 = wv_a13[i] + wv_b14[i];
            os[i] = x1;
          }
          uint32_t *wv_a14 = block_state1.fst + b1 * (uint32_t)4U;
          uint32_t *wv_b = block_state1.fst + c * (uint32_t)4U;
          for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
          {
            uint32_t *os = wv_a14;
            uint32_t x1 = wv_a14[i] ^ wv_b[i];
            os[i] = x1;
          }
          uint32_t *r1110 = wv_a14;
          for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
          {
            uint32_t *os = r1110;
            uint32_t x1 = r1110[i];
            uint32_t x13 = x1 >> r33 | x1 << ((uint32_t)32U - r33);
            os[i] = x13;
          }
          uint32_t *r14 = block_state1.fst + (uint32_t)1U * (uint32_t)4U;
          uint32_t *r2 = block_state1.fst + (uint32_t)2U * (uint32_t)4U;
          uint32_t *r3 = block_state1.fst + (uint32_t)3U * (uint32_t)4U;
          uint32_t *r11 = r14;
          uint32_t x03 = r11[3U];
          uint32_t x13 = r11[((uint32_t)3U + (uint32_t)1U) % (uint32_t)4U];
          uint32_t x23 = r11[((uint32_t)3U + (uint32_t)2U) % (uint32_t)4U];
          uint32_t x33 = r11[((uint32_t)3U + (uint32_t)3U) % (uint32_t)4U];
          r11[0U] = x03;
          r11[1U] = x13;
          r11[2U] = x23;
          r11[3U] = x33;
          uint32_t *r1111 = r2;
          uint32_t x04 = r1111[2U];
          uint32_t x14 = r1111[((uint32_t)2U + (uint32_t)1U) % (uint32_t)4U];
          uint32_t x24 = r1111[((uint32_t)2U + (uint32_t)2U) % (uint32_t)4U];
          uint32_t x34 = r1111[((uint32_t)2U + (uint32_t)3U) % (uint32_t)4U];
          r1111[0U] = x04;
          r1111[1U] = x14;
          r1111[2U] = x24;
          r1111[3U] = x34;
          uint32_t *r1112 = r3;
          uint32_t x0 = r1112[1U];
          uint32_t x1 = r1112[((uint32_t)1U + (uint32_t)1U) % (uint32_t)4U];
          uint32_t x2 = r1112[((uint32_t)1U + (uint32_t)2U) % (uint32_t)4U];
          uint32_t x3 = r1112[((uint32_t)1U + (uint32_t)3U) % (uint32_t)4U];
          r1112[0U] = x0;
          r1112[1U] = x1;
          r1112[2U] = x2;
          r1112[3U] = x3;
        }
        uint32_t *s0 = block_state1.snd + (uint32_t)0U * (uint32_t)4U;
        uint32_t *s11 = block_state1.snd + (uint32_t)1U * (uint32_t)4U;
        uint32_t *r0 = block_state1.fst + (uint32_t)0U * (uint32_t)4U;
        uint32_t *r1 = block_state1.fst + (uint32_t)1U * (uint32_t)4U;
        uint32_t *r2 = block_state1.fst + (uint32_t)2U * (uint32_t)4U;
        uint32_t *r3 = block_state1.fst + (uint32_t)3U * (uint32_t)4U;
        for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
        {
          uint32_t *os = s0;
          uint32_t x = s0[i] ^ r0[i];
          os[i] = x;
        }
        for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
        {
          uint32_t *os = s0;
          uint32_t x = s0[i] ^ r2[i];
          os[i] = x;
        }
        for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
        {
          uint32_t *os = s11;
          uint32_t x = s11[i] ^ r1[i];
          os[i] = x;
        }
        for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
        {
          uint32_t *os = s11;
          uint32_t x = s11[i] ^ r3[i];
          os[i] = x;
        }
      }
    }
    uint32_t ite0;
    if ((uint64_t)len % (uint64_t)(uint32_t)64U == (uint64_t)0U && (uint64_t)len > (uint64_t)0U)
    {
      ite0 = (uint32_t)64U;
    }
    else
    {
      ite0 = (uint32_t)((uint64_t)len % (uint64_t)(uint32_t)64U);
    }
    uint32_t n_blocks = (len - ite0) / (uint32_t)64U;
    uint32_t data1_len = n_blocks * (uint32_t)64U;
    uint32_t data2_len = len - data1_len;
    uint8_t *data1 = data;
    uint8_t *data2 = data + data1_len;
    uint32_t nb = data1_len / (uint32_t)64U;
    for (uint32_t i0 = (uint32_t)0U; i0 < nb; i0++)
    {
      uint64_t ite;
      if ((uint32_t)0U == (uint32_t)0U)
      {
        ite = total_len1;
      }
      else
      {
        ite = total_len1 + (uint64_t)(uint32_t)64U;
      }
      uint64_t totlen = ite + (uint64_t)((i0 + (uint32_t)1U) * (uint32_t)64U);
      uint8_t *b = data1 + i0 * (uint32_t)64U;
      uint32_t m_w[16U] = { 0U };
      for (uint32_t i = (uint32_t)0U; i < (uint32_t)16U; i++)
      {
        uint32_t *os = m_w;
        uint8_t *bj = b + i * (uint32_t)4U;
        uint32_t u = load32_le(bj);
        uint32_t r = u;
        uint32_t x = r;
        os[i] = x;
      }
      uint32_t mask[4U] = { 0U };
      uint32_t wv_14 = (uint32_t)0U;
      uint32_t wv_15 = (uint32_t)0U;
      mask[0U] = (uint32_t)totlen;
      mask[1U] = (uint32_t)(totlen >> (uint32_t)32U);
      mask[2U] = wv_14;
      mask[3U] = wv_15;
      memcpy(block_state1.fst,
        block_state1.snd,
        (uint32_t)4U * (uint32_t)4U * sizeof (block_state1.snd[0U]));
      uint32_t *wv3 = block_state1.fst + (uint32_t)3U * (uint32_t)4U;
      for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
      {
        uint32_t *os = wv3;
        uint32_t x = wv3[i] ^ mask[i];
        os[i] = x;
      }
      for (uint32_t i1 = (uint32_t)0U; i1 < (uint32_t)10U; i1++)
      {
        uint32_t start_idx = i1 % (uint32_t)10U * (uint32_t)16U;
        KRML_CHECK_SIZE(sizeof (uint32_t), (uint32_t)4U * (uint32_t)4U);
        uint32_t m_st[(uint32_t)4U * (uint32_t)4U];
        memset(m_st, 0U, (uint32_t)4U * (uint32_t)4U * sizeof (m_st[0U]));
        uint32_t *r00 = m_st + (uint32_t)0U * (uint32_t)4U;
        uint32_t *r10 = m_st + (uint32_t)1U * (uint32_t)4U;
        uint32_t *r20 = m_st + (uint32_t)2U * (uint32_t)4U;
        uint32_t *r30 = m_st + (uint32_t)3U * (uint32_t)4U;
        uint32_t s0 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx];
        uint32_t s11 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)1U];
        uint32_t s21 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)2U];
        uint32_t s3 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)3U];
        uint32_t s4 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)4U];
        uint32_t s5 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)5U];
        uint32_t s6 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)6U];
        uint32_t s7 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)7U];
        uint32_t s8 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)8U];
        uint32_t s9 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)9U];
        uint32_t s10 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)10U];
        uint32_t s111 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)11U];
        uint32_t s12 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)12U];
        uint32_t s13 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)13U];
        uint32_t s14 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)14U];
        uint32_t s15 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)15U];
        uint32_t uu____12 = m_w[s21];
        uint32_t uu____13 = m_w[s4];
        uint32_t uu____14 = m_w[s6];
        r00[0U] = m_w[s0];
        r00[1U] = uu____12;
        r00[2U] = uu____13;
        r00[3U] = uu____14;
        uint32_t uu____15 = m_w[s3];
        uint32_t uu____16 = m_w[s5];
        uint32_t uu____17 = m_w[s7];
        r10[0U] = m_w[s11];
        r10[1U] = uu____15;
        r10[2U] = uu____16;
        r10[3U] = uu____17;
        uint32_t uu____18 = m_w[s10];
        uint32_t uu____19 = m_w[s12];
        uint32_t uu____20 = m_w[s14];
        r20[0U] = m_w[s8];
        r20[1U] = uu____18;
        r20[2U] = uu____19;
        r20[3U] = uu____20;
        uint32_t uu____21 = m_w[s111];
        uint32_t uu____22 = m_w[s13];
        uint32_t uu____23 = m_w[s15];
        r30[0U] = m_w[s9];
        r30[1U] = uu____21;
        r30[2U] = uu____22;
        r30[3U] = uu____23;
        uint32_t *x = m_st + (uint32_t)0U * (uint32_t)4U;
        uint32_t *y = m_st + (uint32_t)1U * (uint32_t)4U;
        uint32_t *z = m_st + (uint32_t)2U * (uint32_t)4U;
        uint32_t *w = m_st + (uint32_t)3U * (uint32_t)4U;
        uint32_t a = (uint32_t)0U;
        uint32_t b10 = (uint32_t)1U;
        uint32_t c0 = (uint32_t)2U;
        uint32_t d0 = (uint32_t)3U;
        uint32_t r01 = Hacl_Impl_Blake2_Constants_rTable_S[0U];
        uint32_t r12 = Hacl_Impl_Blake2_Constants_rTable_S[1U];
        uint32_t r21 = Hacl_Impl_Blake2_Constants_rTable_S[2U];
        uint32_t r31 = Hacl_Impl_Blake2_Constants_rTable_S[3U];
        uint32_t *wv_a0 = block_state1.fst + a * (uint32_t)4U;
        uint32_t *wv_b0 = block_state1.fst + b10 * (uint32_t)4U;
        for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
        {
          uint32_t *os = wv_a0;
          uint32_t x1 = wv_a0[i] + wv_b0[i];
          os[i] = x1;
        }
        for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
        {
          uint32_t *os = wv_a0;
          uint32_t x1 = wv_a0[i] + x[i];
          os[i] = x1;
        }
        uint32_t *wv_a1 = block_state1.fst + d0 * (uint32_t)4U;
        uint32_t *wv_b1 = block_state1.fst + a * (uint32_t)4U;
        for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
        {
          uint32_t *os = wv_a1;
          uint32_t x1 = wv_a1[i] ^ wv_b1[i];
          os[i] = x1;
        }
        uint32_t *r110 = wv_a1;
        for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
        {
          uint32_t *os = r110;
          uint32_t x1 = r110[i];
          uint32_t x10 = x1 >> r01 | x1 << ((uint32_t)32U - r01);
          os[i] = x10;
        }
        uint32_t *wv_a2 = block_state1.fst + c0 * (uint32_t)4U;
        uint32_t *wv_b2 = block_state1.fst + d0 * (uint32_t)4U;
        for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
        {
          uint32_t *os = wv_a2;
          uint32_t x1 = wv_a2[i] + wv_b2[i];
          os[i] = x1;
        }
        uint32_t *wv_a3 = block_state1.fst + b10 * (uint32_t)4U;
        uint32_t *wv_b3 = block_state1.fst + c0 * (uint32_t)4U;
        for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
        {
          uint32_t *os = wv_a3;
          uint32_t x1 = wv_a3[i] ^ wv_b3[i];
          os[i] = x1;
        }
        uint32_t *r111 = wv_a3;
        for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
        {
          uint32_t *os = r111;
          uint32_t x1 = r111[i];
          uint32_t x10 = x1 >> r12 | x1 << ((uint32_t)32U - r12);
          os[i] = x10;
        }
        uint32_t *wv_a4 = block_state1.fst + a * (uint32_t)4U;
        uint32_t *wv_b4 = block_state1.fst + b10 * (uint32_t)4U;
        for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
        {
          uint32_t *os = wv_a4;
          uint32_t x1 = wv_a4[i] + wv_b4[i];
          os[i] = x1;
        }
        for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
        {
          uint32_t *os = wv_a4;
          uint32_t x1 = wv_a4[i] + y[i];
          os[i] = x1;
        }
        uint32_t *wv_a5 = block_state1.fst + d0 * (uint32_t)4U;
        uint32_t *wv_b5 = block_state1.fst + a * (uint32_t)4U;
        for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
        {
          uint32_t *os = wv_a5;
          uint32_t x1 = wv_a5[i] ^ wv_b5[i];
          os[i] = x1;
        }
        uint32_t *r112 = wv_a5;
        for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
        {
          uint32_t *os = r112;
          uint32_t x1 = r112[i];
          uint32_t x10 = x1 >> r21 | x1 << ((uint32_t)32U - r21);
          os[i] = x10;
        }
        uint32_t *wv_a6 = block_state1.fst + c0 * (uint32_t)4U;
        uint32_t *wv_b6 = block_state1.fst + d0 * (uint32_t)4U;
        for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
        {
          uint32_t *os = wv_a6;
          uint32_t x1 = wv_a6[i] + wv_b6[i];
          os[i] = x1;
        }
        uint32_t *wv_a7 = block_state1.fst + b10 * (uint32_t)4U;
        uint32_t *wv_b7 = block_state1.fst + c0 * (uint32_t)4U;
        for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
        {
          uint32_t *os = wv_a7;
          uint32_t x1 = wv_a7[i] ^ wv_b7[i];
          os[i] = x1;
        }
        uint32_t *r113 = wv_a7;
        for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
        {
          uint32_t *os = r113;
          uint32_t x1 = r113[i];
          uint32_t x10 = x1 >> r31 | x1 << ((uint32_t)32U - r31);
          os[i] = x10;
        }
        uint32_t *r13 = block_state1.fst + (uint32_t)1U * (uint32_t)4U;
        uint32_t *r22 = block_state1.fst + (uint32_t)2U * (uint32_t)4U;
        uint32_t *r32 = block_state1.fst + (uint32_t)3U * (uint32_t)4U;
        uint32_t *r114 = r13;
        uint32_t x00 = r114[1U];
        uint32_t x10 = r114[((uint32_t)1U + (uint32_t)1U) % (uint32_t)4U];
        uint32_t x20 = r114[((uint32_t)1U + (uint32_t)2U) % (uint32_t)4U];
        uint32_t x30 = r114[((uint32_t)1U + (uint32_t)3U) % (uint32_t)4U];
        r114[0U] = x00;
        r114[1U] = x10;
        r114[2U] = x20;
        r114[3U] = x30;
        uint32_t *r115 = r22;
        uint32_t x01 = r115[2U];
        uint32_t x11 = r115[((uint32_t)2U + (uint32_t)1U) % (uint32_t)4U];
        uint32_t x21 = r115[((uint32_t)2U + (uint32_t)2U) % (uint32_t)4U];
        uint32_t x31 = r115[((uint32_t)2U + (uint32_t)3U) % (uint32_t)4U];
        r115[0U] = x01;
        r115[1U] = x11;
        r115[2U] = x21;
        r115[3U] = x31;
        uint32_t *r116 = r32;
        uint32_t x02 = r116[3U];
        uint32_t x12 = r116[((uint32_t)3U + (uint32_t)1U) % (uint32_t)4U];
        uint32_t x22 = r116[((uint32_t)3U + (uint32_t)2U) % (uint32_t)4U];
        uint32_t x32 = r116[((uint32_t)3U + (uint32_t)3U) % (uint32_t)4U];
        r116[0U] = x02;
        r116[1U] = x12;
        r116[2U] = x22;
        r116[3U] = x32;
        uint32_t a0 = (uint32_t)0U;
        uint32_t b1 = (uint32_t)1U;
        uint32_t c = (uint32_t)2U;
        uint32_t d = (uint32_t)3U;
        uint32_t r0 = Hacl_Impl_Blake2_Constants_rTable_S[0U];
        uint32_t r1 = Hacl_Impl_Blake2_Constants_rTable_S[1U];
        uint32_t r23 = Hacl_Impl_Blake2_Constants_rTable_S[2U];
        uint32_t r33 = Hacl_Impl_Blake2_Constants_rTable_S[3U];
        uint32_t *wv_a = block_state1.fst + a0 * (uint32_t)4U;
        uint32_t *wv_b8 = block_state1.fst + b1 * (uint32_t)4U;
        for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
        {
          uint32_t *os = wv_a;
          uint32_t x1 = wv_a[i] + wv_b8[i];
          os[i] = x1;
        }
        for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
        {
          uint32_t *os = wv_a;
          uint32_t x1 = wv_a[i] + z[i];
          os[i] = x1;
        }
        uint32_t *wv_a8 = block_state1.fst + d * (uint32_t)4U;
        uint32_t *wv_b9 = block_state1.fst + a0 * (uint32_t)4U;
        for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
        {
          uint32_t *os = wv_a8;
          uint32_t x1 = wv_a8[i] ^ wv_b9[i];
          os[i] = x1;
        }
        uint32_t *r117 = wv_a8;
        for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
        {
          uint32_t *os = r117;
          uint32_t x1 = r117[i];
          uint32_t x13 = x1 >> r0 | x1 << ((uint32_t)32U - r0);
          os[i] = x13;
        }
        uint32_t *wv_a9 = block_state1.fst + c * (uint32_t)4U;
        uint32_t *wv_b10 = block_state1.fst + d * (uint32_t)4U;
        for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
        {
          uint32_t *os = wv_a9;
          uint32_t x1 = wv_a9[i] + wv_b10[i];
          os[i] = x1;
        }
        uint32_t *wv_a10 = block_state1.fst + b1 * (uint32_t)4U;
        uint32_t *wv_b11 = block_state1.fst + c * (uint32_t)4U;
        for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
        {
          uint32_t *os = wv_a10;
          uint32_t x1 = wv_a10[i] ^ wv_b11[i];
          os[i] = x1;
        }
        uint32_t *r118 = wv_a10;
        for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
        {
          uint32_t *os = r118;
          uint32_t x1 = r118[i];
          uint32_t x13 = x1 >> r1 | x1 << ((uint32_t)32U - r1);
          os[i] = x13;
        }
        uint32_t *wv_a11 = block_state1.fst + a0 * (uint32_t)4U;
        uint32_t *wv_b12 = block_state1.fst + b1 * (uint32_t)4U;
        for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
        {
          uint32_t *os = wv_a11;
          uint32_t x1 = wv_a11[i] + wv_b12[i];
          os[i] = x1;
        }
        for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
        {
          uint32_t *os = wv_a11;
          uint32_t x1 = wv_a11[i] + w[i];
          os[i] = x1;
        }
        uint32_t *wv_a12 = block_state1.fst + d * (uint32_t)4U;
        uint32_t *wv_b13 = block_state1.fst + a0 * (uint32_t)4U;
        for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
        {
          uint32_t *os = wv_a12;
          uint32_t x1 = wv_a12[i] ^ wv_b13[i];
          os[i] = x1;
        }
        uint32_t *r119 = wv_a12;
        for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
        {
          uint32_t *os = r119;
          uint32_t x1 = r119[i];
          uint32_t x13 = x1 >> r23 | x1 << ((uint32_t)32U - r23);
          os[i] = x13;
        }
        uint32_t *wv_a13 = block_state1.fst + c * (uint32_t)4U;
        uint32_t *wv_b14 = block_state1.fst + d * (uint32_t)4U;
        for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
        {
          uint32_t *os = wv_a13;
          uint32_t x1 = wv_a13[i] + wv_b14[i];
          os[i] = x1;
        }
        uint32_t *wv_a14 = block_state1.fst + b1 * (uint32_t)4U;
        uint32_t *wv_b = block_state1.fst + c * (uint32_t)4U;
        for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
        {
          uint32_t *os = wv_a14;
          uint32_t x1 = wv_a14[i] ^ wv_b[i];
          os[i] = x1;
        }
        uint32_t *r1110 = wv_a14;
        for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
        {
          uint32_t *os = r1110;
          uint32_t x1 = r1110[i];
          uint32_t x13 = x1 >> r33 | x1 << ((uint32_t)32U - r33);
          os[i] = x13;
        }
        uint32_t *r14 = block_state1.fst + (uint32_t)1U * (uint32_t)4U;
        uint32_t *r2 = block_state1.fst + (uint32_t)2U * (uint32_t)4U;
        uint32_t *r3 = block_state1.fst + (uint32_t)3U * (uint32_t)4U;
        uint32_t *r11 = r14;
        uint32_t x03 = r11[3U];
        uint32_t x13 = r11[((uint32_t)3U + (uint32_t)1U) % (uint32_t)4U];
        uint32_t x23 = r11[((uint32_t)3U + (uint32_t)2U) % (uint32_t)4U];
        uint32_t x33 = r11[((uint32_t)3U + (uint32_t)3U) % (uint32_t)4U];
        r11[0U] = x03;
        r11[1U] = x13;
        r11[2U] = x23;
        r11[3U] = x33;
        uint32_t *r1111 = r2;
        uint32_t x04 = r1111[2U];
        uint32_t x14 = r1111[((uint32_t)2U + (uint32_t)1U) % (uint32_t)4U];
        uint32_t x24 = r1111[((uint32_t)2U + (uint32_t)2U) % (uint32_t)4U];
        uint32_t x34 = r1111[((uint32_t)2U + (uint32_t)3U) % (uint32_t)4U];
        r1111[0U] = x04;
        r1111[1U] = x14;
        r1111[2U] = x24;
        r1111[3U] = x34;
        uint32_t *r1112 = r3;
        uint32_t x0 = r1112[1U];
        uint32_t x1 = r1112[((uint32_t)1U + (uint32_t)1U) % (uint32_t)4U];
        uint32_t x2 = r1112[((uint32_t)1U + (uint32_t)2U) % (uint32_t)4U];
        uint32_t x3 = r1112[((uint32_t)1U + (uint32_t)3U) % (uint32_t)4U];
        r1112[0U] = x0;
        r1112[1U] = x1;
        r1112[2U] = x2;
        r1112[3U] = x3;
      }
      uint32_t *s0 = block_state1.snd + (uint32_t)0U * (uint32_t)4U;
      uint32_t *s11 = block_state1.snd + (uint32_t)1U * (uint32_t)4U;
      uint32_t *r0 = block_state1.fst + (uint32_t)0U * (uint32_t)4U;
      uint32_t *r1 = block_state1.fst + (uint32_t)1U * (uint32_t)4U;
      uint32_t *r2 = block_state1.fst + (uint32_t)2U * (uint32_t)4U;
      uint32_t *r3 = block_state1.fst + (uint32_t)3U * (uint32_t)4U;
      for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
      {
        uint32_t *os = s0;
        uint32_t x = s0[i] ^ r0[i];
        os[i] = x;
      }
      for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
      {
        uint32_t *os = s0;
        uint32_t x = s0[i] ^ r2[i];
        os[i] = x;
      }
      for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
      {
        uint32_t *os = s11;
        uint32_t x = s11[i] ^ r1[i];
        os[i] = x;
      }
      for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
      {
        uint32_t *os = s11;
        uint32_t x = s11[i] ^ r3[i];
        os[i] = x;
      }
    }
    uint8_t *dst = buf;
    memcpy(dst, data2, data2_len * sizeof (data2[0U]));
    *p
    =
      (
        (Hacl_Streaming_Functor_state_s__K____uint32_t___uint32_t____){
          .block_state = block_state1,
          .buf = buf,
          .total_len = total_len1 + (uint64_t)len
        }
      );
    return;
  }
  uint32_t diff = (uint32_t)64U - sz;
  uint8_t *data1 = data;
  uint8_t *data2 = data + diff;
  Hacl_Streaming_Functor_state_s__K____uint32_t___uint32_t____ s2 = *p;
  K____uint32_t___uint32_t_ block_state10 = s2.block_state;
  uint8_t *buf0 = s2.buf;
  uint64_t total_len10 = s2.total_len;
  uint32_t sz10;
  if (total_len10 % (uint64_t)(uint32_t)64U == (uint64_t)0U && total_len10 > (uint64_t)0U)
  {
    sz10 = (uint32_t)64U;
  }
  else
  {
    sz10 = (uint32_t)(total_len10 % (uint64_t)(uint32_t)64U);
  }
  uint8_t *buf2 = buf0 + sz10;
  memcpy(buf2, data1, diff * sizeof (data1[0U]));
  uint64_t total_len2 = total_len10 + (uint64_t)diff;
  *p
  =
    (
      (Hacl_Streaming_Functor_state_s__K____uint32_t___uint32_t____){
        .block_state = block_state10,
        .buf = buf0,
        .total_len = total_len2
      }
    );
  Hacl_Streaming_Functor_state_s__K____uint32_t___uint32_t____ s20 = *p;
  K____uint32_t___uint32_t_ block_state1 = s20.block_state;
  uint8_t *buf = s20.buf;
  uint64_t total_len1 = s20.total_len;
  uint32_t sz1;
  if (total_len1 % (uint64_t)(uint32_t)64U == (uint64_t)0U && total_len1 > (uint64_t)0U)
  {
    sz1 = (uint32_t)64U;
  }
  else
  {
    sz1 = (uint32_t)(total_len1 % (uint64_t)(uint32_t)64U);
  }
  if (!(sz1 == (uint32_t)0U))
  {
    uint64_t prevlen = total_len1 - (uint64_t)sz1;
    uint32_t nb = (uint32_t)1U;
    for (uint32_t i0 = (uint32_t)0U; i0 < nb; i0++)
    {
      uint64_t ite;
      if ((uint32_t)0U == (uint32_t)0U)
      {
        ite = prevlen;
      }
      else
      {
        ite = prevlen + (uint64_t)(uint32_t)64U;
      }
      uint64_t totlen = ite + (uint64_t)((i0 + (uint32_t)1U) * (uint32_t)64U);
      uint8_t *b = buf + i0 * (uint32_t)64U;
      uint32_t m_w[16U] = { 0U };
      for (uint32_t i = (uint32_t)0U; i < (uint32_t)16U; i++)
      {
        uint32_t *os = m_w;
        uint8_t *bj = b + i * (uint32_t)4U;
        uint32_t u = load32_le(bj);
        uint32_t r = u;
        uint32_t x = r;
        os[i] = x;
      }
      uint32_t mask[4U] = { 0U };
      uint32_t wv_14 = (uint32_t)0U;
      uint32_t wv_15 = (uint32_t)0U;
      mask[0U] = (uint32_t)totlen;
      mask[1U] = (uint32_t)(totlen >> (uint32_t)32U);
      mask[2U] = wv_14;
      mask[3U] = wv_15;
      memcpy(block_state1.fst,
        block_state1.snd,
        (uint32_t)4U * (uint32_t)4U * sizeof (block_state1.snd[0U]));
      uint32_t *wv3 = block_state1.fst + (uint32_t)3U * (uint32_t)4U;
      for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
      {
        uint32_t *os = wv3;
        uint32_t x = wv3[i] ^ mask[i];
        os[i] = x;
      }
      for (uint32_t i1 = (uint32_t)0U; i1 < (uint32_t)10U; i1++)
      {
        uint32_t start_idx = i1 % (uint32_t)10U * (uint32_t)16U;
        KRML_CHECK_SIZE(sizeof (uint32_t), (uint32_t)4U * (uint32_t)4U);
        uint32_t m_st[(uint32_t)4U * (uint32_t)4U];
        memset(m_st, 0U, (uint32_t)4U * (uint32_t)4U * sizeof (m_st[0U]));
        uint32_t *r00 = m_st + (uint32_t)0U * (uint32_t)4U;
        uint32_t *r10 = m_st + (uint32_t)1U * (uint32_t)4U;
        uint32_t *r20 = m_st + (uint32_t)2U * (uint32_t)4U;
        uint32_t *r30 = m_st + (uint32_t)3U * (uint32_t)4U;
        uint32_t s0 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx];
        uint32_t s11 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)1U];
        uint32_t s21 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)2U];
        uint32_t s3 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)3U];
        uint32_t s4 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)4U];
        uint32_t s5 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)5U];
        uint32_t s6 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)6U];
        uint32_t s7 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)7U];
        uint32_t s8 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)8U];
        uint32_t s9 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)9U];
        uint32_t s10 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)10U];
        uint32_t s111 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)11U];
        uint32_t s12 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)12U];
        uint32_t s13 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)13U];
        uint32_t s14 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)14U];
        uint32_t s15 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)15U];
        uint32_t uu____24 = m_w[s21];
        uint32_t uu____25 = m_w[s4];
        uint32_t uu____26 = m_w[s6];
        r00[0U] = m_w[s0];
        r00[1U] = uu____24;
        r00[2U] = uu____25;
        r00[3U] = uu____26;
        uint32_t uu____27 = m_w[s3];
        uint32_t uu____28 = m_w[s5];
        uint32_t uu____29 = m_w[s7];
        r10[0U] = m_w[s11];
        r10[1U] = uu____27;
        r10[2U] = uu____28;
        r10[3U] = uu____29;
        uint32_t uu____30 = m_w[s10];
        uint32_t uu____31 = m_w[s12];
        uint32_t uu____32 = m_w[s14];
        r20[0U] = m_w[s8];
        r20[1U] = uu____30;
        r20[2U] = uu____31;
        r20[3U] = uu____32;
        uint32_t uu____33 = m_w[s111];
        uint32_t uu____34 = m_w[s13];
        uint32_t uu____35 = m_w[s15];
        r30[0U] = m_w[s9];
        r30[1U] = uu____33;
        r30[2U] = uu____34;
        r30[3U] = uu____35;
        uint32_t *x = m_st + (uint32_t)0U * (uint32_t)4U;
        uint32_t *y = m_st + (uint32_t)1U * (uint32_t)4U;
        uint32_t *z = m_st + (uint32_t)2U * (uint32_t)4U;
        uint32_t *w = m_st + (uint32_t)3U * (uint32_t)4U;
        uint32_t a = (uint32_t)0U;
        uint32_t b10 = (uint32_t)1U;
        uint32_t c0 = (uint32_t)2U;
        uint32_t d0 = (uint32_t)3U;
        uint32_t r01 = Hacl_Impl_Blake2_Constants_rTable_S[0U];
        uint32_t r12 = Hacl_Impl_Blake2_Constants_rTable_S[1U];
        uint32_t r21 = Hacl_Impl_Blake2_Constants_rTable_S[2U];
        uint32_t r31 = Hacl_Impl_Blake2_Constants_rTable_S[3U];
        uint32_t *wv_a0 = block_state1.fst + a * (uint32_t)4U;
        uint32_t *wv_b0 = block_state1.fst + b10 * (uint32_t)4U;
        for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
        {
          uint32_t *os = wv_a0;
          uint32_t x1 = wv_a0[i] + wv_b0[i];
          os[i] = x1;
        }
        for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
        {
          uint32_t *os = wv_a0;
          uint32_t x1 = wv_a0[i] + x[i];
          os[i] = x1;
        }
        uint32_t *wv_a1 = block_state1.fst + d0 * (uint32_t)4U;
        uint32_t *wv_b1 = block_state1.fst + a * (uint32_t)4U;
        for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
        {
          uint32_t *os = wv_a1;
          uint32_t x1 = wv_a1[i] ^ wv_b1[i];
          os[i] = x1;
        }
        uint32_t *r110 = wv_a1;
        for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
        {
          uint32_t *os = r110;
          uint32_t x1 = r110[i];
          uint32_t x10 = x1 >> r01 | x1 << ((uint32_t)32U - r01);
          os[i] = x10;
        }
        uint32_t *wv_a2 = block_state1.fst + c0 * (uint32_t)4U;
        uint32_t *wv_b2 = block_state1.fst + d0 * (uint32_t)4U;
        for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
        {
          uint32_t *os = wv_a2;
          uint32_t x1 = wv_a2[i] + wv_b2[i];
          os[i] = x1;
        }
        uint32_t *wv_a3 = block_state1.fst + b10 * (uint32_t)4U;
        uint32_t *wv_b3 = block_state1.fst + c0 * (uint32_t)4U;
        for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
        {
          uint32_t *os = wv_a3;
          uint32_t x1 = wv_a3[i] ^ wv_b3[i];
          os[i] = x1;
        }
        uint32_t *r111 = wv_a3;
        for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
        {
          uint32_t *os = r111;
          uint32_t x1 = r111[i];
          uint32_t x10 = x1 >> r12 | x1 << ((uint32_t)32U - r12);
          os[i] = x10;
        }
        uint32_t *wv_a4 = block_state1.fst + a * (uint32_t)4U;
        uint32_t *wv_b4 = block_state1.fst + b10 * (uint32_t)4U;
        for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
        {
          uint32_t *os = wv_a4;
          uint32_t x1 = wv_a4[i] + wv_b4[i];
          os[i] = x1;
        }
        for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
        {
          uint32_t *os = wv_a4;
          uint32_t x1 = wv_a4[i] + y[i];
          os[i] = x1;
        }
        uint32_t *wv_a5 = block_state1.fst + d0 * (uint32_t)4U;
        uint32_t *wv_b5 = block_state1.fst + a * (uint32_t)4U;
        for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
        {
          uint32_t *os = wv_a5;
          uint32_t x1 = wv_a5[i] ^ wv_b5[i];
          os[i] = x1;
        }
        uint32_t *r112 = wv_a5;
        for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
        {
          uint32_t *os = r112;
          uint32_t x1 = r112[i];
          uint32_t x10 = x1 >> r21 | x1 << ((uint32_t)32U - r21);
          os[i] = x10;
        }
        uint32_t *wv_a6 = block_state1.fst + c0 * (uint32_t)4U;
        uint32_t *wv_b6 = block_state1.fst + d0 * (uint32_t)4U;
        for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
        {
          uint32_t *os = wv_a6;
          uint32_t x1 = wv_a6[i] + wv_b6[i];
          os[i] = x1;
        }
        uint32_t *wv_a7 = block_state1.fst + b10 * (uint32_t)4U;
        uint32_t *wv_b7 = block_state1.fst + c0 * (uint32_t)4U;
        for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
        {
          uint32_t *os = wv_a7;
          uint32_t x1 = wv_a7[i] ^ wv_b7[i];
          os[i] = x1;
        }
        uint32_t *r113 = wv_a7;
        for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
        {
          uint32_t *os = r113;
          uint32_t x1 = r113[i];
          uint32_t x10 = x1 >> r31 | x1 << ((uint32_t)32U - r31);
          os[i] = x10;
        }
        uint32_t *r13 = block_state1.fst + (uint32_t)1U * (uint32_t)4U;
        uint32_t *r22 = block_state1.fst + (uint32_t)2U * (uint32_t)4U;
        uint32_t *r32 = block_state1.fst + (uint32_t)3U * (uint32_t)4U;
        uint32_t *r114 = r13;
        uint32_t x00 = r114[1U];
        uint32_t x10 = r114[((uint32_t)1U + (uint32_t)1U) % (uint32_t)4U];
        uint32_t x20 = r114[((uint32_t)1U + (uint32_t)2U) % (uint32_t)4U];
        uint32_t x30 = r114[((uint32_t)1U + (uint32_t)3U) % (uint32_t)4U];
        r114[0U] = x00;
        r114[1U] = x10;
        r114[2U] = x20;
        r114[3U] = x30;
        uint32_t *r115 = r22;
        uint32_t x01 = r115[2U];
        uint32_t x11 = r115[((uint32_t)2U + (uint32_t)1U) % (uint32_t)4U];
        uint32_t x21 = r115[((uint32_t)2U + (uint32_t)2U) % (uint32_t)4U];
        uint32_t x31 = r115[((uint32_t)2U + (uint32_t)3U) % (uint32_t)4U];
        r115[0U] = x01;
        r115[1U] = x11;
        r115[2U] = x21;
        r115[3U] = x31;
        uint32_t *r116 = r32;
        uint32_t x02 = r116[3U];
        uint32_t x12 = r116[((uint32_t)3U + (uint32_t)1U) % (uint32_t)4U];
        uint32_t x22 = r116[((uint32_t)3U + (uint32_t)2U) % (uint32_t)4U];
        uint32_t x32 = r116[((uint32_t)3U + (uint32_t)3U) % (uint32_t)4U];
        r116[0U] = x02;
        r116[1U] = x12;
        r116[2U] = x22;
        r116[3U] = x32;
        uint32_t a0 = (uint32_t)0U;
        uint32_t b1 = (uint32_t)1U;
        uint32_t c = (uint32_t)2U;
        uint32_t d = (uint32_t)3U;
        uint32_t r0 = Hacl_Impl_Blake2_Constants_rTable_S[0U];
        uint32_t r1 = Hacl_Impl_Blake2_Constants_rTable_S[1U];
        uint32_t r23 = Hacl_Impl_Blake2_Constants_rTable_S[2U];
        uint32_t r33 = Hacl_Impl_Blake2_Constants_rTable_S[3U];
        uint32_t *wv_a = block_state1.fst + a0 * (uint32_t)4U;
        uint32_t *wv_b8 = block_state1.fst + b1 * (uint32_t)4U;
        for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
        {
          uint32_t *os = wv_a;
          uint32_t x1 = wv_a[i] + wv_b8[i];
          os[i] = x1;
        }
        for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
        {
          uint32_t *os = wv_a;
          uint32_t x1 = wv_a[i] + z[i];
          os[i] = x1;
        }
        uint32_t *wv_a8 = block_state1.fst + d * (uint32_t)4U;
        uint32_t *wv_b9 = block_state1.fst + a0 * (uint32_t)4U;
        for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
        {
          uint32_t *os = wv_a8;
          uint32_t x1 = wv_a8[i] ^ wv_b9[i];
          os[i] = x1;
        }
        uint32_t *r117 = wv_a8;
        for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
        {
          uint32_t *os = r117;
          uint32_t x1 = r117[i];
          uint32_t x13 = x1 >> r0 | x1 << ((uint32_t)32U - r0);
          os[i] = x13;
        }
        uint32_t *wv_a9 = block_state1.fst + c * (uint32_t)4U;
        uint32_t *wv_b10 = block_state1.fst + d * (uint32_t)4U;
        for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
        {
          uint32_t *os = wv_a9;
          uint32_t x1 = wv_a9[i] + wv_b10[i];
          os[i] = x1;
        }
        uint32_t *wv_a10 = block_state1.fst + b1 * (uint32_t)4U;
        uint32_t *wv_b11 = block_state1.fst + c * (uint32_t)4U;
        for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
        {
          uint32_t *os = wv_a10;
          uint32_t x1 = wv_a10[i] ^ wv_b11[i];
          os[i] = x1;
        }
        uint32_t *r118 = wv_a10;
        for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
        {
          uint32_t *os = r118;
          uint32_t x1 = r118[i];
          uint32_t x13 = x1 >> r1 | x1 << ((uint32_t)32U - r1);
          os[i] = x13;
        }
        uint32_t *wv_a11 = block_state1.fst + a0 * (uint32_t)4U;
        uint32_t *wv_b12 = block_state1.fst + b1 * (uint32_t)4U;
        for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
        {
          uint32_t *os = wv_a11;
          uint32_t x1 = wv_a11[i] + wv_b12[i];
          os[i] = x1;
        }
        for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
        {
          uint32_t *os = wv_a11;
          uint32_t x1 = wv_a11[i] + w[i];
          os[i] = x1;
        }
        uint32_t *wv_a12 = block_state1.fst + d * (uint32_t)4U;
        uint32_t *wv_b13 = block_state1.fst + a0 * (uint32_t)4U;
        for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
        {
          uint32_t *os = wv_a12;
          uint32_t x1 = wv_a12[i] ^ wv_b13[i];
          os[i] = x1;
        }
        uint32_t *r119 = wv_a12;
        for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
        {
          uint32_t *os = r119;
          uint32_t x1 = r119[i];
          uint32_t x13 = x1 >> r23 | x1 << ((uint32_t)32U - r23);
          os[i] = x13;
        }
        uint32_t *wv_a13 = block_state1.fst + c * (uint32_t)4U;
        uint32_t *wv_b14 = block_state1.fst + d * (uint32_t)4U;
        for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
        {
          uint32_t *os = wv_a13;
          uint32_t x1 = wv_a13[i] + wv_b14[i];
          os[i] = x1;
        }
        uint32_t *wv_a14 = block_state1.fst + b1 * (uint32_t)4U;
        uint32_t *wv_b = block_state1.fst + c * (uint32_t)4U;
        for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
        {
          uint32_t *os = wv_a14;
          uint32_t x1 = wv_a14[i] ^ wv_b[i];
          os[i] = x1;
        }
        uint32_t *r1110 = wv_a14;
        for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
        {
          uint32_t *os = r1110;
          uint32_t x1 = r1110[i];
          uint32_t x13 = x1 >> r33 | x1 << ((uint32_t)32U - r33);
          os[i] = x13;
        }
        uint32_t *r14 = block_state1.fst + (uint32_t)1U * (uint32_t)4U;
        uint32_t *r2 = block_state1.fst + (uint32_t)2U * (uint32_t)4U;
        uint32_t *r3 = block_state1.fst + (uint32_t)3U * (uint32_t)4U;
        uint32_t *r11 = r14;
        uint32_t x03 = r11[3U];
        uint32_t x13 = r11[((uint32_t)3U + (uint32_t)1U) % (uint32_t)4U];
        uint32_t x23 = r11[((uint32_t)3U + (uint32_t)2U) % (uint32_t)4U];
        uint32_t x33 = r11[((uint32_t)3U + (uint32_t)3U) % (uint32_t)4U];
        r11[0U] = x03;
        r11[1U] = x13;
        r11[2U] = x23;
        r11[3U] = x33;
        uint32_t *r1111 = r2;
        uint32_t x04 = r1111[2U];
        uint32_t x14 = r1111[((uint32_t)2U + (uint32_t)1U) % (uint32_t)4U];
        uint32_t x24 = r1111[((uint32_t)2U + (uint32_t)2U) % (uint32_t)4U];
        uint32_t x34 = r1111[((uint32_t)2U + (uint32_t)3U) % (uint32_t)4U];
        r1111[0U] = x04;
        r1111[1U] = x14;
        r1111[2U] = x24;
        r1111[3U] = x34;
        uint32_t *r1112 = r3;
        uint32_t x0 = r1112[1U];
        uint32_t x1 = r1112[((uint32_t)1U + (uint32_t)1U) % (uint32_t)4U];
        uint32_t x2 = r1112[((uint32_t)1U + (uint32_t)2U) % (uint32_t)4U];
        uint32_t x3 = r1112[((uint32_t)1U + (uint32_t)3U) % (uint32_t)4U];
        r1112[0U] = x0;
        r1112[1U] = x1;
        r1112[2U] = x2;
        r1112[3U] = x3;
      }
      uint32_t *s0 = block_state1.snd + (uint32_t)0U * (uint32_t)4U;
      uint32_t *s11 = block_state1.snd + (uint32_t)1U * (uint32_t)4U;
      uint32_t *r0 = block_state1.fst + (uint32_t)0U * (uint32_t)4U;
      uint32_t *r1 = block_state1.fst + (uint32_t)1U * (uint32_t)4U;
      uint32_t *r2 = block_state1.fst + (uint32_t)2U * (uint32_t)4U;
      uint32_t *r3 = block_state1.fst + (uint32_t)3U * (uint32_t)4U;
      for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
      {
        uint32_t *os = s0;
        uint32_t x = s0[i] ^ r0[i];
        os[i] = x;
      }
      for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
      {
        uint32_t *os = s0;
        uint32_t x = s0[i] ^ r2[i];
        os[i] = x;
      }
      for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
      {
        uint32_t *os = s11;
        uint32_t x = s11[i] ^ r1[i];
        os[i] = x;
      }
      for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
      {
        uint32_t *os = s11;
        uint32_t x = s11[i] ^ r3[i];
        os[i] = x;
      }
    }
  }
  uint32_t ite0;
  if
  (
    (uint64_t)(len - diff)
    % (uint64_t)(uint32_t)64U
    == (uint64_t)0U
    && (uint64_t)(len - diff) > (uint64_t)0U
  )
  {
    ite0 = (uint32_t)64U;
  }
  else
  {
    ite0 = (uint32_t)((uint64_t)(len - diff) % (uint64_t)(uint32_t)64U);
  }
  uint32_t n_blocks = (len - diff - ite0) / (uint32_t)64U;
  uint32_t data1_len = n_blocks * (uint32_t)64U;
  uint32_t data2_len = len - diff - data1_len;
  uint8_t *data11 = data2;
  uint8_t *data21 = data2 + data1_len;
  uint32_t nb = data1_len / (uint32_t)64U;
  for (uint32_t i0 = (uint32_t)0U; i0 < nb; i0++)
  {
    uint64_t ite;
    if ((uint32_t)0U == (uint32_t)0U)
    {
      ite = total_len1;
    }
    else
    {
      ite = total_len1 + (uint64_t)(uint32_t)64U;
    }
    uint64_t totlen = ite + (uint64_t)((i0 + (uint32_t)1U) * (uint32_t)64U);
    uint8_t *b = data11 + i0 * (uint32_t)64U;
    uint32_t m_w[16U] = { 0U };
    for (uint32_t i = (uint32_t)0U; i < (uint32_t)16U; i++)
    {
      uint32_t *os = m_w;
      uint8_t *bj = b + i * (uint32_t)4U;
      uint32_t u = load32_le(bj);
      uint32_t r = u;
      uint32_t x = r;
      os[i] = x;
    }
    uint32_t mask[4U] = { 0U };
    uint32_t wv_14 = (uint32_t)0U;
    uint32_t wv_15 = (uint32_t)0U;
    mask[0U] = (uint32_t)totlen;
    mask[1U] = (uint32_t)(totlen >> (uint32_t)32U);
    mask[2U] = wv_14;
    mask[3U] = wv_15;
    memcpy(block_state1.fst,
      block_state1.snd,
      (uint32_t)4U * (uint32_t)4U * sizeof (block_state1.snd[0U]));
    uint32_t *wv3 = block_state1.fst + (uint32_t)3U * (uint32_t)4U;
    for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
    {
      uint32_t *os = wv3;
      uint32_t x = wv3[i] ^ mask[i];
      os[i] = x;
    }
    for (uint32_t i1 = (uint32_t)0U; i1 < (uint32_t)10U; i1++)
    {
      uint32_t start_idx = i1 % (uint32_t)10U * (uint32_t)16U;
      KRML_CHECK_SIZE(sizeof (uint32_t), (uint32_t)4U * (uint32_t)4U);
      uint32_t m_st[(uint32_t)4U * (uint32_t)4U];
      memset(m_st, 0U, (uint32_t)4U * (uint32_t)4U * sizeof (m_st[0U]));
      uint32_t *r00 = m_st + (uint32_t)0U * (uint32_t)4U;
      uint32_t *r10 = m_st + (uint32_t)1U * (uint32_t)4U;
      uint32_t *r20 = m_st + (uint32_t)2U * (uint32_t)4U;
      uint32_t *r30 = m_st + (uint32_t)3U * (uint32_t)4U;
      uint32_t s0 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx];
      uint32_t s11 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)1U];
      uint32_t s21 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)2U];
      uint32_t s3 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)3U];
      uint32_t s4 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)4U];
      uint32_t s5 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)5U];
      uint32_t s6 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)6U];
      uint32_t s7 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)7U];
      uint32_t s8 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)8U];
      uint32_t s9 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)9U];
      uint32_t s10 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)10U];
      uint32_t s111 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)11U];
      uint32_t s12 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)12U];
      uint32_t s13 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)13U];
      uint32_t s14 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)14U];
      uint32_t s15 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)15U];
      uint32_t uu____36 = m_w[s21];
      uint32_t uu____37 = m_w[s4];
      uint32_t uu____38 = m_w[s6];
      r00[0U] = m_w[s0];
      r00[1U] = uu____36;
      r00[2U] = uu____37;
      r00[3U] = uu____38;
      uint32_t uu____39 = m_w[s3];
      uint32_t uu____40 = m_w[s5];
      uint32_t uu____41 = m_w[s7];
      r10[0U] = m_w[s11];
      r10[1U] = uu____39;
      r10[2U] = uu____40;
      r10[3U] = uu____41;
      uint32_t uu____42 = m_w[s10];
      uint32_t uu____43 = m_w[s12];
      uint32_t uu____44 = m_w[s14];
      r20[0U] = m_w[s8];
      r20[1U] = uu____42;
      r20[2U] = uu____43;
      r20[3U] = uu____44;
      uint32_t uu____45 = m_w[s111];
      uint32_t uu____46 = m_w[s13];
      uint32_t uu____47 = m_w[s15];
      r30[0U] = m_w[s9];
      r30[1U] = uu____45;
      r30[2U] = uu____46;
      r30[3U] = uu____47;
      uint32_t *x = m_st + (uint32_t)0U * (uint32_t)4U;
      uint32_t *y = m_st + (uint32_t)1U * (uint32_t)4U;
      uint32_t *z = m_st + (uint32_t)2U * (uint32_t)4U;
      uint32_t *w = m_st + (uint32_t)3U * (uint32_t)4U;
      uint32_t a = (uint32_t)0U;
      uint32_t b10 = (uint32_t)1U;
      uint32_t c0 = (uint32_t)2U;
      uint32_t d0 = (uint32_t)3U;
      uint32_t r01 = Hacl_Impl_Blake2_Constants_rTable_S[0U];
      uint32_t r12 = Hacl_Impl_Blake2_Constants_rTable_S[1U];
      uint32_t r21 = Hacl_Impl_Blake2_Constants_rTable_S[2U];
      uint32_t r31 = Hacl_Impl_Blake2_Constants_rTable_S[3U];
      uint32_t *wv_a0 = block_state1.fst + a * (uint32_t)4U;
      uint32_t *wv_b0 = block_state1.fst + b10 * (uint32_t)4U;
      for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
      {
        uint32_t *os = wv_a0;
        uint32_t x1 = wv_a0[i] + wv_b0[i];
        os[i] = x1;
      }
      for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
      {
        uint32_t *os = wv_a0;
        uint32_t x1 = wv_a0[i] + x[i];
        os[i] = x1;
      }
      uint32_t *wv_a1 = block_state1.fst + d0 * (uint32_t)4U;
      uint32_t *wv_b1 = block_state1.fst + a * (uint32_t)4U;
      for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
      {
        uint32_t *os = wv_a1;
        uint32_t x1 = wv_a1[i] ^ wv_b1[i];
        os[i] = x1;
      }
      uint32_t *r110 = wv_a1;
      for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
      {
        uint32_t *os = r110;
        uint32_t x1 = r110[i];
        uint32_t x10 = x1 >> r01 | x1 << ((uint32_t)32U - r01);
        os[i] = x10;
      }
      uint32_t *wv_a2 = block_state1.fst + c0 * (uint32_t)4U;
      uint32_t *wv_b2 = block_state1.fst + d0 * (uint32_t)4U;
      for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
      {
        uint32_t *os = wv_a2;
        uint32_t x1 = wv_a2[i] + wv_b2[i];
        os[i] = x1;
      }
      uint32_t *wv_a3 = block_state1.fst + b10 * (uint32_t)4U;
      uint32_t *wv_b3 = block_state1.fst + c0 * (uint32_t)4U;
      for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
      {
        uint32_t *os = wv_a3;
        uint32_t x1 = wv_a3[i] ^ wv_b3[i];
        os[i] = x1;
      }
      uint32_t *r111 = wv_a3;
      for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
      {
        uint32_t *os = r111;
        uint32_t x1 = r111[i];
        uint32_t x10 = x1 >> r12 | x1 << ((uint32_t)32U - r12);
        os[i] = x10;
      }
      uint32_t *wv_a4 = block_state1.fst + a * (uint32_t)4U;
      uint32_t *wv_b4 = block_state1.fst + b10 * (uint32_t)4U;
      for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
      {
        uint32_t *os = wv_a4;
        uint32_t x1 = wv_a4[i] + wv_b4[i];
        os[i] = x1;
      }
      for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
      {
        uint32_t *os = wv_a4;
        uint32_t x1 = wv_a4[i] + y[i];
        os[i] = x1;
      }
      uint32_t *wv_a5 = block_state1.fst + d0 * (uint32_t)4U;
      uint32_t *wv_b5 = block_state1.fst + a * (uint32_t)4U;
      for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
      {
        uint32_t *os = wv_a5;
        uint32_t x1 = wv_a5[i] ^ wv_b5[i];
        os[i] = x1;
      }
      uint32_t *r112 = wv_a5;
      for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
      {
        uint32_t *os = r112;
        uint32_t x1 = r112[i];
        uint32_t x10 = x1 >> r21 | x1 << ((uint32_t)32U - r21);
        os[i] = x10;
      }
      uint32_t *wv_a6 = block_state1.fst + c0 * (uint32_t)4U;
      uint32_t *wv_b6 = block_state1.fst + d0 * (uint32_t)4U;
      for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
      {
        uint32_t *os = wv_a6;
        uint32_t x1 = wv_a6[i] + wv_b6[i];
        os[i] = x1;
      }
      uint32_t *wv_a7 = block_state1.fst + b10 * (uint32_t)4U;
      uint32_t *wv_b7 = block_state1.fst + c0 * (uint32_t)4U;
      for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
      {
        uint32_t *os = wv_a7;
        uint32_t x1 = wv_a7[i] ^ wv_b7[i];
        os[i] = x1;
      }
      uint32_t *r113 = wv_a7;
      for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
      {
        uint32_t *os = r113;
        uint32_t x1 = r113[i];
        uint32_t x10 = x1 >> r31 | x1 << ((uint32_t)32U - r31);
        os[i] = x10;
      }
      uint32_t *r13 = block_state1.fst + (uint32_t)1U * (uint32_t)4U;
      uint32_t *r22 = block_state1.fst + (uint32_t)2U * (uint32_t)4U;
      uint32_t *r32 = block_state1.fst + (uint32_t)3U * (uint32_t)4U;
      uint32_t *r114 = r13;
      uint32_t x00 = r114[1U];
      uint32_t x10 = r114[((uint32_t)1U + (uint32_t)1U) % (uint32_t)4U];
      uint32_t x20 = r114[((uint32_t)1U + (uint32_t)2U) % (uint32_t)4U];
      uint32_t x30 = r114[((uint32_t)1U + (uint32_t)3U) % (uint32_t)4U];
      r114[0U] = x00;
      r114[1U] = x10;
      r114[2U] = x20;
      r114[3U] = x30;
      uint32_t *r115 = r22;
      uint32_t x01 = r115[2U];
      uint32_t x11 = r115[((uint32_t)2U + (uint32_t)1U) % (uint32_t)4U];
      uint32_t x21 = r115[((uint32_t)2U + (uint32_t)2U) % (uint32_t)4U];
      uint32_t x31 = r115[((uint32_t)2U + (uint32_t)3U) % (uint32_t)4U];
      r115[0U] = x01;
      r115[1U] = x11;
      r115[2U] = x21;
      r115[3U] = x31;
      uint32_t *r116 = r32;
      uint32_t x02 = r116[3U];
      uint32_t x12 = r116[((uint32_t)3U + (uint32_t)1U) % (uint32_t)4U];
      uint32_t x22 = r116[((uint32_t)3U + (uint32_t)2U) % (uint32_t)4U];
      uint32_t x32 = r116[((uint32_t)3U + (uint32_t)3U) % (uint32_t)4U];
      r116[0U] = x02;
      r116[1U] = x12;
      r116[2U] = x22;
      r116[3U] = x32;
      uint32_t a0 = (uint32_t)0U;
      uint32_t b1 = (uint32_t)1U;
      uint32_t c = (uint32_t)2U;
      uint32_t d = (uint32_t)3U;
      uint32_t r0 = Hacl_Impl_Blake2_Constants_rTable_S[0U];
      uint32_t r1 = Hacl_Impl_Blake2_Constants_rTable_S[1U];
      uint32_t r23 = Hacl_Impl_Blake2_Constants_rTable_S[2U];
      uint32_t r33 = Hacl_Impl_Blake2_Constants_rTable_S[3U];
      uint32_t *wv_a = block_state1.fst + a0 * (uint32_t)4U;
      uint32_t *wv_b8 = block_state1.fst + b1 * (uint32_t)4U;
      for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
      {
        uint32_t *os = wv_a;
        uint32_t x1 = wv_a[i] + wv_b8[i];
        os[i] = x1;
      }
      for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
      {
        uint32_t *os = wv_a;
        uint32_t x1 = wv_a[i] + z[i];
        os[i] = x1;
      }
      uint32_t *wv_a8 = block_state1.fst + d * (uint32_t)4U;
      uint32_t *wv_b9 = block_state1.fst + a0 * (uint32_t)4U;
      for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
      {
        uint32_t *os = wv_a8;
        uint32_t x1 = wv_a8[i] ^ wv_b9[i];
        os[i] = x1;
      }
      uint32_t *r117 = wv_a8;
      for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
      {
        uint32_t *os = r117;
        uint32_t x1 = r117[i];
        uint32_t x13 = x1 >> r0 | x1 << ((uint32_t)32U - r0);
        os[i] = x13;
      }
      uint32_t *wv_a9 = block_state1.fst + c * (uint32_t)4U;
      uint32_t *wv_b10 = block_state1.fst + d * (uint32_t)4U;
      for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
      {
        uint32_t *os = wv_a9;
        uint32_t x1 = wv_a9[i] + wv_b10[i];
        os[i] = x1;
      }
      uint32_t *wv_a10 = block_state1.fst + b1 * (uint32_t)4U;
      uint32_t *wv_b11 = block_state1.fst + c * (uint32_t)4U;
      for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
      {
        uint32_t *os = wv_a10;
        uint32_t x1 = wv_a10[i] ^ wv_b11[i];
        os[i] = x1;
      }
      uint32_t *r118 = wv_a10;
      for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
      {
        uint32_t *os = r118;
        uint32_t x1 = r118[i];
        uint32_t x13 = x1 >> r1 | x1 << ((uint32_t)32U - r1);
        os[i] = x13;
      }
      uint32_t *wv_a11 = block_state1.fst + a0 * (uint32_t)4U;
      uint32_t *wv_b12 = block_state1.fst + b1 * (uint32_t)4U;
      for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
      {
        uint32_t *os = wv_a11;
        uint32_t x1 = wv_a11[i] + wv_b12[i];
        os[i] = x1;
      }
      for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
      {
        uint32_t *os = wv_a11;
        uint32_t x1 = wv_a11[i] + w[i];
        os[i] = x1;
      }
      uint32_t *wv_a12 = block_state1.fst + d * (uint32_t)4U;
      uint32_t *wv_b13 = block_state1.fst + a0 * (uint32_t)4U;
      for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
      {
        uint32_t *os = wv_a12;
        uint32_t x1 = wv_a12[i] ^ wv_b13[i];
        os[i] = x1;
      }
      uint32_t *r119 = wv_a12;
      for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
      {
        uint32_t *os = r119;
        uint32_t x1 = r119[i];
        uint32_t x13 = x1 >> r23 | x1 << ((uint32_t)32U - r23);
        os[i] = x13;
      }
      uint32_t *wv_a13 = block_state1.fst + c * (uint32_t)4U;
      uint32_t *wv_b14 = block_state1.fst + d * (uint32_t)4U;
      for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
      {
        uint32_t *os = wv_a13;
        uint32_t x1 = wv_a13[i] + wv_b14[i];
        os[i] = x1;
      }
      uint32_t *wv_a14 = block_state1.fst + b1 * (uint32_t)4U;
      uint32_t *wv_b = block_state1.fst + c * (uint32_t)4U;
      for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
      {
        uint32_t *os = wv_a14;
        uint32_t x1 = wv_a14[i] ^ wv_b[i];
        os[i] = x1;
      }
      uint32_t *r1110 = wv_a14;
      for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
      {
        uint32_t *os = r1110;
        uint32_t x1 = r1110[i];
        uint32_t x13 = x1 >> r33 | x1 << ((uint32_t)32U - r33);
        os[i] = x13;
      }
      uint32_t *r14 = block_state1.fst + (uint32_t)1U * (uint32_t)4U;
      uint32_t *r2 = block_state1.fst + (uint32_t)2U * (uint32_t)4U;
      uint32_t *r3 = block_state1.fst + (uint32_t)3U * (uint32_t)4U;
      uint32_t *r11 = r14;
      uint32_t x03 = r11[3U];
      uint32_t x13 = r11[((uint32_t)3U + (uint32_t)1U) % (uint32_t)4U];
      uint32_t x23 = r11[((uint32_t)3U + (uint32_t)2U) % (uint32_t)4U];
      uint32_t x33 = r11[((uint32_t)3U + (uint32_t)3U) % (uint32_t)4U];
      r11[0U] = x03;
      r11[1U] = x13;
      r11[2U] = x23;
      r11[3U] = x33;
      uint32_t *r1111 = r2;
      uint32_t x04 = r1111[2U];
      uint32_t x14 = r1111[((uint32_t)2U + (uint32_t)1U) % (uint32_t)4U];
      uint32_t x24 = r1111[((uint32_t)2U + (uint32_t)2U) % (uint32_t)4U];
      uint32_t x34 = r1111[((uint32_t)2U + (uint32_t)3U) % (uint32_t)4U];
      r1111[0U] = x04;
      r1111[1U] = x14;
      r1111[2U] = x24;
      r1111[3U] = x34;
      uint32_t *r1112 = r3;
      uint32_t x0 = r1112[1U];
      uint32_t x1 = r1112[((uint32_t)1U + (uint32_t)1U) % (uint32_t)4U];
      uint32_t x2 = r1112[((uint32_t)1U + (uint32_t)2U) % (uint32_t)4U];
      uint32_t x3 = r1112[((uint32_t)1U + (uint32_t)3U) % (uint32_t)4U];
      r1112[0U] = x0;
      r1112[1U] = x1;
      r1112[2U] = x2;
      r1112[3U] = x3;
    }
    uint32_t *s0 = block_state1.snd + (uint32_t)0U * (uint32_t)4U;
    uint32_t *s11 = block_state1.snd + (uint32_t)1U * (uint32_t)4U;
    uint32_t *r0 = block_state1.fst + (uint32_t)0U * (uint32_t)4U;
    uint32_t *r1 = block_state1.fst + (uint32_t)1U * (uint32_t)4U;
    uint32_t *r2 = block_state1.fst + (uint32_t)2U * (uint32_t)4U;
    uint32_t *r3 = block_state1.fst + (uint32_t)3U * (uint32_t)4U;
    for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
    {
      uint32_t *os = s0;
      uint32_t x = s0[i] ^ r0[i];
      os[i] = x;
    }
    for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
    {
      uint32_t *os = s0;
      uint32_t x = s0[i] ^ r2[i];
      os[i] = x;
    }
    for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
    {
      uint32_t *os = s11;
      uint32_t x = s11[i] ^ r1[i];
      os[i] = x;
    }
    for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
    {
      uint32_t *os = s11;
      uint32_t x = s11[i] ^ r3[i];
      os[i] = x;
    }
  }
  uint8_t *dst = buf;
  memcpy(dst, data21, data2_len * sizeof (data21[0U]));
  *p
  =
    (
      (Hacl_Streaming_Functor_state_s__K____uint32_t___uint32_t____){
        .block_state = block_state1,
        .buf = buf,
        .total_len = total_len1 + (uint64_t)(len - diff)
      }
    );
}

/* SNIPPET_END: Hacl_Streaming_Blake2_blake2s_32_no_key_update */

/* SNIPPET_START: Hacl_Streaming_Blake2_blake2s_32_no_key_finish */

/*
  Finish function when there is no key
*/
void
Hacl_Streaming_Blake2_blake2s_32_no_key_finish(
  Hacl_Streaming_Functor_state_s__K____uint32_t___uint32_t____ *p,
  uint8_t *dst
)
{
  Hacl_Streaming_Functor_state_s__K____uint32_t___uint32_t____ scrut = *p;
  K____uint32_t___uint32_t_ block_state = scrut.block_state;
  uint8_t *buf_ = scrut.buf;
  uint64_t total_len = scrut.total_len;
  uint32_t r;
  if (total_len % (uint64_t)(uint32_t)64U == (uint64_t)0U && total_len > (uint64_t)0U)
  {
    r = (uint32_t)64U;
  }
  else
  {
    r = (uint32_t)(total_len % (uint64_t)(uint32_t)64U);
  }
  uint8_t *buf_1 = buf_;
  KRML_CHECK_SIZE(sizeof (uint32_t), (uint32_t)4U * (uint32_t)4U);
  uint32_t wv[(uint32_t)4U * (uint32_t)4U];
  memset(wv, 0U, (uint32_t)4U * (uint32_t)4U * sizeof (wv[0U]));
  KRML_CHECK_SIZE(sizeof (uint32_t), (uint32_t)4U * (uint32_t)4U);
  uint32_t b0[(uint32_t)4U * (uint32_t)4U];
  memset(b0, 0U, (uint32_t)4U * (uint32_t)4U * sizeof (b0[0U]));
  K____uint32_t___uint32_t_ tmp_block_state = { .fst = wv, .snd = b0 };
  uint32_t *src_b = block_state.snd;
  uint32_t *dst_b = tmp_block_state.snd;
  memcpy(dst_b, src_b, (uint32_t)16U * sizeof (src_b[0U]));
  uint64_t prev_len = total_len - (uint64_t)r;
  uint8_t b2[64U] = { 0U };
  uint8_t *last = buf_1 + r - r;
  memcpy(b2, last, r * sizeof (last[0U]));
  uint64_t ite;
  if ((uint32_t)0U == (uint32_t)0U)
  {
    ite = prev_len;
  }
  else
  {
    ite = prev_len + (uint64_t)(uint32_t)64U;
  }
  uint64_t totlen = ite + (uint64_t)r;
  uint32_t m_w[16U] = { 0U };
  for (uint32_t i = (uint32_t)0U; i < (uint32_t)16U; i++)
  {
    uint32_t *os = m_w;
    uint8_t *bj = b2 + i * (uint32_t)4U;
    uint32_t u = load32_le(bj);
    uint32_t r1 = u;
    uint32_t x = r1;
    os[i] = x;
  }
  uint32_t mask[4U] = { 0U };
  uint32_t wv_14 = (uint32_t)0xFFFFFFFFU;
  uint32_t wv_15 = (uint32_t)0U;
  mask[0U] = (uint32_t)totlen;
  mask[1U] = (uint32_t)(totlen >> (uint32_t)32U);
  mask[2U] = wv_14;
  mask[3U] = wv_15;
  memcpy(tmp_block_state.fst,
    tmp_block_state.snd,
    (uint32_t)4U * (uint32_t)4U * sizeof (tmp_block_state.snd[0U]));
  uint32_t *wv3 = tmp_block_state.fst + (uint32_t)3U * (uint32_t)4U;
  for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
  {
    uint32_t *os = wv3;
    uint32_t x = wv3[i] ^ mask[i];
    os[i] = x;
  }
  for (uint32_t i0 = (uint32_t)0U; i0 < (uint32_t)10U; i0++)
  {
    uint32_t start_idx = i0 % (uint32_t)10U * (uint32_t)16U;
    KRML_CHECK_SIZE(sizeof (uint32_t), (uint32_t)4U * (uint32_t)4U);
    uint32_t m_st[(uint32_t)4U * (uint32_t)4U];
    memset(m_st, 0U, (uint32_t)4U * (uint32_t)4U * sizeof (m_st[0U]));
    uint32_t *r00 = m_st + (uint32_t)0U * (uint32_t)4U;
    uint32_t *r10 = m_st + (uint32_t)1U * (uint32_t)4U;
    uint32_t *r20 = m_st + (uint32_t)2U * (uint32_t)4U;
    uint32_t *r30 = m_st + (uint32_t)3U * (uint32_t)4U;
    uint32_t s0 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx];
    uint32_t s1 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)1U];
    uint32_t s2 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)2U];
    uint32_t s3 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)3U];
    uint32_t s4 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)4U];
    uint32_t s5 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)5U];
    uint32_t s6 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)6U];
    uint32_t s7 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)7U];
    uint32_t s8 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)8U];
    uint32_t s9 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)9U];
    uint32_t s10 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)10U];
    uint32_t s11 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)11U];
    uint32_t s12 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)12U];
    uint32_t s13 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)13U];
    uint32_t s14 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)14U];
    uint32_t s15 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)15U];
    uint32_t uu____0 = m_w[s2];
    uint32_t uu____1 = m_w[s4];
    uint32_t uu____2 = m_w[s6];
    r00[0U] = m_w[s0];
    r00[1U] = uu____0;
    r00[2U] = uu____1;
    r00[3U] = uu____2;
    uint32_t uu____3 = m_w[s3];
    uint32_t uu____4 = m_w[s5];
    uint32_t uu____5 = m_w[s7];
    r10[0U] = m_w[s1];
    r10[1U] = uu____3;
    r10[2U] = uu____4;
    r10[3U] = uu____5;
    uint32_t uu____6 = m_w[s10];
    uint32_t uu____7 = m_w[s12];
    uint32_t uu____8 = m_w[s14];
    r20[0U] = m_w[s8];
    r20[1U] = uu____6;
    r20[2U] = uu____7;
    r20[3U] = uu____8;
    uint32_t uu____9 = m_w[s11];
    uint32_t uu____10 = m_w[s13];
    uint32_t uu____11 = m_w[s15];
    r30[0U] = m_w[s9];
    r30[1U] = uu____9;
    r30[2U] = uu____10;
    r30[3U] = uu____11;
    uint32_t *x = m_st + (uint32_t)0U * (uint32_t)4U;
    uint32_t *y = m_st + (uint32_t)1U * (uint32_t)4U;
    uint32_t *z = m_st + (uint32_t)2U * (uint32_t)4U;
    uint32_t *w = m_st + (uint32_t)3U * (uint32_t)4U;
    uint32_t a = (uint32_t)0U;
    uint32_t b10 = (uint32_t)1U;
    uint32_t c0 = (uint32_t)2U;
    uint32_t d0 = (uint32_t)3U;
    uint32_t r01 = Hacl_Impl_Blake2_Constants_rTable_S[0U];
    uint32_t r12 = Hacl_Impl_Blake2_Constants_rTable_S[1U];
    uint32_t r21 = Hacl_Impl_Blake2_Constants_rTable_S[2U];
    uint32_t r31 = Hacl_Impl_Blake2_Constants_rTable_S[3U];
    uint32_t *wv_a0 = tmp_block_state.fst + a * (uint32_t)4U;
    uint32_t *wv_b0 = tmp_block_state.fst + b10 * (uint32_t)4U;
    for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
    {
      uint32_t *os = wv_a0;
      uint32_t x1 = wv_a0[i] + wv_b0[i];
      os[i] = x1;
    }
    for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
    {
      uint32_t *os = wv_a0;
      uint32_t x1 = wv_a0[i] + x[i];
      os[i] = x1;
    }
    uint32_t *wv_a1 = tmp_block_state.fst + d0 * (uint32_t)4U;
    uint32_t *wv_b1 = tmp_block_state.fst + a * (uint32_t)4U;
    for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
    {
      uint32_t *os = wv_a1;
      uint32_t x1 = wv_a1[i] ^ wv_b1[i];
      os[i] = x1;
    }
    uint32_t *r110 = wv_a1;
    for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
    {
      uint32_t *os = r110;
      uint32_t x1 = r110[i];
      uint32_t x10 = x1 >> r01 | x1 << ((uint32_t)32U - r01);
      os[i] = x10;
    }
    uint32_t *wv_a2 = tmp_block_state.fst + c0 * (uint32_t)4U;
    uint32_t *wv_b2 = tmp_block_state.fst + d0 * (uint32_t)4U;
    for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
    {
      uint32_t *os = wv_a2;
      uint32_t x1 = wv_a2[i] + wv_b2[i];
      os[i] = x1;
    }
    uint32_t *wv_a3 = tmp_block_state.fst + b10 * (uint32_t)4U;
    uint32_t *wv_b3 = tmp_block_state.fst + c0 * (uint32_t)4U;
    for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
    {
      uint32_t *os = wv_a3;
      uint32_t x1 = wv_a3[i] ^ wv_b3[i];
      os[i] = x1;
    }
    uint32_t *r111 = wv_a3;
    for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
    {
      uint32_t *os = r111;
      uint32_t x1 = r111[i];
      uint32_t x10 = x1 >> r12 | x1 << ((uint32_t)32U - r12);
      os[i] = x10;
    }
    uint32_t *wv_a4 = tmp_block_state.fst + a * (uint32_t)4U;
    uint32_t *wv_b4 = tmp_block_state.fst + b10 * (uint32_t)4U;
    for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
    {
      uint32_t *os = wv_a4;
      uint32_t x1 = wv_a4[i] + wv_b4[i];
      os[i] = x1;
    }
    for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
    {
      uint32_t *os = wv_a4;
      uint32_t x1 = wv_a4[i] + y[i];
      os[i] = x1;
    }
    uint32_t *wv_a5 = tmp_block_state.fst + d0 * (uint32_t)4U;
    uint32_t *wv_b5 = tmp_block_state.fst + a * (uint32_t)4U;
    for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
    {
      uint32_t *os = wv_a5;
      uint32_t x1 = wv_a5[i] ^ wv_b5[i];
      os[i] = x1;
    }
    uint32_t *r112 = wv_a5;
    for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
    {
      uint32_t *os = r112;
      uint32_t x1 = r112[i];
      uint32_t x10 = x1 >> r21 | x1 << ((uint32_t)32U - r21);
      os[i] = x10;
    }
    uint32_t *wv_a6 = tmp_block_state.fst + c0 * (uint32_t)4U;
    uint32_t *wv_b6 = tmp_block_state.fst + d0 * (uint32_t)4U;
    for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
    {
      uint32_t *os = wv_a6;
      uint32_t x1 = wv_a6[i] + wv_b6[i];
      os[i] = x1;
    }
    uint32_t *wv_a7 = tmp_block_state.fst + b10 * (uint32_t)4U;
    uint32_t *wv_b7 = tmp_block_state.fst + c0 * (uint32_t)4U;
    for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
    {
      uint32_t *os = wv_a7;
      uint32_t x1 = wv_a7[i] ^ wv_b7[i];
      os[i] = x1;
    }
    uint32_t *r113 = wv_a7;
    for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
    {
      uint32_t *os = r113;
      uint32_t x1 = r113[i];
      uint32_t x10 = x1 >> r31 | x1 << ((uint32_t)32U - r31);
      os[i] = x10;
    }
    uint32_t *r13 = tmp_block_state.fst + (uint32_t)1U * (uint32_t)4U;
    uint32_t *r22 = tmp_block_state.fst + (uint32_t)2U * (uint32_t)4U;
    uint32_t *r32 = tmp_block_state.fst + (uint32_t)3U * (uint32_t)4U;
    uint32_t *r114 = r13;
    uint32_t x00 = r114[1U];
    uint32_t x10 = r114[((uint32_t)1U + (uint32_t)1U) % (uint32_t)4U];
    uint32_t x20 = r114[((uint32_t)1U + (uint32_t)2U) % (uint32_t)4U];
    uint32_t x30 = r114[((uint32_t)1U + (uint32_t)3U) % (uint32_t)4U];
    r114[0U] = x00;
    r114[1U] = x10;
    r114[2U] = x20;
    r114[3U] = x30;
    uint32_t *r115 = r22;
    uint32_t x01 = r115[2U];
    uint32_t x11 = r115[((uint32_t)2U + (uint32_t)1U) % (uint32_t)4U];
    uint32_t x21 = r115[((uint32_t)2U + (uint32_t)2U) % (uint32_t)4U];
    uint32_t x31 = r115[((uint32_t)2U + (uint32_t)3U) % (uint32_t)4U];
    r115[0U] = x01;
    r115[1U] = x11;
    r115[2U] = x21;
    r115[3U] = x31;
    uint32_t *r116 = r32;
    uint32_t x02 = r116[3U];
    uint32_t x12 = r116[((uint32_t)3U + (uint32_t)1U) % (uint32_t)4U];
    uint32_t x22 = r116[((uint32_t)3U + (uint32_t)2U) % (uint32_t)4U];
    uint32_t x32 = r116[((uint32_t)3U + (uint32_t)3U) % (uint32_t)4U];
    r116[0U] = x02;
    r116[1U] = x12;
    r116[2U] = x22;
    r116[3U] = x32;
    uint32_t a0 = (uint32_t)0U;
    uint32_t b1 = (uint32_t)1U;
    uint32_t c = (uint32_t)2U;
    uint32_t d = (uint32_t)3U;
    uint32_t r0 = Hacl_Impl_Blake2_Constants_rTable_S[0U];
    uint32_t r1 = Hacl_Impl_Blake2_Constants_rTable_S[1U];
    uint32_t r23 = Hacl_Impl_Blake2_Constants_rTable_S[2U];
    uint32_t r33 = Hacl_Impl_Blake2_Constants_rTable_S[3U];
    uint32_t *wv_a = tmp_block_state.fst + a0 * (uint32_t)4U;
    uint32_t *wv_b8 = tmp_block_state.fst + b1 * (uint32_t)4U;
    for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
    {
      uint32_t *os = wv_a;
      uint32_t x1 = wv_a[i] + wv_b8[i];
      os[i] = x1;
    }
    for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
    {
      uint32_t *os = wv_a;
      uint32_t x1 = wv_a[i] + z[i];
      os[i] = x1;
    }
    uint32_t *wv_a8 = tmp_block_state.fst + d * (uint32_t)4U;
    uint32_t *wv_b9 = tmp_block_state.fst + a0 * (uint32_t)4U;
    for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
    {
      uint32_t *os = wv_a8;
      uint32_t x1 = wv_a8[i] ^ wv_b9[i];
      os[i] = x1;
    }
    uint32_t *r117 = wv_a8;
    for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
    {
      uint32_t *os = r117;
      uint32_t x1 = r117[i];
      uint32_t x13 = x1 >> r0 | x1 << ((uint32_t)32U - r0);
      os[i] = x13;
    }
    uint32_t *wv_a9 = tmp_block_state.fst + c * (uint32_t)4U;
    uint32_t *wv_b10 = tmp_block_state.fst + d * (uint32_t)4U;
    for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
    {
      uint32_t *os = wv_a9;
      uint32_t x1 = wv_a9[i] + wv_b10[i];
      os[i] = x1;
    }
    uint32_t *wv_a10 = tmp_block_state.fst + b1 * (uint32_t)4U;
    uint32_t *wv_b11 = tmp_block_state.fst + c * (uint32_t)4U;
    for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
    {
      uint32_t *os = wv_a10;
      uint32_t x1 = wv_a10[i] ^ wv_b11[i];
      os[i] = x1;
    }
    uint32_t *r118 = wv_a10;
    for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
    {
      uint32_t *os = r118;
      uint32_t x1 = r118[i];
      uint32_t x13 = x1 >> r1 | x1 << ((uint32_t)32U - r1);
      os[i] = x13;
    }
    uint32_t *wv_a11 = tmp_block_state.fst + a0 * (uint32_t)4U;
    uint32_t *wv_b12 = tmp_block_state.fst + b1 * (uint32_t)4U;
    for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
    {
      uint32_t *os = wv_a11;
      uint32_t x1 = wv_a11[i] + wv_b12[i];
      os[i] = x1;
    }
    for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
    {
      uint32_t *os = wv_a11;
      uint32_t x1 = wv_a11[i] + w[i];
      os[i] = x1;
    }
    uint32_t *wv_a12 = tmp_block_state.fst + d * (uint32_t)4U;
    uint32_t *wv_b13 = tmp_block_state.fst + a0 * (uint32_t)4U;
    for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
    {
      uint32_t *os = wv_a12;
      uint32_t x1 = wv_a12[i] ^ wv_b13[i];
      os[i] = x1;
    }
    uint32_t *r119 = wv_a12;
    for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
    {
      uint32_t *os = r119;
      uint32_t x1 = r119[i];
      uint32_t x13 = x1 >> r23 | x1 << ((uint32_t)32U - r23);
      os[i] = x13;
    }
    uint32_t *wv_a13 = tmp_block_state.fst + c * (uint32_t)4U;
    uint32_t *wv_b14 = tmp_block_state.fst + d * (uint32_t)4U;
    for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
    {
      uint32_t *os = wv_a13;
      uint32_t x1 = wv_a13[i] + wv_b14[i];
      os[i] = x1;
    }
    uint32_t *wv_a14 = tmp_block_state.fst + b1 * (uint32_t)4U;
    uint32_t *wv_b = tmp_block_state.fst + c * (uint32_t)4U;
    for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
    {
      uint32_t *os = wv_a14;
      uint32_t x1 = wv_a14[i] ^ wv_b[i];
      os[i] = x1;
    }
    uint32_t *r1110 = wv_a14;
    for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
    {
      uint32_t *os = r1110;
      uint32_t x1 = r1110[i];
      uint32_t x13 = x1 >> r33 | x1 << ((uint32_t)32U - r33);
      os[i] = x13;
    }
    uint32_t *r14 = tmp_block_state.fst + (uint32_t)1U * (uint32_t)4U;
    uint32_t *r2 = tmp_block_state.fst + (uint32_t)2U * (uint32_t)4U;
    uint32_t *r3 = tmp_block_state.fst + (uint32_t)3U * (uint32_t)4U;
    uint32_t *r11 = r14;
    uint32_t x03 = r11[3U];
    uint32_t x13 = r11[((uint32_t)3U + (uint32_t)1U) % (uint32_t)4U];
    uint32_t x23 = r11[((uint32_t)3U + (uint32_t)2U) % (uint32_t)4U];
    uint32_t x33 = r11[((uint32_t)3U + (uint32_t)3U) % (uint32_t)4U];
    r11[0U] = x03;
    r11[1U] = x13;
    r11[2U] = x23;
    r11[3U] = x33;
    uint32_t *r1111 = r2;
    uint32_t x04 = r1111[2U];
    uint32_t x14 = r1111[((uint32_t)2U + (uint32_t)1U) % (uint32_t)4U];
    uint32_t x24 = r1111[((uint32_t)2U + (uint32_t)2U) % (uint32_t)4U];
    uint32_t x34 = r1111[((uint32_t)2U + (uint32_t)3U) % (uint32_t)4U];
    r1111[0U] = x04;
    r1111[1U] = x14;
    r1111[2U] = x24;
    r1111[3U] = x34;
    uint32_t *r1112 = r3;
    uint32_t x0 = r1112[1U];
    uint32_t x1 = r1112[((uint32_t)1U + (uint32_t)1U) % (uint32_t)4U];
    uint32_t x2 = r1112[((uint32_t)1U + (uint32_t)2U) % (uint32_t)4U];
    uint32_t x3 = r1112[((uint32_t)1U + (uint32_t)3U) % (uint32_t)4U];
    r1112[0U] = x0;
    r1112[1U] = x1;
    r1112[2U] = x2;
    r1112[3U] = x3;
  }
  uint32_t *s0 = tmp_block_state.snd + (uint32_t)0U * (uint32_t)4U;
  uint32_t *s1 = tmp_block_state.snd + (uint32_t)1U * (uint32_t)4U;
  uint32_t *r0 = tmp_block_state.fst + (uint32_t)0U * (uint32_t)4U;
  uint32_t *r1 = tmp_block_state.fst + (uint32_t)1U * (uint32_t)4U;
  uint32_t *r2 = tmp_block_state.fst + (uint32_t)2U * (uint32_t)4U;
  uint32_t *r3 = tmp_block_state.fst + (uint32_t)3U * (uint32_t)4U;
  for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
  {
    uint32_t *os = s0;
    uint32_t x = s0[i] ^ r0[i];
    os[i] = x;
  }
  for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
  {
    uint32_t *os = s0;
    uint32_t x = s0[i] ^ r2[i];
    os[i] = x;
  }
  for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
  {
    uint32_t *os = s1;
    uint32_t x = s1[i] ^ r1[i];
    os[i] = x;
  }
  for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
  {
    uint32_t *os = s1;
    uint32_t x = s1[i] ^ r3[i];
    os[i] = x;
  }
  Lib_Memzero0_memzero(b2, (uint32_t)64U * sizeof (b2[0U]));
  uint32_t double_row = (uint32_t)2U * (uint32_t)4U * (uint32_t)4U;
  KRML_CHECK_SIZE(sizeof (uint8_t), double_row);
  uint8_t b[double_row];
  memset(b, 0U, double_row * sizeof (b[0U]));
  uint8_t *first = b;
  uint8_t *second = b + (uint32_t)4U * (uint32_t)4U;
  uint32_t *row0 = tmp_block_state.snd + (uint32_t)0U * (uint32_t)4U;
  uint32_t *row1 = tmp_block_state.snd + (uint32_t)1U * (uint32_t)4U;
  for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
  {
    store32_le(first + i * (uint32_t)4U, row0[i]);
  }
  for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
  {
    store32_le(second + i * (uint32_t)4U, row1[i]);
  }
  uint8_t *final = b;
  memcpy(dst, final, (uint32_t)32U * sizeof (final[0U]));
  Lib_Memzero0_memzero(b, double_row * sizeof (b[0U]));
}

/* SNIPPET_END: Hacl_Streaming_Blake2_blake2s_32_no_key_finish */

/* SNIPPET_START: Hacl_Streaming_Blake2_blake2s_32_no_key_free */

/*
  Free state function when there is no key
*/
void
Hacl_Streaming_Blake2_blake2s_32_no_key_free(
  Hacl_Streaming_Functor_state_s__K____uint32_t___uint32_t____ *s1
)
{
  Hacl_Streaming_Functor_state_s__K____uint32_t___uint32_t____ scrut = *s1;
  uint8_t *buf = scrut.buf;
  K____uint32_t___uint32_t_ block_state = scrut.block_state;
  uint32_t *wv = block_state.fst;
  uint32_t *b = block_state.snd;
  KRML_HOST_FREE(wv);
  KRML_HOST_FREE(b);
  KRML_HOST_FREE(buf);
  KRML_HOST_FREE(s1);
}

/* SNIPPET_END: Hacl_Streaming_Blake2_blake2s_32_no_key_free */

/* SNIPPET_START: Hacl_Streaming_Functor_state_s__K____Lib_IntVector_Intrinsics_vec128___Lib_IntVector_Intrinsics_vec128____ */

typedef struct
Hacl_Streaming_Functor_state_s__K____Lib_IntVector_Intrinsics_vec128___Lib_IntVector_Intrinsics_vec128_____s
{
  K____Lib_IntVector_Intrinsics_vec128___Lib_IntVector_Intrinsics_vec128_ block_state;
  uint8_t *buf;
  uint64_t total_len;
}
Hacl_Streaming_Functor_state_s__K____Lib_IntVector_Intrinsics_vec128___Lib_IntVector_Intrinsics_vec128____;

/* SNIPPET_END: Hacl_Streaming_Functor_state_s__K____Lib_IntVector_Intrinsics_vec128___Lib_IntVector_Intrinsics_vec128____ */

/* SNIPPET_START: Hacl_Streaming_Blake2_blake2s_128_no_key_create_in */

/*
  State allocation function when there is no key
*/
Hacl_Streaming_Functor_state_s__K____Lib_IntVector_Intrinsics_vec128___Lib_IntVector_Intrinsics_vec128____
*Hacl_Streaming_Blake2_blake2s_128_no_key_create_in()
{
  uint8_t *buf = KRML_HOST_CALLOC((uint32_t)64U, sizeof (uint8_t));
  Lib_IntVector_Intrinsics_vec128
  *wv = KRML_HOST_MALLOC(sizeof (Lib_IntVector_Intrinsics_vec128) * (uint32_t)4U);
  for (uint32_t _i = 0U; _i < (uint32_t)4U; ++_i)
    wv[_i] = Lib_IntVector_Intrinsics_vec128_zero;
  Lib_IntVector_Intrinsics_vec128
  *b0 = KRML_HOST_MALLOC(sizeof (Lib_IntVector_Intrinsics_vec128) * (uint32_t)4U);
  for (uint32_t _i = 0U; _i < (uint32_t)4U; ++_i)
    b0[_i] = Lib_IntVector_Intrinsics_vec128_zero;
  K____Lib_IntVector_Intrinsics_vec128___Lib_IntVector_Intrinsics_vec128_
  block_state = { .fst = wv, .snd = b0 };
  Hacl_Streaming_Functor_state_s__K____Lib_IntVector_Intrinsics_vec128___Lib_IntVector_Intrinsics_vec128____
  s1 = { .block_state = block_state, .buf = buf, .total_len = (uint64_t)0U };
  KRML_CHECK_SIZE(sizeof (
      Hacl_Streaming_Functor_state_s__K____Lib_IntVector_Intrinsics_vec128___Lib_IntVector_Intrinsics_vec128____
    ),
    (uint32_t)1U);
  Hacl_Streaming_Functor_state_s__K____Lib_IntVector_Intrinsics_vec128___Lib_IntVector_Intrinsics_vec128____
  *p =
    KRML_HOST_MALLOC(sizeof (
        Hacl_Streaming_Functor_state_s__K____Lib_IntVector_Intrinsics_vec128___Lib_IntVector_Intrinsics_vec128____
      ));
  p[0U] = s1;
  uint8_t b[64U] = { 0U };
  Lib_IntVector_Intrinsics_vec128 *r00 = block_state.snd + (uint32_t)0U * (uint32_t)1U;
  Lib_IntVector_Intrinsics_vec128 *r10 = block_state.snd + (uint32_t)1U * (uint32_t)1U;
  Lib_IntVector_Intrinsics_vec128 *r20 = block_state.snd + (uint32_t)2U * (uint32_t)1U;
  Lib_IntVector_Intrinsics_vec128 *r30 = block_state.snd + (uint32_t)3U * (uint32_t)1U;
  uint32_t iv0 = Hacl_Impl_Blake2_Constants_ivTable_S[0U];
  uint32_t iv1 = Hacl_Impl_Blake2_Constants_ivTable_S[1U];
  uint32_t iv2 = Hacl_Impl_Blake2_Constants_ivTable_S[2U];
  uint32_t iv3 = Hacl_Impl_Blake2_Constants_ivTable_S[3U];
  uint32_t iv4 = Hacl_Impl_Blake2_Constants_ivTable_S[4U];
  uint32_t iv5 = Hacl_Impl_Blake2_Constants_ivTable_S[5U];
  uint32_t iv6 = Hacl_Impl_Blake2_Constants_ivTable_S[6U];
  uint32_t iv7 = Hacl_Impl_Blake2_Constants_ivTable_S[7U];
  r20[0U] = Lib_IntVector_Intrinsics_vec128_load32s(iv0, iv1, iv2, iv3);
  r30[0U] = Lib_IntVector_Intrinsics_vec128_load32s(iv4, iv5, iv6, iv7);
  uint32_t kk_shift_8 = (uint32_t)0U;
  uint32_t iv0_ = iv0 ^ ((uint32_t)0x01010000U ^ (kk_shift_8 ^ (uint32_t)32U));
  r00[0U] = Lib_IntVector_Intrinsics_vec128_load32s(iv0_, iv1, iv2, iv3);
  r10[0U] = Lib_IntVector_Intrinsics_vec128_load32s(iv4, iv5, iv6, iv7);
  if (!((uint32_t)0U == (uint32_t)0U))
  {
    memcpy(b, NULL, (uint32_t)0U * sizeof (NULL[0U]));
    uint64_t totlen = (uint64_t)(uint32_t)0U + (uint64_t)(uint32_t)64U;
    uint8_t *b1 = b + (uint32_t)0U * (uint32_t)64U;
    uint32_t m_w[16U] = { 0U };
    for (uint32_t i = (uint32_t)0U; i < (uint32_t)16U; i++)
    {
      uint32_t *os = m_w;
      uint8_t *bj = b1 + i * (uint32_t)4U;
      uint32_t u = load32_le(bj);
      uint32_t r1 = u;
      uint32_t x = r1;
      os[i] = x;
    }
    Lib_IntVector_Intrinsics_vec128 mask = Lib_IntVector_Intrinsics_vec128_zero;
    uint32_t wv_14 = (uint32_t)0U;
    uint32_t wv_15 = (uint32_t)0U;
    mask =
      Lib_IntVector_Intrinsics_vec128_load32s((uint32_t)totlen,
        (uint32_t)(totlen >> (uint32_t)32U),
        wv_14,
        wv_15);
    memcpy(block_state.fst,
      block_state.snd,
      (uint32_t)4U * (uint32_t)1U * sizeof (block_state.snd[0U]));
    Lib_IntVector_Intrinsics_vec128 *wv3 = block_state.fst + (uint32_t)3U * (uint32_t)1U;
    wv3[0U] = Lib_IntVector_Intrinsics_vec128_xor(wv3[0U], mask);
    for (uint32_t i = (uint32_t)0U; i < (uint32_t)10U; i++)
    {
      uint32_t start_idx = i % (uint32_t)10U * (uint32_t)16U;
      KRML_CHECK_SIZE(sizeof (Lib_IntVector_Intrinsics_vec128), (uint32_t)4U * (uint32_t)1U);
      Lib_IntVector_Intrinsics_vec128 m_st[(uint32_t)4U * (uint32_t)1U];
      for (uint32_t _i = 0U; _i < (uint32_t)4U * (uint32_t)1U; ++_i)
        m_st[_i] = Lib_IntVector_Intrinsics_vec128_zero;
      Lib_IntVector_Intrinsics_vec128 *r01 = m_st + (uint32_t)0U * (uint32_t)1U;
      Lib_IntVector_Intrinsics_vec128 *r11 = m_st + (uint32_t)1U * (uint32_t)1U;
      Lib_IntVector_Intrinsics_vec128 *r21 = m_st + (uint32_t)2U * (uint32_t)1U;
      Lib_IntVector_Intrinsics_vec128 *r31 = m_st + (uint32_t)3U * (uint32_t)1U;
      uint32_t s0 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx];
      uint32_t s11 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)1U];
      uint32_t s2 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)2U];
      uint32_t s3 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)3U];
      uint32_t s4 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)4U];
      uint32_t s5 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)5U];
      uint32_t s6 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)6U];
      uint32_t s7 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)7U];
      uint32_t s8 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)8U];
      uint32_t s9 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)9U];
      uint32_t s10 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)10U];
      uint32_t s111 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)11U];
      uint32_t s12 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)12U];
      uint32_t s13 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)13U];
      uint32_t s14 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)14U];
      uint32_t s15 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)15U];
      r01[0U] = Lib_IntVector_Intrinsics_vec128_load32s(m_w[s0], m_w[s2], m_w[s4], m_w[s6]);
      r11[0U] = Lib_IntVector_Intrinsics_vec128_load32s(m_w[s11], m_w[s3], m_w[s5], m_w[s7]);
      r21[0U] = Lib_IntVector_Intrinsics_vec128_load32s(m_w[s8], m_w[s10], m_w[s12], m_w[s14]);
      r31[0U] = Lib_IntVector_Intrinsics_vec128_load32s(m_w[s9], m_w[s111], m_w[s13], m_w[s15]);
      Lib_IntVector_Intrinsics_vec128 *x = m_st + (uint32_t)0U * (uint32_t)1U;
      Lib_IntVector_Intrinsics_vec128 *y = m_st + (uint32_t)1U * (uint32_t)1U;
      Lib_IntVector_Intrinsics_vec128 *z = m_st + (uint32_t)2U * (uint32_t)1U;
      Lib_IntVector_Intrinsics_vec128 *w = m_st + (uint32_t)3U * (uint32_t)1U;
      uint32_t a = (uint32_t)0U;
      uint32_t b20 = (uint32_t)1U;
      uint32_t c0 = (uint32_t)2U;
      uint32_t d0 = (uint32_t)3U;
      uint32_t r02 = Hacl_Impl_Blake2_Constants_rTable_S[0U];
      uint32_t r12 = Hacl_Impl_Blake2_Constants_rTable_S[1U];
      uint32_t r22 = Hacl_Impl_Blake2_Constants_rTable_S[2U];
      uint32_t r32 = Hacl_Impl_Blake2_Constants_rTable_S[3U];
      Lib_IntVector_Intrinsics_vec128 *wv_a0 = block_state.fst + a * (uint32_t)1U;
      Lib_IntVector_Intrinsics_vec128 *wv_b0 = block_state.fst + b20 * (uint32_t)1U;
      wv_a0[0U] = Lib_IntVector_Intrinsics_vec128_add32(wv_a0[0U], wv_b0[0U]);
      wv_a0[0U] = Lib_IntVector_Intrinsics_vec128_add32(wv_a0[0U], x[0U]);
      Lib_IntVector_Intrinsics_vec128 *wv_a1 = block_state.fst + d0 * (uint32_t)1U;
      Lib_IntVector_Intrinsics_vec128 *wv_b1 = block_state.fst + a * (uint32_t)1U;
      wv_a1[0U] = Lib_IntVector_Intrinsics_vec128_xor(wv_a1[0U], wv_b1[0U]);
      wv_a1[0U] = Lib_IntVector_Intrinsics_vec128_rotate_right32(wv_a1[0U], r02);
      Lib_IntVector_Intrinsics_vec128 *wv_a2 = block_state.fst + c0 * (uint32_t)1U;
      Lib_IntVector_Intrinsics_vec128 *wv_b2 = block_state.fst + d0 * (uint32_t)1U;
      wv_a2[0U] = Lib_IntVector_Intrinsics_vec128_add32(wv_a2[0U], wv_b2[0U]);
      Lib_IntVector_Intrinsics_vec128 *wv_a3 = block_state.fst + b20 * (uint32_t)1U;
      Lib_IntVector_Intrinsics_vec128 *wv_b3 = block_state.fst + c0 * (uint32_t)1U;
      wv_a3[0U] = Lib_IntVector_Intrinsics_vec128_xor(wv_a3[0U], wv_b3[0U]);
      wv_a3[0U] = Lib_IntVector_Intrinsics_vec128_rotate_right32(wv_a3[0U], r12);
      Lib_IntVector_Intrinsics_vec128 *wv_a4 = block_state.fst + a * (uint32_t)1U;
      Lib_IntVector_Intrinsics_vec128 *wv_b4 = block_state.fst + b20 * (uint32_t)1U;
      wv_a4[0U] = Lib_IntVector_Intrinsics_vec128_add32(wv_a4[0U], wv_b4[0U]);
      wv_a4[0U] = Lib_IntVector_Intrinsics_vec128_add32(wv_a4[0U], y[0U]);
      Lib_IntVector_Intrinsics_vec128 *wv_a5 = block_state.fst + d0 * (uint32_t)1U;
      Lib_IntVector_Intrinsics_vec128 *wv_b5 = block_state.fst + a * (uint32_t)1U;
      wv_a5[0U] = Lib_IntVector_Intrinsics_vec128_xor(wv_a5[0U], wv_b5[0U]);
      wv_a5[0U] = Lib_IntVector_Intrinsics_vec128_rotate_right32(wv_a5[0U], r22);
      Lib_IntVector_Intrinsics_vec128 *wv_a6 = block_state.fst + c0 * (uint32_t)1U;
      Lib_IntVector_Intrinsics_vec128 *wv_b6 = block_state.fst + d0 * (uint32_t)1U;
      wv_a6[0U] = Lib_IntVector_Intrinsics_vec128_add32(wv_a6[0U], wv_b6[0U]);
      Lib_IntVector_Intrinsics_vec128 *wv_a7 = block_state.fst + b20 * (uint32_t)1U;
      Lib_IntVector_Intrinsics_vec128 *wv_b7 = block_state.fst + c0 * (uint32_t)1U;
      wv_a7[0U] = Lib_IntVector_Intrinsics_vec128_xor(wv_a7[0U], wv_b7[0U]);
      wv_a7[0U] = Lib_IntVector_Intrinsics_vec128_rotate_right32(wv_a7[0U], r32);
      Lib_IntVector_Intrinsics_vec128 *r13 = block_state.fst + (uint32_t)1U * (uint32_t)1U;
      Lib_IntVector_Intrinsics_vec128 *r23 = block_state.fst + (uint32_t)2U * (uint32_t)1U;
      Lib_IntVector_Intrinsics_vec128 *r33 = block_state.fst + (uint32_t)3U * (uint32_t)1U;
      Lib_IntVector_Intrinsics_vec128 v00 = r13[0U];
      Lib_IntVector_Intrinsics_vec128
      v1 = Lib_IntVector_Intrinsics_vec128_rotate_right_lanes32(v00, (uint32_t)1U);
      r13[0U] = v1;
      Lib_IntVector_Intrinsics_vec128 v01 = r23[0U];
      Lib_IntVector_Intrinsics_vec128
      v10 = Lib_IntVector_Intrinsics_vec128_rotate_right_lanes32(v01, (uint32_t)2U);
      r23[0U] = v10;
      Lib_IntVector_Intrinsics_vec128 v02 = r33[0U];
      Lib_IntVector_Intrinsics_vec128
      v11 = Lib_IntVector_Intrinsics_vec128_rotate_right_lanes32(v02, (uint32_t)3U);
      r33[0U] = v11;
      uint32_t a0 = (uint32_t)0U;
      uint32_t b2 = (uint32_t)1U;
      uint32_t c = (uint32_t)2U;
      uint32_t d = (uint32_t)3U;
      uint32_t r0 = Hacl_Impl_Blake2_Constants_rTable_S[0U];
      uint32_t r1 = Hacl_Impl_Blake2_Constants_rTable_S[1U];
      uint32_t r24 = Hacl_Impl_Blake2_Constants_rTable_S[2U];
      uint32_t r34 = Hacl_Impl_Blake2_Constants_rTable_S[3U];
      Lib_IntVector_Intrinsics_vec128 *wv_a = block_state.fst + a0 * (uint32_t)1U;
      Lib_IntVector_Intrinsics_vec128 *wv_b8 = block_state.fst + b2 * (uint32_t)1U;
      wv_a[0U] = Lib_IntVector_Intrinsics_vec128_add32(wv_a[0U], wv_b8[0U]);
      wv_a[0U] = Lib_IntVector_Intrinsics_vec128_add32(wv_a[0U], z[0U]);
      Lib_IntVector_Intrinsics_vec128 *wv_a8 = block_state.fst + d * (uint32_t)1U;
      Lib_IntVector_Intrinsics_vec128 *wv_b9 = block_state.fst + a0 * (uint32_t)1U;
      wv_a8[0U] = Lib_IntVector_Intrinsics_vec128_xor(wv_a8[0U], wv_b9[0U]);
      wv_a8[0U] = Lib_IntVector_Intrinsics_vec128_rotate_right32(wv_a8[0U], r0);
      Lib_IntVector_Intrinsics_vec128 *wv_a9 = block_state.fst + c * (uint32_t)1U;
      Lib_IntVector_Intrinsics_vec128 *wv_b10 = block_state.fst + d * (uint32_t)1U;
      wv_a9[0U] = Lib_IntVector_Intrinsics_vec128_add32(wv_a9[0U], wv_b10[0U]);
      Lib_IntVector_Intrinsics_vec128 *wv_a10 = block_state.fst + b2 * (uint32_t)1U;
      Lib_IntVector_Intrinsics_vec128 *wv_b11 = block_state.fst + c * (uint32_t)1U;
      wv_a10[0U] = Lib_IntVector_Intrinsics_vec128_xor(wv_a10[0U], wv_b11[0U]);
      wv_a10[0U] = Lib_IntVector_Intrinsics_vec128_rotate_right32(wv_a10[0U], r1);
      Lib_IntVector_Intrinsics_vec128 *wv_a11 = block_state.fst + a0 * (uint32_t)1U;
      Lib_IntVector_Intrinsics_vec128 *wv_b12 = block_state.fst + b2 * (uint32_t)1U;
      wv_a11[0U] = Lib_IntVector_Intrinsics_vec128_add32(wv_a11[0U], wv_b12[0U]);
      wv_a11[0U] = Lib_IntVector_Intrinsics_vec128_add32(wv_a11[0U], w[0U]);
      Lib_IntVector_Intrinsics_vec128 *wv_a12 = block_state.fst + d * (uint32_t)1U;
      Lib_IntVector_Intrinsics_vec128 *wv_b13 = block_state.fst + a0 * (uint32_t)1U;
      wv_a12[0U] = Lib_IntVector_Intrinsics_vec128_xor(wv_a12[0U], wv_b13[0U]);
      wv_a12[0U] = Lib_IntVector_Intrinsics_vec128_rotate_right32(wv_a12[0U], r24);
      Lib_IntVector_Intrinsics_vec128 *wv_a13 = block_state.fst + c * (uint32_t)1U;
      Lib_IntVector_Intrinsics_vec128 *wv_b14 = block_state.fst + d * (uint32_t)1U;
      wv_a13[0U] = Lib_IntVector_Intrinsics_vec128_add32(wv_a13[0U], wv_b14[0U]);
      Lib_IntVector_Intrinsics_vec128 *wv_a14 = block_state.fst + b2 * (uint32_t)1U;
      Lib_IntVector_Intrinsics_vec128 *wv_b = block_state.fst + c * (uint32_t)1U;
      wv_a14[0U] = Lib_IntVector_Intrinsics_vec128_xor(wv_a14[0U], wv_b[0U]);
      wv_a14[0U] = Lib_IntVector_Intrinsics_vec128_rotate_right32(wv_a14[0U], r34);
      Lib_IntVector_Intrinsics_vec128 *r14 = block_state.fst + (uint32_t)1U * (uint32_t)1U;
      Lib_IntVector_Intrinsics_vec128 *r2 = block_state.fst + (uint32_t)2U * (uint32_t)1U;
      Lib_IntVector_Intrinsics_vec128 *r3 = block_state.fst + (uint32_t)3U * (uint32_t)1U;
      Lib_IntVector_Intrinsics_vec128 v0 = r14[0U];
      Lib_IntVector_Intrinsics_vec128
      v12 = Lib_IntVector_Intrinsics_vec128_rotate_right_lanes32(v0, (uint32_t)3U);
      r14[0U] = v12;
      Lib_IntVector_Intrinsics_vec128 v03 = r2[0U];
      Lib_IntVector_Intrinsics_vec128
      v13 = Lib_IntVector_Intrinsics_vec128_rotate_right_lanes32(v03, (uint32_t)2U);
      r2[0U] = v13;
      Lib_IntVector_Intrinsics_vec128 v04 = r3[0U];
      Lib_IntVector_Intrinsics_vec128
      v14 = Lib_IntVector_Intrinsics_vec128_rotate_right_lanes32(v04, (uint32_t)1U);
      r3[0U] = v14;
    }
    Lib_IntVector_Intrinsics_vec128 *s0 = block_state.snd + (uint32_t)0U * (uint32_t)1U;
    Lib_IntVector_Intrinsics_vec128 *s11 = block_state.snd + (uint32_t)1U * (uint32_t)1U;
    Lib_IntVector_Intrinsics_vec128 *r0 = block_state.fst + (uint32_t)0U * (uint32_t)1U;
    Lib_IntVector_Intrinsics_vec128 *r1 = block_state.fst + (uint32_t)1U * (uint32_t)1U;
    Lib_IntVector_Intrinsics_vec128 *r2 = block_state.fst + (uint32_t)2U * (uint32_t)1U;
    Lib_IntVector_Intrinsics_vec128 *r3 = block_state.fst + (uint32_t)3U * (uint32_t)1U;
    s0[0U] = Lib_IntVector_Intrinsics_vec128_xor(s0[0U], r0[0U]);
    s0[0U] = Lib_IntVector_Intrinsics_vec128_xor(s0[0U], r2[0U]);
    s11[0U] = Lib_IntVector_Intrinsics_vec128_xor(s11[0U], r1[0U]);
    s11[0U] = Lib_IntVector_Intrinsics_vec128_xor(s11[0U], r3[0U]);
  }
  Lib_Memzero0_memzero(b, (uint32_t)64U * sizeof (b[0U]));
  return p;
}

/* SNIPPET_END: Hacl_Streaming_Blake2_blake2s_128_no_key_create_in */

/* SNIPPET_START: Hacl_Streaming_Blake2_blake2s_128_no_key_update */

/*
  Update function when there is no key
*/
void
Hacl_Streaming_Blake2_blake2s_128_no_key_update(
  Hacl_Streaming_Functor_state_s__K____Lib_IntVector_Intrinsics_vec128___Lib_IntVector_Intrinsics_vec128____
  *p,
  uint8_t *data,
  uint32_t len
)
{
  Hacl_Streaming_Functor_state_s__K____Lib_IntVector_Intrinsics_vec128___Lib_IntVector_Intrinsics_vec128____
  s1 = *p;
  uint64_t total_len = s1.total_len;
  uint32_t sz;
  if (total_len % (uint64_t)(uint32_t)64U == (uint64_t)0U && total_len > (uint64_t)0U)
  {
    sz = (uint32_t)64U;
  }
  else
  {
    sz = (uint32_t)(total_len % (uint64_t)(uint32_t)64U);
  }
  if (len <= (uint32_t)64U - sz)
  {
    Hacl_Streaming_Functor_state_s__K____Lib_IntVector_Intrinsics_vec128___Lib_IntVector_Intrinsics_vec128____
    s2 = *p;
    K____Lib_IntVector_Intrinsics_vec128___Lib_IntVector_Intrinsics_vec128_
    block_state1 = s2.block_state;
    uint8_t *buf = s2.buf;
    uint64_t total_len1 = s2.total_len;
    uint32_t sz1;
    if (total_len1 % (uint64_t)(uint32_t)64U == (uint64_t)0U && total_len1 > (uint64_t)0U)
    {
      sz1 = (uint32_t)64U;
    }
    else
    {
      sz1 = (uint32_t)(total_len1 % (uint64_t)(uint32_t)64U);
    }
    uint8_t *buf2 = buf + sz1;
    memcpy(buf2, data, len * sizeof (data[0U]));
    uint64_t total_len2 = total_len1 + (uint64_t)len;
    *p
    =
      (
        (Hacl_Streaming_Functor_state_s__K____Lib_IntVector_Intrinsics_vec128___Lib_IntVector_Intrinsics_vec128____){
          .block_state = block_state1,
          .buf = buf,
          .total_len = total_len2
        }
      );
    return;
  }
  if (sz == (uint32_t)0U)
  {
    Hacl_Streaming_Functor_state_s__K____Lib_IntVector_Intrinsics_vec128___Lib_IntVector_Intrinsics_vec128____
    s2 = *p;
    K____Lib_IntVector_Intrinsics_vec128___Lib_IntVector_Intrinsics_vec128_
    block_state1 = s2.block_state;
    uint8_t *buf = s2.buf;
    uint64_t total_len1 = s2.total_len;
    uint32_t sz1;
    if (total_len1 % (uint64_t)(uint32_t)64U == (uint64_t)0U && total_len1 > (uint64_t)0U)
    {
      sz1 = (uint32_t)64U;
    }
    else
    {
      sz1 = (uint32_t)(total_len1 % (uint64_t)(uint32_t)64U);
    }
    if (!(sz1 == (uint32_t)0U))
    {
      uint64_t prevlen = total_len1 - (uint64_t)sz1;
      uint32_t nb = (uint32_t)1U;
      for (uint32_t i0 = (uint32_t)0U; i0 < nb; i0++)
      {
        uint64_t ite;
        if ((uint32_t)0U == (uint32_t)0U)
        {
          ite = prevlen;
        }
        else
        {
          ite = prevlen + (uint64_t)(uint32_t)64U;
        }
        uint64_t totlen = ite + (uint64_t)((i0 + (uint32_t)1U) * (uint32_t)64U);
        uint8_t *b = buf + i0 * (uint32_t)64U;
        uint32_t m_w[16U] = { 0U };
        for (uint32_t i = (uint32_t)0U; i < (uint32_t)16U; i++)
        {
          uint32_t *os = m_w;
          uint8_t *bj = b + i * (uint32_t)4U;
          uint32_t u = load32_le(bj);
          uint32_t r = u;
          uint32_t x = r;
          os[i] = x;
        }
        Lib_IntVector_Intrinsics_vec128 mask = Lib_IntVector_Intrinsics_vec128_zero;
        uint32_t wv_14 = (uint32_t)0U;
        uint32_t wv_15 = (uint32_t)0U;
        mask =
          Lib_IntVector_Intrinsics_vec128_load32s((uint32_t)totlen,
            (uint32_t)(totlen >> (uint32_t)32U),
            wv_14,
            wv_15);
        memcpy(block_state1.fst,
          block_state1.snd,
          (uint32_t)4U * (uint32_t)1U * sizeof (block_state1.snd[0U]));
        Lib_IntVector_Intrinsics_vec128 *wv3 = block_state1.fst + (uint32_t)3U * (uint32_t)1U;
        wv3[0U] = Lib_IntVector_Intrinsics_vec128_xor(wv3[0U], mask);
        for (uint32_t i = (uint32_t)0U; i < (uint32_t)10U; i++)
        {
          uint32_t start_idx = i % (uint32_t)10U * (uint32_t)16U;
          KRML_CHECK_SIZE(sizeof (Lib_IntVector_Intrinsics_vec128), (uint32_t)4U * (uint32_t)1U);
          Lib_IntVector_Intrinsics_vec128 m_st[(uint32_t)4U * (uint32_t)1U];
          for (uint32_t _i = 0U; _i < (uint32_t)4U * (uint32_t)1U; ++_i)
            m_st[_i] = Lib_IntVector_Intrinsics_vec128_zero;
          Lib_IntVector_Intrinsics_vec128 *r00 = m_st + (uint32_t)0U * (uint32_t)1U;
          Lib_IntVector_Intrinsics_vec128 *r10 = m_st + (uint32_t)1U * (uint32_t)1U;
          Lib_IntVector_Intrinsics_vec128 *r20 = m_st + (uint32_t)2U * (uint32_t)1U;
          Lib_IntVector_Intrinsics_vec128 *r30 = m_st + (uint32_t)3U * (uint32_t)1U;
          uint32_t s0 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx];
          uint32_t s11 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)1U];
          uint32_t s21 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)2U];
          uint32_t s3 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)3U];
          uint32_t s4 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)4U];
          uint32_t s5 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)5U];
          uint32_t s6 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)6U];
          uint32_t s7 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)7U];
          uint32_t s8 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)8U];
          uint32_t s9 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)9U];
          uint32_t s10 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)10U];
          uint32_t s111 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)11U];
          uint32_t s12 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)12U];
          uint32_t s13 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)13U];
          uint32_t s14 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)14U];
          uint32_t s15 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)15U];
          r00[0U] = Lib_IntVector_Intrinsics_vec128_load32s(m_w[s0], m_w[s21], m_w[s4], m_w[s6]);
          r10[0U] = Lib_IntVector_Intrinsics_vec128_load32s(m_w[s11], m_w[s3], m_w[s5], m_w[s7]);
          r20[0U] = Lib_IntVector_Intrinsics_vec128_load32s(m_w[s8], m_w[s10], m_w[s12], m_w[s14]);
          r30[0U] = Lib_IntVector_Intrinsics_vec128_load32s(m_w[s9], m_w[s111], m_w[s13], m_w[s15]);
          Lib_IntVector_Intrinsics_vec128 *x = m_st + (uint32_t)0U * (uint32_t)1U;
          Lib_IntVector_Intrinsics_vec128 *y = m_st + (uint32_t)1U * (uint32_t)1U;
          Lib_IntVector_Intrinsics_vec128 *z = m_st + (uint32_t)2U * (uint32_t)1U;
          Lib_IntVector_Intrinsics_vec128 *w = m_st + (uint32_t)3U * (uint32_t)1U;
          uint32_t a = (uint32_t)0U;
          uint32_t b10 = (uint32_t)1U;
          uint32_t c0 = (uint32_t)2U;
          uint32_t d0 = (uint32_t)3U;
          uint32_t r01 = Hacl_Impl_Blake2_Constants_rTable_S[0U];
          uint32_t r11 = Hacl_Impl_Blake2_Constants_rTable_S[1U];
          uint32_t r21 = Hacl_Impl_Blake2_Constants_rTable_S[2U];
          uint32_t r31 = Hacl_Impl_Blake2_Constants_rTable_S[3U];
          Lib_IntVector_Intrinsics_vec128 *wv_a0 = block_state1.fst + a * (uint32_t)1U;
          Lib_IntVector_Intrinsics_vec128 *wv_b0 = block_state1.fst + b10 * (uint32_t)1U;
          wv_a0[0U] = Lib_IntVector_Intrinsics_vec128_add32(wv_a0[0U], wv_b0[0U]);
          wv_a0[0U] = Lib_IntVector_Intrinsics_vec128_add32(wv_a0[0U], x[0U]);
          Lib_IntVector_Intrinsics_vec128 *wv_a1 = block_state1.fst + d0 * (uint32_t)1U;
          Lib_IntVector_Intrinsics_vec128 *wv_b1 = block_state1.fst + a * (uint32_t)1U;
          wv_a1[0U] = Lib_IntVector_Intrinsics_vec128_xor(wv_a1[0U], wv_b1[0U]);
          wv_a1[0U] = Lib_IntVector_Intrinsics_vec128_rotate_right32(wv_a1[0U], r01);
          Lib_IntVector_Intrinsics_vec128 *wv_a2 = block_state1.fst + c0 * (uint32_t)1U;
          Lib_IntVector_Intrinsics_vec128 *wv_b2 = block_state1.fst + d0 * (uint32_t)1U;
          wv_a2[0U] = Lib_IntVector_Intrinsics_vec128_add32(wv_a2[0U], wv_b2[0U]);
          Lib_IntVector_Intrinsics_vec128 *wv_a3 = block_state1.fst + b10 * (uint32_t)1U;
          Lib_IntVector_Intrinsics_vec128 *wv_b3 = block_state1.fst + c0 * (uint32_t)1U;
          wv_a3[0U] = Lib_IntVector_Intrinsics_vec128_xor(wv_a3[0U], wv_b3[0U]);
          wv_a3[0U] = Lib_IntVector_Intrinsics_vec128_rotate_right32(wv_a3[0U], r11);
          Lib_IntVector_Intrinsics_vec128 *wv_a4 = block_state1.fst + a * (uint32_t)1U;
          Lib_IntVector_Intrinsics_vec128 *wv_b4 = block_state1.fst + b10 * (uint32_t)1U;
          wv_a4[0U] = Lib_IntVector_Intrinsics_vec128_add32(wv_a4[0U], wv_b4[0U]);
          wv_a4[0U] = Lib_IntVector_Intrinsics_vec128_add32(wv_a4[0U], y[0U]);
          Lib_IntVector_Intrinsics_vec128 *wv_a5 = block_state1.fst + d0 * (uint32_t)1U;
          Lib_IntVector_Intrinsics_vec128 *wv_b5 = block_state1.fst + a * (uint32_t)1U;
          wv_a5[0U] = Lib_IntVector_Intrinsics_vec128_xor(wv_a5[0U], wv_b5[0U]);
          wv_a5[0U] = Lib_IntVector_Intrinsics_vec128_rotate_right32(wv_a5[0U], r21);
          Lib_IntVector_Intrinsics_vec128 *wv_a6 = block_state1.fst + c0 * (uint32_t)1U;
          Lib_IntVector_Intrinsics_vec128 *wv_b6 = block_state1.fst + d0 * (uint32_t)1U;
          wv_a6[0U] = Lib_IntVector_Intrinsics_vec128_add32(wv_a6[0U], wv_b6[0U]);
          Lib_IntVector_Intrinsics_vec128 *wv_a7 = block_state1.fst + b10 * (uint32_t)1U;
          Lib_IntVector_Intrinsics_vec128 *wv_b7 = block_state1.fst + c0 * (uint32_t)1U;
          wv_a7[0U] = Lib_IntVector_Intrinsics_vec128_xor(wv_a7[0U], wv_b7[0U]);
          wv_a7[0U] = Lib_IntVector_Intrinsics_vec128_rotate_right32(wv_a7[0U], r31);
          Lib_IntVector_Intrinsics_vec128 *r12 = block_state1.fst + (uint32_t)1U * (uint32_t)1U;
          Lib_IntVector_Intrinsics_vec128 *r22 = block_state1.fst + (uint32_t)2U * (uint32_t)1U;
          Lib_IntVector_Intrinsics_vec128 *r32 = block_state1.fst + (uint32_t)3U * (uint32_t)1U;
          Lib_IntVector_Intrinsics_vec128 v00 = r12[0U];
          Lib_IntVector_Intrinsics_vec128
          v1 = Lib_IntVector_Intrinsics_vec128_rotate_right_lanes32(v00, (uint32_t)1U);
          r12[0U] = v1;
          Lib_IntVector_Intrinsics_vec128 v01 = r22[0U];
          Lib_IntVector_Intrinsics_vec128
          v10 = Lib_IntVector_Intrinsics_vec128_rotate_right_lanes32(v01, (uint32_t)2U);
          r22[0U] = v10;
          Lib_IntVector_Intrinsics_vec128 v02 = r32[0U];
          Lib_IntVector_Intrinsics_vec128
          v11 = Lib_IntVector_Intrinsics_vec128_rotate_right_lanes32(v02, (uint32_t)3U);
          r32[0U] = v11;
          uint32_t a0 = (uint32_t)0U;
          uint32_t b1 = (uint32_t)1U;
          uint32_t c = (uint32_t)2U;
          uint32_t d = (uint32_t)3U;
          uint32_t r0 = Hacl_Impl_Blake2_Constants_rTable_S[0U];
          uint32_t r1 = Hacl_Impl_Blake2_Constants_rTable_S[1U];
          uint32_t r23 = Hacl_Impl_Blake2_Constants_rTable_S[2U];
          uint32_t r33 = Hacl_Impl_Blake2_Constants_rTable_S[3U];
          Lib_IntVector_Intrinsics_vec128 *wv_a = block_state1.fst + a0 * (uint32_t)1U;
          Lib_IntVector_Intrinsics_vec128 *wv_b8 = block_state1.fst + b1 * (uint32_t)1U;
          wv_a[0U] = Lib_IntVector_Intrinsics_vec128_add32(wv_a[0U], wv_b8[0U]);
          wv_a[0U] = Lib_IntVector_Intrinsics_vec128_add32(wv_a[0U], z[0U]);
          Lib_IntVector_Intrinsics_vec128 *wv_a8 = block_state1.fst + d * (uint32_t)1U;
          Lib_IntVector_Intrinsics_vec128 *wv_b9 = block_state1.fst + a0 * (uint32_t)1U;
          wv_a8[0U] = Lib_IntVector_Intrinsics_vec128_xor(wv_a8[0U], wv_b9[0U]);
          wv_a8[0U] = Lib_IntVector_Intrinsics_vec128_rotate_right32(wv_a8[0U], r0);
          Lib_IntVector_Intrinsics_vec128 *wv_a9 = block_state1.fst + c * (uint32_t)1U;
          Lib_IntVector_Intrinsics_vec128 *wv_b10 = block_state1.fst + d * (uint32_t)1U;
          wv_a9[0U] = Lib_IntVector_Intrinsics_vec128_add32(wv_a9[0U], wv_b10[0U]);
          Lib_IntVector_Intrinsics_vec128 *wv_a10 = block_state1.fst + b1 * (uint32_t)1U;
          Lib_IntVector_Intrinsics_vec128 *wv_b11 = block_state1.fst + c * (uint32_t)1U;
          wv_a10[0U] = Lib_IntVector_Intrinsics_vec128_xor(wv_a10[0U], wv_b11[0U]);
          wv_a10[0U] = Lib_IntVector_Intrinsics_vec128_rotate_right32(wv_a10[0U], r1);
          Lib_IntVector_Intrinsics_vec128 *wv_a11 = block_state1.fst + a0 * (uint32_t)1U;
          Lib_IntVector_Intrinsics_vec128 *wv_b12 = block_state1.fst + b1 * (uint32_t)1U;
          wv_a11[0U] = Lib_IntVector_Intrinsics_vec128_add32(wv_a11[0U], wv_b12[0U]);
          wv_a11[0U] = Lib_IntVector_Intrinsics_vec128_add32(wv_a11[0U], w[0U]);
          Lib_IntVector_Intrinsics_vec128 *wv_a12 = block_state1.fst + d * (uint32_t)1U;
          Lib_IntVector_Intrinsics_vec128 *wv_b13 = block_state1.fst + a0 * (uint32_t)1U;
          wv_a12[0U] = Lib_IntVector_Intrinsics_vec128_xor(wv_a12[0U], wv_b13[0U]);
          wv_a12[0U] = Lib_IntVector_Intrinsics_vec128_rotate_right32(wv_a12[0U], r23);
          Lib_IntVector_Intrinsics_vec128 *wv_a13 = block_state1.fst + c * (uint32_t)1U;
          Lib_IntVector_Intrinsics_vec128 *wv_b14 = block_state1.fst + d * (uint32_t)1U;
          wv_a13[0U] = Lib_IntVector_Intrinsics_vec128_add32(wv_a13[0U], wv_b14[0U]);
          Lib_IntVector_Intrinsics_vec128 *wv_a14 = block_state1.fst + b1 * (uint32_t)1U;
          Lib_IntVector_Intrinsics_vec128 *wv_b = block_state1.fst + c * (uint32_t)1U;
          wv_a14[0U] = Lib_IntVector_Intrinsics_vec128_xor(wv_a14[0U], wv_b[0U]);
          wv_a14[0U] = Lib_IntVector_Intrinsics_vec128_rotate_right32(wv_a14[0U], r33);
          Lib_IntVector_Intrinsics_vec128 *r13 = block_state1.fst + (uint32_t)1U * (uint32_t)1U;
          Lib_IntVector_Intrinsics_vec128 *r2 = block_state1.fst + (uint32_t)2U * (uint32_t)1U;
          Lib_IntVector_Intrinsics_vec128 *r3 = block_state1.fst + (uint32_t)3U * (uint32_t)1U;
          Lib_IntVector_Intrinsics_vec128 v0 = r13[0U];
          Lib_IntVector_Intrinsics_vec128
          v12 = Lib_IntVector_Intrinsics_vec128_rotate_right_lanes32(v0, (uint32_t)3U);
          r13[0U] = v12;
          Lib_IntVector_Intrinsics_vec128 v03 = r2[0U];
          Lib_IntVector_Intrinsics_vec128
          v13 = Lib_IntVector_Intrinsics_vec128_rotate_right_lanes32(v03, (uint32_t)2U);
          r2[0U] = v13;
          Lib_IntVector_Intrinsics_vec128 v04 = r3[0U];
          Lib_IntVector_Intrinsics_vec128
          v14 = Lib_IntVector_Intrinsics_vec128_rotate_right_lanes32(v04, (uint32_t)1U);
          r3[0U] = v14;
        }
        Lib_IntVector_Intrinsics_vec128 *s0 = block_state1.snd + (uint32_t)0U * (uint32_t)1U;
        Lib_IntVector_Intrinsics_vec128 *s11 = block_state1.snd + (uint32_t)1U * (uint32_t)1U;
        Lib_IntVector_Intrinsics_vec128 *r0 = block_state1.fst + (uint32_t)0U * (uint32_t)1U;
        Lib_IntVector_Intrinsics_vec128 *r1 = block_state1.fst + (uint32_t)1U * (uint32_t)1U;
        Lib_IntVector_Intrinsics_vec128 *r2 = block_state1.fst + (uint32_t)2U * (uint32_t)1U;
        Lib_IntVector_Intrinsics_vec128 *r3 = block_state1.fst + (uint32_t)3U * (uint32_t)1U;
        s0[0U] = Lib_IntVector_Intrinsics_vec128_xor(s0[0U], r0[0U]);
        s0[0U] = Lib_IntVector_Intrinsics_vec128_xor(s0[0U], r2[0U]);
        s11[0U] = Lib_IntVector_Intrinsics_vec128_xor(s11[0U], r1[0U]);
        s11[0U] = Lib_IntVector_Intrinsics_vec128_xor(s11[0U], r3[0U]);
      }
    }
    uint32_t ite0;
    if ((uint64_t)len % (uint64_t)(uint32_t)64U == (uint64_t)0U && (uint64_t)len > (uint64_t)0U)
    {
      ite0 = (uint32_t)64U;
    }
    else
    {
      ite0 = (uint32_t)((uint64_t)len % (uint64_t)(uint32_t)64U);
    }
    uint32_t n_blocks = (len - ite0) / (uint32_t)64U;
    uint32_t data1_len = n_blocks * (uint32_t)64U;
    uint32_t data2_len = len - data1_len;
    uint8_t *data1 = data;
    uint8_t *data2 = data + data1_len;
    uint32_t nb = data1_len / (uint32_t)64U;
    for (uint32_t i0 = (uint32_t)0U; i0 < nb; i0++)
    {
      uint64_t ite;
      if ((uint32_t)0U == (uint32_t)0U)
      {
        ite = total_len1;
      }
      else
      {
        ite = total_len1 + (uint64_t)(uint32_t)64U;
      }
      uint64_t totlen = ite + (uint64_t)((i0 + (uint32_t)1U) * (uint32_t)64U);
      uint8_t *b = data1 + i0 * (uint32_t)64U;
      uint32_t m_w[16U] = { 0U };
      for (uint32_t i = (uint32_t)0U; i < (uint32_t)16U; i++)
      {
        uint32_t *os = m_w;
        uint8_t *bj = b + i * (uint32_t)4U;
        uint32_t u = load32_le(bj);
        uint32_t r = u;
        uint32_t x = r;
        os[i] = x;
      }
      Lib_IntVector_Intrinsics_vec128 mask = Lib_IntVector_Intrinsics_vec128_zero;
      uint32_t wv_14 = (uint32_t)0U;
      uint32_t wv_15 = (uint32_t)0U;
      mask =
        Lib_IntVector_Intrinsics_vec128_load32s((uint32_t)totlen,
          (uint32_t)(totlen >> (uint32_t)32U),
          wv_14,
          wv_15);
      memcpy(block_state1.fst,
        block_state1.snd,
        (uint32_t)4U * (uint32_t)1U * sizeof (block_state1.snd[0U]));
      Lib_IntVector_Intrinsics_vec128 *wv3 = block_state1.fst + (uint32_t)3U * (uint32_t)1U;
      wv3[0U] = Lib_IntVector_Intrinsics_vec128_xor(wv3[0U], mask);
      for (uint32_t i = (uint32_t)0U; i < (uint32_t)10U; i++)
      {
        uint32_t start_idx = i % (uint32_t)10U * (uint32_t)16U;
        KRML_CHECK_SIZE(sizeof (Lib_IntVector_Intrinsics_vec128), (uint32_t)4U * (uint32_t)1U);
        Lib_IntVector_Intrinsics_vec128 m_st[(uint32_t)4U * (uint32_t)1U];
        for (uint32_t _i = 0U; _i < (uint32_t)4U * (uint32_t)1U; ++_i)
          m_st[_i] = Lib_IntVector_Intrinsics_vec128_zero;
        Lib_IntVector_Intrinsics_vec128 *r00 = m_st + (uint32_t)0U * (uint32_t)1U;
        Lib_IntVector_Intrinsics_vec128 *r10 = m_st + (uint32_t)1U * (uint32_t)1U;
        Lib_IntVector_Intrinsics_vec128 *r20 = m_st + (uint32_t)2U * (uint32_t)1U;
        Lib_IntVector_Intrinsics_vec128 *r30 = m_st + (uint32_t)3U * (uint32_t)1U;
        uint32_t s0 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx];
        uint32_t s11 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)1U];
        uint32_t s21 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)2U];
        uint32_t s3 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)3U];
        uint32_t s4 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)4U];
        uint32_t s5 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)5U];
        uint32_t s6 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)6U];
        uint32_t s7 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)7U];
        uint32_t s8 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)8U];
        uint32_t s9 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)9U];
        uint32_t s10 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)10U];
        uint32_t s111 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)11U];
        uint32_t s12 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)12U];
        uint32_t s13 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)13U];
        uint32_t s14 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)14U];
        uint32_t s15 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)15U];
        r00[0U] = Lib_IntVector_Intrinsics_vec128_load32s(m_w[s0], m_w[s21], m_w[s4], m_w[s6]);
        r10[0U] = Lib_IntVector_Intrinsics_vec128_load32s(m_w[s11], m_w[s3], m_w[s5], m_w[s7]);
        r20[0U] = Lib_IntVector_Intrinsics_vec128_load32s(m_w[s8], m_w[s10], m_w[s12], m_w[s14]);
        r30[0U] = Lib_IntVector_Intrinsics_vec128_load32s(m_w[s9], m_w[s111], m_w[s13], m_w[s15]);
        Lib_IntVector_Intrinsics_vec128 *x = m_st + (uint32_t)0U * (uint32_t)1U;
        Lib_IntVector_Intrinsics_vec128 *y = m_st + (uint32_t)1U * (uint32_t)1U;
        Lib_IntVector_Intrinsics_vec128 *z = m_st + (uint32_t)2U * (uint32_t)1U;
        Lib_IntVector_Intrinsics_vec128 *w = m_st + (uint32_t)3U * (uint32_t)1U;
        uint32_t a = (uint32_t)0U;
        uint32_t b10 = (uint32_t)1U;
        uint32_t c0 = (uint32_t)2U;
        uint32_t d0 = (uint32_t)3U;
        uint32_t r01 = Hacl_Impl_Blake2_Constants_rTable_S[0U];
        uint32_t r11 = Hacl_Impl_Blake2_Constants_rTable_S[1U];
        uint32_t r21 = Hacl_Impl_Blake2_Constants_rTable_S[2U];
        uint32_t r31 = Hacl_Impl_Blake2_Constants_rTable_S[3U];
        Lib_IntVector_Intrinsics_vec128 *wv_a0 = block_state1.fst + a * (uint32_t)1U;
        Lib_IntVector_Intrinsics_vec128 *wv_b0 = block_state1.fst + b10 * (uint32_t)1U;
        wv_a0[0U] = Lib_IntVector_Intrinsics_vec128_add32(wv_a0[0U], wv_b0[0U]);
        wv_a0[0U] = Lib_IntVector_Intrinsics_vec128_add32(wv_a0[0U], x[0U]);
        Lib_IntVector_Intrinsics_vec128 *wv_a1 = block_state1.fst + d0 * (uint32_t)1U;
        Lib_IntVector_Intrinsics_vec128 *wv_b1 = block_state1.fst + a * (uint32_t)1U;
        wv_a1[0U] = Lib_IntVector_Intrinsics_vec128_xor(wv_a1[0U], wv_b1[0U]);
        wv_a1[0U] = Lib_IntVector_Intrinsics_vec128_rotate_right32(wv_a1[0U], r01);
        Lib_IntVector_Intrinsics_vec128 *wv_a2 = block_state1.fst + c0 * (uint32_t)1U;
        Lib_IntVector_Intrinsics_vec128 *wv_b2 = block_state1.fst + d0 * (uint32_t)1U;
        wv_a2[0U] = Lib_IntVector_Intrinsics_vec128_add32(wv_a2[0U], wv_b2[0U]);
        Lib_IntVector_Intrinsics_vec128 *wv_a3 = block_state1.fst + b10 * (uint32_t)1U;
        Lib_IntVector_Intrinsics_vec128 *wv_b3 = block_state1.fst + c0 * (uint32_t)1U;
        wv_a3[0U] = Lib_IntVector_Intrinsics_vec128_xor(wv_a3[0U], wv_b3[0U]);
        wv_a3[0U] = Lib_IntVector_Intrinsics_vec128_rotate_right32(wv_a3[0U], r11);
        Lib_IntVector_Intrinsics_vec128 *wv_a4 = block_state1.fst + a * (uint32_t)1U;
        Lib_IntVector_Intrinsics_vec128 *wv_b4 = block_state1.fst + b10 * (uint32_t)1U;
        wv_a4[0U] = Lib_IntVector_Intrinsics_vec128_add32(wv_a4[0U], wv_b4[0U]);
        wv_a4[0U] = Lib_IntVector_Intrinsics_vec128_add32(wv_a4[0U], y[0U]);
        Lib_IntVector_Intrinsics_vec128 *wv_a5 = block_state1.fst + d0 * (uint32_t)1U;
        Lib_IntVector_Intrinsics_vec128 *wv_b5 = block_state1.fst + a * (uint32_t)1U;
        wv_a5[0U] = Lib_IntVector_Intrinsics_vec128_xor(wv_a5[0U], wv_b5[0U]);
        wv_a5[0U] = Lib_IntVector_Intrinsics_vec128_rotate_right32(wv_a5[0U], r21);
        Lib_IntVector_Intrinsics_vec128 *wv_a6 = block_state1.fst + c0 * (uint32_t)1U;
        Lib_IntVector_Intrinsics_vec128 *wv_b6 = block_state1.fst + d0 * (uint32_t)1U;
        wv_a6[0U] = Lib_IntVector_Intrinsics_vec128_add32(wv_a6[0U], wv_b6[0U]);
        Lib_IntVector_Intrinsics_vec128 *wv_a7 = block_state1.fst + b10 * (uint32_t)1U;
        Lib_IntVector_Intrinsics_vec128 *wv_b7 = block_state1.fst + c0 * (uint32_t)1U;
        wv_a7[0U] = Lib_IntVector_Intrinsics_vec128_xor(wv_a7[0U], wv_b7[0U]);
        wv_a7[0U] = Lib_IntVector_Intrinsics_vec128_rotate_right32(wv_a7[0U], r31);
        Lib_IntVector_Intrinsics_vec128 *r12 = block_state1.fst + (uint32_t)1U * (uint32_t)1U;
        Lib_IntVector_Intrinsics_vec128 *r22 = block_state1.fst + (uint32_t)2U * (uint32_t)1U;
        Lib_IntVector_Intrinsics_vec128 *r32 = block_state1.fst + (uint32_t)3U * (uint32_t)1U;
        Lib_IntVector_Intrinsics_vec128 v00 = r12[0U];
        Lib_IntVector_Intrinsics_vec128
        v1 = Lib_IntVector_Intrinsics_vec128_rotate_right_lanes32(v00, (uint32_t)1U);
        r12[0U] = v1;
        Lib_IntVector_Intrinsics_vec128 v01 = r22[0U];
        Lib_IntVector_Intrinsics_vec128
        v10 = Lib_IntVector_Intrinsics_vec128_rotate_right_lanes32(v01, (uint32_t)2U);
        r22[0U] = v10;
        Lib_IntVector_Intrinsics_vec128 v02 = r32[0U];
        Lib_IntVector_Intrinsics_vec128
        v11 = Lib_IntVector_Intrinsics_vec128_rotate_right_lanes32(v02, (uint32_t)3U);
        r32[0U] = v11;
        uint32_t a0 = (uint32_t)0U;
        uint32_t b1 = (uint32_t)1U;
        uint32_t c = (uint32_t)2U;
        uint32_t d = (uint32_t)3U;
        uint32_t r0 = Hacl_Impl_Blake2_Constants_rTable_S[0U];
        uint32_t r1 = Hacl_Impl_Blake2_Constants_rTable_S[1U];
        uint32_t r23 = Hacl_Impl_Blake2_Constants_rTable_S[2U];
        uint32_t r33 = Hacl_Impl_Blake2_Constants_rTable_S[3U];
        Lib_IntVector_Intrinsics_vec128 *wv_a = block_state1.fst + a0 * (uint32_t)1U;
        Lib_IntVector_Intrinsics_vec128 *wv_b8 = block_state1.fst + b1 * (uint32_t)1U;
        wv_a[0U] = Lib_IntVector_Intrinsics_vec128_add32(wv_a[0U], wv_b8[0U]);
        wv_a[0U] = Lib_IntVector_Intrinsics_vec128_add32(wv_a[0U], z[0U]);
        Lib_IntVector_Intrinsics_vec128 *wv_a8 = block_state1.fst + d * (uint32_t)1U;
        Lib_IntVector_Intrinsics_vec128 *wv_b9 = block_state1.fst + a0 * (uint32_t)1U;
        wv_a8[0U] = Lib_IntVector_Intrinsics_vec128_xor(wv_a8[0U], wv_b9[0U]);
        wv_a8[0U] = Lib_IntVector_Intrinsics_vec128_rotate_right32(wv_a8[0U], r0);
        Lib_IntVector_Intrinsics_vec128 *wv_a9 = block_state1.fst + c * (uint32_t)1U;
        Lib_IntVector_Intrinsics_vec128 *wv_b10 = block_state1.fst + d * (uint32_t)1U;
        wv_a9[0U] = Lib_IntVector_Intrinsics_vec128_add32(wv_a9[0U], wv_b10[0U]);
        Lib_IntVector_Intrinsics_vec128 *wv_a10 = block_state1.fst + b1 * (uint32_t)1U;
        Lib_IntVector_Intrinsics_vec128 *wv_b11 = block_state1.fst + c * (uint32_t)1U;
        wv_a10[0U] = Lib_IntVector_Intrinsics_vec128_xor(wv_a10[0U], wv_b11[0U]);
        wv_a10[0U] = Lib_IntVector_Intrinsics_vec128_rotate_right32(wv_a10[0U], r1);
        Lib_IntVector_Intrinsics_vec128 *wv_a11 = block_state1.fst + a0 * (uint32_t)1U;
        Lib_IntVector_Intrinsics_vec128 *wv_b12 = block_state1.fst + b1 * (uint32_t)1U;
        wv_a11[0U] = Lib_IntVector_Intrinsics_vec128_add32(wv_a11[0U], wv_b12[0U]);
        wv_a11[0U] = Lib_IntVector_Intrinsics_vec128_add32(wv_a11[0U], w[0U]);
        Lib_IntVector_Intrinsics_vec128 *wv_a12 = block_state1.fst + d * (uint32_t)1U;
        Lib_IntVector_Intrinsics_vec128 *wv_b13 = block_state1.fst + a0 * (uint32_t)1U;
        wv_a12[0U] = Lib_IntVector_Intrinsics_vec128_xor(wv_a12[0U], wv_b13[0U]);
        wv_a12[0U] = Lib_IntVector_Intrinsics_vec128_rotate_right32(wv_a12[0U], r23);
        Lib_IntVector_Intrinsics_vec128 *wv_a13 = block_state1.fst + c * (uint32_t)1U;
        Lib_IntVector_Intrinsics_vec128 *wv_b14 = block_state1.fst + d * (uint32_t)1U;
        wv_a13[0U] = Lib_IntVector_Intrinsics_vec128_add32(wv_a13[0U], wv_b14[0U]);
        Lib_IntVector_Intrinsics_vec128 *wv_a14 = block_state1.fst + b1 * (uint32_t)1U;
        Lib_IntVector_Intrinsics_vec128 *wv_b = block_state1.fst + c * (uint32_t)1U;
        wv_a14[0U] = Lib_IntVector_Intrinsics_vec128_xor(wv_a14[0U], wv_b[0U]);
        wv_a14[0U] = Lib_IntVector_Intrinsics_vec128_rotate_right32(wv_a14[0U], r33);
        Lib_IntVector_Intrinsics_vec128 *r13 = block_state1.fst + (uint32_t)1U * (uint32_t)1U;
        Lib_IntVector_Intrinsics_vec128 *r2 = block_state1.fst + (uint32_t)2U * (uint32_t)1U;
        Lib_IntVector_Intrinsics_vec128 *r3 = block_state1.fst + (uint32_t)3U * (uint32_t)1U;
        Lib_IntVector_Intrinsics_vec128 v0 = r13[0U];
        Lib_IntVector_Intrinsics_vec128
        v12 = Lib_IntVector_Intrinsics_vec128_rotate_right_lanes32(v0, (uint32_t)3U);
        r13[0U] = v12;
        Lib_IntVector_Intrinsics_vec128 v03 = r2[0U];
        Lib_IntVector_Intrinsics_vec128
        v13 = Lib_IntVector_Intrinsics_vec128_rotate_right_lanes32(v03, (uint32_t)2U);
        r2[0U] = v13;
        Lib_IntVector_Intrinsics_vec128 v04 = r3[0U];
        Lib_IntVector_Intrinsics_vec128
        v14 = Lib_IntVector_Intrinsics_vec128_rotate_right_lanes32(v04, (uint32_t)1U);
        r3[0U] = v14;
      }
      Lib_IntVector_Intrinsics_vec128 *s0 = block_state1.snd + (uint32_t)0U * (uint32_t)1U;
      Lib_IntVector_Intrinsics_vec128 *s11 = block_state1.snd + (uint32_t)1U * (uint32_t)1U;
      Lib_IntVector_Intrinsics_vec128 *r0 = block_state1.fst + (uint32_t)0U * (uint32_t)1U;
      Lib_IntVector_Intrinsics_vec128 *r1 = block_state1.fst + (uint32_t)1U * (uint32_t)1U;
      Lib_IntVector_Intrinsics_vec128 *r2 = block_state1.fst + (uint32_t)2U * (uint32_t)1U;
      Lib_IntVector_Intrinsics_vec128 *r3 = block_state1.fst + (uint32_t)3U * (uint32_t)1U;
      s0[0U] = Lib_IntVector_Intrinsics_vec128_xor(s0[0U], r0[0U]);
      s0[0U] = Lib_IntVector_Intrinsics_vec128_xor(s0[0U], r2[0U]);
      s11[0U] = Lib_IntVector_Intrinsics_vec128_xor(s11[0U], r1[0U]);
      s11[0U] = Lib_IntVector_Intrinsics_vec128_xor(s11[0U], r3[0U]);
    }
    uint8_t *dst = buf;
    memcpy(dst, data2, data2_len * sizeof (data2[0U]));
    *p
    =
      (
        (Hacl_Streaming_Functor_state_s__K____Lib_IntVector_Intrinsics_vec128___Lib_IntVector_Intrinsics_vec128____){
          .block_state = block_state1,
          .buf = buf,
          .total_len = total_len1 + (uint64_t)len
        }
      );
    return;
  }
  uint32_t diff = (uint32_t)64U - sz;
  uint8_t *data1 = data;
  uint8_t *data2 = data + diff;
  Hacl_Streaming_Functor_state_s__K____Lib_IntVector_Intrinsics_vec128___Lib_IntVector_Intrinsics_vec128____
  s2 = *p;
  K____Lib_IntVector_Intrinsics_vec128___Lib_IntVector_Intrinsics_vec128_
  block_state10 = s2.block_state;
  uint8_t *buf0 = s2.buf;
  uint64_t total_len10 = s2.total_len;
  uint32_t sz10;
  if (total_len10 % (uint64_t)(uint32_t)64U == (uint64_t)0U && total_len10 > (uint64_t)0U)
  {
    sz10 = (uint32_t)64U;
  }
  else
  {
    sz10 = (uint32_t)(total_len10 % (uint64_t)(uint32_t)64U);
  }
  uint8_t *buf2 = buf0 + sz10;
  memcpy(buf2, data1, diff * sizeof (data1[0U]));
  uint64_t total_len2 = total_len10 + (uint64_t)diff;
  *p
  =
    (
      (Hacl_Streaming_Functor_state_s__K____Lib_IntVector_Intrinsics_vec128___Lib_IntVector_Intrinsics_vec128____){
        .block_state = block_state10,
        .buf = buf0,
        .total_len = total_len2
      }
    );
  Hacl_Streaming_Functor_state_s__K____Lib_IntVector_Intrinsics_vec128___Lib_IntVector_Intrinsics_vec128____
  s20 = *p;
  K____Lib_IntVector_Intrinsics_vec128___Lib_IntVector_Intrinsics_vec128_
  block_state1 = s20.block_state;
  uint8_t *buf = s20.buf;
  uint64_t total_len1 = s20.total_len;
  uint32_t sz1;
  if (total_len1 % (uint64_t)(uint32_t)64U == (uint64_t)0U && total_len1 > (uint64_t)0U)
  {
    sz1 = (uint32_t)64U;
  }
  else
  {
    sz1 = (uint32_t)(total_len1 % (uint64_t)(uint32_t)64U);
  }
  if (!(sz1 == (uint32_t)0U))
  {
    uint64_t prevlen = total_len1 - (uint64_t)sz1;
    uint32_t nb = (uint32_t)1U;
    for (uint32_t i0 = (uint32_t)0U; i0 < nb; i0++)
    {
      uint64_t ite;
      if ((uint32_t)0U == (uint32_t)0U)
      {
        ite = prevlen;
      }
      else
      {
        ite = prevlen + (uint64_t)(uint32_t)64U;
      }
      uint64_t totlen = ite + (uint64_t)((i0 + (uint32_t)1U) * (uint32_t)64U);
      uint8_t *b = buf + i0 * (uint32_t)64U;
      uint32_t m_w[16U] = { 0U };
      for (uint32_t i = (uint32_t)0U; i < (uint32_t)16U; i++)
      {
        uint32_t *os = m_w;
        uint8_t *bj = b + i * (uint32_t)4U;
        uint32_t u = load32_le(bj);
        uint32_t r = u;
        uint32_t x = r;
        os[i] = x;
      }
      Lib_IntVector_Intrinsics_vec128 mask = Lib_IntVector_Intrinsics_vec128_zero;
      uint32_t wv_14 = (uint32_t)0U;
      uint32_t wv_15 = (uint32_t)0U;
      mask =
        Lib_IntVector_Intrinsics_vec128_load32s((uint32_t)totlen,
          (uint32_t)(totlen >> (uint32_t)32U),
          wv_14,
          wv_15);
      memcpy(block_state1.fst,
        block_state1.snd,
        (uint32_t)4U * (uint32_t)1U * sizeof (block_state1.snd[0U]));
      Lib_IntVector_Intrinsics_vec128 *wv3 = block_state1.fst + (uint32_t)3U * (uint32_t)1U;
      wv3[0U] = Lib_IntVector_Intrinsics_vec128_xor(wv3[0U], mask);
      for (uint32_t i = (uint32_t)0U; i < (uint32_t)10U; i++)
      {
        uint32_t start_idx = i % (uint32_t)10U * (uint32_t)16U;
        KRML_CHECK_SIZE(sizeof (Lib_IntVector_Intrinsics_vec128), (uint32_t)4U * (uint32_t)1U);
        Lib_IntVector_Intrinsics_vec128 m_st[(uint32_t)4U * (uint32_t)1U];
        for (uint32_t _i = 0U; _i < (uint32_t)4U * (uint32_t)1U; ++_i)
          m_st[_i] = Lib_IntVector_Intrinsics_vec128_zero;
        Lib_IntVector_Intrinsics_vec128 *r00 = m_st + (uint32_t)0U * (uint32_t)1U;
        Lib_IntVector_Intrinsics_vec128 *r10 = m_st + (uint32_t)1U * (uint32_t)1U;
        Lib_IntVector_Intrinsics_vec128 *r20 = m_st + (uint32_t)2U * (uint32_t)1U;
        Lib_IntVector_Intrinsics_vec128 *r30 = m_st + (uint32_t)3U * (uint32_t)1U;
        uint32_t s0 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx];
        uint32_t s11 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)1U];
        uint32_t s21 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)2U];
        uint32_t s3 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)3U];
        uint32_t s4 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)4U];
        uint32_t s5 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)5U];
        uint32_t s6 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)6U];
        uint32_t s7 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)7U];
        uint32_t s8 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)8U];
        uint32_t s9 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)9U];
        uint32_t s10 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)10U];
        uint32_t s111 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)11U];
        uint32_t s12 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)12U];
        uint32_t s13 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)13U];
        uint32_t s14 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)14U];
        uint32_t s15 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)15U];
        r00[0U] = Lib_IntVector_Intrinsics_vec128_load32s(m_w[s0], m_w[s21], m_w[s4], m_w[s6]);
        r10[0U] = Lib_IntVector_Intrinsics_vec128_load32s(m_w[s11], m_w[s3], m_w[s5], m_w[s7]);
        r20[0U] = Lib_IntVector_Intrinsics_vec128_load32s(m_w[s8], m_w[s10], m_w[s12], m_w[s14]);
        r30[0U] = Lib_IntVector_Intrinsics_vec128_load32s(m_w[s9], m_w[s111], m_w[s13], m_w[s15]);
        Lib_IntVector_Intrinsics_vec128 *x = m_st + (uint32_t)0U * (uint32_t)1U;
        Lib_IntVector_Intrinsics_vec128 *y = m_st + (uint32_t)1U * (uint32_t)1U;
        Lib_IntVector_Intrinsics_vec128 *z = m_st + (uint32_t)2U * (uint32_t)1U;
        Lib_IntVector_Intrinsics_vec128 *w = m_st + (uint32_t)3U * (uint32_t)1U;
        uint32_t a = (uint32_t)0U;
        uint32_t b10 = (uint32_t)1U;
        uint32_t c0 = (uint32_t)2U;
        uint32_t d0 = (uint32_t)3U;
        uint32_t r01 = Hacl_Impl_Blake2_Constants_rTable_S[0U];
        uint32_t r11 = Hacl_Impl_Blake2_Constants_rTable_S[1U];
        uint32_t r21 = Hacl_Impl_Blake2_Constants_rTable_S[2U];
        uint32_t r31 = Hacl_Impl_Blake2_Constants_rTable_S[3U];
        Lib_IntVector_Intrinsics_vec128 *wv_a0 = block_state1.fst + a * (uint32_t)1U;
        Lib_IntVector_Intrinsics_vec128 *wv_b0 = block_state1.fst + b10 * (uint32_t)1U;
        wv_a0[0U] = Lib_IntVector_Intrinsics_vec128_add32(wv_a0[0U], wv_b0[0U]);
        wv_a0[0U] = Lib_IntVector_Intrinsics_vec128_add32(wv_a0[0U], x[0U]);
        Lib_IntVector_Intrinsics_vec128 *wv_a1 = block_state1.fst + d0 * (uint32_t)1U;
        Lib_IntVector_Intrinsics_vec128 *wv_b1 = block_state1.fst + a * (uint32_t)1U;
        wv_a1[0U] = Lib_IntVector_Intrinsics_vec128_xor(wv_a1[0U], wv_b1[0U]);
        wv_a1[0U] = Lib_IntVector_Intrinsics_vec128_rotate_right32(wv_a1[0U], r01);
        Lib_IntVector_Intrinsics_vec128 *wv_a2 = block_state1.fst + c0 * (uint32_t)1U;
        Lib_IntVector_Intrinsics_vec128 *wv_b2 = block_state1.fst + d0 * (uint32_t)1U;
        wv_a2[0U] = Lib_IntVector_Intrinsics_vec128_add32(wv_a2[0U], wv_b2[0U]);
        Lib_IntVector_Intrinsics_vec128 *wv_a3 = block_state1.fst + b10 * (uint32_t)1U;
        Lib_IntVector_Intrinsics_vec128 *wv_b3 = block_state1.fst + c0 * (uint32_t)1U;
        wv_a3[0U] = Lib_IntVector_Intrinsics_vec128_xor(wv_a3[0U], wv_b3[0U]);
        wv_a3[0U] = Lib_IntVector_Intrinsics_vec128_rotate_right32(wv_a3[0U], r11);
        Lib_IntVector_Intrinsics_vec128 *wv_a4 = block_state1.fst + a * (uint32_t)1U;
        Lib_IntVector_Intrinsics_vec128 *wv_b4 = block_state1.fst + b10 * (uint32_t)1U;
        wv_a4[0U] = Lib_IntVector_Intrinsics_vec128_add32(wv_a4[0U], wv_b4[0U]);
        wv_a4[0U] = Lib_IntVector_Intrinsics_vec128_add32(wv_a4[0U], y[0U]);
        Lib_IntVector_Intrinsics_vec128 *wv_a5 = block_state1.fst + d0 * (uint32_t)1U;
        Lib_IntVector_Intrinsics_vec128 *wv_b5 = block_state1.fst + a * (uint32_t)1U;
        wv_a5[0U] = Lib_IntVector_Intrinsics_vec128_xor(wv_a5[0U], wv_b5[0U]);
        wv_a5[0U] = Lib_IntVector_Intrinsics_vec128_rotate_right32(wv_a5[0U], r21);
        Lib_IntVector_Intrinsics_vec128 *wv_a6 = block_state1.fst + c0 * (uint32_t)1U;
        Lib_IntVector_Intrinsics_vec128 *wv_b6 = block_state1.fst + d0 * (uint32_t)1U;
        wv_a6[0U] = Lib_IntVector_Intrinsics_vec128_add32(wv_a6[0U], wv_b6[0U]);
        Lib_IntVector_Intrinsics_vec128 *wv_a7 = block_state1.fst + b10 * (uint32_t)1U;
        Lib_IntVector_Intrinsics_vec128 *wv_b7 = block_state1.fst + c0 * (uint32_t)1U;
        wv_a7[0U] = Lib_IntVector_Intrinsics_vec128_xor(wv_a7[0U], wv_b7[0U]);
        wv_a7[0U] = Lib_IntVector_Intrinsics_vec128_rotate_right32(wv_a7[0U], r31);
        Lib_IntVector_Intrinsics_vec128 *r12 = block_state1.fst + (uint32_t)1U * (uint32_t)1U;
        Lib_IntVector_Intrinsics_vec128 *r22 = block_state1.fst + (uint32_t)2U * (uint32_t)1U;
        Lib_IntVector_Intrinsics_vec128 *r32 = block_state1.fst + (uint32_t)3U * (uint32_t)1U;
        Lib_IntVector_Intrinsics_vec128 v00 = r12[0U];
        Lib_IntVector_Intrinsics_vec128
        v1 = Lib_IntVector_Intrinsics_vec128_rotate_right_lanes32(v00, (uint32_t)1U);
        r12[0U] = v1;
        Lib_IntVector_Intrinsics_vec128 v01 = r22[0U];
        Lib_IntVector_Intrinsics_vec128
        v10 = Lib_IntVector_Intrinsics_vec128_rotate_right_lanes32(v01, (uint32_t)2U);
        r22[0U] = v10;
        Lib_IntVector_Intrinsics_vec128 v02 = r32[0U];
        Lib_IntVector_Intrinsics_vec128
        v11 = Lib_IntVector_Intrinsics_vec128_rotate_right_lanes32(v02, (uint32_t)3U);
        r32[0U] = v11;
        uint32_t a0 = (uint32_t)0U;
        uint32_t b1 = (uint32_t)1U;
        uint32_t c = (uint32_t)2U;
        uint32_t d = (uint32_t)3U;
        uint32_t r0 = Hacl_Impl_Blake2_Constants_rTable_S[0U];
        uint32_t r1 = Hacl_Impl_Blake2_Constants_rTable_S[1U];
        uint32_t r23 = Hacl_Impl_Blake2_Constants_rTable_S[2U];
        uint32_t r33 = Hacl_Impl_Blake2_Constants_rTable_S[3U];
        Lib_IntVector_Intrinsics_vec128 *wv_a = block_state1.fst + a0 * (uint32_t)1U;
        Lib_IntVector_Intrinsics_vec128 *wv_b8 = block_state1.fst + b1 * (uint32_t)1U;
        wv_a[0U] = Lib_IntVector_Intrinsics_vec128_add32(wv_a[0U], wv_b8[0U]);
        wv_a[0U] = Lib_IntVector_Intrinsics_vec128_add32(wv_a[0U], z[0U]);
        Lib_IntVector_Intrinsics_vec128 *wv_a8 = block_state1.fst + d * (uint32_t)1U;
        Lib_IntVector_Intrinsics_vec128 *wv_b9 = block_state1.fst + a0 * (uint32_t)1U;
        wv_a8[0U] = Lib_IntVector_Intrinsics_vec128_xor(wv_a8[0U], wv_b9[0U]);
        wv_a8[0U] = Lib_IntVector_Intrinsics_vec128_rotate_right32(wv_a8[0U], r0);
        Lib_IntVector_Intrinsics_vec128 *wv_a9 = block_state1.fst + c * (uint32_t)1U;
        Lib_IntVector_Intrinsics_vec128 *wv_b10 = block_state1.fst + d * (uint32_t)1U;
        wv_a9[0U] = Lib_IntVector_Intrinsics_vec128_add32(wv_a9[0U], wv_b10[0U]);
        Lib_IntVector_Intrinsics_vec128 *wv_a10 = block_state1.fst + b1 * (uint32_t)1U;
        Lib_IntVector_Intrinsics_vec128 *wv_b11 = block_state1.fst + c * (uint32_t)1U;
        wv_a10[0U] = Lib_IntVector_Intrinsics_vec128_xor(wv_a10[0U], wv_b11[0U]);
        wv_a10[0U] = Lib_IntVector_Intrinsics_vec128_rotate_right32(wv_a10[0U], r1);
        Lib_IntVector_Intrinsics_vec128 *wv_a11 = block_state1.fst + a0 * (uint32_t)1U;
        Lib_IntVector_Intrinsics_vec128 *wv_b12 = block_state1.fst + b1 * (uint32_t)1U;
        wv_a11[0U] = Lib_IntVector_Intrinsics_vec128_add32(wv_a11[0U], wv_b12[0U]);
        wv_a11[0U] = Lib_IntVector_Intrinsics_vec128_add32(wv_a11[0U], w[0U]);
        Lib_IntVector_Intrinsics_vec128 *wv_a12 = block_state1.fst + d * (uint32_t)1U;
        Lib_IntVector_Intrinsics_vec128 *wv_b13 = block_state1.fst + a0 * (uint32_t)1U;
        wv_a12[0U] = Lib_IntVector_Intrinsics_vec128_xor(wv_a12[0U], wv_b13[0U]);
        wv_a12[0U] = Lib_IntVector_Intrinsics_vec128_rotate_right32(wv_a12[0U], r23);
        Lib_IntVector_Intrinsics_vec128 *wv_a13 = block_state1.fst + c * (uint32_t)1U;
        Lib_IntVector_Intrinsics_vec128 *wv_b14 = block_state1.fst + d * (uint32_t)1U;
        wv_a13[0U] = Lib_IntVector_Intrinsics_vec128_add32(wv_a13[0U], wv_b14[0U]);
        Lib_IntVector_Intrinsics_vec128 *wv_a14 = block_state1.fst + b1 * (uint32_t)1U;
        Lib_IntVector_Intrinsics_vec128 *wv_b = block_state1.fst + c * (uint32_t)1U;
        wv_a14[0U] = Lib_IntVector_Intrinsics_vec128_xor(wv_a14[0U], wv_b[0U]);
        wv_a14[0U] = Lib_IntVector_Intrinsics_vec128_rotate_right32(wv_a14[0U], r33);
        Lib_IntVector_Intrinsics_vec128 *r13 = block_state1.fst + (uint32_t)1U * (uint32_t)1U;
        Lib_IntVector_Intrinsics_vec128 *r2 = block_state1.fst + (uint32_t)2U * (uint32_t)1U;
        Lib_IntVector_Intrinsics_vec128 *r3 = block_state1.fst + (uint32_t)3U * (uint32_t)1U;
        Lib_IntVector_Intrinsics_vec128 v0 = r13[0U];
        Lib_IntVector_Intrinsics_vec128
        v12 = Lib_IntVector_Intrinsics_vec128_rotate_right_lanes32(v0, (uint32_t)3U);
        r13[0U] = v12;
        Lib_IntVector_Intrinsics_vec128 v03 = r2[0U];
        Lib_IntVector_Intrinsics_vec128
        v13 = Lib_IntVector_Intrinsics_vec128_rotate_right_lanes32(v03, (uint32_t)2U);
        r2[0U] = v13;
        Lib_IntVector_Intrinsics_vec128 v04 = r3[0U];
        Lib_IntVector_Intrinsics_vec128
        v14 = Lib_IntVector_Intrinsics_vec128_rotate_right_lanes32(v04, (uint32_t)1U);
        r3[0U] = v14;
      }
      Lib_IntVector_Intrinsics_vec128 *s0 = block_state1.snd + (uint32_t)0U * (uint32_t)1U;
      Lib_IntVector_Intrinsics_vec128 *s11 = block_state1.snd + (uint32_t)1U * (uint32_t)1U;
      Lib_IntVector_Intrinsics_vec128 *r0 = block_state1.fst + (uint32_t)0U * (uint32_t)1U;
      Lib_IntVector_Intrinsics_vec128 *r1 = block_state1.fst + (uint32_t)1U * (uint32_t)1U;
      Lib_IntVector_Intrinsics_vec128 *r2 = block_state1.fst + (uint32_t)2U * (uint32_t)1U;
      Lib_IntVector_Intrinsics_vec128 *r3 = block_state1.fst + (uint32_t)3U * (uint32_t)1U;
      s0[0U] = Lib_IntVector_Intrinsics_vec128_xor(s0[0U], r0[0U]);
      s0[0U] = Lib_IntVector_Intrinsics_vec128_xor(s0[0U], r2[0U]);
      s11[0U] = Lib_IntVector_Intrinsics_vec128_xor(s11[0U], r1[0U]);
      s11[0U] = Lib_IntVector_Intrinsics_vec128_xor(s11[0U], r3[0U]);
    }
  }
  uint32_t ite0;
  if
  (
    (uint64_t)(len - diff)
    % (uint64_t)(uint32_t)64U
    == (uint64_t)0U
    && (uint64_t)(len - diff) > (uint64_t)0U
  )
  {
    ite0 = (uint32_t)64U;
  }
  else
  {
    ite0 = (uint32_t)((uint64_t)(len - diff) % (uint64_t)(uint32_t)64U);
  }
  uint32_t n_blocks = (len - diff - ite0) / (uint32_t)64U;
  uint32_t data1_len = n_blocks * (uint32_t)64U;
  uint32_t data2_len = len - diff - data1_len;
  uint8_t *data11 = data2;
  uint8_t *data21 = data2 + data1_len;
  uint32_t nb = data1_len / (uint32_t)64U;
  for (uint32_t i0 = (uint32_t)0U; i0 < nb; i0++)
  {
    uint64_t ite;
    if ((uint32_t)0U == (uint32_t)0U)
    {
      ite = total_len1;
    }
    else
    {
      ite = total_len1 + (uint64_t)(uint32_t)64U;
    }
    uint64_t totlen = ite + (uint64_t)((i0 + (uint32_t)1U) * (uint32_t)64U);
    uint8_t *b = data11 + i0 * (uint32_t)64U;
    uint32_t m_w[16U] = { 0U };
    for (uint32_t i = (uint32_t)0U; i < (uint32_t)16U; i++)
    {
      uint32_t *os = m_w;
      uint8_t *bj = b + i * (uint32_t)4U;
      uint32_t u = load32_le(bj);
      uint32_t r = u;
      uint32_t x = r;
      os[i] = x;
    }
    Lib_IntVector_Intrinsics_vec128 mask = Lib_IntVector_Intrinsics_vec128_zero;
    uint32_t wv_14 = (uint32_t)0U;
    uint32_t wv_15 = (uint32_t)0U;
    mask =
      Lib_IntVector_Intrinsics_vec128_load32s((uint32_t)totlen,
        (uint32_t)(totlen >> (uint32_t)32U),
        wv_14,
        wv_15);
    memcpy(block_state1.fst,
      block_state1.snd,
      (uint32_t)4U * (uint32_t)1U * sizeof (block_state1.snd[0U]));
    Lib_IntVector_Intrinsics_vec128 *wv3 = block_state1.fst + (uint32_t)3U * (uint32_t)1U;
    wv3[0U] = Lib_IntVector_Intrinsics_vec128_xor(wv3[0U], mask);
    for (uint32_t i = (uint32_t)0U; i < (uint32_t)10U; i++)
    {
      uint32_t start_idx = i % (uint32_t)10U * (uint32_t)16U;
      KRML_CHECK_SIZE(sizeof (Lib_IntVector_Intrinsics_vec128), (uint32_t)4U * (uint32_t)1U);
      Lib_IntVector_Intrinsics_vec128 m_st[(uint32_t)4U * (uint32_t)1U];
      for (uint32_t _i = 0U; _i < (uint32_t)4U * (uint32_t)1U; ++_i)
        m_st[_i] = Lib_IntVector_Intrinsics_vec128_zero;
      Lib_IntVector_Intrinsics_vec128 *r00 = m_st + (uint32_t)0U * (uint32_t)1U;
      Lib_IntVector_Intrinsics_vec128 *r10 = m_st + (uint32_t)1U * (uint32_t)1U;
      Lib_IntVector_Intrinsics_vec128 *r20 = m_st + (uint32_t)2U * (uint32_t)1U;
      Lib_IntVector_Intrinsics_vec128 *r30 = m_st + (uint32_t)3U * (uint32_t)1U;
      uint32_t s0 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx];
      uint32_t s11 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)1U];
      uint32_t s21 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)2U];
      uint32_t s3 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)3U];
      uint32_t s4 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)4U];
      uint32_t s5 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)5U];
      uint32_t s6 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)6U];
      uint32_t s7 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)7U];
      uint32_t s8 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)8U];
      uint32_t s9 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)9U];
      uint32_t s10 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)10U];
      uint32_t s111 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)11U];
      uint32_t s12 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)12U];
      uint32_t s13 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)13U];
      uint32_t s14 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)14U];
      uint32_t s15 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)15U];
      r00[0U] = Lib_IntVector_Intrinsics_vec128_load32s(m_w[s0], m_w[s21], m_w[s4], m_w[s6]);
      r10[0U] = Lib_IntVector_Intrinsics_vec128_load32s(m_w[s11], m_w[s3], m_w[s5], m_w[s7]);
      r20[0U] = Lib_IntVector_Intrinsics_vec128_load32s(m_w[s8], m_w[s10], m_w[s12], m_w[s14]);
      r30[0U] = Lib_IntVector_Intrinsics_vec128_load32s(m_w[s9], m_w[s111], m_w[s13], m_w[s15]);
      Lib_IntVector_Intrinsics_vec128 *x = m_st + (uint32_t)0U * (uint32_t)1U;
      Lib_IntVector_Intrinsics_vec128 *y = m_st + (uint32_t)1U * (uint32_t)1U;
      Lib_IntVector_Intrinsics_vec128 *z = m_st + (uint32_t)2U * (uint32_t)1U;
      Lib_IntVector_Intrinsics_vec128 *w = m_st + (uint32_t)3U * (uint32_t)1U;
      uint32_t a = (uint32_t)0U;
      uint32_t b10 = (uint32_t)1U;
      uint32_t c0 = (uint32_t)2U;
      uint32_t d0 = (uint32_t)3U;
      uint32_t r01 = Hacl_Impl_Blake2_Constants_rTable_S[0U];
      uint32_t r11 = Hacl_Impl_Blake2_Constants_rTable_S[1U];
      uint32_t r21 = Hacl_Impl_Blake2_Constants_rTable_S[2U];
      uint32_t r31 = Hacl_Impl_Blake2_Constants_rTable_S[3U];
      Lib_IntVector_Intrinsics_vec128 *wv_a0 = block_state1.fst + a * (uint32_t)1U;
      Lib_IntVector_Intrinsics_vec128 *wv_b0 = block_state1.fst + b10 * (uint32_t)1U;
      wv_a0[0U] = Lib_IntVector_Intrinsics_vec128_add32(wv_a0[0U], wv_b0[0U]);
      wv_a0[0U] = Lib_IntVector_Intrinsics_vec128_add32(wv_a0[0U], x[0U]);
      Lib_IntVector_Intrinsics_vec128 *wv_a1 = block_state1.fst + d0 * (uint32_t)1U;
      Lib_IntVector_Intrinsics_vec128 *wv_b1 = block_state1.fst + a * (uint32_t)1U;
      wv_a1[0U] = Lib_IntVector_Intrinsics_vec128_xor(wv_a1[0U], wv_b1[0U]);
      wv_a1[0U] = Lib_IntVector_Intrinsics_vec128_rotate_right32(wv_a1[0U], r01);
      Lib_IntVector_Intrinsics_vec128 *wv_a2 = block_state1.fst + c0 * (uint32_t)1U;
      Lib_IntVector_Intrinsics_vec128 *wv_b2 = block_state1.fst + d0 * (uint32_t)1U;
      wv_a2[0U] = Lib_IntVector_Intrinsics_vec128_add32(wv_a2[0U], wv_b2[0U]);
      Lib_IntVector_Intrinsics_vec128 *wv_a3 = block_state1.fst + b10 * (uint32_t)1U;
      Lib_IntVector_Intrinsics_vec128 *wv_b3 = block_state1.fst + c0 * (uint32_t)1U;
      wv_a3[0U] = Lib_IntVector_Intrinsics_vec128_xor(wv_a3[0U], wv_b3[0U]);
      wv_a3[0U] = Lib_IntVector_Intrinsics_vec128_rotate_right32(wv_a3[0U], r11);
      Lib_IntVector_Intrinsics_vec128 *wv_a4 = block_state1.fst + a * (uint32_t)1U;
      Lib_IntVector_Intrinsics_vec128 *wv_b4 = block_state1.fst + b10 * (uint32_t)1U;
      wv_a4[0U] = Lib_IntVector_Intrinsics_vec128_add32(wv_a4[0U], wv_b4[0U]);
      wv_a4[0U] = Lib_IntVector_Intrinsics_vec128_add32(wv_a4[0U], y[0U]);
      Lib_IntVector_Intrinsics_vec128 *wv_a5 = block_state1.fst + d0 * (uint32_t)1U;
      Lib_IntVector_Intrinsics_vec128 *wv_b5 = block_state1.fst + a * (uint32_t)1U;
      wv_a5[0U] = Lib_IntVector_Intrinsics_vec128_xor(wv_a5[0U], wv_b5[0U]);
      wv_a5[0U] = Lib_IntVector_Intrinsics_vec128_rotate_right32(wv_a5[0U], r21);
      Lib_IntVector_Intrinsics_vec128 *wv_a6 = block_state1.fst + c0 * (uint32_t)1U;
      Lib_IntVector_Intrinsics_vec128 *wv_b6 = block_state1.fst + d0 * (uint32_t)1U;
      wv_a6[0U] = Lib_IntVector_Intrinsics_vec128_add32(wv_a6[0U], wv_b6[0U]);
      Lib_IntVector_Intrinsics_vec128 *wv_a7 = block_state1.fst + b10 * (uint32_t)1U;
      Lib_IntVector_Intrinsics_vec128 *wv_b7 = block_state1.fst + c0 * (uint32_t)1U;
      wv_a7[0U] = Lib_IntVector_Intrinsics_vec128_xor(wv_a7[0U], wv_b7[0U]);
      wv_a7[0U] = Lib_IntVector_Intrinsics_vec128_rotate_right32(wv_a7[0U], r31);
      Lib_IntVector_Intrinsics_vec128 *r12 = block_state1.fst + (uint32_t)1U * (uint32_t)1U;
      Lib_IntVector_Intrinsics_vec128 *r22 = block_state1.fst + (uint32_t)2U * (uint32_t)1U;
      Lib_IntVector_Intrinsics_vec128 *r32 = block_state1.fst + (uint32_t)3U * (uint32_t)1U;
      Lib_IntVector_Intrinsics_vec128 v00 = r12[0U];
      Lib_IntVector_Intrinsics_vec128
      v1 = Lib_IntVector_Intrinsics_vec128_rotate_right_lanes32(v00, (uint32_t)1U);
      r12[0U] = v1;
      Lib_IntVector_Intrinsics_vec128 v01 = r22[0U];
      Lib_IntVector_Intrinsics_vec128
      v10 = Lib_IntVector_Intrinsics_vec128_rotate_right_lanes32(v01, (uint32_t)2U);
      r22[0U] = v10;
      Lib_IntVector_Intrinsics_vec128 v02 = r32[0U];
      Lib_IntVector_Intrinsics_vec128
      v11 = Lib_IntVector_Intrinsics_vec128_rotate_right_lanes32(v02, (uint32_t)3U);
      r32[0U] = v11;
      uint32_t a0 = (uint32_t)0U;
      uint32_t b1 = (uint32_t)1U;
      uint32_t c = (uint32_t)2U;
      uint32_t d = (uint32_t)3U;
      uint32_t r0 = Hacl_Impl_Blake2_Constants_rTable_S[0U];
      uint32_t r1 = Hacl_Impl_Blake2_Constants_rTable_S[1U];
      uint32_t r23 = Hacl_Impl_Blake2_Constants_rTable_S[2U];
      uint32_t r33 = Hacl_Impl_Blake2_Constants_rTable_S[3U];
      Lib_IntVector_Intrinsics_vec128 *wv_a = block_state1.fst + a0 * (uint32_t)1U;
      Lib_IntVector_Intrinsics_vec128 *wv_b8 = block_state1.fst + b1 * (uint32_t)1U;
      wv_a[0U] = Lib_IntVector_Intrinsics_vec128_add32(wv_a[0U], wv_b8[0U]);
      wv_a[0U] = Lib_IntVector_Intrinsics_vec128_add32(wv_a[0U], z[0U]);
      Lib_IntVector_Intrinsics_vec128 *wv_a8 = block_state1.fst + d * (uint32_t)1U;
      Lib_IntVector_Intrinsics_vec128 *wv_b9 = block_state1.fst + a0 * (uint32_t)1U;
      wv_a8[0U] = Lib_IntVector_Intrinsics_vec128_xor(wv_a8[0U], wv_b9[0U]);
      wv_a8[0U] = Lib_IntVector_Intrinsics_vec128_rotate_right32(wv_a8[0U], r0);
      Lib_IntVector_Intrinsics_vec128 *wv_a9 = block_state1.fst + c * (uint32_t)1U;
      Lib_IntVector_Intrinsics_vec128 *wv_b10 = block_state1.fst + d * (uint32_t)1U;
      wv_a9[0U] = Lib_IntVector_Intrinsics_vec128_add32(wv_a9[0U], wv_b10[0U]);
      Lib_IntVector_Intrinsics_vec128 *wv_a10 = block_state1.fst + b1 * (uint32_t)1U;
      Lib_IntVector_Intrinsics_vec128 *wv_b11 = block_state1.fst + c * (uint32_t)1U;
      wv_a10[0U] = Lib_IntVector_Intrinsics_vec128_xor(wv_a10[0U], wv_b11[0U]);
      wv_a10[0U] = Lib_IntVector_Intrinsics_vec128_rotate_right32(wv_a10[0U], r1);
      Lib_IntVector_Intrinsics_vec128 *wv_a11 = block_state1.fst + a0 * (uint32_t)1U;
      Lib_IntVector_Intrinsics_vec128 *wv_b12 = block_state1.fst + b1 * (uint32_t)1U;
      wv_a11[0U] = Lib_IntVector_Intrinsics_vec128_add32(wv_a11[0U], wv_b12[0U]);
      wv_a11[0U] = Lib_IntVector_Intrinsics_vec128_add32(wv_a11[0U], w[0U]);
      Lib_IntVector_Intrinsics_vec128 *wv_a12 = block_state1.fst + d * (uint32_t)1U;
      Lib_IntVector_Intrinsics_vec128 *wv_b13 = block_state1.fst + a0 * (uint32_t)1U;
      wv_a12[0U] = Lib_IntVector_Intrinsics_vec128_xor(wv_a12[0U], wv_b13[0U]);
      wv_a12[0U] = Lib_IntVector_Intrinsics_vec128_rotate_right32(wv_a12[0U], r23);
      Lib_IntVector_Intrinsics_vec128 *wv_a13 = block_state1.fst + c * (uint32_t)1U;
      Lib_IntVector_Intrinsics_vec128 *wv_b14 = block_state1.fst + d * (uint32_t)1U;
      wv_a13[0U] = Lib_IntVector_Intrinsics_vec128_add32(wv_a13[0U], wv_b14[0U]);
      Lib_IntVector_Intrinsics_vec128 *wv_a14 = block_state1.fst + b1 * (uint32_t)1U;
      Lib_IntVector_Intrinsics_vec128 *wv_b = block_state1.fst + c * (uint32_t)1U;
      wv_a14[0U] = Lib_IntVector_Intrinsics_vec128_xor(wv_a14[0U], wv_b[0U]);
      wv_a14[0U] = Lib_IntVector_Intrinsics_vec128_rotate_right32(wv_a14[0U], r33);
      Lib_IntVector_Intrinsics_vec128 *r13 = block_state1.fst + (uint32_t)1U * (uint32_t)1U;
      Lib_IntVector_Intrinsics_vec128 *r2 = block_state1.fst + (uint32_t)2U * (uint32_t)1U;
      Lib_IntVector_Intrinsics_vec128 *r3 = block_state1.fst + (uint32_t)3U * (uint32_t)1U;
      Lib_IntVector_Intrinsics_vec128 v0 = r13[0U];
      Lib_IntVector_Intrinsics_vec128
      v12 = Lib_IntVector_Intrinsics_vec128_rotate_right_lanes32(v0, (uint32_t)3U);
      r13[0U] = v12;
      Lib_IntVector_Intrinsics_vec128 v03 = r2[0U];
      Lib_IntVector_Intrinsics_vec128
      v13 = Lib_IntVector_Intrinsics_vec128_rotate_right_lanes32(v03, (uint32_t)2U);
      r2[0U] = v13;
      Lib_IntVector_Intrinsics_vec128 v04 = r3[0U];
      Lib_IntVector_Intrinsics_vec128
      v14 = Lib_IntVector_Intrinsics_vec128_rotate_right_lanes32(v04, (uint32_t)1U);
      r3[0U] = v14;
    }
    Lib_IntVector_Intrinsics_vec128 *s0 = block_state1.snd + (uint32_t)0U * (uint32_t)1U;
    Lib_IntVector_Intrinsics_vec128 *s11 = block_state1.snd + (uint32_t)1U * (uint32_t)1U;
    Lib_IntVector_Intrinsics_vec128 *r0 = block_state1.fst + (uint32_t)0U * (uint32_t)1U;
    Lib_IntVector_Intrinsics_vec128 *r1 = block_state1.fst + (uint32_t)1U * (uint32_t)1U;
    Lib_IntVector_Intrinsics_vec128 *r2 = block_state1.fst + (uint32_t)2U * (uint32_t)1U;
    Lib_IntVector_Intrinsics_vec128 *r3 = block_state1.fst + (uint32_t)3U * (uint32_t)1U;
    s0[0U] = Lib_IntVector_Intrinsics_vec128_xor(s0[0U], r0[0U]);
    s0[0U] = Lib_IntVector_Intrinsics_vec128_xor(s0[0U], r2[0U]);
    s11[0U] = Lib_IntVector_Intrinsics_vec128_xor(s11[0U], r1[0U]);
    s11[0U] = Lib_IntVector_Intrinsics_vec128_xor(s11[0U], r3[0U]);
  }
  uint8_t *dst = buf;
  memcpy(dst, data21, data2_len * sizeof (data21[0U]));
  *p
  =
    (
      (Hacl_Streaming_Functor_state_s__K____Lib_IntVector_Intrinsics_vec128___Lib_IntVector_Intrinsics_vec128____){
        .block_state = block_state1,
        .buf = buf,
        .total_len = total_len1 + (uint64_t)(len - diff)
      }
    );
}

/* SNIPPET_END: Hacl_Streaming_Blake2_blake2s_128_no_key_update */

/* SNIPPET_START: Hacl_Streaming_Blake2_blake2s_128_no_key_128_finish */

/*
  Finish function when there is no key
*/
void
Hacl_Streaming_Blake2_blake2s_128_no_key_128_finish(
  Hacl_Streaming_Functor_state_s__K____Lib_IntVector_Intrinsics_vec128___Lib_IntVector_Intrinsics_vec128____
  *p,
  uint8_t *dst
)
{
  Hacl_Streaming_Functor_state_s__K____Lib_IntVector_Intrinsics_vec128___Lib_IntVector_Intrinsics_vec128____
  scrut = *p;
  K____Lib_IntVector_Intrinsics_vec128___Lib_IntVector_Intrinsics_vec128_
  block_state = scrut.block_state;
  uint8_t *buf_ = scrut.buf;
  uint64_t total_len = scrut.total_len;
  uint32_t r;
  if (total_len % (uint64_t)(uint32_t)64U == (uint64_t)0U && total_len > (uint64_t)0U)
  {
    r = (uint32_t)64U;
  }
  else
  {
    r = (uint32_t)(total_len % (uint64_t)(uint32_t)64U);
  }
  uint8_t *buf_1 = buf_;
  KRML_CHECK_SIZE(sizeof (Lib_IntVector_Intrinsics_vec128), (uint32_t)4U * (uint32_t)1U);
  Lib_IntVector_Intrinsics_vec128 wv[(uint32_t)4U * (uint32_t)1U];
  for (uint32_t _i = 0U; _i < (uint32_t)4U * (uint32_t)1U; ++_i)
    wv[_i] = Lib_IntVector_Intrinsics_vec128_zero;
  KRML_CHECK_SIZE(sizeof (Lib_IntVector_Intrinsics_vec128), (uint32_t)4U * (uint32_t)1U);
  Lib_IntVector_Intrinsics_vec128 b0[(uint32_t)4U * (uint32_t)1U];
  for (uint32_t _i = 0U; _i < (uint32_t)4U * (uint32_t)1U; ++_i)
    b0[_i] = Lib_IntVector_Intrinsics_vec128_zero;
  K____Lib_IntVector_Intrinsics_vec128___Lib_IntVector_Intrinsics_vec128_
  tmp_block_state = { .fst = wv, .snd = b0 };
  Lib_IntVector_Intrinsics_vec128 *src_b = block_state.snd;
  Lib_IntVector_Intrinsics_vec128 *dst_b = tmp_block_state.snd;
  memcpy(dst_b, src_b, (uint32_t)4U * sizeof (src_b[0U]));
  uint64_t prev_len = total_len - (uint64_t)r;
  uint8_t b2[64U] = { 0U };
  uint8_t *last = buf_1 + r - r;
  memcpy(b2, last, r * sizeof (last[0U]));
  uint64_t ite;
  if ((uint32_t)0U == (uint32_t)0U)
  {
    ite = prev_len;
  }
  else
  {
    ite = prev_len + (uint64_t)(uint32_t)64U;
  }
  uint64_t totlen = ite + (uint64_t)r;
  uint32_t m_w[16U] = { 0U };
  for (uint32_t i = (uint32_t)0U; i < (uint32_t)16U; i++)
  {
    uint32_t *os = m_w;
    uint8_t *bj = b2 + i * (uint32_t)4U;
    uint32_t u = load32_le(bj);
    uint32_t r1 = u;
    uint32_t x = r1;
    os[i] = x;
  }
  Lib_IntVector_Intrinsics_vec128 mask = Lib_IntVector_Intrinsics_vec128_zero;
  uint32_t wv_14 = (uint32_t)0xFFFFFFFFU;
  uint32_t wv_15 = (uint32_t)0U;
  mask =
    Lib_IntVector_Intrinsics_vec128_load32s((uint32_t)totlen,
      (uint32_t)(totlen >> (uint32_t)32U),
      wv_14,
      wv_15);
  memcpy(tmp_block_state.fst,
    tmp_block_state.snd,
    (uint32_t)4U * (uint32_t)1U * sizeof (tmp_block_state.snd[0U]));
  Lib_IntVector_Intrinsics_vec128 *wv3 = tmp_block_state.fst + (uint32_t)3U * (uint32_t)1U;
  wv3[0U] = Lib_IntVector_Intrinsics_vec128_xor(wv3[0U], mask);
  for (uint32_t i = (uint32_t)0U; i < (uint32_t)10U; i++)
  {
    uint32_t start_idx = i % (uint32_t)10U * (uint32_t)16U;
    KRML_CHECK_SIZE(sizeof (Lib_IntVector_Intrinsics_vec128), (uint32_t)4U * (uint32_t)1U);
    Lib_IntVector_Intrinsics_vec128 m_st[(uint32_t)4U * (uint32_t)1U];
    for (uint32_t _i = 0U; _i < (uint32_t)4U * (uint32_t)1U; ++_i)
      m_st[_i] = Lib_IntVector_Intrinsics_vec128_zero;
    Lib_IntVector_Intrinsics_vec128 *r00 = m_st + (uint32_t)0U * (uint32_t)1U;
    Lib_IntVector_Intrinsics_vec128 *r10 = m_st + (uint32_t)1U * (uint32_t)1U;
    Lib_IntVector_Intrinsics_vec128 *r20 = m_st + (uint32_t)2U * (uint32_t)1U;
    Lib_IntVector_Intrinsics_vec128 *r30 = m_st + (uint32_t)3U * (uint32_t)1U;
    uint32_t s0 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx];
    uint32_t s1 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)1U];
    uint32_t s2 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)2U];
    uint32_t s3 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)3U];
    uint32_t s4 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)4U];
    uint32_t s5 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)5U];
    uint32_t s6 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)6U];
    uint32_t s7 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)7U];
    uint32_t s8 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)8U];
    uint32_t s9 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)9U];
    uint32_t s10 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)10U];
    uint32_t s11 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)11U];
    uint32_t s12 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)12U];
    uint32_t s13 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)13U];
    uint32_t s14 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)14U];
    uint32_t s15 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)15U];
    r00[0U] = Lib_IntVector_Intrinsics_vec128_load32s(m_w[s0], m_w[s2], m_w[s4], m_w[s6]);
    r10[0U] = Lib_IntVector_Intrinsics_vec128_load32s(m_w[s1], m_w[s3], m_w[s5], m_w[s7]);
    r20[0U] = Lib_IntVector_Intrinsics_vec128_load32s(m_w[s8], m_w[s10], m_w[s12], m_w[s14]);
    r30[0U] = Lib_IntVector_Intrinsics_vec128_load32s(m_w[s9], m_w[s11], m_w[s13], m_w[s15]);
    Lib_IntVector_Intrinsics_vec128 *x = m_st + (uint32_t)0U * (uint32_t)1U;
    Lib_IntVector_Intrinsics_vec128 *y = m_st + (uint32_t)1U * (uint32_t)1U;
    Lib_IntVector_Intrinsics_vec128 *z = m_st + (uint32_t)2U * (uint32_t)1U;
    Lib_IntVector_Intrinsics_vec128 *w = m_st + (uint32_t)3U * (uint32_t)1U;
    uint32_t a = (uint32_t)0U;
    uint32_t b10 = (uint32_t)1U;
    uint32_t c0 = (uint32_t)2U;
    uint32_t d0 = (uint32_t)3U;
    uint32_t r01 = Hacl_Impl_Blake2_Constants_rTable_S[0U];
    uint32_t r11 = Hacl_Impl_Blake2_Constants_rTable_S[1U];
    uint32_t r21 = Hacl_Impl_Blake2_Constants_rTable_S[2U];
    uint32_t r31 = Hacl_Impl_Blake2_Constants_rTable_S[3U];
    Lib_IntVector_Intrinsics_vec128 *wv_a0 = tmp_block_state.fst + a * (uint32_t)1U;
    Lib_IntVector_Intrinsics_vec128 *wv_b0 = tmp_block_state.fst + b10 * (uint32_t)1U;
    wv_a0[0U] = Lib_IntVector_Intrinsics_vec128_add32(wv_a0[0U], wv_b0[0U]);
    wv_a0[0U] = Lib_IntVector_Intrinsics_vec128_add32(wv_a0[0U], x[0U]);
    Lib_IntVector_Intrinsics_vec128 *wv_a1 = tmp_block_state.fst + d0 * (uint32_t)1U;
    Lib_IntVector_Intrinsics_vec128 *wv_b1 = tmp_block_state.fst + a * (uint32_t)1U;
    wv_a1[0U] = Lib_IntVector_Intrinsics_vec128_xor(wv_a1[0U], wv_b1[0U]);
    wv_a1[0U] = Lib_IntVector_Intrinsics_vec128_rotate_right32(wv_a1[0U], r01);
    Lib_IntVector_Intrinsics_vec128 *wv_a2 = tmp_block_state.fst + c0 * (uint32_t)1U;
    Lib_IntVector_Intrinsics_vec128 *wv_b2 = tmp_block_state.fst + d0 * (uint32_t)1U;
    wv_a2[0U] = Lib_IntVector_Intrinsics_vec128_add32(wv_a2[0U], wv_b2[0U]);
    Lib_IntVector_Intrinsics_vec128 *wv_a3 = tmp_block_state.fst + b10 * (uint32_t)1U;
    Lib_IntVector_Intrinsics_vec128 *wv_b3 = tmp_block_state.fst + c0 * (uint32_t)1U;
    wv_a3[0U] = Lib_IntVector_Intrinsics_vec128_xor(wv_a3[0U], wv_b3[0U]);
    wv_a3[0U] = Lib_IntVector_Intrinsics_vec128_rotate_right32(wv_a3[0U], r11);
    Lib_IntVector_Intrinsics_vec128 *wv_a4 = tmp_block_state.fst + a * (uint32_t)1U;
    Lib_IntVector_Intrinsics_vec128 *wv_b4 = tmp_block_state.fst + b10 * (uint32_t)1U;
    wv_a4[0U] = Lib_IntVector_Intrinsics_vec128_add32(wv_a4[0U], wv_b4[0U]);
    wv_a4[0U] = Lib_IntVector_Intrinsics_vec128_add32(wv_a4[0U], y[0U]);
    Lib_IntVector_Intrinsics_vec128 *wv_a5 = tmp_block_state.fst + d0 * (uint32_t)1U;
    Lib_IntVector_Intrinsics_vec128 *wv_b5 = tmp_block_state.fst + a * (uint32_t)1U;
    wv_a5[0U] = Lib_IntVector_Intrinsics_vec128_xor(wv_a5[0U], wv_b5[0U]);
    wv_a5[0U] = Lib_IntVector_Intrinsics_vec128_rotate_right32(wv_a5[0U], r21);
    Lib_IntVector_Intrinsics_vec128 *wv_a6 = tmp_block_state.fst + c0 * (uint32_t)1U;
    Lib_IntVector_Intrinsics_vec128 *wv_b6 = tmp_block_state.fst + d0 * (uint32_t)1U;
    wv_a6[0U] = Lib_IntVector_Intrinsics_vec128_add32(wv_a6[0U], wv_b6[0U]);
    Lib_IntVector_Intrinsics_vec128 *wv_a7 = tmp_block_state.fst + b10 * (uint32_t)1U;
    Lib_IntVector_Intrinsics_vec128 *wv_b7 = tmp_block_state.fst + c0 * (uint32_t)1U;
    wv_a7[0U] = Lib_IntVector_Intrinsics_vec128_xor(wv_a7[0U], wv_b7[0U]);
    wv_a7[0U] = Lib_IntVector_Intrinsics_vec128_rotate_right32(wv_a7[0U], r31);
    Lib_IntVector_Intrinsics_vec128 *r12 = tmp_block_state.fst + (uint32_t)1U * (uint32_t)1U;
    Lib_IntVector_Intrinsics_vec128 *r22 = tmp_block_state.fst + (uint32_t)2U * (uint32_t)1U;
    Lib_IntVector_Intrinsics_vec128 *r32 = tmp_block_state.fst + (uint32_t)3U * (uint32_t)1U;
    Lib_IntVector_Intrinsics_vec128 v00 = r12[0U];
    Lib_IntVector_Intrinsics_vec128
    v1 = Lib_IntVector_Intrinsics_vec128_rotate_right_lanes32(v00, (uint32_t)1U);
    r12[0U] = v1;
    Lib_IntVector_Intrinsics_vec128 v01 = r22[0U];
    Lib_IntVector_Intrinsics_vec128
    v10 = Lib_IntVector_Intrinsics_vec128_rotate_right_lanes32(v01, (uint32_t)2U);
    r22[0U] = v10;
    Lib_IntVector_Intrinsics_vec128 v02 = r32[0U];
    Lib_IntVector_Intrinsics_vec128
    v11 = Lib_IntVector_Intrinsics_vec128_rotate_right_lanes32(v02, (uint32_t)3U);
    r32[0U] = v11;
    uint32_t a0 = (uint32_t)0U;
    uint32_t b1 = (uint32_t)1U;
    uint32_t c = (uint32_t)2U;
    uint32_t d = (uint32_t)3U;
    uint32_t r0 = Hacl_Impl_Blake2_Constants_rTable_S[0U];
    uint32_t r1 = Hacl_Impl_Blake2_Constants_rTable_S[1U];
    uint32_t r23 = Hacl_Impl_Blake2_Constants_rTable_S[2U];
    uint32_t r33 = Hacl_Impl_Blake2_Constants_rTable_S[3U];
    Lib_IntVector_Intrinsics_vec128 *wv_a = tmp_block_state.fst + a0 * (uint32_t)1U;
    Lib_IntVector_Intrinsics_vec128 *wv_b8 = tmp_block_state.fst + b1 * (uint32_t)1U;
    wv_a[0U] = Lib_IntVector_Intrinsics_vec128_add32(wv_a[0U], wv_b8[0U]);
    wv_a[0U] = Lib_IntVector_Intrinsics_vec128_add32(wv_a[0U], z[0U]);
    Lib_IntVector_Intrinsics_vec128 *wv_a8 = tmp_block_state.fst + d * (uint32_t)1U;
    Lib_IntVector_Intrinsics_vec128 *wv_b9 = tmp_block_state.fst + a0 * (uint32_t)1U;
    wv_a8[0U] = Lib_IntVector_Intrinsics_vec128_xor(wv_a8[0U], wv_b9[0U]);
    wv_a8[0U] = Lib_IntVector_Intrinsics_vec128_rotate_right32(wv_a8[0U], r0);
    Lib_IntVector_Intrinsics_vec128 *wv_a9 = tmp_block_state.fst + c * (uint32_t)1U;
    Lib_IntVector_Intrinsics_vec128 *wv_b10 = tmp_block_state.fst + d * (uint32_t)1U;
    wv_a9[0U] = Lib_IntVector_Intrinsics_vec128_add32(wv_a9[0U], wv_b10[0U]);
    Lib_IntVector_Intrinsics_vec128 *wv_a10 = tmp_block_state.fst + b1 * (uint32_t)1U;
    Lib_IntVector_Intrinsics_vec128 *wv_b11 = tmp_block_state.fst + c * (uint32_t)1U;
    wv_a10[0U] = Lib_IntVector_Intrinsics_vec128_xor(wv_a10[0U], wv_b11[0U]);
    wv_a10[0U] = Lib_IntVector_Intrinsics_vec128_rotate_right32(wv_a10[0U], r1);
    Lib_IntVector_Intrinsics_vec128 *wv_a11 = tmp_block_state.fst + a0 * (uint32_t)1U;
    Lib_IntVector_Intrinsics_vec128 *wv_b12 = tmp_block_state.fst + b1 * (uint32_t)1U;
    wv_a11[0U] = Lib_IntVector_Intrinsics_vec128_add32(wv_a11[0U], wv_b12[0U]);
    wv_a11[0U] = Lib_IntVector_Intrinsics_vec128_add32(wv_a11[0U], w[0U]);
    Lib_IntVector_Intrinsics_vec128 *wv_a12 = tmp_block_state.fst + d * (uint32_t)1U;
    Lib_IntVector_Intrinsics_vec128 *wv_b13 = tmp_block_state.fst + a0 * (uint32_t)1U;
    wv_a12[0U] = Lib_IntVector_Intrinsics_vec128_xor(wv_a12[0U], wv_b13[0U]);
    wv_a12[0U] = Lib_IntVector_Intrinsics_vec128_rotate_right32(wv_a12[0U], r23);
    Lib_IntVector_Intrinsics_vec128 *wv_a13 = tmp_block_state.fst + c * (uint32_t)1U;
    Lib_IntVector_Intrinsics_vec128 *wv_b14 = tmp_block_state.fst + d * (uint32_t)1U;
    wv_a13[0U] = Lib_IntVector_Intrinsics_vec128_add32(wv_a13[0U], wv_b14[0U]);
    Lib_IntVector_Intrinsics_vec128 *wv_a14 = tmp_block_state.fst + b1 * (uint32_t)1U;
    Lib_IntVector_Intrinsics_vec128 *wv_b = tmp_block_state.fst + c * (uint32_t)1U;
    wv_a14[0U] = Lib_IntVector_Intrinsics_vec128_xor(wv_a14[0U], wv_b[0U]);
    wv_a14[0U] = Lib_IntVector_Intrinsics_vec128_rotate_right32(wv_a14[0U], r33);
    Lib_IntVector_Intrinsics_vec128 *r13 = tmp_block_state.fst + (uint32_t)1U * (uint32_t)1U;
    Lib_IntVector_Intrinsics_vec128 *r2 = tmp_block_state.fst + (uint32_t)2U * (uint32_t)1U;
    Lib_IntVector_Intrinsics_vec128 *r3 = tmp_block_state.fst + (uint32_t)3U * (uint32_t)1U;
    Lib_IntVector_Intrinsics_vec128 v0 = r13[0U];
    Lib_IntVector_Intrinsics_vec128
    v12 = Lib_IntVector_Intrinsics_vec128_rotate_right_lanes32(v0, (uint32_t)3U);
    r13[0U] = v12;
    Lib_IntVector_Intrinsics_vec128 v03 = r2[0U];
    Lib_IntVector_Intrinsics_vec128
    v13 = Lib_IntVector_Intrinsics_vec128_rotate_right_lanes32(v03, (uint32_t)2U);
    r2[0U] = v13;
    Lib_IntVector_Intrinsics_vec128 v04 = r3[0U];
    Lib_IntVector_Intrinsics_vec128
    v14 = Lib_IntVector_Intrinsics_vec128_rotate_right_lanes32(v04, (uint32_t)1U);
    r3[0U] = v14;
  }
  Lib_IntVector_Intrinsics_vec128 *s0 = tmp_block_state.snd + (uint32_t)0U * (uint32_t)1U;
  Lib_IntVector_Intrinsics_vec128 *s1 = tmp_block_state.snd + (uint32_t)1U * (uint32_t)1U;
  Lib_IntVector_Intrinsics_vec128 *r0 = tmp_block_state.fst + (uint32_t)0U * (uint32_t)1U;
  Lib_IntVector_Intrinsics_vec128 *r1 = tmp_block_state.fst + (uint32_t)1U * (uint32_t)1U;
  Lib_IntVector_Intrinsics_vec128 *r2 = tmp_block_state.fst + (uint32_t)2U * (uint32_t)1U;
  Lib_IntVector_Intrinsics_vec128 *r3 = tmp_block_state.fst + (uint32_t)3U * (uint32_t)1U;
  s0[0U] = Lib_IntVector_Intrinsics_vec128_xor(s0[0U], r0[0U]);
  s0[0U] = Lib_IntVector_Intrinsics_vec128_xor(s0[0U], r2[0U]);
  s1[0U] = Lib_IntVector_Intrinsics_vec128_xor(s1[0U], r1[0U]);
  s1[0U] = Lib_IntVector_Intrinsics_vec128_xor(s1[0U], r3[0U]);
  Lib_Memzero0_memzero(b2, (uint32_t)64U * sizeof (b2[0U]));
  uint32_t double_row = (uint32_t)2U * (uint32_t)4U * (uint32_t)4U;
  KRML_CHECK_SIZE(sizeof (uint8_t), double_row);
  uint8_t b[double_row];
  memset(b, 0U, double_row * sizeof (b[0U]));
  uint8_t *first = b;
  uint8_t *second = b + (uint32_t)4U * (uint32_t)4U;
  Lib_IntVector_Intrinsics_vec128 *row0 = tmp_block_state.snd + (uint32_t)0U * (uint32_t)1U;
  Lib_IntVector_Intrinsics_vec128 *row1 = tmp_block_state.snd + (uint32_t)1U * (uint32_t)1U;
  Lib_IntVector_Intrinsics_vec128_store_le(first, row0[0U]);
  Lib_IntVector_Intrinsics_vec128_store_le(second, row1[0U]);
  uint8_t *final = b;
  memcpy(dst, final, (uint32_t)32U * sizeof (final[0U]));
  Lib_Memzero0_memzero(b, double_row * sizeof (b[0U]));
}

/* SNIPPET_END: Hacl_Streaming_Blake2_blake2s_128_no_key_128_finish */

/* SNIPPET_START: Hacl_Streaming_Blake2_blake2s_128_no_key_free */

/*
  Free state function when there is no key
*/
void
Hacl_Streaming_Blake2_blake2s_128_no_key_free(
  Hacl_Streaming_Functor_state_s__K____Lib_IntVector_Intrinsics_vec128___Lib_IntVector_Intrinsics_vec128____
  *s1
)
{
  Hacl_Streaming_Functor_state_s__K____Lib_IntVector_Intrinsics_vec128___Lib_IntVector_Intrinsics_vec128____
  scrut = *s1;
  uint8_t *buf = scrut.buf;
  K____Lib_IntVector_Intrinsics_vec128___Lib_IntVector_Intrinsics_vec128_
  block_state = scrut.block_state;
  Lib_IntVector_Intrinsics_vec128 *wv = block_state.fst;
  Lib_IntVector_Intrinsics_vec128 *b = block_state.snd;
  KRML_HOST_FREE(wv);
  KRML_HOST_FREE(b);
  KRML_HOST_FREE(buf);
  KRML_HOST_FREE(s1);
}

/* SNIPPET_END: Hacl_Streaming_Blake2_blake2s_128_no_key_free */

/* SNIPPET_START: Hacl_Streaming_Functor_state_s__K____uint64_t___uint64_t____ */

typedef struct Hacl_Streaming_Functor_state_s__K____uint64_t___uint64_t_____s
{
  K____uint64_t___uint64_t_ block_state;
  uint8_t *buf;
  uint64_t total_len;
}
Hacl_Streaming_Functor_state_s__K____uint64_t___uint64_t____;

/* SNIPPET_END: Hacl_Streaming_Functor_state_s__K____uint64_t___uint64_t____ */

/* SNIPPET_START: Hacl_Streaming_Blake2_blake2b_32_no_key_create_in */

/*
  State allocation function when there is no key
*/
Hacl_Streaming_Functor_state_s__K____uint64_t___uint64_t____
*Hacl_Streaming_Blake2_blake2b_32_no_key_create_in()
{
  uint8_t *buf = KRML_HOST_CALLOC((uint32_t)128U, sizeof (uint8_t));
  uint64_t *wv = KRML_HOST_CALLOC((uint32_t)16U, sizeof (uint64_t));
  uint64_t *b0 = KRML_HOST_CALLOC((uint32_t)16U, sizeof (uint64_t));
  K____uint64_t___uint64_t_ block_state = { .fst = wv, .snd = b0 };
  Hacl_Streaming_Functor_state_s__K____uint64_t___uint64_t____
  s1 = { .block_state = block_state, .buf = buf, .total_len = (uint64_t)0U };
  KRML_CHECK_SIZE(sizeof (Hacl_Streaming_Functor_state_s__K____uint64_t___uint64_t____),
    (uint32_t)1U);
  Hacl_Streaming_Functor_state_s__K____uint64_t___uint64_t____
  *p = KRML_HOST_MALLOC(sizeof (Hacl_Streaming_Functor_state_s__K____uint64_t___uint64_t____));
  p[0U] = s1;
  uint8_t b[128U] = { 0U };
  uint64_t *r00 = block_state.snd + (uint32_t)0U * (uint32_t)4U;
  uint64_t *r10 = block_state.snd + (uint32_t)1U * (uint32_t)4U;
  uint64_t *r20 = block_state.snd + (uint32_t)2U * (uint32_t)4U;
  uint64_t *r30 = block_state.snd + (uint32_t)3U * (uint32_t)4U;
  uint64_t iv0 = Hacl_Impl_Blake2_Constants_ivTable_B[0U];
  uint64_t iv1 = Hacl_Impl_Blake2_Constants_ivTable_B[1U];
  uint64_t iv2 = Hacl_Impl_Blake2_Constants_ivTable_B[2U];
  uint64_t iv3 = Hacl_Impl_Blake2_Constants_ivTable_B[3U];
  uint64_t iv4 = Hacl_Impl_Blake2_Constants_ivTable_B[4U];
  uint64_t iv5 = Hacl_Impl_Blake2_Constants_ivTable_B[5U];
  uint64_t iv6 = Hacl_Impl_Blake2_Constants_ivTable_B[6U];
  uint64_t iv7 = Hacl_Impl_Blake2_Constants_ivTable_B[7U];
  r20[0U] = iv0;
  r20[1U] = iv1;
  r20[2U] = iv2;
  r20[3U] = iv3;
  r30[0U] = iv4;
  r30[1U] = iv5;
  r30[2U] = iv6;
  r30[3U] = iv7;
  uint64_t kk_shift_8 = (uint64_t)(uint32_t)0U << (uint32_t)8U;
  uint64_t iv0_ = iv0 ^ ((uint64_t)0x01010000U ^ (kk_shift_8 ^ (uint64_t)(uint32_t)64U));
  r00[0U] = iv0_;
  r00[1U] = iv1;
  r00[2U] = iv2;
  r00[3U] = iv3;
  r10[0U] = iv4;
  r10[1U] = iv5;
  r10[2U] = iv6;
  r10[3U] = iv7;
  if (!((uint32_t)0U == (uint32_t)0U))
  {
    memcpy(b, NULL, (uint32_t)0U * sizeof (NULL[0U]));
    FStar_UInt128_uint128
    totlen =
      FStar_UInt128_add_mod(FStar_UInt128_uint64_to_uint128((uint64_t)(uint32_t)0U),
        FStar_UInt128_uint64_to_uint128((uint64_t)(uint32_t)128U));
    uint8_t *b1 = b + (uint32_t)0U * (uint32_t)128U;
    uint64_t m_w[16U] = { 0U };
    for (uint32_t i = (uint32_t)0U; i < (uint32_t)16U; i++)
    {
      uint64_t *os = m_w;
      uint8_t *bj = b1 + i * (uint32_t)8U;
      uint64_t u = load64_le(bj);
      uint64_t r1 = u;
      uint64_t x = r1;
      os[i] = x;
    }
    uint64_t mask[4U] = { 0U };
    uint64_t wv_14 = (uint64_t)0U;
    uint64_t wv_15 = (uint64_t)0U;
    mask[0U] = FStar_UInt128_uint128_to_uint64(totlen);
    mask[1U] = FStar_UInt128_uint128_to_uint64(FStar_UInt128_shift_right(totlen, (uint32_t)64U));
    mask[2U] = wv_14;
    mask[3U] = wv_15;
    memcpy(block_state.fst,
      block_state.snd,
      (uint32_t)4U * (uint32_t)4U * sizeof (block_state.snd[0U]));
    uint64_t *wv3 = block_state.fst + (uint32_t)3U * (uint32_t)4U;
    for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
    {
      uint64_t *os = wv3;
      uint64_t x = wv3[i] ^ mask[i];
      os[i] = x;
    }
    for (uint32_t i0 = (uint32_t)0U; i0 < (uint32_t)12U; i0++)
    {
      uint32_t start_idx = i0 % (uint32_t)10U * (uint32_t)16U;
      KRML_CHECK_SIZE(sizeof (uint64_t), (uint32_t)4U * (uint32_t)4U);
      uint64_t m_st[(uint32_t)4U * (uint32_t)4U];
      memset(m_st, 0U, (uint32_t)4U * (uint32_t)4U * sizeof (m_st[0U]));
      uint64_t *r01 = m_st + (uint32_t)0U * (uint32_t)4U;
      uint64_t *r12 = m_st + (uint32_t)1U * (uint32_t)4U;
      uint64_t *r21 = m_st + (uint32_t)2U * (uint32_t)4U;
      uint64_t *r31 = m_st + (uint32_t)3U * (uint32_t)4U;
      uint32_t s0 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx];
      uint32_t s11 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)1U];
      uint32_t s2 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)2U];
      uint32_t s3 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)3U];
      uint32_t s4 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)4U];
      uint32_t s5 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)5U];
      uint32_t s6 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)6U];
      uint32_t s7 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)7U];
      uint32_t s8 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)8U];
      uint32_t s9 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)9U];
      uint32_t s10 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)10U];
      uint32_t s111 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)11U];
      uint32_t s12 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)12U];
      uint32_t s13 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)13U];
      uint32_t s14 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)14U];
      uint32_t s15 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)15U];
      uint64_t uu____0 = m_w[s2];
      uint64_t uu____1 = m_w[s4];
      uint64_t uu____2 = m_w[s6];
      r01[0U] = m_w[s0];
      r01[1U] = uu____0;
      r01[2U] = uu____1;
      r01[3U] = uu____2;
      uint64_t uu____3 = m_w[s3];
      uint64_t uu____4 = m_w[s5];
      uint64_t uu____5 = m_w[s7];
      r12[0U] = m_w[s11];
      r12[1U] = uu____3;
      r12[2U] = uu____4;
      r12[3U] = uu____5;
      uint64_t uu____6 = m_w[s10];
      uint64_t uu____7 = m_w[s12];
      uint64_t uu____8 = m_w[s14];
      r21[0U] = m_w[s8];
      r21[1U] = uu____6;
      r21[2U] = uu____7;
      r21[3U] = uu____8;
      uint64_t uu____9 = m_w[s111];
      uint64_t uu____10 = m_w[s13];
      uint64_t uu____11 = m_w[s15];
      r31[0U] = m_w[s9];
      r31[1U] = uu____9;
      r31[2U] = uu____10;
      r31[3U] = uu____11;
      uint64_t *x = m_st + (uint32_t)0U * (uint32_t)4U;
      uint64_t *y = m_st + (uint32_t)1U * (uint32_t)4U;
      uint64_t *z = m_st + (uint32_t)2U * (uint32_t)4U;
      uint64_t *w = m_st + (uint32_t)3U * (uint32_t)4U;
      uint32_t a = (uint32_t)0U;
      uint32_t b20 = (uint32_t)1U;
      uint32_t c0 = (uint32_t)2U;
      uint32_t d0 = (uint32_t)3U;
      uint32_t r02 = Hacl_Impl_Blake2_Constants_rTable_B[0U];
      uint32_t r13 = Hacl_Impl_Blake2_Constants_rTable_B[1U];
      uint32_t r22 = Hacl_Impl_Blake2_Constants_rTable_B[2U];
      uint32_t r32 = Hacl_Impl_Blake2_Constants_rTable_B[3U];
      uint64_t *wv_a0 = block_state.fst + a * (uint32_t)4U;
      uint64_t *wv_b0 = block_state.fst + b20 * (uint32_t)4U;
      for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
      {
        uint64_t *os = wv_a0;
        uint64_t x1 = wv_a0[i] + wv_b0[i];
        os[i] = x1;
      }
      for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
      {
        uint64_t *os = wv_a0;
        uint64_t x1 = wv_a0[i] + x[i];
        os[i] = x1;
      }
      uint64_t *wv_a1 = block_state.fst + d0 * (uint32_t)4U;
      uint64_t *wv_b1 = block_state.fst + a * (uint32_t)4U;
      for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
      {
        uint64_t *os = wv_a1;
        uint64_t x1 = wv_a1[i] ^ wv_b1[i];
        os[i] = x1;
      }
      uint64_t *r110 = wv_a1;
      for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
      {
        uint64_t *os = r110;
        uint64_t x1 = r110[i];
        uint64_t x10 = x1 >> r02 | x1 << ((uint32_t)64U - r02);
        os[i] = x10;
      }
      uint64_t *wv_a2 = block_state.fst + c0 * (uint32_t)4U;
      uint64_t *wv_b2 = block_state.fst + d0 * (uint32_t)4U;
      for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
      {
        uint64_t *os = wv_a2;
        uint64_t x1 = wv_a2[i] + wv_b2[i];
        os[i] = x1;
      }
      uint64_t *wv_a3 = block_state.fst + b20 * (uint32_t)4U;
      uint64_t *wv_b3 = block_state.fst + c0 * (uint32_t)4U;
      for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
      {
        uint64_t *os = wv_a3;
        uint64_t x1 = wv_a3[i] ^ wv_b3[i];
        os[i] = x1;
      }
      uint64_t *r111 = wv_a3;
      for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
      {
        uint64_t *os = r111;
        uint64_t x1 = r111[i];
        uint64_t x10 = x1 >> r13 | x1 << ((uint32_t)64U - r13);
        os[i] = x10;
      }
      uint64_t *wv_a4 = block_state.fst + a * (uint32_t)4U;
      uint64_t *wv_b4 = block_state.fst + b20 * (uint32_t)4U;
      for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
      {
        uint64_t *os = wv_a4;
        uint64_t x1 = wv_a4[i] + wv_b4[i];
        os[i] = x1;
      }
      for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
      {
        uint64_t *os = wv_a4;
        uint64_t x1 = wv_a4[i] + y[i];
        os[i] = x1;
      }
      uint64_t *wv_a5 = block_state.fst + d0 * (uint32_t)4U;
      uint64_t *wv_b5 = block_state.fst + a * (uint32_t)4U;
      for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
      {
        uint64_t *os = wv_a5;
        uint64_t x1 = wv_a5[i] ^ wv_b5[i];
        os[i] = x1;
      }
      uint64_t *r112 = wv_a5;
      for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
      {
        uint64_t *os = r112;
        uint64_t x1 = r112[i];
        uint64_t x10 = x1 >> r22 | x1 << ((uint32_t)64U - r22);
        os[i] = x10;
      }
      uint64_t *wv_a6 = block_state.fst + c0 * (uint32_t)4U;
      uint64_t *wv_b6 = block_state.fst + d0 * (uint32_t)4U;
      for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
      {
        uint64_t *os = wv_a6;
        uint64_t x1 = wv_a6[i] + wv_b6[i];
        os[i] = x1;
      }
      uint64_t *wv_a7 = block_state.fst + b20 * (uint32_t)4U;
      uint64_t *wv_b7 = block_state.fst + c0 * (uint32_t)4U;
      for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
      {
        uint64_t *os = wv_a7;
        uint64_t x1 = wv_a7[i] ^ wv_b7[i];
        os[i] = x1;
      }
      uint64_t *r113 = wv_a7;
      for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
      {
        uint64_t *os = r113;
        uint64_t x1 = r113[i];
        uint64_t x10 = x1 >> r32 | x1 << ((uint32_t)64U - r32);
        os[i] = x10;
      }
      uint64_t *r14 = block_state.fst + (uint32_t)1U * (uint32_t)4U;
      uint64_t *r23 = block_state.fst + (uint32_t)2U * (uint32_t)4U;
      uint64_t *r33 = block_state.fst + (uint32_t)3U * (uint32_t)4U;
      uint64_t *r114 = r14;
      uint64_t x00 = r114[1U];
      uint64_t x10 = r114[((uint32_t)1U + (uint32_t)1U) % (uint32_t)4U];
      uint64_t x20 = r114[((uint32_t)1U + (uint32_t)2U) % (uint32_t)4U];
      uint64_t x30 = r114[((uint32_t)1U + (uint32_t)3U) % (uint32_t)4U];
      r114[0U] = x00;
      r114[1U] = x10;
      r114[2U] = x20;
      r114[3U] = x30;
      uint64_t *r115 = r23;
      uint64_t x01 = r115[2U];
      uint64_t x11 = r115[((uint32_t)2U + (uint32_t)1U) % (uint32_t)4U];
      uint64_t x21 = r115[((uint32_t)2U + (uint32_t)2U) % (uint32_t)4U];
      uint64_t x31 = r115[((uint32_t)2U + (uint32_t)3U) % (uint32_t)4U];
      r115[0U] = x01;
      r115[1U] = x11;
      r115[2U] = x21;
      r115[3U] = x31;
      uint64_t *r116 = r33;
      uint64_t x02 = r116[3U];
      uint64_t x12 = r116[((uint32_t)3U + (uint32_t)1U) % (uint32_t)4U];
      uint64_t x22 = r116[((uint32_t)3U + (uint32_t)2U) % (uint32_t)4U];
      uint64_t x32 = r116[((uint32_t)3U + (uint32_t)3U) % (uint32_t)4U];
      r116[0U] = x02;
      r116[1U] = x12;
      r116[2U] = x22;
      r116[3U] = x32;
      uint32_t a0 = (uint32_t)0U;
      uint32_t b2 = (uint32_t)1U;
      uint32_t c = (uint32_t)2U;
      uint32_t d = (uint32_t)3U;
      uint32_t r0 = Hacl_Impl_Blake2_Constants_rTable_B[0U];
      uint32_t r1 = Hacl_Impl_Blake2_Constants_rTable_B[1U];
      uint32_t r24 = Hacl_Impl_Blake2_Constants_rTable_B[2U];
      uint32_t r34 = Hacl_Impl_Blake2_Constants_rTable_B[3U];
      uint64_t *wv_a = block_state.fst + a0 * (uint32_t)4U;
      uint64_t *wv_b8 = block_state.fst + b2 * (uint32_t)4U;
      for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
      {
        uint64_t *os = wv_a;
        uint64_t x1 = wv_a[i] + wv_b8[i];
        os[i] = x1;
      }
      for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
      {
        uint64_t *os = wv_a;
        uint64_t x1 = wv_a[i] + z[i];
        os[i] = x1;
      }
      uint64_t *wv_a8 = block_state.fst + d * (uint32_t)4U;
      uint64_t *wv_b9 = block_state.fst + a0 * (uint32_t)4U;
      for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
      {
        uint64_t *os = wv_a8;
        uint64_t x1 = wv_a8[i] ^ wv_b9[i];
        os[i] = x1;
      }
      uint64_t *r117 = wv_a8;
      for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
      {
        uint64_t *os = r117;
        uint64_t x1 = r117[i];
        uint64_t x13 = x1 >> r0 | x1 << ((uint32_t)64U - r0);
        os[i] = x13;
      }
      uint64_t *wv_a9 = block_state.fst + c * (uint32_t)4U;
      uint64_t *wv_b10 = block_state.fst + d * (uint32_t)4U;
      for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
      {
        uint64_t *os = wv_a9;
        uint64_t x1 = wv_a9[i] + wv_b10[i];
        os[i] = x1;
      }
      uint64_t *wv_a10 = block_state.fst + b2 * (uint32_t)4U;
      uint64_t *wv_b11 = block_state.fst + c * (uint32_t)4U;
      for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
      {
        uint64_t *os = wv_a10;
        uint64_t x1 = wv_a10[i] ^ wv_b11[i];
        os[i] = x1;
      }
      uint64_t *r118 = wv_a10;
      for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
      {
        uint64_t *os = r118;
        uint64_t x1 = r118[i];
        uint64_t x13 = x1 >> r1 | x1 << ((uint32_t)64U - r1);
        os[i] = x13;
      }
      uint64_t *wv_a11 = block_state.fst + a0 * (uint32_t)4U;
      uint64_t *wv_b12 = block_state.fst + b2 * (uint32_t)4U;
      for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
      {
        uint64_t *os = wv_a11;
        uint64_t x1 = wv_a11[i] + wv_b12[i];
        os[i] = x1;
      }
      for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
      {
        uint64_t *os = wv_a11;
        uint64_t x1 = wv_a11[i] + w[i];
        os[i] = x1;
      }
      uint64_t *wv_a12 = block_state.fst + d * (uint32_t)4U;
      uint64_t *wv_b13 = block_state.fst + a0 * (uint32_t)4U;
      for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
      {
        uint64_t *os = wv_a12;
        uint64_t x1 = wv_a12[i] ^ wv_b13[i];
        os[i] = x1;
      }
      uint64_t *r119 = wv_a12;
      for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
      {
        uint64_t *os = r119;
        uint64_t x1 = r119[i];
        uint64_t x13 = x1 >> r24 | x1 << ((uint32_t)64U - r24);
        os[i] = x13;
      }
      uint64_t *wv_a13 = block_state.fst + c * (uint32_t)4U;
      uint64_t *wv_b14 = block_state.fst + d * (uint32_t)4U;
      for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
      {
        uint64_t *os = wv_a13;
        uint64_t x1 = wv_a13[i] + wv_b14[i];
        os[i] = x1;
      }
      uint64_t *wv_a14 = block_state.fst + b2 * (uint32_t)4U;
      uint64_t *wv_b = block_state.fst + c * (uint32_t)4U;
      for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
      {
        uint64_t *os = wv_a14;
        uint64_t x1 = wv_a14[i] ^ wv_b[i];
        os[i] = x1;
      }
      uint64_t *r1110 = wv_a14;
      for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
      {
        uint64_t *os = r1110;
        uint64_t x1 = r1110[i];
        uint64_t x13 = x1 >> r34 | x1 << ((uint32_t)64U - r34);
        os[i] = x13;
      }
      uint64_t *r15 = block_state.fst + (uint32_t)1U * (uint32_t)4U;
      uint64_t *r2 = block_state.fst + (uint32_t)2U * (uint32_t)4U;
      uint64_t *r3 = block_state.fst + (uint32_t)3U * (uint32_t)4U;
      uint64_t *r11 = r15;
      uint64_t x03 = r11[3U];
      uint64_t x13 = r11[((uint32_t)3U + (uint32_t)1U) % (uint32_t)4U];
      uint64_t x23 = r11[((uint32_t)3U + (uint32_t)2U) % (uint32_t)4U];
      uint64_t x33 = r11[((uint32_t)3U + (uint32_t)3U) % (uint32_t)4U];
      r11[0U] = x03;
      r11[1U] = x13;
      r11[2U] = x23;
      r11[3U] = x33;
      uint64_t *r1111 = r2;
      uint64_t x04 = r1111[2U];
      uint64_t x14 = r1111[((uint32_t)2U + (uint32_t)1U) % (uint32_t)4U];
      uint64_t x24 = r1111[((uint32_t)2U + (uint32_t)2U) % (uint32_t)4U];
      uint64_t x34 = r1111[((uint32_t)2U + (uint32_t)3U) % (uint32_t)4U];
      r1111[0U] = x04;
      r1111[1U] = x14;
      r1111[2U] = x24;
      r1111[3U] = x34;
      uint64_t *r1112 = r3;
      uint64_t x0 = r1112[1U];
      uint64_t x1 = r1112[((uint32_t)1U + (uint32_t)1U) % (uint32_t)4U];
      uint64_t x2 = r1112[((uint32_t)1U + (uint32_t)2U) % (uint32_t)4U];
      uint64_t x3 = r1112[((uint32_t)1U + (uint32_t)3U) % (uint32_t)4U];
      r1112[0U] = x0;
      r1112[1U] = x1;
      r1112[2U] = x2;
      r1112[3U] = x3;
    }
    uint64_t *s0 = block_state.snd + (uint32_t)0U * (uint32_t)4U;
    uint64_t *s11 = block_state.snd + (uint32_t)1U * (uint32_t)4U;
    uint64_t *r0 = block_state.fst + (uint32_t)0U * (uint32_t)4U;
    uint64_t *r1 = block_state.fst + (uint32_t)1U * (uint32_t)4U;
    uint64_t *r2 = block_state.fst + (uint32_t)2U * (uint32_t)4U;
    uint64_t *r3 = block_state.fst + (uint32_t)3U * (uint32_t)4U;
    for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
    {
      uint64_t *os = s0;
      uint64_t x = s0[i] ^ r0[i];
      os[i] = x;
    }
    for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
    {
      uint64_t *os = s0;
      uint64_t x = s0[i] ^ r2[i];
      os[i] = x;
    }
    for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
    {
      uint64_t *os = s11;
      uint64_t x = s11[i] ^ r1[i];
      os[i] = x;
    }
    for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
    {
      uint64_t *os = s11;
      uint64_t x = s11[i] ^ r3[i];
      os[i] = x;
    }
  }
  Lib_Memzero0_memzero(b, (uint32_t)128U * sizeof (b[0U]));
  return p;
}

/* SNIPPET_END: Hacl_Streaming_Blake2_blake2b_32_no_key_create_in */

/* SNIPPET_START: Hacl_Streaming_Blake2_blake2b_32_no_key_update */

/*
  Update function when there is no key
*/
void
Hacl_Streaming_Blake2_blake2b_32_no_key_update(
  Hacl_Streaming_Functor_state_s__K____uint64_t___uint64_t____ *p,
  uint8_t *data,
  uint32_t len
)
{
  Hacl_Streaming_Functor_state_s__K____uint64_t___uint64_t____ s1 = *p;
  uint64_t total_len = s1.total_len;
  uint32_t sz;
  if (total_len % (uint64_t)(uint32_t)128U == (uint64_t)0U && total_len > (uint64_t)0U)
  {
    sz = (uint32_t)128U;
  }
  else
  {
    sz = (uint32_t)(total_len % (uint64_t)(uint32_t)128U);
  }
  if (len <= (uint32_t)128U - sz)
  {
    Hacl_Streaming_Functor_state_s__K____uint64_t___uint64_t____ s2 = *p;
    K____uint64_t___uint64_t_ block_state1 = s2.block_state;
    uint8_t *buf = s2.buf;
    uint64_t total_len1 = s2.total_len;
    uint32_t sz1;
    if (total_len1 % (uint64_t)(uint32_t)128U == (uint64_t)0U && total_len1 > (uint64_t)0U)
    {
      sz1 = (uint32_t)128U;
    }
    else
    {
      sz1 = (uint32_t)(total_len1 % (uint64_t)(uint32_t)128U);
    }
    uint8_t *buf2 = buf + sz1;
    memcpy(buf2, data, len * sizeof (data[0U]));
    uint64_t total_len2 = total_len1 + (uint64_t)len;
    *p
    =
      (
        (Hacl_Streaming_Functor_state_s__K____uint64_t___uint64_t____){
          .block_state = block_state1,
          .buf = buf,
          .total_len = total_len2
        }
      );
    return;
  }
  if (sz == (uint32_t)0U)
  {
    Hacl_Streaming_Functor_state_s__K____uint64_t___uint64_t____ s2 = *p;
    K____uint64_t___uint64_t_ block_state1 = s2.block_state;
    uint8_t *buf = s2.buf;
    uint64_t total_len1 = s2.total_len;
    uint32_t sz1;
    if (total_len1 % (uint64_t)(uint32_t)128U == (uint64_t)0U && total_len1 > (uint64_t)0U)
    {
      sz1 = (uint32_t)128U;
    }
    else
    {
      sz1 = (uint32_t)(total_len1 % (uint64_t)(uint32_t)128U);
    }
    if (!(sz1 == (uint32_t)0U))
    {
      uint64_t prevlen = total_len1 - (uint64_t)sz1;
      uint32_t nb = (uint32_t)1U;
      for (uint32_t i0 = (uint32_t)0U; i0 < nb; i0++)
      {
        uint64_t ite;
        if ((uint32_t)0U == (uint32_t)0U)
        {
          ite = prevlen;
        }
        else
        {
          ite = prevlen + (uint64_t)(uint32_t)128U;
        }
        FStar_UInt128_uint128
        totlen =
          FStar_UInt128_add_mod(FStar_UInt128_uint64_to_uint128(ite),
            FStar_UInt128_uint64_to_uint128((uint64_t)((i0 + (uint32_t)1U) * (uint32_t)128U)));
        uint8_t *b = buf + i0 * (uint32_t)128U;
        uint64_t m_w[16U] = { 0U };
        for (uint32_t i = (uint32_t)0U; i < (uint32_t)16U; i++)
        {
          uint64_t *os = m_w;
          uint8_t *bj = b + i * (uint32_t)8U;
          uint64_t u = load64_le(bj);
          uint64_t r = u;
          uint64_t x = r;
          os[i] = x;
        }
        uint64_t mask[4U] = { 0U };
        uint64_t wv_14 = (uint64_t)0U;
        uint64_t wv_15 = (uint64_t)0U;
        mask[0U] = FStar_UInt128_uint128_to_uint64(totlen);
        mask[1U] = FStar_UInt128_uint128_to_uint64(FStar_UInt128_shift_right(totlen, (uint32_t)64U));
        mask[2U] = wv_14;
        mask[3U] = wv_15;
        memcpy(block_state1.fst,
          block_state1.snd,
          (uint32_t)4U * (uint32_t)4U * sizeof (block_state1.snd[0U]));
        uint64_t *wv3 = block_state1.fst + (uint32_t)3U * (uint32_t)4U;
        for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
        {
          uint64_t *os = wv3;
          uint64_t x = wv3[i] ^ mask[i];
          os[i] = x;
        }
        for (uint32_t i1 = (uint32_t)0U; i1 < (uint32_t)12U; i1++)
        {
          uint32_t start_idx = i1 % (uint32_t)10U * (uint32_t)16U;
          KRML_CHECK_SIZE(sizeof (uint64_t), (uint32_t)4U * (uint32_t)4U);
          uint64_t m_st[(uint32_t)4U * (uint32_t)4U];
          memset(m_st, 0U, (uint32_t)4U * (uint32_t)4U * sizeof (m_st[0U]));
          uint64_t *r00 = m_st + (uint32_t)0U * (uint32_t)4U;
          uint64_t *r10 = m_st + (uint32_t)1U * (uint32_t)4U;
          uint64_t *r20 = m_st + (uint32_t)2U * (uint32_t)4U;
          uint64_t *r30 = m_st + (uint32_t)3U * (uint32_t)4U;
          uint32_t s0 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx];
          uint32_t s11 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)1U];
          uint32_t s21 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)2U];
          uint32_t s3 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)3U];
          uint32_t s4 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)4U];
          uint32_t s5 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)5U];
          uint32_t s6 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)6U];
          uint32_t s7 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)7U];
          uint32_t s8 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)8U];
          uint32_t s9 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)9U];
          uint32_t s10 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)10U];
          uint32_t s111 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)11U];
          uint32_t s12 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)12U];
          uint32_t s13 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)13U];
          uint32_t s14 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)14U];
          uint32_t s15 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)15U];
          uint64_t uu____0 = m_w[s21];
          uint64_t uu____1 = m_w[s4];
          uint64_t uu____2 = m_w[s6];
          r00[0U] = m_w[s0];
          r00[1U] = uu____0;
          r00[2U] = uu____1;
          r00[3U] = uu____2;
          uint64_t uu____3 = m_w[s3];
          uint64_t uu____4 = m_w[s5];
          uint64_t uu____5 = m_w[s7];
          r10[0U] = m_w[s11];
          r10[1U] = uu____3;
          r10[2U] = uu____4;
          r10[3U] = uu____5;
          uint64_t uu____6 = m_w[s10];
          uint64_t uu____7 = m_w[s12];
          uint64_t uu____8 = m_w[s14];
          r20[0U] = m_w[s8];
          r20[1U] = uu____6;
          r20[2U] = uu____7;
          r20[3U] = uu____8;
          uint64_t uu____9 = m_w[s111];
          uint64_t uu____10 = m_w[s13];
          uint64_t uu____11 = m_w[s15];
          r30[0U] = m_w[s9];
          r30[1U] = uu____9;
          r30[2U] = uu____10;
          r30[3U] = uu____11;
          uint64_t *x = m_st + (uint32_t)0U * (uint32_t)4U;
          uint64_t *y = m_st + (uint32_t)1U * (uint32_t)4U;
          uint64_t *z = m_st + (uint32_t)2U * (uint32_t)4U;
          uint64_t *w = m_st + (uint32_t)3U * (uint32_t)4U;
          uint32_t a = (uint32_t)0U;
          uint32_t b10 = (uint32_t)1U;
          uint32_t c0 = (uint32_t)2U;
          uint32_t d0 = (uint32_t)3U;
          uint32_t r01 = Hacl_Impl_Blake2_Constants_rTable_B[0U];
          uint32_t r12 = Hacl_Impl_Blake2_Constants_rTable_B[1U];
          uint32_t r21 = Hacl_Impl_Blake2_Constants_rTable_B[2U];
          uint32_t r31 = Hacl_Impl_Blake2_Constants_rTable_B[3U];
          uint64_t *wv_a0 = block_state1.fst + a * (uint32_t)4U;
          uint64_t *wv_b0 = block_state1.fst + b10 * (uint32_t)4U;
          for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
          {
            uint64_t *os = wv_a0;
            uint64_t x1 = wv_a0[i] + wv_b0[i];
            os[i] = x1;
          }
          for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
          {
            uint64_t *os = wv_a0;
            uint64_t x1 = wv_a0[i] + x[i];
            os[i] = x1;
          }
          uint64_t *wv_a1 = block_state1.fst + d0 * (uint32_t)4U;
          uint64_t *wv_b1 = block_state1.fst + a * (uint32_t)4U;
          for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
          {
            uint64_t *os = wv_a1;
            uint64_t x1 = wv_a1[i] ^ wv_b1[i];
            os[i] = x1;
          }
          uint64_t *r110 = wv_a1;
          for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
          {
            uint64_t *os = r110;
            uint64_t x1 = r110[i];
            uint64_t x10 = x1 >> r01 | x1 << ((uint32_t)64U - r01);
            os[i] = x10;
          }
          uint64_t *wv_a2 = block_state1.fst + c0 * (uint32_t)4U;
          uint64_t *wv_b2 = block_state1.fst + d0 * (uint32_t)4U;
          for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
          {
            uint64_t *os = wv_a2;
            uint64_t x1 = wv_a2[i] + wv_b2[i];
            os[i] = x1;
          }
          uint64_t *wv_a3 = block_state1.fst + b10 * (uint32_t)4U;
          uint64_t *wv_b3 = block_state1.fst + c0 * (uint32_t)4U;
          for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
          {
            uint64_t *os = wv_a3;
            uint64_t x1 = wv_a3[i] ^ wv_b3[i];
            os[i] = x1;
          }
          uint64_t *r111 = wv_a3;
          for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
          {
            uint64_t *os = r111;
            uint64_t x1 = r111[i];
            uint64_t x10 = x1 >> r12 | x1 << ((uint32_t)64U - r12);
            os[i] = x10;
          }
          uint64_t *wv_a4 = block_state1.fst + a * (uint32_t)4U;
          uint64_t *wv_b4 = block_state1.fst + b10 * (uint32_t)4U;
          for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
          {
            uint64_t *os = wv_a4;
            uint64_t x1 = wv_a4[i] + wv_b4[i];
            os[i] = x1;
          }
          for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
          {
            uint64_t *os = wv_a4;
            uint64_t x1 = wv_a4[i] + y[i];
            os[i] = x1;
          }
          uint64_t *wv_a5 = block_state1.fst + d0 * (uint32_t)4U;
          uint64_t *wv_b5 = block_state1.fst + a * (uint32_t)4U;
          for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
          {
            uint64_t *os = wv_a5;
            uint64_t x1 = wv_a5[i] ^ wv_b5[i];
            os[i] = x1;
          }
          uint64_t *r112 = wv_a5;
          for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
          {
            uint64_t *os = r112;
            uint64_t x1 = r112[i];
            uint64_t x10 = x1 >> r21 | x1 << ((uint32_t)64U - r21);
            os[i] = x10;
          }
          uint64_t *wv_a6 = block_state1.fst + c0 * (uint32_t)4U;
          uint64_t *wv_b6 = block_state1.fst + d0 * (uint32_t)4U;
          for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
          {
            uint64_t *os = wv_a6;
            uint64_t x1 = wv_a6[i] + wv_b6[i];
            os[i] = x1;
          }
          uint64_t *wv_a7 = block_state1.fst + b10 * (uint32_t)4U;
          uint64_t *wv_b7 = block_state1.fst + c0 * (uint32_t)4U;
          for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
          {
            uint64_t *os = wv_a7;
            uint64_t x1 = wv_a7[i] ^ wv_b7[i];
            os[i] = x1;
          }
          uint64_t *r113 = wv_a7;
          for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
          {
            uint64_t *os = r113;
            uint64_t x1 = r113[i];
            uint64_t x10 = x1 >> r31 | x1 << ((uint32_t)64U - r31);
            os[i] = x10;
          }
          uint64_t *r13 = block_state1.fst + (uint32_t)1U * (uint32_t)4U;
          uint64_t *r22 = block_state1.fst + (uint32_t)2U * (uint32_t)4U;
          uint64_t *r32 = block_state1.fst + (uint32_t)3U * (uint32_t)4U;
          uint64_t *r114 = r13;
          uint64_t x00 = r114[1U];
          uint64_t x10 = r114[((uint32_t)1U + (uint32_t)1U) % (uint32_t)4U];
          uint64_t x20 = r114[((uint32_t)1U + (uint32_t)2U) % (uint32_t)4U];
          uint64_t x30 = r114[((uint32_t)1U + (uint32_t)3U) % (uint32_t)4U];
          r114[0U] = x00;
          r114[1U] = x10;
          r114[2U] = x20;
          r114[3U] = x30;
          uint64_t *r115 = r22;
          uint64_t x01 = r115[2U];
          uint64_t x11 = r115[((uint32_t)2U + (uint32_t)1U) % (uint32_t)4U];
          uint64_t x21 = r115[((uint32_t)2U + (uint32_t)2U) % (uint32_t)4U];
          uint64_t x31 = r115[((uint32_t)2U + (uint32_t)3U) % (uint32_t)4U];
          r115[0U] = x01;
          r115[1U] = x11;
          r115[2U] = x21;
          r115[3U] = x31;
          uint64_t *r116 = r32;
          uint64_t x02 = r116[3U];
          uint64_t x12 = r116[((uint32_t)3U + (uint32_t)1U) % (uint32_t)4U];
          uint64_t x22 = r116[((uint32_t)3U + (uint32_t)2U) % (uint32_t)4U];
          uint64_t x32 = r116[((uint32_t)3U + (uint32_t)3U) % (uint32_t)4U];
          r116[0U] = x02;
          r116[1U] = x12;
          r116[2U] = x22;
          r116[3U] = x32;
          uint32_t a0 = (uint32_t)0U;
          uint32_t b1 = (uint32_t)1U;
          uint32_t c = (uint32_t)2U;
          uint32_t d = (uint32_t)3U;
          uint32_t r0 = Hacl_Impl_Blake2_Constants_rTable_B[0U];
          uint32_t r1 = Hacl_Impl_Blake2_Constants_rTable_B[1U];
          uint32_t r23 = Hacl_Impl_Blake2_Constants_rTable_B[2U];
          uint32_t r33 = Hacl_Impl_Blake2_Constants_rTable_B[3U];
          uint64_t *wv_a = block_state1.fst + a0 * (uint32_t)4U;
          uint64_t *wv_b8 = block_state1.fst + b1 * (uint32_t)4U;
          for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
          {
            uint64_t *os = wv_a;
            uint64_t x1 = wv_a[i] + wv_b8[i];
            os[i] = x1;
          }
          for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
          {
            uint64_t *os = wv_a;
            uint64_t x1 = wv_a[i] + z[i];
            os[i] = x1;
          }
          uint64_t *wv_a8 = block_state1.fst + d * (uint32_t)4U;
          uint64_t *wv_b9 = block_state1.fst + a0 * (uint32_t)4U;
          for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
          {
            uint64_t *os = wv_a8;
            uint64_t x1 = wv_a8[i] ^ wv_b9[i];
            os[i] = x1;
          }
          uint64_t *r117 = wv_a8;
          for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
          {
            uint64_t *os = r117;
            uint64_t x1 = r117[i];
            uint64_t x13 = x1 >> r0 | x1 << ((uint32_t)64U - r0);
            os[i] = x13;
          }
          uint64_t *wv_a9 = block_state1.fst + c * (uint32_t)4U;
          uint64_t *wv_b10 = block_state1.fst + d * (uint32_t)4U;
          for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
          {
            uint64_t *os = wv_a9;
            uint64_t x1 = wv_a9[i] + wv_b10[i];
            os[i] = x1;
          }
          uint64_t *wv_a10 = block_state1.fst + b1 * (uint32_t)4U;
          uint64_t *wv_b11 = block_state1.fst + c * (uint32_t)4U;
          for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
          {
            uint64_t *os = wv_a10;
            uint64_t x1 = wv_a10[i] ^ wv_b11[i];
            os[i] = x1;
          }
          uint64_t *r118 = wv_a10;
          for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
          {
            uint64_t *os = r118;
            uint64_t x1 = r118[i];
            uint64_t x13 = x1 >> r1 | x1 << ((uint32_t)64U - r1);
            os[i] = x13;
          }
          uint64_t *wv_a11 = block_state1.fst + a0 * (uint32_t)4U;
          uint64_t *wv_b12 = block_state1.fst + b1 * (uint32_t)4U;
          for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
          {
            uint64_t *os = wv_a11;
            uint64_t x1 = wv_a11[i] + wv_b12[i];
            os[i] = x1;
          }
          for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
          {
            uint64_t *os = wv_a11;
            uint64_t x1 = wv_a11[i] + w[i];
            os[i] = x1;
          }
          uint64_t *wv_a12 = block_state1.fst + d * (uint32_t)4U;
          uint64_t *wv_b13 = block_state1.fst + a0 * (uint32_t)4U;
          for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
          {
            uint64_t *os = wv_a12;
            uint64_t x1 = wv_a12[i] ^ wv_b13[i];
            os[i] = x1;
          }
          uint64_t *r119 = wv_a12;
          for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
          {
            uint64_t *os = r119;
            uint64_t x1 = r119[i];
            uint64_t x13 = x1 >> r23 | x1 << ((uint32_t)64U - r23);
            os[i] = x13;
          }
          uint64_t *wv_a13 = block_state1.fst + c * (uint32_t)4U;
          uint64_t *wv_b14 = block_state1.fst + d * (uint32_t)4U;
          for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
          {
            uint64_t *os = wv_a13;
            uint64_t x1 = wv_a13[i] + wv_b14[i];
            os[i] = x1;
          }
          uint64_t *wv_a14 = block_state1.fst + b1 * (uint32_t)4U;
          uint64_t *wv_b = block_state1.fst + c * (uint32_t)4U;
          for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
          {
            uint64_t *os = wv_a14;
            uint64_t x1 = wv_a14[i] ^ wv_b[i];
            os[i] = x1;
          }
          uint64_t *r1110 = wv_a14;
          for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
          {
            uint64_t *os = r1110;
            uint64_t x1 = r1110[i];
            uint64_t x13 = x1 >> r33 | x1 << ((uint32_t)64U - r33);
            os[i] = x13;
          }
          uint64_t *r14 = block_state1.fst + (uint32_t)1U * (uint32_t)4U;
          uint64_t *r2 = block_state1.fst + (uint32_t)2U * (uint32_t)4U;
          uint64_t *r3 = block_state1.fst + (uint32_t)3U * (uint32_t)4U;
          uint64_t *r11 = r14;
          uint64_t x03 = r11[3U];
          uint64_t x13 = r11[((uint32_t)3U + (uint32_t)1U) % (uint32_t)4U];
          uint64_t x23 = r11[((uint32_t)3U + (uint32_t)2U) % (uint32_t)4U];
          uint64_t x33 = r11[((uint32_t)3U + (uint32_t)3U) % (uint32_t)4U];
          r11[0U] = x03;
          r11[1U] = x13;
          r11[2U] = x23;
          r11[3U] = x33;
          uint64_t *r1111 = r2;
          uint64_t x04 = r1111[2U];
          uint64_t x14 = r1111[((uint32_t)2U + (uint32_t)1U) % (uint32_t)4U];
          uint64_t x24 = r1111[((uint32_t)2U + (uint32_t)2U) % (uint32_t)4U];
          uint64_t x34 = r1111[((uint32_t)2U + (uint32_t)3U) % (uint32_t)4U];
          r1111[0U] = x04;
          r1111[1U] = x14;
          r1111[2U] = x24;
          r1111[3U] = x34;
          uint64_t *r1112 = r3;
          uint64_t x0 = r1112[1U];
          uint64_t x1 = r1112[((uint32_t)1U + (uint32_t)1U) % (uint32_t)4U];
          uint64_t x2 = r1112[((uint32_t)1U + (uint32_t)2U) % (uint32_t)4U];
          uint64_t x3 = r1112[((uint32_t)1U + (uint32_t)3U) % (uint32_t)4U];
          r1112[0U] = x0;
          r1112[1U] = x1;
          r1112[2U] = x2;
          r1112[3U] = x3;
        }
        uint64_t *s0 = block_state1.snd + (uint32_t)0U * (uint32_t)4U;
        uint64_t *s11 = block_state1.snd + (uint32_t)1U * (uint32_t)4U;
        uint64_t *r0 = block_state1.fst + (uint32_t)0U * (uint32_t)4U;
        uint64_t *r1 = block_state1.fst + (uint32_t)1U * (uint32_t)4U;
        uint64_t *r2 = block_state1.fst + (uint32_t)2U * (uint32_t)4U;
        uint64_t *r3 = block_state1.fst + (uint32_t)3U * (uint32_t)4U;
        for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
        {
          uint64_t *os = s0;
          uint64_t x = s0[i] ^ r0[i];
          os[i] = x;
        }
        for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
        {
          uint64_t *os = s0;
          uint64_t x = s0[i] ^ r2[i];
          os[i] = x;
        }
        for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
        {
          uint64_t *os = s11;
          uint64_t x = s11[i] ^ r1[i];
          os[i] = x;
        }
        for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
        {
          uint64_t *os = s11;
          uint64_t x = s11[i] ^ r3[i];
          os[i] = x;
        }
      }
    }
    uint32_t ite0;
    if ((uint64_t)len % (uint64_t)(uint32_t)128U == (uint64_t)0U && (uint64_t)len > (uint64_t)0U)
    {
      ite0 = (uint32_t)128U;
    }
    else
    {
      ite0 = (uint32_t)((uint64_t)len % (uint64_t)(uint32_t)128U);
    }
    uint32_t n_blocks = (len - ite0) / (uint32_t)128U;
    uint32_t data1_len = n_blocks * (uint32_t)128U;
    uint32_t data2_len = len - data1_len;
    uint8_t *data1 = data;
    uint8_t *data2 = data + data1_len;
    uint32_t nb = data1_len / (uint32_t)128U;
    for (uint32_t i0 = (uint32_t)0U; i0 < nb; i0++)
    {
      uint64_t ite;
      if ((uint32_t)0U == (uint32_t)0U)
      {
        ite = total_len1;
      }
      else
      {
        ite = total_len1 + (uint64_t)(uint32_t)128U;
      }
      FStar_UInt128_uint128
      totlen =
        FStar_UInt128_add_mod(FStar_UInt128_uint64_to_uint128(ite),
          FStar_UInt128_uint64_to_uint128((uint64_t)((i0 + (uint32_t)1U) * (uint32_t)128U)));
      uint8_t *b = data1 + i0 * (uint32_t)128U;
      uint64_t m_w[16U] = { 0U };
      for (uint32_t i = (uint32_t)0U; i < (uint32_t)16U; i++)
      {
        uint64_t *os = m_w;
        uint8_t *bj = b + i * (uint32_t)8U;
        uint64_t u = load64_le(bj);
        uint64_t r = u;
        uint64_t x = r;
        os[i] = x;
      }
      uint64_t mask[4U] = { 0U };
      uint64_t wv_14 = (uint64_t)0U;
      uint64_t wv_15 = (uint64_t)0U;
      mask[0U] = FStar_UInt128_uint128_to_uint64(totlen);
      mask[1U] = FStar_UInt128_uint128_to_uint64(FStar_UInt128_shift_right(totlen, (uint32_t)64U));
      mask[2U] = wv_14;
      mask[3U] = wv_15;
      memcpy(block_state1.fst,
        block_state1.snd,
        (uint32_t)4U * (uint32_t)4U * sizeof (block_state1.snd[0U]));
      uint64_t *wv3 = block_state1.fst + (uint32_t)3U * (uint32_t)4U;
      for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
      {
        uint64_t *os = wv3;
        uint64_t x = wv3[i] ^ mask[i];
        os[i] = x;
      }
      for (uint32_t i1 = (uint32_t)0U; i1 < (uint32_t)12U; i1++)
      {
        uint32_t start_idx = i1 % (uint32_t)10U * (uint32_t)16U;
        KRML_CHECK_SIZE(sizeof (uint64_t), (uint32_t)4U * (uint32_t)4U);
        uint64_t m_st[(uint32_t)4U * (uint32_t)4U];
        memset(m_st, 0U, (uint32_t)4U * (uint32_t)4U * sizeof (m_st[0U]));
        uint64_t *r00 = m_st + (uint32_t)0U * (uint32_t)4U;
        uint64_t *r10 = m_st + (uint32_t)1U * (uint32_t)4U;
        uint64_t *r20 = m_st + (uint32_t)2U * (uint32_t)4U;
        uint64_t *r30 = m_st + (uint32_t)3U * (uint32_t)4U;
        uint32_t s0 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx];
        uint32_t s11 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)1U];
        uint32_t s21 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)2U];
        uint32_t s3 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)3U];
        uint32_t s4 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)4U];
        uint32_t s5 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)5U];
        uint32_t s6 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)6U];
        uint32_t s7 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)7U];
        uint32_t s8 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)8U];
        uint32_t s9 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)9U];
        uint32_t s10 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)10U];
        uint32_t s111 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)11U];
        uint32_t s12 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)12U];
        uint32_t s13 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)13U];
        uint32_t s14 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)14U];
        uint32_t s15 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)15U];
        uint64_t uu____12 = m_w[s21];
        uint64_t uu____13 = m_w[s4];
        uint64_t uu____14 = m_w[s6];
        r00[0U] = m_w[s0];
        r00[1U] = uu____12;
        r00[2U] = uu____13;
        r00[3U] = uu____14;
        uint64_t uu____15 = m_w[s3];
        uint64_t uu____16 = m_w[s5];
        uint64_t uu____17 = m_w[s7];
        r10[0U] = m_w[s11];
        r10[1U] = uu____15;
        r10[2U] = uu____16;
        r10[3U] = uu____17;
        uint64_t uu____18 = m_w[s10];
        uint64_t uu____19 = m_w[s12];
        uint64_t uu____20 = m_w[s14];
        r20[0U] = m_w[s8];
        r20[1U] = uu____18;
        r20[2U] = uu____19;
        r20[3U] = uu____20;
        uint64_t uu____21 = m_w[s111];
        uint64_t uu____22 = m_w[s13];
        uint64_t uu____23 = m_w[s15];
        r30[0U] = m_w[s9];
        r30[1U] = uu____21;
        r30[2U] = uu____22;
        r30[3U] = uu____23;
        uint64_t *x = m_st + (uint32_t)0U * (uint32_t)4U;
        uint64_t *y = m_st + (uint32_t)1U * (uint32_t)4U;
        uint64_t *z = m_st + (uint32_t)2U * (uint32_t)4U;
        uint64_t *w = m_st + (uint32_t)3U * (uint32_t)4U;
        uint32_t a = (uint32_t)0U;
        uint32_t b10 = (uint32_t)1U;
        uint32_t c0 = (uint32_t)2U;
        uint32_t d0 = (uint32_t)3U;
        uint32_t r01 = Hacl_Impl_Blake2_Constants_rTable_B[0U];
        uint32_t r12 = Hacl_Impl_Blake2_Constants_rTable_B[1U];
        uint32_t r21 = Hacl_Impl_Blake2_Constants_rTable_B[2U];
        uint32_t r31 = Hacl_Impl_Blake2_Constants_rTable_B[3U];
        uint64_t *wv_a0 = block_state1.fst + a * (uint32_t)4U;
        uint64_t *wv_b0 = block_state1.fst + b10 * (uint32_t)4U;
        for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
        {
          uint64_t *os = wv_a0;
          uint64_t x1 = wv_a0[i] + wv_b0[i];
          os[i] = x1;
        }
        for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
        {
          uint64_t *os = wv_a0;
          uint64_t x1 = wv_a0[i] + x[i];
          os[i] = x1;
        }
        uint64_t *wv_a1 = block_state1.fst + d0 * (uint32_t)4U;
        uint64_t *wv_b1 = block_state1.fst + a * (uint32_t)4U;
        for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
        {
          uint64_t *os = wv_a1;
          uint64_t x1 = wv_a1[i] ^ wv_b1[i];
          os[i] = x1;
        }
        uint64_t *r110 = wv_a1;
        for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
        {
          uint64_t *os = r110;
          uint64_t x1 = r110[i];
          uint64_t x10 = x1 >> r01 | x1 << ((uint32_t)64U - r01);
          os[i] = x10;
        }
        uint64_t *wv_a2 = block_state1.fst + c0 * (uint32_t)4U;
        uint64_t *wv_b2 = block_state1.fst + d0 * (uint32_t)4U;
        for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
        {
          uint64_t *os = wv_a2;
          uint64_t x1 = wv_a2[i] + wv_b2[i];
          os[i] = x1;
        }
        uint64_t *wv_a3 = block_state1.fst + b10 * (uint32_t)4U;
        uint64_t *wv_b3 = block_state1.fst + c0 * (uint32_t)4U;
        for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
        {
          uint64_t *os = wv_a3;
          uint64_t x1 = wv_a3[i] ^ wv_b3[i];
          os[i] = x1;
        }
        uint64_t *r111 = wv_a3;
        for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
        {
          uint64_t *os = r111;
          uint64_t x1 = r111[i];
          uint64_t x10 = x1 >> r12 | x1 << ((uint32_t)64U - r12);
          os[i] = x10;
        }
        uint64_t *wv_a4 = block_state1.fst + a * (uint32_t)4U;
        uint64_t *wv_b4 = block_state1.fst + b10 * (uint32_t)4U;
        for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
        {
          uint64_t *os = wv_a4;
          uint64_t x1 = wv_a4[i] + wv_b4[i];
          os[i] = x1;
        }
        for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
        {
          uint64_t *os = wv_a4;
          uint64_t x1 = wv_a4[i] + y[i];
          os[i] = x1;
        }
        uint64_t *wv_a5 = block_state1.fst + d0 * (uint32_t)4U;
        uint64_t *wv_b5 = block_state1.fst + a * (uint32_t)4U;
        for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
        {
          uint64_t *os = wv_a5;
          uint64_t x1 = wv_a5[i] ^ wv_b5[i];
          os[i] = x1;
        }
        uint64_t *r112 = wv_a5;
        for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
        {
          uint64_t *os = r112;
          uint64_t x1 = r112[i];
          uint64_t x10 = x1 >> r21 | x1 << ((uint32_t)64U - r21);
          os[i] = x10;
        }
        uint64_t *wv_a6 = block_state1.fst + c0 * (uint32_t)4U;
        uint64_t *wv_b6 = block_state1.fst + d0 * (uint32_t)4U;
        for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
        {
          uint64_t *os = wv_a6;
          uint64_t x1 = wv_a6[i] + wv_b6[i];
          os[i] = x1;
        }
        uint64_t *wv_a7 = block_state1.fst + b10 * (uint32_t)4U;
        uint64_t *wv_b7 = block_state1.fst + c0 * (uint32_t)4U;
        for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
        {
          uint64_t *os = wv_a7;
          uint64_t x1 = wv_a7[i] ^ wv_b7[i];
          os[i] = x1;
        }
        uint64_t *r113 = wv_a7;
        for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
        {
          uint64_t *os = r113;
          uint64_t x1 = r113[i];
          uint64_t x10 = x1 >> r31 | x1 << ((uint32_t)64U - r31);
          os[i] = x10;
        }
        uint64_t *r13 = block_state1.fst + (uint32_t)1U * (uint32_t)4U;
        uint64_t *r22 = block_state1.fst + (uint32_t)2U * (uint32_t)4U;
        uint64_t *r32 = block_state1.fst + (uint32_t)3U * (uint32_t)4U;
        uint64_t *r114 = r13;
        uint64_t x00 = r114[1U];
        uint64_t x10 = r114[((uint32_t)1U + (uint32_t)1U) % (uint32_t)4U];
        uint64_t x20 = r114[((uint32_t)1U + (uint32_t)2U) % (uint32_t)4U];
        uint64_t x30 = r114[((uint32_t)1U + (uint32_t)3U) % (uint32_t)4U];
        r114[0U] = x00;
        r114[1U] = x10;
        r114[2U] = x20;
        r114[3U] = x30;
        uint64_t *r115 = r22;
        uint64_t x01 = r115[2U];
        uint64_t x11 = r115[((uint32_t)2U + (uint32_t)1U) % (uint32_t)4U];
        uint64_t x21 = r115[((uint32_t)2U + (uint32_t)2U) % (uint32_t)4U];
        uint64_t x31 = r115[((uint32_t)2U + (uint32_t)3U) % (uint32_t)4U];
        r115[0U] = x01;
        r115[1U] = x11;
        r115[2U] = x21;
        r115[3U] = x31;
        uint64_t *r116 = r32;
        uint64_t x02 = r116[3U];
        uint64_t x12 = r116[((uint32_t)3U + (uint32_t)1U) % (uint32_t)4U];
        uint64_t x22 = r116[((uint32_t)3U + (uint32_t)2U) % (uint32_t)4U];
        uint64_t x32 = r116[((uint32_t)3U + (uint32_t)3U) % (uint32_t)4U];
        r116[0U] = x02;
        r116[1U] = x12;
        r116[2U] = x22;
        r116[3U] = x32;
        uint32_t a0 = (uint32_t)0U;
        uint32_t b1 = (uint32_t)1U;
        uint32_t c = (uint32_t)2U;
        uint32_t d = (uint32_t)3U;
        uint32_t r0 = Hacl_Impl_Blake2_Constants_rTable_B[0U];
        uint32_t r1 = Hacl_Impl_Blake2_Constants_rTable_B[1U];
        uint32_t r23 = Hacl_Impl_Blake2_Constants_rTable_B[2U];
        uint32_t r33 = Hacl_Impl_Blake2_Constants_rTable_B[3U];
        uint64_t *wv_a = block_state1.fst + a0 * (uint32_t)4U;
        uint64_t *wv_b8 = block_state1.fst + b1 * (uint32_t)4U;
        for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
        {
          uint64_t *os = wv_a;
          uint64_t x1 = wv_a[i] + wv_b8[i];
          os[i] = x1;
        }
        for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
        {
          uint64_t *os = wv_a;
          uint64_t x1 = wv_a[i] + z[i];
          os[i] = x1;
        }
        uint64_t *wv_a8 = block_state1.fst + d * (uint32_t)4U;
        uint64_t *wv_b9 = block_state1.fst + a0 * (uint32_t)4U;
        for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
        {
          uint64_t *os = wv_a8;
          uint64_t x1 = wv_a8[i] ^ wv_b9[i];
          os[i] = x1;
        }
        uint64_t *r117 = wv_a8;
        for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
        {
          uint64_t *os = r117;
          uint64_t x1 = r117[i];
          uint64_t x13 = x1 >> r0 | x1 << ((uint32_t)64U - r0);
          os[i] = x13;
        }
        uint64_t *wv_a9 = block_state1.fst + c * (uint32_t)4U;
        uint64_t *wv_b10 = block_state1.fst + d * (uint32_t)4U;
        for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
        {
          uint64_t *os = wv_a9;
          uint64_t x1 = wv_a9[i] + wv_b10[i];
          os[i] = x1;
        }
        uint64_t *wv_a10 = block_state1.fst + b1 * (uint32_t)4U;
        uint64_t *wv_b11 = block_state1.fst + c * (uint32_t)4U;
        for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
        {
          uint64_t *os = wv_a10;
          uint64_t x1 = wv_a10[i] ^ wv_b11[i];
          os[i] = x1;
        }
        uint64_t *r118 = wv_a10;
        for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
        {
          uint64_t *os = r118;
          uint64_t x1 = r118[i];
          uint64_t x13 = x1 >> r1 | x1 << ((uint32_t)64U - r1);
          os[i] = x13;
        }
        uint64_t *wv_a11 = block_state1.fst + a0 * (uint32_t)4U;
        uint64_t *wv_b12 = block_state1.fst + b1 * (uint32_t)4U;
        for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
        {
          uint64_t *os = wv_a11;
          uint64_t x1 = wv_a11[i] + wv_b12[i];
          os[i] = x1;
        }
        for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
        {
          uint64_t *os = wv_a11;
          uint64_t x1 = wv_a11[i] + w[i];
          os[i] = x1;
        }
        uint64_t *wv_a12 = block_state1.fst + d * (uint32_t)4U;
        uint64_t *wv_b13 = block_state1.fst + a0 * (uint32_t)4U;
        for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
        {
          uint64_t *os = wv_a12;
          uint64_t x1 = wv_a12[i] ^ wv_b13[i];
          os[i] = x1;
        }
        uint64_t *r119 = wv_a12;
        for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
        {
          uint64_t *os = r119;
          uint64_t x1 = r119[i];
          uint64_t x13 = x1 >> r23 | x1 << ((uint32_t)64U - r23);
          os[i] = x13;
        }
        uint64_t *wv_a13 = block_state1.fst + c * (uint32_t)4U;
        uint64_t *wv_b14 = block_state1.fst + d * (uint32_t)4U;
        for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
        {
          uint64_t *os = wv_a13;
          uint64_t x1 = wv_a13[i] + wv_b14[i];
          os[i] = x1;
        }
        uint64_t *wv_a14 = block_state1.fst + b1 * (uint32_t)4U;
        uint64_t *wv_b = block_state1.fst + c * (uint32_t)4U;
        for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
        {
          uint64_t *os = wv_a14;
          uint64_t x1 = wv_a14[i] ^ wv_b[i];
          os[i] = x1;
        }
        uint64_t *r1110 = wv_a14;
        for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
        {
          uint64_t *os = r1110;
          uint64_t x1 = r1110[i];
          uint64_t x13 = x1 >> r33 | x1 << ((uint32_t)64U - r33);
          os[i] = x13;
        }
        uint64_t *r14 = block_state1.fst + (uint32_t)1U * (uint32_t)4U;
        uint64_t *r2 = block_state1.fst + (uint32_t)2U * (uint32_t)4U;
        uint64_t *r3 = block_state1.fst + (uint32_t)3U * (uint32_t)4U;
        uint64_t *r11 = r14;
        uint64_t x03 = r11[3U];
        uint64_t x13 = r11[((uint32_t)3U + (uint32_t)1U) % (uint32_t)4U];
        uint64_t x23 = r11[((uint32_t)3U + (uint32_t)2U) % (uint32_t)4U];
        uint64_t x33 = r11[((uint32_t)3U + (uint32_t)3U) % (uint32_t)4U];
        r11[0U] = x03;
        r11[1U] = x13;
        r11[2U] = x23;
        r11[3U] = x33;
        uint64_t *r1111 = r2;
        uint64_t x04 = r1111[2U];
        uint64_t x14 = r1111[((uint32_t)2U + (uint32_t)1U) % (uint32_t)4U];
        uint64_t x24 = r1111[((uint32_t)2U + (uint32_t)2U) % (uint32_t)4U];
        uint64_t x34 = r1111[((uint32_t)2U + (uint32_t)3U) % (uint32_t)4U];
        r1111[0U] = x04;
        r1111[1U] = x14;
        r1111[2U] = x24;
        r1111[3U] = x34;
        uint64_t *r1112 = r3;
        uint64_t x0 = r1112[1U];
        uint64_t x1 = r1112[((uint32_t)1U + (uint32_t)1U) % (uint32_t)4U];
        uint64_t x2 = r1112[((uint32_t)1U + (uint32_t)2U) % (uint32_t)4U];
        uint64_t x3 = r1112[((uint32_t)1U + (uint32_t)3U) % (uint32_t)4U];
        r1112[0U] = x0;
        r1112[1U] = x1;
        r1112[2U] = x2;
        r1112[3U] = x3;
      }
      uint64_t *s0 = block_state1.snd + (uint32_t)0U * (uint32_t)4U;
      uint64_t *s11 = block_state1.snd + (uint32_t)1U * (uint32_t)4U;
      uint64_t *r0 = block_state1.fst + (uint32_t)0U * (uint32_t)4U;
      uint64_t *r1 = block_state1.fst + (uint32_t)1U * (uint32_t)4U;
      uint64_t *r2 = block_state1.fst + (uint32_t)2U * (uint32_t)4U;
      uint64_t *r3 = block_state1.fst + (uint32_t)3U * (uint32_t)4U;
      for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
      {
        uint64_t *os = s0;
        uint64_t x = s0[i] ^ r0[i];
        os[i] = x;
      }
      for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
      {
        uint64_t *os = s0;
        uint64_t x = s0[i] ^ r2[i];
        os[i] = x;
      }
      for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
      {
        uint64_t *os = s11;
        uint64_t x = s11[i] ^ r1[i];
        os[i] = x;
      }
      for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
      {
        uint64_t *os = s11;
        uint64_t x = s11[i] ^ r3[i];
        os[i] = x;
      }
    }
    uint8_t *dst = buf;
    memcpy(dst, data2, data2_len * sizeof (data2[0U]));
    *p
    =
      (
        (Hacl_Streaming_Functor_state_s__K____uint64_t___uint64_t____){
          .block_state = block_state1,
          .buf = buf,
          .total_len = total_len1 + (uint64_t)len
        }
      );
    return;
  }
  uint32_t diff = (uint32_t)128U - sz;
  uint8_t *data1 = data;
  uint8_t *data2 = data + diff;
  Hacl_Streaming_Functor_state_s__K____uint64_t___uint64_t____ s2 = *p;
  K____uint64_t___uint64_t_ block_state10 = s2.block_state;
  uint8_t *buf0 = s2.buf;
  uint64_t total_len10 = s2.total_len;
  uint32_t sz10;
  if (total_len10 % (uint64_t)(uint32_t)128U == (uint64_t)0U && total_len10 > (uint64_t)0U)
  {
    sz10 = (uint32_t)128U;
  }
  else
  {
    sz10 = (uint32_t)(total_len10 % (uint64_t)(uint32_t)128U);
  }
  uint8_t *buf2 = buf0 + sz10;
  memcpy(buf2, data1, diff * sizeof (data1[0U]));
  uint64_t total_len2 = total_len10 + (uint64_t)diff;
  *p
  =
    (
      (Hacl_Streaming_Functor_state_s__K____uint64_t___uint64_t____){
        .block_state = block_state10,
        .buf = buf0,
        .total_len = total_len2
      }
    );
  Hacl_Streaming_Functor_state_s__K____uint64_t___uint64_t____ s20 = *p;
  K____uint64_t___uint64_t_ block_state1 = s20.block_state;
  uint8_t *buf = s20.buf;
  uint64_t total_len1 = s20.total_len;
  uint32_t sz1;
  if (total_len1 % (uint64_t)(uint32_t)128U == (uint64_t)0U && total_len1 > (uint64_t)0U)
  {
    sz1 = (uint32_t)128U;
  }
  else
  {
    sz1 = (uint32_t)(total_len1 % (uint64_t)(uint32_t)128U);
  }
  if (!(sz1 == (uint32_t)0U))
  {
    uint64_t prevlen = total_len1 - (uint64_t)sz1;
    uint32_t nb = (uint32_t)1U;
    for (uint32_t i0 = (uint32_t)0U; i0 < nb; i0++)
    {
      uint64_t ite;
      if ((uint32_t)0U == (uint32_t)0U)
      {
        ite = prevlen;
      }
      else
      {
        ite = prevlen + (uint64_t)(uint32_t)128U;
      }
      FStar_UInt128_uint128
      totlen =
        FStar_UInt128_add_mod(FStar_UInt128_uint64_to_uint128(ite),
          FStar_UInt128_uint64_to_uint128((uint64_t)((i0 + (uint32_t)1U) * (uint32_t)128U)));
      uint8_t *b = buf + i0 * (uint32_t)128U;
      uint64_t m_w[16U] = { 0U };
      for (uint32_t i = (uint32_t)0U; i < (uint32_t)16U; i++)
      {
        uint64_t *os = m_w;
        uint8_t *bj = b + i * (uint32_t)8U;
        uint64_t u = load64_le(bj);
        uint64_t r = u;
        uint64_t x = r;
        os[i] = x;
      }
      uint64_t mask[4U] = { 0U };
      uint64_t wv_14 = (uint64_t)0U;
      uint64_t wv_15 = (uint64_t)0U;
      mask[0U] = FStar_UInt128_uint128_to_uint64(totlen);
      mask[1U] = FStar_UInt128_uint128_to_uint64(FStar_UInt128_shift_right(totlen, (uint32_t)64U));
      mask[2U] = wv_14;
      mask[3U] = wv_15;
      memcpy(block_state1.fst,
        block_state1.snd,
        (uint32_t)4U * (uint32_t)4U * sizeof (block_state1.snd[0U]));
      uint64_t *wv3 = block_state1.fst + (uint32_t)3U * (uint32_t)4U;
      for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
      {
        uint64_t *os = wv3;
        uint64_t x = wv3[i] ^ mask[i];
        os[i] = x;
      }
      for (uint32_t i1 = (uint32_t)0U; i1 < (uint32_t)12U; i1++)
      {
        uint32_t start_idx = i1 % (uint32_t)10U * (uint32_t)16U;
        KRML_CHECK_SIZE(sizeof (uint64_t), (uint32_t)4U * (uint32_t)4U);
        uint64_t m_st[(uint32_t)4U * (uint32_t)4U];
        memset(m_st, 0U, (uint32_t)4U * (uint32_t)4U * sizeof (m_st[0U]));
        uint64_t *r00 = m_st + (uint32_t)0U * (uint32_t)4U;
        uint64_t *r10 = m_st + (uint32_t)1U * (uint32_t)4U;
        uint64_t *r20 = m_st + (uint32_t)2U * (uint32_t)4U;
        uint64_t *r30 = m_st + (uint32_t)3U * (uint32_t)4U;
        uint32_t s0 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx];
        uint32_t s11 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)1U];
        uint32_t s21 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)2U];
        uint32_t s3 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)3U];
        uint32_t s4 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)4U];
        uint32_t s5 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)5U];
        uint32_t s6 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)6U];
        uint32_t s7 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)7U];
        uint32_t s8 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)8U];
        uint32_t s9 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)9U];
        uint32_t s10 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)10U];
        uint32_t s111 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)11U];
        uint32_t s12 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)12U];
        uint32_t s13 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)13U];
        uint32_t s14 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)14U];
        uint32_t s15 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)15U];
        uint64_t uu____24 = m_w[s21];
        uint64_t uu____25 = m_w[s4];
        uint64_t uu____26 = m_w[s6];
        r00[0U] = m_w[s0];
        r00[1U] = uu____24;
        r00[2U] = uu____25;
        r00[3U] = uu____26;
        uint64_t uu____27 = m_w[s3];
        uint64_t uu____28 = m_w[s5];
        uint64_t uu____29 = m_w[s7];
        r10[0U] = m_w[s11];
        r10[1U] = uu____27;
        r10[2U] = uu____28;
        r10[3U] = uu____29;
        uint64_t uu____30 = m_w[s10];
        uint64_t uu____31 = m_w[s12];
        uint64_t uu____32 = m_w[s14];
        r20[0U] = m_w[s8];
        r20[1U] = uu____30;
        r20[2U] = uu____31;
        r20[3U] = uu____32;
        uint64_t uu____33 = m_w[s111];
        uint64_t uu____34 = m_w[s13];
        uint64_t uu____35 = m_w[s15];
        r30[0U] = m_w[s9];
        r30[1U] = uu____33;
        r30[2U] = uu____34;
        r30[3U] = uu____35;
        uint64_t *x = m_st + (uint32_t)0U * (uint32_t)4U;
        uint64_t *y = m_st + (uint32_t)1U * (uint32_t)4U;
        uint64_t *z = m_st + (uint32_t)2U * (uint32_t)4U;
        uint64_t *w = m_st + (uint32_t)3U * (uint32_t)4U;
        uint32_t a = (uint32_t)0U;
        uint32_t b10 = (uint32_t)1U;
        uint32_t c0 = (uint32_t)2U;
        uint32_t d0 = (uint32_t)3U;
        uint32_t r01 = Hacl_Impl_Blake2_Constants_rTable_B[0U];
        uint32_t r12 = Hacl_Impl_Blake2_Constants_rTable_B[1U];
        uint32_t r21 = Hacl_Impl_Blake2_Constants_rTable_B[2U];
        uint32_t r31 = Hacl_Impl_Blake2_Constants_rTable_B[3U];
        uint64_t *wv_a0 = block_state1.fst + a * (uint32_t)4U;
        uint64_t *wv_b0 = block_state1.fst + b10 * (uint32_t)4U;
        for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
        {
          uint64_t *os = wv_a0;
          uint64_t x1 = wv_a0[i] + wv_b0[i];
          os[i] = x1;
        }
        for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
        {
          uint64_t *os = wv_a0;
          uint64_t x1 = wv_a0[i] + x[i];
          os[i] = x1;
        }
        uint64_t *wv_a1 = block_state1.fst + d0 * (uint32_t)4U;
        uint64_t *wv_b1 = block_state1.fst + a * (uint32_t)4U;
        for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
        {
          uint64_t *os = wv_a1;
          uint64_t x1 = wv_a1[i] ^ wv_b1[i];
          os[i] = x1;
        }
        uint64_t *r110 = wv_a1;
        for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
        {
          uint64_t *os = r110;
          uint64_t x1 = r110[i];
          uint64_t x10 = x1 >> r01 | x1 << ((uint32_t)64U - r01);
          os[i] = x10;
        }
        uint64_t *wv_a2 = block_state1.fst + c0 * (uint32_t)4U;
        uint64_t *wv_b2 = block_state1.fst + d0 * (uint32_t)4U;
        for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
        {
          uint64_t *os = wv_a2;
          uint64_t x1 = wv_a2[i] + wv_b2[i];
          os[i] = x1;
        }
        uint64_t *wv_a3 = block_state1.fst + b10 * (uint32_t)4U;
        uint64_t *wv_b3 = block_state1.fst + c0 * (uint32_t)4U;
        for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
        {
          uint64_t *os = wv_a3;
          uint64_t x1 = wv_a3[i] ^ wv_b3[i];
          os[i] = x1;
        }
        uint64_t *r111 = wv_a3;
        for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
        {
          uint64_t *os = r111;
          uint64_t x1 = r111[i];
          uint64_t x10 = x1 >> r12 | x1 << ((uint32_t)64U - r12);
          os[i] = x10;
        }
        uint64_t *wv_a4 = block_state1.fst + a * (uint32_t)4U;
        uint64_t *wv_b4 = block_state1.fst + b10 * (uint32_t)4U;
        for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
        {
          uint64_t *os = wv_a4;
          uint64_t x1 = wv_a4[i] + wv_b4[i];
          os[i] = x1;
        }
        for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
        {
          uint64_t *os = wv_a4;
          uint64_t x1 = wv_a4[i] + y[i];
          os[i] = x1;
        }
        uint64_t *wv_a5 = block_state1.fst + d0 * (uint32_t)4U;
        uint64_t *wv_b5 = block_state1.fst + a * (uint32_t)4U;
        for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
        {
          uint64_t *os = wv_a5;
          uint64_t x1 = wv_a5[i] ^ wv_b5[i];
          os[i] = x1;
        }
        uint64_t *r112 = wv_a5;
        for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
        {
          uint64_t *os = r112;
          uint64_t x1 = r112[i];
          uint64_t x10 = x1 >> r21 | x1 << ((uint32_t)64U - r21);
          os[i] = x10;
        }
        uint64_t *wv_a6 = block_state1.fst + c0 * (uint32_t)4U;
        uint64_t *wv_b6 = block_state1.fst + d0 * (uint32_t)4U;
        for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
        {
          uint64_t *os = wv_a6;
          uint64_t x1 = wv_a6[i] + wv_b6[i];
          os[i] = x1;
        }
        uint64_t *wv_a7 = block_state1.fst + b10 * (uint32_t)4U;
        uint64_t *wv_b7 = block_state1.fst + c0 * (uint32_t)4U;
        for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
        {
          uint64_t *os = wv_a7;
          uint64_t x1 = wv_a7[i] ^ wv_b7[i];
          os[i] = x1;
        }
        uint64_t *r113 = wv_a7;
        for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
        {
          uint64_t *os = r113;
          uint64_t x1 = r113[i];
          uint64_t x10 = x1 >> r31 | x1 << ((uint32_t)64U - r31);
          os[i] = x10;
        }
        uint64_t *r13 = block_state1.fst + (uint32_t)1U * (uint32_t)4U;
        uint64_t *r22 = block_state1.fst + (uint32_t)2U * (uint32_t)4U;
        uint64_t *r32 = block_state1.fst + (uint32_t)3U * (uint32_t)4U;
        uint64_t *r114 = r13;
        uint64_t x00 = r114[1U];
        uint64_t x10 = r114[((uint32_t)1U + (uint32_t)1U) % (uint32_t)4U];
        uint64_t x20 = r114[((uint32_t)1U + (uint32_t)2U) % (uint32_t)4U];
        uint64_t x30 = r114[((uint32_t)1U + (uint32_t)3U) % (uint32_t)4U];
        r114[0U] = x00;
        r114[1U] = x10;
        r114[2U] = x20;
        r114[3U] = x30;
        uint64_t *r115 = r22;
        uint64_t x01 = r115[2U];
        uint64_t x11 = r115[((uint32_t)2U + (uint32_t)1U) % (uint32_t)4U];
        uint64_t x21 = r115[((uint32_t)2U + (uint32_t)2U) % (uint32_t)4U];
        uint64_t x31 = r115[((uint32_t)2U + (uint32_t)3U) % (uint32_t)4U];
        r115[0U] = x01;
        r115[1U] = x11;
        r115[2U] = x21;
        r115[3U] = x31;
        uint64_t *r116 = r32;
        uint64_t x02 = r116[3U];
        uint64_t x12 = r116[((uint32_t)3U + (uint32_t)1U) % (uint32_t)4U];
        uint64_t x22 = r116[((uint32_t)3U + (uint32_t)2U) % (uint32_t)4U];
        uint64_t x32 = r116[((uint32_t)3U + (uint32_t)3U) % (uint32_t)4U];
        r116[0U] = x02;
        r116[1U] = x12;
        r116[2U] = x22;
        r116[3U] = x32;
        uint32_t a0 = (uint32_t)0U;
        uint32_t b1 = (uint32_t)1U;
        uint32_t c = (uint32_t)2U;
        uint32_t d = (uint32_t)3U;
        uint32_t r0 = Hacl_Impl_Blake2_Constants_rTable_B[0U];
        uint32_t r1 = Hacl_Impl_Blake2_Constants_rTable_B[1U];
        uint32_t r23 = Hacl_Impl_Blake2_Constants_rTable_B[2U];
        uint32_t r33 = Hacl_Impl_Blake2_Constants_rTable_B[3U];
        uint64_t *wv_a = block_state1.fst + a0 * (uint32_t)4U;
        uint64_t *wv_b8 = block_state1.fst + b1 * (uint32_t)4U;
        for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
        {
          uint64_t *os = wv_a;
          uint64_t x1 = wv_a[i] + wv_b8[i];
          os[i] = x1;
        }
        for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
        {
          uint64_t *os = wv_a;
          uint64_t x1 = wv_a[i] + z[i];
          os[i] = x1;
        }
        uint64_t *wv_a8 = block_state1.fst + d * (uint32_t)4U;
        uint64_t *wv_b9 = block_state1.fst + a0 * (uint32_t)4U;
        for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
        {
          uint64_t *os = wv_a8;
          uint64_t x1 = wv_a8[i] ^ wv_b9[i];
          os[i] = x1;
        }
        uint64_t *r117 = wv_a8;
        for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
        {
          uint64_t *os = r117;
          uint64_t x1 = r117[i];
          uint64_t x13 = x1 >> r0 | x1 << ((uint32_t)64U - r0);
          os[i] = x13;
        }
        uint64_t *wv_a9 = block_state1.fst + c * (uint32_t)4U;
        uint64_t *wv_b10 = block_state1.fst + d * (uint32_t)4U;
        for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
        {
          uint64_t *os = wv_a9;
          uint64_t x1 = wv_a9[i] + wv_b10[i];
          os[i] = x1;
        }
        uint64_t *wv_a10 = block_state1.fst + b1 * (uint32_t)4U;
        uint64_t *wv_b11 = block_state1.fst + c * (uint32_t)4U;
        for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
        {
          uint64_t *os = wv_a10;
          uint64_t x1 = wv_a10[i] ^ wv_b11[i];
          os[i] = x1;
        }
        uint64_t *r118 = wv_a10;
        for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
        {
          uint64_t *os = r118;
          uint64_t x1 = r118[i];
          uint64_t x13 = x1 >> r1 | x1 << ((uint32_t)64U - r1);
          os[i] = x13;
        }
        uint64_t *wv_a11 = block_state1.fst + a0 * (uint32_t)4U;
        uint64_t *wv_b12 = block_state1.fst + b1 * (uint32_t)4U;
        for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
        {
          uint64_t *os = wv_a11;
          uint64_t x1 = wv_a11[i] + wv_b12[i];
          os[i] = x1;
        }
        for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
        {
          uint64_t *os = wv_a11;
          uint64_t x1 = wv_a11[i] + w[i];
          os[i] = x1;
        }
        uint64_t *wv_a12 = block_state1.fst + d * (uint32_t)4U;
        uint64_t *wv_b13 = block_state1.fst + a0 * (uint32_t)4U;
        for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
        {
          uint64_t *os = wv_a12;
          uint64_t x1 = wv_a12[i] ^ wv_b13[i];
          os[i] = x1;
        }
        uint64_t *r119 = wv_a12;
        for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
        {
          uint64_t *os = r119;
          uint64_t x1 = r119[i];
          uint64_t x13 = x1 >> r23 | x1 << ((uint32_t)64U - r23);
          os[i] = x13;
        }
        uint64_t *wv_a13 = block_state1.fst + c * (uint32_t)4U;
        uint64_t *wv_b14 = block_state1.fst + d * (uint32_t)4U;
        for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
        {
          uint64_t *os = wv_a13;
          uint64_t x1 = wv_a13[i] + wv_b14[i];
          os[i] = x1;
        }
        uint64_t *wv_a14 = block_state1.fst + b1 * (uint32_t)4U;
        uint64_t *wv_b = block_state1.fst + c * (uint32_t)4U;
        for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
        {
          uint64_t *os = wv_a14;
          uint64_t x1 = wv_a14[i] ^ wv_b[i];
          os[i] = x1;
        }
        uint64_t *r1110 = wv_a14;
        for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
        {
          uint64_t *os = r1110;
          uint64_t x1 = r1110[i];
          uint64_t x13 = x1 >> r33 | x1 << ((uint32_t)64U - r33);
          os[i] = x13;
        }
        uint64_t *r14 = block_state1.fst + (uint32_t)1U * (uint32_t)4U;
        uint64_t *r2 = block_state1.fst + (uint32_t)2U * (uint32_t)4U;
        uint64_t *r3 = block_state1.fst + (uint32_t)3U * (uint32_t)4U;
        uint64_t *r11 = r14;
        uint64_t x03 = r11[3U];
        uint64_t x13 = r11[((uint32_t)3U + (uint32_t)1U) % (uint32_t)4U];
        uint64_t x23 = r11[((uint32_t)3U + (uint32_t)2U) % (uint32_t)4U];
        uint64_t x33 = r11[((uint32_t)3U + (uint32_t)3U) % (uint32_t)4U];
        r11[0U] = x03;
        r11[1U] = x13;
        r11[2U] = x23;
        r11[3U] = x33;
        uint64_t *r1111 = r2;
        uint64_t x04 = r1111[2U];
        uint64_t x14 = r1111[((uint32_t)2U + (uint32_t)1U) % (uint32_t)4U];
        uint64_t x24 = r1111[((uint32_t)2U + (uint32_t)2U) % (uint32_t)4U];
        uint64_t x34 = r1111[((uint32_t)2U + (uint32_t)3U) % (uint32_t)4U];
        r1111[0U] = x04;
        r1111[1U] = x14;
        r1111[2U] = x24;
        r1111[3U] = x34;
        uint64_t *r1112 = r3;
        uint64_t x0 = r1112[1U];
        uint64_t x1 = r1112[((uint32_t)1U + (uint32_t)1U) % (uint32_t)4U];
        uint64_t x2 = r1112[((uint32_t)1U + (uint32_t)2U) % (uint32_t)4U];
        uint64_t x3 = r1112[((uint32_t)1U + (uint32_t)3U) % (uint32_t)4U];
        r1112[0U] = x0;
        r1112[1U] = x1;
        r1112[2U] = x2;
        r1112[3U] = x3;
      }
      uint64_t *s0 = block_state1.snd + (uint32_t)0U * (uint32_t)4U;
      uint64_t *s11 = block_state1.snd + (uint32_t)1U * (uint32_t)4U;
      uint64_t *r0 = block_state1.fst + (uint32_t)0U * (uint32_t)4U;
      uint64_t *r1 = block_state1.fst + (uint32_t)1U * (uint32_t)4U;
      uint64_t *r2 = block_state1.fst + (uint32_t)2U * (uint32_t)4U;
      uint64_t *r3 = block_state1.fst + (uint32_t)3U * (uint32_t)4U;
      for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
      {
        uint64_t *os = s0;
        uint64_t x = s0[i] ^ r0[i];
        os[i] = x;
      }
      for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
      {
        uint64_t *os = s0;
        uint64_t x = s0[i] ^ r2[i];
        os[i] = x;
      }
      for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
      {
        uint64_t *os = s11;
        uint64_t x = s11[i] ^ r1[i];
        os[i] = x;
      }
      for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
      {
        uint64_t *os = s11;
        uint64_t x = s11[i] ^ r3[i];
        os[i] = x;
      }
    }
  }
  uint32_t ite0;
  if
  (
    (uint64_t)(len - diff)
    % (uint64_t)(uint32_t)128U
    == (uint64_t)0U
    && (uint64_t)(len - diff) > (uint64_t)0U
  )
  {
    ite0 = (uint32_t)128U;
  }
  else
  {
    ite0 = (uint32_t)((uint64_t)(len - diff) % (uint64_t)(uint32_t)128U);
  }
  uint32_t n_blocks = (len - diff - ite0) / (uint32_t)128U;
  uint32_t data1_len = n_blocks * (uint32_t)128U;
  uint32_t data2_len = len - diff - data1_len;
  uint8_t *data11 = data2;
  uint8_t *data21 = data2 + data1_len;
  uint32_t nb = data1_len / (uint32_t)128U;
  for (uint32_t i0 = (uint32_t)0U; i0 < nb; i0++)
  {
    uint64_t ite;
    if ((uint32_t)0U == (uint32_t)0U)
    {
      ite = total_len1;
    }
    else
    {
      ite = total_len1 + (uint64_t)(uint32_t)128U;
    }
    FStar_UInt128_uint128
    totlen =
      FStar_UInt128_add_mod(FStar_UInt128_uint64_to_uint128(ite),
        FStar_UInt128_uint64_to_uint128((uint64_t)((i0 + (uint32_t)1U) * (uint32_t)128U)));
    uint8_t *b = data11 + i0 * (uint32_t)128U;
    uint64_t m_w[16U] = { 0U };
    for (uint32_t i = (uint32_t)0U; i < (uint32_t)16U; i++)
    {
      uint64_t *os = m_w;
      uint8_t *bj = b + i * (uint32_t)8U;
      uint64_t u = load64_le(bj);
      uint64_t r = u;
      uint64_t x = r;
      os[i] = x;
    }
    uint64_t mask[4U] = { 0U };
    uint64_t wv_14 = (uint64_t)0U;
    uint64_t wv_15 = (uint64_t)0U;
    mask[0U] = FStar_UInt128_uint128_to_uint64(totlen);
    mask[1U] = FStar_UInt128_uint128_to_uint64(FStar_UInt128_shift_right(totlen, (uint32_t)64U));
    mask[2U] = wv_14;
    mask[3U] = wv_15;
    memcpy(block_state1.fst,
      block_state1.snd,
      (uint32_t)4U * (uint32_t)4U * sizeof (block_state1.snd[0U]));
    uint64_t *wv3 = block_state1.fst + (uint32_t)3U * (uint32_t)4U;
    for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
    {
      uint64_t *os = wv3;
      uint64_t x = wv3[i] ^ mask[i];
      os[i] = x;
    }
    for (uint32_t i1 = (uint32_t)0U; i1 < (uint32_t)12U; i1++)
    {
      uint32_t start_idx = i1 % (uint32_t)10U * (uint32_t)16U;
      KRML_CHECK_SIZE(sizeof (uint64_t), (uint32_t)4U * (uint32_t)4U);
      uint64_t m_st[(uint32_t)4U * (uint32_t)4U];
      memset(m_st, 0U, (uint32_t)4U * (uint32_t)4U * sizeof (m_st[0U]));
      uint64_t *r00 = m_st + (uint32_t)0U * (uint32_t)4U;
      uint64_t *r10 = m_st + (uint32_t)1U * (uint32_t)4U;
      uint64_t *r20 = m_st + (uint32_t)2U * (uint32_t)4U;
      uint64_t *r30 = m_st + (uint32_t)3U * (uint32_t)4U;
      uint32_t s0 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx];
      uint32_t s11 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)1U];
      uint32_t s21 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)2U];
      uint32_t s3 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)3U];
      uint32_t s4 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)4U];
      uint32_t s5 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)5U];
      uint32_t s6 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)6U];
      uint32_t s7 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)7U];
      uint32_t s8 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)8U];
      uint32_t s9 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)9U];
      uint32_t s10 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)10U];
      uint32_t s111 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)11U];
      uint32_t s12 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)12U];
      uint32_t s13 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)13U];
      uint32_t s14 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)14U];
      uint32_t s15 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)15U];
      uint64_t uu____36 = m_w[s21];
      uint64_t uu____37 = m_w[s4];
      uint64_t uu____38 = m_w[s6];
      r00[0U] = m_w[s0];
      r00[1U] = uu____36;
      r00[2U] = uu____37;
      r00[3U] = uu____38;
      uint64_t uu____39 = m_w[s3];
      uint64_t uu____40 = m_w[s5];
      uint64_t uu____41 = m_w[s7];
      r10[0U] = m_w[s11];
      r10[1U] = uu____39;
      r10[2U] = uu____40;
      r10[3U] = uu____41;
      uint64_t uu____42 = m_w[s10];
      uint64_t uu____43 = m_w[s12];
      uint64_t uu____44 = m_w[s14];
      r20[0U] = m_w[s8];
      r20[1U] = uu____42;
      r20[2U] = uu____43;
      r20[3U] = uu____44;
      uint64_t uu____45 = m_w[s111];
      uint64_t uu____46 = m_w[s13];
      uint64_t uu____47 = m_w[s15];
      r30[0U] = m_w[s9];
      r30[1U] = uu____45;
      r30[2U] = uu____46;
      r30[3U] = uu____47;
      uint64_t *x = m_st + (uint32_t)0U * (uint32_t)4U;
      uint64_t *y = m_st + (uint32_t)1U * (uint32_t)4U;
      uint64_t *z = m_st + (uint32_t)2U * (uint32_t)4U;
      uint64_t *w = m_st + (uint32_t)3U * (uint32_t)4U;
      uint32_t a = (uint32_t)0U;
      uint32_t b10 = (uint32_t)1U;
      uint32_t c0 = (uint32_t)2U;
      uint32_t d0 = (uint32_t)3U;
      uint32_t r01 = Hacl_Impl_Blake2_Constants_rTable_B[0U];
      uint32_t r12 = Hacl_Impl_Blake2_Constants_rTable_B[1U];
      uint32_t r21 = Hacl_Impl_Blake2_Constants_rTable_B[2U];
      uint32_t r31 = Hacl_Impl_Blake2_Constants_rTable_B[3U];
      uint64_t *wv_a0 = block_state1.fst + a * (uint32_t)4U;
      uint64_t *wv_b0 = block_state1.fst + b10 * (uint32_t)4U;
      for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
      {
        uint64_t *os = wv_a0;
        uint64_t x1 = wv_a0[i] + wv_b0[i];
        os[i] = x1;
      }
      for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
      {
        uint64_t *os = wv_a0;
        uint64_t x1 = wv_a0[i] + x[i];
        os[i] = x1;
      }
      uint64_t *wv_a1 = block_state1.fst + d0 * (uint32_t)4U;
      uint64_t *wv_b1 = block_state1.fst + a * (uint32_t)4U;
      for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
      {
        uint64_t *os = wv_a1;
        uint64_t x1 = wv_a1[i] ^ wv_b1[i];
        os[i] = x1;
      }
      uint64_t *r110 = wv_a1;
      for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
      {
        uint64_t *os = r110;
        uint64_t x1 = r110[i];
        uint64_t x10 = x1 >> r01 | x1 << ((uint32_t)64U - r01);
        os[i] = x10;
      }
      uint64_t *wv_a2 = block_state1.fst + c0 * (uint32_t)4U;
      uint64_t *wv_b2 = block_state1.fst + d0 * (uint32_t)4U;
      for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
      {
        uint64_t *os = wv_a2;
        uint64_t x1 = wv_a2[i] + wv_b2[i];
        os[i] = x1;
      }
      uint64_t *wv_a3 = block_state1.fst + b10 * (uint32_t)4U;
      uint64_t *wv_b3 = block_state1.fst + c0 * (uint32_t)4U;
      for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
      {
        uint64_t *os = wv_a3;
        uint64_t x1 = wv_a3[i] ^ wv_b3[i];
        os[i] = x1;
      }
      uint64_t *r111 = wv_a3;
      for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
      {
        uint64_t *os = r111;
        uint64_t x1 = r111[i];
        uint64_t x10 = x1 >> r12 | x1 << ((uint32_t)64U - r12);
        os[i] = x10;
      }
      uint64_t *wv_a4 = block_state1.fst + a * (uint32_t)4U;
      uint64_t *wv_b4 = block_state1.fst + b10 * (uint32_t)4U;
      for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
      {
        uint64_t *os = wv_a4;
        uint64_t x1 = wv_a4[i] + wv_b4[i];
        os[i] = x1;
      }
      for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
      {
        uint64_t *os = wv_a4;
        uint64_t x1 = wv_a4[i] + y[i];
        os[i] = x1;
      }
      uint64_t *wv_a5 = block_state1.fst + d0 * (uint32_t)4U;
      uint64_t *wv_b5 = block_state1.fst + a * (uint32_t)4U;
      for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
      {
        uint64_t *os = wv_a5;
        uint64_t x1 = wv_a5[i] ^ wv_b5[i];
        os[i] = x1;
      }
      uint64_t *r112 = wv_a5;
      for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
      {
        uint64_t *os = r112;
        uint64_t x1 = r112[i];
        uint64_t x10 = x1 >> r21 | x1 << ((uint32_t)64U - r21);
        os[i] = x10;
      }
      uint64_t *wv_a6 = block_state1.fst + c0 * (uint32_t)4U;
      uint64_t *wv_b6 = block_state1.fst + d0 * (uint32_t)4U;
      for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
      {
        uint64_t *os = wv_a6;
        uint64_t x1 = wv_a6[i] + wv_b6[i];
        os[i] = x1;
      }
      uint64_t *wv_a7 = block_state1.fst + b10 * (uint32_t)4U;
      uint64_t *wv_b7 = block_state1.fst + c0 * (uint32_t)4U;
      for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
      {
        uint64_t *os = wv_a7;
        uint64_t x1 = wv_a7[i] ^ wv_b7[i];
        os[i] = x1;
      }
      uint64_t *r113 = wv_a7;
      for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
      {
        uint64_t *os = r113;
        uint64_t x1 = r113[i];
        uint64_t x10 = x1 >> r31 | x1 << ((uint32_t)64U - r31);
        os[i] = x10;
      }
      uint64_t *r13 = block_state1.fst + (uint32_t)1U * (uint32_t)4U;
      uint64_t *r22 = block_state1.fst + (uint32_t)2U * (uint32_t)4U;
      uint64_t *r32 = block_state1.fst + (uint32_t)3U * (uint32_t)4U;
      uint64_t *r114 = r13;
      uint64_t x00 = r114[1U];
      uint64_t x10 = r114[((uint32_t)1U + (uint32_t)1U) % (uint32_t)4U];
      uint64_t x20 = r114[((uint32_t)1U + (uint32_t)2U) % (uint32_t)4U];
      uint64_t x30 = r114[((uint32_t)1U + (uint32_t)3U) % (uint32_t)4U];
      r114[0U] = x00;
      r114[1U] = x10;
      r114[2U] = x20;
      r114[3U] = x30;
      uint64_t *r115 = r22;
      uint64_t x01 = r115[2U];
      uint64_t x11 = r115[((uint32_t)2U + (uint32_t)1U) % (uint32_t)4U];
      uint64_t x21 = r115[((uint32_t)2U + (uint32_t)2U) % (uint32_t)4U];
      uint64_t x31 = r115[((uint32_t)2U + (uint32_t)3U) % (uint32_t)4U];
      r115[0U] = x01;
      r115[1U] = x11;
      r115[2U] = x21;
      r115[3U] = x31;
      uint64_t *r116 = r32;
      uint64_t x02 = r116[3U];
      uint64_t x12 = r116[((uint32_t)3U + (uint32_t)1U) % (uint32_t)4U];
      uint64_t x22 = r116[((uint32_t)3U + (uint32_t)2U) % (uint32_t)4U];
      uint64_t x32 = r116[((uint32_t)3U + (uint32_t)3U) % (uint32_t)4U];
      r116[0U] = x02;
      r116[1U] = x12;
      r116[2U] = x22;
      r116[3U] = x32;
      uint32_t a0 = (uint32_t)0U;
      uint32_t b1 = (uint32_t)1U;
      uint32_t c = (uint32_t)2U;
      uint32_t d = (uint32_t)3U;
      uint32_t r0 = Hacl_Impl_Blake2_Constants_rTable_B[0U];
      uint32_t r1 = Hacl_Impl_Blake2_Constants_rTable_B[1U];
      uint32_t r23 = Hacl_Impl_Blake2_Constants_rTable_B[2U];
      uint32_t r33 = Hacl_Impl_Blake2_Constants_rTable_B[3U];
      uint64_t *wv_a = block_state1.fst + a0 * (uint32_t)4U;
      uint64_t *wv_b8 = block_state1.fst + b1 * (uint32_t)4U;
      for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
      {
        uint64_t *os = wv_a;
        uint64_t x1 = wv_a[i] + wv_b8[i];
        os[i] = x1;
      }
      for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
      {
        uint64_t *os = wv_a;
        uint64_t x1 = wv_a[i] + z[i];
        os[i] = x1;
      }
      uint64_t *wv_a8 = block_state1.fst + d * (uint32_t)4U;
      uint64_t *wv_b9 = block_state1.fst + a0 * (uint32_t)4U;
      for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
      {
        uint64_t *os = wv_a8;
        uint64_t x1 = wv_a8[i] ^ wv_b9[i];
        os[i] = x1;
      }
      uint64_t *r117 = wv_a8;
      for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
      {
        uint64_t *os = r117;
        uint64_t x1 = r117[i];
        uint64_t x13 = x1 >> r0 | x1 << ((uint32_t)64U - r0);
        os[i] = x13;
      }
      uint64_t *wv_a9 = block_state1.fst + c * (uint32_t)4U;
      uint64_t *wv_b10 = block_state1.fst + d * (uint32_t)4U;
      for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
      {
        uint64_t *os = wv_a9;
        uint64_t x1 = wv_a9[i] + wv_b10[i];
        os[i] = x1;
      }
      uint64_t *wv_a10 = block_state1.fst + b1 * (uint32_t)4U;
      uint64_t *wv_b11 = block_state1.fst + c * (uint32_t)4U;
      for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
      {
        uint64_t *os = wv_a10;
        uint64_t x1 = wv_a10[i] ^ wv_b11[i];
        os[i] = x1;
      }
      uint64_t *r118 = wv_a10;
      for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
      {
        uint64_t *os = r118;
        uint64_t x1 = r118[i];
        uint64_t x13 = x1 >> r1 | x1 << ((uint32_t)64U - r1);
        os[i] = x13;
      }
      uint64_t *wv_a11 = block_state1.fst + a0 * (uint32_t)4U;
      uint64_t *wv_b12 = block_state1.fst + b1 * (uint32_t)4U;
      for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
      {
        uint64_t *os = wv_a11;
        uint64_t x1 = wv_a11[i] + wv_b12[i];
        os[i] = x1;
      }
      for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
      {
        uint64_t *os = wv_a11;
        uint64_t x1 = wv_a11[i] + w[i];
        os[i] = x1;
      }
      uint64_t *wv_a12 = block_state1.fst + d * (uint32_t)4U;
      uint64_t *wv_b13 = block_state1.fst + a0 * (uint32_t)4U;
      for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
      {
        uint64_t *os = wv_a12;
        uint64_t x1 = wv_a12[i] ^ wv_b13[i];
        os[i] = x1;
      }
      uint64_t *r119 = wv_a12;
      for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
      {
        uint64_t *os = r119;
        uint64_t x1 = r119[i];
        uint64_t x13 = x1 >> r23 | x1 << ((uint32_t)64U - r23);
        os[i] = x13;
      }
      uint64_t *wv_a13 = block_state1.fst + c * (uint32_t)4U;
      uint64_t *wv_b14 = block_state1.fst + d * (uint32_t)4U;
      for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
      {
        uint64_t *os = wv_a13;
        uint64_t x1 = wv_a13[i] + wv_b14[i];
        os[i] = x1;
      }
      uint64_t *wv_a14 = block_state1.fst + b1 * (uint32_t)4U;
      uint64_t *wv_b = block_state1.fst + c * (uint32_t)4U;
      for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
      {
        uint64_t *os = wv_a14;
        uint64_t x1 = wv_a14[i] ^ wv_b[i];
        os[i] = x1;
      }
      uint64_t *r1110 = wv_a14;
      for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
      {
        uint64_t *os = r1110;
        uint64_t x1 = r1110[i];
        uint64_t x13 = x1 >> r33 | x1 << ((uint32_t)64U - r33);
        os[i] = x13;
      }
      uint64_t *r14 = block_state1.fst + (uint32_t)1U * (uint32_t)4U;
      uint64_t *r2 = block_state1.fst + (uint32_t)2U * (uint32_t)4U;
      uint64_t *r3 = block_state1.fst + (uint32_t)3U * (uint32_t)4U;
      uint64_t *r11 = r14;
      uint64_t x03 = r11[3U];
      uint64_t x13 = r11[((uint32_t)3U + (uint32_t)1U) % (uint32_t)4U];
      uint64_t x23 = r11[((uint32_t)3U + (uint32_t)2U) % (uint32_t)4U];
      uint64_t x33 = r11[((uint32_t)3U + (uint32_t)3U) % (uint32_t)4U];
      r11[0U] = x03;
      r11[1U] = x13;
      r11[2U] = x23;
      r11[3U] = x33;
      uint64_t *r1111 = r2;
      uint64_t x04 = r1111[2U];
      uint64_t x14 = r1111[((uint32_t)2U + (uint32_t)1U) % (uint32_t)4U];
      uint64_t x24 = r1111[((uint32_t)2U + (uint32_t)2U) % (uint32_t)4U];
      uint64_t x34 = r1111[((uint32_t)2U + (uint32_t)3U) % (uint32_t)4U];
      r1111[0U] = x04;
      r1111[1U] = x14;
      r1111[2U] = x24;
      r1111[3U] = x34;
      uint64_t *r1112 = r3;
      uint64_t x0 = r1112[1U];
      uint64_t x1 = r1112[((uint32_t)1U + (uint32_t)1U) % (uint32_t)4U];
      uint64_t x2 = r1112[((uint32_t)1U + (uint32_t)2U) % (uint32_t)4U];
      uint64_t x3 = r1112[((uint32_t)1U + (uint32_t)3U) % (uint32_t)4U];
      r1112[0U] = x0;
      r1112[1U] = x1;
      r1112[2U] = x2;
      r1112[3U] = x3;
    }
    uint64_t *s0 = block_state1.snd + (uint32_t)0U * (uint32_t)4U;
    uint64_t *s11 = block_state1.snd + (uint32_t)1U * (uint32_t)4U;
    uint64_t *r0 = block_state1.fst + (uint32_t)0U * (uint32_t)4U;
    uint64_t *r1 = block_state1.fst + (uint32_t)1U * (uint32_t)4U;
    uint64_t *r2 = block_state1.fst + (uint32_t)2U * (uint32_t)4U;
    uint64_t *r3 = block_state1.fst + (uint32_t)3U * (uint32_t)4U;
    for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
    {
      uint64_t *os = s0;
      uint64_t x = s0[i] ^ r0[i];
      os[i] = x;
    }
    for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
    {
      uint64_t *os = s0;
      uint64_t x = s0[i] ^ r2[i];
      os[i] = x;
    }
    for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
    {
      uint64_t *os = s11;
      uint64_t x = s11[i] ^ r1[i];
      os[i] = x;
    }
    for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
    {
      uint64_t *os = s11;
      uint64_t x = s11[i] ^ r3[i];
      os[i] = x;
    }
  }
  uint8_t *dst = buf;
  memcpy(dst, data21, data2_len * sizeof (data21[0U]));
  *p
  =
    (
      (Hacl_Streaming_Functor_state_s__K____uint64_t___uint64_t____){
        .block_state = block_state1,
        .buf = buf,
        .total_len = total_len1 + (uint64_t)(len - diff)
      }
    );
}

/* SNIPPET_END: Hacl_Streaming_Blake2_blake2b_32_no_key_update */

/* SNIPPET_START: Hacl_Streaming_Blake2_blake2b_32_no_key_finish */

/*
  Finish function when there is no key
*/
void
Hacl_Streaming_Blake2_blake2b_32_no_key_finish(
  Hacl_Streaming_Functor_state_s__K____uint64_t___uint64_t____ *p,
  uint8_t *dst
)
{
  Hacl_Streaming_Functor_state_s__K____uint64_t___uint64_t____ scrut = *p;
  K____uint64_t___uint64_t_ block_state = scrut.block_state;
  uint8_t *buf_ = scrut.buf;
  uint64_t total_len = scrut.total_len;
  uint32_t r;
  if (total_len % (uint64_t)(uint32_t)128U == (uint64_t)0U && total_len > (uint64_t)0U)
  {
    r = (uint32_t)128U;
  }
  else
  {
    r = (uint32_t)(total_len % (uint64_t)(uint32_t)128U);
  }
  uint8_t *buf_1 = buf_;
  KRML_CHECK_SIZE(sizeof (uint64_t), (uint32_t)4U * (uint32_t)4U);
  uint64_t wv[(uint32_t)4U * (uint32_t)4U];
  memset(wv, 0U, (uint32_t)4U * (uint32_t)4U * sizeof (wv[0U]));
  KRML_CHECK_SIZE(sizeof (uint64_t), (uint32_t)4U * (uint32_t)4U);
  uint64_t b0[(uint32_t)4U * (uint32_t)4U];
  memset(b0, 0U, (uint32_t)4U * (uint32_t)4U * sizeof (b0[0U]));
  K____uint64_t___uint64_t_ tmp_block_state = { .fst = wv, .snd = b0 };
  uint64_t *src_b = block_state.snd;
  uint64_t *dst_b = tmp_block_state.snd;
  memcpy(dst_b, src_b, (uint32_t)16U * sizeof (src_b[0U]));
  uint64_t prev_len = total_len - (uint64_t)r;
  uint8_t b2[128U] = { 0U };
  uint8_t *last = buf_1 + r - r;
  memcpy(b2, last, r * sizeof (last[0U]));
  uint64_t ite;
  if ((uint32_t)0U == (uint32_t)0U)
  {
    ite = prev_len;
  }
  else
  {
    ite = prev_len + (uint64_t)(uint32_t)128U;
  }
  FStar_UInt128_uint128
  totlen =
    FStar_UInt128_add_mod(FStar_UInt128_uint64_to_uint128(ite),
      FStar_UInt128_uint64_to_uint128((uint64_t)r));
  uint64_t m_w[16U] = { 0U };
  for (uint32_t i = (uint32_t)0U; i < (uint32_t)16U; i++)
  {
    uint64_t *os = m_w;
    uint8_t *bj = b2 + i * (uint32_t)8U;
    uint64_t u = load64_le(bj);
    uint64_t r1 = u;
    uint64_t x = r1;
    os[i] = x;
  }
  uint64_t mask[4U] = { 0U };
  uint64_t wv_14 = (uint64_t)0xFFFFFFFFFFFFFFFFU;
  uint64_t wv_15 = (uint64_t)0U;
  mask[0U] = FStar_UInt128_uint128_to_uint64(totlen);
  mask[1U] = FStar_UInt128_uint128_to_uint64(FStar_UInt128_shift_right(totlen, (uint32_t)64U));
  mask[2U] = wv_14;
  mask[3U] = wv_15;
  memcpy(tmp_block_state.fst,
    tmp_block_state.snd,
    (uint32_t)4U * (uint32_t)4U * sizeof (tmp_block_state.snd[0U]));
  uint64_t *wv3 = tmp_block_state.fst + (uint32_t)3U * (uint32_t)4U;
  for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
  {
    uint64_t *os = wv3;
    uint64_t x = wv3[i] ^ mask[i];
    os[i] = x;
  }
  for (uint32_t i0 = (uint32_t)0U; i0 < (uint32_t)12U; i0++)
  {
    uint32_t start_idx = i0 % (uint32_t)10U * (uint32_t)16U;
    KRML_CHECK_SIZE(sizeof (uint64_t), (uint32_t)4U * (uint32_t)4U);
    uint64_t m_st[(uint32_t)4U * (uint32_t)4U];
    memset(m_st, 0U, (uint32_t)4U * (uint32_t)4U * sizeof (m_st[0U]));
    uint64_t *r00 = m_st + (uint32_t)0U * (uint32_t)4U;
    uint64_t *r10 = m_st + (uint32_t)1U * (uint32_t)4U;
    uint64_t *r20 = m_st + (uint32_t)2U * (uint32_t)4U;
    uint64_t *r30 = m_st + (uint32_t)3U * (uint32_t)4U;
    uint32_t s0 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx];
    uint32_t s1 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)1U];
    uint32_t s2 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)2U];
    uint32_t s3 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)3U];
    uint32_t s4 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)4U];
    uint32_t s5 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)5U];
    uint32_t s6 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)6U];
    uint32_t s7 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)7U];
    uint32_t s8 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)8U];
    uint32_t s9 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)9U];
    uint32_t s10 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)10U];
    uint32_t s11 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)11U];
    uint32_t s12 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)12U];
    uint32_t s13 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)13U];
    uint32_t s14 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)14U];
    uint32_t s15 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)15U];
    uint64_t uu____0 = m_w[s2];
    uint64_t uu____1 = m_w[s4];
    uint64_t uu____2 = m_w[s6];
    r00[0U] = m_w[s0];
    r00[1U] = uu____0;
    r00[2U] = uu____1;
    r00[3U] = uu____2;
    uint64_t uu____3 = m_w[s3];
    uint64_t uu____4 = m_w[s5];
    uint64_t uu____5 = m_w[s7];
    r10[0U] = m_w[s1];
    r10[1U] = uu____3;
    r10[2U] = uu____4;
    r10[3U] = uu____5;
    uint64_t uu____6 = m_w[s10];
    uint64_t uu____7 = m_w[s12];
    uint64_t uu____8 = m_w[s14];
    r20[0U] = m_w[s8];
    r20[1U] = uu____6;
    r20[2U] = uu____7;
    r20[3U] = uu____8;
    uint64_t uu____9 = m_w[s11];
    uint64_t uu____10 = m_w[s13];
    uint64_t uu____11 = m_w[s15];
    r30[0U] = m_w[s9];
    r30[1U] = uu____9;
    r30[2U] = uu____10;
    r30[3U] = uu____11;
    uint64_t *x = m_st + (uint32_t)0U * (uint32_t)4U;
    uint64_t *y = m_st + (uint32_t)1U * (uint32_t)4U;
    uint64_t *z = m_st + (uint32_t)2U * (uint32_t)4U;
    uint64_t *w = m_st + (uint32_t)3U * (uint32_t)4U;
    uint32_t a = (uint32_t)0U;
    uint32_t b10 = (uint32_t)1U;
    uint32_t c0 = (uint32_t)2U;
    uint32_t d0 = (uint32_t)3U;
    uint32_t r01 = Hacl_Impl_Blake2_Constants_rTable_B[0U];
    uint32_t r12 = Hacl_Impl_Blake2_Constants_rTable_B[1U];
    uint32_t r21 = Hacl_Impl_Blake2_Constants_rTable_B[2U];
    uint32_t r31 = Hacl_Impl_Blake2_Constants_rTable_B[3U];
    uint64_t *wv_a0 = tmp_block_state.fst + a * (uint32_t)4U;
    uint64_t *wv_b0 = tmp_block_state.fst + b10 * (uint32_t)4U;
    for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
    {
      uint64_t *os = wv_a0;
      uint64_t x1 = wv_a0[i] + wv_b0[i];
      os[i] = x1;
    }
    for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
    {
      uint64_t *os = wv_a0;
      uint64_t x1 = wv_a0[i] + x[i];
      os[i] = x1;
    }
    uint64_t *wv_a1 = tmp_block_state.fst + d0 * (uint32_t)4U;
    uint64_t *wv_b1 = tmp_block_state.fst + a * (uint32_t)4U;
    for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
    {
      uint64_t *os = wv_a1;
      uint64_t x1 = wv_a1[i] ^ wv_b1[i];
      os[i] = x1;
    }
    uint64_t *r110 = wv_a1;
    for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
    {
      uint64_t *os = r110;
      uint64_t x1 = r110[i];
      uint64_t x10 = x1 >> r01 | x1 << ((uint32_t)64U - r01);
      os[i] = x10;
    }
    uint64_t *wv_a2 = tmp_block_state.fst + c0 * (uint32_t)4U;
    uint64_t *wv_b2 = tmp_block_state.fst + d0 * (uint32_t)4U;
    for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
    {
      uint64_t *os = wv_a2;
      uint64_t x1 = wv_a2[i] + wv_b2[i];
      os[i] = x1;
    }
    uint64_t *wv_a3 = tmp_block_state.fst + b10 * (uint32_t)4U;
    uint64_t *wv_b3 = tmp_block_state.fst + c0 * (uint32_t)4U;
    for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
    {
      uint64_t *os = wv_a3;
      uint64_t x1 = wv_a3[i] ^ wv_b3[i];
      os[i] = x1;
    }
    uint64_t *r111 = wv_a3;
    for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
    {
      uint64_t *os = r111;
      uint64_t x1 = r111[i];
      uint64_t x10 = x1 >> r12 | x1 << ((uint32_t)64U - r12);
      os[i] = x10;
    }
    uint64_t *wv_a4 = tmp_block_state.fst + a * (uint32_t)4U;
    uint64_t *wv_b4 = tmp_block_state.fst + b10 * (uint32_t)4U;
    for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
    {
      uint64_t *os = wv_a4;
      uint64_t x1 = wv_a4[i] + wv_b4[i];
      os[i] = x1;
    }
    for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
    {
      uint64_t *os = wv_a4;
      uint64_t x1 = wv_a4[i] + y[i];
      os[i] = x1;
    }
    uint64_t *wv_a5 = tmp_block_state.fst + d0 * (uint32_t)4U;
    uint64_t *wv_b5 = tmp_block_state.fst + a * (uint32_t)4U;
    for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
    {
      uint64_t *os = wv_a5;
      uint64_t x1 = wv_a5[i] ^ wv_b5[i];
      os[i] = x1;
    }
    uint64_t *r112 = wv_a5;
    for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
    {
      uint64_t *os = r112;
      uint64_t x1 = r112[i];
      uint64_t x10 = x1 >> r21 | x1 << ((uint32_t)64U - r21);
      os[i] = x10;
    }
    uint64_t *wv_a6 = tmp_block_state.fst + c0 * (uint32_t)4U;
    uint64_t *wv_b6 = tmp_block_state.fst + d0 * (uint32_t)4U;
    for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
    {
      uint64_t *os = wv_a6;
      uint64_t x1 = wv_a6[i] + wv_b6[i];
      os[i] = x1;
    }
    uint64_t *wv_a7 = tmp_block_state.fst + b10 * (uint32_t)4U;
    uint64_t *wv_b7 = tmp_block_state.fst + c0 * (uint32_t)4U;
    for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
    {
      uint64_t *os = wv_a7;
      uint64_t x1 = wv_a7[i] ^ wv_b7[i];
      os[i] = x1;
    }
    uint64_t *r113 = wv_a7;
    for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
    {
      uint64_t *os = r113;
      uint64_t x1 = r113[i];
      uint64_t x10 = x1 >> r31 | x1 << ((uint32_t)64U - r31);
      os[i] = x10;
    }
    uint64_t *r13 = tmp_block_state.fst + (uint32_t)1U * (uint32_t)4U;
    uint64_t *r22 = tmp_block_state.fst + (uint32_t)2U * (uint32_t)4U;
    uint64_t *r32 = tmp_block_state.fst + (uint32_t)3U * (uint32_t)4U;
    uint64_t *r114 = r13;
    uint64_t x00 = r114[1U];
    uint64_t x10 = r114[((uint32_t)1U + (uint32_t)1U) % (uint32_t)4U];
    uint64_t x20 = r114[((uint32_t)1U + (uint32_t)2U) % (uint32_t)4U];
    uint64_t x30 = r114[((uint32_t)1U + (uint32_t)3U) % (uint32_t)4U];
    r114[0U] = x00;
    r114[1U] = x10;
    r114[2U] = x20;
    r114[3U] = x30;
    uint64_t *r115 = r22;
    uint64_t x01 = r115[2U];
    uint64_t x11 = r115[((uint32_t)2U + (uint32_t)1U) % (uint32_t)4U];
    uint64_t x21 = r115[((uint32_t)2U + (uint32_t)2U) % (uint32_t)4U];
    uint64_t x31 = r115[((uint32_t)2U + (uint32_t)3U) % (uint32_t)4U];
    r115[0U] = x01;
    r115[1U] = x11;
    r115[2U] = x21;
    r115[3U] = x31;
    uint64_t *r116 = r32;
    uint64_t x02 = r116[3U];
    uint64_t x12 = r116[((uint32_t)3U + (uint32_t)1U) % (uint32_t)4U];
    uint64_t x22 = r116[((uint32_t)3U + (uint32_t)2U) % (uint32_t)4U];
    uint64_t x32 = r116[((uint32_t)3U + (uint32_t)3U) % (uint32_t)4U];
    r116[0U] = x02;
    r116[1U] = x12;
    r116[2U] = x22;
    r116[3U] = x32;
    uint32_t a0 = (uint32_t)0U;
    uint32_t b1 = (uint32_t)1U;
    uint32_t c = (uint32_t)2U;
    uint32_t d = (uint32_t)3U;
    uint32_t r0 = Hacl_Impl_Blake2_Constants_rTable_B[0U];
    uint32_t r1 = Hacl_Impl_Blake2_Constants_rTable_B[1U];
    uint32_t r23 = Hacl_Impl_Blake2_Constants_rTable_B[2U];
    uint32_t r33 = Hacl_Impl_Blake2_Constants_rTable_B[3U];
    uint64_t *wv_a = tmp_block_state.fst + a0 * (uint32_t)4U;
    uint64_t *wv_b8 = tmp_block_state.fst + b1 * (uint32_t)4U;
    for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
    {
      uint64_t *os = wv_a;
      uint64_t x1 = wv_a[i] + wv_b8[i];
      os[i] = x1;
    }
    for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
    {
      uint64_t *os = wv_a;
      uint64_t x1 = wv_a[i] + z[i];
      os[i] = x1;
    }
    uint64_t *wv_a8 = tmp_block_state.fst + d * (uint32_t)4U;
    uint64_t *wv_b9 = tmp_block_state.fst + a0 * (uint32_t)4U;
    for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
    {
      uint64_t *os = wv_a8;
      uint64_t x1 = wv_a8[i] ^ wv_b9[i];
      os[i] = x1;
    }
    uint64_t *r117 = wv_a8;
    for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
    {
      uint64_t *os = r117;
      uint64_t x1 = r117[i];
      uint64_t x13 = x1 >> r0 | x1 << ((uint32_t)64U - r0);
      os[i] = x13;
    }
    uint64_t *wv_a9 = tmp_block_state.fst + c * (uint32_t)4U;
    uint64_t *wv_b10 = tmp_block_state.fst + d * (uint32_t)4U;
    for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
    {
      uint64_t *os = wv_a9;
      uint64_t x1 = wv_a9[i] + wv_b10[i];
      os[i] = x1;
    }
    uint64_t *wv_a10 = tmp_block_state.fst + b1 * (uint32_t)4U;
    uint64_t *wv_b11 = tmp_block_state.fst + c * (uint32_t)4U;
    for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
    {
      uint64_t *os = wv_a10;
      uint64_t x1 = wv_a10[i] ^ wv_b11[i];
      os[i] = x1;
    }
    uint64_t *r118 = wv_a10;
    for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
    {
      uint64_t *os = r118;
      uint64_t x1 = r118[i];
      uint64_t x13 = x1 >> r1 | x1 << ((uint32_t)64U - r1);
      os[i] = x13;
    }
    uint64_t *wv_a11 = tmp_block_state.fst + a0 * (uint32_t)4U;
    uint64_t *wv_b12 = tmp_block_state.fst + b1 * (uint32_t)4U;
    for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
    {
      uint64_t *os = wv_a11;
      uint64_t x1 = wv_a11[i] + wv_b12[i];
      os[i] = x1;
    }
    for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
    {
      uint64_t *os = wv_a11;
      uint64_t x1 = wv_a11[i] + w[i];
      os[i] = x1;
    }
    uint64_t *wv_a12 = tmp_block_state.fst + d * (uint32_t)4U;
    uint64_t *wv_b13 = tmp_block_state.fst + a0 * (uint32_t)4U;
    for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
    {
      uint64_t *os = wv_a12;
      uint64_t x1 = wv_a12[i] ^ wv_b13[i];
      os[i] = x1;
    }
    uint64_t *r119 = wv_a12;
    for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
    {
      uint64_t *os = r119;
      uint64_t x1 = r119[i];
      uint64_t x13 = x1 >> r23 | x1 << ((uint32_t)64U - r23);
      os[i] = x13;
    }
    uint64_t *wv_a13 = tmp_block_state.fst + c * (uint32_t)4U;
    uint64_t *wv_b14 = tmp_block_state.fst + d * (uint32_t)4U;
    for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
    {
      uint64_t *os = wv_a13;
      uint64_t x1 = wv_a13[i] + wv_b14[i];
      os[i] = x1;
    }
    uint64_t *wv_a14 = tmp_block_state.fst + b1 * (uint32_t)4U;
    uint64_t *wv_b = tmp_block_state.fst + c * (uint32_t)4U;
    for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
    {
      uint64_t *os = wv_a14;
      uint64_t x1 = wv_a14[i] ^ wv_b[i];
      os[i] = x1;
    }
    uint64_t *r1110 = wv_a14;
    for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
    {
      uint64_t *os = r1110;
      uint64_t x1 = r1110[i];
      uint64_t x13 = x1 >> r33 | x1 << ((uint32_t)64U - r33);
      os[i] = x13;
    }
    uint64_t *r14 = tmp_block_state.fst + (uint32_t)1U * (uint32_t)4U;
    uint64_t *r2 = tmp_block_state.fst + (uint32_t)2U * (uint32_t)4U;
    uint64_t *r3 = tmp_block_state.fst + (uint32_t)3U * (uint32_t)4U;
    uint64_t *r11 = r14;
    uint64_t x03 = r11[3U];
    uint64_t x13 = r11[((uint32_t)3U + (uint32_t)1U) % (uint32_t)4U];
    uint64_t x23 = r11[((uint32_t)3U + (uint32_t)2U) % (uint32_t)4U];
    uint64_t x33 = r11[((uint32_t)3U + (uint32_t)3U) % (uint32_t)4U];
    r11[0U] = x03;
    r11[1U] = x13;
    r11[2U] = x23;
    r11[3U] = x33;
    uint64_t *r1111 = r2;
    uint64_t x04 = r1111[2U];
    uint64_t x14 = r1111[((uint32_t)2U + (uint32_t)1U) % (uint32_t)4U];
    uint64_t x24 = r1111[((uint32_t)2U + (uint32_t)2U) % (uint32_t)4U];
    uint64_t x34 = r1111[((uint32_t)2U + (uint32_t)3U) % (uint32_t)4U];
    r1111[0U] = x04;
    r1111[1U] = x14;
    r1111[2U] = x24;
    r1111[3U] = x34;
    uint64_t *r1112 = r3;
    uint64_t x0 = r1112[1U];
    uint64_t x1 = r1112[((uint32_t)1U + (uint32_t)1U) % (uint32_t)4U];
    uint64_t x2 = r1112[((uint32_t)1U + (uint32_t)2U) % (uint32_t)4U];
    uint64_t x3 = r1112[((uint32_t)1U + (uint32_t)3U) % (uint32_t)4U];
    r1112[0U] = x0;
    r1112[1U] = x1;
    r1112[2U] = x2;
    r1112[3U] = x3;
  }
  uint64_t *s0 = tmp_block_state.snd + (uint32_t)0U * (uint32_t)4U;
  uint64_t *s1 = tmp_block_state.snd + (uint32_t)1U * (uint32_t)4U;
  uint64_t *r0 = tmp_block_state.fst + (uint32_t)0U * (uint32_t)4U;
  uint64_t *r1 = tmp_block_state.fst + (uint32_t)1U * (uint32_t)4U;
  uint64_t *r2 = tmp_block_state.fst + (uint32_t)2U * (uint32_t)4U;
  uint64_t *r3 = tmp_block_state.fst + (uint32_t)3U * (uint32_t)4U;
  for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
  {
    uint64_t *os = s0;
    uint64_t x = s0[i] ^ r0[i];
    os[i] = x;
  }
  for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
  {
    uint64_t *os = s0;
    uint64_t x = s0[i] ^ r2[i];
    os[i] = x;
  }
  for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
  {
    uint64_t *os = s1;
    uint64_t x = s1[i] ^ r1[i];
    os[i] = x;
  }
  for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
  {
    uint64_t *os = s1;
    uint64_t x = s1[i] ^ r3[i];
    os[i] = x;
  }
  Lib_Memzero0_memzero(b2, (uint32_t)128U * sizeof (b2[0U]));
  uint32_t double_row = (uint32_t)2U * (uint32_t)4U * (uint32_t)8U;
  KRML_CHECK_SIZE(sizeof (uint8_t), double_row);
  uint8_t b[double_row];
  memset(b, 0U, double_row * sizeof (b[0U]));
  uint8_t *first = b;
  uint8_t *second = b + (uint32_t)4U * (uint32_t)8U;
  uint64_t *row0 = tmp_block_state.snd + (uint32_t)0U * (uint32_t)4U;
  uint64_t *row1 = tmp_block_state.snd + (uint32_t)1U * (uint32_t)4U;
  for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
  {
    store64_le(first + i * (uint32_t)8U, row0[i]);
  }
  for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
  {
    store64_le(second + i * (uint32_t)8U, row1[i]);
  }
  uint8_t *final = b;
  memcpy(dst, final, (uint32_t)64U * sizeof (final[0U]));
  Lib_Memzero0_memzero(b, double_row * sizeof (b[0U]));
}

/* SNIPPET_END: Hacl_Streaming_Blake2_blake2b_32_no_key_finish */

/* SNIPPET_START: Hacl_Streaming_Blake2_blake2b_32_no_key_free */

/*
  Free state function when there is no key
*/
void
Hacl_Streaming_Blake2_blake2b_32_no_key_free(
  Hacl_Streaming_Functor_state_s__K____uint64_t___uint64_t____ *s1
)
{
  Hacl_Streaming_Functor_state_s__K____uint64_t___uint64_t____ scrut = *s1;
  uint8_t *buf = scrut.buf;
  K____uint64_t___uint64_t_ block_state = scrut.block_state;
  uint64_t *wv = block_state.fst;
  uint64_t *b = block_state.snd;
  KRML_HOST_FREE(wv);
  KRML_HOST_FREE(b);
  KRML_HOST_FREE(buf);
  KRML_HOST_FREE(s1);
}

/* SNIPPET_END: Hacl_Streaming_Blake2_blake2b_32_no_key_free */

/* SNIPPET_START: Hacl_Streaming_Functor_state_s__K____Lib_IntVector_Intrinsics_vec256___Lib_IntVector_Intrinsics_vec256____ */

typedef struct
Hacl_Streaming_Functor_state_s__K____Lib_IntVector_Intrinsics_vec256___Lib_IntVector_Intrinsics_vec256_____s
{
  K____Lib_IntVector_Intrinsics_vec256___Lib_IntVector_Intrinsics_vec256_ block_state;
  uint8_t *buf;
  uint64_t total_len;
}
Hacl_Streaming_Functor_state_s__K____Lib_IntVector_Intrinsics_vec256___Lib_IntVector_Intrinsics_vec256____;

/* SNIPPET_END: Hacl_Streaming_Functor_state_s__K____Lib_IntVector_Intrinsics_vec256___Lib_IntVector_Intrinsics_vec256____ */

/* SNIPPET_START: Hacl_Streaming_Blake2_blake2b_256_no_key_create_in */

/*
  State allocation function when there is no key
*/
Hacl_Streaming_Functor_state_s__K____Lib_IntVector_Intrinsics_vec256___Lib_IntVector_Intrinsics_vec256____
*Hacl_Streaming_Blake2_blake2b_256_no_key_create_in()
{
  uint8_t *buf = KRML_HOST_CALLOC((uint32_t)128U, sizeof (uint8_t));
  Lib_IntVector_Intrinsics_vec256
  *wv = KRML_HOST_MALLOC(sizeof (Lib_IntVector_Intrinsics_vec256) * (uint32_t)4U);
  for (uint32_t _i = 0U; _i < (uint32_t)4U; ++_i)
    wv[_i] = Lib_IntVector_Intrinsics_vec256_zero;
  Lib_IntVector_Intrinsics_vec256
  *b0 = KRML_HOST_MALLOC(sizeof (Lib_IntVector_Intrinsics_vec256) * (uint32_t)4U);
  for (uint32_t _i = 0U; _i < (uint32_t)4U; ++_i)
    b0[_i] = Lib_IntVector_Intrinsics_vec256_zero;
  K____Lib_IntVector_Intrinsics_vec256___Lib_IntVector_Intrinsics_vec256_
  block_state = { .fst = wv, .snd = b0 };
  Hacl_Streaming_Functor_state_s__K____Lib_IntVector_Intrinsics_vec256___Lib_IntVector_Intrinsics_vec256____
  s1 = { .block_state = block_state, .buf = buf, .total_len = (uint64_t)0U };
  KRML_CHECK_SIZE(sizeof (
      Hacl_Streaming_Functor_state_s__K____Lib_IntVector_Intrinsics_vec256___Lib_IntVector_Intrinsics_vec256____
    ),
    (uint32_t)1U);
  Hacl_Streaming_Functor_state_s__K____Lib_IntVector_Intrinsics_vec256___Lib_IntVector_Intrinsics_vec256____
  *p =
    KRML_HOST_MALLOC(sizeof (
        Hacl_Streaming_Functor_state_s__K____Lib_IntVector_Intrinsics_vec256___Lib_IntVector_Intrinsics_vec256____
      ));
  p[0U] = s1;
  uint8_t b[128U] = { 0U };
  Lib_IntVector_Intrinsics_vec256 *r00 = block_state.snd + (uint32_t)0U * (uint32_t)1U;
  Lib_IntVector_Intrinsics_vec256 *r10 = block_state.snd + (uint32_t)1U * (uint32_t)1U;
  Lib_IntVector_Intrinsics_vec256 *r20 = block_state.snd + (uint32_t)2U * (uint32_t)1U;
  Lib_IntVector_Intrinsics_vec256 *r30 = block_state.snd + (uint32_t)3U * (uint32_t)1U;
  uint64_t iv0 = Hacl_Impl_Blake2_Constants_ivTable_B[0U];
  uint64_t iv1 = Hacl_Impl_Blake2_Constants_ivTable_B[1U];
  uint64_t iv2 = Hacl_Impl_Blake2_Constants_ivTable_B[2U];
  uint64_t iv3 = Hacl_Impl_Blake2_Constants_ivTable_B[3U];
  uint64_t iv4 = Hacl_Impl_Blake2_Constants_ivTable_B[4U];
  uint64_t iv5 = Hacl_Impl_Blake2_Constants_ivTable_B[5U];
  uint64_t iv6 = Hacl_Impl_Blake2_Constants_ivTable_B[6U];
  uint64_t iv7 = Hacl_Impl_Blake2_Constants_ivTable_B[7U];
  r20[0U] = Lib_IntVector_Intrinsics_vec256_load64s(iv0, iv1, iv2, iv3);
  r30[0U] = Lib_IntVector_Intrinsics_vec256_load64s(iv4, iv5, iv6, iv7);
  uint64_t kk_shift_8 = (uint64_t)(uint32_t)0U << (uint32_t)8U;
  uint64_t iv0_ = iv0 ^ ((uint64_t)0x01010000U ^ (kk_shift_8 ^ (uint64_t)(uint32_t)64U));
  r00[0U] = Lib_IntVector_Intrinsics_vec256_load64s(iv0_, iv1, iv2, iv3);
  r10[0U] = Lib_IntVector_Intrinsics_vec256_load64s(iv4, iv5, iv6, iv7);
  if (!((uint32_t)0U == (uint32_t)0U))
  {
    memcpy(b, NULL, (uint32_t)0U * sizeof (NULL[0U]));
    FStar_UInt128_uint128
    totlen =
      FStar_UInt128_add_mod(FStar_UInt128_uint64_to_uint128((uint64_t)(uint32_t)0U),
        FStar_UInt128_uint64_to_uint128((uint64_t)(uint32_t)128U));
    uint8_t *b1 = b + (uint32_t)0U * (uint32_t)128U;
    uint64_t m_w[16U] = { 0U };
    for (uint32_t i = (uint32_t)0U; i < (uint32_t)16U; i++)
    {
      uint64_t *os = m_w;
      uint8_t *bj = b1 + i * (uint32_t)8U;
      uint64_t u = load64_le(bj);
      uint64_t r1 = u;
      uint64_t x = r1;
      os[i] = x;
    }
    Lib_IntVector_Intrinsics_vec256 mask = Lib_IntVector_Intrinsics_vec256_zero;
    uint64_t wv_14 = (uint64_t)0U;
    uint64_t wv_15 = (uint64_t)0U;
    mask =
      Lib_IntVector_Intrinsics_vec256_load64s(FStar_UInt128_uint128_to_uint64(totlen),
        FStar_UInt128_uint128_to_uint64(FStar_UInt128_shift_right(totlen, (uint32_t)64U)),
        wv_14,
        wv_15);
    memcpy(block_state.fst,
      block_state.snd,
      (uint32_t)4U * (uint32_t)1U * sizeof (block_state.snd[0U]));
    Lib_IntVector_Intrinsics_vec256 *wv3 = block_state.fst + (uint32_t)3U * (uint32_t)1U;
    wv3[0U] = Lib_IntVector_Intrinsics_vec256_xor(wv3[0U], mask);
    for (uint32_t i = (uint32_t)0U; i < (uint32_t)12U; i++)
    {
      uint32_t start_idx = i % (uint32_t)10U * (uint32_t)16U;
      KRML_CHECK_SIZE(sizeof (Lib_IntVector_Intrinsics_vec256), (uint32_t)4U * (uint32_t)1U);
      Lib_IntVector_Intrinsics_vec256 m_st[(uint32_t)4U * (uint32_t)1U];
      for (uint32_t _i = 0U; _i < (uint32_t)4U * (uint32_t)1U; ++_i)
        m_st[_i] = Lib_IntVector_Intrinsics_vec256_zero;
      Lib_IntVector_Intrinsics_vec256 *r01 = m_st + (uint32_t)0U * (uint32_t)1U;
      Lib_IntVector_Intrinsics_vec256 *r11 = m_st + (uint32_t)1U * (uint32_t)1U;
      Lib_IntVector_Intrinsics_vec256 *r21 = m_st + (uint32_t)2U * (uint32_t)1U;
      Lib_IntVector_Intrinsics_vec256 *r31 = m_st + (uint32_t)3U * (uint32_t)1U;
      uint32_t s0 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx];
      uint32_t s11 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)1U];
      uint32_t s2 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)2U];
      uint32_t s3 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)3U];
      uint32_t s4 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)4U];
      uint32_t s5 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)5U];
      uint32_t s6 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)6U];
      uint32_t s7 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)7U];
      uint32_t s8 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)8U];
      uint32_t s9 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)9U];
      uint32_t s10 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)10U];
      uint32_t s111 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)11U];
      uint32_t s12 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)12U];
      uint32_t s13 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)13U];
      uint32_t s14 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)14U];
      uint32_t s15 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)15U];
      r01[0U] = Lib_IntVector_Intrinsics_vec256_load64s(m_w[s0], m_w[s2], m_w[s4], m_w[s6]);
      r11[0U] = Lib_IntVector_Intrinsics_vec256_load64s(m_w[s11], m_w[s3], m_w[s5], m_w[s7]);
      r21[0U] = Lib_IntVector_Intrinsics_vec256_load64s(m_w[s8], m_w[s10], m_w[s12], m_w[s14]);
      r31[0U] = Lib_IntVector_Intrinsics_vec256_load64s(m_w[s9], m_w[s111], m_w[s13], m_w[s15]);
      Lib_IntVector_Intrinsics_vec256 *x = m_st + (uint32_t)0U * (uint32_t)1U;
      Lib_IntVector_Intrinsics_vec256 *y = m_st + (uint32_t)1U * (uint32_t)1U;
      Lib_IntVector_Intrinsics_vec256 *z = m_st + (uint32_t)2U * (uint32_t)1U;
      Lib_IntVector_Intrinsics_vec256 *w = m_st + (uint32_t)3U * (uint32_t)1U;
      uint32_t a = (uint32_t)0U;
      uint32_t b20 = (uint32_t)1U;
      uint32_t c0 = (uint32_t)2U;
      uint32_t d0 = (uint32_t)3U;
      uint32_t r02 = Hacl_Impl_Blake2_Constants_rTable_B[0U];
      uint32_t r12 = Hacl_Impl_Blake2_Constants_rTable_B[1U];
      uint32_t r22 = Hacl_Impl_Blake2_Constants_rTable_B[2U];
      uint32_t r32 = Hacl_Impl_Blake2_Constants_rTable_B[3U];
      Lib_IntVector_Intrinsics_vec256 *wv_a0 = block_state.fst + a * (uint32_t)1U;
      Lib_IntVector_Intrinsics_vec256 *wv_b0 = block_state.fst + b20 * (uint32_t)1U;
      wv_a0[0U] = Lib_IntVector_Intrinsics_vec256_add64(wv_a0[0U], wv_b0[0U]);
      wv_a0[0U] = Lib_IntVector_Intrinsics_vec256_add64(wv_a0[0U], x[0U]);
      Lib_IntVector_Intrinsics_vec256 *wv_a1 = block_state.fst + d0 * (uint32_t)1U;
      Lib_IntVector_Intrinsics_vec256 *wv_b1 = block_state.fst + a * (uint32_t)1U;
      wv_a1[0U] = Lib_IntVector_Intrinsics_vec256_xor(wv_a1[0U], wv_b1[0U]);
      wv_a1[0U] = Lib_IntVector_Intrinsics_vec256_rotate_right64(wv_a1[0U], r02);
      Lib_IntVector_Intrinsics_vec256 *wv_a2 = block_state.fst + c0 * (uint32_t)1U;
      Lib_IntVector_Intrinsics_vec256 *wv_b2 = block_state.fst + d0 * (uint32_t)1U;
      wv_a2[0U] = Lib_IntVector_Intrinsics_vec256_add64(wv_a2[0U], wv_b2[0U]);
      Lib_IntVector_Intrinsics_vec256 *wv_a3 = block_state.fst + b20 * (uint32_t)1U;
      Lib_IntVector_Intrinsics_vec256 *wv_b3 = block_state.fst + c0 * (uint32_t)1U;
      wv_a3[0U] = Lib_IntVector_Intrinsics_vec256_xor(wv_a3[0U], wv_b3[0U]);
      wv_a3[0U] = Lib_IntVector_Intrinsics_vec256_rotate_right64(wv_a3[0U], r12);
      Lib_IntVector_Intrinsics_vec256 *wv_a4 = block_state.fst + a * (uint32_t)1U;
      Lib_IntVector_Intrinsics_vec256 *wv_b4 = block_state.fst + b20 * (uint32_t)1U;
      wv_a4[0U] = Lib_IntVector_Intrinsics_vec256_add64(wv_a4[0U], wv_b4[0U]);
      wv_a4[0U] = Lib_IntVector_Intrinsics_vec256_add64(wv_a4[0U], y[0U]);
      Lib_IntVector_Intrinsics_vec256 *wv_a5 = block_state.fst + d0 * (uint32_t)1U;
      Lib_IntVector_Intrinsics_vec256 *wv_b5 = block_state.fst + a * (uint32_t)1U;
      wv_a5[0U] = Lib_IntVector_Intrinsics_vec256_xor(wv_a5[0U], wv_b5[0U]);
      wv_a5[0U] = Lib_IntVector_Intrinsics_vec256_rotate_right64(wv_a5[0U], r22);
      Lib_IntVector_Intrinsics_vec256 *wv_a6 = block_state.fst + c0 * (uint32_t)1U;
      Lib_IntVector_Intrinsics_vec256 *wv_b6 = block_state.fst + d0 * (uint32_t)1U;
      wv_a6[0U] = Lib_IntVector_Intrinsics_vec256_add64(wv_a6[0U], wv_b6[0U]);
      Lib_IntVector_Intrinsics_vec256 *wv_a7 = block_state.fst + b20 * (uint32_t)1U;
      Lib_IntVector_Intrinsics_vec256 *wv_b7 = block_state.fst + c0 * (uint32_t)1U;
      wv_a7[0U] = Lib_IntVector_Intrinsics_vec256_xor(wv_a7[0U], wv_b7[0U]);
      wv_a7[0U] = Lib_IntVector_Intrinsics_vec256_rotate_right64(wv_a7[0U], r32);
      Lib_IntVector_Intrinsics_vec256 *r13 = block_state.fst + (uint32_t)1U * (uint32_t)1U;
      Lib_IntVector_Intrinsics_vec256 *r23 = block_state.fst + (uint32_t)2U * (uint32_t)1U;
      Lib_IntVector_Intrinsics_vec256 *r33 = block_state.fst + (uint32_t)3U * (uint32_t)1U;
      Lib_IntVector_Intrinsics_vec256 v00 = r13[0U];
      Lib_IntVector_Intrinsics_vec256
      v1 = Lib_IntVector_Intrinsics_vec256_rotate_right_lanes64(v00, (uint32_t)1U);
      r13[0U] = v1;
      Lib_IntVector_Intrinsics_vec256 v01 = r23[0U];
      Lib_IntVector_Intrinsics_vec256
      v10 = Lib_IntVector_Intrinsics_vec256_rotate_right_lanes64(v01, (uint32_t)2U);
      r23[0U] = v10;
      Lib_IntVector_Intrinsics_vec256 v02 = r33[0U];
      Lib_IntVector_Intrinsics_vec256
      v11 = Lib_IntVector_Intrinsics_vec256_rotate_right_lanes64(v02, (uint32_t)3U);
      r33[0U] = v11;
      uint32_t a0 = (uint32_t)0U;
      uint32_t b2 = (uint32_t)1U;
      uint32_t c = (uint32_t)2U;
      uint32_t d = (uint32_t)3U;
      uint32_t r0 = Hacl_Impl_Blake2_Constants_rTable_B[0U];
      uint32_t r1 = Hacl_Impl_Blake2_Constants_rTable_B[1U];
      uint32_t r24 = Hacl_Impl_Blake2_Constants_rTable_B[2U];
      uint32_t r34 = Hacl_Impl_Blake2_Constants_rTable_B[3U];
      Lib_IntVector_Intrinsics_vec256 *wv_a = block_state.fst + a0 * (uint32_t)1U;
      Lib_IntVector_Intrinsics_vec256 *wv_b8 = block_state.fst + b2 * (uint32_t)1U;
      wv_a[0U] = Lib_IntVector_Intrinsics_vec256_add64(wv_a[0U], wv_b8[0U]);
      wv_a[0U] = Lib_IntVector_Intrinsics_vec256_add64(wv_a[0U], z[0U]);
      Lib_IntVector_Intrinsics_vec256 *wv_a8 = block_state.fst + d * (uint32_t)1U;
      Lib_IntVector_Intrinsics_vec256 *wv_b9 = block_state.fst + a0 * (uint32_t)1U;
      wv_a8[0U] = Lib_IntVector_Intrinsics_vec256_xor(wv_a8[0U], wv_b9[0U]);
      wv_a8[0U] = Lib_IntVector_Intrinsics_vec256_rotate_right64(wv_a8[0U], r0);
      Lib_IntVector_Intrinsics_vec256 *wv_a9 = block_state.fst + c * (uint32_t)1U;
      Lib_IntVector_Intrinsics_vec256 *wv_b10 = block_state.fst + d * (uint32_t)1U;
      wv_a9[0U] = Lib_IntVector_Intrinsics_vec256_add64(wv_a9[0U], wv_b10[0U]);
      Lib_IntVector_Intrinsics_vec256 *wv_a10 = block_state.fst + b2 * (uint32_t)1U;
      Lib_IntVector_Intrinsics_vec256 *wv_b11 = block_state.fst + c * (uint32_t)1U;
      wv_a10[0U] = Lib_IntVector_Intrinsics_vec256_xor(wv_a10[0U], wv_b11[0U]);
      wv_a10[0U] = Lib_IntVector_Intrinsics_vec256_rotate_right64(wv_a10[0U], r1);
      Lib_IntVector_Intrinsics_vec256 *wv_a11 = block_state.fst + a0 * (uint32_t)1U;
      Lib_IntVector_Intrinsics_vec256 *wv_b12 = block_state.fst + b2 * (uint32_t)1U;
      wv_a11[0U] = Lib_IntVector_Intrinsics_vec256_add64(wv_a11[0U], wv_b12[0U]);
      wv_a11[0U] = Lib_IntVector_Intrinsics_vec256_add64(wv_a11[0U], w[0U]);
      Lib_IntVector_Intrinsics_vec256 *wv_a12 = block_state.fst + d * (uint32_t)1U;
      Lib_IntVector_Intrinsics_vec256 *wv_b13 = block_state.fst + a0 * (uint32_t)1U;
      wv_a12[0U] = Lib_IntVector_Intrinsics_vec256_xor(wv_a12[0U], wv_b13[0U]);
      wv_a12[0U] = Lib_IntVector_Intrinsics_vec256_rotate_right64(wv_a12[0U], r24);
      Lib_IntVector_Intrinsics_vec256 *wv_a13 = block_state.fst + c * (uint32_t)1U;
      Lib_IntVector_Intrinsics_vec256 *wv_b14 = block_state.fst + d * (uint32_t)1U;
      wv_a13[0U] = Lib_IntVector_Intrinsics_vec256_add64(wv_a13[0U], wv_b14[0U]);
      Lib_IntVector_Intrinsics_vec256 *wv_a14 = block_state.fst + b2 * (uint32_t)1U;
      Lib_IntVector_Intrinsics_vec256 *wv_b = block_state.fst + c * (uint32_t)1U;
      wv_a14[0U] = Lib_IntVector_Intrinsics_vec256_xor(wv_a14[0U], wv_b[0U]);
      wv_a14[0U] = Lib_IntVector_Intrinsics_vec256_rotate_right64(wv_a14[0U], r34);
      Lib_IntVector_Intrinsics_vec256 *r14 = block_state.fst + (uint32_t)1U * (uint32_t)1U;
      Lib_IntVector_Intrinsics_vec256 *r2 = block_state.fst + (uint32_t)2U * (uint32_t)1U;
      Lib_IntVector_Intrinsics_vec256 *r3 = block_state.fst + (uint32_t)3U * (uint32_t)1U;
      Lib_IntVector_Intrinsics_vec256 v0 = r14[0U];
      Lib_IntVector_Intrinsics_vec256
      v12 = Lib_IntVector_Intrinsics_vec256_rotate_right_lanes64(v0, (uint32_t)3U);
      r14[0U] = v12;
      Lib_IntVector_Intrinsics_vec256 v03 = r2[0U];
      Lib_IntVector_Intrinsics_vec256
      v13 = Lib_IntVector_Intrinsics_vec256_rotate_right_lanes64(v03, (uint32_t)2U);
      r2[0U] = v13;
      Lib_IntVector_Intrinsics_vec256 v04 = r3[0U];
      Lib_IntVector_Intrinsics_vec256
      v14 = Lib_IntVector_Intrinsics_vec256_rotate_right_lanes64(v04, (uint32_t)1U);
      r3[0U] = v14;
    }
    Lib_IntVector_Intrinsics_vec256 *s0 = block_state.snd + (uint32_t)0U * (uint32_t)1U;
    Lib_IntVector_Intrinsics_vec256 *s11 = block_state.snd + (uint32_t)1U * (uint32_t)1U;
    Lib_IntVector_Intrinsics_vec256 *r0 = block_state.fst + (uint32_t)0U * (uint32_t)1U;
    Lib_IntVector_Intrinsics_vec256 *r1 = block_state.fst + (uint32_t)1U * (uint32_t)1U;
    Lib_IntVector_Intrinsics_vec256 *r2 = block_state.fst + (uint32_t)2U * (uint32_t)1U;
    Lib_IntVector_Intrinsics_vec256 *r3 = block_state.fst + (uint32_t)3U * (uint32_t)1U;
    s0[0U] = Lib_IntVector_Intrinsics_vec256_xor(s0[0U], r0[0U]);
    s0[0U] = Lib_IntVector_Intrinsics_vec256_xor(s0[0U], r2[0U]);
    s11[0U] = Lib_IntVector_Intrinsics_vec256_xor(s11[0U], r1[0U]);
    s11[0U] = Lib_IntVector_Intrinsics_vec256_xor(s11[0U], r3[0U]);
  }
  Lib_Memzero0_memzero(b, (uint32_t)128U * sizeof (b[0U]));
  return p;
}

/* SNIPPET_END: Hacl_Streaming_Blake2_blake2b_256_no_key_create_in */

/* SNIPPET_START: Hacl_Streaming_Blake2_blake2b_256_no_key_update */

/*
  Update function when there is no key
*/
void
Hacl_Streaming_Blake2_blake2b_256_no_key_update(
  Hacl_Streaming_Functor_state_s__K____Lib_IntVector_Intrinsics_vec256___Lib_IntVector_Intrinsics_vec256____
  *p,
  uint8_t *data,
  uint32_t len
)
{
  Hacl_Streaming_Functor_state_s__K____Lib_IntVector_Intrinsics_vec256___Lib_IntVector_Intrinsics_vec256____
  s1 = *p;
  uint64_t total_len = s1.total_len;
  uint32_t sz;
  if (total_len % (uint64_t)(uint32_t)128U == (uint64_t)0U && total_len > (uint64_t)0U)
  {
    sz = (uint32_t)128U;
  }
  else
  {
    sz = (uint32_t)(total_len % (uint64_t)(uint32_t)128U);
  }
  if (len <= (uint32_t)128U - sz)
  {
    Hacl_Streaming_Functor_state_s__K____Lib_IntVector_Intrinsics_vec256___Lib_IntVector_Intrinsics_vec256____
    s2 = *p;
    K____Lib_IntVector_Intrinsics_vec256___Lib_IntVector_Intrinsics_vec256_
    block_state1 = s2.block_state;
    uint8_t *buf = s2.buf;
    uint64_t total_len1 = s2.total_len;
    uint32_t sz1;
    if (total_len1 % (uint64_t)(uint32_t)128U == (uint64_t)0U && total_len1 > (uint64_t)0U)
    {
      sz1 = (uint32_t)128U;
    }
    else
    {
      sz1 = (uint32_t)(total_len1 % (uint64_t)(uint32_t)128U);
    }
    uint8_t *buf2 = buf + sz1;
    memcpy(buf2, data, len * sizeof (data[0U]));
    uint64_t total_len2 = total_len1 + (uint64_t)len;
    *p
    =
      (
        (Hacl_Streaming_Functor_state_s__K____Lib_IntVector_Intrinsics_vec256___Lib_IntVector_Intrinsics_vec256____){
          .block_state = block_state1,
          .buf = buf,
          .total_len = total_len2
        }
      );
    return;
  }
  if (sz == (uint32_t)0U)
  {
    Hacl_Streaming_Functor_state_s__K____Lib_IntVector_Intrinsics_vec256___Lib_IntVector_Intrinsics_vec256____
    s2 = *p;
    K____Lib_IntVector_Intrinsics_vec256___Lib_IntVector_Intrinsics_vec256_
    block_state1 = s2.block_state;
    uint8_t *buf = s2.buf;
    uint64_t total_len1 = s2.total_len;
    uint32_t sz1;
    if (total_len1 % (uint64_t)(uint32_t)128U == (uint64_t)0U && total_len1 > (uint64_t)0U)
    {
      sz1 = (uint32_t)128U;
    }
    else
    {
      sz1 = (uint32_t)(total_len1 % (uint64_t)(uint32_t)128U);
    }
    if (!(sz1 == (uint32_t)0U))
    {
      uint64_t prevlen = total_len1 - (uint64_t)sz1;
      uint32_t nb = (uint32_t)1U;
      for (uint32_t i0 = (uint32_t)0U; i0 < nb; i0++)
      {
        uint64_t ite;
        if ((uint32_t)0U == (uint32_t)0U)
        {
          ite = prevlen;
        }
        else
        {
          ite = prevlen + (uint64_t)(uint32_t)128U;
        }
        FStar_UInt128_uint128
        totlen =
          FStar_UInt128_add_mod(FStar_UInt128_uint64_to_uint128(ite),
            FStar_UInt128_uint64_to_uint128((uint64_t)((i0 + (uint32_t)1U) * (uint32_t)128U)));
        uint8_t *b = buf + i0 * (uint32_t)128U;
        uint64_t m_w[16U] = { 0U };
        for (uint32_t i = (uint32_t)0U; i < (uint32_t)16U; i++)
        {
          uint64_t *os = m_w;
          uint8_t *bj = b + i * (uint32_t)8U;
          uint64_t u = load64_le(bj);
          uint64_t r = u;
          uint64_t x = r;
          os[i] = x;
        }
        Lib_IntVector_Intrinsics_vec256 mask = Lib_IntVector_Intrinsics_vec256_zero;
        uint64_t wv_14 = (uint64_t)0U;
        uint64_t wv_15 = (uint64_t)0U;
        mask =
          Lib_IntVector_Intrinsics_vec256_load64s(FStar_UInt128_uint128_to_uint64(totlen),
            FStar_UInt128_uint128_to_uint64(FStar_UInt128_shift_right(totlen, (uint32_t)64U)),
            wv_14,
            wv_15);
        memcpy(block_state1.fst,
          block_state1.snd,
          (uint32_t)4U * (uint32_t)1U * sizeof (block_state1.snd[0U]));
        Lib_IntVector_Intrinsics_vec256 *wv3 = block_state1.fst + (uint32_t)3U * (uint32_t)1U;
        wv3[0U] = Lib_IntVector_Intrinsics_vec256_xor(wv3[0U], mask);
        for (uint32_t i = (uint32_t)0U; i < (uint32_t)12U; i++)
        {
          uint32_t start_idx = i % (uint32_t)10U * (uint32_t)16U;
          KRML_CHECK_SIZE(sizeof (Lib_IntVector_Intrinsics_vec256), (uint32_t)4U * (uint32_t)1U);
          Lib_IntVector_Intrinsics_vec256 m_st[(uint32_t)4U * (uint32_t)1U];
          for (uint32_t _i = 0U; _i < (uint32_t)4U * (uint32_t)1U; ++_i)
            m_st[_i] = Lib_IntVector_Intrinsics_vec256_zero;
          Lib_IntVector_Intrinsics_vec256 *r00 = m_st + (uint32_t)0U * (uint32_t)1U;
          Lib_IntVector_Intrinsics_vec256 *r10 = m_st + (uint32_t)1U * (uint32_t)1U;
          Lib_IntVector_Intrinsics_vec256 *r20 = m_st + (uint32_t)2U * (uint32_t)1U;
          Lib_IntVector_Intrinsics_vec256 *r30 = m_st + (uint32_t)3U * (uint32_t)1U;
          uint32_t s0 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx];
          uint32_t s11 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)1U];
          uint32_t s21 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)2U];
          uint32_t s3 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)3U];
          uint32_t s4 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)4U];
          uint32_t s5 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)5U];
          uint32_t s6 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)6U];
          uint32_t s7 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)7U];
          uint32_t s8 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)8U];
          uint32_t s9 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)9U];
          uint32_t s10 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)10U];
          uint32_t s111 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)11U];
          uint32_t s12 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)12U];
          uint32_t s13 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)13U];
          uint32_t s14 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)14U];
          uint32_t s15 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)15U];
          r00[0U] = Lib_IntVector_Intrinsics_vec256_load64s(m_w[s0], m_w[s21], m_w[s4], m_w[s6]);
          r10[0U] = Lib_IntVector_Intrinsics_vec256_load64s(m_w[s11], m_w[s3], m_w[s5], m_w[s7]);
          r20[0U] = Lib_IntVector_Intrinsics_vec256_load64s(m_w[s8], m_w[s10], m_w[s12], m_w[s14]);
          r30[0U] = Lib_IntVector_Intrinsics_vec256_load64s(m_w[s9], m_w[s111], m_w[s13], m_w[s15]);
          Lib_IntVector_Intrinsics_vec256 *x = m_st + (uint32_t)0U * (uint32_t)1U;
          Lib_IntVector_Intrinsics_vec256 *y = m_st + (uint32_t)1U * (uint32_t)1U;
          Lib_IntVector_Intrinsics_vec256 *z = m_st + (uint32_t)2U * (uint32_t)1U;
          Lib_IntVector_Intrinsics_vec256 *w = m_st + (uint32_t)3U * (uint32_t)1U;
          uint32_t a = (uint32_t)0U;
          uint32_t b10 = (uint32_t)1U;
          uint32_t c0 = (uint32_t)2U;
          uint32_t d0 = (uint32_t)3U;
          uint32_t r01 = Hacl_Impl_Blake2_Constants_rTable_B[0U];
          uint32_t r11 = Hacl_Impl_Blake2_Constants_rTable_B[1U];
          uint32_t r21 = Hacl_Impl_Blake2_Constants_rTable_B[2U];
          uint32_t r31 = Hacl_Impl_Blake2_Constants_rTable_B[3U];
          Lib_IntVector_Intrinsics_vec256 *wv_a0 = block_state1.fst + a * (uint32_t)1U;
          Lib_IntVector_Intrinsics_vec256 *wv_b0 = block_state1.fst + b10 * (uint32_t)1U;
          wv_a0[0U] = Lib_IntVector_Intrinsics_vec256_add64(wv_a0[0U], wv_b0[0U]);
          wv_a0[0U] = Lib_IntVector_Intrinsics_vec256_add64(wv_a0[0U], x[0U]);
          Lib_IntVector_Intrinsics_vec256 *wv_a1 = block_state1.fst + d0 * (uint32_t)1U;
          Lib_IntVector_Intrinsics_vec256 *wv_b1 = block_state1.fst + a * (uint32_t)1U;
          wv_a1[0U] = Lib_IntVector_Intrinsics_vec256_xor(wv_a1[0U], wv_b1[0U]);
          wv_a1[0U] = Lib_IntVector_Intrinsics_vec256_rotate_right64(wv_a1[0U], r01);
          Lib_IntVector_Intrinsics_vec256 *wv_a2 = block_state1.fst + c0 * (uint32_t)1U;
          Lib_IntVector_Intrinsics_vec256 *wv_b2 = block_state1.fst + d0 * (uint32_t)1U;
          wv_a2[0U] = Lib_IntVector_Intrinsics_vec256_add64(wv_a2[0U], wv_b2[0U]);
          Lib_IntVector_Intrinsics_vec256 *wv_a3 = block_state1.fst + b10 * (uint32_t)1U;
          Lib_IntVector_Intrinsics_vec256 *wv_b3 = block_state1.fst + c0 * (uint32_t)1U;
          wv_a3[0U] = Lib_IntVector_Intrinsics_vec256_xor(wv_a3[0U], wv_b3[0U]);
          wv_a3[0U] = Lib_IntVector_Intrinsics_vec256_rotate_right64(wv_a3[0U], r11);
          Lib_IntVector_Intrinsics_vec256 *wv_a4 = block_state1.fst + a * (uint32_t)1U;
          Lib_IntVector_Intrinsics_vec256 *wv_b4 = block_state1.fst + b10 * (uint32_t)1U;
          wv_a4[0U] = Lib_IntVector_Intrinsics_vec256_add64(wv_a4[0U], wv_b4[0U]);
          wv_a4[0U] = Lib_IntVector_Intrinsics_vec256_add64(wv_a4[0U], y[0U]);
          Lib_IntVector_Intrinsics_vec256 *wv_a5 = block_state1.fst + d0 * (uint32_t)1U;
          Lib_IntVector_Intrinsics_vec256 *wv_b5 = block_state1.fst + a * (uint32_t)1U;
          wv_a5[0U] = Lib_IntVector_Intrinsics_vec256_xor(wv_a5[0U], wv_b5[0U]);
          wv_a5[0U] = Lib_IntVector_Intrinsics_vec256_rotate_right64(wv_a5[0U], r21);
          Lib_IntVector_Intrinsics_vec256 *wv_a6 = block_state1.fst + c0 * (uint32_t)1U;
          Lib_IntVector_Intrinsics_vec256 *wv_b6 = block_state1.fst + d0 * (uint32_t)1U;
          wv_a6[0U] = Lib_IntVector_Intrinsics_vec256_add64(wv_a6[0U], wv_b6[0U]);
          Lib_IntVector_Intrinsics_vec256 *wv_a7 = block_state1.fst + b10 * (uint32_t)1U;
          Lib_IntVector_Intrinsics_vec256 *wv_b7 = block_state1.fst + c0 * (uint32_t)1U;
          wv_a7[0U] = Lib_IntVector_Intrinsics_vec256_xor(wv_a7[0U], wv_b7[0U]);
          wv_a7[0U] = Lib_IntVector_Intrinsics_vec256_rotate_right64(wv_a7[0U], r31);
          Lib_IntVector_Intrinsics_vec256 *r12 = block_state1.fst + (uint32_t)1U * (uint32_t)1U;
          Lib_IntVector_Intrinsics_vec256 *r22 = block_state1.fst + (uint32_t)2U * (uint32_t)1U;
          Lib_IntVector_Intrinsics_vec256 *r32 = block_state1.fst + (uint32_t)3U * (uint32_t)1U;
          Lib_IntVector_Intrinsics_vec256 v00 = r12[0U];
          Lib_IntVector_Intrinsics_vec256
          v1 = Lib_IntVector_Intrinsics_vec256_rotate_right_lanes64(v00, (uint32_t)1U);
          r12[0U] = v1;
          Lib_IntVector_Intrinsics_vec256 v01 = r22[0U];
          Lib_IntVector_Intrinsics_vec256
          v10 = Lib_IntVector_Intrinsics_vec256_rotate_right_lanes64(v01, (uint32_t)2U);
          r22[0U] = v10;
          Lib_IntVector_Intrinsics_vec256 v02 = r32[0U];
          Lib_IntVector_Intrinsics_vec256
          v11 = Lib_IntVector_Intrinsics_vec256_rotate_right_lanes64(v02, (uint32_t)3U);
          r32[0U] = v11;
          uint32_t a0 = (uint32_t)0U;
          uint32_t b1 = (uint32_t)1U;
          uint32_t c = (uint32_t)2U;
          uint32_t d = (uint32_t)3U;
          uint32_t r0 = Hacl_Impl_Blake2_Constants_rTable_B[0U];
          uint32_t r1 = Hacl_Impl_Blake2_Constants_rTable_B[1U];
          uint32_t r23 = Hacl_Impl_Blake2_Constants_rTable_B[2U];
          uint32_t r33 = Hacl_Impl_Blake2_Constants_rTable_B[3U];
          Lib_IntVector_Intrinsics_vec256 *wv_a = block_state1.fst + a0 * (uint32_t)1U;
          Lib_IntVector_Intrinsics_vec256 *wv_b8 = block_state1.fst + b1 * (uint32_t)1U;
          wv_a[0U] = Lib_IntVector_Intrinsics_vec256_add64(wv_a[0U], wv_b8[0U]);
          wv_a[0U] = Lib_IntVector_Intrinsics_vec256_add64(wv_a[0U], z[0U]);
          Lib_IntVector_Intrinsics_vec256 *wv_a8 = block_state1.fst + d * (uint32_t)1U;
          Lib_IntVector_Intrinsics_vec256 *wv_b9 = block_state1.fst + a0 * (uint32_t)1U;
          wv_a8[0U] = Lib_IntVector_Intrinsics_vec256_xor(wv_a8[0U], wv_b9[0U]);
          wv_a8[0U] = Lib_IntVector_Intrinsics_vec256_rotate_right64(wv_a8[0U], r0);
          Lib_IntVector_Intrinsics_vec256 *wv_a9 = block_state1.fst + c * (uint32_t)1U;
          Lib_IntVector_Intrinsics_vec256 *wv_b10 = block_state1.fst + d * (uint32_t)1U;
          wv_a9[0U] = Lib_IntVector_Intrinsics_vec256_add64(wv_a9[0U], wv_b10[0U]);
          Lib_IntVector_Intrinsics_vec256 *wv_a10 = block_state1.fst + b1 * (uint32_t)1U;
          Lib_IntVector_Intrinsics_vec256 *wv_b11 = block_state1.fst + c * (uint32_t)1U;
          wv_a10[0U] = Lib_IntVector_Intrinsics_vec256_xor(wv_a10[0U], wv_b11[0U]);
          wv_a10[0U] = Lib_IntVector_Intrinsics_vec256_rotate_right64(wv_a10[0U], r1);
          Lib_IntVector_Intrinsics_vec256 *wv_a11 = block_state1.fst + a0 * (uint32_t)1U;
          Lib_IntVector_Intrinsics_vec256 *wv_b12 = block_state1.fst + b1 * (uint32_t)1U;
          wv_a11[0U] = Lib_IntVector_Intrinsics_vec256_add64(wv_a11[0U], wv_b12[0U]);
          wv_a11[0U] = Lib_IntVector_Intrinsics_vec256_add64(wv_a11[0U], w[0U]);
          Lib_IntVector_Intrinsics_vec256 *wv_a12 = block_state1.fst + d * (uint32_t)1U;
          Lib_IntVector_Intrinsics_vec256 *wv_b13 = block_state1.fst + a0 * (uint32_t)1U;
          wv_a12[0U] = Lib_IntVector_Intrinsics_vec256_xor(wv_a12[0U], wv_b13[0U]);
          wv_a12[0U] = Lib_IntVector_Intrinsics_vec256_rotate_right64(wv_a12[0U], r23);
          Lib_IntVector_Intrinsics_vec256 *wv_a13 = block_state1.fst + c * (uint32_t)1U;
          Lib_IntVector_Intrinsics_vec256 *wv_b14 = block_state1.fst + d * (uint32_t)1U;
          wv_a13[0U] = Lib_IntVector_Intrinsics_vec256_add64(wv_a13[0U], wv_b14[0U]);
          Lib_IntVector_Intrinsics_vec256 *wv_a14 = block_state1.fst + b1 * (uint32_t)1U;
          Lib_IntVector_Intrinsics_vec256 *wv_b = block_state1.fst + c * (uint32_t)1U;
          wv_a14[0U] = Lib_IntVector_Intrinsics_vec256_xor(wv_a14[0U], wv_b[0U]);
          wv_a14[0U] = Lib_IntVector_Intrinsics_vec256_rotate_right64(wv_a14[0U], r33);
          Lib_IntVector_Intrinsics_vec256 *r13 = block_state1.fst + (uint32_t)1U * (uint32_t)1U;
          Lib_IntVector_Intrinsics_vec256 *r2 = block_state1.fst + (uint32_t)2U * (uint32_t)1U;
          Lib_IntVector_Intrinsics_vec256 *r3 = block_state1.fst + (uint32_t)3U * (uint32_t)1U;
          Lib_IntVector_Intrinsics_vec256 v0 = r13[0U];
          Lib_IntVector_Intrinsics_vec256
          v12 = Lib_IntVector_Intrinsics_vec256_rotate_right_lanes64(v0, (uint32_t)3U);
          r13[0U] = v12;
          Lib_IntVector_Intrinsics_vec256 v03 = r2[0U];
          Lib_IntVector_Intrinsics_vec256
          v13 = Lib_IntVector_Intrinsics_vec256_rotate_right_lanes64(v03, (uint32_t)2U);
          r2[0U] = v13;
          Lib_IntVector_Intrinsics_vec256 v04 = r3[0U];
          Lib_IntVector_Intrinsics_vec256
          v14 = Lib_IntVector_Intrinsics_vec256_rotate_right_lanes64(v04, (uint32_t)1U);
          r3[0U] = v14;
        }
        Lib_IntVector_Intrinsics_vec256 *s0 = block_state1.snd + (uint32_t)0U * (uint32_t)1U;
        Lib_IntVector_Intrinsics_vec256 *s11 = block_state1.snd + (uint32_t)1U * (uint32_t)1U;
        Lib_IntVector_Intrinsics_vec256 *r0 = block_state1.fst + (uint32_t)0U * (uint32_t)1U;
        Lib_IntVector_Intrinsics_vec256 *r1 = block_state1.fst + (uint32_t)1U * (uint32_t)1U;
        Lib_IntVector_Intrinsics_vec256 *r2 = block_state1.fst + (uint32_t)2U * (uint32_t)1U;
        Lib_IntVector_Intrinsics_vec256 *r3 = block_state1.fst + (uint32_t)3U * (uint32_t)1U;
        s0[0U] = Lib_IntVector_Intrinsics_vec256_xor(s0[0U], r0[0U]);
        s0[0U] = Lib_IntVector_Intrinsics_vec256_xor(s0[0U], r2[0U]);
        s11[0U] = Lib_IntVector_Intrinsics_vec256_xor(s11[0U], r1[0U]);
        s11[0U] = Lib_IntVector_Intrinsics_vec256_xor(s11[0U], r3[0U]);
      }
    }
    uint32_t ite0;
    if ((uint64_t)len % (uint64_t)(uint32_t)128U == (uint64_t)0U && (uint64_t)len > (uint64_t)0U)
    {
      ite0 = (uint32_t)128U;
    }
    else
    {
      ite0 = (uint32_t)((uint64_t)len % (uint64_t)(uint32_t)128U);
    }
    uint32_t n_blocks = (len - ite0) / (uint32_t)128U;
    uint32_t data1_len = n_blocks * (uint32_t)128U;
    uint32_t data2_len = len - data1_len;
    uint8_t *data1 = data;
    uint8_t *data2 = data + data1_len;
    uint32_t nb = data1_len / (uint32_t)128U;
    for (uint32_t i0 = (uint32_t)0U; i0 < nb; i0++)
    {
      uint64_t ite;
      if ((uint32_t)0U == (uint32_t)0U)
      {
        ite = total_len1;
      }
      else
      {
        ite = total_len1 + (uint64_t)(uint32_t)128U;
      }
      FStar_UInt128_uint128
      totlen =
        FStar_UInt128_add_mod(FStar_UInt128_uint64_to_uint128(ite),
          FStar_UInt128_uint64_to_uint128((uint64_t)((i0 + (uint32_t)1U) * (uint32_t)128U)));
      uint8_t *b = data1 + i0 * (uint32_t)128U;
      uint64_t m_w[16U] = { 0U };
      for (uint32_t i = (uint32_t)0U; i < (uint32_t)16U; i++)
      {
        uint64_t *os = m_w;
        uint8_t *bj = b + i * (uint32_t)8U;
        uint64_t u = load64_le(bj);
        uint64_t r = u;
        uint64_t x = r;
        os[i] = x;
      }
      Lib_IntVector_Intrinsics_vec256 mask = Lib_IntVector_Intrinsics_vec256_zero;
      uint64_t wv_14 = (uint64_t)0U;
      uint64_t wv_15 = (uint64_t)0U;
      mask =
        Lib_IntVector_Intrinsics_vec256_load64s(FStar_UInt128_uint128_to_uint64(totlen),
          FStar_UInt128_uint128_to_uint64(FStar_UInt128_shift_right(totlen, (uint32_t)64U)),
          wv_14,
          wv_15);
      memcpy(block_state1.fst,
        block_state1.snd,
        (uint32_t)4U * (uint32_t)1U * sizeof (block_state1.snd[0U]));
      Lib_IntVector_Intrinsics_vec256 *wv3 = block_state1.fst + (uint32_t)3U * (uint32_t)1U;
      wv3[0U] = Lib_IntVector_Intrinsics_vec256_xor(wv3[0U], mask);
      for (uint32_t i = (uint32_t)0U; i < (uint32_t)12U; i++)
      {
        uint32_t start_idx = i % (uint32_t)10U * (uint32_t)16U;
        KRML_CHECK_SIZE(sizeof (Lib_IntVector_Intrinsics_vec256), (uint32_t)4U * (uint32_t)1U);
        Lib_IntVector_Intrinsics_vec256 m_st[(uint32_t)4U * (uint32_t)1U];
        for (uint32_t _i = 0U; _i < (uint32_t)4U * (uint32_t)1U; ++_i)
          m_st[_i] = Lib_IntVector_Intrinsics_vec256_zero;
        Lib_IntVector_Intrinsics_vec256 *r00 = m_st + (uint32_t)0U * (uint32_t)1U;
        Lib_IntVector_Intrinsics_vec256 *r10 = m_st + (uint32_t)1U * (uint32_t)1U;
        Lib_IntVector_Intrinsics_vec256 *r20 = m_st + (uint32_t)2U * (uint32_t)1U;
        Lib_IntVector_Intrinsics_vec256 *r30 = m_st + (uint32_t)3U * (uint32_t)1U;
        uint32_t s0 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx];
        uint32_t s11 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)1U];
        uint32_t s21 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)2U];
        uint32_t s3 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)3U];
        uint32_t s4 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)4U];
        uint32_t s5 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)5U];
        uint32_t s6 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)6U];
        uint32_t s7 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)7U];
        uint32_t s8 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)8U];
        uint32_t s9 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)9U];
        uint32_t s10 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)10U];
        uint32_t s111 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)11U];
        uint32_t s12 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)12U];
        uint32_t s13 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)13U];
        uint32_t s14 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)14U];
        uint32_t s15 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)15U];
        r00[0U] = Lib_IntVector_Intrinsics_vec256_load64s(m_w[s0], m_w[s21], m_w[s4], m_w[s6]);
        r10[0U] = Lib_IntVector_Intrinsics_vec256_load64s(m_w[s11], m_w[s3], m_w[s5], m_w[s7]);
        r20[0U] = Lib_IntVector_Intrinsics_vec256_load64s(m_w[s8], m_w[s10], m_w[s12], m_w[s14]);
        r30[0U] = Lib_IntVector_Intrinsics_vec256_load64s(m_w[s9], m_w[s111], m_w[s13], m_w[s15]);
        Lib_IntVector_Intrinsics_vec256 *x = m_st + (uint32_t)0U * (uint32_t)1U;
        Lib_IntVector_Intrinsics_vec256 *y = m_st + (uint32_t)1U * (uint32_t)1U;
        Lib_IntVector_Intrinsics_vec256 *z = m_st + (uint32_t)2U * (uint32_t)1U;
        Lib_IntVector_Intrinsics_vec256 *w = m_st + (uint32_t)3U * (uint32_t)1U;
        uint32_t a = (uint32_t)0U;
        uint32_t b10 = (uint32_t)1U;
        uint32_t c0 = (uint32_t)2U;
        uint32_t d0 = (uint32_t)3U;
        uint32_t r01 = Hacl_Impl_Blake2_Constants_rTable_B[0U];
        uint32_t r11 = Hacl_Impl_Blake2_Constants_rTable_B[1U];
        uint32_t r21 = Hacl_Impl_Blake2_Constants_rTable_B[2U];
        uint32_t r31 = Hacl_Impl_Blake2_Constants_rTable_B[3U];
        Lib_IntVector_Intrinsics_vec256 *wv_a0 = block_state1.fst + a * (uint32_t)1U;
        Lib_IntVector_Intrinsics_vec256 *wv_b0 = block_state1.fst + b10 * (uint32_t)1U;
        wv_a0[0U] = Lib_IntVector_Intrinsics_vec256_add64(wv_a0[0U], wv_b0[0U]);
        wv_a0[0U] = Lib_IntVector_Intrinsics_vec256_add64(wv_a0[0U], x[0U]);
        Lib_IntVector_Intrinsics_vec256 *wv_a1 = block_state1.fst + d0 * (uint32_t)1U;
        Lib_IntVector_Intrinsics_vec256 *wv_b1 = block_state1.fst + a * (uint32_t)1U;
        wv_a1[0U] = Lib_IntVector_Intrinsics_vec256_xor(wv_a1[0U], wv_b1[0U]);
        wv_a1[0U] = Lib_IntVector_Intrinsics_vec256_rotate_right64(wv_a1[0U], r01);
        Lib_IntVector_Intrinsics_vec256 *wv_a2 = block_state1.fst + c0 * (uint32_t)1U;
        Lib_IntVector_Intrinsics_vec256 *wv_b2 = block_state1.fst + d0 * (uint32_t)1U;
        wv_a2[0U] = Lib_IntVector_Intrinsics_vec256_add64(wv_a2[0U], wv_b2[0U]);
        Lib_IntVector_Intrinsics_vec256 *wv_a3 = block_state1.fst + b10 * (uint32_t)1U;
        Lib_IntVector_Intrinsics_vec256 *wv_b3 = block_state1.fst + c0 * (uint32_t)1U;
        wv_a3[0U] = Lib_IntVector_Intrinsics_vec256_xor(wv_a3[0U], wv_b3[0U]);
        wv_a3[0U] = Lib_IntVector_Intrinsics_vec256_rotate_right64(wv_a3[0U], r11);
        Lib_IntVector_Intrinsics_vec256 *wv_a4 = block_state1.fst + a * (uint32_t)1U;
        Lib_IntVector_Intrinsics_vec256 *wv_b4 = block_state1.fst + b10 * (uint32_t)1U;
        wv_a4[0U] = Lib_IntVector_Intrinsics_vec256_add64(wv_a4[0U], wv_b4[0U]);
        wv_a4[0U] = Lib_IntVector_Intrinsics_vec256_add64(wv_a4[0U], y[0U]);
        Lib_IntVector_Intrinsics_vec256 *wv_a5 = block_state1.fst + d0 * (uint32_t)1U;
        Lib_IntVector_Intrinsics_vec256 *wv_b5 = block_state1.fst + a * (uint32_t)1U;
        wv_a5[0U] = Lib_IntVector_Intrinsics_vec256_xor(wv_a5[0U], wv_b5[0U]);
        wv_a5[0U] = Lib_IntVector_Intrinsics_vec256_rotate_right64(wv_a5[0U], r21);
        Lib_IntVector_Intrinsics_vec256 *wv_a6 = block_state1.fst + c0 * (uint32_t)1U;
        Lib_IntVector_Intrinsics_vec256 *wv_b6 = block_state1.fst + d0 * (uint32_t)1U;
        wv_a6[0U] = Lib_IntVector_Intrinsics_vec256_add64(wv_a6[0U], wv_b6[0U]);
        Lib_IntVector_Intrinsics_vec256 *wv_a7 = block_state1.fst + b10 * (uint32_t)1U;
        Lib_IntVector_Intrinsics_vec256 *wv_b7 = block_state1.fst + c0 * (uint32_t)1U;
        wv_a7[0U] = Lib_IntVector_Intrinsics_vec256_xor(wv_a7[0U], wv_b7[0U]);
        wv_a7[0U] = Lib_IntVector_Intrinsics_vec256_rotate_right64(wv_a7[0U], r31);
        Lib_IntVector_Intrinsics_vec256 *r12 = block_state1.fst + (uint32_t)1U * (uint32_t)1U;
        Lib_IntVector_Intrinsics_vec256 *r22 = block_state1.fst + (uint32_t)2U * (uint32_t)1U;
        Lib_IntVector_Intrinsics_vec256 *r32 = block_state1.fst + (uint32_t)3U * (uint32_t)1U;
        Lib_IntVector_Intrinsics_vec256 v00 = r12[0U];
        Lib_IntVector_Intrinsics_vec256
        v1 = Lib_IntVector_Intrinsics_vec256_rotate_right_lanes64(v00, (uint32_t)1U);
        r12[0U] = v1;
        Lib_IntVector_Intrinsics_vec256 v01 = r22[0U];
        Lib_IntVector_Intrinsics_vec256
        v10 = Lib_IntVector_Intrinsics_vec256_rotate_right_lanes64(v01, (uint32_t)2U);
        r22[0U] = v10;
        Lib_IntVector_Intrinsics_vec256 v02 = r32[0U];
        Lib_IntVector_Intrinsics_vec256
        v11 = Lib_IntVector_Intrinsics_vec256_rotate_right_lanes64(v02, (uint32_t)3U);
        r32[0U] = v11;
        uint32_t a0 = (uint32_t)0U;
        uint32_t b1 = (uint32_t)1U;
        uint32_t c = (uint32_t)2U;
        uint32_t d = (uint32_t)3U;
        uint32_t r0 = Hacl_Impl_Blake2_Constants_rTable_B[0U];
        uint32_t r1 = Hacl_Impl_Blake2_Constants_rTable_B[1U];
        uint32_t r23 = Hacl_Impl_Blake2_Constants_rTable_B[2U];
        uint32_t r33 = Hacl_Impl_Blake2_Constants_rTable_B[3U];
        Lib_IntVector_Intrinsics_vec256 *wv_a = block_state1.fst + a0 * (uint32_t)1U;
        Lib_IntVector_Intrinsics_vec256 *wv_b8 = block_state1.fst + b1 * (uint32_t)1U;
        wv_a[0U] = Lib_IntVector_Intrinsics_vec256_add64(wv_a[0U], wv_b8[0U]);
        wv_a[0U] = Lib_IntVector_Intrinsics_vec256_add64(wv_a[0U], z[0U]);
        Lib_IntVector_Intrinsics_vec256 *wv_a8 = block_state1.fst + d * (uint32_t)1U;
        Lib_IntVector_Intrinsics_vec256 *wv_b9 = block_state1.fst + a0 * (uint32_t)1U;
        wv_a8[0U] = Lib_IntVector_Intrinsics_vec256_xor(wv_a8[0U], wv_b9[0U]);
        wv_a8[0U] = Lib_IntVector_Intrinsics_vec256_rotate_right64(wv_a8[0U], r0);
        Lib_IntVector_Intrinsics_vec256 *wv_a9 = block_state1.fst + c * (uint32_t)1U;
        Lib_IntVector_Intrinsics_vec256 *wv_b10 = block_state1.fst + d * (uint32_t)1U;
        wv_a9[0U] = Lib_IntVector_Intrinsics_vec256_add64(wv_a9[0U], wv_b10[0U]);
        Lib_IntVector_Intrinsics_vec256 *wv_a10 = block_state1.fst + b1 * (uint32_t)1U;
        Lib_IntVector_Intrinsics_vec256 *wv_b11 = block_state1.fst + c * (uint32_t)1U;
        wv_a10[0U] = Lib_IntVector_Intrinsics_vec256_xor(wv_a10[0U], wv_b11[0U]);
        wv_a10[0U] = Lib_IntVector_Intrinsics_vec256_rotate_right64(wv_a10[0U], r1);
        Lib_IntVector_Intrinsics_vec256 *wv_a11 = block_state1.fst + a0 * (uint32_t)1U;
        Lib_IntVector_Intrinsics_vec256 *wv_b12 = block_state1.fst + b1 * (uint32_t)1U;
        wv_a11[0U] = Lib_IntVector_Intrinsics_vec256_add64(wv_a11[0U], wv_b12[0U]);
        wv_a11[0U] = Lib_IntVector_Intrinsics_vec256_add64(wv_a11[0U], w[0U]);
        Lib_IntVector_Intrinsics_vec256 *wv_a12 = block_state1.fst + d * (uint32_t)1U;
        Lib_IntVector_Intrinsics_vec256 *wv_b13 = block_state1.fst + a0 * (uint32_t)1U;
        wv_a12[0U] = Lib_IntVector_Intrinsics_vec256_xor(wv_a12[0U], wv_b13[0U]);
        wv_a12[0U] = Lib_IntVector_Intrinsics_vec256_rotate_right64(wv_a12[0U], r23);
        Lib_IntVector_Intrinsics_vec256 *wv_a13 = block_state1.fst + c * (uint32_t)1U;
        Lib_IntVector_Intrinsics_vec256 *wv_b14 = block_state1.fst + d * (uint32_t)1U;
        wv_a13[0U] = Lib_IntVector_Intrinsics_vec256_add64(wv_a13[0U], wv_b14[0U]);
        Lib_IntVector_Intrinsics_vec256 *wv_a14 = block_state1.fst + b1 * (uint32_t)1U;
        Lib_IntVector_Intrinsics_vec256 *wv_b = block_state1.fst + c * (uint32_t)1U;
        wv_a14[0U] = Lib_IntVector_Intrinsics_vec256_xor(wv_a14[0U], wv_b[0U]);
        wv_a14[0U] = Lib_IntVector_Intrinsics_vec256_rotate_right64(wv_a14[0U], r33);
        Lib_IntVector_Intrinsics_vec256 *r13 = block_state1.fst + (uint32_t)1U * (uint32_t)1U;
        Lib_IntVector_Intrinsics_vec256 *r2 = block_state1.fst + (uint32_t)2U * (uint32_t)1U;
        Lib_IntVector_Intrinsics_vec256 *r3 = block_state1.fst + (uint32_t)3U * (uint32_t)1U;
        Lib_IntVector_Intrinsics_vec256 v0 = r13[0U];
        Lib_IntVector_Intrinsics_vec256
        v12 = Lib_IntVector_Intrinsics_vec256_rotate_right_lanes64(v0, (uint32_t)3U);
        r13[0U] = v12;
        Lib_IntVector_Intrinsics_vec256 v03 = r2[0U];
        Lib_IntVector_Intrinsics_vec256
        v13 = Lib_IntVector_Intrinsics_vec256_rotate_right_lanes64(v03, (uint32_t)2U);
        r2[0U] = v13;
        Lib_IntVector_Intrinsics_vec256 v04 = r3[0U];
        Lib_IntVector_Intrinsics_vec256
        v14 = Lib_IntVector_Intrinsics_vec256_rotate_right_lanes64(v04, (uint32_t)1U);
        r3[0U] = v14;
      }
      Lib_IntVector_Intrinsics_vec256 *s0 = block_state1.snd + (uint32_t)0U * (uint32_t)1U;
      Lib_IntVector_Intrinsics_vec256 *s11 = block_state1.snd + (uint32_t)1U * (uint32_t)1U;
      Lib_IntVector_Intrinsics_vec256 *r0 = block_state1.fst + (uint32_t)0U * (uint32_t)1U;
      Lib_IntVector_Intrinsics_vec256 *r1 = block_state1.fst + (uint32_t)1U * (uint32_t)1U;
      Lib_IntVector_Intrinsics_vec256 *r2 = block_state1.fst + (uint32_t)2U * (uint32_t)1U;
      Lib_IntVector_Intrinsics_vec256 *r3 = block_state1.fst + (uint32_t)3U * (uint32_t)1U;
      s0[0U] = Lib_IntVector_Intrinsics_vec256_xor(s0[0U], r0[0U]);
      s0[0U] = Lib_IntVector_Intrinsics_vec256_xor(s0[0U], r2[0U]);
      s11[0U] = Lib_IntVector_Intrinsics_vec256_xor(s11[0U], r1[0U]);
      s11[0U] = Lib_IntVector_Intrinsics_vec256_xor(s11[0U], r3[0U]);
    }
    uint8_t *dst = buf;
    memcpy(dst, data2, data2_len * sizeof (data2[0U]));
    *p
    =
      (
        (Hacl_Streaming_Functor_state_s__K____Lib_IntVector_Intrinsics_vec256___Lib_IntVector_Intrinsics_vec256____){
          .block_state = block_state1,
          .buf = buf,
          .total_len = total_len1 + (uint64_t)len
        }
      );
    return;
  }
  uint32_t diff = (uint32_t)128U - sz;
  uint8_t *data1 = data;
  uint8_t *data2 = data + diff;
  Hacl_Streaming_Functor_state_s__K____Lib_IntVector_Intrinsics_vec256___Lib_IntVector_Intrinsics_vec256____
  s2 = *p;
  K____Lib_IntVector_Intrinsics_vec256___Lib_IntVector_Intrinsics_vec256_
  block_state10 = s2.block_state;
  uint8_t *buf0 = s2.buf;
  uint64_t total_len10 = s2.total_len;
  uint32_t sz10;
  if (total_len10 % (uint64_t)(uint32_t)128U == (uint64_t)0U && total_len10 > (uint64_t)0U)
  {
    sz10 = (uint32_t)128U;
  }
  else
  {
    sz10 = (uint32_t)(total_len10 % (uint64_t)(uint32_t)128U);
  }
  uint8_t *buf2 = buf0 + sz10;
  memcpy(buf2, data1, diff * sizeof (data1[0U]));
  uint64_t total_len2 = total_len10 + (uint64_t)diff;
  *p
  =
    (
      (Hacl_Streaming_Functor_state_s__K____Lib_IntVector_Intrinsics_vec256___Lib_IntVector_Intrinsics_vec256____){
        .block_state = block_state10,
        .buf = buf0,
        .total_len = total_len2
      }
    );
  Hacl_Streaming_Functor_state_s__K____Lib_IntVector_Intrinsics_vec256___Lib_IntVector_Intrinsics_vec256____
  s20 = *p;
  K____Lib_IntVector_Intrinsics_vec256___Lib_IntVector_Intrinsics_vec256_
  block_state1 = s20.block_state;
  uint8_t *buf = s20.buf;
  uint64_t total_len1 = s20.total_len;
  uint32_t sz1;
  if (total_len1 % (uint64_t)(uint32_t)128U == (uint64_t)0U && total_len1 > (uint64_t)0U)
  {
    sz1 = (uint32_t)128U;
  }
  else
  {
    sz1 = (uint32_t)(total_len1 % (uint64_t)(uint32_t)128U);
  }
  if (!(sz1 == (uint32_t)0U))
  {
    uint64_t prevlen = total_len1 - (uint64_t)sz1;
    uint32_t nb = (uint32_t)1U;
    for (uint32_t i0 = (uint32_t)0U; i0 < nb; i0++)
    {
      uint64_t ite;
      if ((uint32_t)0U == (uint32_t)0U)
      {
        ite = prevlen;
      }
      else
      {
        ite = prevlen + (uint64_t)(uint32_t)128U;
      }
      FStar_UInt128_uint128
      totlen =
        FStar_UInt128_add_mod(FStar_UInt128_uint64_to_uint128(ite),
          FStar_UInt128_uint64_to_uint128((uint64_t)((i0 + (uint32_t)1U) * (uint32_t)128U)));
      uint8_t *b = buf + i0 * (uint32_t)128U;
      uint64_t m_w[16U] = { 0U };
      for (uint32_t i = (uint32_t)0U; i < (uint32_t)16U; i++)
      {
        uint64_t *os = m_w;
        uint8_t *bj = b + i * (uint32_t)8U;
        uint64_t u = load64_le(bj);
        uint64_t r = u;
        uint64_t x = r;
        os[i] = x;
      }
      Lib_IntVector_Intrinsics_vec256 mask = Lib_IntVector_Intrinsics_vec256_zero;
      uint64_t wv_14 = (uint64_t)0U;
      uint64_t wv_15 = (uint64_t)0U;
      mask =
        Lib_IntVector_Intrinsics_vec256_load64s(FStar_UInt128_uint128_to_uint64(totlen),
          FStar_UInt128_uint128_to_uint64(FStar_UInt128_shift_right(totlen, (uint32_t)64U)),
          wv_14,
          wv_15);
      memcpy(block_state1.fst,
        block_state1.snd,
        (uint32_t)4U * (uint32_t)1U * sizeof (block_state1.snd[0U]));
      Lib_IntVector_Intrinsics_vec256 *wv3 = block_state1.fst + (uint32_t)3U * (uint32_t)1U;
      wv3[0U] = Lib_IntVector_Intrinsics_vec256_xor(wv3[0U], mask);
      for (uint32_t i = (uint32_t)0U; i < (uint32_t)12U; i++)
      {
        uint32_t start_idx = i % (uint32_t)10U * (uint32_t)16U;
        KRML_CHECK_SIZE(sizeof (Lib_IntVector_Intrinsics_vec256), (uint32_t)4U * (uint32_t)1U);
        Lib_IntVector_Intrinsics_vec256 m_st[(uint32_t)4U * (uint32_t)1U];
        for (uint32_t _i = 0U; _i < (uint32_t)4U * (uint32_t)1U; ++_i)
          m_st[_i] = Lib_IntVector_Intrinsics_vec256_zero;
        Lib_IntVector_Intrinsics_vec256 *r00 = m_st + (uint32_t)0U * (uint32_t)1U;
        Lib_IntVector_Intrinsics_vec256 *r10 = m_st + (uint32_t)1U * (uint32_t)1U;
        Lib_IntVector_Intrinsics_vec256 *r20 = m_st + (uint32_t)2U * (uint32_t)1U;
        Lib_IntVector_Intrinsics_vec256 *r30 = m_st + (uint32_t)3U * (uint32_t)1U;
        uint32_t s0 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx];
        uint32_t s11 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)1U];
        uint32_t s21 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)2U];
        uint32_t s3 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)3U];
        uint32_t s4 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)4U];
        uint32_t s5 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)5U];
        uint32_t s6 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)6U];
        uint32_t s7 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)7U];
        uint32_t s8 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)8U];
        uint32_t s9 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)9U];
        uint32_t s10 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)10U];
        uint32_t s111 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)11U];
        uint32_t s12 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)12U];
        uint32_t s13 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)13U];
        uint32_t s14 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)14U];
        uint32_t s15 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)15U];
        r00[0U] = Lib_IntVector_Intrinsics_vec256_load64s(m_w[s0], m_w[s21], m_w[s4], m_w[s6]);
        r10[0U] = Lib_IntVector_Intrinsics_vec256_load64s(m_w[s11], m_w[s3], m_w[s5], m_w[s7]);
        r20[0U] = Lib_IntVector_Intrinsics_vec256_load64s(m_w[s8], m_w[s10], m_w[s12], m_w[s14]);
        r30[0U] = Lib_IntVector_Intrinsics_vec256_load64s(m_w[s9], m_w[s111], m_w[s13], m_w[s15]);
        Lib_IntVector_Intrinsics_vec256 *x = m_st + (uint32_t)0U * (uint32_t)1U;
        Lib_IntVector_Intrinsics_vec256 *y = m_st + (uint32_t)1U * (uint32_t)1U;
        Lib_IntVector_Intrinsics_vec256 *z = m_st + (uint32_t)2U * (uint32_t)1U;
        Lib_IntVector_Intrinsics_vec256 *w = m_st + (uint32_t)3U * (uint32_t)1U;
        uint32_t a = (uint32_t)0U;
        uint32_t b10 = (uint32_t)1U;
        uint32_t c0 = (uint32_t)2U;
        uint32_t d0 = (uint32_t)3U;
        uint32_t r01 = Hacl_Impl_Blake2_Constants_rTable_B[0U];
        uint32_t r11 = Hacl_Impl_Blake2_Constants_rTable_B[1U];
        uint32_t r21 = Hacl_Impl_Blake2_Constants_rTable_B[2U];
        uint32_t r31 = Hacl_Impl_Blake2_Constants_rTable_B[3U];
        Lib_IntVector_Intrinsics_vec256 *wv_a0 = block_state1.fst + a * (uint32_t)1U;
        Lib_IntVector_Intrinsics_vec256 *wv_b0 = block_state1.fst + b10 * (uint32_t)1U;
        wv_a0[0U] = Lib_IntVector_Intrinsics_vec256_add64(wv_a0[0U], wv_b0[0U]);
        wv_a0[0U] = Lib_IntVector_Intrinsics_vec256_add64(wv_a0[0U], x[0U]);
        Lib_IntVector_Intrinsics_vec256 *wv_a1 = block_state1.fst + d0 * (uint32_t)1U;
        Lib_IntVector_Intrinsics_vec256 *wv_b1 = block_state1.fst + a * (uint32_t)1U;
        wv_a1[0U] = Lib_IntVector_Intrinsics_vec256_xor(wv_a1[0U], wv_b1[0U]);
        wv_a1[0U] = Lib_IntVector_Intrinsics_vec256_rotate_right64(wv_a1[0U], r01);
        Lib_IntVector_Intrinsics_vec256 *wv_a2 = block_state1.fst + c0 * (uint32_t)1U;
        Lib_IntVector_Intrinsics_vec256 *wv_b2 = block_state1.fst + d0 * (uint32_t)1U;
        wv_a2[0U] = Lib_IntVector_Intrinsics_vec256_add64(wv_a2[0U], wv_b2[0U]);
        Lib_IntVector_Intrinsics_vec256 *wv_a3 = block_state1.fst + b10 * (uint32_t)1U;
        Lib_IntVector_Intrinsics_vec256 *wv_b3 = block_state1.fst + c0 * (uint32_t)1U;
        wv_a3[0U] = Lib_IntVector_Intrinsics_vec256_xor(wv_a3[0U], wv_b3[0U]);
        wv_a3[0U] = Lib_IntVector_Intrinsics_vec256_rotate_right64(wv_a3[0U], r11);
        Lib_IntVector_Intrinsics_vec256 *wv_a4 = block_state1.fst + a * (uint32_t)1U;
        Lib_IntVector_Intrinsics_vec256 *wv_b4 = block_state1.fst + b10 * (uint32_t)1U;
        wv_a4[0U] = Lib_IntVector_Intrinsics_vec256_add64(wv_a4[0U], wv_b4[0U]);
        wv_a4[0U] = Lib_IntVector_Intrinsics_vec256_add64(wv_a4[0U], y[0U]);
        Lib_IntVector_Intrinsics_vec256 *wv_a5 = block_state1.fst + d0 * (uint32_t)1U;
        Lib_IntVector_Intrinsics_vec256 *wv_b5 = block_state1.fst + a * (uint32_t)1U;
        wv_a5[0U] = Lib_IntVector_Intrinsics_vec256_xor(wv_a5[0U], wv_b5[0U]);
        wv_a5[0U] = Lib_IntVector_Intrinsics_vec256_rotate_right64(wv_a5[0U], r21);
        Lib_IntVector_Intrinsics_vec256 *wv_a6 = block_state1.fst + c0 * (uint32_t)1U;
        Lib_IntVector_Intrinsics_vec256 *wv_b6 = block_state1.fst + d0 * (uint32_t)1U;
        wv_a6[0U] = Lib_IntVector_Intrinsics_vec256_add64(wv_a6[0U], wv_b6[0U]);
        Lib_IntVector_Intrinsics_vec256 *wv_a7 = block_state1.fst + b10 * (uint32_t)1U;
        Lib_IntVector_Intrinsics_vec256 *wv_b7 = block_state1.fst + c0 * (uint32_t)1U;
        wv_a7[0U] = Lib_IntVector_Intrinsics_vec256_xor(wv_a7[0U], wv_b7[0U]);
        wv_a7[0U] = Lib_IntVector_Intrinsics_vec256_rotate_right64(wv_a7[0U], r31);
        Lib_IntVector_Intrinsics_vec256 *r12 = block_state1.fst + (uint32_t)1U * (uint32_t)1U;
        Lib_IntVector_Intrinsics_vec256 *r22 = block_state1.fst + (uint32_t)2U * (uint32_t)1U;
        Lib_IntVector_Intrinsics_vec256 *r32 = block_state1.fst + (uint32_t)3U * (uint32_t)1U;
        Lib_IntVector_Intrinsics_vec256 v00 = r12[0U];
        Lib_IntVector_Intrinsics_vec256
        v1 = Lib_IntVector_Intrinsics_vec256_rotate_right_lanes64(v00, (uint32_t)1U);
        r12[0U] = v1;
        Lib_IntVector_Intrinsics_vec256 v01 = r22[0U];
        Lib_IntVector_Intrinsics_vec256
        v10 = Lib_IntVector_Intrinsics_vec256_rotate_right_lanes64(v01, (uint32_t)2U);
        r22[0U] = v10;
        Lib_IntVector_Intrinsics_vec256 v02 = r32[0U];
        Lib_IntVector_Intrinsics_vec256
        v11 = Lib_IntVector_Intrinsics_vec256_rotate_right_lanes64(v02, (uint32_t)3U);
        r32[0U] = v11;
        uint32_t a0 = (uint32_t)0U;
        uint32_t b1 = (uint32_t)1U;
        uint32_t c = (uint32_t)2U;
        uint32_t d = (uint32_t)3U;
        uint32_t r0 = Hacl_Impl_Blake2_Constants_rTable_B[0U];
        uint32_t r1 = Hacl_Impl_Blake2_Constants_rTable_B[1U];
        uint32_t r23 = Hacl_Impl_Blake2_Constants_rTable_B[2U];
        uint32_t r33 = Hacl_Impl_Blake2_Constants_rTable_B[3U];
        Lib_IntVector_Intrinsics_vec256 *wv_a = block_state1.fst + a0 * (uint32_t)1U;
        Lib_IntVector_Intrinsics_vec256 *wv_b8 = block_state1.fst + b1 * (uint32_t)1U;
        wv_a[0U] = Lib_IntVector_Intrinsics_vec256_add64(wv_a[0U], wv_b8[0U]);
        wv_a[0U] = Lib_IntVector_Intrinsics_vec256_add64(wv_a[0U], z[0U]);
        Lib_IntVector_Intrinsics_vec256 *wv_a8 = block_state1.fst + d * (uint32_t)1U;
        Lib_IntVector_Intrinsics_vec256 *wv_b9 = block_state1.fst + a0 * (uint32_t)1U;
        wv_a8[0U] = Lib_IntVector_Intrinsics_vec256_xor(wv_a8[0U], wv_b9[0U]);
        wv_a8[0U] = Lib_IntVector_Intrinsics_vec256_rotate_right64(wv_a8[0U], r0);
        Lib_IntVector_Intrinsics_vec256 *wv_a9 = block_state1.fst + c * (uint32_t)1U;
        Lib_IntVector_Intrinsics_vec256 *wv_b10 = block_state1.fst + d * (uint32_t)1U;
        wv_a9[0U] = Lib_IntVector_Intrinsics_vec256_add64(wv_a9[0U], wv_b10[0U]);
        Lib_IntVector_Intrinsics_vec256 *wv_a10 = block_state1.fst + b1 * (uint32_t)1U;
        Lib_IntVector_Intrinsics_vec256 *wv_b11 = block_state1.fst + c * (uint32_t)1U;
        wv_a10[0U] = Lib_IntVector_Intrinsics_vec256_xor(wv_a10[0U], wv_b11[0U]);
        wv_a10[0U] = Lib_IntVector_Intrinsics_vec256_rotate_right64(wv_a10[0U], r1);
        Lib_IntVector_Intrinsics_vec256 *wv_a11 = block_state1.fst + a0 * (uint32_t)1U;
        Lib_IntVector_Intrinsics_vec256 *wv_b12 = block_state1.fst + b1 * (uint32_t)1U;
        wv_a11[0U] = Lib_IntVector_Intrinsics_vec256_add64(wv_a11[0U], wv_b12[0U]);
        wv_a11[0U] = Lib_IntVector_Intrinsics_vec256_add64(wv_a11[0U], w[0U]);
        Lib_IntVector_Intrinsics_vec256 *wv_a12 = block_state1.fst + d * (uint32_t)1U;
        Lib_IntVector_Intrinsics_vec256 *wv_b13 = block_state1.fst + a0 * (uint32_t)1U;
        wv_a12[0U] = Lib_IntVector_Intrinsics_vec256_xor(wv_a12[0U], wv_b13[0U]);
        wv_a12[0U] = Lib_IntVector_Intrinsics_vec256_rotate_right64(wv_a12[0U], r23);
        Lib_IntVector_Intrinsics_vec256 *wv_a13 = block_state1.fst + c * (uint32_t)1U;
        Lib_IntVector_Intrinsics_vec256 *wv_b14 = block_state1.fst + d * (uint32_t)1U;
        wv_a13[0U] = Lib_IntVector_Intrinsics_vec256_add64(wv_a13[0U], wv_b14[0U]);
        Lib_IntVector_Intrinsics_vec256 *wv_a14 = block_state1.fst + b1 * (uint32_t)1U;
        Lib_IntVector_Intrinsics_vec256 *wv_b = block_state1.fst + c * (uint32_t)1U;
        wv_a14[0U] = Lib_IntVector_Intrinsics_vec256_xor(wv_a14[0U], wv_b[0U]);
        wv_a14[0U] = Lib_IntVector_Intrinsics_vec256_rotate_right64(wv_a14[0U], r33);
        Lib_IntVector_Intrinsics_vec256 *r13 = block_state1.fst + (uint32_t)1U * (uint32_t)1U;
        Lib_IntVector_Intrinsics_vec256 *r2 = block_state1.fst + (uint32_t)2U * (uint32_t)1U;
        Lib_IntVector_Intrinsics_vec256 *r3 = block_state1.fst + (uint32_t)3U * (uint32_t)1U;
        Lib_IntVector_Intrinsics_vec256 v0 = r13[0U];
        Lib_IntVector_Intrinsics_vec256
        v12 = Lib_IntVector_Intrinsics_vec256_rotate_right_lanes64(v0, (uint32_t)3U);
        r13[0U] = v12;
        Lib_IntVector_Intrinsics_vec256 v03 = r2[0U];
        Lib_IntVector_Intrinsics_vec256
        v13 = Lib_IntVector_Intrinsics_vec256_rotate_right_lanes64(v03, (uint32_t)2U);
        r2[0U] = v13;
        Lib_IntVector_Intrinsics_vec256 v04 = r3[0U];
        Lib_IntVector_Intrinsics_vec256
        v14 = Lib_IntVector_Intrinsics_vec256_rotate_right_lanes64(v04, (uint32_t)1U);
        r3[0U] = v14;
      }
      Lib_IntVector_Intrinsics_vec256 *s0 = block_state1.snd + (uint32_t)0U * (uint32_t)1U;
      Lib_IntVector_Intrinsics_vec256 *s11 = block_state1.snd + (uint32_t)1U * (uint32_t)1U;
      Lib_IntVector_Intrinsics_vec256 *r0 = block_state1.fst + (uint32_t)0U * (uint32_t)1U;
      Lib_IntVector_Intrinsics_vec256 *r1 = block_state1.fst + (uint32_t)1U * (uint32_t)1U;
      Lib_IntVector_Intrinsics_vec256 *r2 = block_state1.fst + (uint32_t)2U * (uint32_t)1U;
      Lib_IntVector_Intrinsics_vec256 *r3 = block_state1.fst + (uint32_t)3U * (uint32_t)1U;
      s0[0U] = Lib_IntVector_Intrinsics_vec256_xor(s0[0U], r0[0U]);
      s0[0U] = Lib_IntVector_Intrinsics_vec256_xor(s0[0U], r2[0U]);
      s11[0U] = Lib_IntVector_Intrinsics_vec256_xor(s11[0U], r1[0U]);
      s11[0U] = Lib_IntVector_Intrinsics_vec256_xor(s11[0U], r3[0U]);
    }
  }
  uint32_t ite0;
  if
  (
    (uint64_t)(len - diff)
    % (uint64_t)(uint32_t)128U
    == (uint64_t)0U
    && (uint64_t)(len - diff) > (uint64_t)0U
  )
  {
    ite0 = (uint32_t)128U;
  }
  else
  {
    ite0 = (uint32_t)((uint64_t)(len - diff) % (uint64_t)(uint32_t)128U);
  }
  uint32_t n_blocks = (len - diff - ite0) / (uint32_t)128U;
  uint32_t data1_len = n_blocks * (uint32_t)128U;
  uint32_t data2_len = len - diff - data1_len;
  uint8_t *data11 = data2;
  uint8_t *data21 = data2 + data1_len;
  uint32_t nb = data1_len / (uint32_t)128U;
  for (uint32_t i0 = (uint32_t)0U; i0 < nb; i0++)
  {
    uint64_t ite;
    if ((uint32_t)0U == (uint32_t)0U)
    {
      ite = total_len1;
    }
    else
    {
      ite = total_len1 + (uint64_t)(uint32_t)128U;
    }
    FStar_UInt128_uint128
    totlen =
      FStar_UInt128_add_mod(FStar_UInt128_uint64_to_uint128(ite),
        FStar_UInt128_uint64_to_uint128((uint64_t)((i0 + (uint32_t)1U) * (uint32_t)128U)));
    uint8_t *b = data11 + i0 * (uint32_t)128U;
    uint64_t m_w[16U] = { 0U };
    for (uint32_t i = (uint32_t)0U; i < (uint32_t)16U; i++)
    {
      uint64_t *os = m_w;
      uint8_t *bj = b + i * (uint32_t)8U;
      uint64_t u = load64_le(bj);
      uint64_t r = u;
      uint64_t x = r;
      os[i] = x;
    }
    Lib_IntVector_Intrinsics_vec256 mask = Lib_IntVector_Intrinsics_vec256_zero;
    uint64_t wv_14 = (uint64_t)0U;
    uint64_t wv_15 = (uint64_t)0U;
    mask =
      Lib_IntVector_Intrinsics_vec256_load64s(FStar_UInt128_uint128_to_uint64(totlen),
        FStar_UInt128_uint128_to_uint64(FStar_UInt128_shift_right(totlen, (uint32_t)64U)),
        wv_14,
        wv_15);
    memcpy(block_state1.fst,
      block_state1.snd,
      (uint32_t)4U * (uint32_t)1U * sizeof (block_state1.snd[0U]));
    Lib_IntVector_Intrinsics_vec256 *wv3 = block_state1.fst + (uint32_t)3U * (uint32_t)1U;
    wv3[0U] = Lib_IntVector_Intrinsics_vec256_xor(wv3[0U], mask);
    for (uint32_t i = (uint32_t)0U; i < (uint32_t)12U; i++)
    {
      uint32_t start_idx = i % (uint32_t)10U * (uint32_t)16U;
      KRML_CHECK_SIZE(sizeof (Lib_IntVector_Intrinsics_vec256), (uint32_t)4U * (uint32_t)1U);
      Lib_IntVector_Intrinsics_vec256 m_st[(uint32_t)4U * (uint32_t)1U];
      for (uint32_t _i = 0U; _i < (uint32_t)4U * (uint32_t)1U; ++_i)
        m_st[_i] = Lib_IntVector_Intrinsics_vec256_zero;
      Lib_IntVector_Intrinsics_vec256 *r00 = m_st + (uint32_t)0U * (uint32_t)1U;
      Lib_IntVector_Intrinsics_vec256 *r10 = m_st + (uint32_t)1U * (uint32_t)1U;
      Lib_IntVector_Intrinsics_vec256 *r20 = m_st + (uint32_t)2U * (uint32_t)1U;
      Lib_IntVector_Intrinsics_vec256 *r30 = m_st + (uint32_t)3U * (uint32_t)1U;
      uint32_t s0 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx];
      uint32_t s11 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)1U];
      uint32_t s21 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)2U];
      uint32_t s3 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)3U];
      uint32_t s4 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)4U];
      uint32_t s5 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)5U];
      uint32_t s6 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)6U];
      uint32_t s7 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)7U];
      uint32_t s8 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)8U];
      uint32_t s9 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)9U];
      uint32_t s10 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)10U];
      uint32_t s111 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)11U];
      uint32_t s12 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)12U];
      uint32_t s13 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)13U];
      uint32_t s14 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)14U];
      uint32_t s15 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)15U];
      r00[0U] = Lib_IntVector_Intrinsics_vec256_load64s(m_w[s0], m_w[s21], m_w[s4], m_w[s6]);
      r10[0U] = Lib_IntVector_Intrinsics_vec256_load64s(m_w[s11], m_w[s3], m_w[s5], m_w[s7]);
      r20[0U] = Lib_IntVector_Intrinsics_vec256_load64s(m_w[s8], m_w[s10], m_w[s12], m_w[s14]);
      r30[0U] = Lib_IntVector_Intrinsics_vec256_load64s(m_w[s9], m_w[s111], m_w[s13], m_w[s15]);
      Lib_IntVector_Intrinsics_vec256 *x = m_st + (uint32_t)0U * (uint32_t)1U;
      Lib_IntVector_Intrinsics_vec256 *y = m_st + (uint32_t)1U * (uint32_t)1U;
      Lib_IntVector_Intrinsics_vec256 *z = m_st + (uint32_t)2U * (uint32_t)1U;
      Lib_IntVector_Intrinsics_vec256 *w = m_st + (uint32_t)3U * (uint32_t)1U;
      uint32_t a = (uint32_t)0U;
      uint32_t b10 = (uint32_t)1U;
      uint32_t c0 = (uint32_t)2U;
      uint32_t d0 = (uint32_t)3U;
      uint32_t r01 = Hacl_Impl_Blake2_Constants_rTable_B[0U];
      uint32_t r11 = Hacl_Impl_Blake2_Constants_rTable_B[1U];
      uint32_t r21 = Hacl_Impl_Blake2_Constants_rTable_B[2U];
      uint32_t r31 = Hacl_Impl_Blake2_Constants_rTable_B[3U];
      Lib_IntVector_Intrinsics_vec256 *wv_a0 = block_state1.fst + a * (uint32_t)1U;
      Lib_IntVector_Intrinsics_vec256 *wv_b0 = block_state1.fst + b10 * (uint32_t)1U;
      wv_a0[0U] = Lib_IntVector_Intrinsics_vec256_add64(wv_a0[0U], wv_b0[0U]);
      wv_a0[0U] = Lib_IntVector_Intrinsics_vec256_add64(wv_a0[0U], x[0U]);
      Lib_IntVector_Intrinsics_vec256 *wv_a1 = block_state1.fst + d0 * (uint32_t)1U;
      Lib_IntVector_Intrinsics_vec256 *wv_b1 = block_state1.fst + a * (uint32_t)1U;
      wv_a1[0U] = Lib_IntVector_Intrinsics_vec256_xor(wv_a1[0U], wv_b1[0U]);
      wv_a1[0U] = Lib_IntVector_Intrinsics_vec256_rotate_right64(wv_a1[0U], r01);
      Lib_IntVector_Intrinsics_vec256 *wv_a2 = block_state1.fst + c0 * (uint32_t)1U;
      Lib_IntVector_Intrinsics_vec256 *wv_b2 = block_state1.fst + d0 * (uint32_t)1U;
      wv_a2[0U] = Lib_IntVector_Intrinsics_vec256_add64(wv_a2[0U], wv_b2[0U]);
      Lib_IntVector_Intrinsics_vec256 *wv_a3 = block_state1.fst + b10 * (uint32_t)1U;
      Lib_IntVector_Intrinsics_vec256 *wv_b3 = block_state1.fst + c0 * (uint32_t)1U;
      wv_a3[0U] = Lib_IntVector_Intrinsics_vec256_xor(wv_a3[0U], wv_b3[0U]);
      wv_a3[0U] = Lib_IntVector_Intrinsics_vec256_rotate_right64(wv_a3[0U], r11);
      Lib_IntVector_Intrinsics_vec256 *wv_a4 = block_state1.fst + a * (uint32_t)1U;
      Lib_IntVector_Intrinsics_vec256 *wv_b4 = block_state1.fst + b10 * (uint32_t)1U;
      wv_a4[0U] = Lib_IntVector_Intrinsics_vec256_add64(wv_a4[0U], wv_b4[0U]);
      wv_a4[0U] = Lib_IntVector_Intrinsics_vec256_add64(wv_a4[0U], y[0U]);
      Lib_IntVector_Intrinsics_vec256 *wv_a5 = block_state1.fst + d0 * (uint32_t)1U;
      Lib_IntVector_Intrinsics_vec256 *wv_b5 = block_state1.fst + a * (uint32_t)1U;
      wv_a5[0U] = Lib_IntVector_Intrinsics_vec256_xor(wv_a5[0U], wv_b5[0U]);
      wv_a5[0U] = Lib_IntVector_Intrinsics_vec256_rotate_right64(wv_a5[0U], r21);
      Lib_IntVector_Intrinsics_vec256 *wv_a6 = block_state1.fst + c0 * (uint32_t)1U;
      Lib_IntVector_Intrinsics_vec256 *wv_b6 = block_state1.fst + d0 * (uint32_t)1U;
      wv_a6[0U] = Lib_IntVector_Intrinsics_vec256_add64(wv_a6[0U], wv_b6[0U]);
      Lib_IntVector_Intrinsics_vec256 *wv_a7 = block_state1.fst + b10 * (uint32_t)1U;
      Lib_IntVector_Intrinsics_vec256 *wv_b7 = block_state1.fst + c0 * (uint32_t)1U;
      wv_a7[0U] = Lib_IntVector_Intrinsics_vec256_xor(wv_a7[0U], wv_b7[0U]);
      wv_a7[0U] = Lib_IntVector_Intrinsics_vec256_rotate_right64(wv_a7[0U], r31);
      Lib_IntVector_Intrinsics_vec256 *r12 = block_state1.fst + (uint32_t)1U * (uint32_t)1U;
      Lib_IntVector_Intrinsics_vec256 *r22 = block_state1.fst + (uint32_t)2U * (uint32_t)1U;
      Lib_IntVector_Intrinsics_vec256 *r32 = block_state1.fst + (uint32_t)3U * (uint32_t)1U;
      Lib_IntVector_Intrinsics_vec256 v00 = r12[0U];
      Lib_IntVector_Intrinsics_vec256
      v1 = Lib_IntVector_Intrinsics_vec256_rotate_right_lanes64(v00, (uint32_t)1U);
      r12[0U] = v1;
      Lib_IntVector_Intrinsics_vec256 v01 = r22[0U];
      Lib_IntVector_Intrinsics_vec256
      v10 = Lib_IntVector_Intrinsics_vec256_rotate_right_lanes64(v01, (uint32_t)2U);
      r22[0U] = v10;
      Lib_IntVector_Intrinsics_vec256 v02 = r32[0U];
      Lib_IntVector_Intrinsics_vec256
      v11 = Lib_IntVector_Intrinsics_vec256_rotate_right_lanes64(v02, (uint32_t)3U);
      r32[0U] = v11;
      uint32_t a0 = (uint32_t)0U;
      uint32_t b1 = (uint32_t)1U;
      uint32_t c = (uint32_t)2U;
      uint32_t d = (uint32_t)3U;
      uint32_t r0 = Hacl_Impl_Blake2_Constants_rTable_B[0U];
      uint32_t r1 = Hacl_Impl_Blake2_Constants_rTable_B[1U];
      uint32_t r23 = Hacl_Impl_Blake2_Constants_rTable_B[2U];
      uint32_t r33 = Hacl_Impl_Blake2_Constants_rTable_B[3U];
      Lib_IntVector_Intrinsics_vec256 *wv_a = block_state1.fst + a0 * (uint32_t)1U;
      Lib_IntVector_Intrinsics_vec256 *wv_b8 = block_state1.fst + b1 * (uint32_t)1U;
      wv_a[0U] = Lib_IntVector_Intrinsics_vec256_add64(wv_a[0U], wv_b8[0U]);
      wv_a[0U] = Lib_IntVector_Intrinsics_vec256_add64(wv_a[0U], z[0U]);
      Lib_IntVector_Intrinsics_vec256 *wv_a8 = block_state1.fst + d * (uint32_t)1U;
      Lib_IntVector_Intrinsics_vec256 *wv_b9 = block_state1.fst + a0 * (uint32_t)1U;
      wv_a8[0U] = Lib_IntVector_Intrinsics_vec256_xor(wv_a8[0U], wv_b9[0U]);
      wv_a8[0U] = Lib_IntVector_Intrinsics_vec256_rotate_right64(wv_a8[0U], r0);
      Lib_IntVector_Intrinsics_vec256 *wv_a9 = block_state1.fst + c * (uint32_t)1U;
      Lib_IntVector_Intrinsics_vec256 *wv_b10 = block_state1.fst + d * (uint32_t)1U;
      wv_a9[0U] = Lib_IntVector_Intrinsics_vec256_add64(wv_a9[0U], wv_b10[0U]);
      Lib_IntVector_Intrinsics_vec256 *wv_a10 = block_state1.fst + b1 * (uint32_t)1U;
      Lib_IntVector_Intrinsics_vec256 *wv_b11 = block_state1.fst + c * (uint32_t)1U;
      wv_a10[0U] = Lib_IntVector_Intrinsics_vec256_xor(wv_a10[0U], wv_b11[0U]);
      wv_a10[0U] = Lib_IntVector_Intrinsics_vec256_rotate_right64(wv_a10[0U], r1);
      Lib_IntVector_Intrinsics_vec256 *wv_a11 = block_state1.fst + a0 * (uint32_t)1U;
      Lib_IntVector_Intrinsics_vec256 *wv_b12 = block_state1.fst + b1 * (uint32_t)1U;
      wv_a11[0U] = Lib_IntVector_Intrinsics_vec256_add64(wv_a11[0U], wv_b12[0U]);
      wv_a11[0U] = Lib_IntVector_Intrinsics_vec256_add64(wv_a11[0U], w[0U]);
      Lib_IntVector_Intrinsics_vec256 *wv_a12 = block_state1.fst + d * (uint32_t)1U;
      Lib_IntVector_Intrinsics_vec256 *wv_b13 = block_state1.fst + a0 * (uint32_t)1U;
      wv_a12[0U] = Lib_IntVector_Intrinsics_vec256_xor(wv_a12[0U], wv_b13[0U]);
      wv_a12[0U] = Lib_IntVector_Intrinsics_vec256_rotate_right64(wv_a12[0U], r23);
      Lib_IntVector_Intrinsics_vec256 *wv_a13 = block_state1.fst + c * (uint32_t)1U;
      Lib_IntVector_Intrinsics_vec256 *wv_b14 = block_state1.fst + d * (uint32_t)1U;
      wv_a13[0U] = Lib_IntVector_Intrinsics_vec256_add64(wv_a13[0U], wv_b14[0U]);
      Lib_IntVector_Intrinsics_vec256 *wv_a14 = block_state1.fst + b1 * (uint32_t)1U;
      Lib_IntVector_Intrinsics_vec256 *wv_b = block_state1.fst + c * (uint32_t)1U;
      wv_a14[0U] = Lib_IntVector_Intrinsics_vec256_xor(wv_a14[0U], wv_b[0U]);
      wv_a14[0U] = Lib_IntVector_Intrinsics_vec256_rotate_right64(wv_a14[0U], r33);
      Lib_IntVector_Intrinsics_vec256 *r13 = block_state1.fst + (uint32_t)1U * (uint32_t)1U;
      Lib_IntVector_Intrinsics_vec256 *r2 = block_state1.fst + (uint32_t)2U * (uint32_t)1U;
      Lib_IntVector_Intrinsics_vec256 *r3 = block_state1.fst + (uint32_t)3U * (uint32_t)1U;
      Lib_IntVector_Intrinsics_vec256 v0 = r13[0U];
      Lib_IntVector_Intrinsics_vec256
      v12 = Lib_IntVector_Intrinsics_vec256_rotate_right_lanes64(v0, (uint32_t)3U);
      r13[0U] = v12;
      Lib_IntVector_Intrinsics_vec256 v03 = r2[0U];
      Lib_IntVector_Intrinsics_vec256
      v13 = Lib_IntVector_Intrinsics_vec256_rotate_right_lanes64(v03, (uint32_t)2U);
      r2[0U] = v13;
      Lib_IntVector_Intrinsics_vec256 v04 = r3[0U];
      Lib_IntVector_Intrinsics_vec256
      v14 = Lib_IntVector_Intrinsics_vec256_rotate_right_lanes64(v04, (uint32_t)1U);
      r3[0U] = v14;
    }
    Lib_IntVector_Intrinsics_vec256 *s0 = block_state1.snd + (uint32_t)0U * (uint32_t)1U;
    Lib_IntVector_Intrinsics_vec256 *s11 = block_state1.snd + (uint32_t)1U * (uint32_t)1U;
    Lib_IntVector_Intrinsics_vec256 *r0 = block_state1.fst + (uint32_t)0U * (uint32_t)1U;
    Lib_IntVector_Intrinsics_vec256 *r1 = block_state1.fst + (uint32_t)1U * (uint32_t)1U;
    Lib_IntVector_Intrinsics_vec256 *r2 = block_state1.fst + (uint32_t)2U * (uint32_t)1U;
    Lib_IntVector_Intrinsics_vec256 *r3 = block_state1.fst + (uint32_t)3U * (uint32_t)1U;
    s0[0U] = Lib_IntVector_Intrinsics_vec256_xor(s0[0U], r0[0U]);
    s0[0U] = Lib_IntVector_Intrinsics_vec256_xor(s0[0U], r2[0U]);
    s11[0U] = Lib_IntVector_Intrinsics_vec256_xor(s11[0U], r1[0U]);
    s11[0U] = Lib_IntVector_Intrinsics_vec256_xor(s11[0U], r3[0U]);
  }
  uint8_t *dst = buf;
  memcpy(dst, data21, data2_len * sizeof (data21[0U]));
  *p
  =
    (
      (Hacl_Streaming_Functor_state_s__K____Lib_IntVector_Intrinsics_vec256___Lib_IntVector_Intrinsics_vec256____){
        .block_state = block_state1,
        .buf = buf,
        .total_len = total_len1 + (uint64_t)(len - diff)
      }
    );
}

/* SNIPPET_END: Hacl_Streaming_Blake2_blake2b_256_no_key_update */

/* SNIPPET_START: Hacl_Streaming_Blake2_blake2b_256_no_key_finish */

/*
  Finish function when there is no key
*/
void
Hacl_Streaming_Blake2_blake2b_256_no_key_finish(
  Hacl_Streaming_Functor_state_s__K____Lib_IntVector_Intrinsics_vec256___Lib_IntVector_Intrinsics_vec256____
  *p,
  uint8_t *dst
)
{
  Hacl_Streaming_Functor_state_s__K____Lib_IntVector_Intrinsics_vec256___Lib_IntVector_Intrinsics_vec256____
  scrut = *p;
  K____Lib_IntVector_Intrinsics_vec256___Lib_IntVector_Intrinsics_vec256_
  block_state = scrut.block_state;
  uint8_t *buf_ = scrut.buf;
  uint64_t total_len = scrut.total_len;
  uint32_t r;
  if (total_len % (uint64_t)(uint32_t)128U == (uint64_t)0U && total_len > (uint64_t)0U)
  {
    r = (uint32_t)128U;
  }
  else
  {
    r = (uint32_t)(total_len % (uint64_t)(uint32_t)128U);
  }
  uint8_t *buf_1 = buf_;
  KRML_CHECK_SIZE(sizeof (Lib_IntVector_Intrinsics_vec256), (uint32_t)4U * (uint32_t)1U);
  Lib_IntVector_Intrinsics_vec256 wv[(uint32_t)4U * (uint32_t)1U];
  for (uint32_t _i = 0U; _i < (uint32_t)4U * (uint32_t)1U; ++_i)
    wv[_i] = Lib_IntVector_Intrinsics_vec256_zero;
  KRML_CHECK_SIZE(sizeof (Lib_IntVector_Intrinsics_vec256), (uint32_t)4U * (uint32_t)1U);
  Lib_IntVector_Intrinsics_vec256 b0[(uint32_t)4U * (uint32_t)1U];
  for (uint32_t _i = 0U; _i < (uint32_t)4U * (uint32_t)1U; ++_i)
    b0[_i] = Lib_IntVector_Intrinsics_vec256_zero;
  K____Lib_IntVector_Intrinsics_vec256___Lib_IntVector_Intrinsics_vec256_
  tmp_block_state = { .fst = wv, .snd = b0 };
  Lib_IntVector_Intrinsics_vec256 *src_b = block_state.snd;
  Lib_IntVector_Intrinsics_vec256 *dst_b = tmp_block_state.snd;
  memcpy(dst_b, src_b, (uint32_t)4U * sizeof (src_b[0U]));
  uint64_t prev_len = total_len - (uint64_t)r;
  uint8_t b2[128U] = { 0U };
  uint8_t *last = buf_1 + r - r;
  memcpy(b2, last, r * sizeof (last[0U]));
  uint64_t ite;
  if ((uint32_t)0U == (uint32_t)0U)
  {
    ite = prev_len;
  }
  else
  {
    ite = prev_len + (uint64_t)(uint32_t)128U;
  }
  FStar_UInt128_uint128
  totlen =
    FStar_UInt128_add_mod(FStar_UInt128_uint64_to_uint128(ite),
      FStar_UInt128_uint64_to_uint128((uint64_t)r));
  uint64_t m_w[16U] = { 0U };
  for (uint32_t i = (uint32_t)0U; i < (uint32_t)16U; i++)
  {
    uint64_t *os = m_w;
    uint8_t *bj = b2 + i * (uint32_t)8U;
    uint64_t u = load64_le(bj);
    uint64_t r1 = u;
    uint64_t x = r1;
    os[i] = x;
  }
  Lib_IntVector_Intrinsics_vec256 mask = Lib_IntVector_Intrinsics_vec256_zero;
  uint64_t wv_14 = (uint64_t)0xFFFFFFFFFFFFFFFFU;
  uint64_t wv_15 = (uint64_t)0U;
  mask =
    Lib_IntVector_Intrinsics_vec256_load64s(FStar_UInt128_uint128_to_uint64(totlen),
      FStar_UInt128_uint128_to_uint64(FStar_UInt128_shift_right(totlen, (uint32_t)64U)),
      wv_14,
      wv_15);
  memcpy(tmp_block_state.fst,
    tmp_block_state.snd,
    (uint32_t)4U * (uint32_t)1U * sizeof (tmp_block_state.snd[0U]));
  Lib_IntVector_Intrinsics_vec256 *wv3 = tmp_block_state.fst + (uint32_t)3U * (uint32_t)1U;
  wv3[0U] = Lib_IntVector_Intrinsics_vec256_xor(wv3[0U], mask);
  for (uint32_t i = (uint32_t)0U; i < (uint32_t)12U; i++)
  {
    uint32_t start_idx = i % (uint32_t)10U * (uint32_t)16U;
    KRML_CHECK_SIZE(sizeof (Lib_IntVector_Intrinsics_vec256), (uint32_t)4U * (uint32_t)1U);
    Lib_IntVector_Intrinsics_vec256 m_st[(uint32_t)4U * (uint32_t)1U];
    for (uint32_t _i = 0U; _i < (uint32_t)4U * (uint32_t)1U; ++_i)
      m_st[_i] = Lib_IntVector_Intrinsics_vec256_zero;
    Lib_IntVector_Intrinsics_vec256 *r00 = m_st + (uint32_t)0U * (uint32_t)1U;
    Lib_IntVector_Intrinsics_vec256 *r10 = m_st + (uint32_t)1U * (uint32_t)1U;
    Lib_IntVector_Intrinsics_vec256 *r20 = m_st + (uint32_t)2U * (uint32_t)1U;
    Lib_IntVector_Intrinsics_vec256 *r30 = m_st + (uint32_t)3U * (uint32_t)1U;
    uint32_t s0 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx];
    uint32_t s1 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)1U];
    uint32_t s2 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)2U];
    uint32_t s3 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)3U];
    uint32_t s4 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)4U];
    uint32_t s5 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)5U];
    uint32_t s6 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)6U];
    uint32_t s7 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)7U];
    uint32_t s8 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)8U];
    uint32_t s9 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)9U];
    uint32_t s10 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)10U];
    uint32_t s11 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)11U];
    uint32_t s12 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)12U];
    uint32_t s13 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)13U];
    uint32_t s14 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)14U];
    uint32_t s15 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)15U];
    r00[0U] = Lib_IntVector_Intrinsics_vec256_load64s(m_w[s0], m_w[s2], m_w[s4], m_w[s6]);
    r10[0U] = Lib_IntVector_Intrinsics_vec256_load64s(m_w[s1], m_w[s3], m_w[s5], m_w[s7]);
    r20[0U] = Lib_IntVector_Intrinsics_vec256_load64s(m_w[s8], m_w[s10], m_w[s12], m_w[s14]);
    r30[0U] = Lib_IntVector_Intrinsics_vec256_load64s(m_w[s9], m_w[s11], m_w[s13], m_w[s15]);
    Lib_IntVector_Intrinsics_vec256 *x = m_st + (uint32_t)0U * (uint32_t)1U;
    Lib_IntVector_Intrinsics_vec256 *y = m_st + (uint32_t)1U * (uint32_t)1U;
    Lib_IntVector_Intrinsics_vec256 *z = m_st + (uint32_t)2U * (uint32_t)1U;
    Lib_IntVector_Intrinsics_vec256 *w = m_st + (uint32_t)3U * (uint32_t)1U;
    uint32_t a = (uint32_t)0U;
    uint32_t b10 = (uint32_t)1U;
    uint32_t c0 = (uint32_t)2U;
    uint32_t d0 = (uint32_t)3U;
    uint32_t r01 = Hacl_Impl_Blake2_Constants_rTable_B[0U];
    uint32_t r11 = Hacl_Impl_Blake2_Constants_rTable_B[1U];
    uint32_t r21 = Hacl_Impl_Blake2_Constants_rTable_B[2U];
    uint32_t r31 = Hacl_Impl_Blake2_Constants_rTable_B[3U];
    Lib_IntVector_Intrinsics_vec256 *wv_a0 = tmp_block_state.fst + a * (uint32_t)1U;
    Lib_IntVector_Intrinsics_vec256 *wv_b0 = tmp_block_state.fst + b10 * (uint32_t)1U;
    wv_a0[0U] = Lib_IntVector_Intrinsics_vec256_add64(wv_a0[0U], wv_b0[0U]);
    wv_a0[0U] = Lib_IntVector_Intrinsics_vec256_add64(wv_a0[0U], x[0U]);
    Lib_IntVector_Intrinsics_vec256 *wv_a1 = tmp_block_state.fst + d0 * (uint32_t)1U;
    Lib_IntVector_Intrinsics_vec256 *wv_b1 = tmp_block_state.fst + a * (uint32_t)1U;
    wv_a1[0U] = Lib_IntVector_Intrinsics_vec256_xor(wv_a1[0U], wv_b1[0U]);
    wv_a1[0U] = Lib_IntVector_Intrinsics_vec256_rotate_right64(wv_a1[0U], r01);
    Lib_IntVector_Intrinsics_vec256 *wv_a2 = tmp_block_state.fst + c0 * (uint32_t)1U;
    Lib_IntVector_Intrinsics_vec256 *wv_b2 = tmp_block_state.fst + d0 * (uint32_t)1U;
    wv_a2[0U] = Lib_IntVector_Intrinsics_vec256_add64(wv_a2[0U], wv_b2[0U]);
    Lib_IntVector_Intrinsics_vec256 *wv_a3 = tmp_block_state.fst + b10 * (uint32_t)1U;
    Lib_IntVector_Intrinsics_vec256 *wv_b3 = tmp_block_state.fst + c0 * (uint32_t)1U;
    wv_a3[0U] = Lib_IntVector_Intrinsics_vec256_xor(wv_a3[0U], wv_b3[0U]);
    wv_a3[0U] = Lib_IntVector_Intrinsics_vec256_rotate_right64(wv_a3[0U], r11);
    Lib_IntVector_Intrinsics_vec256 *wv_a4 = tmp_block_state.fst + a * (uint32_t)1U;
    Lib_IntVector_Intrinsics_vec256 *wv_b4 = tmp_block_state.fst + b10 * (uint32_t)1U;
    wv_a4[0U] = Lib_IntVector_Intrinsics_vec256_add64(wv_a4[0U], wv_b4[0U]);
    wv_a4[0U] = Lib_IntVector_Intrinsics_vec256_add64(wv_a4[0U], y[0U]);
    Lib_IntVector_Intrinsics_vec256 *wv_a5 = tmp_block_state.fst + d0 * (uint32_t)1U;
    Lib_IntVector_Intrinsics_vec256 *wv_b5 = tmp_block_state.fst + a * (uint32_t)1U;
    wv_a5[0U] = Lib_IntVector_Intrinsics_vec256_xor(wv_a5[0U], wv_b5[0U]);
    wv_a5[0U] = Lib_IntVector_Intrinsics_vec256_rotate_right64(wv_a5[0U], r21);
    Lib_IntVector_Intrinsics_vec256 *wv_a6 = tmp_block_state.fst + c0 * (uint32_t)1U;
    Lib_IntVector_Intrinsics_vec256 *wv_b6 = tmp_block_state.fst + d0 * (uint32_t)1U;
    wv_a6[0U] = Lib_IntVector_Intrinsics_vec256_add64(wv_a6[0U], wv_b6[0U]);
    Lib_IntVector_Intrinsics_vec256 *wv_a7 = tmp_block_state.fst + b10 * (uint32_t)1U;
    Lib_IntVector_Intrinsics_vec256 *wv_b7 = tmp_block_state.fst + c0 * (uint32_t)1U;
    wv_a7[0U] = Lib_IntVector_Intrinsics_vec256_xor(wv_a7[0U], wv_b7[0U]);
    wv_a7[0U] = Lib_IntVector_Intrinsics_vec256_rotate_right64(wv_a7[0U], r31);
    Lib_IntVector_Intrinsics_vec256 *r12 = tmp_block_state.fst + (uint32_t)1U * (uint32_t)1U;
    Lib_IntVector_Intrinsics_vec256 *r22 = tmp_block_state.fst + (uint32_t)2U * (uint32_t)1U;
    Lib_IntVector_Intrinsics_vec256 *r32 = tmp_block_state.fst + (uint32_t)3U * (uint32_t)1U;
    Lib_IntVector_Intrinsics_vec256 v00 = r12[0U];
    Lib_IntVector_Intrinsics_vec256
    v1 = Lib_IntVector_Intrinsics_vec256_rotate_right_lanes64(v00, (uint32_t)1U);
    r12[0U] = v1;
    Lib_IntVector_Intrinsics_vec256 v01 = r22[0U];
    Lib_IntVector_Intrinsics_vec256
    v10 = Lib_IntVector_Intrinsics_vec256_rotate_right_lanes64(v01, (uint32_t)2U);
    r22[0U] = v10;
    Lib_IntVector_Intrinsics_vec256 v02 = r32[0U];
    Lib_IntVector_Intrinsics_vec256
    v11 = Lib_IntVector_Intrinsics_vec256_rotate_right_lanes64(v02, (uint32_t)3U);
    r32[0U] = v11;
    uint32_t a0 = (uint32_t)0U;
    uint32_t b1 = (uint32_t)1U;
    uint32_t c = (uint32_t)2U;
    uint32_t d = (uint32_t)3U;
    uint32_t r0 = Hacl_Impl_Blake2_Constants_rTable_B[0U];
    uint32_t r1 = Hacl_Impl_Blake2_Constants_rTable_B[1U];
    uint32_t r23 = Hacl_Impl_Blake2_Constants_rTable_B[2U];
    uint32_t r33 = Hacl_Impl_Blake2_Constants_rTable_B[3U];
    Lib_IntVector_Intrinsics_vec256 *wv_a = tmp_block_state.fst + a0 * (uint32_t)1U;
    Lib_IntVector_Intrinsics_vec256 *wv_b8 = tmp_block_state.fst + b1 * (uint32_t)1U;
    wv_a[0U] = Lib_IntVector_Intrinsics_vec256_add64(wv_a[0U], wv_b8[0U]);
    wv_a[0U] = Lib_IntVector_Intrinsics_vec256_add64(wv_a[0U], z[0U]);
    Lib_IntVector_Intrinsics_vec256 *wv_a8 = tmp_block_state.fst + d * (uint32_t)1U;
    Lib_IntVector_Intrinsics_vec256 *wv_b9 = tmp_block_state.fst + a0 * (uint32_t)1U;
    wv_a8[0U] = Lib_IntVector_Intrinsics_vec256_xor(wv_a8[0U], wv_b9[0U]);
    wv_a8[0U] = Lib_IntVector_Intrinsics_vec256_rotate_right64(wv_a8[0U], r0);
    Lib_IntVector_Intrinsics_vec256 *wv_a9 = tmp_block_state.fst + c * (uint32_t)1U;
    Lib_IntVector_Intrinsics_vec256 *wv_b10 = tmp_block_state.fst + d * (uint32_t)1U;
    wv_a9[0U] = Lib_IntVector_Intrinsics_vec256_add64(wv_a9[0U], wv_b10[0U]);
    Lib_IntVector_Intrinsics_vec256 *wv_a10 = tmp_block_state.fst + b1 * (uint32_t)1U;
    Lib_IntVector_Intrinsics_vec256 *wv_b11 = tmp_block_state.fst + c * (uint32_t)1U;
    wv_a10[0U] = Lib_IntVector_Intrinsics_vec256_xor(wv_a10[0U], wv_b11[0U]);
    wv_a10[0U] = Lib_IntVector_Intrinsics_vec256_rotate_right64(wv_a10[0U], r1);
    Lib_IntVector_Intrinsics_vec256 *wv_a11 = tmp_block_state.fst + a0 * (uint32_t)1U;
    Lib_IntVector_Intrinsics_vec256 *wv_b12 = tmp_block_state.fst + b1 * (uint32_t)1U;
    wv_a11[0U] = Lib_IntVector_Intrinsics_vec256_add64(wv_a11[0U], wv_b12[0U]);
    wv_a11[0U] = Lib_IntVector_Intrinsics_vec256_add64(wv_a11[0U], w[0U]);
    Lib_IntVector_Intrinsics_vec256 *wv_a12 = tmp_block_state.fst + d * (uint32_t)1U;
    Lib_IntVector_Intrinsics_vec256 *wv_b13 = tmp_block_state.fst + a0 * (uint32_t)1U;
    wv_a12[0U] = Lib_IntVector_Intrinsics_vec256_xor(wv_a12[0U], wv_b13[0U]);
    wv_a12[0U] = Lib_IntVector_Intrinsics_vec256_rotate_right64(wv_a12[0U], r23);
    Lib_IntVector_Intrinsics_vec256 *wv_a13 = tmp_block_state.fst + c * (uint32_t)1U;
    Lib_IntVector_Intrinsics_vec256 *wv_b14 = tmp_block_state.fst + d * (uint32_t)1U;
    wv_a13[0U] = Lib_IntVector_Intrinsics_vec256_add64(wv_a13[0U], wv_b14[0U]);
    Lib_IntVector_Intrinsics_vec256 *wv_a14 = tmp_block_state.fst + b1 * (uint32_t)1U;
    Lib_IntVector_Intrinsics_vec256 *wv_b = tmp_block_state.fst + c * (uint32_t)1U;
    wv_a14[0U] = Lib_IntVector_Intrinsics_vec256_xor(wv_a14[0U], wv_b[0U]);
    wv_a14[0U] = Lib_IntVector_Intrinsics_vec256_rotate_right64(wv_a14[0U], r33);
    Lib_IntVector_Intrinsics_vec256 *r13 = tmp_block_state.fst + (uint32_t)1U * (uint32_t)1U;
    Lib_IntVector_Intrinsics_vec256 *r2 = tmp_block_state.fst + (uint32_t)2U * (uint32_t)1U;
    Lib_IntVector_Intrinsics_vec256 *r3 = tmp_block_state.fst + (uint32_t)3U * (uint32_t)1U;
    Lib_IntVector_Intrinsics_vec256 v0 = r13[0U];
    Lib_IntVector_Intrinsics_vec256
    v12 = Lib_IntVector_Intrinsics_vec256_rotate_right_lanes64(v0, (uint32_t)3U);
    r13[0U] = v12;
    Lib_IntVector_Intrinsics_vec256 v03 = r2[0U];
    Lib_IntVector_Intrinsics_vec256
    v13 = Lib_IntVector_Intrinsics_vec256_rotate_right_lanes64(v03, (uint32_t)2U);
    r2[0U] = v13;
    Lib_IntVector_Intrinsics_vec256 v04 = r3[0U];
    Lib_IntVector_Intrinsics_vec256
    v14 = Lib_IntVector_Intrinsics_vec256_rotate_right_lanes64(v04, (uint32_t)1U);
    r3[0U] = v14;
  }
  Lib_IntVector_Intrinsics_vec256 *s0 = tmp_block_state.snd + (uint32_t)0U * (uint32_t)1U;
  Lib_IntVector_Intrinsics_vec256 *s1 = tmp_block_state.snd + (uint32_t)1U * (uint32_t)1U;
  Lib_IntVector_Intrinsics_vec256 *r0 = tmp_block_state.fst + (uint32_t)0U * (uint32_t)1U;
  Lib_IntVector_Intrinsics_vec256 *r1 = tmp_block_state.fst + (uint32_t)1U * (uint32_t)1U;
  Lib_IntVector_Intrinsics_vec256 *r2 = tmp_block_state.fst + (uint32_t)2U * (uint32_t)1U;
  Lib_IntVector_Intrinsics_vec256 *r3 = tmp_block_state.fst + (uint32_t)3U * (uint32_t)1U;
  s0[0U] = Lib_IntVector_Intrinsics_vec256_xor(s0[0U], r0[0U]);
  s0[0U] = Lib_IntVector_Intrinsics_vec256_xor(s0[0U], r2[0U]);
  s1[0U] = Lib_IntVector_Intrinsics_vec256_xor(s1[0U], r1[0U]);
  s1[0U] = Lib_IntVector_Intrinsics_vec256_xor(s1[0U], r3[0U]);
  Lib_Memzero0_memzero(b2, (uint32_t)128U * sizeof (b2[0U]));
  uint32_t double_row = (uint32_t)2U * (uint32_t)4U * (uint32_t)8U;
  KRML_CHECK_SIZE(sizeof (uint8_t), double_row);
  uint8_t b[double_row];
  memset(b, 0U, double_row * sizeof (b[0U]));
  uint8_t *first = b;
  uint8_t *second = b + (uint32_t)4U * (uint32_t)8U;
  Lib_IntVector_Intrinsics_vec256 *row0 = tmp_block_state.snd + (uint32_t)0U * (uint32_t)1U;
  Lib_IntVector_Intrinsics_vec256 *row1 = tmp_block_state.snd + (uint32_t)1U * (uint32_t)1U;
  Lib_IntVector_Intrinsics_vec256_store_le(first, row0[0U]);
  Lib_IntVector_Intrinsics_vec256_store_le(second, row1[0U]);
  uint8_t *final = b;
  memcpy(dst, final, (uint32_t)64U * sizeof (final[0U]));
  Lib_Memzero0_memzero(b, double_row * sizeof (b[0U]));
}

/* SNIPPET_END: Hacl_Streaming_Blake2_blake2b_256_no_key_finish */

/* SNIPPET_START: Hacl_Streaming_Blake2_blake2b_256_no_key_free */

/*
  Free state function when there is no key
*/
void
Hacl_Streaming_Blake2_blake2b_256_no_key_free(
  Hacl_Streaming_Functor_state_s__K____Lib_IntVector_Intrinsics_vec256___Lib_IntVector_Intrinsics_vec256____
  *s1
)
{
  Hacl_Streaming_Functor_state_s__K____Lib_IntVector_Intrinsics_vec256___Lib_IntVector_Intrinsics_vec256____
  scrut = *s1;
  uint8_t *buf = scrut.buf;
  K____Lib_IntVector_Intrinsics_vec256___Lib_IntVector_Intrinsics_vec256_
  block_state = scrut.block_state;
  Lib_IntVector_Intrinsics_vec256 *wv = block_state.fst;
  Lib_IntVector_Intrinsics_vec256 *b = block_state.snd;
  KRML_HOST_FREE(wv);
  KRML_HOST_FREE(b);
  KRML_HOST_FREE(buf);
  KRML_HOST_FREE(s1);
}

/* SNIPPET_END: Hacl_Streaming_Blake2_blake2b_256_no_key_free */

/* SNIPPET_START: Hacl_Streaming_Blake2_blake2s_32_with_key_create_in */

/*
  State allocation function when using a (potentially null) key
*/
Hacl_Streaming_Functor_state_s__K____uint32_t___uint32_t____
*Hacl_Streaming_Blake2_blake2s_32_with_key_create_in(uint32_t key_size, uint8_t *k1)
{
  uint8_t *buf = KRML_HOST_CALLOC((uint32_t)64U, sizeof (uint8_t));
  uint32_t *wv = KRML_HOST_CALLOC((uint32_t)16U, sizeof (uint32_t));
  uint32_t *b0 = KRML_HOST_CALLOC((uint32_t)16U, sizeof (uint32_t));
  K____uint32_t___uint32_t_ block_state = { .fst = wv, .snd = b0 };
  Hacl_Streaming_Functor_state_s__K____uint32_t___uint32_t____
  s1 = { .block_state = block_state, .buf = buf, .total_len = (uint64_t)0U };
  KRML_CHECK_SIZE(sizeof (Hacl_Streaming_Functor_state_s__K____uint32_t___uint32_t____),
    (uint32_t)1U);
  Hacl_Streaming_Functor_state_s__K____uint32_t___uint32_t____
  *p = KRML_HOST_MALLOC(sizeof (Hacl_Streaming_Functor_state_s__K____uint32_t___uint32_t____));
  p[0U] = s1;
  uint8_t b[64U] = { 0U };
  uint32_t *r00 = block_state.snd + (uint32_t)0U * (uint32_t)4U;
  uint32_t *r10 = block_state.snd + (uint32_t)1U * (uint32_t)4U;
  uint32_t *r20 = block_state.snd + (uint32_t)2U * (uint32_t)4U;
  uint32_t *r30 = block_state.snd + (uint32_t)3U * (uint32_t)4U;
  uint32_t iv0 = Hacl_Impl_Blake2_Constants_ivTable_S[0U];
  uint32_t iv1 = Hacl_Impl_Blake2_Constants_ivTable_S[1U];
  uint32_t iv2 = Hacl_Impl_Blake2_Constants_ivTable_S[2U];
  uint32_t iv3 = Hacl_Impl_Blake2_Constants_ivTable_S[3U];
  uint32_t iv4 = Hacl_Impl_Blake2_Constants_ivTable_S[4U];
  uint32_t iv5 = Hacl_Impl_Blake2_Constants_ivTable_S[5U];
  uint32_t iv6 = Hacl_Impl_Blake2_Constants_ivTable_S[6U];
  uint32_t iv7 = Hacl_Impl_Blake2_Constants_ivTable_S[7U];
  r20[0U] = iv0;
  r20[1U] = iv1;
  r20[2U] = iv2;
  r20[3U] = iv3;
  r30[0U] = iv4;
  r30[1U] = iv5;
  r30[2U] = iv6;
  r30[3U] = iv7;
  uint32_t kk_shift_8 = key_size << (uint32_t)8U;
  uint32_t iv0_ = iv0 ^ ((uint32_t)0x01010000U ^ (kk_shift_8 ^ (uint32_t)32U));
  r00[0U] = iv0_;
  r00[1U] = iv1;
  r00[2U] = iv2;
  r00[3U] = iv3;
  r10[0U] = iv4;
  r10[1U] = iv5;
  r10[2U] = iv6;
  r10[3U] = iv7;
  if (!(key_size == (uint32_t)0U))
  {
    memcpy(b, k1, key_size * sizeof (k1[0U]));
    uint64_t totlen = (uint64_t)(uint32_t)0U + (uint64_t)(uint32_t)64U;
    uint8_t *b1 = b + (uint32_t)0U * (uint32_t)64U;
    uint32_t m_w[16U] = { 0U };
    for (uint32_t i = (uint32_t)0U; i < (uint32_t)16U; i++)
    {
      uint32_t *os = m_w;
      uint8_t *bj = b1 + i * (uint32_t)4U;
      uint32_t u = load32_le(bj);
      uint32_t r1 = u;
      uint32_t x = r1;
      os[i] = x;
    }
    uint32_t mask[4U] = { 0U };
    uint32_t wv_14 = (uint32_t)0U;
    uint32_t wv_15 = (uint32_t)0U;
    mask[0U] = (uint32_t)totlen;
    mask[1U] = (uint32_t)(totlen >> (uint32_t)32U);
    mask[2U] = wv_14;
    mask[3U] = wv_15;
    memcpy(block_state.fst,
      block_state.snd,
      (uint32_t)4U * (uint32_t)4U * sizeof (block_state.snd[0U]));
    uint32_t *wv3 = block_state.fst + (uint32_t)3U * (uint32_t)4U;
    for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
    {
      uint32_t *os = wv3;
      uint32_t x = wv3[i] ^ mask[i];
      os[i] = x;
    }
    for (uint32_t i0 = (uint32_t)0U; i0 < (uint32_t)10U; i0++)
    {
      uint32_t start_idx = i0 % (uint32_t)10U * (uint32_t)16U;
      KRML_CHECK_SIZE(sizeof (uint32_t), (uint32_t)4U * (uint32_t)4U);
      uint32_t m_st[(uint32_t)4U * (uint32_t)4U];
      memset(m_st, 0U, (uint32_t)4U * (uint32_t)4U * sizeof (m_st[0U]));
      uint32_t *r01 = m_st + (uint32_t)0U * (uint32_t)4U;
      uint32_t *r12 = m_st + (uint32_t)1U * (uint32_t)4U;
      uint32_t *r21 = m_st + (uint32_t)2U * (uint32_t)4U;
      uint32_t *r31 = m_st + (uint32_t)3U * (uint32_t)4U;
      uint32_t s0 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx];
      uint32_t s11 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)1U];
      uint32_t s2 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)2U];
      uint32_t s3 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)3U];
      uint32_t s4 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)4U];
      uint32_t s5 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)5U];
      uint32_t s6 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)6U];
      uint32_t s7 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)7U];
      uint32_t s8 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)8U];
      uint32_t s9 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)9U];
      uint32_t s10 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)10U];
      uint32_t s111 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)11U];
      uint32_t s12 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)12U];
      uint32_t s13 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)13U];
      uint32_t s14 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)14U];
      uint32_t s15 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)15U];
      uint32_t uu____0 = m_w[s2];
      uint32_t uu____1 = m_w[s4];
      uint32_t uu____2 = m_w[s6];
      r01[0U] = m_w[s0];
      r01[1U] = uu____0;
      r01[2U] = uu____1;
      r01[3U] = uu____2;
      uint32_t uu____3 = m_w[s3];
      uint32_t uu____4 = m_w[s5];
      uint32_t uu____5 = m_w[s7];
      r12[0U] = m_w[s11];
      r12[1U] = uu____3;
      r12[2U] = uu____4;
      r12[3U] = uu____5;
      uint32_t uu____6 = m_w[s10];
      uint32_t uu____7 = m_w[s12];
      uint32_t uu____8 = m_w[s14];
      r21[0U] = m_w[s8];
      r21[1U] = uu____6;
      r21[2U] = uu____7;
      r21[3U] = uu____8;
      uint32_t uu____9 = m_w[s111];
      uint32_t uu____10 = m_w[s13];
      uint32_t uu____11 = m_w[s15];
      r31[0U] = m_w[s9];
      r31[1U] = uu____9;
      r31[2U] = uu____10;
      r31[3U] = uu____11;
      uint32_t *x = m_st + (uint32_t)0U * (uint32_t)4U;
      uint32_t *y = m_st + (uint32_t)1U * (uint32_t)4U;
      uint32_t *z = m_st + (uint32_t)2U * (uint32_t)4U;
      uint32_t *w = m_st + (uint32_t)3U * (uint32_t)4U;
      uint32_t a = (uint32_t)0U;
      uint32_t b20 = (uint32_t)1U;
      uint32_t c0 = (uint32_t)2U;
      uint32_t d0 = (uint32_t)3U;
      uint32_t r02 = Hacl_Impl_Blake2_Constants_rTable_S[0U];
      uint32_t r13 = Hacl_Impl_Blake2_Constants_rTable_S[1U];
      uint32_t r22 = Hacl_Impl_Blake2_Constants_rTable_S[2U];
      uint32_t r32 = Hacl_Impl_Blake2_Constants_rTable_S[3U];
      uint32_t *wv_a0 = block_state.fst + a * (uint32_t)4U;
      uint32_t *wv_b0 = block_state.fst + b20 * (uint32_t)4U;
      for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
      {
        uint32_t *os = wv_a0;
        uint32_t x1 = wv_a0[i] + wv_b0[i];
        os[i] = x1;
      }
      for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
      {
        uint32_t *os = wv_a0;
        uint32_t x1 = wv_a0[i] + x[i];
        os[i] = x1;
      }
      uint32_t *wv_a1 = block_state.fst + d0 * (uint32_t)4U;
      uint32_t *wv_b1 = block_state.fst + a * (uint32_t)4U;
      for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
      {
        uint32_t *os = wv_a1;
        uint32_t x1 = wv_a1[i] ^ wv_b1[i];
        os[i] = x1;
      }
      uint32_t *r110 = wv_a1;
      for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
      {
        uint32_t *os = r110;
        uint32_t x1 = r110[i];
        uint32_t x10 = x1 >> r02 | x1 << ((uint32_t)32U - r02);
        os[i] = x10;
      }
      uint32_t *wv_a2 = block_state.fst + c0 * (uint32_t)4U;
      uint32_t *wv_b2 = block_state.fst + d0 * (uint32_t)4U;
      for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
      {
        uint32_t *os = wv_a2;
        uint32_t x1 = wv_a2[i] + wv_b2[i];
        os[i] = x1;
      }
      uint32_t *wv_a3 = block_state.fst + b20 * (uint32_t)4U;
      uint32_t *wv_b3 = block_state.fst + c0 * (uint32_t)4U;
      for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
      {
        uint32_t *os = wv_a3;
        uint32_t x1 = wv_a3[i] ^ wv_b3[i];
        os[i] = x1;
      }
      uint32_t *r111 = wv_a3;
      for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
      {
        uint32_t *os = r111;
        uint32_t x1 = r111[i];
        uint32_t x10 = x1 >> r13 | x1 << ((uint32_t)32U - r13);
        os[i] = x10;
      }
      uint32_t *wv_a4 = block_state.fst + a * (uint32_t)4U;
      uint32_t *wv_b4 = block_state.fst + b20 * (uint32_t)4U;
      for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
      {
        uint32_t *os = wv_a4;
        uint32_t x1 = wv_a4[i] + wv_b4[i];
        os[i] = x1;
      }
      for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
      {
        uint32_t *os = wv_a4;
        uint32_t x1 = wv_a4[i] + y[i];
        os[i] = x1;
      }
      uint32_t *wv_a5 = block_state.fst + d0 * (uint32_t)4U;
      uint32_t *wv_b5 = block_state.fst + a * (uint32_t)4U;
      for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
      {
        uint32_t *os = wv_a5;
        uint32_t x1 = wv_a5[i] ^ wv_b5[i];
        os[i] = x1;
      }
      uint32_t *r112 = wv_a5;
      for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
      {
        uint32_t *os = r112;
        uint32_t x1 = r112[i];
        uint32_t x10 = x1 >> r22 | x1 << ((uint32_t)32U - r22);
        os[i] = x10;
      }
      uint32_t *wv_a6 = block_state.fst + c0 * (uint32_t)4U;
      uint32_t *wv_b6 = block_state.fst + d0 * (uint32_t)4U;
      for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
      {
        uint32_t *os = wv_a6;
        uint32_t x1 = wv_a6[i] + wv_b6[i];
        os[i] = x1;
      }
      uint32_t *wv_a7 = block_state.fst + b20 * (uint32_t)4U;
      uint32_t *wv_b7 = block_state.fst + c0 * (uint32_t)4U;
      for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
      {
        uint32_t *os = wv_a7;
        uint32_t x1 = wv_a7[i] ^ wv_b7[i];
        os[i] = x1;
      }
      uint32_t *r113 = wv_a7;
      for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
      {
        uint32_t *os = r113;
        uint32_t x1 = r113[i];
        uint32_t x10 = x1 >> r32 | x1 << ((uint32_t)32U - r32);
        os[i] = x10;
      }
      uint32_t *r14 = block_state.fst + (uint32_t)1U * (uint32_t)4U;
      uint32_t *r23 = block_state.fst + (uint32_t)2U * (uint32_t)4U;
      uint32_t *r33 = block_state.fst + (uint32_t)3U * (uint32_t)4U;
      uint32_t *r114 = r14;
      uint32_t x00 = r114[1U];
      uint32_t x10 = r114[((uint32_t)1U + (uint32_t)1U) % (uint32_t)4U];
      uint32_t x20 = r114[((uint32_t)1U + (uint32_t)2U) % (uint32_t)4U];
      uint32_t x30 = r114[((uint32_t)1U + (uint32_t)3U) % (uint32_t)4U];
      r114[0U] = x00;
      r114[1U] = x10;
      r114[2U] = x20;
      r114[3U] = x30;
      uint32_t *r115 = r23;
      uint32_t x01 = r115[2U];
      uint32_t x11 = r115[((uint32_t)2U + (uint32_t)1U) % (uint32_t)4U];
      uint32_t x21 = r115[((uint32_t)2U + (uint32_t)2U) % (uint32_t)4U];
      uint32_t x31 = r115[((uint32_t)2U + (uint32_t)3U) % (uint32_t)4U];
      r115[0U] = x01;
      r115[1U] = x11;
      r115[2U] = x21;
      r115[3U] = x31;
      uint32_t *r116 = r33;
      uint32_t x02 = r116[3U];
      uint32_t x12 = r116[((uint32_t)3U + (uint32_t)1U) % (uint32_t)4U];
      uint32_t x22 = r116[((uint32_t)3U + (uint32_t)2U) % (uint32_t)4U];
      uint32_t x32 = r116[((uint32_t)3U + (uint32_t)3U) % (uint32_t)4U];
      r116[0U] = x02;
      r116[1U] = x12;
      r116[2U] = x22;
      r116[3U] = x32;
      uint32_t a0 = (uint32_t)0U;
      uint32_t b2 = (uint32_t)1U;
      uint32_t c = (uint32_t)2U;
      uint32_t d = (uint32_t)3U;
      uint32_t r0 = Hacl_Impl_Blake2_Constants_rTable_S[0U];
      uint32_t r1 = Hacl_Impl_Blake2_Constants_rTable_S[1U];
      uint32_t r24 = Hacl_Impl_Blake2_Constants_rTable_S[2U];
      uint32_t r34 = Hacl_Impl_Blake2_Constants_rTable_S[3U];
      uint32_t *wv_a = block_state.fst + a0 * (uint32_t)4U;
      uint32_t *wv_b8 = block_state.fst + b2 * (uint32_t)4U;
      for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
      {
        uint32_t *os = wv_a;
        uint32_t x1 = wv_a[i] + wv_b8[i];
        os[i] = x1;
      }
      for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
      {
        uint32_t *os = wv_a;
        uint32_t x1 = wv_a[i] + z[i];
        os[i] = x1;
      }
      uint32_t *wv_a8 = block_state.fst + d * (uint32_t)4U;
      uint32_t *wv_b9 = block_state.fst + a0 * (uint32_t)4U;
      for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
      {
        uint32_t *os = wv_a8;
        uint32_t x1 = wv_a8[i] ^ wv_b9[i];
        os[i] = x1;
      }
      uint32_t *r117 = wv_a8;
      for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
      {
        uint32_t *os = r117;
        uint32_t x1 = r117[i];
        uint32_t x13 = x1 >> r0 | x1 << ((uint32_t)32U - r0);
        os[i] = x13;
      }
      uint32_t *wv_a9 = block_state.fst + c * (uint32_t)4U;
      uint32_t *wv_b10 = block_state.fst + d * (uint32_t)4U;
      for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
      {
        uint32_t *os = wv_a9;
        uint32_t x1 = wv_a9[i] + wv_b10[i];
        os[i] = x1;
      }
      uint32_t *wv_a10 = block_state.fst + b2 * (uint32_t)4U;
      uint32_t *wv_b11 = block_state.fst + c * (uint32_t)4U;
      for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
      {
        uint32_t *os = wv_a10;
        uint32_t x1 = wv_a10[i] ^ wv_b11[i];
        os[i] = x1;
      }
      uint32_t *r118 = wv_a10;
      for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
      {
        uint32_t *os = r118;
        uint32_t x1 = r118[i];
        uint32_t x13 = x1 >> r1 | x1 << ((uint32_t)32U - r1);
        os[i] = x13;
      }
      uint32_t *wv_a11 = block_state.fst + a0 * (uint32_t)4U;
      uint32_t *wv_b12 = block_state.fst + b2 * (uint32_t)4U;
      for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
      {
        uint32_t *os = wv_a11;
        uint32_t x1 = wv_a11[i] + wv_b12[i];
        os[i] = x1;
      }
      for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
      {
        uint32_t *os = wv_a11;
        uint32_t x1 = wv_a11[i] + w[i];
        os[i] = x1;
      }
      uint32_t *wv_a12 = block_state.fst + d * (uint32_t)4U;
      uint32_t *wv_b13 = block_state.fst + a0 * (uint32_t)4U;
      for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
      {
        uint32_t *os = wv_a12;
        uint32_t x1 = wv_a12[i] ^ wv_b13[i];
        os[i] = x1;
      }
      uint32_t *r119 = wv_a12;
      for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
      {
        uint32_t *os = r119;
        uint32_t x1 = r119[i];
        uint32_t x13 = x1 >> r24 | x1 << ((uint32_t)32U - r24);
        os[i] = x13;
      }
      uint32_t *wv_a13 = block_state.fst + c * (uint32_t)4U;
      uint32_t *wv_b14 = block_state.fst + d * (uint32_t)4U;
      for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
      {
        uint32_t *os = wv_a13;
        uint32_t x1 = wv_a13[i] + wv_b14[i];
        os[i] = x1;
      }
      uint32_t *wv_a14 = block_state.fst + b2 * (uint32_t)4U;
      uint32_t *wv_b = block_state.fst + c * (uint32_t)4U;
      for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
      {
        uint32_t *os = wv_a14;
        uint32_t x1 = wv_a14[i] ^ wv_b[i];
        os[i] = x1;
      }
      uint32_t *r1110 = wv_a14;
      for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
      {
        uint32_t *os = r1110;
        uint32_t x1 = r1110[i];
        uint32_t x13 = x1 >> r34 | x1 << ((uint32_t)32U - r34);
        os[i] = x13;
      }
      uint32_t *r15 = block_state.fst + (uint32_t)1U * (uint32_t)4U;
      uint32_t *r2 = block_state.fst + (uint32_t)2U * (uint32_t)4U;
      uint32_t *r3 = block_state.fst + (uint32_t)3U * (uint32_t)4U;
      uint32_t *r11 = r15;
      uint32_t x03 = r11[3U];
      uint32_t x13 = r11[((uint32_t)3U + (uint32_t)1U) % (uint32_t)4U];
      uint32_t x23 = r11[((uint32_t)3U + (uint32_t)2U) % (uint32_t)4U];
      uint32_t x33 = r11[((uint32_t)3U + (uint32_t)3U) % (uint32_t)4U];
      r11[0U] = x03;
      r11[1U] = x13;
      r11[2U] = x23;
      r11[3U] = x33;
      uint32_t *r1111 = r2;
      uint32_t x04 = r1111[2U];
      uint32_t x14 = r1111[((uint32_t)2U + (uint32_t)1U) % (uint32_t)4U];
      uint32_t x24 = r1111[((uint32_t)2U + (uint32_t)2U) % (uint32_t)4U];
      uint32_t x34 = r1111[((uint32_t)2U + (uint32_t)3U) % (uint32_t)4U];
      r1111[0U] = x04;
      r1111[1U] = x14;
      r1111[2U] = x24;
      r1111[3U] = x34;
      uint32_t *r1112 = r3;
      uint32_t x0 = r1112[1U];
      uint32_t x1 = r1112[((uint32_t)1U + (uint32_t)1U) % (uint32_t)4U];
      uint32_t x2 = r1112[((uint32_t)1U + (uint32_t)2U) % (uint32_t)4U];
      uint32_t x3 = r1112[((uint32_t)1U + (uint32_t)3U) % (uint32_t)4U];
      r1112[0U] = x0;
      r1112[1U] = x1;
      r1112[2U] = x2;
      r1112[3U] = x3;
    }
    uint32_t *s0 = block_state.snd + (uint32_t)0U * (uint32_t)4U;
    uint32_t *s11 = block_state.snd + (uint32_t)1U * (uint32_t)4U;
    uint32_t *r0 = block_state.fst + (uint32_t)0U * (uint32_t)4U;
    uint32_t *r1 = block_state.fst + (uint32_t)1U * (uint32_t)4U;
    uint32_t *r2 = block_state.fst + (uint32_t)2U * (uint32_t)4U;
    uint32_t *r3 = block_state.fst + (uint32_t)3U * (uint32_t)4U;
    for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
    {
      uint32_t *os = s0;
      uint32_t x = s0[i] ^ r0[i];
      os[i] = x;
    }
    for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
    {
      uint32_t *os = s0;
      uint32_t x = s0[i] ^ r2[i];
      os[i] = x;
    }
    for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
    {
      uint32_t *os = s11;
      uint32_t x = s11[i] ^ r1[i];
      os[i] = x;
    }
    for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
    {
      uint32_t *os = s11;
      uint32_t x = s11[i] ^ r3[i];
      os[i] = x;
    }
  }
  Lib_Memzero0_memzero(b, (uint32_t)64U * sizeof (b[0U]));
  return p;
}

/* SNIPPET_END: Hacl_Streaming_Blake2_blake2s_32_with_key_create_in */

/* SNIPPET_START: Hacl_Streaming_Blake2_blake2s_32_with_key_update */

/*
  Update function when using a (potentially null) key
*/
void
Hacl_Streaming_Blake2_blake2s_32_with_key_update(
  uint32_t key_size,
  Hacl_Streaming_Functor_state_s__K____uint32_t___uint32_t____ *p,
  uint8_t *data,
  uint32_t len
)
{
  Hacl_Streaming_Functor_state_s__K____uint32_t___uint32_t____ s1 = *p;
  uint64_t total_len = s1.total_len;
  uint32_t sz;
  if (total_len % (uint64_t)(uint32_t)64U == (uint64_t)0U && total_len > (uint64_t)0U)
  {
    sz = (uint32_t)64U;
  }
  else
  {
    sz = (uint32_t)(total_len % (uint64_t)(uint32_t)64U);
  }
  if (len <= (uint32_t)64U - sz)
  {
    Hacl_Streaming_Functor_state_s__K____uint32_t___uint32_t____ s2 = *p;
    K____uint32_t___uint32_t_ block_state1 = s2.block_state;
    uint8_t *buf = s2.buf;
    uint64_t total_len1 = s2.total_len;
    uint32_t sz1;
    if (total_len1 % (uint64_t)(uint32_t)64U == (uint64_t)0U && total_len1 > (uint64_t)0U)
    {
      sz1 = (uint32_t)64U;
    }
    else
    {
      sz1 = (uint32_t)(total_len1 % (uint64_t)(uint32_t)64U);
    }
    uint8_t *buf2 = buf + sz1;
    memcpy(buf2, data, len * sizeof (data[0U]));
    uint64_t total_len2 = total_len1 + (uint64_t)len;
    *p
    =
      (
        (Hacl_Streaming_Functor_state_s__K____uint32_t___uint32_t____){
          .block_state = block_state1,
          .buf = buf,
          .total_len = total_len2
        }
      );
    return;
  }
  if (sz == (uint32_t)0U)
  {
    Hacl_Streaming_Functor_state_s__K____uint32_t___uint32_t____ s2 = *p;
    K____uint32_t___uint32_t_ block_state1 = s2.block_state;
    uint8_t *buf = s2.buf;
    uint64_t total_len1 = s2.total_len;
    uint32_t sz1;
    if (total_len1 % (uint64_t)(uint32_t)64U == (uint64_t)0U && total_len1 > (uint64_t)0U)
    {
      sz1 = (uint32_t)64U;
    }
    else
    {
      sz1 = (uint32_t)(total_len1 % (uint64_t)(uint32_t)64U);
    }
    if (!(sz1 == (uint32_t)0U))
    {
      uint64_t prevlen = total_len1 - (uint64_t)sz1;
      uint32_t nb = (uint32_t)1U;
      for (uint32_t i0 = (uint32_t)0U; i0 < nb; i0++)
      {
        uint64_t ite;
        if (key_size == (uint32_t)0U)
        {
          ite = prevlen;
        }
        else
        {
          ite = prevlen + (uint64_t)(uint32_t)64U;
        }
        uint64_t totlen = ite + (uint64_t)((i0 + (uint32_t)1U) * (uint32_t)64U);
        uint8_t *b = buf + i0 * (uint32_t)64U;
        uint32_t m_w[16U] = { 0U };
        for (uint32_t i = (uint32_t)0U; i < (uint32_t)16U; i++)
        {
          uint32_t *os = m_w;
          uint8_t *bj = b + i * (uint32_t)4U;
          uint32_t u = load32_le(bj);
          uint32_t r = u;
          uint32_t x = r;
          os[i] = x;
        }
        uint32_t mask[4U] = { 0U };
        uint32_t wv_14 = (uint32_t)0U;
        uint32_t wv_15 = (uint32_t)0U;
        mask[0U] = (uint32_t)totlen;
        mask[1U] = (uint32_t)(totlen >> (uint32_t)32U);
        mask[2U] = wv_14;
        mask[3U] = wv_15;
        memcpy(block_state1.fst,
          block_state1.snd,
          (uint32_t)4U * (uint32_t)4U * sizeof (block_state1.snd[0U]));
        uint32_t *wv3 = block_state1.fst + (uint32_t)3U * (uint32_t)4U;
        for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
        {
          uint32_t *os = wv3;
          uint32_t x = wv3[i] ^ mask[i];
          os[i] = x;
        }
        for (uint32_t i1 = (uint32_t)0U; i1 < (uint32_t)10U; i1++)
        {
          uint32_t start_idx = i1 % (uint32_t)10U * (uint32_t)16U;
          KRML_CHECK_SIZE(sizeof (uint32_t), (uint32_t)4U * (uint32_t)4U);
          uint32_t m_st[(uint32_t)4U * (uint32_t)4U];
          memset(m_st, 0U, (uint32_t)4U * (uint32_t)4U * sizeof (m_st[0U]));
          uint32_t *r00 = m_st + (uint32_t)0U * (uint32_t)4U;
          uint32_t *r10 = m_st + (uint32_t)1U * (uint32_t)4U;
          uint32_t *r20 = m_st + (uint32_t)2U * (uint32_t)4U;
          uint32_t *r30 = m_st + (uint32_t)3U * (uint32_t)4U;
          uint32_t s0 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx];
          uint32_t s11 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)1U];
          uint32_t s21 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)2U];
          uint32_t s3 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)3U];
          uint32_t s4 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)4U];
          uint32_t s5 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)5U];
          uint32_t s6 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)6U];
          uint32_t s7 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)7U];
          uint32_t s8 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)8U];
          uint32_t s9 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)9U];
          uint32_t s10 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)10U];
          uint32_t s111 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)11U];
          uint32_t s12 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)12U];
          uint32_t s13 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)13U];
          uint32_t s14 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)14U];
          uint32_t s15 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)15U];
          uint32_t uu____0 = m_w[s21];
          uint32_t uu____1 = m_w[s4];
          uint32_t uu____2 = m_w[s6];
          r00[0U] = m_w[s0];
          r00[1U] = uu____0;
          r00[2U] = uu____1;
          r00[3U] = uu____2;
          uint32_t uu____3 = m_w[s3];
          uint32_t uu____4 = m_w[s5];
          uint32_t uu____5 = m_w[s7];
          r10[0U] = m_w[s11];
          r10[1U] = uu____3;
          r10[2U] = uu____4;
          r10[3U] = uu____5;
          uint32_t uu____6 = m_w[s10];
          uint32_t uu____7 = m_w[s12];
          uint32_t uu____8 = m_w[s14];
          r20[0U] = m_w[s8];
          r20[1U] = uu____6;
          r20[2U] = uu____7;
          r20[3U] = uu____8;
          uint32_t uu____9 = m_w[s111];
          uint32_t uu____10 = m_w[s13];
          uint32_t uu____11 = m_w[s15];
          r30[0U] = m_w[s9];
          r30[1U] = uu____9;
          r30[2U] = uu____10;
          r30[3U] = uu____11;
          uint32_t *x = m_st + (uint32_t)0U * (uint32_t)4U;
          uint32_t *y = m_st + (uint32_t)1U * (uint32_t)4U;
          uint32_t *z = m_st + (uint32_t)2U * (uint32_t)4U;
          uint32_t *w = m_st + (uint32_t)3U * (uint32_t)4U;
          uint32_t a = (uint32_t)0U;
          uint32_t b10 = (uint32_t)1U;
          uint32_t c0 = (uint32_t)2U;
          uint32_t d0 = (uint32_t)3U;
          uint32_t r01 = Hacl_Impl_Blake2_Constants_rTable_S[0U];
          uint32_t r12 = Hacl_Impl_Blake2_Constants_rTable_S[1U];
          uint32_t r21 = Hacl_Impl_Blake2_Constants_rTable_S[2U];
          uint32_t r31 = Hacl_Impl_Blake2_Constants_rTable_S[3U];
          uint32_t *wv_a0 = block_state1.fst + a * (uint32_t)4U;
          uint32_t *wv_b0 = block_state1.fst + b10 * (uint32_t)4U;
          for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
          {
            uint32_t *os = wv_a0;
            uint32_t x1 = wv_a0[i] + wv_b0[i];
            os[i] = x1;
          }
          for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
          {
            uint32_t *os = wv_a0;
            uint32_t x1 = wv_a0[i] + x[i];
            os[i] = x1;
          }
          uint32_t *wv_a1 = block_state1.fst + d0 * (uint32_t)4U;
          uint32_t *wv_b1 = block_state1.fst + a * (uint32_t)4U;
          for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
          {
            uint32_t *os = wv_a1;
            uint32_t x1 = wv_a1[i] ^ wv_b1[i];
            os[i] = x1;
          }
          uint32_t *r110 = wv_a1;
          for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
          {
            uint32_t *os = r110;
            uint32_t x1 = r110[i];
            uint32_t x10 = x1 >> r01 | x1 << ((uint32_t)32U - r01);
            os[i] = x10;
          }
          uint32_t *wv_a2 = block_state1.fst + c0 * (uint32_t)4U;
          uint32_t *wv_b2 = block_state1.fst + d0 * (uint32_t)4U;
          for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
          {
            uint32_t *os = wv_a2;
            uint32_t x1 = wv_a2[i] + wv_b2[i];
            os[i] = x1;
          }
          uint32_t *wv_a3 = block_state1.fst + b10 * (uint32_t)4U;
          uint32_t *wv_b3 = block_state1.fst + c0 * (uint32_t)4U;
          for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
          {
            uint32_t *os = wv_a3;
            uint32_t x1 = wv_a3[i] ^ wv_b3[i];
            os[i] = x1;
          }
          uint32_t *r111 = wv_a3;
          for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
          {
            uint32_t *os = r111;
            uint32_t x1 = r111[i];
            uint32_t x10 = x1 >> r12 | x1 << ((uint32_t)32U - r12);
            os[i] = x10;
          }
          uint32_t *wv_a4 = block_state1.fst + a * (uint32_t)4U;
          uint32_t *wv_b4 = block_state1.fst + b10 * (uint32_t)4U;
          for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
          {
            uint32_t *os = wv_a4;
            uint32_t x1 = wv_a4[i] + wv_b4[i];
            os[i] = x1;
          }
          for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
          {
            uint32_t *os = wv_a4;
            uint32_t x1 = wv_a4[i] + y[i];
            os[i] = x1;
          }
          uint32_t *wv_a5 = block_state1.fst + d0 * (uint32_t)4U;
          uint32_t *wv_b5 = block_state1.fst + a * (uint32_t)4U;
          for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
          {
            uint32_t *os = wv_a5;
            uint32_t x1 = wv_a5[i] ^ wv_b5[i];
            os[i] = x1;
          }
          uint32_t *r112 = wv_a5;
          for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
          {
            uint32_t *os = r112;
            uint32_t x1 = r112[i];
            uint32_t x10 = x1 >> r21 | x1 << ((uint32_t)32U - r21);
            os[i] = x10;
          }
          uint32_t *wv_a6 = block_state1.fst + c0 * (uint32_t)4U;
          uint32_t *wv_b6 = block_state1.fst + d0 * (uint32_t)4U;
          for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
          {
            uint32_t *os = wv_a6;
            uint32_t x1 = wv_a6[i] + wv_b6[i];
            os[i] = x1;
          }
          uint32_t *wv_a7 = block_state1.fst + b10 * (uint32_t)4U;
          uint32_t *wv_b7 = block_state1.fst + c0 * (uint32_t)4U;
          for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
          {
            uint32_t *os = wv_a7;
            uint32_t x1 = wv_a7[i] ^ wv_b7[i];
            os[i] = x1;
          }
          uint32_t *r113 = wv_a7;
          for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
          {
            uint32_t *os = r113;
            uint32_t x1 = r113[i];
            uint32_t x10 = x1 >> r31 | x1 << ((uint32_t)32U - r31);
            os[i] = x10;
          }
          uint32_t *r13 = block_state1.fst + (uint32_t)1U * (uint32_t)4U;
          uint32_t *r22 = block_state1.fst + (uint32_t)2U * (uint32_t)4U;
          uint32_t *r32 = block_state1.fst + (uint32_t)3U * (uint32_t)4U;
          uint32_t *r114 = r13;
          uint32_t x00 = r114[1U];
          uint32_t x10 = r114[((uint32_t)1U + (uint32_t)1U) % (uint32_t)4U];
          uint32_t x20 = r114[((uint32_t)1U + (uint32_t)2U) % (uint32_t)4U];
          uint32_t x30 = r114[((uint32_t)1U + (uint32_t)3U) % (uint32_t)4U];
          r114[0U] = x00;
          r114[1U] = x10;
          r114[2U] = x20;
          r114[3U] = x30;
          uint32_t *r115 = r22;
          uint32_t x01 = r115[2U];
          uint32_t x11 = r115[((uint32_t)2U + (uint32_t)1U) % (uint32_t)4U];
          uint32_t x21 = r115[((uint32_t)2U + (uint32_t)2U) % (uint32_t)4U];
          uint32_t x31 = r115[((uint32_t)2U + (uint32_t)3U) % (uint32_t)4U];
          r115[0U] = x01;
          r115[1U] = x11;
          r115[2U] = x21;
          r115[3U] = x31;
          uint32_t *r116 = r32;
          uint32_t x02 = r116[3U];
          uint32_t x12 = r116[((uint32_t)3U + (uint32_t)1U) % (uint32_t)4U];
          uint32_t x22 = r116[((uint32_t)3U + (uint32_t)2U) % (uint32_t)4U];
          uint32_t x32 = r116[((uint32_t)3U + (uint32_t)3U) % (uint32_t)4U];
          r116[0U] = x02;
          r116[1U] = x12;
          r116[2U] = x22;
          r116[3U] = x32;
          uint32_t a0 = (uint32_t)0U;
          uint32_t b1 = (uint32_t)1U;
          uint32_t c = (uint32_t)2U;
          uint32_t d = (uint32_t)3U;
          uint32_t r0 = Hacl_Impl_Blake2_Constants_rTable_S[0U];
          uint32_t r1 = Hacl_Impl_Blake2_Constants_rTable_S[1U];
          uint32_t r23 = Hacl_Impl_Blake2_Constants_rTable_S[2U];
          uint32_t r33 = Hacl_Impl_Blake2_Constants_rTable_S[3U];
          uint32_t *wv_a = block_state1.fst + a0 * (uint32_t)4U;
          uint32_t *wv_b8 = block_state1.fst + b1 * (uint32_t)4U;
          for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
          {
            uint32_t *os = wv_a;
            uint32_t x1 = wv_a[i] + wv_b8[i];
            os[i] = x1;
          }
          for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
          {
            uint32_t *os = wv_a;
            uint32_t x1 = wv_a[i] + z[i];
            os[i] = x1;
          }
          uint32_t *wv_a8 = block_state1.fst + d * (uint32_t)4U;
          uint32_t *wv_b9 = block_state1.fst + a0 * (uint32_t)4U;
          for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
          {
            uint32_t *os = wv_a8;
            uint32_t x1 = wv_a8[i] ^ wv_b9[i];
            os[i] = x1;
          }
          uint32_t *r117 = wv_a8;
          for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
          {
            uint32_t *os = r117;
            uint32_t x1 = r117[i];
            uint32_t x13 = x1 >> r0 | x1 << ((uint32_t)32U - r0);
            os[i] = x13;
          }
          uint32_t *wv_a9 = block_state1.fst + c * (uint32_t)4U;
          uint32_t *wv_b10 = block_state1.fst + d * (uint32_t)4U;
          for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
          {
            uint32_t *os = wv_a9;
            uint32_t x1 = wv_a9[i] + wv_b10[i];
            os[i] = x1;
          }
          uint32_t *wv_a10 = block_state1.fst + b1 * (uint32_t)4U;
          uint32_t *wv_b11 = block_state1.fst + c * (uint32_t)4U;
          for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
          {
            uint32_t *os = wv_a10;
            uint32_t x1 = wv_a10[i] ^ wv_b11[i];
            os[i] = x1;
          }
          uint32_t *r118 = wv_a10;
          for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
          {
            uint32_t *os = r118;
            uint32_t x1 = r118[i];
            uint32_t x13 = x1 >> r1 | x1 << ((uint32_t)32U - r1);
            os[i] = x13;
          }
          uint32_t *wv_a11 = block_state1.fst + a0 * (uint32_t)4U;
          uint32_t *wv_b12 = block_state1.fst + b1 * (uint32_t)4U;
          for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
          {
            uint32_t *os = wv_a11;
            uint32_t x1 = wv_a11[i] + wv_b12[i];
            os[i] = x1;
          }
          for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
          {
            uint32_t *os = wv_a11;
            uint32_t x1 = wv_a11[i] + w[i];
            os[i] = x1;
          }
          uint32_t *wv_a12 = block_state1.fst + d * (uint32_t)4U;
          uint32_t *wv_b13 = block_state1.fst + a0 * (uint32_t)4U;
          for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
          {
            uint32_t *os = wv_a12;
            uint32_t x1 = wv_a12[i] ^ wv_b13[i];
            os[i] = x1;
          }
          uint32_t *r119 = wv_a12;
          for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
          {
            uint32_t *os = r119;
            uint32_t x1 = r119[i];
            uint32_t x13 = x1 >> r23 | x1 << ((uint32_t)32U - r23);
            os[i] = x13;
          }
          uint32_t *wv_a13 = block_state1.fst + c * (uint32_t)4U;
          uint32_t *wv_b14 = block_state1.fst + d * (uint32_t)4U;
          for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
          {
            uint32_t *os = wv_a13;
            uint32_t x1 = wv_a13[i] + wv_b14[i];
            os[i] = x1;
          }
          uint32_t *wv_a14 = block_state1.fst + b1 * (uint32_t)4U;
          uint32_t *wv_b = block_state1.fst + c * (uint32_t)4U;
          for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
          {
            uint32_t *os = wv_a14;
            uint32_t x1 = wv_a14[i] ^ wv_b[i];
            os[i] = x1;
          }
          uint32_t *r1110 = wv_a14;
          for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
          {
            uint32_t *os = r1110;
            uint32_t x1 = r1110[i];
            uint32_t x13 = x1 >> r33 | x1 << ((uint32_t)32U - r33);
            os[i] = x13;
          }
          uint32_t *r14 = block_state1.fst + (uint32_t)1U * (uint32_t)4U;
          uint32_t *r2 = block_state1.fst + (uint32_t)2U * (uint32_t)4U;
          uint32_t *r3 = block_state1.fst + (uint32_t)3U * (uint32_t)4U;
          uint32_t *r11 = r14;
          uint32_t x03 = r11[3U];
          uint32_t x13 = r11[((uint32_t)3U + (uint32_t)1U) % (uint32_t)4U];
          uint32_t x23 = r11[((uint32_t)3U + (uint32_t)2U) % (uint32_t)4U];
          uint32_t x33 = r11[((uint32_t)3U + (uint32_t)3U) % (uint32_t)4U];
          r11[0U] = x03;
          r11[1U] = x13;
          r11[2U] = x23;
          r11[3U] = x33;
          uint32_t *r1111 = r2;
          uint32_t x04 = r1111[2U];
          uint32_t x14 = r1111[((uint32_t)2U + (uint32_t)1U) % (uint32_t)4U];
          uint32_t x24 = r1111[((uint32_t)2U + (uint32_t)2U) % (uint32_t)4U];
          uint32_t x34 = r1111[((uint32_t)2U + (uint32_t)3U) % (uint32_t)4U];
          r1111[0U] = x04;
          r1111[1U] = x14;
          r1111[2U] = x24;
          r1111[3U] = x34;
          uint32_t *r1112 = r3;
          uint32_t x0 = r1112[1U];
          uint32_t x1 = r1112[((uint32_t)1U + (uint32_t)1U) % (uint32_t)4U];
          uint32_t x2 = r1112[((uint32_t)1U + (uint32_t)2U) % (uint32_t)4U];
          uint32_t x3 = r1112[((uint32_t)1U + (uint32_t)3U) % (uint32_t)4U];
          r1112[0U] = x0;
          r1112[1U] = x1;
          r1112[2U] = x2;
          r1112[3U] = x3;
        }
        uint32_t *s0 = block_state1.snd + (uint32_t)0U * (uint32_t)4U;
        uint32_t *s11 = block_state1.snd + (uint32_t)1U * (uint32_t)4U;
        uint32_t *r0 = block_state1.fst + (uint32_t)0U * (uint32_t)4U;
        uint32_t *r1 = block_state1.fst + (uint32_t)1U * (uint32_t)4U;
        uint32_t *r2 = block_state1.fst + (uint32_t)2U * (uint32_t)4U;
        uint32_t *r3 = block_state1.fst + (uint32_t)3U * (uint32_t)4U;
        for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
        {
          uint32_t *os = s0;
          uint32_t x = s0[i] ^ r0[i];
          os[i] = x;
        }
        for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
        {
          uint32_t *os = s0;
          uint32_t x = s0[i] ^ r2[i];
          os[i] = x;
        }
        for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
        {
          uint32_t *os = s11;
          uint32_t x = s11[i] ^ r1[i];
          os[i] = x;
        }
        for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
        {
          uint32_t *os = s11;
          uint32_t x = s11[i] ^ r3[i];
          os[i] = x;
        }
      }
    }
    uint32_t ite0;
    if ((uint64_t)len % (uint64_t)(uint32_t)64U == (uint64_t)0U && (uint64_t)len > (uint64_t)0U)
    {
      ite0 = (uint32_t)64U;
    }
    else
    {
      ite0 = (uint32_t)((uint64_t)len % (uint64_t)(uint32_t)64U);
    }
    uint32_t n_blocks = (len - ite0) / (uint32_t)64U;
    uint32_t data1_len = n_blocks * (uint32_t)64U;
    uint32_t data2_len = len - data1_len;
    uint8_t *data1 = data;
    uint8_t *data2 = data + data1_len;
    uint32_t nb = data1_len / (uint32_t)64U;
    for (uint32_t i0 = (uint32_t)0U; i0 < nb; i0++)
    {
      uint64_t ite;
      if (key_size == (uint32_t)0U)
      {
        ite = total_len1;
      }
      else
      {
        ite = total_len1 + (uint64_t)(uint32_t)64U;
      }
      uint64_t totlen = ite + (uint64_t)((i0 + (uint32_t)1U) * (uint32_t)64U);
      uint8_t *b = data1 + i0 * (uint32_t)64U;
      uint32_t m_w[16U] = { 0U };
      for (uint32_t i = (uint32_t)0U; i < (uint32_t)16U; i++)
      {
        uint32_t *os = m_w;
        uint8_t *bj = b + i * (uint32_t)4U;
        uint32_t u = load32_le(bj);
        uint32_t r = u;
        uint32_t x = r;
        os[i] = x;
      }
      uint32_t mask[4U] = { 0U };
      uint32_t wv_14 = (uint32_t)0U;
      uint32_t wv_15 = (uint32_t)0U;
      mask[0U] = (uint32_t)totlen;
      mask[1U] = (uint32_t)(totlen >> (uint32_t)32U);
      mask[2U] = wv_14;
      mask[3U] = wv_15;
      memcpy(block_state1.fst,
        block_state1.snd,
        (uint32_t)4U * (uint32_t)4U * sizeof (block_state1.snd[0U]));
      uint32_t *wv3 = block_state1.fst + (uint32_t)3U * (uint32_t)4U;
      for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
      {
        uint32_t *os = wv3;
        uint32_t x = wv3[i] ^ mask[i];
        os[i] = x;
      }
      for (uint32_t i1 = (uint32_t)0U; i1 < (uint32_t)10U; i1++)
      {
        uint32_t start_idx = i1 % (uint32_t)10U * (uint32_t)16U;
        KRML_CHECK_SIZE(sizeof (uint32_t), (uint32_t)4U * (uint32_t)4U);
        uint32_t m_st[(uint32_t)4U * (uint32_t)4U];
        memset(m_st, 0U, (uint32_t)4U * (uint32_t)4U * sizeof (m_st[0U]));
        uint32_t *r00 = m_st + (uint32_t)0U * (uint32_t)4U;
        uint32_t *r10 = m_st + (uint32_t)1U * (uint32_t)4U;
        uint32_t *r20 = m_st + (uint32_t)2U * (uint32_t)4U;
        uint32_t *r30 = m_st + (uint32_t)3U * (uint32_t)4U;
        uint32_t s0 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx];
        uint32_t s11 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)1U];
        uint32_t s21 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)2U];
        uint32_t s3 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)3U];
        uint32_t s4 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)4U];
        uint32_t s5 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)5U];
        uint32_t s6 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)6U];
        uint32_t s7 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)7U];
        uint32_t s8 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)8U];
        uint32_t s9 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)9U];
        uint32_t s10 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)10U];
        uint32_t s111 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)11U];
        uint32_t s12 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)12U];
        uint32_t s13 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)13U];
        uint32_t s14 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)14U];
        uint32_t s15 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)15U];
        uint32_t uu____12 = m_w[s21];
        uint32_t uu____13 = m_w[s4];
        uint32_t uu____14 = m_w[s6];
        r00[0U] = m_w[s0];
        r00[1U] = uu____12;
        r00[2U] = uu____13;
        r00[3U] = uu____14;
        uint32_t uu____15 = m_w[s3];
        uint32_t uu____16 = m_w[s5];
        uint32_t uu____17 = m_w[s7];
        r10[0U] = m_w[s11];
        r10[1U] = uu____15;
        r10[2U] = uu____16;
        r10[3U] = uu____17;
        uint32_t uu____18 = m_w[s10];
        uint32_t uu____19 = m_w[s12];
        uint32_t uu____20 = m_w[s14];
        r20[0U] = m_w[s8];
        r20[1U] = uu____18;
        r20[2U] = uu____19;
        r20[3U] = uu____20;
        uint32_t uu____21 = m_w[s111];
        uint32_t uu____22 = m_w[s13];
        uint32_t uu____23 = m_w[s15];
        r30[0U] = m_w[s9];
        r30[1U] = uu____21;
        r30[2U] = uu____22;
        r30[3U] = uu____23;
        uint32_t *x = m_st + (uint32_t)0U * (uint32_t)4U;
        uint32_t *y = m_st + (uint32_t)1U * (uint32_t)4U;
        uint32_t *z = m_st + (uint32_t)2U * (uint32_t)4U;
        uint32_t *w = m_st + (uint32_t)3U * (uint32_t)4U;
        uint32_t a = (uint32_t)0U;
        uint32_t b10 = (uint32_t)1U;
        uint32_t c0 = (uint32_t)2U;
        uint32_t d0 = (uint32_t)3U;
        uint32_t r01 = Hacl_Impl_Blake2_Constants_rTable_S[0U];
        uint32_t r12 = Hacl_Impl_Blake2_Constants_rTable_S[1U];
        uint32_t r21 = Hacl_Impl_Blake2_Constants_rTable_S[2U];
        uint32_t r31 = Hacl_Impl_Blake2_Constants_rTable_S[3U];
        uint32_t *wv_a0 = block_state1.fst + a * (uint32_t)4U;
        uint32_t *wv_b0 = block_state1.fst + b10 * (uint32_t)4U;
        for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
        {
          uint32_t *os = wv_a0;
          uint32_t x1 = wv_a0[i] + wv_b0[i];
          os[i] = x1;
        }
        for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
        {
          uint32_t *os = wv_a0;
          uint32_t x1 = wv_a0[i] + x[i];
          os[i] = x1;
        }
        uint32_t *wv_a1 = block_state1.fst + d0 * (uint32_t)4U;
        uint32_t *wv_b1 = block_state1.fst + a * (uint32_t)4U;
        for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
        {
          uint32_t *os = wv_a1;
          uint32_t x1 = wv_a1[i] ^ wv_b1[i];
          os[i] = x1;
        }
        uint32_t *r110 = wv_a1;
        for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
        {
          uint32_t *os = r110;
          uint32_t x1 = r110[i];
          uint32_t x10 = x1 >> r01 | x1 << ((uint32_t)32U - r01);
          os[i] = x10;
        }
        uint32_t *wv_a2 = block_state1.fst + c0 * (uint32_t)4U;
        uint32_t *wv_b2 = block_state1.fst + d0 * (uint32_t)4U;
        for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
        {
          uint32_t *os = wv_a2;
          uint32_t x1 = wv_a2[i] + wv_b2[i];
          os[i] = x1;
        }
        uint32_t *wv_a3 = block_state1.fst + b10 * (uint32_t)4U;
        uint32_t *wv_b3 = block_state1.fst + c0 * (uint32_t)4U;
        for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
        {
          uint32_t *os = wv_a3;
          uint32_t x1 = wv_a3[i] ^ wv_b3[i];
          os[i] = x1;
        }
        uint32_t *r111 = wv_a3;
        for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
        {
          uint32_t *os = r111;
          uint32_t x1 = r111[i];
          uint32_t x10 = x1 >> r12 | x1 << ((uint32_t)32U - r12);
          os[i] = x10;
        }
        uint32_t *wv_a4 = block_state1.fst + a * (uint32_t)4U;
        uint32_t *wv_b4 = block_state1.fst + b10 * (uint32_t)4U;
        for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
        {
          uint32_t *os = wv_a4;
          uint32_t x1 = wv_a4[i] + wv_b4[i];
          os[i] = x1;
        }
        for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
        {
          uint32_t *os = wv_a4;
          uint32_t x1 = wv_a4[i] + y[i];
          os[i] = x1;
        }
        uint32_t *wv_a5 = block_state1.fst + d0 * (uint32_t)4U;
        uint32_t *wv_b5 = block_state1.fst + a * (uint32_t)4U;
        for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
        {
          uint32_t *os = wv_a5;
          uint32_t x1 = wv_a5[i] ^ wv_b5[i];
          os[i] = x1;
        }
        uint32_t *r112 = wv_a5;
        for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
        {
          uint32_t *os = r112;
          uint32_t x1 = r112[i];
          uint32_t x10 = x1 >> r21 | x1 << ((uint32_t)32U - r21);
          os[i] = x10;
        }
        uint32_t *wv_a6 = block_state1.fst + c0 * (uint32_t)4U;
        uint32_t *wv_b6 = block_state1.fst + d0 * (uint32_t)4U;
        for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
        {
          uint32_t *os = wv_a6;
          uint32_t x1 = wv_a6[i] + wv_b6[i];
          os[i] = x1;
        }
        uint32_t *wv_a7 = block_state1.fst + b10 * (uint32_t)4U;
        uint32_t *wv_b7 = block_state1.fst + c0 * (uint32_t)4U;
        for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
        {
          uint32_t *os = wv_a7;
          uint32_t x1 = wv_a7[i] ^ wv_b7[i];
          os[i] = x1;
        }
        uint32_t *r113 = wv_a7;
        for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
        {
          uint32_t *os = r113;
          uint32_t x1 = r113[i];
          uint32_t x10 = x1 >> r31 | x1 << ((uint32_t)32U - r31);
          os[i] = x10;
        }
        uint32_t *r13 = block_state1.fst + (uint32_t)1U * (uint32_t)4U;
        uint32_t *r22 = block_state1.fst + (uint32_t)2U * (uint32_t)4U;
        uint32_t *r32 = block_state1.fst + (uint32_t)3U * (uint32_t)4U;
        uint32_t *r114 = r13;
        uint32_t x00 = r114[1U];
        uint32_t x10 = r114[((uint32_t)1U + (uint32_t)1U) % (uint32_t)4U];
        uint32_t x20 = r114[((uint32_t)1U + (uint32_t)2U) % (uint32_t)4U];
        uint32_t x30 = r114[((uint32_t)1U + (uint32_t)3U) % (uint32_t)4U];
        r114[0U] = x00;
        r114[1U] = x10;
        r114[2U] = x20;
        r114[3U] = x30;
        uint32_t *r115 = r22;
        uint32_t x01 = r115[2U];
        uint32_t x11 = r115[((uint32_t)2U + (uint32_t)1U) % (uint32_t)4U];
        uint32_t x21 = r115[((uint32_t)2U + (uint32_t)2U) % (uint32_t)4U];
        uint32_t x31 = r115[((uint32_t)2U + (uint32_t)3U) % (uint32_t)4U];
        r115[0U] = x01;
        r115[1U] = x11;
        r115[2U] = x21;
        r115[3U] = x31;
        uint32_t *r116 = r32;
        uint32_t x02 = r116[3U];
        uint32_t x12 = r116[((uint32_t)3U + (uint32_t)1U) % (uint32_t)4U];
        uint32_t x22 = r116[((uint32_t)3U + (uint32_t)2U) % (uint32_t)4U];
        uint32_t x32 = r116[((uint32_t)3U + (uint32_t)3U) % (uint32_t)4U];
        r116[0U] = x02;
        r116[1U] = x12;
        r116[2U] = x22;
        r116[3U] = x32;
        uint32_t a0 = (uint32_t)0U;
        uint32_t b1 = (uint32_t)1U;
        uint32_t c = (uint32_t)2U;
        uint32_t d = (uint32_t)3U;
        uint32_t r0 = Hacl_Impl_Blake2_Constants_rTable_S[0U];
        uint32_t r1 = Hacl_Impl_Blake2_Constants_rTable_S[1U];
        uint32_t r23 = Hacl_Impl_Blake2_Constants_rTable_S[2U];
        uint32_t r33 = Hacl_Impl_Blake2_Constants_rTable_S[3U];
        uint32_t *wv_a = block_state1.fst + a0 * (uint32_t)4U;
        uint32_t *wv_b8 = block_state1.fst + b1 * (uint32_t)4U;
        for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
        {
          uint32_t *os = wv_a;
          uint32_t x1 = wv_a[i] + wv_b8[i];
          os[i] = x1;
        }
        for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
        {
          uint32_t *os = wv_a;
          uint32_t x1 = wv_a[i] + z[i];
          os[i] = x1;
        }
        uint32_t *wv_a8 = block_state1.fst + d * (uint32_t)4U;
        uint32_t *wv_b9 = block_state1.fst + a0 * (uint32_t)4U;
        for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
        {
          uint32_t *os = wv_a8;
          uint32_t x1 = wv_a8[i] ^ wv_b9[i];
          os[i] = x1;
        }
        uint32_t *r117 = wv_a8;
        for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
        {
          uint32_t *os = r117;
          uint32_t x1 = r117[i];
          uint32_t x13 = x1 >> r0 | x1 << ((uint32_t)32U - r0);
          os[i] = x13;
        }
        uint32_t *wv_a9 = block_state1.fst + c * (uint32_t)4U;
        uint32_t *wv_b10 = block_state1.fst + d * (uint32_t)4U;
        for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
        {
          uint32_t *os = wv_a9;
          uint32_t x1 = wv_a9[i] + wv_b10[i];
          os[i] = x1;
        }
        uint32_t *wv_a10 = block_state1.fst + b1 * (uint32_t)4U;
        uint32_t *wv_b11 = block_state1.fst + c * (uint32_t)4U;
        for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
        {
          uint32_t *os = wv_a10;
          uint32_t x1 = wv_a10[i] ^ wv_b11[i];
          os[i] = x1;
        }
        uint32_t *r118 = wv_a10;
        for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
        {
          uint32_t *os = r118;
          uint32_t x1 = r118[i];
          uint32_t x13 = x1 >> r1 | x1 << ((uint32_t)32U - r1);
          os[i] = x13;
        }
        uint32_t *wv_a11 = block_state1.fst + a0 * (uint32_t)4U;
        uint32_t *wv_b12 = block_state1.fst + b1 * (uint32_t)4U;
        for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
        {
          uint32_t *os = wv_a11;
          uint32_t x1 = wv_a11[i] + wv_b12[i];
          os[i] = x1;
        }
        for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
        {
          uint32_t *os = wv_a11;
          uint32_t x1 = wv_a11[i] + w[i];
          os[i] = x1;
        }
        uint32_t *wv_a12 = block_state1.fst + d * (uint32_t)4U;
        uint32_t *wv_b13 = block_state1.fst + a0 * (uint32_t)4U;
        for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
        {
          uint32_t *os = wv_a12;
          uint32_t x1 = wv_a12[i] ^ wv_b13[i];
          os[i] = x1;
        }
        uint32_t *r119 = wv_a12;
        for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
        {
          uint32_t *os = r119;
          uint32_t x1 = r119[i];
          uint32_t x13 = x1 >> r23 | x1 << ((uint32_t)32U - r23);
          os[i] = x13;
        }
        uint32_t *wv_a13 = block_state1.fst + c * (uint32_t)4U;
        uint32_t *wv_b14 = block_state1.fst + d * (uint32_t)4U;
        for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
        {
          uint32_t *os = wv_a13;
          uint32_t x1 = wv_a13[i] + wv_b14[i];
          os[i] = x1;
        }
        uint32_t *wv_a14 = block_state1.fst + b1 * (uint32_t)4U;
        uint32_t *wv_b = block_state1.fst + c * (uint32_t)4U;
        for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
        {
          uint32_t *os = wv_a14;
          uint32_t x1 = wv_a14[i] ^ wv_b[i];
          os[i] = x1;
        }
        uint32_t *r1110 = wv_a14;
        for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
        {
          uint32_t *os = r1110;
          uint32_t x1 = r1110[i];
          uint32_t x13 = x1 >> r33 | x1 << ((uint32_t)32U - r33);
          os[i] = x13;
        }
        uint32_t *r14 = block_state1.fst + (uint32_t)1U * (uint32_t)4U;
        uint32_t *r2 = block_state1.fst + (uint32_t)2U * (uint32_t)4U;
        uint32_t *r3 = block_state1.fst + (uint32_t)3U * (uint32_t)4U;
        uint32_t *r11 = r14;
        uint32_t x03 = r11[3U];
        uint32_t x13 = r11[((uint32_t)3U + (uint32_t)1U) % (uint32_t)4U];
        uint32_t x23 = r11[((uint32_t)3U + (uint32_t)2U) % (uint32_t)4U];
        uint32_t x33 = r11[((uint32_t)3U + (uint32_t)3U) % (uint32_t)4U];
        r11[0U] = x03;
        r11[1U] = x13;
        r11[2U] = x23;
        r11[3U] = x33;
        uint32_t *r1111 = r2;
        uint32_t x04 = r1111[2U];
        uint32_t x14 = r1111[((uint32_t)2U + (uint32_t)1U) % (uint32_t)4U];
        uint32_t x24 = r1111[((uint32_t)2U + (uint32_t)2U) % (uint32_t)4U];
        uint32_t x34 = r1111[((uint32_t)2U + (uint32_t)3U) % (uint32_t)4U];
        r1111[0U] = x04;
        r1111[1U] = x14;
        r1111[2U] = x24;
        r1111[3U] = x34;
        uint32_t *r1112 = r3;
        uint32_t x0 = r1112[1U];
        uint32_t x1 = r1112[((uint32_t)1U + (uint32_t)1U) % (uint32_t)4U];
        uint32_t x2 = r1112[((uint32_t)1U + (uint32_t)2U) % (uint32_t)4U];
        uint32_t x3 = r1112[((uint32_t)1U + (uint32_t)3U) % (uint32_t)4U];
        r1112[0U] = x0;
        r1112[1U] = x1;
        r1112[2U] = x2;
        r1112[3U] = x3;
      }
      uint32_t *s0 = block_state1.snd + (uint32_t)0U * (uint32_t)4U;
      uint32_t *s11 = block_state1.snd + (uint32_t)1U * (uint32_t)4U;
      uint32_t *r0 = block_state1.fst + (uint32_t)0U * (uint32_t)4U;
      uint32_t *r1 = block_state1.fst + (uint32_t)1U * (uint32_t)4U;
      uint32_t *r2 = block_state1.fst + (uint32_t)2U * (uint32_t)4U;
      uint32_t *r3 = block_state1.fst + (uint32_t)3U * (uint32_t)4U;
      for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
      {
        uint32_t *os = s0;
        uint32_t x = s0[i] ^ r0[i];
        os[i] = x;
      }
      for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
      {
        uint32_t *os = s0;
        uint32_t x = s0[i] ^ r2[i];
        os[i] = x;
      }
      for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
      {
        uint32_t *os = s11;
        uint32_t x = s11[i] ^ r1[i];
        os[i] = x;
      }
      for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
      {
        uint32_t *os = s11;
        uint32_t x = s11[i] ^ r3[i];
        os[i] = x;
      }
    }
    uint8_t *dst = buf;
    memcpy(dst, data2, data2_len * sizeof (data2[0U]));
    *p
    =
      (
        (Hacl_Streaming_Functor_state_s__K____uint32_t___uint32_t____){
          .block_state = block_state1,
          .buf = buf,
          .total_len = total_len1 + (uint64_t)len
        }
      );
    return;
  }
  uint32_t diff = (uint32_t)64U - sz;
  uint8_t *data1 = data;
  uint8_t *data2 = data + diff;
  Hacl_Streaming_Functor_state_s__K____uint32_t___uint32_t____ s2 = *p;
  K____uint32_t___uint32_t_ block_state10 = s2.block_state;
  uint8_t *buf0 = s2.buf;
  uint64_t total_len10 = s2.total_len;
  uint32_t sz10;
  if (total_len10 % (uint64_t)(uint32_t)64U == (uint64_t)0U && total_len10 > (uint64_t)0U)
  {
    sz10 = (uint32_t)64U;
  }
  else
  {
    sz10 = (uint32_t)(total_len10 % (uint64_t)(uint32_t)64U);
  }
  uint8_t *buf2 = buf0 + sz10;
  memcpy(buf2, data1, diff * sizeof (data1[0U]));
  uint64_t total_len2 = total_len10 + (uint64_t)diff;
  *p
  =
    (
      (Hacl_Streaming_Functor_state_s__K____uint32_t___uint32_t____){
        .block_state = block_state10,
        .buf = buf0,
        .total_len = total_len2
      }
    );
  Hacl_Streaming_Functor_state_s__K____uint32_t___uint32_t____ s20 = *p;
  K____uint32_t___uint32_t_ block_state1 = s20.block_state;
  uint8_t *buf = s20.buf;
  uint64_t total_len1 = s20.total_len;
  uint32_t sz1;
  if (total_len1 % (uint64_t)(uint32_t)64U == (uint64_t)0U && total_len1 > (uint64_t)0U)
  {
    sz1 = (uint32_t)64U;
  }
  else
  {
    sz1 = (uint32_t)(total_len1 % (uint64_t)(uint32_t)64U);
  }
  if (!(sz1 == (uint32_t)0U))
  {
    uint64_t prevlen = total_len1 - (uint64_t)sz1;
    uint32_t nb = (uint32_t)1U;
    for (uint32_t i0 = (uint32_t)0U; i0 < nb; i0++)
    {
      uint64_t ite;
      if (key_size == (uint32_t)0U)
      {
        ite = prevlen;
      }
      else
      {
        ite = prevlen + (uint64_t)(uint32_t)64U;
      }
      uint64_t totlen = ite + (uint64_t)((i0 + (uint32_t)1U) * (uint32_t)64U);
      uint8_t *b = buf + i0 * (uint32_t)64U;
      uint32_t m_w[16U] = { 0U };
      for (uint32_t i = (uint32_t)0U; i < (uint32_t)16U; i++)
      {
        uint32_t *os = m_w;
        uint8_t *bj = b + i * (uint32_t)4U;
        uint32_t u = load32_le(bj);
        uint32_t r = u;
        uint32_t x = r;
        os[i] = x;
      }
      uint32_t mask[4U] = { 0U };
      uint32_t wv_14 = (uint32_t)0U;
      uint32_t wv_15 = (uint32_t)0U;
      mask[0U] = (uint32_t)totlen;
      mask[1U] = (uint32_t)(totlen >> (uint32_t)32U);
      mask[2U] = wv_14;
      mask[3U] = wv_15;
      memcpy(block_state1.fst,
        block_state1.snd,
        (uint32_t)4U * (uint32_t)4U * sizeof (block_state1.snd[0U]));
      uint32_t *wv3 = block_state1.fst + (uint32_t)3U * (uint32_t)4U;
      for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
      {
        uint32_t *os = wv3;
        uint32_t x = wv3[i] ^ mask[i];
        os[i] = x;
      }
      for (uint32_t i1 = (uint32_t)0U; i1 < (uint32_t)10U; i1++)
      {
        uint32_t start_idx = i1 % (uint32_t)10U * (uint32_t)16U;
        KRML_CHECK_SIZE(sizeof (uint32_t), (uint32_t)4U * (uint32_t)4U);
        uint32_t m_st[(uint32_t)4U * (uint32_t)4U];
        memset(m_st, 0U, (uint32_t)4U * (uint32_t)4U * sizeof (m_st[0U]));
        uint32_t *r00 = m_st + (uint32_t)0U * (uint32_t)4U;
        uint32_t *r10 = m_st + (uint32_t)1U * (uint32_t)4U;
        uint32_t *r20 = m_st + (uint32_t)2U * (uint32_t)4U;
        uint32_t *r30 = m_st + (uint32_t)3U * (uint32_t)4U;
        uint32_t s0 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx];
        uint32_t s11 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)1U];
        uint32_t s21 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)2U];
        uint32_t s3 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)3U];
        uint32_t s4 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)4U];
        uint32_t s5 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)5U];
        uint32_t s6 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)6U];
        uint32_t s7 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)7U];
        uint32_t s8 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)8U];
        uint32_t s9 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)9U];
        uint32_t s10 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)10U];
        uint32_t s111 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)11U];
        uint32_t s12 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)12U];
        uint32_t s13 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)13U];
        uint32_t s14 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)14U];
        uint32_t s15 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)15U];
        uint32_t uu____24 = m_w[s21];
        uint32_t uu____25 = m_w[s4];
        uint32_t uu____26 = m_w[s6];
        r00[0U] = m_w[s0];
        r00[1U] = uu____24;
        r00[2U] = uu____25;
        r00[3U] = uu____26;
        uint32_t uu____27 = m_w[s3];
        uint32_t uu____28 = m_w[s5];
        uint32_t uu____29 = m_w[s7];
        r10[0U] = m_w[s11];
        r10[1U] = uu____27;
        r10[2U] = uu____28;
        r10[3U] = uu____29;
        uint32_t uu____30 = m_w[s10];
        uint32_t uu____31 = m_w[s12];
        uint32_t uu____32 = m_w[s14];
        r20[0U] = m_w[s8];
        r20[1U] = uu____30;
        r20[2U] = uu____31;
        r20[3U] = uu____32;
        uint32_t uu____33 = m_w[s111];
        uint32_t uu____34 = m_w[s13];
        uint32_t uu____35 = m_w[s15];
        r30[0U] = m_w[s9];
        r30[1U] = uu____33;
        r30[2U] = uu____34;
        r30[3U] = uu____35;
        uint32_t *x = m_st + (uint32_t)0U * (uint32_t)4U;
        uint32_t *y = m_st + (uint32_t)1U * (uint32_t)4U;
        uint32_t *z = m_st + (uint32_t)2U * (uint32_t)4U;
        uint32_t *w = m_st + (uint32_t)3U * (uint32_t)4U;
        uint32_t a = (uint32_t)0U;
        uint32_t b10 = (uint32_t)1U;
        uint32_t c0 = (uint32_t)2U;
        uint32_t d0 = (uint32_t)3U;
        uint32_t r01 = Hacl_Impl_Blake2_Constants_rTable_S[0U];
        uint32_t r12 = Hacl_Impl_Blake2_Constants_rTable_S[1U];
        uint32_t r21 = Hacl_Impl_Blake2_Constants_rTable_S[2U];
        uint32_t r31 = Hacl_Impl_Blake2_Constants_rTable_S[3U];
        uint32_t *wv_a0 = block_state1.fst + a * (uint32_t)4U;
        uint32_t *wv_b0 = block_state1.fst + b10 * (uint32_t)4U;
        for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
        {
          uint32_t *os = wv_a0;
          uint32_t x1 = wv_a0[i] + wv_b0[i];
          os[i] = x1;
        }
        for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
        {
          uint32_t *os = wv_a0;
          uint32_t x1 = wv_a0[i] + x[i];
          os[i] = x1;
        }
        uint32_t *wv_a1 = block_state1.fst + d0 * (uint32_t)4U;
        uint32_t *wv_b1 = block_state1.fst + a * (uint32_t)4U;
        for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
        {
          uint32_t *os = wv_a1;
          uint32_t x1 = wv_a1[i] ^ wv_b1[i];
          os[i] = x1;
        }
        uint32_t *r110 = wv_a1;
        for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
        {
          uint32_t *os = r110;
          uint32_t x1 = r110[i];
          uint32_t x10 = x1 >> r01 | x1 << ((uint32_t)32U - r01);
          os[i] = x10;
        }
        uint32_t *wv_a2 = block_state1.fst + c0 * (uint32_t)4U;
        uint32_t *wv_b2 = block_state1.fst + d0 * (uint32_t)4U;
        for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
        {
          uint32_t *os = wv_a2;
          uint32_t x1 = wv_a2[i] + wv_b2[i];
          os[i] = x1;
        }
        uint32_t *wv_a3 = block_state1.fst + b10 * (uint32_t)4U;
        uint32_t *wv_b3 = block_state1.fst + c0 * (uint32_t)4U;
        for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
        {
          uint32_t *os = wv_a3;
          uint32_t x1 = wv_a3[i] ^ wv_b3[i];
          os[i] = x1;
        }
        uint32_t *r111 = wv_a3;
        for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
        {
          uint32_t *os = r111;
          uint32_t x1 = r111[i];
          uint32_t x10 = x1 >> r12 | x1 << ((uint32_t)32U - r12);
          os[i] = x10;
        }
        uint32_t *wv_a4 = block_state1.fst + a * (uint32_t)4U;
        uint32_t *wv_b4 = block_state1.fst + b10 * (uint32_t)4U;
        for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
        {
          uint32_t *os = wv_a4;
          uint32_t x1 = wv_a4[i] + wv_b4[i];
          os[i] = x1;
        }
        for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
        {
          uint32_t *os = wv_a4;
          uint32_t x1 = wv_a4[i] + y[i];
          os[i] = x1;
        }
        uint32_t *wv_a5 = block_state1.fst + d0 * (uint32_t)4U;
        uint32_t *wv_b5 = block_state1.fst + a * (uint32_t)4U;
        for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
        {
          uint32_t *os = wv_a5;
          uint32_t x1 = wv_a5[i] ^ wv_b5[i];
          os[i] = x1;
        }
        uint32_t *r112 = wv_a5;
        for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
        {
          uint32_t *os = r112;
          uint32_t x1 = r112[i];
          uint32_t x10 = x1 >> r21 | x1 << ((uint32_t)32U - r21);
          os[i] = x10;
        }
        uint32_t *wv_a6 = block_state1.fst + c0 * (uint32_t)4U;
        uint32_t *wv_b6 = block_state1.fst + d0 * (uint32_t)4U;
        for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
        {
          uint32_t *os = wv_a6;
          uint32_t x1 = wv_a6[i] + wv_b6[i];
          os[i] = x1;
        }
        uint32_t *wv_a7 = block_state1.fst + b10 * (uint32_t)4U;
        uint32_t *wv_b7 = block_state1.fst + c0 * (uint32_t)4U;
        for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
        {
          uint32_t *os = wv_a7;
          uint32_t x1 = wv_a7[i] ^ wv_b7[i];
          os[i] = x1;
        }
        uint32_t *r113 = wv_a7;
        for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
        {
          uint32_t *os = r113;
          uint32_t x1 = r113[i];
          uint32_t x10 = x1 >> r31 | x1 << ((uint32_t)32U - r31);
          os[i] = x10;
        }
        uint32_t *r13 = block_state1.fst + (uint32_t)1U * (uint32_t)4U;
        uint32_t *r22 = block_state1.fst + (uint32_t)2U * (uint32_t)4U;
        uint32_t *r32 = block_state1.fst + (uint32_t)3U * (uint32_t)4U;
        uint32_t *r114 = r13;
        uint32_t x00 = r114[1U];
        uint32_t x10 = r114[((uint32_t)1U + (uint32_t)1U) % (uint32_t)4U];
        uint32_t x20 = r114[((uint32_t)1U + (uint32_t)2U) % (uint32_t)4U];
        uint32_t x30 = r114[((uint32_t)1U + (uint32_t)3U) % (uint32_t)4U];
        r114[0U] = x00;
        r114[1U] = x10;
        r114[2U] = x20;
        r114[3U] = x30;
        uint32_t *r115 = r22;
        uint32_t x01 = r115[2U];
        uint32_t x11 = r115[((uint32_t)2U + (uint32_t)1U) % (uint32_t)4U];
        uint32_t x21 = r115[((uint32_t)2U + (uint32_t)2U) % (uint32_t)4U];
        uint32_t x31 = r115[((uint32_t)2U + (uint32_t)3U) % (uint32_t)4U];
        r115[0U] = x01;
        r115[1U] = x11;
        r115[2U] = x21;
        r115[3U] = x31;
        uint32_t *r116 = r32;
        uint32_t x02 = r116[3U];
        uint32_t x12 = r116[((uint32_t)3U + (uint32_t)1U) % (uint32_t)4U];
        uint32_t x22 = r116[((uint32_t)3U + (uint32_t)2U) % (uint32_t)4U];
        uint32_t x32 = r116[((uint32_t)3U + (uint32_t)3U) % (uint32_t)4U];
        r116[0U] = x02;
        r116[1U] = x12;
        r116[2U] = x22;
        r116[3U] = x32;
        uint32_t a0 = (uint32_t)0U;
        uint32_t b1 = (uint32_t)1U;
        uint32_t c = (uint32_t)2U;
        uint32_t d = (uint32_t)3U;
        uint32_t r0 = Hacl_Impl_Blake2_Constants_rTable_S[0U];
        uint32_t r1 = Hacl_Impl_Blake2_Constants_rTable_S[1U];
        uint32_t r23 = Hacl_Impl_Blake2_Constants_rTable_S[2U];
        uint32_t r33 = Hacl_Impl_Blake2_Constants_rTable_S[3U];
        uint32_t *wv_a = block_state1.fst + a0 * (uint32_t)4U;
        uint32_t *wv_b8 = block_state1.fst + b1 * (uint32_t)4U;
        for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
        {
          uint32_t *os = wv_a;
          uint32_t x1 = wv_a[i] + wv_b8[i];
          os[i] = x1;
        }
        for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
        {
          uint32_t *os = wv_a;
          uint32_t x1 = wv_a[i] + z[i];
          os[i] = x1;
        }
        uint32_t *wv_a8 = block_state1.fst + d * (uint32_t)4U;
        uint32_t *wv_b9 = block_state1.fst + a0 * (uint32_t)4U;
        for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
        {
          uint32_t *os = wv_a8;
          uint32_t x1 = wv_a8[i] ^ wv_b9[i];
          os[i] = x1;
        }
        uint32_t *r117 = wv_a8;
        for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
        {
          uint32_t *os = r117;
          uint32_t x1 = r117[i];
          uint32_t x13 = x1 >> r0 | x1 << ((uint32_t)32U - r0);
          os[i] = x13;
        }
        uint32_t *wv_a9 = block_state1.fst + c * (uint32_t)4U;
        uint32_t *wv_b10 = block_state1.fst + d * (uint32_t)4U;
        for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
        {
          uint32_t *os = wv_a9;
          uint32_t x1 = wv_a9[i] + wv_b10[i];
          os[i] = x1;
        }
        uint32_t *wv_a10 = block_state1.fst + b1 * (uint32_t)4U;
        uint32_t *wv_b11 = block_state1.fst + c * (uint32_t)4U;
        for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
        {
          uint32_t *os = wv_a10;
          uint32_t x1 = wv_a10[i] ^ wv_b11[i];
          os[i] = x1;
        }
        uint32_t *r118 = wv_a10;
        for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
        {
          uint32_t *os = r118;
          uint32_t x1 = r118[i];
          uint32_t x13 = x1 >> r1 | x1 << ((uint32_t)32U - r1);
          os[i] = x13;
        }
        uint32_t *wv_a11 = block_state1.fst + a0 * (uint32_t)4U;
        uint32_t *wv_b12 = block_state1.fst + b1 * (uint32_t)4U;
        for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
        {
          uint32_t *os = wv_a11;
          uint32_t x1 = wv_a11[i] + wv_b12[i];
          os[i] = x1;
        }
        for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
        {
          uint32_t *os = wv_a11;
          uint32_t x1 = wv_a11[i] + w[i];
          os[i] = x1;
        }
        uint32_t *wv_a12 = block_state1.fst + d * (uint32_t)4U;
        uint32_t *wv_b13 = block_state1.fst + a0 * (uint32_t)4U;
        for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
        {
          uint32_t *os = wv_a12;
          uint32_t x1 = wv_a12[i] ^ wv_b13[i];
          os[i] = x1;
        }
        uint32_t *r119 = wv_a12;
        for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
        {
          uint32_t *os = r119;
          uint32_t x1 = r119[i];
          uint32_t x13 = x1 >> r23 | x1 << ((uint32_t)32U - r23);
          os[i] = x13;
        }
        uint32_t *wv_a13 = block_state1.fst + c * (uint32_t)4U;
        uint32_t *wv_b14 = block_state1.fst + d * (uint32_t)4U;
        for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
        {
          uint32_t *os = wv_a13;
          uint32_t x1 = wv_a13[i] + wv_b14[i];
          os[i] = x1;
        }
        uint32_t *wv_a14 = block_state1.fst + b1 * (uint32_t)4U;
        uint32_t *wv_b = block_state1.fst + c * (uint32_t)4U;
        for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
        {
          uint32_t *os = wv_a14;
          uint32_t x1 = wv_a14[i] ^ wv_b[i];
          os[i] = x1;
        }
        uint32_t *r1110 = wv_a14;
        for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
        {
          uint32_t *os = r1110;
          uint32_t x1 = r1110[i];
          uint32_t x13 = x1 >> r33 | x1 << ((uint32_t)32U - r33);
          os[i] = x13;
        }
        uint32_t *r14 = block_state1.fst + (uint32_t)1U * (uint32_t)4U;
        uint32_t *r2 = block_state1.fst + (uint32_t)2U * (uint32_t)4U;
        uint32_t *r3 = block_state1.fst + (uint32_t)3U * (uint32_t)4U;
        uint32_t *r11 = r14;
        uint32_t x03 = r11[3U];
        uint32_t x13 = r11[((uint32_t)3U + (uint32_t)1U) % (uint32_t)4U];
        uint32_t x23 = r11[((uint32_t)3U + (uint32_t)2U) % (uint32_t)4U];
        uint32_t x33 = r11[((uint32_t)3U + (uint32_t)3U) % (uint32_t)4U];
        r11[0U] = x03;
        r11[1U] = x13;
        r11[2U] = x23;
        r11[3U] = x33;
        uint32_t *r1111 = r2;
        uint32_t x04 = r1111[2U];
        uint32_t x14 = r1111[((uint32_t)2U + (uint32_t)1U) % (uint32_t)4U];
        uint32_t x24 = r1111[((uint32_t)2U + (uint32_t)2U) % (uint32_t)4U];
        uint32_t x34 = r1111[((uint32_t)2U + (uint32_t)3U) % (uint32_t)4U];
        r1111[0U] = x04;
        r1111[1U] = x14;
        r1111[2U] = x24;
        r1111[3U] = x34;
        uint32_t *r1112 = r3;
        uint32_t x0 = r1112[1U];
        uint32_t x1 = r1112[((uint32_t)1U + (uint32_t)1U) % (uint32_t)4U];
        uint32_t x2 = r1112[((uint32_t)1U + (uint32_t)2U) % (uint32_t)4U];
        uint32_t x3 = r1112[((uint32_t)1U + (uint32_t)3U) % (uint32_t)4U];
        r1112[0U] = x0;
        r1112[1U] = x1;
        r1112[2U] = x2;
        r1112[3U] = x3;
      }
      uint32_t *s0 = block_state1.snd + (uint32_t)0U * (uint32_t)4U;
      uint32_t *s11 = block_state1.snd + (uint32_t)1U * (uint32_t)4U;
      uint32_t *r0 = block_state1.fst + (uint32_t)0U * (uint32_t)4U;
      uint32_t *r1 = block_state1.fst + (uint32_t)1U * (uint32_t)4U;
      uint32_t *r2 = block_state1.fst + (uint32_t)2U * (uint32_t)4U;
      uint32_t *r3 = block_state1.fst + (uint32_t)3U * (uint32_t)4U;
      for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
      {
        uint32_t *os = s0;
        uint32_t x = s0[i] ^ r0[i];
        os[i] = x;
      }
      for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
      {
        uint32_t *os = s0;
        uint32_t x = s0[i] ^ r2[i];
        os[i] = x;
      }
      for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
      {
        uint32_t *os = s11;
        uint32_t x = s11[i] ^ r1[i];
        os[i] = x;
      }
      for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
      {
        uint32_t *os = s11;
        uint32_t x = s11[i] ^ r3[i];
        os[i] = x;
      }
    }
  }
  uint32_t ite0;
  if
  (
    (uint64_t)(len - diff)
    % (uint64_t)(uint32_t)64U
    == (uint64_t)0U
    && (uint64_t)(len - diff) > (uint64_t)0U
  )
  {
    ite0 = (uint32_t)64U;
  }
  else
  {
    ite0 = (uint32_t)((uint64_t)(len - diff) % (uint64_t)(uint32_t)64U);
  }
  uint32_t n_blocks = (len - diff - ite0) / (uint32_t)64U;
  uint32_t data1_len = n_blocks * (uint32_t)64U;
  uint32_t data2_len = len - diff - data1_len;
  uint8_t *data11 = data2;
  uint8_t *data21 = data2 + data1_len;
  uint32_t nb = data1_len / (uint32_t)64U;
  for (uint32_t i0 = (uint32_t)0U; i0 < nb; i0++)
  {
    uint64_t ite;
    if (key_size == (uint32_t)0U)
    {
      ite = total_len1;
    }
    else
    {
      ite = total_len1 + (uint64_t)(uint32_t)64U;
    }
    uint64_t totlen = ite + (uint64_t)((i0 + (uint32_t)1U) * (uint32_t)64U);
    uint8_t *b = data11 + i0 * (uint32_t)64U;
    uint32_t m_w[16U] = { 0U };
    for (uint32_t i = (uint32_t)0U; i < (uint32_t)16U; i++)
    {
      uint32_t *os = m_w;
      uint8_t *bj = b + i * (uint32_t)4U;
      uint32_t u = load32_le(bj);
      uint32_t r = u;
      uint32_t x = r;
      os[i] = x;
    }
    uint32_t mask[4U] = { 0U };
    uint32_t wv_14 = (uint32_t)0U;
    uint32_t wv_15 = (uint32_t)0U;
    mask[0U] = (uint32_t)totlen;
    mask[1U] = (uint32_t)(totlen >> (uint32_t)32U);
    mask[2U] = wv_14;
    mask[3U] = wv_15;
    memcpy(block_state1.fst,
      block_state1.snd,
      (uint32_t)4U * (uint32_t)4U * sizeof (block_state1.snd[0U]));
    uint32_t *wv3 = block_state1.fst + (uint32_t)3U * (uint32_t)4U;
    for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
    {
      uint32_t *os = wv3;
      uint32_t x = wv3[i] ^ mask[i];
      os[i] = x;
    }
    for (uint32_t i1 = (uint32_t)0U; i1 < (uint32_t)10U; i1++)
    {
      uint32_t start_idx = i1 % (uint32_t)10U * (uint32_t)16U;
      KRML_CHECK_SIZE(sizeof (uint32_t), (uint32_t)4U * (uint32_t)4U);
      uint32_t m_st[(uint32_t)4U * (uint32_t)4U];
      memset(m_st, 0U, (uint32_t)4U * (uint32_t)4U * sizeof (m_st[0U]));
      uint32_t *r00 = m_st + (uint32_t)0U * (uint32_t)4U;
      uint32_t *r10 = m_st + (uint32_t)1U * (uint32_t)4U;
      uint32_t *r20 = m_st + (uint32_t)2U * (uint32_t)4U;
      uint32_t *r30 = m_st + (uint32_t)3U * (uint32_t)4U;
      uint32_t s0 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx];
      uint32_t s11 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)1U];
      uint32_t s21 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)2U];
      uint32_t s3 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)3U];
      uint32_t s4 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)4U];
      uint32_t s5 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)5U];
      uint32_t s6 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)6U];
      uint32_t s7 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)7U];
      uint32_t s8 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)8U];
      uint32_t s9 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)9U];
      uint32_t s10 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)10U];
      uint32_t s111 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)11U];
      uint32_t s12 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)12U];
      uint32_t s13 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)13U];
      uint32_t s14 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)14U];
      uint32_t s15 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)15U];
      uint32_t uu____36 = m_w[s21];
      uint32_t uu____37 = m_w[s4];
      uint32_t uu____38 = m_w[s6];
      r00[0U] = m_w[s0];
      r00[1U] = uu____36;
      r00[2U] = uu____37;
      r00[3U] = uu____38;
      uint32_t uu____39 = m_w[s3];
      uint32_t uu____40 = m_w[s5];
      uint32_t uu____41 = m_w[s7];
      r10[0U] = m_w[s11];
      r10[1U] = uu____39;
      r10[2U] = uu____40;
      r10[3U] = uu____41;
      uint32_t uu____42 = m_w[s10];
      uint32_t uu____43 = m_w[s12];
      uint32_t uu____44 = m_w[s14];
      r20[0U] = m_w[s8];
      r20[1U] = uu____42;
      r20[2U] = uu____43;
      r20[3U] = uu____44;
      uint32_t uu____45 = m_w[s111];
      uint32_t uu____46 = m_w[s13];
      uint32_t uu____47 = m_w[s15];
      r30[0U] = m_w[s9];
      r30[1U] = uu____45;
      r30[2U] = uu____46;
      r30[3U] = uu____47;
      uint32_t *x = m_st + (uint32_t)0U * (uint32_t)4U;
      uint32_t *y = m_st + (uint32_t)1U * (uint32_t)4U;
      uint32_t *z = m_st + (uint32_t)2U * (uint32_t)4U;
      uint32_t *w = m_st + (uint32_t)3U * (uint32_t)4U;
      uint32_t a = (uint32_t)0U;
      uint32_t b10 = (uint32_t)1U;
      uint32_t c0 = (uint32_t)2U;
      uint32_t d0 = (uint32_t)3U;
      uint32_t r01 = Hacl_Impl_Blake2_Constants_rTable_S[0U];
      uint32_t r12 = Hacl_Impl_Blake2_Constants_rTable_S[1U];
      uint32_t r21 = Hacl_Impl_Blake2_Constants_rTable_S[2U];
      uint32_t r31 = Hacl_Impl_Blake2_Constants_rTable_S[3U];
      uint32_t *wv_a0 = block_state1.fst + a * (uint32_t)4U;
      uint32_t *wv_b0 = block_state1.fst + b10 * (uint32_t)4U;
      for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
      {
        uint32_t *os = wv_a0;
        uint32_t x1 = wv_a0[i] + wv_b0[i];
        os[i] = x1;
      }
      for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
      {
        uint32_t *os = wv_a0;
        uint32_t x1 = wv_a0[i] + x[i];
        os[i] = x1;
      }
      uint32_t *wv_a1 = block_state1.fst + d0 * (uint32_t)4U;
      uint32_t *wv_b1 = block_state1.fst + a * (uint32_t)4U;
      for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
      {
        uint32_t *os = wv_a1;
        uint32_t x1 = wv_a1[i] ^ wv_b1[i];
        os[i] = x1;
      }
      uint32_t *r110 = wv_a1;
      for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
      {
        uint32_t *os = r110;
        uint32_t x1 = r110[i];
        uint32_t x10 = x1 >> r01 | x1 << ((uint32_t)32U - r01);
        os[i] = x10;
      }
      uint32_t *wv_a2 = block_state1.fst + c0 * (uint32_t)4U;
      uint32_t *wv_b2 = block_state1.fst + d0 * (uint32_t)4U;
      for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
      {
        uint32_t *os = wv_a2;
        uint32_t x1 = wv_a2[i] + wv_b2[i];
        os[i] = x1;
      }
      uint32_t *wv_a3 = block_state1.fst + b10 * (uint32_t)4U;
      uint32_t *wv_b3 = block_state1.fst + c0 * (uint32_t)4U;
      for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
      {
        uint32_t *os = wv_a3;
        uint32_t x1 = wv_a3[i] ^ wv_b3[i];
        os[i] = x1;
      }
      uint32_t *r111 = wv_a3;
      for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
      {
        uint32_t *os = r111;
        uint32_t x1 = r111[i];
        uint32_t x10 = x1 >> r12 | x1 << ((uint32_t)32U - r12);
        os[i] = x10;
      }
      uint32_t *wv_a4 = block_state1.fst + a * (uint32_t)4U;
      uint32_t *wv_b4 = block_state1.fst + b10 * (uint32_t)4U;
      for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
      {
        uint32_t *os = wv_a4;
        uint32_t x1 = wv_a4[i] + wv_b4[i];
        os[i] = x1;
      }
      for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
      {
        uint32_t *os = wv_a4;
        uint32_t x1 = wv_a4[i] + y[i];
        os[i] = x1;
      }
      uint32_t *wv_a5 = block_state1.fst + d0 * (uint32_t)4U;
      uint32_t *wv_b5 = block_state1.fst + a * (uint32_t)4U;
      for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
      {
        uint32_t *os = wv_a5;
        uint32_t x1 = wv_a5[i] ^ wv_b5[i];
        os[i] = x1;
      }
      uint32_t *r112 = wv_a5;
      for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
      {
        uint32_t *os = r112;
        uint32_t x1 = r112[i];
        uint32_t x10 = x1 >> r21 | x1 << ((uint32_t)32U - r21);
        os[i] = x10;
      }
      uint32_t *wv_a6 = block_state1.fst + c0 * (uint32_t)4U;
      uint32_t *wv_b6 = block_state1.fst + d0 * (uint32_t)4U;
      for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
      {
        uint32_t *os = wv_a6;
        uint32_t x1 = wv_a6[i] + wv_b6[i];
        os[i] = x1;
      }
      uint32_t *wv_a7 = block_state1.fst + b10 * (uint32_t)4U;
      uint32_t *wv_b7 = block_state1.fst + c0 * (uint32_t)4U;
      for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
      {
        uint32_t *os = wv_a7;
        uint32_t x1 = wv_a7[i] ^ wv_b7[i];
        os[i] = x1;
      }
      uint32_t *r113 = wv_a7;
      for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
      {
        uint32_t *os = r113;
        uint32_t x1 = r113[i];
        uint32_t x10 = x1 >> r31 | x1 << ((uint32_t)32U - r31);
        os[i] = x10;
      }
      uint32_t *r13 = block_state1.fst + (uint32_t)1U * (uint32_t)4U;
      uint32_t *r22 = block_state1.fst + (uint32_t)2U * (uint32_t)4U;
      uint32_t *r32 = block_state1.fst + (uint32_t)3U * (uint32_t)4U;
      uint32_t *r114 = r13;
      uint32_t x00 = r114[1U];
      uint32_t x10 = r114[((uint32_t)1U + (uint32_t)1U) % (uint32_t)4U];
      uint32_t x20 = r114[((uint32_t)1U + (uint32_t)2U) % (uint32_t)4U];
      uint32_t x30 = r114[((uint32_t)1U + (uint32_t)3U) % (uint32_t)4U];
      r114[0U] = x00;
      r114[1U] = x10;
      r114[2U] = x20;
      r114[3U] = x30;
      uint32_t *r115 = r22;
      uint32_t x01 = r115[2U];
      uint32_t x11 = r115[((uint32_t)2U + (uint32_t)1U) % (uint32_t)4U];
      uint32_t x21 = r115[((uint32_t)2U + (uint32_t)2U) % (uint32_t)4U];
      uint32_t x31 = r115[((uint32_t)2U + (uint32_t)3U) % (uint32_t)4U];
      r115[0U] = x01;
      r115[1U] = x11;
      r115[2U] = x21;
      r115[3U] = x31;
      uint32_t *r116 = r32;
      uint32_t x02 = r116[3U];
      uint32_t x12 = r116[((uint32_t)3U + (uint32_t)1U) % (uint32_t)4U];
      uint32_t x22 = r116[((uint32_t)3U + (uint32_t)2U) % (uint32_t)4U];
      uint32_t x32 = r116[((uint32_t)3U + (uint32_t)3U) % (uint32_t)4U];
      r116[0U] = x02;
      r116[1U] = x12;
      r116[2U] = x22;
      r116[3U] = x32;
      uint32_t a0 = (uint32_t)0U;
      uint32_t b1 = (uint32_t)1U;
      uint32_t c = (uint32_t)2U;
      uint32_t d = (uint32_t)3U;
      uint32_t r0 = Hacl_Impl_Blake2_Constants_rTable_S[0U];
      uint32_t r1 = Hacl_Impl_Blake2_Constants_rTable_S[1U];
      uint32_t r23 = Hacl_Impl_Blake2_Constants_rTable_S[2U];
      uint32_t r33 = Hacl_Impl_Blake2_Constants_rTable_S[3U];
      uint32_t *wv_a = block_state1.fst + a0 * (uint32_t)4U;
      uint32_t *wv_b8 = block_state1.fst + b1 * (uint32_t)4U;
      for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
      {
        uint32_t *os = wv_a;
        uint32_t x1 = wv_a[i] + wv_b8[i];
        os[i] = x1;
      }
      for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
      {
        uint32_t *os = wv_a;
        uint32_t x1 = wv_a[i] + z[i];
        os[i] = x1;
      }
      uint32_t *wv_a8 = block_state1.fst + d * (uint32_t)4U;
      uint32_t *wv_b9 = block_state1.fst + a0 * (uint32_t)4U;
      for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
      {
        uint32_t *os = wv_a8;
        uint32_t x1 = wv_a8[i] ^ wv_b9[i];
        os[i] = x1;
      }
      uint32_t *r117 = wv_a8;
      for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
      {
        uint32_t *os = r117;
        uint32_t x1 = r117[i];
        uint32_t x13 = x1 >> r0 | x1 << ((uint32_t)32U - r0);
        os[i] = x13;
      }
      uint32_t *wv_a9 = block_state1.fst + c * (uint32_t)4U;
      uint32_t *wv_b10 = block_state1.fst + d * (uint32_t)4U;
      for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
      {
        uint32_t *os = wv_a9;
        uint32_t x1 = wv_a9[i] + wv_b10[i];
        os[i] = x1;
      }
      uint32_t *wv_a10 = block_state1.fst + b1 * (uint32_t)4U;
      uint32_t *wv_b11 = block_state1.fst + c * (uint32_t)4U;
      for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
      {
        uint32_t *os = wv_a10;
        uint32_t x1 = wv_a10[i] ^ wv_b11[i];
        os[i] = x1;
      }
      uint32_t *r118 = wv_a10;
      for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
      {
        uint32_t *os = r118;
        uint32_t x1 = r118[i];
        uint32_t x13 = x1 >> r1 | x1 << ((uint32_t)32U - r1);
        os[i] = x13;
      }
      uint32_t *wv_a11 = block_state1.fst + a0 * (uint32_t)4U;
      uint32_t *wv_b12 = block_state1.fst + b1 * (uint32_t)4U;
      for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
      {
        uint32_t *os = wv_a11;
        uint32_t x1 = wv_a11[i] + wv_b12[i];
        os[i] = x1;
      }
      for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
      {
        uint32_t *os = wv_a11;
        uint32_t x1 = wv_a11[i] + w[i];
        os[i] = x1;
      }
      uint32_t *wv_a12 = block_state1.fst + d * (uint32_t)4U;
      uint32_t *wv_b13 = block_state1.fst + a0 * (uint32_t)4U;
      for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
      {
        uint32_t *os = wv_a12;
        uint32_t x1 = wv_a12[i] ^ wv_b13[i];
        os[i] = x1;
      }
      uint32_t *r119 = wv_a12;
      for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
      {
        uint32_t *os = r119;
        uint32_t x1 = r119[i];
        uint32_t x13 = x1 >> r23 | x1 << ((uint32_t)32U - r23);
        os[i] = x13;
      }
      uint32_t *wv_a13 = block_state1.fst + c * (uint32_t)4U;
      uint32_t *wv_b14 = block_state1.fst + d * (uint32_t)4U;
      for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
      {
        uint32_t *os = wv_a13;
        uint32_t x1 = wv_a13[i] + wv_b14[i];
        os[i] = x1;
      }
      uint32_t *wv_a14 = block_state1.fst + b1 * (uint32_t)4U;
      uint32_t *wv_b = block_state1.fst + c * (uint32_t)4U;
      for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
      {
        uint32_t *os = wv_a14;
        uint32_t x1 = wv_a14[i] ^ wv_b[i];
        os[i] = x1;
      }
      uint32_t *r1110 = wv_a14;
      for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
      {
        uint32_t *os = r1110;
        uint32_t x1 = r1110[i];
        uint32_t x13 = x1 >> r33 | x1 << ((uint32_t)32U - r33);
        os[i] = x13;
      }
      uint32_t *r14 = block_state1.fst + (uint32_t)1U * (uint32_t)4U;
      uint32_t *r2 = block_state1.fst + (uint32_t)2U * (uint32_t)4U;
      uint32_t *r3 = block_state1.fst + (uint32_t)3U * (uint32_t)4U;
      uint32_t *r11 = r14;
      uint32_t x03 = r11[3U];
      uint32_t x13 = r11[((uint32_t)3U + (uint32_t)1U) % (uint32_t)4U];
      uint32_t x23 = r11[((uint32_t)3U + (uint32_t)2U) % (uint32_t)4U];
      uint32_t x33 = r11[((uint32_t)3U + (uint32_t)3U) % (uint32_t)4U];
      r11[0U] = x03;
      r11[1U] = x13;
      r11[2U] = x23;
      r11[3U] = x33;
      uint32_t *r1111 = r2;
      uint32_t x04 = r1111[2U];
      uint32_t x14 = r1111[((uint32_t)2U + (uint32_t)1U) % (uint32_t)4U];
      uint32_t x24 = r1111[((uint32_t)2U + (uint32_t)2U) % (uint32_t)4U];
      uint32_t x34 = r1111[((uint32_t)2U + (uint32_t)3U) % (uint32_t)4U];
      r1111[0U] = x04;
      r1111[1U] = x14;
      r1111[2U] = x24;
      r1111[3U] = x34;
      uint32_t *r1112 = r3;
      uint32_t x0 = r1112[1U];
      uint32_t x1 = r1112[((uint32_t)1U + (uint32_t)1U) % (uint32_t)4U];
      uint32_t x2 = r1112[((uint32_t)1U + (uint32_t)2U) % (uint32_t)4U];
      uint32_t x3 = r1112[((uint32_t)1U + (uint32_t)3U) % (uint32_t)4U];
      r1112[0U] = x0;
      r1112[1U] = x1;
      r1112[2U] = x2;
      r1112[3U] = x3;
    }
    uint32_t *s0 = block_state1.snd + (uint32_t)0U * (uint32_t)4U;
    uint32_t *s11 = block_state1.snd + (uint32_t)1U * (uint32_t)4U;
    uint32_t *r0 = block_state1.fst + (uint32_t)0U * (uint32_t)4U;
    uint32_t *r1 = block_state1.fst + (uint32_t)1U * (uint32_t)4U;
    uint32_t *r2 = block_state1.fst + (uint32_t)2U * (uint32_t)4U;
    uint32_t *r3 = block_state1.fst + (uint32_t)3U * (uint32_t)4U;
    for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
    {
      uint32_t *os = s0;
      uint32_t x = s0[i] ^ r0[i];
      os[i] = x;
    }
    for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
    {
      uint32_t *os = s0;
      uint32_t x = s0[i] ^ r2[i];
      os[i] = x;
    }
    for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
    {
      uint32_t *os = s11;
      uint32_t x = s11[i] ^ r1[i];
      os[i] = x;
    }
    for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
    {
      uint32_t *os = s11;
      uint32_t x = s11[i] ^ r3[i];
      os[i] = x;
    }
  }
  uint8_t *dst = buf;
  memcpy(dst, data21, data2_len * sizeof (data21[0U]));
  *p
  =
    (
      (Hacl_Streaming_Functor_state_s__K____uint32_t___uint32_t____){
        .block_state = block_state1,
        .buf = buf,
        .total_len = total_len1 + (uint64_t)(len - diff)
      }
    );
}

/* SNIPPET_END: Hacl_Streaming_Blake2_blake2s_32_with_key_update */

/* SNIPPET_START: Hacl_Streaming_Blake2_blake2s_32_with_key_finish */

/*
  Finish function when using a (potentially null) key
*/
void
Hacl_Streaming_Blake2_blake2s_32_with_key_finish(
  uint32_t key_size,
  Hacl_Streaming_Functor_state_s__K____uint32_t___uint32_t____ *p,
  uint8_t *dst
)
{
  Hacl_Streaming_Functor_state_s__K____uint32_t___uint32_t____ scrut = *p;
  K____uint32_t___uint32_t_ block_state = scrut.block_state;
  uint8_t *buf_ = scrut.buf;
  uint64_t total_len = scrut.total_len;
  uint32_t r;
  if (total_len % (uint64_t)(uint32_t)64U == (uint64_t)0U && total_len > (uint64_t)0U)
  {
    r = (uint32_t)64U;
  }
  else
  {
    r = (uint32_t)(total_len % (uint64_t)(uint32_t)64U);
  }
  uint8_t *buf_1 = buf_;
  KRML_CHECK_SIZE(sizeof (uint32_t), (uint32_t)4U * (uint32_t)4U);
  uint32_t wv[(uint32_t)4U * (uint32_t)4U];
  memset(wv, 0U, (uint32_t)4U * (uint32_t)4U * sizeof (wv[0U]));
  KRML_CHECK_SIZE(sizeof (uint32_t), (uint32_t)4U * (uint32_t)4U);
  uint32_t b0[(uint32_t)4U * (uint32_t)4U];
  memset(b0, 0U, (uint32_t)4U * (uint32_t)4U * sizeof (b0[0U]));
  K____uint32_t___uint32_t_ tmp_block_state = { .fst = wv, .snd = b0 };
  uint32_t *src_b = block_state.snd;
  uint32_t *dst_b = tmp_block_state.snd;
  memcpy(dst_b, src_b, (uint32_t)16U * sizeof (src_b[0U]));
  uint64_t prev_len = total_len - (uint64_t)r;
  uint8_t b2[64U] = { 0U };
  uint8_t *last = buf_1 + r - r;
  memcpy(b2, last, r * sizeof (last[0U]));
  uint64_t ite;
  if (key_size == (uint32_t)0U)
  {
    ite = prev_len;
  }
  else
  {
    ite = prev_len + (uint64_t)(uint32_t)64U;
  }
  uint64_t totlen = ite + (uint64_t)r;
  uint32_t m_w[16U] = { 0U };
  for (uint32_t i = (uint32_t)0U; i < (uint32_t)16U; i++)
  {
    uint32_t *os = m_w;
    uint8_t *bj = b2 + i * (uint32_t)4U;
    uint32_t u = load32_le(bj);
    uint32_t r1 = u;
    uint32_t x = r1;
    os[i] = x;
  }
  uint32_t mask[4U] = { 0U };
  uint32_t wv_14 = (uint32_t)0xFFFFFFFFU;
  uint32_t wv_15 = (uint32_t)0U;
  mask[0U] = (uint32_t)totlen;
  mask[1U] = (uint32_t)(totlen >> (uint32_t)32U);
  mask[2U] = wv_14;
  mask[3U] = wv_15;
  memcpy(tmp_block_state.fst,
    tmp_block_state.snd,
    (uint32_t)4U * (uint32_t)4U * sizeof (tmp_block_state.snd[0U]));
  uint32_t *wv3 = tmp_block_state.fst + (uint32_t)3U * (uint32_t)4U;
  for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
  {
    uint32_t *os = wv3;
    uint32_t x = wv3[i] ^ mask[i];
    os[i] = x;
  }
  for (uint32_t i0 = (uint32_t)0U; i0 < (uint32_t)10U; i0++)
  {
    uint32_t start_idx = i0 % (uint32_t)10U * (uint32_t)16U;
    KRML_CHECK_SIZE(sizeof (uint32_t), (uint32_t)4U * (uint32_t)4U);
    uint32_t m_st[(uint32_t)4U * (uint32_t)4U];
    memset(m_st, 0U, (uint32_t)4U * (uint32_t)4U * sizeof (m_st[0U]));
    uint32_t *r00 = m_st + (uint32_t)0U * (uint32_t)4U;
    uint32_t *r10 = m_st + (uint32_t)1U * (uint32_t)4U;
    uint32_t *r20 = m_st + (uint32_t)2U * (uint32_t)4U;
    uint32_t *r30 = m_st + (uint32_t)3U * (uint32_t)4U;
    uint32_t s0 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx];
    uint32_t s1 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)1U];
    uint32_t s2 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)2U];
    uint32_t s3 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)3U];
    uint32_t s4 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)4U];
    uint32_t s5 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)5U];
    uint32_t s6 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)6U];
    uint32_t s7 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)7U];
    uint32_t s8 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)8U];
    uint32_t s9 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)9U];
    uint32_t s10 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)10U];
    uint32_t s11 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)11U];
    uint32_t s12 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)12U];
    uint32_t s13 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)13U];
    uint32_t s14 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)14U];
    uint32_t s15 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)15U];
    uint32_t uu____0 = m_w[s2];
    uint32_t uu____1 = m_w[s4];
    uint32_t uu____2 = m_w[s6];
    r00[0U] = m_w[s0];
    r00[1U] = uu____0;
    r00[2U] = uu____1;
    r00[3U] = uu____2;
    uint32_t uu____3 = m_w[s3];
    uint32_t uu____4 = m_w[s5];
    uint32_t uu____5 = m_w[s7];
    r10[0U] = m_w[s1];
    r10[1U] = uu____3;
    r10[2U] = uu____4;
    r10[3U] = uu____5;
    uint32_t uu____6 = m_w[s10];
    uint32_t uu____7 = m_w[s12];
    uint32_t uu____8 = m_w[s14];
    r20[0U] = m_w[s8];
    r20[1U] = uu____6;
    r20[2U] = uu____7;
    r20[3U] = uu____8;
    uint32_t uu____9 = m_w[s11];
    uint32_t uu____10 = m_w[s13];
    uint32_t uu____11 = m_w[s15];
    r30[0U] = m_w[s9];
    r30[1U] = uu____9;
    r30[2U] = uu____10;
    r30[3U] = uu____11;
    uint32_t *x = m_st + (uint32_t)0U * (uint32_t)4U;
    uint32_t *y = m_st + (uint32_t)1U * (uint32_t)4U;
    uint32_t *z = m_st + (uint32_t)2U * (uint32_t)4U;
    uint32_t *w = m_st + (uint32_t)3U * (uint32_t)4U;
    uint32_t a = (uint32_t)0U;
    uint32_t b10 = (uint32_t)1U;
    uint32_t c0 = (uint32_t)2U;
    uint32_t d0 = (uint32_t)3U;
    uint32_t r01 = Hacl_Impl_Blake2_Constants_rTable_S[0U];
    uint32_t r12 = Hacl_Impl_Blake2_Constants_rTable_S[1U];
    uint32_t r21 = Hacl_Impl_Blake2_Constants_rTable_S[2U];
    uint32_t r31 = Hacl_Impl_Blake2_Constants_rTable_S[3U];
    uint32_t *wv_a0 = tmp_block_state.fst + a * (uint32_t)4U;
    uint32_t *wv_b0 = tmp_block_state.fst + b10 * (uint32_t)4U;
    for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
    {
      uint32_t *os = wv_a0;
      uint32_t x1 = wv_a0[i] + wv_b0[i];
      os[i] = x1;
    }
    for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
    {
      uint32_t *os = wv_a0;
      uint32_t x1 = wv_a0[i] + x[i];
      os[i] = x1;
    }
    uint32_t *wv_a1 = tmp_block_state.fst + d0 * (uint32_t)4U;
    uint32_t *wv_b1 = tmp_block_state.fst + a * (uint32_t)4U;
    for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
    {
      uint32_t *os = wv_a1;
      uint32_t x1 = wv_a1[i] ^ wv_b1[i];
      os[i] = x1;
    }
    uint32_t *r110 = wv_a1;
    for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
    {
      uint32_t *os = r110;
      uint32_t x1 = r110[i];
      uint32_t x10 = x1 >> r01 | x1 << ((uint32_t)32U - r01);
      os[i] = x10;
    }
    uint32_t *wv_a2 = tmp_block_state.fst + c0 * (uint32_t)4U;
    uint32_t *wv_b2 = tmp_block_state.fst + d0 * (uint32_t)4U;
    for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
    {
      uint32_t *os = wv_a2;
      uint32_t x1 = wv_a2[i] + wv_b2[i];
      os[i] = x1;
    }
    uint32_t *wv_a3 = tmp_block_state.fst + b10 * (uint32_t)4U;
    uint32_t *wv_b3 = tmp_block_state.fst + c0 * (uint32_t)4U;
    for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
    {
      uint32_t *os = wv_a3;
      uint32_t x1 = wv_a3[i] ^ wv_b3[i];
      os[i] = x1;
    }
    uint32_t *r111 = wv_a3;
    for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
    {
      uint32_t *os = r111;
      uint32_t x1 = r111[i];
      uint32_t x10 = x1 >> r12 | x1 << ((uint32_t)32U - r12);
      os[i] = x10;
    }
    uint32_t *wv_a4 = tmp_block_state.fst + a * (uint32_t)4U;
    uint32_t *wv_b4 = tmp_block_state.fst + b10 * (uint32_t)4U;
    for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
    {
      uint32_t *os = wv_a4;
      uint32_t x1 = wv_a4[i] + wv_b4[i];
      os[i] = x1;
    }
    for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
    {
      uint32_t *os = wv_a4;
      uint32_t x1 = wv_a4[i] + y[i];
      os[i] = x1;
    }
    uint32_t *wv_a5 = tmp_block_state.fst + d0 * (uint32_t)4U;
    uint32_t *wv_b5 = tmp_block_state.fst + a * (uint32_t)4U;
    for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
    {
      uint32_t *os = wv_a5;
      uint32_t x1 = wv_a5[i] ^ wv_b5[i];
      os[i] = x1;
    }
    uint32_t *r112 = wv_a5;
    for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
    {
      uint32_t *os = r112;
      uint32_t x1 = r112[i];
      uint32_t x10 = x1 >> r21 | x1 << ((uint32_t)32U - r21);
      os[i] = x10;
    }
    uint32_t *wv_a6 = tmp_block_state.fst + c0 * (uint32_t)4U;
    uint32_t *wv_b6 = tmp_block_state.fst + d0 * (uint32_t)4U;
    for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
    {
      uint32_t *os = wv_a6;
      uint32_t x1 = wv_a6[i] + wv_b6[i];
      os[i] = x1;
    }
    uint32_t *wv_a7 = tmp_block_state.fst + b10 * (uint32_t)4U;
    uint32_t *wv_b7 = tmp_block_state.fst + c0 * (uint32_t)4U;
    for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
    {
      uint32_t *os = wv_a7;
      uint32_t x1 = wv_a7[i] ^ wv_b7[i];
      os[i] = x1;
    }
    uint32_t *r113 = wv_a7;
    for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
    {
      uint32_t *os = r113;
      uint32_t x1 = r113[i];
      uint32_t x10 = x1 >> r31 | x1 << ((uint32_t)32U - r31);
      os[i] = x10;
    }
    uint32_t *r13 = tmp_block_state.fst + (uint32_t)1U * (uint32_t)4U;
    uint32_t *r22 = tmp_block_state.fst + (uint32_t)2U * (uint32_t)4U;
    uint32_t *r32 = tmp_block_state.fst + (uint32_t)3U * (uint32_t)4U;
    uint32_t *r114 = r13;
    uint32_t x00 = r114[1U];
    uint32_t x10 = r114[((uint32_t)1U + (uint32_t)1U) % (uint32_t)4U];
    uint32_t x20 = r114[((uint32_t)1U + (uint32_t)2U) % (uint32_t)4U];
    uint32_t x30 = r114[((uint32_t)1U + (uint32_t)3U) % (uint32_t)4U];
    r114[0U] = x00;
    r114[1U] = x10;
    r114[2U] = x20;
    r114[3U] = x30;
    uint32_t *r115 = r22;
    uint32_t x01 = r115[2U];
    uint32_t x11 = r115[((uint32_t)2U + (uint32_t)1U) % (uint32_t)4U];
    uint32_t x21 = r115[((uint32_t)2U + (uint32_t)2U) % (uint32_t)4U];
    uint32_t x31 = r115[((uint32_t)2U + (uint32_t)3U) % (uint32_t)4U];
    r115[0U] = x01;
    r115[1U] = x11;
    r115[2U] = x21;
    r115[3U] = x31;
    uint32_t *r116 = r32;
    uint32_t x02 = r116[3U];
    uint32_t x12 = r116[((uint32_t)3U + (uint32_t)1U) % (uint32_t)4U];
    uint32_t x22 = r116[((uint32_t)3U + (uint32_t)2U) % (uint32_t)4U];
    uint32_t x32 = r116[((uint32_t)3U + (uint32_t)3U) % (uint32_t)4U];
    r116[0U] = x02;
    r116[1U] = x12;
    r116[2U] = x22;
    r116[3U] = x32;
    uint32_t a0 = (uint32_t)0U;
    uint32_t b1 = (uint32_t)1U;
    uint32_t c = (uint32_t)2U;
    uint32_t d = (uint32_t)3U;
    uint32_t r0 = Hacl_Impl_Blake2_Constants_rTable_S[0U];
    uint32_t r1 = Hacl_Impl_Blake2_Constants_rTable_S[1U];
    uint32_t r23 = Hacl_Impl_Blake2_Constants_rTable_S[2U];
    uint32_t r33 = Hacl_Impl_Blake2_Constants_rTable_S[3U];
    uint32_t *wv_a = tmp_block_state.fst + a0 * (uint32_t)4U;
    uint32_t *wv_b8 = tmp_block_state.fst + b1 * (uint32_t)4U;
    for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
    {
      uint32_t *os = wv_a;
      uint32_t x1 = wv_a[i] + wv_b8[i];
      os[i] = x1;
    }
    for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
    {
      uint32_t *os = wv_a;
      uint32_t x1 = wv_a[i] + z[i];
      os[i] = x1;
    }
    uint32_t *wv_a8 = tmp_block_state.fst + d * (uint32_t)4U;
    uint32_t *wv_b9 = tmp_block_state.fst + a0 * (uint32_t)4U;
    for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
    {
      uint32_t *os = wv_a8;
      uint32_t x1 = wv_a8[i] ^ wv_b9[i];
      os[i] = x1;
    }
    uint32_t *r117 = wv_a8;
    for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
    {
      uint32_t *os = r117;
      uint32_t x1 = r117[i];
      uint32_t x13 = x1 >> r0 | x1 << ((uint32_t)32U - r0);
      os[i] = x13;
    }
    uint32_t *wv_a9 = tmp_block_state.fst + c * (uint32_t)4U;
    uint32_t *wv_b10 = tmp_block_state.fst + d * (uint32_t)4U;
    for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
    {
      uint32_t *os = wv_a9;
      uint32_t x1 = wv_a9[i] + wv_b10[i];
      os[i] = x1;
    }
    uint32_t *wv_a10 = tmp_block_state.fst + b1 * (uint32_t)4U;
    uint32_t *wv_b11 = tmp_block_state.fst + c * (uint32_t)4U;
    for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
    {
      uint32_t *os = wv_a10;
      uint32_t x1 = wv_a10[i] ^ wv_b11[i];
      os[i] = x1;
    }
    uint32_t *r118 = wv_a10;
    for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
    {
      uint32_t *os = r118;
      uint32_t x1 = r118[i];
      uint32_t x13 = x1 >> r1 | x1 << ((uint32_t)32U - r1);
      os[i] = x13;
    }
    uint32_t *wv_a11 = tmp_block_state.fst + a0 * (uint32_t)4U;
    uint32_t *wv_b12 = tmp_block_state.fst + b1 * (uint32_t)4U;
    for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
    {
      uint32_t *os = wv_a11;
      uint32_t x1 = wv_a11[i] + wv_b12[i];
      os[i] = x1;
    }
    for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
    {
      uint32_t *os = wv_a11;
      uint32_t x1 = wv_a11[i] + w[i];
      os[i] = x1;
    }
    uint32_t *wv_a12 = tmp_block_state.fst + d * (uint32_t)4U;
    uint32_t *wv_b13 = tmp_block_state.fst + a0 * (uint32_t)4U;
    for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
    {
      uint32_t *os = wv_a12;
      uint32_t x1 = wv_a12[i] ^ wv_b13[i];
      os[i] = x1;
    }
    uint32_t *r119 = wv_a12;
    for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
    {
      uint32_t *os = r119;
      uint32_t x1 = r119[i];
      uint32_t x13 = x1 >> r23 | x1 << ((uint32_t)32U - r23);
      os[i] = x13;
    }
    uint32_t *wv_a13 = tmp_block_state.fst + c * (uint32_t)4U;
    uint32_t *wv_b14 = tmp_block_state.fst + d * (uint32_t)4U;
    for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
    {
      uint32_t *os = wv_a13;
      uint32_t x1 = wv_a13[i] + wv_b14[i];
      os[i] = x1;
    }
    uint32_t *wv_a14 = tmp_block_state.fst + b1 * (uint32_t)4U;
    uint32_t *wv_b = tmp_block_state.fst + c * (uint32_t)4U;
    for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
    {
      uint32_t *os = wv_a14;
      uint32_t x1 = wv_a14[i] ^ wv_b[i];
      os[i] = x1;
    }
    uint32_t *r1110 = wv_a14;
    for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
    {
      uint32_t *os = r1110;
      uint32_t x1 = r1110[i];
      uint32_t x13 = x1 >> r33 | x1 << ((uint32_t)32U - r33);
      os[i] = x13;
    }
    uint32_t *r14 = tmp_block_state.fst + (uint32_t)1U * (uint32_t)4U;
    uint32_t *r2 = tmp_block_state.fst + (uint32_t)2U * (uint32_t)4U;
    uint32_t *r3 = tmp_block_state.fst + (uint32_t)3U * (uint32_t)4U;
    uint32_t *r11 = r14;
    uint32_t x03 = r11[3U];
    uint32_t x13 = r11[((uint32_t)3U + (uint32_t)1U) % (uint32_t)4U];
    uint32_t x23 = r11[((uint32_t)3U + (uint32_t)2U) % (uint32_t)4U];
    uint32_t x33 = r11[((uint32_t)3U + (uint32_t)3U) % (uint32_t)4U];
    r11[0U] = x03;
    r11[1U] = x13;
    r11[2U] = x23;
    r11[3U] = x33;
    uint32_t *r1111 = r2;
    uint32_t x04 = r1111[2U];
    uint32_t x14 = r1111[((uint32_t)2U + (uint32_t)1U) % (uint32_t)4U];
    uint32_t x24 = r1111[((uint32_t)2U + (uint32_t)2U) % (uint32_t)4U];
    uint32_t x34 = r1111[((uint32_t)2U + (uint32_t)3U) % (uint32_t)4U];
    r1111[0U] = x04;
    r1111[1U] = x14;
    r1111[2U] = x24;
    r1111[3U] = x34;
    uint32_t *r1112 = r3;
    uint32_t x0 = r1112[1U];
    uint32_t x1 = r1112[((uint32_t)1U + (uint32_t)1U) % (uint32_t)4U];
    uint32_t x2 = r1112[((uint32_t)1U + (uint32_t)2U) % (uint32_t)4U];
    uint32_t x3 = r1112[((uint32_t)1U + (uint32_t)3U) % (uint32_t)4U];
    r1112[0U] = x0;
    r1112[1U] = x1;
    r1112[2U] = x2;
    r1112[3U] = x3;
  }
  uint32_t *s0 = tmp_block_state.snd + (uint32_t)0U * (uint32_t)4U;
  uint32_t *s1 = tmp_block_state.snd + (uint32_t)1U * (uint32_t)4U;
  uint32_t *r0 = tmp_block_state.fst + (uint32_t)0U * (uint32_t)4U;
  uint32_t *r1 = tmp_block_state.fst + (uint32_t)1U * (uint32_t)4U;
  uint32_t *r2 = tmp_block_state.fst + (uint32_t)2U * (uint32_t)4U;
  uint32_t *r3 = tmp_block_state.fst + (uint32_t)3U * (uint32_t)4U;
  for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
  {
    uint32_t *os = s0;
    uint32_t x = s0[i] ^ r0[i];
    os[i] = x;
  }
  for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
  {
    uint32_t *os = s0;
    uint32_t x = s0[i] ^ r2[i];
    os[i] = x;
  }
  for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
  {
    uint32_t *os = s1;
    uint32_t x = s1[i] ^ r1[i];
    os[i] = x;
  }
  for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
  {
    uint32_t *os = s1;
    uint32_t x = s1[i] ^ r3[i];
    os[i] = x;
  }
  Lib_Memzero0_memzero(b2, (uint32_t)64U * sizeof (b2[0U]));
  uint32_t double_row = (uint32_t)2U * (uint32_t)4U * (uint32_t)4U;
  KRML_CHECK_SIZE(sizeof (uint8_t), double_row);
  uint8_t b[double_row];
  memset(b, 0U, double_row * sizeof (b[0U]));
  uint8_t *first = b;
  uint8_t *second = b + (uint32_t)4U * (uint32_t)4U;
  uint32_t *row0 = tmp_block_state.snd + (uint32_t)0U * (uint32_t)4U;
  uint32_t *row1 = tmp_block_state.snd + (uint32_t)1U * (uint32_t)4U;
  for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
  {
    store32_le(first + i * (uint32_t)4U, row0[i]);
  }
  for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
  {
    store32_le(second + i * (uint32_t)4U, row1[i]);
  }
  uint8_t *final = b;
  memcpy(dst, final, (uint32_t)32U * sizeof (final[0U]));
  Lib_Memzero0_memzero(b, double_row * sizeof (b[0U]));
}

/* SNIPPET_END: Hacl_Streaming_Blake2_blake2s_32_with_key_finish */

/* SNIPPET_START: Hacl_Streaming_Blake2_blake2s_32_with_key_free */

/*
  Free state function when using a (potentially null) key
*/
void
Hacl_Streaming_Blake2_blake2s_32_with_key_free(
  uint32_t key_size,
  Hacl_Streaming_Functor_state_s__K____uint32_t___uint32_t____ *s1
)
{
  Hacl_Streaming_Functor_state_s__K____uint32_t___uint32_t____ scrut = *s1;
  uint8_t *buf = scrut.buf;
  K____uint32_t___uint32_t_ block_state = scrut.block_state;
  uint32_t *wv = block_state.fst;
  uint32_t *b = block_state.snd;
  KRML_HOST_FREE(wv);
  KRML_HOST_FREE(b);
  KRML_HOST_FREE(buf);
  KRML_HOST_FREE(s1);
}

/* SNIPPET_END: Hacl_Streaming_Blake2_blake2s_32_with_key_free */

/* SNIPPET_START: Hacl_Streaming_Blake2_blake2s_128_with_key_create_in */

/*
  State allocation function when using a (potentially null) key
*/
Hacl_Streaming_Functor_state_s__K____Lib_IntVector_Intrinsics_vec128___Lib_IntVector_Intrinsics_vec128____
*Hacl_Streaming_Blake2_blake2s_128_with_key_create_in(uint32_t key_size, uint8_t *k1)
{
  uint8_t *buf = KRML_HOST_CALLOC((uint32_t)64U, sizeof (uint8_t));
  Lib_IntVector_Intrinsics_vec128
  *wv = KRML_HOST_MALLOC(sizeof (Lib_IntVector_Intrinsics_vec128) * (uint32_t)4U);
  for (uint32_t _i = 0U; _i < (uint32_t)4U; ++_i)
    wv[_i] = Lib_IntVector_Intrinsics_vec128_zero;
  Lib_IntVector_Intrinsics_vec128
  *b0 = KRML_HOST_MALLOC(sizeof (Lib_IntVector_Intrinsics_vec128) * (uint32_t)4U);
  for (uint32_t _i = 0U; _i < (uint32_t)4U; ++_i)
    b0[_i] = Lib_IntVector_Intrinsics_vec128_zero;
  K____Lib_IntVector_Intrinsics_vec128___Lib_IntVector_Intrinsics_vec128_
  block_state = { .fst = wv, .snd = b0 };
  Hacl_Streaming_Functor_state_s__K____Lib_IntVector_Intrinsics_vec128___Lib_IntVector_Intrinsics_vec128____
  s1 = { .block_state = block_state, .buf = buf, .total_len = (uint64_t)0U };
  KRML_CHECK_SIZE(sizeof (
      Hacl_Streaming_Functor_state_s__K____Lib_IntVector_Intrinsics_vec128___Lib_IntVector_Intrinsics_vec128____
    ),
    (uint32_t)1U);
  Hacl_Streaming_Functor_state_s__K____Lib_IntVector_Intrinsics_vec128___Lib_IntVector_Intrinsics_vec128____
  *p =
    KRML_HOST_MALLOC(sizeof (
        Hacl_Streaming_Functor_state_s__K____Lib_IntVector_Intrinsics_vec128___Lib_IntVector_Intrinsics_vec128____
      ));
  p[0U] = s1;
  uint8_t b[64U] = { 0U };
  Lib_IntVector_Intrinsics_vec128 *r00 = block_state.snd + (uint32_t)0U * (uint32_t)1U;
  Lib_IntVector_Intrinsics_vec128 *r10 = block_state.snd + (uint32_t)1U * (uint32_t)1U;
  Lib_IntVector_Intrinsics_vec128 *r20 = block_state.snd + (uint32_t)2U * (uint32_t)1U;
  Lib_IntVector_Intrinsics_vec128 *r30 = block_state.snd + (uint32_t)3U * (uint32_t)1U;
  uint32_t iv0 = Hacl_Impl_Blake2_Constants_ivTable_S[0U];
  uint32_t iv1 = Hacl_Impl_Blake2_Constants_ivTable_S[1U];
  uint32_t iv2 = Hacl_Impl_Blake2_Constants_ivTable_S[2U];
  uint32_t iv3 = Hacl_Impl_Blake2_Constants_ivTable_S[3U];
  uint32_t iv4 = Hacl_Impl_Blake2_Constants_ivTable_S[4U];
  uint32_t iv5 = Hacl_Impl_Blake2_Constants_ivTable_S[5U];
  uint32_t iv6 = Hacl_Impl_Blake2_Constants_ivTable_S[6U];
  uint32_t iv7 = Hacl_Impl_Blake2_Constants_ivTable_S[7U];
  r20[0U] = Lib_IntVector_Intrinsics_vec128_load32s(iv0, iv1, iv2, iv3);
  r30[0U] = Lib_IntVector_Intrinsics_vec128_load32s(iv4, iv5, iv6, iv7);
  uint32_t kk_shift_8 = key_size << (uint32_t)8U;
  uint32_t iv0_ = iv0 ^ ((uint32_t)0x01010000U ^ (kk_shift_8 ^ (uint32_t)32U));
  r00[0U] = Lib_IntVector_Intrinsics_vec128_load32s(iv0_, iv1, iv2, iv3);
  r10[0U] = Lib_IntVector_Intrinsics_vec128_load32s(iv4, iv5, iv6, iv7);
  if (!(key_size == (uint32_t)0U))
  {
    memcpy(b, k1, key_size * sizeof (k1[0U]));
    uint64_t totlen = (uint64_t)(uint32_t)0U + (uint64_t)(uint32_t)64U;
    uint8_t *b1 = b + (uint32_t)0U * (uint32_t)64U;
    uint32_t m_w[16U] = { 0U };
    for (uint32_t i = (uint32_t)0U; i < (uint32_t)16U; i++)
    {
      uint32_t *os = m_w;
      uint8_t *bj = b1 + i * (uint32_t)4U;
      uint32_t u = load32_le(bj);
      uint32_t r1 = u;
      uint32_t x = r1;
      os[i] = x;
    }
    Lib_IntVector_Intrinsics_vec128 mask = Lib_IntVector_Intrinsics_vec128_zero;
    uint32_t wv_14 = (uint32_t)0U;
    uint32_t wv_15 = (uint32_t)0U;
    mask =
      Lib_IntVector_Intrinsics_vec128_load32s((uint32_t)totlen,
        (uint32_t)(totlen >> (uint32_t)32U),
        wv_14,
        wv_15);
    memcpy(block_state.fst,
      block_state.snd,
      (uint32_t)4U * (uint32_t)1U * sizeof (block_state.snd[0U]));
    Lib_IntVector_Intrinsics_vec128 *wv3 = block_state.fst + (uint32_t)3U * (uint32_t)1U;
    wv3[0U] = Lib_IntVector_Intrinsics_vec128_xor(wv3[0U], mask);
    for (uint32_t i = (uint32_t)0U; i < (uint32_t)10U; i++)
    {
      uint32_t start_idx = i % (uint32_t)10U * (uint32_t)16U;
      KRML_CHECK_SIZE(sizeof (Lib_IntVector_Intrinsics_vec128), (uint32_t)4U * (uint32_t)1U);
      Lib_IntVector_Intrinsics_vec128 m_st[(uint32_t)4U * (uint32_t)1U];
      for (uint32_t _i = 0U; _i < (uint32_t)4U * (uint32_t)1U; ++_i)
        m_st[_i] = Lib_IntVector_Intrinsics_vec128_zero;
      Lib_IntVector_Intrinsics_vec128 *r01 = m_st + (uint32_t)0U * (uint32_t)1U;
      Lib_IntVector_Intrinsics_vec128 *r11 = m_st + (uint32_t)1U * (uint32_t)1U;
      Lib_IntVector_Intrinsics_vec128 *r21 = m_st + (uint32_t)2U * (uint32_t)1U;
      Lib_IntVector_Intrinsics_vec128 *r31 = m_st + (uint32_t)3U * (uint32_t)1U;
      uint32_t s0 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx];
      uint32_t s11 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)1U];
      uint32_t s2 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)2U];
      uint32_t s3 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)3U];
      uint32_t s4 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)4U];
      uint32_t s5 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)5U];
      uint32_t s6 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)6U];
      uint32_t s7 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)7U];
      uint32_t s8 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)8U];
      uint32_t s9 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)9U];
      uint32_t s10 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)10U];
      uint32_t s111 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)11U];
      uint32_t s12 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)12U];
      uint32_t s13 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)13U];
      uint32_t s14 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)14U];
      uint32_t s15 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)15U];
      r01[0U] = Lib_IntVector_Intrinsics_vec128_load32s(m_w[s0], m_w[s2], m_w[s4], m_w[s6]);
      r11[0U] = Lib_IntVector_Intrinsics_vec128_load32s(m_w[s11], m_w[s3], m_w[s5], m_w[s7]);
      r21[0U] = Lib_IntVector_Intrinsics_vec128_load32s(m_w[s8], m_w[s10], m_w[s12], m_w[s14]);
      r31[0U] = Lib_IntVector_Intrinsics_vec128_load32s(m_w[s9], m_w[s111], m_w[s13], m_w[s15]);
      Lib_IntVector_Intrinsics_vec128 *x = m_st + (uint32_t)0U * (uint32_t)1U;
      Lib_IntVector_Intrinsics_vec128 *y = m_st + (uint32_t)1U * (uint32_t)1U;
      Lib_IntVector_Intrinsics_vec128 *z = m_st + (uint32_t)2U * (uint32_t)1U;
      Lib_IntVector_Intrinsics_vec128 *w = m_st + (uint32_t)3U * (uint32_t)1U;
      uint32_t a = (uint32_t)0U;
      uint32_t b20 = (uint32_t)1U;
      uint32_t c0 = (uint32_t)2U;
      uint32_t d0 = (uint32_t)3U;
      uint32_t r02 = Hacl_Impl_Blake2_Constants_rTable_S[0U];
      uint32_t r12 = Hacl_Impl_Blake2_Constants_rTable_S[1U];
      uint32_t r22 = Hacl_Impl_Blake2_Constants_rTable_S[2U];
      uint32_t r32 = Hacl_Impl_Blake2_Constants_rTable_S[3U];
      Lib_IntVector_Intrinsics_vec128 *wv_a0 = block_state.fst + a * (uint32_t)1U;
      Lib_IntVector_Intrinsics_vec128 *wv_b0 = block_state.fst + b20 * (uint32_t)1U;
      wv_a0[0U] = Lib_IntVector_Intrinsics_vec128_add32(wv_a0[0U], wv_b0[0U]);
      wv_a0[0U] = Lib_IntVector_Intrinsics_vec128_add32(wv_a0[0U], x[0U]);
      Lib_IntVector_Intrinsics_vec128 *wv_a1 = block_state.fst + d0 * (uint32_t)1U;
      Lib_IntVector_Intrinsics_vec128 *wv_b1 = block_state.fst + a * (uint32_t)1U;
      wv_a1[0U] = Lib_IntVector_Intrinsics_vec128_xor(wv_a1[0U], wv_b1[0U]);
      wv_a1[0U] = Lib_IntVector_Intrinsics_vec128_rotate_right32(wv_a1[0U], r02);
      Lib_IntVector_Intrinsics_vec128 *wv_a2 = block_state.fst + c0 * (uint32_t)1U;
      Lib_IntVector_Intrinsics_vec128 *wv_b2 = block_state.fst + d0 * (uint32_t)1U;
      wv_a2[0U] = Lib_IntVector_Intrinsics_vec128_add32(wv_a2[0U], wv_b2[0U]);
      Lib_IntVector_Intrinsics_vec128 *wv_a3 = block_state.fst + b20 * (uint32_t)1U;
      Lib_IntVector_Intrinsics_vec128 *wv_b3 = block_state.fst + c0 * (uint32_t)1U;
      wv_a3[0U] = Lib_IntVector_Intrinsics_vec128_xor(wv_a3[0U], wv_b3[0U]);
      wv_a3[0U] = Lib_IntVector_Intrinsics_vec128_rotate_right32(wv_a3[0U], r12);
      Lib_IntVector_Intrinsics_vec128 *wv_a4 = block_state.fst + a * (uint32_t)1U;
      Lib_IntVector_Intrinsics_vec128 *wv_b4 = block_state.fst + b20 * (uint32_t)1U;
      wv_a4[0U] = Lib_IntVector_Intrinsics_vec128_add32(wv_a4[0U], wv_b4[0U]);
      wv_a4[0U] = Lib_IntVector_Intrinsics_vec128_add32(wv_a4[0U], y[0U]);
      Lib_IntVector_Intrinsics_vec128 *wv_a5 = block_state.fst + d0 * (uint32_t)1U;
      Lib_IntVector_Intrinsics_vec128 *wv_b5 = block_state.fst + a * (uint32_t)1U;
      wv_a5[0U] = Lib_IntVector_Intrinsics_vec128_xor(wv_a5[0U], wv_b5[0U]);
      wv_a5[0U] = Lib_IntVector_Intrinsics_vec128_rotate_right32(wv_a5[0U], r22);
      Lib_IntVector_Intrinsics_vec128 *wv_a6 = block_state.fst + c0 * (uint32_t)1U;
      Lib_IntVector_Intrinsics_vec128 *wv_b6 = block_state.fst + d0 * (uint32_t)1U;
      wv_a6[0U] = Lib_IntVector_Intrinsics_vec128_add32(wv_a6[0U], wv_b6[0U]);
      Lib_IntVector_Intrinsics_vec128 *wv_a7 = block_state.fst + b20 * (uint32_t)1U;
      Lib_IntVector_Intrinsics_vec128 *wv_b7 = block_state.fst + c0 * (uint32_t)1U;
      wv_a7[0U] = Lib_IntVector_Intrinsics_vec128_xor(wv_a7[0U], wv_b7[0U]);
      wv_a7[0U] = Lib_IntVector_Intrinsics_vec128_rotate_right32(wv_a7[0U], r32);
      Lib_IntVector_Intrinsics_vec128 *r13 = block_state.fst + (uint32_t)1U * (uint32_t)1U;
      Lib_IntVector_Intrinsics_vec128 *r23 = block_state.fst + (uint32_t)2U * (uint32_t)1U;
      Lib_IntVector_Intrinsics_vec128 *r33 = block_state.fst + (uint32_t)3U * (uint32_t)1U;
      Lib_IntVector_Intrinsics_vec128 v00 = r13[0U];
      Lib_IntVector_Intrinsics_vec128
      v1 = Lib_IntVector_Intrinsics_vec128_rotate_right_lanes32(v00, (uint32_t)1U);
      r13[0U] = v1;
      Lib_IntVector_Intrinsics_vec128 v01 = r23[0U];
      Lib_IntVector_Intrinsics_vec128
      v10 = Lib_IntVector_Intrinsics_vec128_rotate_right_lanes32(v01, (uint32_t)2U);
      r23[0U] = v10;
      Lib_IntVector_Intrinsics_vec128 v02 = r33[0U];
      Lib_IntVector_Intrinsics_vec128
      v11 = Lib_IntVector_Intrinsics_vec128_rotate_right_lanes32(v02, (uint32_t)3U);
      r33[0U] = v11;
      uint32_t a0 = (uint32_t)0U;
      uint32_t b2 = (uint32_t)1U;
      uint32_t c = (uint32_t)2U;
      uint32_t d = (uint32_t)3U;
      uint32_t r0 = Hacl_Impl_Blake2_Constants_rTable_S[0U];
      uint32_t r1 = Hacl_Impl_Blake2_Constants_rTable_S[1U];
      uint32_t r24 = Hacl_Impl_Blake2_Constants_rTable_S[2U];
      uint32_t r34 = Hacl_Impl_Blake2_Constants_rTable_S[3U];
      Lib_IntVector_Intrinsics_vec128 *wv_a = block_state.fst + a0 * (uint32_t)1U;
      Lib_IntVector_Intrinsics_vec128 *wv_b8 = block_state.fst + b2 * (uint32_t)1U;
      wv_a[0U] = Lib_IntVector_Intrinsics_vec128_add32(wv_a[0U], wv_b8[0U]);
      wv_a[0U] = Lib_IntVector_Intrinsics_vec128_add32(wv_a[0U], z[0U]);
      Lib_IntVector_Intrinsics_vec128 *wv_a8 = block_state.fst + d * (uint32_t)1U;
      Lib_IntVector_Intrinsics_vec128 *wv_b9 = block_state.fst + a0 * (uint32_t)1U;
      wv_a8[0U] = Lib_IntVector_Intrinsics_vec128_xor(wv_a8[0U], wv_b9[0U]);
      wv_a8[0U] = Lib_IntVector_Intrinsics_vec128_rotate_right32(wv_a8[0U], r0);
      Lib_IntVector_Intrinsics_vec128 *wv_a9 = block_state.fst + c * (uint32_t)1U;
      Lib_IntVector_Intrinsics_vec128 *wv_b10 = block_state.fst + d * (uint32_t)1U;
      wv_a9[0U] = Lib_IntVector_Intrinsics_vec128_add32(wv_a9[0U], wv_b10[0U]);
      Lib_IntVector_Intrinsics_vec128 *wv_a10 = block_state.fst + b2 * (uint32_t)1U;
      Lib_IntVector_Intrinsics_vec128 *wv_b11 = block_state.fst + c * (uint32_t)1U;
      wv_a10[0U] = Lib_IntVector_Intrinsics_vec128_xor(wv_a10[0U], wv_b11[0U]);
      wv_a10[0U] = Lib_IntVector_Intrinsics_vec128_rotate_right32(wv_a10[0U], r1);
      Lib_IntVector_Intrinsics_vec128 *wv_a11 = block_state.fst + a0 * (uint32_t)1U;
      Lib_IntVector_Intrinsics_vec128 *wv_b12 = block_state.fst + b2 * (uint32_t)1U;
      wv_a11[0U] = Lib_IntVector_Intrinsics_vec128_add32(wv_a11[0U], wv_b12[0U]);
      wv_a11[0U] = Lib_IntVector_Intrinsics_vec128_add32(wv_a11[0U], w[0U]);
      Lib_IntVector_Intrinsics_vec128 *wv_a12 = block_state.fst + d * (uint32_t)1U;
      Lib_IntVector_Intrinsics_vec128 *wv_b13 = block_state.fst + a0 * (uint32_t)1U;
      wv_a12[0U] = Lib_IntVector_Intrinsics_vec128_xor(wv_a12[0U], wv_b13[0U]);
      wv_a12[0U] = Lib_IntVector_Intrinsics_vec128_rotate_right32(wv_a12[0U], r24);
      Lib_IntVector_Intrinsics_vec128 *wv_a13 = block_state.fst + c * (uint32_t)1U;
      Lib_IntVector_Intrinsics_vec128 *wv_b14 = block_state.fst + d * (uint32_t)1U;
      wv_a13[0U] = Lib_IntVector_Intrinsics_vec128_add32(wv_a13[0U], wv_b14[0U]);
      Lib_IntVector_Intrinsics_vec128 *wv_a14 = block_state.fst + b2 * (uint32_t)1U;
      Lib_IntVector_Intrinsics_vec128 *wv_b = block_state.fst + c * (uint32_t)1U;
      wv_a14[0U] = Lib_IntVector_Intrinsics_vec128_xor(wv_a14[0U], wv_b[0U]);
      wv_a14[0U] = Lib_IntVector_Intrinsics_vec128_rotate_right32(wv_a14[0U], r34);
      Lib_IntVector_Intrinsics_vec128 *r14 = block_state.fst + (uint32_t)1U * (uint32_t)1U;
      Lib_IntVector_Intrinsics_vec128 *r2 = block_state.fst + (uint32_t)2U * (uint32_t)1U;
      Lib_IntVector_Intrinsics_vec128 *r3 = block_state.fst + (uint32_t)3U * (uint32_t)1U;
      Lib_IntVector_Intrinsics_vec128 v0 = r14[0U];
      Lib_IntVector_Intrinsics_vec128
      v12 = Lib_IntVector_Intrinsics_vec128_rotate_right_lanes32(v0, (uint32_t)3U);
      r14[0U] = v12;
      Lib_IntVector_Intrinsics_vec128 v03 = r2[0U];
      Lib_IntVector_Intrinsics_vec128
      v13 = Lib_IntVector_Intrinsics_vec128_rotate_right_lanes32(v03, (uint32_t)2U);
      r2[0U] = v13;
      Lib_IntVector_Intrinsics_vec128 v04 = r3[0U];
      Lib_IntVector_Intrinsics_vec128
      v14 = Lib_IntVector_Intrinsics_vec128_rotate_right_lanes32(v04, (uint32_t)1U);
      r3[0U] = v14;
    }
    Lib_IntVector_Intrinsics_vec128 *s0 = block_state.snd + (uint32_t)0U * (uint32_t)1U;
    Lib_IntVector_Intrinsics_vec128 *s11 = block_state.snd + (uint32_t)1U * (uint32_t)1U;
    Lib_IntVector_Intrinsics_vec128 *r0 = block_state.fst + (uint32_t)0U * (uint32_t)1U;
    Lib_IntVector_Intrinsics_vec128 *r1 = block_state.fst + (uint32_t)1U * (uint32_t)1U;
    Lib_IntVector_Intrinsics_vec128 *r2 = block_state.fst + (uint32_t)2U * (uint32_t)1U;
    Lib_IntVector_Intrinsics_vec128 *r3 = block_state.fst + (uint32_t)3U * (uint32_t)1U;
    s0[0U] = Lib_IntVector_Intrinsics_vec128_xor(s0[0U], r0[0U]);
    s0[0U] = Lib_IntVector_Intrinsics_vec128_xor(s0[0U], r2[0U]);
    s11[0U] = Lib_IntVector_Intrinsics_vec128_xor(s11[0U], r1[0U]);
    s11[0U] = Lib_IntVector_Intrinsics_vec128_xor(s11[0U], r3[0U]);
  }
  Lib_Memzero0_memzero(b, (uint32_t)64U * sizeof (b[0U]));
  return p;
}

/* SNIPPET_END: Hacl_Streaming_Blake2_blake2s_128_with_key_create_in */

/* SNIPPET_START: Hacl_Streaming_Blake2_blake2s_128_with_key_update */

/*
  Update function when using a (potentially null) key
*/
void
Hacl_Streaming_Blake2_blake2s_128_with_key_update(
  uint32_t key_size,
  Hacl_Streaming_Functor_state_s__K____Lib_IntVector_Intrinsics_vec128___Lib_IntVector_Intrinsics_vec128____
  *p,
  uint8_t *data,
  uint32_t len
)
{
  Hacl_Streaming_Functor_state_s__K____Lib_IntVector_Intrinsics_vec128___Lib_IntVector_Intrinsics_vec128____
  s1 = *p;
  uint64_t total_len = s1.total_len;
  uint32_t sz;
  if (total_len % (uint64_t)(uint32_t)64U == (uint64_t)0U && total_len > (uint64_t)0U)
  {
    sz = (uint32_t)64U;
  }
  else
  {
    sz = (uint32_t)(total_len % (uint64_t)(uint32_t)64U);
  }
  if (len <= (uint32_t)64U - sz)
  {
    Hacl_Streaming_Functor_state_s__K____Lib_IntVector_Intrinsics_vec128___Lib_IntVector_Intrinsics_vec128____
    s2 = *p;
    K____Lib_IntVector_Intrinsics_vec128___Lib_IntVector_Intrinsics_vec128_
    block_state1 = s2.block_state;
    uint8_t *buf = s2.buf;
    uint64_t total_len1 = s2.total_len;
    uint32_t sz1;
    if (total_len1 % (uint64_t)(uint32_t)64U == (uint64_t)0U && total_len1 > (uint64_t)0U)
    {
      sz1 = (uint32_t)64U;
    }
    else
    {
      sz1 = (uint32_t)(total_len1 % (uint64_t)(uint32_t)64U);
    }
    uint8_t *buf2 = buf + sz1;
    memcpy(buf2, data, len * sizeof (data[0U]));
    uint64_t total_len2 = total_len1 + (uint64_t)len;
    *p
    =
      (
        (Hacl_Streaming_Functor_state_s__K____Lib_IntVector_Intrinsics_vec128___Lib_IntVector_Intrinsics_vec128____){
          .block_state = block_state1,
          .buf = buf,
          .total_len = total_len2
        }
      );
    return;
  }
  if (sz == (uint32_t)0U)
  {
    Hacl_Streaming_Functor_state_s__K____Lib_IntVector_Intrinsics_vec128___Lib_IntVector_Intrinsics_vec128____
    s2 = *p;
    K____Lib_IntVector_Intrinsics_vec128___Lib_IntVector_Intrinsics_vec128_
    block_state1 = s2.block_state;
    uint8_t *buf = s2.buf;
    uint64_t total_len1 = s2.total_len;
    uint32_t sz1;
    if (total_len1 % (uint64_t)(uint32_t)64U == (uint64_t)0U && total_len1 > (uint64_t)0U)
    {
      sz1 = (uint32_t)64U;
    }
    else
    {
      sz1 = (uint32_t)(total_len1 % (uint64_t)(uint32_t)64U);
    }
    if (!(sz1 == (uint32_t)0U))
    {
      uint64_t prevlen = total_len1 - (uint64_t)sz1;
      uint32_t nb = (uint32_t)1U;
      for (uint32_t i0 = (uint32_t)0U; i0 < nb; i0++)
      {
        uint64_t ite;
        if (key_size == (uint32_t)0U)
        {
          ite = prevlen;
        }
        else
        {
          ite = prevlen + (uint64_t)(uint32_t)64U;
        }
        uint64_t totlen = ite + (uint64_t)((i0 + (uint32_t)1U) * (uint32_t)64U);
        uint8_t *b = buf + i0 * (uint32_t)64U;
        uint32_t m_w[16U] = { 0U };
        for (uint32_t i = (uint32_t)0U; i < (uint32_t)16U; i++)
        {
          uint32_t *os = m_w;
          uint8_t *bj = b + i * (uint32_t)4U;
          uint32_t u = load32_le(bj);
          uint32_t r = u;
          uint32_t x = r;
          os[i] = x;
        }
        Lib_IntVector_Intrinsics_vec128 mask = Lib_IntVector_Intrinsics_vec128_zero;
        uint32_t wv_14 = (uint32_t)0U;
        uint32_t wv_15 = (uint32_t)0U;
        mask =
          Lib_IntVector_Intrinsics_vec128_load32s((uint32_t)totlen,
            (uint32_t)(totlen >> (uint32_t)32U),
            wv_14,
            wv_15);
        memcpy(block_state1.fst,
          block_state1.snd,
          (uint32_t)4U * (uint32_t)1U * sizeof (block_state1.snd[0U]));
        Lib_IntVector_Intrinsics_vec128 *wv3 = block_state1.fst + (uint32_t)3U * (uint32_t)1U;
        wv3[0U] = Lib_IntVector_Intrinsics_vec128_xor(wv3[0U], mask);
        for (uint32_t i = (uint32_t)0U; i < (uint32_t)10U; i++)
        {
          uint32_t start_idx = i % (uint32_t)10U * (uint32_t)16U;
          KRML_CHECK_SIZE(sizeof (Lib_IntVector_Intrinsics_vec128), (uint32_t)4U * (uint32_t)1U);
          Lib_IntVector_Intrinsics_vec128 m_st[(uint32_t)4U * (uint32_t)1U];
          for (uint32_t _i = 0U; _i < (uint32_t)4U * (uint32_t)1U; ++_i)
            m_st[_i] = Lib_IntVector_Intrinsics_vec128_zero;
          Lib_IntVector_Intrinsics_vec128 *r00 = m_st + (uint32_t)0U * (uint32_t)1U;
          Lib_IntVector_Intrinsics_vec128 *r10 = m_st + (uint32_t)1U * (uint32_t)1U;
          Lib_IntVector_Intrinsics_vec128 *r20 = m_st + (uint32_t)2U * (uint32_t)1U;
          Lib_IntVector_Intrinsics_vec128 *r30 = m_st + (uint32_t)3U * (uint32_t)1U;
          uint32_t s0 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx];
          uint32_t s11 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)1U];
          uint32_t s21 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)2U];
          uint32_t s3 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)3U];
          uint32_t s4 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)4U];
          uint32_t s5 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)5U];
          uint32_t s6 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)6U];
          uint32_t s7 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)7U];
          uint32_t s8 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)8U];
          uint32_t s9 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)9U];
          uint32_t s10 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)10U];
          uint32_t s111 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)11U];
          uint32_t s12 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)12U];
          uint32_t s13 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)13U];
          uint32_t s14 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)14U];
          uint32_t s15 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)15U];
          r00[0U] = Lib_IntVector_Intrinsics_vec128_load32s(m_w[s0], m_w[s21], m_w[s4], m_w[s6]);
          r10[0U] = Lib_IntVector_Intrinsics_vec128_load32s(m_w[s11], m_w[s3], m_w[s5], m_w[s7]);
          r20[0U] = Lib_IntVector_Intrinsics_vec128_load32s(m_w[s8], m_w[s10], m_w[s12], m_w[s14]);
          r30[0U] = Lib_IntVector_Intrinsics_vec128_load32s(m_w[s9], m_w[s111], m_w[s13], m_w[s15]);
          Lib_IntVector_Intrinsics_vec128 *x = m_st + (uint32_t)0U * (uint32_t)1U;
          Lib_IntVector_Intrinsics_vec128 *y = m_st + (uint32_t)1U * (uint32_t)1U;
          Lib_IntVector_Intrinsics_vec128 *z = m_st + (uint32_t)2U * (uint32_t)1U;
          Lib_IntVector_Intrinsics_vec128 *w = m_st + (uint32_t)3U * (uint32_t)1U;
          uint32_t a = (uint32_t)0U;
          uint32_t b10 = (uint32_t)1U;
          uint32_t c0 = (uint32_t)2U;
          uint32_t d0 = (uint32_t)3U;
          uint32_t r01 = Hacl_Impl_Blake2_Constants_rTable_S[0U];
          uint32_t r11 = Hacl_Impl_Blake2_Constants_rTable_S[1U];
          uint32_t r21 = Hacl_Impl_Blake2_Constants_rTable_S[2U];
          uint32_t r31 = Hacl_Impl_Blake2_Constants_rTable_S[3U];
          Lib_IntVector_Intrinsics_vec128 *wv_a0 = block_state1.fst + a * (uint32_t)1U;
          Lib_IntVector_Intrinsics_vec128 *wv_b0 = block_state1.fst + b10 * (uint32_t)1U;
          wv_a0[0U] = Lib_IntVector_Intrinsics_vec128_add32(wv_a0[0U], wv_b0[0U]);
          wv_a0[0U] = Lib_IntVector_Intrinsics_vec128_add32(wv_a0[0U], x[0U]);
          Lib_IntVector_Intrinsics_vec128 *wv_a1 = block_state1.fst + d0 * (uint32_t)1U;
          Lib_IntVector_Intrinsics_vec128 *wv_b1 = block_state1.fst + a * (uint32_t)1U;
          wv_a1[0U] = Lib_IntVector_Intrinsics_vec128_xor(wv_a1[0U], wv_b1[0U]);
          wv_a1[0U] = Lib_IntVector_Intrinsics_vec128_rotate_right32(wv_a1[0U], r01);
          Lib_IntVector_Intrinsics_vec128 *wv_a2 = block_state1.fst + c0 * (uint32_t)1U;
          Lib_IntVector_Intrinsics_vec128 *wv_b2 = block_state1.fst + d0 * (uint32_t)1U;
          wv_a2[0U] = Lib_IntVector_Intrinsics_vec128_add32(wv_a2[0U], wv_b2[0U]);
          Lib_IntVector_Intrinsics_vec128 *wv_a3 = block_state1.fst + b10 * (uint32_t)1U;
          Lib_IntVector_Intrinsics_vec128 *wv_b3 = block_state1.fst + c0 * (uint32_t)1U;
          wv_a3[0U] = Lib_IntVector_Intrinsics_vec128_xor(wv_a3[0U], wv_b3[0U]);
          wv_a3[0U] = Lib_IntVector_Intrinsics_vec128_rotate_right32(wv_a3[0U], r11);
          Lib_IntVector_Intrinsics_vec128 *wv_a4 = block_state1.fst + a * (uint32_t)1U;
          Lib_IntVector_Intrinsics_vec128 *wv_b4 = block_state1.fst + b10 * (uint32_t)1U;
          wv_a4[0U] = Lib_IntVector_Intrinsics_vec128_add32(wv_a4[0U], wv_b4[0U]);
          wv_a4[0U] = Lib_IntVector_Intrinsics_vec128_add32(wv_a4[0U], y[0U]);
          Lib_IntVector_Intrinsics_vec128 *wv_a5 = block_state1.fst + d0 * (uint32_t)1U;
          Lib_IntVector_Intrinsics_vec128 *wv_b5 = block_state1.fst + a * (uint32_t)1U;
          wv_a5[0U] = Lib_IntVector_Intrinsics_vec128_xor(wv_a5[0U], wv_b5[0U]);
          wv_a5[0U] = Lib_IntVector_Intrinsics_vec128_rotate_right32(wv_a5[0U], r21);
          Lib_IntVector_Intrinsics_vec128 *wv_a6 = block_state1.fst + c0 * (uint32_t)1U;
          Lib_IntVector_Intrinsics_vec128 *wv_b6 = block_state1.fst + d0 * (uint32_t)1U;
          wv_a6[0U] = Lib_IntVector_Intrinsics_vec128_add32(wv_a6[0U], wv_b6[0U]);
          Lib_IntVector_Intrinsics_vec128 *wv_a7 = block_state1.fst + b10 * (uint32_t)1U;
          Lib_IntVector_Intrinsics_vec128 *wv_b7 = block_state1.fst + c0 * (uint32_t)1U;
          wv_a7[0U] = Lib_IntVector_Intrinsics_vec128_xor(wv_a7[0U], wv_b7[0U]);
          wv_a7[0U] = Lib_IntVector_Intrinsics_vec128_rotate_right32(wv_a7[0U], r31);
          Lib_IntVector_Intrinsics_vec128 *r12 = block_state1.fst + (uint32_t)1U * (uint32_t)1U;
          Lib_IntVector_Intrinsics_vec128 *r22 = block_state1.fst + (uint32_t)2U * (uint32_t)1U;
          Lib_IntVector_Intrinsics_vec128 *r32 = block_state1.fst + (uint32_t)3U * (uint32_t)1U;
          Lib_IntVector_Intrinsics_vec128 v00 = r12[0U];
          Lib_IntVector_Intrinsics_vec128
          v1 = Lib_IntVector_Intrinsics_vec128_rotate_right_lanes32(v00, (uint32_t)1U);
          r12[0U] = v1;
          Lib_IntVector_Intrinsics_vec128 v01 = r22[0U];
          Lib_IntVector_Intrinsics_vec128
          v10 = Lib_IntVector_Intrinsics_vec128_rotate_right_lanes32(v01, (uint32_t)2U);
          r22[0U] = v10;
          Lib_IntVector_Intrinsics_vec128 v02 = r32[0U];
          Lib_IntVector_Intrinsics_vec128
          v11 = Lib_IntVector_Intrinsics_vec128_rotate_right_lanes32(v02, (uint32_t)3U);
          r32[0U] = v11;
          uint32_t a0 = (uint32_t)0U;
          uint32_t b1 = (uint32_t)1U;
          uint32_t c = (uint32_t)2U;
          uint32_t d = (uint32_t)3U;
          uint32_t r0 = Hacl_Impl_Blake2_Constants_rTable_S[0U];
          uint32_t r1 = Hacl_Impl_Blake2_Constants_rTable_S[1U];
          uint32_t r23 = Hacl_Impl_Blake2_Constants_rTable_S[2U];
          uint32_t r33 = Hacl_Impl_Blake2_Constants_rTable_S[3U];
          Lib_IntVector_Intrinsics_vec128 *wv_a = block_state1.fst + a0 * (uint32_t)1U;
          Lib_IntVector_Intrinsics_vec128 *wv_b8 = block_state1.fst + b1 * (uint32_t)1U;
          wv_a[0U] = Lib_IntVector_Intrinsics_vec128_add32(wv_a[0U], wv_b8[0U]);
          wv_a[0U] = Lib_IntVector_Intrinsics_vec128_add32(wv_a[0U], z[0U]);
          Lib_IntVector_Intrinsics_vec128 *wv_a8 = block_state1.fst + d * (uint32_t)1U;
          Lib_IntVector_Intrinsics_vec128 *wv_b9 = block_state1.fst + a0 * (uint32_t)1U;
          wv_a8[0U] = Lib_IntVector_Intrinsics_vec128_xor(wv_a8[0U], wv_b9[0U]);
          wv_a8[0U] = Lib_IntVector_Intrinsics_vec128_rotate_right32(wv_a8[0U], r0);
          Lib_IntVector_Intrinsics_vec128 *wv_a9 = block_state1.fst + c * (uint32_t)1U;
          Lib_IntVector_Intrinsics_vec128 *wv_b10 = block_state1.fst + d * (uint32_t)1U;
          wv_a9[0U] = Lib_IntVector_Intrinsics_vec128_add32(wv_a9[0U], wv_b10[0U]);
          Lib_IntVector_Intrinsics_vec128 *wv_a10 = block_state1.fst + b1 * (uint32_t)1U;
          Lib_IntVector_Intrinsics_vec128 *wv_b11 = block_state1.fst + c * (uint32_t)1U;
          wv_a10[0U] = Lib_IntVector_Intrinsics_vec128_xor(wv_a10[0U], wv_b11[0U]);
          wv_a10[0U] = Lib_IntVector_Intrinsics_vec128_rotate_right32(wv_a10[0U], r1);
          Lib_IntVector_Intrinsics_vec128 *wv_a11 = block_state1.fst + a0 * (uint32_t)1U;
          Lib_IntVector_Intrinsics_vec128 *wv_b12 = block_state1.fst + b1 * (uint32_t)1U;
          wv_a11[0U] = Lib_IntVector_Intrinsics_vec128_add32(wv_a11[0U], wv_b12[0U]);
          wv_a11[0U] = Lib_IntVector_Intrinsics_vec128_add32(wv_a11[0U], w[0U]);
          Lib_IntVector_Intrinsics_vec128 *wv_a12 = block_state1.fst + d * (uint32_t)1U;
          Lib_IntVector_Intrinsics_vec128 *wv_b13 = block_state1.fst + a0 * (uint32_t)1U;
          wv_a12[0U] = Lib_IntVector_Intrinsics_vec128_xor(wv_a12[0U], wv_b13[0U]);
          wv_a12[0U] = Lib_IntVector_Intrinsics_vec128_rotate_right32(wv_a12[0U], r23);
          Lib_IntVector_Intrinsics_vec128 *wv_a13 = block_state1.fst + c * (uint32_t)1U;
          Lib_IntVector_Intrinsics_vec128 *wv_b14 = block_state1.fst + d * (uint32_t)1U;
          wv_a13[0U] = Lib_IntVector_Intrinsics_vec128_add32(wv_a13[0U], wv_b14[0U]);
          Lib_IntVector_Intrinsics_vec128 *wv_a14 = block_state1.fst + b1 * (uint32_t)1U;
          Lib_IntVector_Intrinsics_vec128 *wv_b = block_state1.fst + c * (uint32_t)1U;
          wv_a14[0U] = Lib_IntVector_Intrinsics_vec128_xor(wv_a14[0U], wv_b[0U]);
          wv_a14[0U] = Lib_IntVector_Intrinsics_vec128_rotate_right32(wv_a14[0U], r33);
          Lib_IntVector_Intrinsics_vec128 *r13 = block_state1.fst + (uint32_t)1U * (uint32_t)1U;
          Lib_IntVector_Intrinsics_vec128 *r2 = block_state1.fst + (uint32_t)2U * (uint32_t)1U;
          Lib_IntVector_Intrinsics_vec128 *r3 = block_state1.fst + (uint32_t)3U * (uint32_t)1U;
          Lib_IntVector_Intrinsics_vec128 v0 = r13[0U];
          Lib_IntVector_Intrinsics_vec128
          v12 = Lib_IntVector_Intrinsics_vec128_rotate_right_lanes32(v0, (uint32_t)3U);
          r13[0U] = v12;
          Lib_IntVector_Intrinsics_vec128 v03 = r2[0U];
          Lib_IntVector_Intrinsics_vec128
          v13 = Lib_IntVector_Intrinsics_vec128_rotate_right_lanes32(v03, (uint32_t)2U);
          r2[0U] = v13;
          Lib_IntVector_Intrinsics_vec128 v04 = r3[0U];
          Lib_IntVector_Intrinsics_vec128
          v14 = Lib_IntVector_Intrinsics_vec128_rotate_right_lanes32(v04, (uint32_t)1U);
          r3[0U] = v14;
        }
        Lib_IntVector_Intrinsics_vec128 *s0 = block_state1.snd + (uint32_t)0U * (uint32_t)1U;
        Lib_IntVector_Intrinsics_vec128 *s11 = block_state1.snd + (uint32_t)1U * (uint32_t)1U;
        Lib_IntVector_Intrinsics_vec128 *r0 = block_state1.fst + (uint32_t)0U * (uint32_t)1U;
        Lib_IntVector_Intrinsics_vec128 *r1 = block_state1.fst + (uint32_t)1U * (uint32_t)1U;
        Lib_IntVector_Intrinsics_vec128 *r2 = block_state1.fst + (uint32_t)2U * (uint32_t)1U;
        Lib_IntVector_Intrinsics_vec128 *r3 = block_state1.fst + (uint32_t)3U * (uint32_t)1U;
        s0[0U] = Lib_IntVector_Intrinsics_vec128_xor(s0[0U], r0[0U]);
        s0[0U] = Lib_IntVector_Intrinsics_vec128_xor(s0[0U], r2[0U]);
        s11[0U] = Lib_IntVector_Intrinsics_vec128_xor(s11[0U], r1[0U]);
        s11[0U] = Lib_IntVector_Intrinsics_vec128_xor(s11[0U], r3[0U]);
      }
    }
    uint32_t ite0;
    if ((uint64_t)len % (uint64_t)(uint32_t)64U == (uint64_t)0U && (uint64_t)len > (uint64_t)0U)
    {
      ite0 = (uint32_t)64U;
    }
    else
    {
      ite0 = (uint32_t)((uint64_t)len % (uint64_t)(uint32_t)64U);
    }
    uint32_t n_blocks = (len - ite0) / (uint32_t)64U;
    uint32_t data1_len = n_blocks * (uint32_t)64U;
    uint32_t data2_len = len - data1_len;
    uint8_t *data1 = data;
    uint8_t *data2 = data + data1_len;
    uint32_t nb = data1_len / (uint32_t)64U;
    for (uint32_t i0 = (uint32_t)0U; i0 < nb; i0++)
    {
      uint64_t ite;
      if (key_size == (uint32_t)0U)
      {
        ite = total_len1;
      }
      else
      {
        ite = total_len1 + (uint64_t)(uint32_t)64U;
      }
      uint64_t totlen = ite + (uint64_t)((i0 + (uint32_t)1U) * (uint32_t)64U);
      uint8_t *b = data1 + i0 * (uint32_t)64U;
      uint32_t m_w[16U] = { 0U };
      for (uint32_t i = (uint32_t)0U; i < (uint32_t)16U; i++)
      {
        uint32_t *os = m_w;
        uint8_t *bj = b + i * (uint32_t)4U;
        uint32_t u = load32_le(bj);
        uint32_t r = u;
        uint32_t x = r;
        os[i] = x;
      }
      Lib_IntVector_Intrinsics_vec128 mask = Lib_IntVector_Intrinsics_vec128_zero;
      uint32_t wv_14 = (uint32_t)0U;
      uint32_t wv_15 = (uint32_t)0U;
      mask =
        Lib_IntVector_Intrinsics_vec128_load32s((uint32_t)totlen,
          (uint32_t)(totlen >> (uint32_t)32U),
          wv_14,
          wv_15);
      memcpy(block_state1.fst,
        block_state1.snd,
        (uint32_t)4U * (uint32_t)1U * sizeof (block_state1.snd[0U]));
      Lib_IntVector_Intrinsics_vec128 *wv3 = block_state1.fst + (uint32_t)3U * (uint32_t)1U;
      wv3[0U] = Lib_IntVector_Intrinsics_vec128_xor(wv3[0U], mask);
      for (uint32_t i = (uint32_t)0U; i < (uint32_t)10U; i++)
      {
        uint32_t start_idx = i % (uint32_t)10U * (uint32_t)16U;
        KRML_CHECK_SIZE(sizeof (Lib_IntVector_Intrinsics_vec128), (uint32_t)4U * (uint32_t)1U);
        Lib_IntVector_Intrinsics_vec128 m_st[(uint32_t)4U * (uint32_t)1U];
        for (uint32_t _i = 0U; _i < (uint32_t)4U * (uint32_t)1U; ++_i)
          m_st[_i] = Lib_IntVector_Intrinsics_vec128_zero;
        Lib_IntVector_Intrinsics_vec128 *r00 = m_st + (uint32_t)0U * (uint32_t)1U;
        Lib_IntVector_Intrinsics_vec128 *r10 = m_st + (uint32_t)1U * (uint32_t)1U;
        Lib_IntVector_Intrinsics_vec128 *r20 = m_st + (uint32_t)2U * (uint32_t)1U;
        Lib_IntVector_Intrinsics_vec128 *r30 = m_st + (uint32_t)3U * (uint32_t)1U;
        uint32_t s0 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx];
        uint32_t s11 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)1U];
        uint32_t s21 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)2U];
        uint32_t s3 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)3U];
        uint32_t s4 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)4U];
        uint32_t s5 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)5U];
        uint32_t s6 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)6U];
        uint32_t s7 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)7U];
        uint32_t s8 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)8U];
        uint32_t s9 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)9U];
        uint32_t s10 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)10U];
        uint32_t s111 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)11U];
        uint32_t s12 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)12U];
        uint32_t s13 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)13U];
        uint32_t s14 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)14U];
        uint32_t s15 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)15U];
        r00[0U] = Lib_IntVector_Intrinsics_vec128_load32s(m_w[s0], m_w[s21], m_w[s4], m_w[s6]);
        r10[0U] = Lib_IntVector_Intrinsics_vec128_load32s(m_w[s11], m_w[s3], m_w[s5], m_w[s7]);
        r20[0U] = Lib_IntVector_Intrinsics_vec128_load32s(m_w[s8], m_w[s10], m_w[s12], m_w[s14]);
        r30[0U] = Lib_IntVector_Intrinsics_vec128_load32s(m_w[s9], m_w[s111], m_w[s13], m_w[s15]);
        Lib_IntVector_Intrinsics_vec128 *x = m_st + (uint32_t)0U * (uint32_t)1U;
        Lib_IntVector_Intrinsics_vec128 *y = m_st + (uint32_t)1U * (uint32_t)1U;
        Lib_IntVector_Intrinsics_vec128 *z = m_st + (uint32_t)2U * (uint32_t)1U;
        Lib_IntVector_Intrinsics_vec128 *w = m_st + (uint32_t)3U * (uint32_t)1U;
        uint32_t a = (uint32_t)0U;
        uint32_t b10 = (uint32_t)1U;
        uint32_t c0 = (uint32_t)2U;
        uint32_t d0 = (uint32_t)3U;
        uint32_t r01 = Hacl_Impl_Blake2_Constants_rTable_S[0U];
        uint32_t r11 = Hacl_Impl_Blake2_Constants_rTable_S[1U];
        uint32_t r21 = Hacl_Impl_Blake2_Constants_rTable_S[2U];
        uint32_t r31 = Hacl_Impl_Blake2_Constants_rTable_S[3U];
        Lib_IntVector_Intrinsics_vec128 *wv_a0 = block_state1.fst + a * (uint32_t)1U;
        Lib_IntVector_Intrinsics_vec128 *wv_b0 = block_state1.fst + b10 * (uint32_t)1U;
        wv_a0[0U] = Lib_IntVector_Intrinsics_vec128_add32(wv_a0[0U], wv_b0[0U]);
        wv_a0[0U] = Lib_IntVector_Intrinsics_vec128_add32(wv_a0[0U], x[0U]);
        Lib_IntVector_Intrinsics_vec128 *wv_a1 = block_state1.fst + d0 * (uint32_t)1U;
        Lib_IntVector_Intrinsics_vec128 *wv_b1 = block_state1.fst + a * (uint32_t)1U;
        wv_a1[0U] = Lib_IntVector_Intrinsics_vec128_xor(wv_a1[0U], wv_b1[0U]);
        wv_a1[0U] = Lib_IntVector_Intrinsics_vec128_rotate_right32(wv_a1[0U], r01);
        Lib_IntVector_Intrinsics_vec128 *wv_a2 = block_state1.fst + c0 * (uint32_t)1U;
        Lib_IntVector_Intrinsics_vec128 *wv_b2 = block_state1.fst + d0 * (uint32_t)1U;
        wv_a2[0U] = Lib_IntVector_Intrinsics_vec128_add32(wv_a2[0U], wv_b2[0U]);
        Lib_IntVector_Intrinsics_vec128 *wv_a3 = block_state1.fst + b10 * (uint32_t)1U;
        Lib_IntVector_Intrinsics_vec128 *wv_b3 = block_state1.fst + c0 * (uint32_t)1U;
        wv_a3[0U] = Lib_IntVector_Intrinsics_vec128_xor(wv_a3[0U], wv_b3[0U]);
        wv_a3[0U] = Lib_IntVector_Intrinsics_vec128_rotate_right32(wv_a3[0U], r11);
        Lib_IntVector_Intrinsics_vec128 *wv_a4 = block_state1.fst + a * (uint32_t)1U;
        Lib_IntVector_Intrinsics_vec128 *wv_b4 = block_state1.fst + b10 * (uint32_t)1U;
        wv_a4[0U] = Lib_IntVector_Intrinsics_vec128_add32(wv_a4[0U], wv_b4[0U]);
        wv_a4[0U] = Lib_IntVector_Intrinsics_vec128_add32(wv_a4[0U], y[0U]);
        Lib_IntVector_Intrinsics_vec128 *wv_a5 = block_state1.fst + d0 * (uint32_t)1U;
        Lib_IntVector_Intrinsics_vec128 *wv_b5 = block_state1.fst + a * (uint32_t)1U;
        wv_a5[0U] = Lib_IntVector_Intrinsics_vec128_xor(wv_a5[0U], wv_b5[0U]);
        wv_a5[0U] = Lib_IntVector_Intrinsics_vec128_rotate_right32(wv_a5[0U], r21);
        Lib_IntVector_Intrinsics_vec128 *wv_a6 = block_state1.fst + c0 * (uint32_t)1U;
        Lib_IntVector_Intrinsics_vec128 *wv_b6 = block_state1.fst + d0 * (uint32_t)1U;
        wv_a6[0U] = Lib_IntVector_Intrinsics_vec128_add32(wv_a6[0U], wv_b6[0U]);
        Lib_IntVector_Intrinsics_vec128 *wv_a7 = block_state1.fst + b10 * (uint32_t)1U;
        Lib_IntVector_Intrinsics_vec128 *wv_b7 = block_state1.fst + c0 * (uint32_t)1U;
        wv_a7[0U] = Lib_IntVector_Intrinsics_vec128_xor(wv_a7[0U], wv_b7[0U]);
        wv_a7[0U] = Lib_IntVector_Intrinsics_vec128_rotate_right32(wv_a7[0U], r31);
        Lib_IntVector_Intrinsics_vec128 *r12 = block_state1.fst + (uint32_t)1U * (uint32_t)1U;
        Lib_IntVector_Intrinsics_vec128 *r22 = block_state1.fst + (uint32_t)2U * (uint32_t)1U;
        Lib_IntVector_Intrinsics_vec128 *r32 = block_state1.fst + (uint32_t)3U * (uint32_t)1U;
        Lib_IntVector_Intrinsics_vec128 v00 = r12[0U];
        Lib_IntVector_Intrinsics_vec128
        v1 = Lib_IntVector_Intrinsics_vec128_rotate_right_lanes32(v00, (uint32_t)1U);
        r12[0U] = v1;
        Lib_IntVector_Intrinsics_vec128 v01 = r22[0U];
        Lib_IntVector_Intrinsics_vec128
        v10 = Lib_IntVector_Intrinsics_vec128_rotate_right_lanes32(v01, (uint32_t)2U);
        r22[0U] = v10;
        Lib_IntVector_Intrinsics_vec128 v02 = r32[0U];
        Lib_IntVector_Intrinsics_vec128
        v11 = Lib_IntVector_Intrinsics_vec128_rotate_right_lanes32(v02, (uint32_t)3U);
        r32[0U] = v11;
        uint32_t a0 = (uint32_t)0U;
        uint32_t b1 = (uint32_t)1U;
        uint32_t c = (uint32_t)2U;
        uint32_t d = (uint32_t)3U;
        uint32_t r0 = Hacl_Impl_Blake2_Constants_rTable_S[0U];
        uint32_t r1 = Hacl_Impl_Blake2_Constants_rTable_S[1U];
        uint32_t r23 = Hacl_Impl_Blake2_Constants_rTable_S[2U];
        uint32_t r33 = Hacl_Impl_Blake2_Constants_rTable_S[3U];
        Lib_IntVector_Intrinsics_vec128 *wv_a = block_state1.fst + a0 * (uint32_t)1U;
        Lib_IntVector_Intrinsics_vec128 *wv_b8 = block_state1.fst + b1 * (uint32_t)1U;
        wv_a[0U] = Lib_IntVector_Intrinsics_vec128_add32(wv_a[0U], wv_b8[0U]);
        wv_a[0U] = Lib_IntVector_Intrinsics_vec128_add32(wv_a[0U], z[0U]);
        Lib_IntVector_Intrinsics_vec128 *wv_a8 = block_state1.fst + d * (uint32_t)1U;
        Lib_IntVector_Intrinsics_vec128 *wv_b9 = block_state1.fst + a0 * (uint32_t)1U;
        wv_a8[0U] = Lib_IntVector_Intrinsics_vec128_xor(wv_a8[0U], wv_b9[0U]);
        wv_a8[0U] = Lib_IntVector_Intrinsics_vec128_rotate_right32(wv_a8[0U], r0);
        Lib_IntVector_Intrinsics_vec128 *wv_a9 = block_state1.fst + c * (uint32_t)1U;
        Lib_IntVector_Intrinsics_vec128 *wv_b10 = block_state1.fst + d * (uint32_t)1U;
        wv_a9[0U] = Lib_IntVector_Intrinsics_vec128_add32(wv_a9[0U], wv_b10[0U]);
        Lib_IntVector_Intrinsics_vec128 *wv_a10 = block_state1.fst + b1 * (uint32_t)1U;
        Lib_IntVector_Intrinsics_vec128 *wv_b11 = block_state1.fst + c * (uint32_t)1U;
        wv_a10[0U] = Lib_IntVector_Intrinsics_vec128_xor(wv_a10[0U], wv_b11[0U]);
        wv_a10[0U] = Lib_IntVector_Intrinsics_vec128_rotate_right32(wv_a10[0U], r1);
        Lib_IntVector_Intrinsics_vec128 *wv_a11 = block_state1.fst + a0 * (uint32_t)1U;
        Lib_IntVector_Intrinsics_vec128 *wv_b12 = block_state1.fst + b1 * (uint32_t)1U;
        wv_a11[0U] = Lib_IntVector_Intrinsics_vec128_add32(wv_a11[0U], wv_b12[0U]);
        wv_a11[0U] = Lib_IntVector_Intrinsics_vec128_add32(wv_a11[0U], w[0U]);
        Lib_IntVector_Intrinsics_vec128 *wv_a12 = block_state1.fst + d * (uint32_t)1U;
        Lib_IntVector_Intrinsics_vec128 *wv_b13 = block_state1.fst + a0 * (uint32_t)1U;
        wv_a12[0U] = Lib_IntVector_Intrinsics_vec128_xor(wv_a12[0U], wv_b13[0U]);
        wv_a12[0U] = Lib_IntVector_Intrinsics_vec128_rotate_right32(wv_a12[0U], r23);
        Lib_IntVector_Intrinsics_vec128 *wv_a13 = block_state1.fst + c * (uint32_t)1U;
        Lib_IntVector_Intrinsics_vec128 *wv_b14 = block_state1.fst + d * (uint32_t)1U;
        wv_a13[0U] = Lib_IntVector_Intrinsics_vec128_add32(wv_a13[0U], wv_b14[0U]);
        Lib_IntVector_Intrinsics_vec128 *wv_a14 = block_state1.fst + b1 * (uint32_t)1U;
        Lib_IntVector_Intrinsics_vec128 *wv_b = block_state1.fst + c * (uint32_t)1U;
        wv_a14[0U] = Lib_IntVector_Intrinsics_vec128_xor(wv_a14[0U], wv_b[0U]);
        wv_a14[0U] = Lib_IntVector_Intrinsics_vec128_rotate_right32(wv_a14[0U], r33);
        Lib_IntVector_Intrinsics_vec128 *r13 = block_state1.fst + (uint32_t)1U * (uint32_t)1U;
        Lib_IntVector_Intrinsics_vec128 *r2 = block_state1.fst + (uint32_t)2U * (uint32_t)1U;
        Lib_IntVector_Intrinsics_vec128 *r3 = block_state1.fst + (uint32_t)3U * (uint32_t)1U;
        Lib_IntVector_Intrinsics_vec128 v0 = r13[0U];
        Lib_IntVector_Intrinsics_vec128
        v12 = Lib_IntVector_Intrinsics_vec128_rotate_right_lanes32(v0, (uint32_t)3U);
        r13[0U] = v12;
        Lib_IntVector_Intrinsics_vec128 v03 = r2[0U];
        Lib_IntVector_Intrinsics_vec128
        v13 = Lib_IntVector_Intrinsics_vec128_rotate_right_lanes32(v03, (uint32_t)2U);
        r2[0U] = v13;
        Lib_IntVector_Intrinsics_vec128 v04 = r3[0U];
        Lib_IntVector_Intrinsics_vec128
        v14 = Lib_IntVector_Intrinsics_vec128_rotate_right_lanes32(v04, (uint32_t)1U);
        r3[0U] = v14;
      }
      Lib_IntVector_Intrinsics_vec128 *s0 = block_state1.snd + (uint32_t)0U * (uint32_t)1U;
      Lib_IntVector_Intrinsics_vec128 *s11 = block_state1.snd + (uint32_t)1U * (uint32_t)1U;
      Lib_IntVector_Intrinsics_vec128 *r0 = block_state1.fst + (uint32_t)0U * (uint32_t)1U;
      Lib_IntVector_Intrinsics_vec128 *r1 = block_state1.fst + (uint32_t)1U * (uint32_t)1U;
      Lib_IntVector_Intrinsics_vec128 *r2 = block_state1.fst + (uint32_t)2U * (uint32_t)1U;
      Lib_IntVector_Intrinsics_vec128 *r3 = block_state1.fst + (uint32_t)3U * (uint32_t)1U;
      s0[0U] = Lib_IntVector_Intrinsics_vec128_xor(s0[0U], r0[0U]);
      s0[0U] = Lib_IntVector_Intrinsics_vec128_xor(s0[0U], r2[0U]);
      s11[0U] = Lib_IntVector_Intrinsics_vec128_xor(s11[0U], r1[0U]);
      s11[0U] = Lib_IntVector_Intrinsics_vec128_xor(s11[0U], r3[0U]);
    }
    uint8_t *dst = buf;
    memcpy(dst, data2, data2_len * sizeof (data2[0U]));
    *p
    =
      (
        (Hacl_Streaming_Functor_state_s__K____Lib_IntVector_Intrinsics_vec128___Lib_IntVector_Intrinsics_vec128____){
          .block_state = block_state1,
          .buf = buf,
          .total_len = total_len1 + (uint64_t)len
        }
      );
    return;
  }
  uint32_t diff = (uint32_t)64U - sz;
  uint8_t *data1 = data;
  uint8_t *data2 = data + diff;
  Hacl_Streaming_Functor_state_s__K____Lib_IntVector_Intrinsics_vec128___Lib_IntVector_Intrinsics_vec128____
  s2 = *p;
  K____Lib_IntVector_Intrinsics_vec128___Lib_IntVector_Intrinsics_vec128_
  block_state10 = s2.block_state;
  uint8_t *buf0 = s2.buf;
  uint64_t total_len10 = s2.total_len;
  uint32_t sz10;
  if (total_len10 % (uint64_t)(uint32_t)64U == (uint64_t)0U && total_len10 > (uint64_t)0U)
  {
    sz10 = (uint32_t)64U;
  }
  else
  {
    sz10 = (uint32_t)(total_len10 % (uint64_t)(uint32_t)64U);
  }
  uint8_t *buf2 = buf0 + sz10;
  memcpy(buf2, data1, diff * sizeof (data1[0U]));
  uint64_t total_len2 = total_len10 + (uint64_t)diff;
  *p
  =
    (
      (Hacl_Streaming_Functor_state_s__K____Lib_IntVector_Intrinsics_vec128___Lib_IntVector_Intrinsics_vec128____){
        .block_state = block_state10,
        .buf = buf0,
        .total_len = total_len2
      }
    );
  Hacl_Streaming_Functor_state_s__K____Lib_IntVector_Intrinsics_vec128___Lib_IntVector_Intrinsics_vec128____
  s20 = *p;
  K____Lib_IntVector_Intrinsics_vec128___Lib_IntVector_Intrinsics_vec128_
  block_state1 = s20.block_state;
  uint8_t *buf = s20.buf;
  uint64_t total_len1 = s20.total_len;
  uint32_t sz1;
  if (total_len1 % (uint64_t)(uint32_t)64U == (uint64_t)0U && total_len1 > (uint64_t)0U)
  {
    sz1 = (uint32_t)64U;
  }
  else
  {
    sz1 = (uint32_t)(total_len1 % (uint64_t)(uint32_t)64U);
  }
  if (!(sz1 == (uint32_t)0U))
  {
    uint64_t prevlen = total_len1 - (uint64_t)sz1;
    uint32_t nb = (uint32_t)1U;
    for (uint32_t i0 = (uint32_t)0U; i0 < nb; i0++)
    {
      uint64_t ite;
      if (key_size == (uint32_t)0U)
      {
        ite = prevlen;
      }
      else
      {
        ite = prevlen + (uint64_t)(uint32_t)64U;
      }
      uint64_t totlen = ite + (uint64_t)((i0 + (uint32_t)1U) * (uint32_t)64U);
      uint8_t *b = buf + i0 * (uint32_t)64U;
      uint32_t m_w[16U] = { 0U };
      for (uint32_t i = (uint32_t)0U; i < (uint32_t)16U; i++)
      {
        uint32_t *os = m_w;
        uint8_t *bj = b + i * (uint32_t)4U;
        uint32_t u = load32_le(bj);
        uint32_t r = u;
        uint32_t x = r;
        os[i] = x;
      }
      Lib_IntVector_Intrinsics_vec128 mask = Lib_IntVector_Intrinsics_vec128_zero;
      uint32_t wv_14 = (uint32_t)0U;
      uint32_t wv_15 = (uint32_t)0U;
      mask =
        Lib_IntVector_Intrinsics_vec128_load32s((uint32_t)totlen,
          (uint32_t)(totlen >> (uint32_t)32U),
          wv_14,
          wv_15);
      memcpy(block_state1.fst,
        block_state1.snd,
        (uint32_t)4U * (uint32_t)1U * sizeof (block_state1.snd[0U]));
      Lib_IntVector_Intrinsics_vec128 *wv3 = block_state1.fst + (uint32_t)3U * (uint32_t)1U;
      wv3[0U] = Lib_IntVector_Intrinsics_vec128_xor(wv3[0U], mask);
      for (uint32_t i = (uint32_t)0U; i < (uint32_t)10U; i++)
      {
        uint32_t start_idx = i % (uint32_t)10U * (uint32_t)16U;
        KRML_CHECK_SIZE(sizeof (Lib_IntVector_Intrinsics_vec128), (uint32_t)4U * (uint32_t)1U);
        Lib_IntVector_Intrinsics_vec128 m_st[(uint32_t)4U * (uint32_t)1U];
        for (uint32_t _i = 0U; _i < (uint32_t)4U * (uint32_t)1U; ++_i)
          m_st[_i] = Lib_IntVector_Intrinsics_vec128_zero;
        Lib_IntVector_Intrinsics_vec128 *r00 = m_st + (uint32_t)0U * (uint32_t)1U;
        Lib_IntVector_Intrinsics_vec128 *r10 = m_st + (uint32_t)1U * (uint32_t)1U;
        Lib_IntVector_Intrinsics_vec128 *r20 = m_st + (uint32_t)2U * (uint32_t)1U;
        Lib_IntVector_Intrinsics_vec128 *r30 = m_st + (uint32_t)3U * (uint32_t)1U;
        uint32_t s0 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx];
        uint32_t s11 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)1U];
        uint32_t s21 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)2U];
        uint32_t s3 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)3U];
        uint32_t s4 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)4U];
        uint32_t s5 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)5U];
        uint32_t s6 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)6U];
        uint32_t s7 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)7U];
        uint32_t s8 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)8U];
        uint32_t s9 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)9U];
        uint32_t s10 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)10U];
        uint32_t s111 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)11U];
        uint32_t s12 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)12U];
        uint32_t s13 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)13U];
        uint32_t s14 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)14U];
        uint32_t s15 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)15U];
        r00[0U] = Lib_IntVector_Intrinsics_vec128_load32s(m_w[s0], m_w[s21], m_w[s4], m_w[s6]);
        r10[0U] = Lib_IntVector_Intrinsics_vec128_load32s(m_w[s11], m_w[s3], m_w[s5], m_w[s7]);
        r20[0U] = Lib_IntVector_Intrinsics_vec128_load32s(m_w[s8], m_w[s10], m_w[s12], m_w[s14]);
        r30[0U] = Lib_IntVector_Intrinsics_vec128_load32s(m_w[s9], m_w[s111], m_w[s13], m_w[s15]);
        Lib_IntVector_Intrinsics_vec128 *x = m_st + (uint32_t)0U * (uint32_t)1U;
        Lib_IntVector_Intrinsics_vec128 *y = m_st + (uint32_t)1U * (uint32_t)1U;
        Lib_IntVector_Intrinsics_vec128 *z = m_st + (uint32_t)2U * (uint32_t)1U;
        Lib_IntVector_Intrinsics_vec128 *w = m_st + (uint32_t)3U * (uint32_t)1U;
        uint32_t a = (uint32_t)0U;
        uint32_t b10 = (uint32_t)1U;
        uint32_t c0 = (uint32_t)2U;
        uint32_t d0 = (uint32_t)3U;
        uint32_t r01 = Hacl_Impl_Blake2_Constants_rTable_S[0U];
        uint32_t r11 = Hacl_Impl_Blake2_Constants_rTable_S[1U];
        uint32_t r21 = Hacl_Impl_Blake2_Constants_rTable_S[2U];
        uint32_t r31 = Hacl_Impl_Blake2_Constants_rTable_S[3U];
        Lib_IntVector_Intrinsics_vec128 *wv_a0 = block_state1.fst + a * (uint32_t)1U;
        Lib_IntVector_Intrinsics_vec128 *wv_b0 = block_state1.fst + b10 * (uint32_t)1U;
        wv_a0[0U] = Lib_IntVector_Intrinsics_vec128_add32(wv_a0[0U], wv_b0[0U]);
        wv_a0[0U] = Lib_IntVector_Intrinsics_vec128_add32(wv_a0[0U], x[0U]);
        Lib_IntVector_Intrinsics_vec128 *wv_a1 = block_state1.fst + d0 * (uint32_t)1U;
        Lib_IntVector_Intrinsics_vec128 *wv_b1 = block_state1.fst + a * (uint32_t)1U;
        wv_a1[0U] = Lib_IntVector_Intrinsics_vec128_xor(wv_a1[0U], wv_b1[0U]);
        wv_a1[0U] = Lib_IntVector_Intrinsics_vec128_rotate_right32(wv_a1[0U], r01);
        Lib_IntVector_Intrinsics_vec128 *wv_a2 = block_state1.fst + c0 * (uint32_t)1U;
        Lib_IntVector_Intrinsics_vec128 *wv_b2 = block_state1.fst + d0 * (uint32_t)1U;
        wv_a2[0U] = Lib_IntVector_Intrinsics_vec128_add32(wv_a2[0U], wv_b2[0U]);
        Lib_IntVector_Intrinsics_vec128 *wv_a3 = block_state1.fst + b10 * (uint32_t)1U;
        Lib_IntVector_Intrinsics_vec128 *wv_b3 = block_state1.fst + c0 * (uint32_t)1U;
        wv_a3[0U] = Lib_IntVector_Intrinsics_vec128_xor(wv_a3[0U], wv_b3[0U]);
        wv_a3[0U] = Lib_IntVector_Intrinsics_vec128_rotate_right32(wv_a3[0U], r11);
        Lib_IntVector_Intrinsics_vec128 *wv_a4 = block_state1.fst + a * (uint32_t)1U;
        Lib_IntVector_Intrinsics_vec128 *wv_b4 = block_state1.fst + b10 * (uint32_t)1U;
        wv_a4[0U] = Lib_IntVector_Intrinsics_vec128_add32(wv_a4[0U], wv_b4[0U]);
        wv_a4[0U] = Lib_IntVector_Intrinsics_vec128_add32(wv_a4[0U], y[0U]);
        Lib_IntVector_Intrinsics_vec128 *wv_a5 = block_state1.fst + d0 * (uint32_t)1U;
        Lib_IntVector_Intrinsics_vec128 *wv_b5 = block_state1.fst + a * (uint32_t)1U;
        wv_a5[0U] = Lib_IntVector_Intrinsics_vec128_xor(wv_a5[0U], wv_b5[0U]);
        wv_a5[0U] = Lib_IntVector_Intrinsics_vec128_rotate_right32(wv_a5[0U], r21);
        Lib_IntVector_Intrinsics_vec128 *wv_a6 = block_state1.fst + c0 * (uint32_t)1U;
        Lib_IntVector_Intrinsics_vec128 *wv_b6 = block_state1.fst + d0 * (uint32_t)1U;
        wv_a6[0U] = Lib_IntVector_Intrinsics_vec128_add32(wv_a6[0U], wv_b6[0U]);
        Lib_IntVector_Intrinsics_vec128 *wv_a7 = block_state1.fst + b10 * (uint32_t)1U;
        Lib_IntVector_Intrinsics_vec128 *wv_b7 = block_state1.fst + c0 * (uint32_t)1U;
        wv_a7[0U] = Lib_IntVector_Intrinsics_vec128_xor(wv_a7[0U], wv_b7[0U]);
        wv_a7[0U] = Lib_IntVector_Intrinsics_vec128_rotate_right32(wv_a7[0U], r31);
        Lib_IntVector_Intrinsics_vec128 *r12 = block_state1.fst + (uint32_t)1U * (uint32_t)1U;
        Lib_IntVector_Intrinsics_vec128 *r22 = block_state1.fst + (uint32_t)2U * (uint32_t)1U;
        Lib_IntVector_Intrinsics_vec128 *r32 = block_state1.fst + (uint32_t)3U * (uint32_t)1U;
        Lib_IntVector_Intrinsics_vec128 v00 = r12[0U];
        Lib_IntVector_Intrinsics_vec128
        v1 = Lib_IntVector_Intrinsics_vec128_rotate_right_lanes32(v00, (uint32_t)1U);
        r12[0U] = v1;
        Lib_IntVector_Intrinsics_vec128 v01 = r22[0U];
        Lib_IntVector_Intrinsics_vec128
        v10 = Lib_IntVector_Intrinsics_vec128_rotate_right_lanes32(v01, (uint32_t)2U);
        r22[0U] = v10;
        Lib_IntVector_Intrinsics_vec128 v02 = r32[0U];
        Lib_IntVector_Intrinsics_vec128
        v11 = Lib_IntVector_Intrinsics_vec128_rotate_right_lanes32(v02, (uint32_t)3U);
        r32[0U] = v11;
        uint32_t a0 = (uint32_t)0U;
        uint32_t b1 = (uint32_t)1U;
        uint32_t c = (uint32_t)2U;
        uint32_t d = (uint32_t)3U;
        uint32_t r0 = Hacl_Impl_Blake2_Constants_rTable_S[0U];
        uint32_t r1 = Hacl_Impl_Blake2_Constants_rTable_S[1U];
        uint32_t r23 = Hacl_Impl_Blake2_Constants_rTable_S[2U];
        uint32_t r33 = Hacl_Impl_Blake2_Constants_rTable_S[3U];
        Lib_IntVector_Intrinsics_vec128 *wv_a = block_state1.fst + a0 * (uint32_t)1U;
        Lib_IntVector_Intrinsics_vec128 *wv_b8 = block_state1.fst + b1 * (uint32_t)1U;
        wv_a[0U] = Lib_IntVector_Intrinsics_vec128_add32(wv_a[0U], wv_b8[0U]);
        wv_a[0U] = Lib_IntVector_Intrinsics_vec128_add32(wv_a[0U], z[0U]);
        Lib_IntVector_Intrinsics_vec128 *wv_a8 = block_state1.fst + d * (uint32_t)1U;
        Lib_IntVector_Intrinsics_vec128 *wv_b9 = block_state1.fst + a0 * (uint32_t)1U;
        wv_a8[0U] = Lib_IntVector_Intrinsics_vec128_xor(wv_a8[0U], wv_b9[0U]);
        wv_a8[0U] = Lib_IntVector_Intrinsics_vec128_rotate_right32(wv_a8[0U], r0);
        Lib_IntVector_Intrinsics_vec128 *wv_a9 = block_state1.fst + c * (uint32_t)1U;
        Lib_IntVector_Intrinsics_vec128 *wv_b10 = block_state1.fst + d * (uint32_t)1U;
        wv_a9[0U] = Lib_IntVector_Intrinsics_vec128_add32(wv_a9[0U], wv_b10[0U]);
        Lib_IntVector_Intrinsics_vec128 *wv_a10 = block_state1.fst + b1 * (uint32_t)1U;
        Lib_IntVector_Intrinsics_vec128 *wv_b11 = block_state1.fst + c * (uint32_t)1U;
        wv_a10[0U] = Lib_IntVector_Intrinsics_vec128_xor(wv_a10[0U], wv_b11[0U]);
        wv_a10[0U] = Lib_IntVector_Intrinsics_vec128_rotate_right32(wv_a10[0U], r1);
        Lib_IntVector_Intrinsics_vec128 *wv_a11 = block_state1.fst + a0 * (uint32_t)1U;
        Lib_IntVector_Intrinsics_vec128 *wv_b12 = block_state1.fst + b1 * (uint32_t)1U;
        wv_a11[0U] = Lib_IntVector_Intrinsics_vec128_add32(wv_a11[0U], wv_b12[0U]);
        wv_a11[0U] = Lib_IntVector_Intrinsics_vec128_add32(wv_a11[0U], w[0U]);
        Lib_IntVector_Intrinsics_vec128 *wv_a12 = block_state1.fst + d * (uint32_t)1U;
        Lib_IntVector_Intrinsics_vec128 *wv_b13 = block_state1.fst + a0 * (uint32_t)1U;
        wv_a12[0U] = Lib_IntVector_Intrinsics_vec128_xor(wv_a12[0U], wv_b13[0U]);
        wv_a12[0U] = Lib_IntVector_Intrinsics_vec128_rotate_right32(wv_a12[0U], r23);
        Lib_IntVector_Intrinsics_vec128 *wv_a13 = block_state1.fst + c * (uint32_t)1U;
        Lib_IntVector_Intrinsics_vec128 *wv_b14 = block_state1.fst + d * (uint32_t)1U;
        wv_a13[0U] = Lib_IntVector_Intrinsics_vec128_add32(wv_a13[0U], wv_b14[0U]);
        Lib_IntVector_Intrinsics_vec128 *wv_a14 = block_state1.fst + b1 * (uint32_t)1U;
        Lib_IntVector_Intrinsics_vec128 *wv_b = block_state1.fst + c * (uint32_t)1U;
        wv_a14[0U] = Lib_IntVector_Intrinsics_vec128_xor(wv_a14[0U], wv_b[0U]);
        wv_a14[0U] = Lib_IntVector_Intrinsics_vec128_rotate_right32(wv_a14[0U], r33);
        Lib_IntVector_Intrinsics_vec128 *r13 = block_state1.fst + (uint32_t)1U * (uint32_t)1U;
        Lib_IntVector_Intrinsics_vec128 *r2 = block_state1.fst + (uint32_t)2U * (uint32_t)1U;
        Lib_IntVector_Intrinsics_vec128 *r3 = block_state1.fst + (uint32_t)3U * (uint32_t)1U;
        Lib_IntVector_Intrinsics_vec128 v0 = r13[0U];
        Lib_IntVector_Intrinsics_vec128
        v12 = Lib_IntVector_Intrinsics_vec128_rotate_right_lanes32(v0, (uint32_t)3U);
        r13[0U] = v12;
        Lib_IntVector_Intrinsics_vec128 v03 = r2[0U];
        Lib_IntVector_Intrinsics_vec128
        v13 = Lib_IntVector_Intrinsics_vec128_rotate_right_lanes32(v03, (uint32_t)2U);
        r2[0U] = v13;
        Lib_IntVector_Intrinsics_vec128 v04 = r3[0U];
        Lib_IntVector_Intrinsics_vec128
        v14 = Lib_IntVector_Intrinsics_vec128_rotate_right_lanes32(v04, (uint32_t)1U);
        r3[0U] = v14;
      }
      Lib_IntVector_Intrinsics_vec128 *s0 = block_state1.snd + (uint32_t)0U * (uint32_t)1U;
      Lib_IntVector_Intrinsics_vec128 *s11 = block_state1.snd + (uint32_t)1U * (uint32_t)1U;
      Lib_IntVector_Intrinsics_vec128 *r0 = block_state1.fst + (uint32_t)0U * (uint32_t)1U;
      Lib_IntVector_Intrinsics_vec128 *r1 = block_state1.fst + (uint32_t)1U * (uint32_t)1U;
      Lib_IntVector_Intrinsics_vec128 *r2 = block_state1.fst + (uint32_t)2U * (uint32_t)1U;
      Lib_IntVector_Intrinsics_vec128 *r3 = block_state1.fst + (uint32_t)3U * (uint32_t)1U;
      s0[0U] = Lib_IntVector_Intrinsics_vec128_xor(s0[0U], r0[0U]);
      s0[0U] = Lib_IntVector_Intrinsics_vec128_xor(s0[0U], r2[0U]);
      s11[0U] = Lib_IntVector_Intrinsics_vec128_xor(s11[0U], r1[0U]);
      s11[0U] = Lib_IntVector_Intrinsics_vec128_xor(s11[0U], r3[0U]);
    }
  }
  uint32_t ite0;
  if
  (
    (uint64_t)(len - diff)
    % (uint64_t)(uint32_t)64U
    == (uint64_t)0U
    && (uint64_t)(len - diff) > (uint64_t)0U
  )
  {
    ite0 = (uint32_t)64U;
  }
  else
  {
    ite0 = (uint32_t)((uint64_t)(len - diff) % (uint64_t)(uint32_t)64U);
  }
  uint32_t n_blocks = (len - diff - ite0) / (uint32_t)64U;
  uint32_t data1_len = n_blocks * (uint32_t)64U;
  uint32_t data2_len = len - diff - data1_len;
  uint8_t *data11 = data2;
  uint8_t *data21 = data2 + data1_len;
  uint32_t nb = data1_len / (uint32_t)64U;
  for (uint32_t i0 = (uint32_t)0U; i0 < nb; i0++)
  {
    uint64_t ite;
    if (key_size == (uint32_t)0U)
    {
      ite = total_len1;
    }
    else
    {
      ite = total_len1 + (uint64_t)(uint32_t)64U;
    }
    uint64_t totlen = ite + (uint64_t)((i0 + (uint32_t)1U) * (uint32_t)64U);
    uint8_t *b = data11 + i0 * (uint32_t)64U;
    uint32_t m_w[16U] = { 0U };
    for (uint32_t i = (uint32_t)0U; i < (uint32_t)16U; i++)
    {
      uint32_t *os = m_w;
      uint8_t *bj = b + i * (uint32_t)4U;
      uint32_t u = load32_le(bj);
      uint32_t r = u;
      uint32_t x = r;
      os[i] = x;
    }
    Lib_IntVector_Intrinsics_vec128 mask = Lib_IntVector_Intrinsics_vec128_zero;
    uint32_t wv_14 = (uint32_t)0U;
    uint32_t wv_15 = (uint32_t)0U;
    mask =
      Lib_IntVector_Intrinsics_vec128_load32s((uint32_t)totlen,
        (uint32_t)(totlen >> (uint32_t)32U),
        wv_14,
        wv_15);
    memcpy(block_state1.fst,
      block_state1.snd,
      (uint32_t)4U * (uint32_t)1U * sizeof (block_state1.snd[0U]));
    Lib_IntVector_Intrinsics_vec128 *wv3 = block_state1.fst + (uint32_t)3U * (uint32_t)1U;
    wv3[0U] = Lib_IntVector_Intrinsics_vec128_xor(wv3[0U], mask);
    for (uint32_t i = (uint32_t)0U; i < (uint32_t)10U; i++)
    {
      uint32_t start_idx = i % (uint32_t)10U * (uint32_t)16U;
      KRML_CHECK_SIZE(sizeof (Lib_IntVector_Intrinsics_vec128), (uint32_t)4U * (uint32_t)1U);
      Lib_IntVector_Intrinsics_vec128 m_st[(uint32_t)4U * (uint32_t)1U];
      for (uint32_t _i = 0U; _i < (uint32_t)4U * (uint32_t)1U; ++_i)
        m_st[_i] = Lib_IntVector_Intrinsics_vec128_zero;
      Lib_IntVector_Intrinsics_vec128 *r00 = m_st + (uint32_t)0U * (uint32_t)1U;
      Lib_IntVector_Intrinsics_vec128 *r10 = m_st + (uint32_t)1U * (uint32_t)1U;
      Lib_IntVector_Intrinsics_vec128 *r20 = m_st + (uint32_t)2U * (uint32_t)1U;
      Lib_IntVector_Intrinsics_vec128 *r30 = m_st + (uint32_t)3U * (uint32_t)1U;
      uint32_t s0 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx];
      uint32_t s11 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)1U];
      uint32_t s21 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)2U];
      uint32_t s3 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)3U];
      uint32_t s4 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)4U];
      uint32_t s5 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)5U];
      uint32_t s6 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)6U];
      uint32_t s7 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)7U];
      uint32_t s8 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)8U];
      uint32_t s9 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)9U];
      uint32_t s10 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)10U];
      uint32_t s111 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)11U];
      uint32_t s12 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)12U];
      uint32_t s13 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)13U];
      uint32_t s14 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)14U];
      uint32_t s15 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)15U];
      r00[0U] = Lib_IntVector_Intrinsics_vec128_load32s(m_w[s0], m_w[s21], m_w[s4], m_w[s6]);
      r10[0U] = Lib_IntVector_Intrinsics_vec128_load32s(m_w[s11], m_w[s3], m_w[s5], m_w[s7]);
      r20[0U] = Lib_IntVector_Intrinsics_vec128_load32s(m_w[s8], m_w[s10], m_w[s12], m_w[s14]);
      r30[0U] = Lib_IntVector_Intrinsics_vec128_load32s(m_w[s9], m_w[s111], m_w[s13], m_w[s15]);
      Lib_IntVector_Intrinsics_vec128 *x = m_st + (uint32_t)0U * (uint32_t)1U;
      Lib_IntVector_Intrinsics_vec128 *y = m_st + (uint32_t)1U * (uint32_t)1U;
      Lib_IntVector_Intrinsics_vec128 *z = m_st + (uint32_t)2U * (uint32_t)1U;
      Lib_IntVector_Intrinsics_vec128 *w = m_st + (uint32_t)3U * (uint32_t)1U;
      uint32_t a = (uint32_t)0U;
      uint32_t b10 = (uint32_t)1U;
      uint32_t c0 = (uint32_t)2U;
      uint32_t d0 = (uint32_t)3U;
      uint32_t r01 = Hacl_Impl_Blake2_Constants_rTable_S[0U];
      uint32_t r11 = Hacl_Impl_Blake2_Constants_rTable_S[1U];
      uint32_t r21 = Hacl_Impl_Blake2_Constants_rTable_S[2U];
      uint32_t r31 = Hacl_Impl_Blake2_Constants_rTable_S[3U];
      Lib_IntVector_Intrinsics_vec128 *wv_a0 = block_state1.fst + a * (uint32_t)1U;
      Lib_IntVector_Intrinsics_vec128 *wv_b0 = block_state1.fst + b10 * (uint32_t)1U;
      wv_a0[0U] = Lib_IntVector_Intrinsics_vec128_add32(wv_a0[0U], wv_b0[0U]);
      wv_a0[0U] = Lib_IntVector_Intrinsics_vec128_add32(wv_a0[0U], x[0U]);
      Lib_IntVector_Intrinsics_vec128 *wv_a1 = block_state1.fst + d0 * (uint32_t)1U;
      Lib_IntVector_Intrinsics_vec128 *wv_b1 = block_state1.fst + a * (uint32_t)1U;
      wv_a1[0U] = Lib_IntVector_Intrinsics_vec128_xor(wv_a1[0U], wv_b1[0U]);
      wv_a1[0U] = Lib_IntVector_Intrinsics_vec128_rotate_right32(wv_a1[0U], r01);
      Lib_IntVector_Intrinsics_vec128 *wv_a2 = block_state1.fst + c0 * (uint32_t)1U;
      Lib_IntVector_Intrinsics_vec128 *wv_b2 = block_state1.fst + d0 * (uint32_t)1U;
      wv_a2[0U] = Lib_IntVector_Intrinsics_vec128_add32(wv_a2[0U], wv_b2[0U]);
      Lib_IntVector_Intrinsics_vec128 *wv_a3 = block_state1.fst + b10 * (uint32_t)1U;
      Lib_IntVector_Intrinsics_vec128 *wv_b3 = block_state1.fst + c0 * (uint32_t)1U;
      wv_a3[0U] = Lib_IntVector_Intrinsics_vec128_xor(wv_a3[0U], wv_b3[0U]);
      wv_a3[0U] = Lib_IntVector_Intrinsics_vec128_rotate_right32(wv_a3[0U], r11);
      Lib_IntVector_Intrinsics_vec128 *wv_a4 = block_state1.fst + a * (uint32_t)1U;
      Lib_IntVector_Intrinsics_vec128 *wv_b4 = block_state1.fst + b10 * (uint32_t)1U;
      wv_a4[0U] = Lib_IntVector_Intrinsics_vec128_add32(wv_a4[0U], wv_b4[0U]);
      wv_a4[0U] = Lib_IntVector_Intrinsics_vec128_add32(wv_a4[0U], y[0U]);
      Lib_IntVector_Intrinsics_vec128 *wv_a5 = block_state1.fst + d0 * (uint32_t)1U;
      Lib_IntVector_Intrinsics_vec128 *wv_b5 = block_state1.fst + a * (uint32_t)1U;
      wv_a5[0U] = Lib_IntVector_Intrinsics_vec128_xor(wv_a5[0U], wv_b5[0U]);
      wv_a5[0U] = Lib_IntVector_Intrinsics_vec128_rotate_right32(wv_a5[0U], r21);
      Lib_IntVector_Intrinsics_vec128 *wv_a6 = block_state1.fst + c0 * (uint32_t)1U;
      Lib_IntVector_Intrinsics_vec128 *wv_b6 = block_state1.fst + d0 * (uint32_t)1U;
      wv_a6[0U] = Lib_IntVector_Intrinsics_vec128_add32(wv_a6[0U], wv_b6[0U]);
      Lib_IntVector_Intrinsics_vec128 *wv_a7 = block_state1.fst + b10 * (uint32_t)1U;
      Lib_IntVector_Intrinsics_vec128 *wv_b7 = block_state1.fst + c0 * (uint32_t)1U;
      wv_a7[0U] = Lib_IntVector_Intrinsics_vec128_xor(wv_a7[0U], wv_b7[0U]);
      wv_a7[0U] = Lib_IntVector_Intrinsics_vec128_rotate_right32(wv_a7[0U], r31);
      Lib_IntVector_Intrinsics_vec128 *r12 = block_state1.fst + (uint32_t)1U * (uint32_t)1U;
      Lib_IntVector_Intrinsics_vec128 *r22 = block_state1.fst + (uint32_t)2U * (uint32_t)1U;
      Lib_IntVector_Intrinsics_vec128 *r32 = block_state1.fst + (uint32_t)3U * (uint32_t)1U;
      Lib_IntVector_Intrinsics_vec128 v00 = r12[0U];
      Lib_IntVector_Intrinsics_vec128
      v1 = Lib_IntVector_Intrinsics_vec128_rotate_right_lanes32(v00, (uint32_t)1U);
      r12[0U] = v1;
      Lib_IntVector_Intrinsics_vec128 v01 = r22[0U];
      Lib_IntVector_Intrinsics_vec128
      v10 = Lib_IntVector_Intrinsics_vec128_rotate_right_lanes32(v01, (uint32_t)2U);
      r22[0U] = v10;
      Lib_IntVector_Intrinsics_vec128 v02 = r32[0U];
      Lib_IntVector_Intrinsics_vec128
      v11 = Lib_IntVector_Intrinsics_vec128_rotate_right_lanes32(v02, (uint32_t)3U);
      r32[0U] = v11;
      uint32_t a0 = (uint32_t)0U;
      uint32_t b1 = (uint32_t)1U;
      uint32_t c = (uint32_t)2U;
      uint32_t d = (uint32_t)3U;
      uint32_t r0 = Hacl_Impl_Blake2_Constants_rTable_S[0U];
      uint32_t r1 = Hacl_Impl_Blake2_Constants_rTable_S[1U];
      uint32_t r23 = Hacl_Impl_Blake2_Constants_rTable_S[2U];
      uint32_t r33 = Hacl_Impl_Blake2_Constants_rTable_S[3U];
      Lib_IntVector_Intrinsics_vec128 *wv_a = block_state1.fst + a0 * (uint32_t)1U;
      Lib_IntVector_Intrinsics_vec128 *wv_b8 = block_state1.fst + b1 * (uint32_t)1U;
      wv_a[0U] = Lib_IntVector_Intrinsics_vec128_add32(wv_a[0U], wv_b8[0U]);
      wv_a[0U] = Lib_IntVector_Intrinsics_vec128_add32(wv_a[0U], z[0U]);
      Lib_IntVector_Intrinsics_vec128 *wv_a8 = block_state1.fst + d * (uint32_t)1U;
      Lib_IntVector_Intrinsics_vec128 *wv_b9 = block_state1.fst + a0 * (uint32_t)1U;
      wv_a8[0U] = Lib_IntVector_Intrinsics_vec128_xor(wv_a8[0U], wv_b9[0U]);
      wv_a8[0U] = Lib_IntVector_Intrinsics_vec128_rotate_right32(wv_a8[0U], r0);
      Lib_IntVector_Intrinsics_vec128 *wv_a9 = block_state1.fst + c * (uint32_t)1U;
      Lib_IntVector_Intrinsics_vec128 *wv_b10 = block_state1.fst + d * (uint32_t)1U;
      wv_a9[0U] = Lib_IntVector_Intrinsics_vec128_add32(wv_a9[0U], wv_b10[0U]);
      Lib_IntVector_Intrinsics_vec128 *wv_a10 = block_state1.fst + b1 * (uint32_t)1U;
      Lib_IntVector_Intrinsics_vec128 *wv_b11 = block_state1.fst + c * (uint32_t)1U;
      wv_a10[0U] = Lib_IntVector_Intrinsics_vec128_xor(wv_a10[0U], wv_b11[0U]);
      wv_a10[0U] = Lib_IntVector_Intrinsics_vec128_rotate_right32(wv_a10[0U], r1);
      Lib_IntVector_Intrinsics_vec128 *wv_a11 = block_state1.fst + a0 * (uint32_t)1U;
      Lib_IntVector_Intrinsics_vec128 *wv_b12 = block_state1.fst + b1 * (uint32_t)1U;
      wv_a11[0U] = Lib_IntVector_Intrinsics_vec128_add32(wv_a11[0U], wv_b12[0U]);
      wv_a11[0U] = Lib_IntVector_Intrinsics_vec128_add32(wv_a11[0U], w[0U]);
      Lib_IntVector_Intrinsics_vec128 *wv_a12 = block_state1.fst + d * (uint32_t)1U;
      Lib_IntVector_Intrinsics_vec128 *wv_b13 = block_state1.fst + a0 * (uint32_t)1U;
      wv_a12[0U] = Lib_IntVector_Intrinsics_vec128_xor(wv_a12[0U], wv_b13[0U]);
      wv_a12[0U] = Lib_IntVector_Intrinsics_vec128_rotate_right32(wv_a12[0U], r23);
      Lib_IntVector_Intrinsics_vec128 *wv_a13 = block_state1.fst + c * (uint32_t)1U;
      Lib_IntVector_Intrinsics_vec128 *wv_b14 = block_state1.fst + d * (uint32_t)1U;
      wv_a13[0U] = Lib_IntVector_Intrinsics_vec128_add32(wv_a13[0U], wv_b14[0U]);
      Lib_IntVector_Intrinsics_vec128 *wv_a14 = block_state1.fst + b1 * (uint32_t)1U;
      Lib_IntVector_Intrinsics_vec128 *wv_b = block_state1.fst + c * (uint32_t)1U;
      wv_a14[0U] = Lib_IntVector_Intrinsics_vec128_xor(wv_a14[0U], wv_b[0U]);
      wv_a14[0U] = Lib_IntVector_Intrinsics_vec128_rotate_right32(wv_a14[0U], r33);
      Lib_IntVector_Intrinsics_vec128 *r13 = block_state1.fst + (uint32_t)1U * (uint32_t)1U;
      Lib_IntVector_Intrinsics_vec128 *r2 = block_state1.fst + (uint32_t)2U * (uint32_t)1U;
      Lib_IntVector_Intrinsics_vec128 *r3 = block_state1.fst + (uint32_t)3U * (uint32_t)1U;
      Lib_IntVector_Intrinsics_vec128 v0 = r13[0U];
      Lib_IntVector_Intrinsics_vec128
      v12 = Lib_IntVector_Intrinsics_vec128_rotate_right_lanes32(v0, (uint32_t)3U);
      r13[0U] = v12;
      Lib_IntVector_Intrinsics_vec128 v03 = r2[0U];
      Lib_IntVector_Intrinsics_vec128
      v13 = Lib_IntVector_Intrinsics_vec128_rotate_right_lanes32(v03, (uint32_t)2U);
      r2[0U] = v13;
      Lib_IntVector_Intrinsics_vec128 v04 = r3[0U];
      Lib_IntVector_Intrinsics_vec128
      v14 = Lib_IntVector_Intrinsics_vec128_rotate_right_lanes32(v04, (uint32_t)1U);
      r3[0U] = v14;
    }
    Lib_IntVector_Intrinsics_vec128 *s0 = block_state1.snd + (uint32_t)0U * (uint32_t)1U;
    Lib_IntVector_Intrinsics_vec128 *s11 = block_state1.snd + (uint32_t)1U * (uint32_t)1U;
    Lib_IntVector_Intrinsics_vec128 *r0 = block_state1.fst + (uint32_t)0U * (uint32_t)1U;
    Lib_IntVector_Intrinsics_vec128 *r1 = block_state1.fst + (uint32_t)1U * (uint32_t)1U;
    Lib_IntVector_Intrinsics_vec128 *r2 = block_state1.fst + (uint32_t)2U * (uint32_t)1U;
    Lib_IntVector_Intrinsics_vec128 *r3 = block_state1.fst + (uint32_t)3U * (uint32_t)1U;
    s0[0U] = Lib_IntVector_Intrinsics_vec128_xor(s0[0U], r0[0U]);
    s0[0U] = Lib_IntVector_Intrinsics_vec128_xor(s0[0U], r2[0U]);
    s11[0U] = Lib_IntVector_Intrinsics_vec128_xor(s11[0U], r1[0U]);
    s11[0U] = Lib_IntVector_Intrinsics_vec128_xor(s11[0U], r3[0U]);
  }
  uint8_t *dst = buf;
  memcpy(dst, data21, data2_len * sizeof (data21[0U]));
  *p
  =
    (
      (Hacl_Streaming_Functor_state_s__K____Lib_IntVector_Intrinsics_vec128___Lib_IntVector_Intrinsics_vec128____){
        .block_state = block_state1,
        .buf = buf,
        .total_len = total_len1 + (uint64_t)(len - diff)
      }
    );
}

/* SNIPPET_END: Hacl_Streaming_Blake2_blake2s_128_with_key_update */

/* SNIPPET_START: Hacl_Streaming_Blake2_blake2s_128_with_key_128_finish */

/*
  Finish function when using a (potentially null) key
*/
void
Hacl_Streaming_Blake2_blake2s_128_with_key_128_finish(
  uint32_t key_size,
  Hacl_Streaming_Functor_state_s__K____Lib_IntVector_Intrinsics_vec128___Lib_IntVector_Intrinsics_vec128____
  *p,
  uint8_t *dst
)
{
  Hacl_Streaming_Functor_state_s__K____Lib_IntVector_Intrinsics_vec128___Lib_IntVector_Intrinsics_vec128____
  scrut = *p;
  K____Lib_IntVector_Intrinsics_vec128___Lib_IntVector_Intrinsics_vec128_
  block_state = scrut.block_state;
  uint8_t *buf_ = scrut.buf;
  uint64_t total_len = scrut.total_len;
  uint32_t r;
  if (total_len % (uint64_t)(uint32_t)64U == (uint64_t)0U && total_len > (uint64_t)0U)
  {
    r = (uint32_t)64U;
  }
  else
  {
    r = (uint32_t)(total_len % (uint64_t)(uint32_t)64U);
  }
  uint8_t *buf_1 = buf_;
  KRML_CHECK_SIZE(sizeof (Lib_IntVector_Intrinsics_vec128), (uint32_t)4U * (uint32_t)1U);
  Lib_IntVector_Intrinsics_vec128 wv[(uint32_t)4U * (uint32_t)1U];
  for (uint32_t _i = 0U; _i < (uint32_t)4U * (uint32_t)1U; ++_i)
    wv[_i] = Lib_IntVector_Intrinsics_vec128_zero;
  KRML_CHECK_SIZE(sizeof (Lib_IntVector_Intrinsics_vec128), (uint32_t)4U * (uint32_t)1U);
  Lib_IntVector_Intrinsics_vec128 b0[(uint32_t)4U * (uint32_t)1U];
  for (uint32_t _i = 0U; _i < (uint32_t)4U * (uint32_t)1U; ++_i)
    b0[_i] = Lib_IntVector_Intrinsics_vec128_zero;
  K____Lib_IntVector_Intrinsics_vec128___Lib_IntVector_Intrinsics_vec128_
  tmp_block_state = { .fst = wv, .snd = b0 };
  Lib_IntVector_Intrinsics_vec128 *src_b = block_state.snd;
  Lib_IntVector_Intrinsics_vec128 *dst_b = tmp_block_state.snd;
  memcpy(dst_b, src_b, (uint32_t)4U * sizeof (src_b[0U]));
  uint64_t prev_len = total_len - (uint64_t)r;
  uint8_t b2[64U] = { 0U };
  uint8_t *last = buf_1 + r - r;
  memcpy(b2, last, r * sizeof (last[0U]));
  uint64_t ite;
  if (key_size == (uint32_t)0U)
  {
    ite = prev_len;
  }
  else
  {
    ite = prev_len + (uint64_t)(uint32_t)64U;
  }
  uint64_t totlen = ite + (uint64_t)r;
  uint32_t m_w[16U] = { 0U };
  for (uint32_t i = (uint32_t)0U; i < (uint32_t)16U; i++)
  {
    uint32_t *os = m_w;
    uint8_t *bj = b2 + i * (uint32_t)4U;
    uint32_t u = load32_le(bj);
    uint32_t r1 = u;
    uint32_t x = r1;
    os[i] = x;
  }
  Lib_IntVector_Intrinsics_vec128 mask = Lib_IntVector_Intrinsics_vec128_zero;
  uint32_t wv_14 = (uint32_t)0xFFFFFFFFU;
  uint32_t wv_15 = (uint32_t)0U;
  mask =
    Lib_IntVector_Intrinsics_vec128_load32s((uint32_t)totlen,
      (uint32_t)(totlen >> (uint32_t)32U),
      wv_14,
      wv_15);
  memcpy(tmp_block_state.fst,
    tmp_block_state.snd,
    (uint32_t)4U * (uint32_t)1U * sizeof (tmp_block_state.snd[0U]));
  Lib_IntVector_Intrinsics_vec128 *wv3 = tmp_block_state.fst + (uint32_t)3U * (uint32_t)1U;
  wv3[0U] = Lib_IntVector_Intrinsics_vec128_xor(wv3[0U], mask);
  for (uint32_t i = (uint32_t)0U; i < (uint32_t)10U; i++)
  {
    uint32_t start_idx = i % (uint32_t)10U * (uint32_t)16U;
    KRML_CHECK_SIZE(sizeof (Lib_IntVector_Intrinsics_vec128), (uint32_t)4U * (uint32_t)1U);
    Lib_IntVector_Intrinsics_vec128 m_st[(uint32_t)4U * (uint32_t)1U];
    for (uint32_t _i = 0U; _i < (uint32_t)4U * (uint32_t)1U; ++_i)
      m_st[_i] = Lib_IntVector_Intrinsics_vec128_zero;
    Lib_IntVector_Intrinsics_vec128 *r00 = m_st + (uint32_t)0U * (uint32_t)1U;
    Lib_IntVector_Intrinsics_vec128 *r10 = m_st + (uint32_t)1U * (uint32_t)1U;
    Lib_IntVector_Intrinsics_vec128 *r20 = m_st + (uint32_t)2U * (uint32_t)1U;
    Lib_IntVector_Intrinsics_vec128 *r30 = m_st + (uint32_t)3U * (uint32_t)1U;
    uint32_t s0 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx];
    uint32_t s1 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)1U];
    uint32_t s2 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)2U];
    uint32_t s3 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)3U];
    uint32_t s4 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)4U];
    uint32_t s5 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)5U];
    uint32_t s6 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)6U];
    uint32_t s7 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)7U];
    uint32_t s8 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)8U];
    uint32_t s9 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)9U];
    uint32_t s10 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)10U];
    uint32_t s11 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)11U];
    uint32_t s12 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)12U];
    uint32_t s13 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)13U];
    uint32_t s14 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)14U];
    uint32_t s15 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)15U];
    r00[0U] = Lib_IntVector_Intrinsics_vec128_load32s(m_w[s0], m_w[s2], m_w[s4], m_w[s6]);
    r10[0U] = Lib_IntVector_Intrinsics_vec128_load32s(m_w[s1], m_w[s3], m_w[s5], m_w[s7]);
    r20[0U] = Lib_IntVector_Intrinsics_vec128_load32s(m_w[s8], m_w[s10], m_w[s12], m_w[s14]);
    r30[0U] = Lib_IntVector_Intrinsics_vec128_load32s(m_w[s9], m_w[s11], m_w[s13], m_w[s15]);
    Lib_IntVector_Intrinsics_vec128 *x = m_st + (uint32_t)0U * (uint32_t)1U;
    Lib_IntVector_Intrinsics_vec128 *y = m_st + (uint32_t)1U * (uint32_t)1U;
    Lib_IntVector_Intrinsics_vec128 *z = m_st + (uint32_t)2U * (uint32_t)1U;
    Lib_IntVector_Intrinsics_vec128 *w = m_st + (uint32_t)3U * (uint32_t)1U;
    uint32_t a = (uint32_t)0U;
    uint32_t b10 = (uint32_t)1U;
    uint32_t c0 = (uint32_t)2U;
    uint32_t d0 = (uint32_t)3U;
    uint32_t r01 = Hacl_Impl_Blake2_Constants_rTable_S[0U];
    uint32_t r11 = Hacl_Impl_Blake2_Constants_rTable_S[1U];
    uint32_t r21 = Hacl_Impl_Blake2_Constants_rTable_S[2U];
    uint32_t r31 = Hacl_Impl_Blake2_Constants_rTable_S[3U];
    Lib_IntVector_Intrinsics_vec128 *wv_a0 = tmp_block_state.fst + a * (uint32_t)1U;
    Lib_IntVector_Intrinsics_vec128 *wv_b0 = tmp_block_state.fst + b10 * (uint32_t)1U;
    wv_a0[0U] = Lib_IntVector_Intrinsics_vec128_add32(wv_a0[0U], wv_b0[0U]);
    wv_a0[0U] = Lib_IntVector_Intrinsics_vec128_add32(wv_a0[0U], x[0U]);
    Lib_IntVector_Intrinsics_vec128 *wv_a1 = tmp_block_state.fst + d0 * (uint32_t)1U;
    Lib_IntVector_Intrinsics_vec128 *wv_b1 = tmp_block_state.fst + a * (uint32_t)1U;
    wv_a1[0U] = Lib_IntVector_Intrinsics_vec128_xor(wv_a1[0U], wv_b1[0U]);
    wv_a1[0U] = Lib_IntVector_Intrinsics_vec128_rotate_right32(wv_a1[0U], r01);
    Lib_IntVector_Intrinsics_vec128 *wv_a2 = tmp_block_state.fst + c0 * (uint32_t)1U;
    Lib_IntVector_Intrinsics_vec128 *wv_b2 = tmp_block_state.fst + d0 * (uint32_t)1U;
    wv_a2[0U] = Lib_IntVector_Intrinsics_vec128_add32(wv_a2[0U], wv_b2[0U]);
    Lib_IntVector_Intrinsics_vec128 *wv_a3 = tmp_block_state.fst + b10 * (uint32_t)1U;
    Lib_IntVector_Intrinsics_vec128 *wv_b3 = tmp_block_state.fst + c0 * (uint32_t)1U;
    wv_a3[0U] = Lib_IntVector_Intrinsics_vec128_xor(wv_a3[0U], wv_b3[0U]);
    wv_a3[0U] = Lib_IntVector_Intrinsics_vec128_rotate_right32(wv_a3[0U], r11);
    Lib_IntVector_Intrinsics_vec128 *wv_a4 = tmp_block_state.fst + a * (uint32_t)1U;
    Lib_IntVector_Intrinsics_vec128 *wv_b4 = tmp_block_state.fst + b10 * (uint32_t)1U;
    wv_a4[0U] = Lib_IntVector_Intrinsics_vec128_add32(wv_a4[0U], wv_b4[0U]);
    wv_a4[0U] = Lib_IntVector_Intrinsics_vec128_add32(wv_a4[0U], y[0U]);
    Lib_IntVector_Intrinsics_vec128 *wv_a5 = tmp_block_state.fst + d0 * (uint32_t)1U;
    Lib_IntVector_Intrinsics_vec128 *wv_b5 = tmp_block_state.fst + a * (uint32_t)1U;
    wv_a5[0U] = Lib_IntVector_Intrinsics_vec128_xor(wv_a5[0U], wv_b5[0U]);
    wv_a5[0U] = Lib_IntVector_Intrinsics_vec128_rotate_right32(wv_a5[0U], r21);
    Lib_IntVector_Intrinsics_vec128 *wv_a6 = tmp_block_state.fst + c0 * (uint32_t)1U;
    Lib_IntVector_Intrinsics_vec128 *wv_b6 = tmp_block_state.fst + d0 * (uint32_t)1U;
    wv_a6[0U] = Lib_IntVector_Intrinsics_vec128_add32(wv_a6[0U], wv_b6[0U]);
    Lib_IntVector_Intrinsics_vec128 *wv_a7 = tmp_block_state.fst + b10 * (uint32_t)1U;
    Lib_IntVector_Intrinsics_vec128 *wv_b7 = tmp_block_state.fst + c0 * (uint32_t)1U;
    wv_a7[0U] = Lib_IntVector_Intrinsics_vec128_xor(wv_a7[0U], wv_b7[0U]);
    wv_a7[0U] = Lib_IntVector_Intrinsics_vec128_rotate_right32(wv_a7[0U], r31);
    Lib_IntVector_Intrinsics_vec128 *r12 = tmp_block_state.fst + (uint32_t)1U * (uint32_t)1U;
    Lib_IntVector_Intrinsics_vec128 *r22 = tmp_block_state.fst + (uint32_t)2U * (uint32_t)1U;
    Lib_IntVector_Intrinsics_vec128 *r32 = tmp_block_state.fst + (uint32_t)3U * (uint32_t)1U;
    Lib_IntVector_Intrinsics_vec128 v00 = r12[0U];
    Lib_IntVector_Intrinsics_vec128
    v1 = Lib_IntVector_Intrinsics_vec128_rotate_right_lanes32(v00, (uint32_t)1U);
    r12[0U] = v1;
    Lib_IntVector_Intrinsics_vec128 v01 = r22[0U];
    Lib_IntVector_Intrinsics_vec128
    v10 = Lib_IntVector_Intrinsics_vec128_rotate_right_lanes32(v01, (uint32_t)2U);
    r22[0U] = v10;
    Lib_IntVector_Intrinsics_vec128 v02 = r32[0U];
    Lib_IntVector_Intrinsics_vec128
    v11 = Lib_IntVector_Intrinsics_vec128_rotate_right_lanes32(v02, (uint32_t)3U);
    r32[0U] = v11;
    uint32_t a0 = (uint32_t)0U;
    uint32_t b1 = (uint32_t)1U;
    uint32_t c = (uint32_t)2U;
    uint32_t d = (uint32_t)3U;
    uint32_t r0 = Hacl_Impl_Blake2_Constants_rTable_S[0U];
    uint32_t r1 = Hacl_Impl_Blake2_Constants_rTable_S[1U];
    uint32_t r23 = Hacl_Impl_Blake2_Constants_rTable_S[2U];
    uint32_t r33 = Hacl_Impl_Blake2_Constants_rTable_S[3U];
    Lib_IntVector_Intrinsics_vec128 *wv_a = tmp_block_state.fst + a0 * (uint32_t)1U;
    Lib_IntVector_Intrinsics_vec128 *wv_b8 = tmp_block_state.fst + b1 * (uint32_t)1U;
    wv_a[0U] = Lib_IntVector_Intrinsics_vec128_add32(wv_a[0U], wv_b8[0U]);
    wv_a[0U] = Lib_IntVector_Intrinsics_vec128_add32(wv_a[0U], z[0U]);
    Lib_IntVector_Intrinsics_vec128 *wv_a8 = tmp_block_state.fst + d * (uint32_t)1U;
    Lib_IntVector_Intrinsics_vec128 *wv_b9 = tmp_block_state.fst + a0 * (uint32_t)1U;
    wv_a8[0U] = Lib_IntVector_Intrinsics_vec128_xor(wv_a8[0U], wv_b9[0U]);
    wv_a8[0U] = Lib_IntVector_Intrinsics_vec128_rotate_right32(wv_a8[0U], r0);
    Lib_IntVector_Intrinsics_vec128 *wv_a9 = tmp_block_state.fst + c * (uint32_t)1U;
    Lib_IntVector_Intrinsics_vec128 *wv_b10 = tmp_block_state.fst + d * (uint32_t)1U;
    wv_a9[0U] = Lib_IntVector_Intrinsics_vec128_add32(wv_a9[0U], wv_b10[0U]);
    Lib_IntVector_Intrinsics_vec128 *wv_a10 = tmp_block_state.fst + b1 * (uint32_t)1U;
    Lib_IntVector_Intrinsics_vec128 *wv_b11 = tmp_block_state.fst + c * (uint32_t)1U;
    wv_a10[0U] = Lib_IntVector_Intrinsics_vec128_xor(wv_a10[0U], wv_b11[0U]);
    wv_a10[0U] = Lib_IntVector_Intrinsics_vec128_rotate_right32(wv_a10[0U], r1);
    Lib_IntVector_Intrinsics_vec128 *wv_a11 = tmp_block_state.fst + a0 * (uint32_t)1U;
    Lib_IntVector_Intrinsics_vec128 *wv_b12 = tmp_block_state.fst + b1 * (uint32_t)1U;
    wv_a11[0U] = Lib_IntVector_Intrinsics_vec128_add32(wv_a11[0U], wv_b12[0U]);
    wv_a11[0U] = Lib_IntVector_Intrinsics_vec128_add32(wv_a11[0U], w[0U]);
    Lib_IntVector_Intrinsics_vec128 *wv_a12 = tmp_block_state.fst + d * (uint32_t)1U;
    Lib_IntVector_Intrinsics_vec128 *wv_b13 = tmp_block_state.fst + a0 * (uint32_t)1U;
    wv_a12[0U] = Lib_IntVector_Intrinsics_vec128_xor(wv_a12[0U], wv_b13[0U]);
    wv_a12[0U] = Lib_IntVector_Intrinsics_vec128_rotate_right32(wv_a12[0U], r23);
    Lib_IntVector_Intrinsics_vec128 *wv_a13 = tmp_block_state.fst + c * (uint32_t)1U;
    Lib_IntVector_Intrinsics_vec128 *wv_b14 = tmp_block_state.fst + d * (uint32_t)1U;
    wv_a13[0U] = Lib_IntVector_Intrinsics_vec128_add32(wv_a13[0U], wv_b14[0U]);
    Lib_IntVector_Intrinsics_vec128 *wv_a14 = tmp_block_state.fst + b1 * (uint32_t)1U;
    Lib_IntVector_Intrinsics_vec128 *wv_b = tmp_block_state.fst + c * (uint32_t)1U;
    wv_a14[0U] = Lib_IntVector_Intrinsics_vec128_xor(wv_a14[0U], wv_b[0U]);
    wv_a14[0U] = Lib_IntVector_Intrinsics_vec128_rotate_right32(wv_a14[0U], r33);
    Lib_IntVector_Intrinsics_vec128 *r13 = tmp_block_state.fst + (uint32_t)1U * (uint32_t)1U;
    Lib_IntVector_Intrinsics_vec128 *r2 = tmp_block_state.fst + (uint32_t)2U * (uint32_t)1U;
    Lib_IntVector_Intrinsics_vec128 *r3 = tmp_block_state.fst + (uint32_t)3U * (uint32_t)1U;
    Lib_IntVector_Intrinsics_vec128 v0 = r13[0U];
    Lib_IntVector_Intrinsics_vec128
    v12 = Lib_IntVector_Intrinsics_vec128_rotate_right_lanes32(v0, (uint32_t)3U);
    r13[0U] = v12;
    Lib_IntVector_Intrinsics_vec128 v03 = r2[0U];
    Lib_IntVector_Intrinsics_vec128
    v13 = Lib_IntVector_Intrinsics_vec128_rotate_right_lanes32(v03, (uint32_t)2U);
    r2[0U] = v13;
    Lib_IntVector_Intrinsics_vec128 v04 = r3[0U];
    Lib_IntVector_Intrinsics_vec128
    v14 = Lib_IntVector_Intrinsics_vec128_rotate_right_lanes32(v04, (uint32_t)1U);
    r3[0U] = v14;
  }
  Lib_IntVector_Intrinsics_vec128 *s0 = tmp_block_state.snd + (uint32_t)0U * (uint32_t)1U;
  Lib_IntVector_Intrinsics_vec128 *s1 = tmp_block_state.snd + (uint32_t)1U * (uint32_t)1U;
  Lib_IntVector_Intrinsics_vec128 *r0 = tmp_block_state.fst + (uint32_t)0U * (uint32_t)1U;
  Lib_IntVector_Intrinsics_vec128 *r1 = tmp_block_state.fst + (uint32_t)1U * (uint32_t)1U;
  Lib_IntVector_Intrinsics_vec128 *r2 = tmp_block_state.fst + (uint32_t)2U * (uint32_t)1U;
  Lib_IntVector_Intrinsics_vec128 *r3 = tmp_block_state.fst + (uint32_t)3U * (uint32_t)1U;
  s0[0U] = Lib_IntVector_Intrinsics_vec128_xor(s0[0U], r0[0U]);
  s0[0U] = Lib_IntVector_Intrinsics_vec128_xor(s0[0U], r2[0U]);
  s1[0U] = Lib_IntVector_Intrinsics_vec128_xor(s1[0U], r1[0U]);
  s1[0U] = Lib_IntVector_Intrinsics_vec128_xor(s1[0U], r3[0U]);
  Lib_Memzero0_memzero(b2, (uint32_t)64U * sizeof (b2[0U]));
  uint32_t double_row = (uint32_t)2U * (uint32_t)4U * (uint32_t)4U;
  KRML_CHECK_SIZE(sizeof (uint8_t), double_row);
  uint8_t b[double_row];
  memset(b, 0U, double_row * sizeof (b[0U]));
  uint8_t *first = b;
  uint8_t *second = b + (uint32_t)4U * (uint32_t)4U;
  Lib_IntVector_Intrinsics_vec128 *row0 = tmp_block_state.snd + (uint32_t)0U * (uint32_t)1U;
  Lib_IntVector_Intrinsics_vec128 *row1 = tmp_block_state.snd + (uint32_t)1U * (uint32_t)1U;
  Lib_IntVector_Intrinsics_vec128_store_le(first, row0[0U]);
  Lib_IntVector_Intrinsics_vec128_store_le(second, row1[0U]);
  uint8_t *final = b;
  memcpy(dst, final, (uint32_t)32U * sizeof (final[0U]));
  Lib_Memzero0_memzero(b, double_row * sizeof (b[0U]));
}

/* SNIPPET_END: Hacl_Streaming_Blake2_blake2s_128_with_key_128_finish */

/* SNIPPET_START: Hacl_Streaming_Blake2_blake2s_128_with_key_free */

/*
  Free state function when using a (potentially null) key
*/
void
Hacl_Streaming_Blake2_blake2s_128_with_key_free(
  uint32_t key_size,
  Hacl_Streaming_Functor_state_s__K____Lib_IntVector_Intrinsics_vec128___Lib_IntVector_Intrinsics_vec128____
  *s1
)
{
  Hacl_Streaming_Functor_state_s__K____Lib_IntVector_Intrinsics_vec128___Lib_IntVector_Intrinsics_vec128____
  scrut = *s1;
  uint8_t *buf = scrut.buf;
  K____Lib_IntVector_Intrinsics_vec128___Lib_IntVector_Intrinsics_vec128_
  block_state = scrut.block_state;
  Lib_IntVector_Intrinsics_vec128 *wv = block_state.fst;
  Lib_IntVector_Intrinsics_vec128 *b = block_state.snd;
  KRML_HOST_FREE(wv);
  KRML_HOST_FREE(b);
  KRML_HOST_FREE(buf);
  KRML_HOST_FREE(s1);
}

/* SNIPPET_END: Hacl_Streaming_Blake2_blake2s_128_with_key_free */

/* SNIPPET_START: Hacl_Streaming_Blake2_blake2b_32_with_key_create_in */

/*
  State allocation function when using a (potentially null) key
*/
Hacl_Streaming_Functor_state_s__K____uint64_t___uint64_t____
*Hacl_Streaming_Blake2_blake2b_32_with_key_create_in(uint32_t key_size, uint8_t *k1)
{
  uint8_t *buf = KRML_HOST_CALLOC((uint32_t)128U, sizeof (uint8_t));
  uint64_t *wv = KRML_HOST_CALLOC((uint32_t)16U, sizeof (uint64_t));
  uint64_t *b0 = KRML_HOST_CALLOC((uint32_t)16U, sizeof (uint64_t));
  K____uint64_t___uint64_t_ block_state = { .fst = wv, .snd = b0 };
  Hacl_Streaming_Functor_state_s__K____uint64_t___uint64_t____
  s1 = { .block_state = block_state, .buf = buf, .total_len = (uint64_t)0U };
  KRML_CHECK_SIZE(sizeof (Hacl_Streaming_Functor_state_s__K____uint64_t___uint64_t____),
    (uint32_t)1U);
  Hacl_Streaming_Functor_state_s__K____uint64_t___uint64_t____
  *p = KRML_HOST_MALLOC(sizeof (Hacl_Streaming_Functor_state_s__K____uint64_t___uint64_t____));
  p[0U] = s1;
  uint8_t b[128U] = { 0U };
  uint64_t *r00 = block_state.snd + (uint32_t)0U * (uint32_t)4U;
  uint64_t *r10 = block_state.snd + (uint32_t)1U * (uint32_t)4U;
  uint64_t *r20 = block_state.snd + (uint32_t)2U * (uint32_t)4U;
  uint64_t *r30 = block_state.snd + (uint32_t)3U * (uint32_t)4U;
  uint64_t iv0 = Hacl_Impl_Blake2_Constants_ivTable_B[0U];
  uint64_t iv1 = Hacl_Impl_Blake2_Constants_ivTable_B[1U];
  uint64_t iv2 = Hacl_Impl_Blake2_Constants_ivTable_B[2U];
  uint64_t iv3 = Hacl_Impl_Blake2_Constants_ivTable_B[3U];
  uint64_t iv4 = Hacl_Impl_Blake2_Constants_ivTable_B[4U];
  uint64_t iv5 = Hacl_Impl_Blake2_Constants_ivTable_B[5U];
  uint64_t iv6 = Hacl_Impl_Blake2_Constants_ivTable_B[6U];
  uint64_t iv7 = Hacl_Impl_Blake2_Constants_ivTable_B[7U];
  r20[0U] = iv0;
  r20[1U] = iv1;
  r20[2U] = iv2;
  r20[3U] = iv3;
  r30[0U] = iv4;
  r30[1U] = iv5;
  r30[2U] = iv6;
  r30[3U] = iv7;
  uint64_t kk_shift_8 = (uint64_t)key_size << (uint32_t)8U;
  uint64_t iv0_ = iv0 ^ ((uint64_t)0x01010000U ^ (kk_shift_8 ^ (uint64_t)(uint32_t)64U));
  r00[0U] = iv0_;
  r00[1U] = iv1;
  r00[2U] = iv2;
  r00[3U] = iv3;
  r10[0U] = iv4;
  r10[1U] = iv5;
  r10[2U] = iv6;
  r10[3U] = iv7;
  if (!(key_size == (uint32_t)0U))
  {
    memcpy(b, k1, key_size * sizeof (k1[0U]));
    FStar_UInt128_uint128
    totlen =
      FStar_UInt128_add_mod(FStar_UInt128_uint64_to_uint128((uint64_t)(uint32_t)0U),
        FStar_UInt128_uint64_to_uint128((uint64_t)(uint32_t)128U));
    uint8_t *b1 = b + (uint32_t)0U * (uint32_t)128U;
    uint64_t m_w[16U] = { 0U };
    for (uint32_t i = (uint32_t)0U; i < (uint32_t)16U; i++)
    {
      uint64_t *os = m_w;
      uint8_t *bj = b1 + i * (uint32_t)8U;
      uint64_t u = load64_le(bj);
      uint64_t r1 = u;
      uint64_t x = r1;
      os[i] = x;
    }
    uint64_t mask[4U] = { 0U };
    uint64_t wv_14 = (uint64_t)0U;
    uint64_t wv_15 = (uint64_t)0U;
    mask[0U] = FStar_UInt128_uint128_to_uint64(totlen);
    mask[1U] = FStar_UInt128_uint128_to_uint64(FStar_UInt128_shift_right(totlen, (uint32_t)64U));
    mask[2U] = wv_14;
    mask[3U] = wv_15;
    memcpy(block_state.fst,
      block_state.snd,
      (uint32_t)4U * (uint32_t)4U * sizeof (block_state.snd[0U]));
    uint64_t *wv3 = block_state.fst + (uint32_t)3U * (uint32_t)4U;
    for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
    {
      uint64_t *os = wv3;
      uint64_t x = wv3[i] ^ mask[i];
      os[i] = x;
    }
    for (uint32_t i0 = (uint32_t)0U; i0 < (uint32_t)12U; i0++)
    {
      uint32_t start_idx = i0 % (uint32_t)10U * (uint32_t)16U;
      KRML_CHECK_SIZE(sizeof (uint64_t), (uint32_t)4U * (uint32_t)4U);
      uint64_t m_st[(uint32_t)4U * (uint32_t)4U];
      memset(m_st, 0U, (uint32_t)4U * (uint32_t)4U * sizeof (m_st[0U]));
      uint64_t *r01 = m_st + (uint32_t)0U * (uint32_t)4U;
      uint64_t *r12 = m_st + (uint32_t)1U * (uint32_t)4U;
      uint64_t *r21 = m_st + (uint32_t)2U * (uint32_t)4U;
      uint64_t *r31 = m_st + (uint32_t)3U * (uint32_t)4U;
      uint32_t s0 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx];
      uint32_t s11 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)1U];
      uint32_t s2 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)2U];
      uint32_t s3 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)3U];
      uint32_t s4 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)4U];
      uint32_t s5 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)5U];
      uint32_t s6 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)6U];
      uint32_t s7 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)7U];
      uint32_t s8 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)8U];
      uint32_t s9 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)9U];
      uint32_t s10 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)10U];
      uint32_t s111 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)11U];
      uint32_t s12 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)12U];
      uint32_t s13 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)13U];
      uint32_t s14 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)14U];
      uint32_t s15 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)15U];
      uint64_t uu____0 = m_w[s2];
      uint64_t uu____1 = m_w[s4];
      uint64_t uu____2 = m_w[s6];
      r01[0U] = m_w[s0];
      r01[1U] = uu____0;
      r01[2U] = uu____1;
      r01[3U] = uu____2;
      uint64_t uu____3 = m_w[s3];
      uint64_t uu____4 = m_w[s5];
      uint64_t uu____5 = m_w[s7];
      r12[0U] = m_w[s11];
      r12[1U] = uu____3;
      r12[2U] = uu____4;
      r12[3U] = uu____5;
      uint64_t uu____6 = m_w[s10];
      uint64_t uu____7 = m_w[s12];
      uint64_t uu____8 = m_w[s14];
      r21[0U] = m_w[s8];
      r21[1U] = uu____6;
      r21[2U] = uu____7;
      r21[3U] = uu____8;
      uint64_t uu____9 = m_w[s111];
      uint64_t uu____10 = m_w[s13];
      uint64_t uu____11 = m_w[s15];
      r31[0U] = m_w[s9];
      r31[1U] = uu____9;
      r31[2U] = uu____10;
      r31[3U] = uu____11;
      uint64_t *x = m_st + (uint32_t)0U * (uint32_t)4U;
      uint64_t *y = m_st + (uint32_t)1U * (uint32_t)4U;
      uint64_t *z = m_st + (uint32_t)2U * (uint32_t)4U;
      uint64_t *w = m_st + (uint32_t)3U * (uint32_t)4U;
      uint32_t a = (uint32_t)0U;
      uint32_t b20 = (uint32_t)1U;
      uint32_t c0 = (uint32_t)2U;
      uint32_t d0 = (uint32_t)3U;
      uint32_t r02 = Hacl_Impl_Blake2_Constants_rTable_B[0U];
      uint32_t r13 = Hacl_Impl_Blake2_Constants_rTable_B[1U];
      uint32_t r22 = Hacl_Impl_Blake2_Constants_rTable_B[2U];
      uint32_t r32 = Hacl_Impl_Blake2_Constants_rTable_B[3U];
      uint64_t *wv_a0 = block_state.fst + a * (uint32_t)4U;
      uint64_t *wv_b0 = block_state.fst + b20 * (uint32_t)4U;
      for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
      {
        uint64_t *os = wv_a0;
        uint64_t x1 = wv_a0[i] + wv_b0[i];
        os[i] = x1;
      }
      for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
      {
        uint64_t *os = wv_a0;
        uint64_t x1 = wv_a0[i] + x[i];
        os[i] = x1;
      }
      uint64_t *wv_a1 = block_state.fst + d0 * (uint32_t)4U;
      uint64_t *wv_b1 = block_state.fst + a * (uint32_t)4U;
      for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
      {
        uint64_t *os = wv_a1;
        uint64_t x1 = wv_a1[i] ^ wv_b1[i];
        os[i] = x1;
      }
      uint64_t *r110 = wv_a1;
      for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
      {
        uint64_t *os = r110;
        uint64_t x1 = r110[i];
        uint64_t x10 = x1 >> r02 | x1 << ((uint32_t)64U - r02);
        os[i] = x10;
      }
      uint64_t *wv_a2 = block_state.fst + c0 * (uint32_t)4U;
      uint64_t *wv_b2 = block_state.fst + d0 * (uint32_t)4U;
      for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
      {
        uint64_t *os = wv_a2;
        uint64_t x1 = wv_a2[i] + wv_b2[i];
        os[i] = x1;
      }
      uint64_t *wv_a3 = block_state.fst + b20 * (uint32_t)4U;
      uint64_t *wv_b3 = block_state.fst + c0 * (uint32_t)4U;
      for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
      {
        uint64_t *os = wv_a3;
        uint64_t x1 = wv_a3[i] ^ wv_b3[i];
        os[i] = x1;
      }
      uint64_t *r111 = wv_a3;
      for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
      {
        uint64_t *os = r111;
        uint64_t x1 = r111[i];
        uint64_t x10 = x1 >> r13 | x1 << ((uint32_t)64U - r13);
        os[i] = x10;
      }
      uint64_t *wv_a4 = block_state.fst + a * (uint32_t)4U;
      uint64_t *wv_b4 = block_state.fst + b20 * (uint32_t)4U;
      for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
      {
        uint64_t *os = wv_a4;
        uint64_t x1 = wv_a4[i] + wv_b4[i];
        os[i] = x1;
      }
      for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
      {
        uint64_t *os = wv_a4;
        uint64_t x1 = wv_a4[i] + y[i];
        os[i] = x1;
      }
      uint64_t *wv_a5 = block_state.fst + d0 * (uint32_t)4U;
      uint64_t *wv_b5 = block_state.fst + a * (uint32_t)4U;
      for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
      {
        uint64_t *os = wv_a5;
        uint64_t x1 = wv_a5[i] ^ wv_b5[i];
        os[i] = x1;
      }
      uint64_t *r112 = wv_a5;
      for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
      {
        uint64_t *os = r112;
        uint64_t x1 = r112[i];
        uint64_t x10 = x1 >> r22 | x1 << ((uint32_t)64U - r22);
        os[i] = x10;
      }
      uint64_t *wv_a6 = block_state.fst + c0 * (uint32_t)4U;
      uint64_t *wv_b6 = block_state.fst + d0 * (uint32_t)4U;
      for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
      {
        uint64_t *os = wv_a6;
        uint64_t x1 = wv_a6[i] + wv_b6[i];
        os[i] = x1;
      }
      uint64_t *wv_a7 = block_state.fst + b20 * (uint32_t)4U;
      uint64_t *wv_b7 = block_state.fst + c0 * (uint32_t)4U;
      for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
      {
        uint64_t *os = wv_a7;
        uint64_t x1 = wv_a7[i] ^ wv_b7[i];
        os[i] = x1;
      }
      uint64_t *r113 = wv_a7;
      for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
      {
        uint64_t *os = r113;
        uint64_t x1 = r113[i];
        uint64_t x10 = x1 >> r32 | x1 << ((uint32_t)64U - r32);
        os[i] = x10;
      }
      uint64_t *r14 = block_state.fst + (uint32_t)1U * (uint32_t)4U;
      uint64_t *r23 = block_state.fst + (uint32_t)2U * (uint32_t)4U;
      uint64_t *r33 = block_state.fst + (uint32_t)3U * (uint32_t)4U;
      uint64_t *r114 = r14;
      uint64_t x00 = r114[1U];
      uint64_t x10 = r114[((uint32_t)1U + (uint32_t)1U) % (uint32_t)4U];
      uint64_t x20 = r114[((uint32_t)1U + (uint32_t)2U) % (uint32_t)4U];
      uint64_t x30 = r114[((uint32_t)1U + (uint32_t)3U) % (uint32_t)4U];
      r114[0U] = x00;
      r114[1U] = x10;
      r114[2U] = x20;
      r114[3U] = x30;
      uint64_t *r115 = r23;
      uint64_t x01 = r115[2U];
      uint64_t x11 = r115[((uint32_t)2U + (uint32_t)1U) % (uint32_t)4U];
      uint64_t x21 = r115[((uint32_t)2U + (uint32_t)2U) % (uint32_t)4U];
      uint64_t x31 = r115[((uint32_t)2U + (uint32_t)3U) % (uint32_t)4U];
      r115[0U] = x01;
      r115[1U] = x11;
      r115[2U] = x21;
      r115[3U] = x31;
      uint64_t *r116 = r33;
      uint64_t x02 = r116[3U];
      uint64_t x12 = r116[((uint32_t)3U + (uint32_t)1U) % (uint32_t)4U];
      uint64_t x22 = r116[((uint32_t)3U + (uint32_t)2U) % (uint32_t)4U];
      uint64_t x32 = r116[((uint32_t)3U + (uint32_t)3U) % (uint32_t)4U];
      r116[0U] = x02;
      r116[1U] = x12;
      r116[2U] = x22;
      r116[3U] = x32;
      uint32_t a0 = (uint32_t)0U;
      uint32_t b2 = (uint32_t)1U;
      uint32_t c = (uint32_t)2U;
      uint32_t d = (uint32_t)3U;
      uint32_t r0 = Hacl_Impl_Blake2_Constants_rTable_B[0U];
      uint32_t r1 = Hacl_Impl_Blake2_Constants_rTable_B[1U];
      uint32_t r24 = Hacl_Impl_Blake2_Constants_rTable_B[2U];
      uint32_t r34 = Hacl_Impl_Blake2_Constants_rTable_B[3U];
      uint64_t *wv_a = block_state.fst + a0 * (uint32_t)4U;
      uint64_t *wv_b8 = block_state.fst + b2 * (uint32_t)4U;
      for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
      {
        uint64_t *os = wv_a;
        uint64_t x1 = wv_a[i] + wv_b8[i];
        os[i] = x1;
      }
      for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
      {
        uint64_t *os = wv_a;
        uint64_t x1 = wv_a[i] + z[i];
        os[i] = x1;
      }
      uint64_t *wv_a8 = block_state.fst + d * (uint32_t)4U;
      uint64_t *wv_b9 = block_state.fst + a0 * (uint32_t)4U;
      for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
      {
        uint64_t *os = wv_a8;
        uint64_t x1 = wv_a8[i] ^ wv_b9[i];
        os[i] = x1;
      }
      uint64_t *r117 = wv_a8;
      for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
      {
        uint64_t *os = r117;
        uint64_t x1 = r117[i];
        uint64_t x13 = x1 >> r0 | x1 << ((uint32_t)64U - r0);
        os[i] = x13;
      }
      uint64_t *wv_a9 = block_state.fst + c * (uint32_t)4U;
      uint64_t *wv_b10 = block_state.fst + d * (uint32_t)4U;
      for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
      {
        uint64_t *os = wv_a9;
        uint64_t x1 = wv_a9[i] + wv_b10[i];
        os[i] = x1;
      }
      uint64_t *wv_a10 = block_state.fst + b2 * (uint32_t)4U;
      uint64_t *wv_b11 = block_state.fst + c * (uint32_t)4U;
      for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
      {
        uint64_t *os = wv_a10;
        uint64_t x1 = wv_a10[i] ^ wv_b11[i];
        os[i] = x1;
      }
      uint64_t *r118 = wv_a10;
      for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
      {
        uint64_t *os = r118;
        uint64_t x1 = r118[i];
        uint64_t x13 = x1 >> r1 | x1 << ((uint32_t)64U - r1);
        os[i] = x13;
      }
      uint64_t *wv_a11 = block_state.fst + a0 * (uint32_t)4U;
      uint64_t *wv_b12 = block_state.fst + b2 * (uint32_t)4U;
      for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
      {
        uint64_t *os = wv_a11;
        uint64_t x1 = wv_a11[i] + wv_b12[i];
        os[i] = x1;
      }
      for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
      {
        uint64_t *os = wv_a11;
        uint64_t x1 = wv_a11[i] + w[i];
        os[i] = x1;
      }
      uint64_t *wv_a12 = block_state.fst + d * (uint32_t)4U;
      uint64_t *wv_b13 = block_state.fst + a0 * (uint32_t)4U;
      for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
      {
        uint64_t *os = wv_a12;
        uint64_t x1 = wv_a12[i] ^ wv_b13[i];
        os[i] = x1;
      }
      uint64_t *r119 = wv_a12;
      for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
      {
        uint64_t *os = r119;
        uint64_t x1 = r119[i];
        uint64_t x13 = x1 >> r24 | x1 << ((uint32_t)64U - r24);
        os[i] = x13;
      }
      uint64_t *wv_a13 = block_state.fst + c * (uint32_t)4U;
      uint64_t *wv_b14 = block_state.fst + d * (uint32_t)4U;
      for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
      {
        uint64_t *os = wv_a13;
        uint64_t x1 = wv_a13[i] + wv_b14[i];
        os[i] = x1;
      }
      uint64_t *wv_a14 = block_state.fst + b2 * (uint32_t)4U;
      uint64_t *wv_b = block_state.fst + c * (uint32_t)4U;
      for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
      {
        uint64_t *os = wv_a14;
        uint64_t x1 = wv_a14[i] ^ wv_b[i];
        os[i] = x1;
      }
      uint64_t *r1110 = wv_a14;
      for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
      {
        uint64_t *os = r1110;
        uint64_t x1 = r1110[i];
        uint64_t x13 = x1 >> r34 | x1 << ((uint32_t)64U - r34);
        os[i] = x13;
      }
      uint64_t *r15 = block_state.fst + (uint32_t)1U * (uint32_t)4U;
      uint64_t *r2 = block_state.fst + (uint32_t)2U * (uint32_t)4U;
      uint64_t *r3 = block_state.fst + (uint32_t)3U * (uint32_t)4U;
      uint64_t *r11 = r15;
      uint64_t x03 = r11[3U];
      uint64_t x13 = r11[((uint32_t)3U + (uint32_t)1U) % (uint32_t)4U];
      uint64_t x23 = r11[((uint32_t)3U + (uint32_t)2U) % (uint32_t)4U];
      uint64_t x33 = r11[((uint32_t)3U + (uint32_t)3U) % (uint32_t)4U];
      r11[0U] = x03;
      r11[1U] = x13;
      r11[2U] = x23;
      r11[3U] = x33;
      uint64_t *r1111 = r2;
      uint64_t x04 = r1111[2U];
      uint64_t x14 = r1111[((uint32_t)2U + (uint32_t)1U) % (uint32_t)4U];
      uint64_t x24 = r1111[((uint32_t)2U + (uint32_t)2U) % (uint32_t)4U];
      uint64_t x34 = r1111[((uint32_t)2U + (uint32_t)3U) % (uint32_t)4U];
      r1111[0U] = x04;
      r1111[1U] = x14;
      r1111[2U] = x24;
      r1111[3U] = x34;
      uint64_t *r1112 = r3;
      uint64_t x0 = r1112[1U];
      uint64_t x1 = r1112[((uint32_t)1U + (uint32_t)1U) % (uint32_t)4U];
      uint64_t x2 = r1112[((uint32_t)1U + (uint32_t)2U) % (uint32_t)4U];
      uint64_t x3 = r1112[((uint32_t)1U + (uint32_t)3U) % (uint32_t)4U];
      r1112[0U] = x0;
      r1112[1U] = x1;
      r1112[2U] = x2;
      r1112[3U] = x3;
    }
    uint64_t *s0 = block_state.snd + (uint32_t)0U * (uint32_t)4U;
    uint64_t *s11 = block_state.snd + (uint32_t)1U * (uint32_t)4U;
    uint64_t *r0 = block_state.fst + (uint32_t)0U * (uint32_t)4U;
    uint64_t *r1 = block_state.fst + (uint32_t)1U * (uint32_t)4U;
    uint64_t *r2 = block_state.fst + (uint32_t)2U * (uint32_t)4U;
    uint64_t *r3 = block_state.fst + (uint32_t)3U * (uint32_t)4U;
    for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
    {
      uint64_t *os = s0;
      uint64_t x = s0[i] ^ r0[i];
      os[i] = x;
    }
    for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
    {
      uint64_t *os = s0;
      uint64_t x = s0[i] ^ r2[i];
      os[i] = x;
    }
    for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
    {
      uint64_t *os = s11;
      uint64_t x = s11[i] ^ r1[i];
      os[i] = x;
    }
    for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
    {
      uint64_t *os = s11;
      uint64_t x = s11[i] ^ r3[i];
      os[i] = x;
    }
  }
  Lib_Memzero0_memzero(b, (uint32_t)128U * sizeof (b[0U]));
  return p;
}

/* SNIPPET_END: Hacl_Streaming_Blake2_blake2b_32_with_key_create_in */

/* SNIPPET_START: Hacl_Streaming_Blake2_blake2b_32_with_key_update */

/*
  Update function when using a (potentially null) key
*/
void
Hacl_Streaming_Blake2_blake2b_32_with_key_update(
  uint32_t key_size,
  Hacl_Streaming_Functor_state_s__K____uint64_t___uint64_t____ *p,
  uint8_t *data,
  uint32_t len
)
{
  Hacl_Streaming_Functor_state_s__K____uint64_t___uint64_t____ s1 = *p;
  uint64_t total_len = s1.total_len;
  uint32_t sz;
  if (total_len % (uint64_t)(uint32_t)128U == (uint64_t)0U && total_len > (uint64_t)0U)
  {
    sz = (uint32_t)128U;
  }
  else
  {
    sz = (uint32_t)(total_len % (uint64_t)(uint32_t)128U);
  }
  if (len <= (uint32_t)128U - sz)
  {
    Hacl_Streaming_Functor_state_s__K____uint64_t___uint64_t____ s2 = *p;
    K____uint64_t___uint64_t_ block_state1 = s2.block_state;
    uint8_t *buf = s2.buf;
    uint64_t total_len1 = s2.total_len;
    uint32_t sz1;
    if (total_len1 % (uint64_t)(uint32_t)128U == (uint64_t)0U && total_len1 > (uint64_t)0U)
    {
      sz1 = (uint32_t)128U;
    }
    else
    {
      sz1 = (uint32_t)(total_len1 % (uint64_t)(uint32_t)128U);
    }
    uint8_t *buf2 = buf + sz1;
    memcpy(buf2, data, len * sizeof (data[0U]));
    uint64_t total_len2 = total_len1 + (uint64_t)len;
    *p
    =
      (
        (Hacl_Streaming_Functor_state_s__K____uint64_t___uint64_t____){
          .block_state = block_state1,
          .buf = buf,
          .total_len = total_len2
        }
      );
    return;
  }
  if (sz == (uint32_t)0U)
  {
    Hacl_Streaming_Functor_state_s__K____uint64_t___uint64_t____ s2 = *p;
    K____uint64_t___uint64_t_ block_state1 = s2.block_state;
    uint8_t *buf = s2.buf;
    uint64_t total_len1 = s2.total_len;
    uint32_t sz1;
    if (total_len1 % (uint64_t)(uint32_t)128U == (uint64_t)0U && total_len1 > (uint64_t)0U)
    {
      sz1 = (uint32_t)128U;
    }
    else
    {
      sz1 = (uint32_t)(total_len1 % (uint64_t)(uint32_t)128U);
    }
    if (!(sz1 == (uint32_t)0U))
    {
      uint64_t prevlen = total_len1 - (uint64_t)sz1;
      uint32_t nb = (uint32_t)1U;
      for (uint32_t i0 = (uint32_t)0U; i0 < nb; i0++)
      {
        uint64_t ite;
        if (key_size == (uint32_t)0U)
        {
          ite = prevlen;
        }
        else
        {
          ite = prevlen + (uint64_t)(uint32_t)128U;
        }
        FStar_UInt128_uint128
        totlen =
          FStar_UInt128_add_mod(FStar_UInt128_uint64_to_uint128(ite),
            FStar_UInt128_uint64_to_uint128((uint64_t)((i0 + (uint32_t)1U) * (uint32_t)128U)));
        uint8_t *b = buf + i0 * (uint32_t)128U;
        uint64_t m_w[16U] = { 0U };
        for (uint32_t i = (uint32_t)0U; i < (uint32_t)16U; i++)
        {
          uint64_t *os = m_w;
          uint8_t *bj = b + i * (uint32_t)8U;
          uint64_t u = load64_le(bj);
          uint64_t r = u;
          uint64_t x = r;
          os[i] = x;
        }
        uint64_t mask[4U] = { 0U };
        uint64_t wv_14 = (uint64_t)0U;
        uint64_t wv_15 = (uint64_t)0U;
        mask[0U] = FStar_UInt128_uint128_to_uint64(totlen);
        mask[1U] = FStar_UInt128_uint128_to_uint64(FStar_UInt128_shift_right(totlen, (uint32_t)64U));
        mask[2U] = wv_14;
        mask[3U] = wv_15;
        memcpy(block_state1.fst,
          block_state1.snd,
          (uint32_t)4U * (uint32_t)4U * sizeof (block_state1.snd[0U]));
        uint64_t *wv3 = block_state1.fst + (uint32_t)3U * (uint32_t)4U;
        for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
        {
          uint64_t *os = wv3;
          uint64_t x = wv3[i] ^ mask[i];
          os[i] = x;
        }
        for (uint32_t i1 = (uint32_t)0U; i1 < (uint32_t)12U; i1++)
        {
          uint32_t start_idx = i1 % (uint32_t)10U * (uint32_t)16U;
          KRML_CHECK_SIZE(sizeof (uint64_t), (uint32_t)4U * (uint32_t)4U);
          uint64_t m_st[(uint32_t)4U * (uint32_t)4U];
          memset(m_st, 0U, (uint32_t)4U * (uint32_t)4U * sizeof (m_st[0U]));
          uint64_t *r00 = m_st + (uint32_t)0U * (uint32_t)4U;
          uint64_t *r10 = m_st + (uint32_t)1U * (uint32_t)4U;
          uint64_t *r20 = m_st + (uint32_t)2U * (uint32_t)4U;
          uint64_t *r30 = m_st + (uint32_t)3U * (uint32_t)4U;
          uint32_t s0 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx];
          uint32_t s11 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)1U];
          uint32_t s21 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)2U];
          uint32_t s3 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)3U];
          uint32_t s4 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)4U];
          uint32_t s5 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)5U];
          uint32_t s6 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)6U];
          uint32_t s7 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)7U];
          uint32_t s8 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)8U];
          uint32_t s9 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)9U];
          uint32_t s10 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)10U];
          uint32_t s111 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)11U];
          uint32_t s12 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)12U];
          uint32_t s13 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)13U];
          uint32_t s14 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)14U];
          uint32_t s15 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)15U];
          uint64_t uu____0 = m_w[s21];
          uint64_t uu____1 = m_w[s4];
          uint64_t uu____2 = m_w[s6];
          r00[0U] = m_w[s0];
          r00[1U] = uu____0;
          r00[2U] = uu____1;
          r00[3U] = uu____2;
          uint64_t uu____3 = m_w[s3];
          uint64_t uu____4 = m_w[s5];
          uint64_t uu____5 = m_w[s7];
          r10[0U] = m_w[s11];
          r10[1U] = uu____3;
          r10[2U] = uu____4;
          r10[3U] = uu____5;
          uint64_t uu____6 = m_w[s10];
          uint64_t uu____7 = m_w[s12];
          uint64_t uu____8 = m_w[s14];
          r20[0U] = m_w[s8];
          r20[1U] = uu____6;
          r20[2U] = uu____7;
          r20[3U] = uu____8;
          uint64_t uu____9 = m_w[s111];
          uint64_t uu____10 = m_w[s13];
          uint64_t uu____11 = m_w[s15];
          r30[0U] = m_w[s9];
          r30[1U] = uu____9;
          r30[2U] = uu____10;
          r30[3U] = uu____11;
          uint64_t *x = m_st + (uint32_t)0U * (uint32_t)4U;
          uint64_t *y = m_st + (uint32_t)1U * (uint32_t)4U;
          uint64_t *z = m_st + (uint32_t)2U * (uint32_t)4U;
          uint64_t *w = m_st + (uint32_t)3U * (uint32_t)4U;
          uint32_t a = (uint32_t)0U;
          uint32_t b10 = (uint32_t)1U;
          uint32_t c0 = (uint32_t)2U;
          uint32_t d0 = (uint32_t)3U;
          uint32_t r01 = Hacl_Impl_Blake2_Constants_rTable_B[0U];
          uint32_t r12 = Hacl_Impl_Blake2_Constants_rTable_B[1U];
          uint32_t r21 = Hacl_Impl_Blake2_Constants_rTable_B[2U];
          uint32_t r31 = Hacl_Impl_Blake2_Constants_rTable_B[3U];
          uint64_t *wv_a0 = block_state1.fst + a * (uint32_t)4U;
          uint64_t *wv_b0 = block_state1.fst + b10 * (uint32_t)4U;
          for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
          {
            uint64_t *os = wv_a0;
            uint64_t x1 = wv_a0[i] + wv_b0[i];
            os[i] = x1;
          }
          for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
          {
            uint64_t *os = wv_a0;
            uint64_t x1 = wv_a0[i] + x[i];
            os[i] = x1;
          }
          uint64_t *wv_a1 = block_state1.fst + d0 * (uint32_t)4U;
          uint64_t *wv_b1 = block_state1.fst + a * (uint32_t)4U;
          for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
          {
            uint64_t *os = wv_a1;
            uint64_t x1 = wv_a1[i] ^ wv_b1[i];
            os[i] = x1;
          }
          uint64_t *r110 = wv_a1;
          for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
          {
            uint64_t *os = r110;
            uint64_t x1 = r110[i];
            uint64_t x10 = x1 >> r01 | x1 << ((uint32_t)64U - r01);
            os[i] = x10;
          }
          uint64_t *wv_a2 = block_state1.fst + c0 * (uint32_t)4U;
          uint64_t *wv_b2 = block_state1.fst + d0 * (uint32_t)4U;
          for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
          {
            uint64_t *os = wv_a2;
            uint64_t x1 = wv_a2[i] + wv_b2[i];
            os[i] = x1;
          }
          uint64_t *wv_a3 = block_state1.fst + b10 * (uint32_t)4U;
          uint64_t *wv_b3 = block_state1.fst + c0 * (uint32_t)4U;
          for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
          {
            uint64_t *os = wv_a3;
            uint64_t x1 = wv_a3[i] ^ wv_b3[i];
            os[i] = x1;
          }
          uint64_t *r111 = wv_a3;
          for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
          {
            uint64_t *os = r111;
            uint64_t x1 = r111[i];
            uint64_t x10 = x1 >> r12 | x1 << ((uint32_t)64U - r12);
            os[i] = x10;
          }
          uint64_t *wv_a4 = block_state1.fst + a * (uint32_t)4U;
          uint64_t *wv_b4 = block_state1.fst + b10 * (uint32_t)4U;
          for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
          {
            uint64_t *os = wv_a4;
            uint64_t x1 = wv_a4[i] + wv_b4[i];
            os[i] = x1;
          }
          for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
          {
            uint64_t *os = wv_a4;
            uint64_t x1 = wv_a4[i] + y[i];
            os[i] = x1;
          }
          uint64_t *wv_a5 = block_state1.fst + d0 * (uint32_t)4U;
          uint64_t *wv_b5 = block_state1.fst + a * (uint32_t)4U;
          for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
          {
            uint64_t *os = wv_a5;
            uint64_t x1 = wv_a5[i] ^ wv_b5[i];
            os[i] = x1;
          }
          uint64_t *r112 = wv_a5;
          for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
          {
            uint64_t *os = r112;
            uint64_t x1 = r112[i];
            uint64_t x10 = x1 >> r21 | x1 << ((uint32_t)64U - r21);
            os[i] = x10;
          }
          uint64_t *wv_a6 = block_state1.fst + c0 * (uint32_t)4U;
          uint64_t *wv_b6 = block_state1.fst + d0 * (uint32_t)4U;
          for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
          {
            uint64_t *os = wv_a6;
            uint64_t x1 = wv_a6[i] + wv_b6[i];
            os[i] = x1;
          }
          uint64_t *wv_a7 = block_state1.fst + b10 * (uint32_t)4U;
          uint64_t *wv_b7 = block_state1.fst + c0 * (uint32_t)4U;
          for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
          {
            uint64_t *os = wv_a7;
            uint64_t x1 = wv_a7[i] ^ wv_b7[i];
            os[i] = x1;
          }
          uint64_t *r113 = wv_a7;
          for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
          {
            uint64_t *os = r113;
            uint64_t x1 = r113[i];
            uint64_t x10 = x1 >> r31 | x1 << ((uint32_t)64U - r31);
            os[i] = x10;
          }
          uint64_t *r13 = block_state1.fst + (uint32_t)1U * (uint32_t)4U;
          uint64_t *r22 = block_state1.fst + (uint32_t)2U * (uint32_t)4U;
          uint64_t *r32 = block_state1.fst + (uint32_t)3U * (uint32_t)4U;
          uint64_t *r114 = r13;
          uint64_t x00 = r114[1U];
          uint64_t x10 = r114[((uint32_t)1U + (uint32_t)1U) % (uint32_t)4U];
          uint64_t x20 = r114[((uint32_t)1U + (uint32_t)2U) % (uint32_t)4U];
          uint64_t x30 = r114[((uint32_t)1U + (uint32_t)3U) % (uint32_t)4U];
          r114[0U] = x00;
          r114[1U] = x10;
          r114[2U] = x20;
          r114[3U] = x30;
          uint64_t *r115 = r22;
          uint64_t x01 = r115[2U];
          uint64_t x11 = r115[((uint32_t)2U + (uint32_t)1U) % (uint32_t)4U];
          uint64_t x21 = r115[((uint32_t)2U + (uint32_t)2U) % (uint32_t)4U];
          uint64_t x31 = r115[((uint32_t)2U + (uint32_t)3U) % (uint32_t)4U];
          r115[0U] = x01;
          r115[1U] = x11;
          r115[2U] = x21;
          r115[3U] = x31;
          uint64_t *r116 = r32;
          uint64_t x02 = r116[3U];
          uint64_t x12 = r116[((uint32_t)3U + (uint32_t)1U) % (uint32_t)4U];
          uint64_t x22 = r116[((uint32_t)3U + (uint32_t)2U) % (uint32_t)4U];
          uint64_t x32 = r116[((uint32_t)3U + (uint32_t)3U) % (uint32_t)4U];
          r116[0U] = x02;
          r116[1U] = x12;
          r116[2U] = x22;
          r116[3U] = x32;
          uint32_t a0 = (uint32_t)0U;
          uint32_t b1 = (uint32_t)1U;
          uint32_t c = (uint32_t)2U;
          uint32_t d = (uint32_t)3U;
          uint32_t r0 = Hacl_Impl_Blake2_Constants_rTable_B[0U];
          uint32_t r1 = Hacl_Impl_Blake2_Constants_rTable_B[1U];
          uint32_t r23 = Hacl_Impl_Blake2_Constants_rTable_B[2U];
          uint32_t r33 = Hacl_Impl_Blake2_Constants_rTable_B[3U];
          uint64_t *wv_a = block_state1.fst + a0 * (uint32_t)4U;
          uint64_t *wv_b8 = block_state1.fst + b1 * (uint32_t)4U;
          for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
          {
            uint64_t *os = wv_a;
            uint64_t x1 = wv_a[i] + wv_b8[i];
            os[i] = x1;
          }
          for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
          {
            uint64_t *os = wv_a;
            uint64_t x1 = wv_a[i] + z[i];
            os[i] = x1;
          }
          uint64_t *wv_a8 = block_state1.fst + d * (uint32_t)4U;
          uint64_t *wv_b9 = block_state1.fst + a0 * (uint32_t)4U;
          for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
          {
            uint64_t *os = wv_a8;
            uint64_t x1 = wv_a8[i] ^ wv_b9[i];
            os[i] = x1;
          }
          uint64_t *r117 = wv_a8;
          for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
          {
            uint64_t *os = r117;
            uint64_t x1 = r117[i];
            uint64_t x13 = x1 >> r0 | x1 << ((uint32_t)64U - r0);
            os[i] = x13;
          }
          uint64_t *wv_a9 = block_state1.fst + c * (uint32_t)4U;
          uint64_t *wv_b10 = block_state1.fst + d * (uint32_t)4U;
          for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
          {
            uint64_t *os = wv_a9;
            uint64_t x1 = wv_a9[i] + wv_b10[i];
            os[i] = x1;
          }
          uint64_t *wv_a10 = block_state1.fst + b1 * (uint32_t)4U;
          uint64_t *wv_b11 = block_state1.fst + c * (uint32_t)4U;
          for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
          {
            uint64_t *os = wv_a10;
            uint64_t x1 = wv_a10[i] ^ wv_b11[i];
            os[i] = x1;
          }
          uint64_t *r118 = wv_a10;
          for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
          {
            uint64_t *os = r118;
            uint64_t x1 = r118[i];
            uint64_t x13 = x1 >> r1 | x1 << ((uint32_t)64U - r1);
            os[i] = x13;
          }
          uint64_t *wv_a11 = block_state1.fst + a0 * (uint32_t)4U;
          uint64_t *wv_b12 = block_state1.fst + b1 * (uint32_t)4U;
          for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
          {
            uint64_t *os = wv_a11;
            uint64_t x1 = wv_a11[i] + wv_b12[i];
            os[i] = x1;
          }
          for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
          {
            uint64_t *os = wv_a11;
            uint64_t x1 = wv_a11[i] + w[i];
            os[i] = x1;
          }
          uint64_t *wv_a12 = block_state1.fst + d * (uint32_t)4U;
          uint64_t *wv_b13 = block_state1.fst + a0 * (uint32_t)4U;
          for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
          {
            uint64_t *os = wv_a12;
            uint64_t x1 = wv_a12[i] ^ wv_b13[i];
            os[i] = x1;
          }
          uint64_t *r119 = wv_a12;
          for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
          {
            uint64_t *os = r119;
            uint64_t x1 = r119[i];
            uint64_t x13 = x1 >> r23 | x1 << ((uint32_t)64U - r23);
            os[i] = x13;
          }
          uint64_t *wv_a13 = block_state1.fst + c * (uint32_t)4U;
          uint64_t *wv_b14 = block_state1.fst + d * (uint32_t)4U;
          for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
          {
            uint64_t *os = wv_a13;
            uint64_t x1 = wv_a13[i] + wv_b14[i];
            os[i] = x1;
          }
          uint64_t *wv_a14 = block_state1.fst + b1 * (uint32_t)4U;
          uint64_t *wv_b = block_state1.fst + c * (uint32_t)4U;
          for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
          {
            uint64_t *os = wv_a14;
            uint64_t x1 = wv_a14[i] ^ wv_b[i];
            os[i] = x1;
          }
          uint64_t *r1110 = wv_a14;
          for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
          {
            uint64_t *os = r1110;
            uint64_t x1 = r1110[i];
            uint64_t x13 = x1 >> r33 | x1 << ((uint32_t)64U - r33);
            os[i] = x13;
          }
          uint64_t *r14 = block_state1.fst + (uint32_t)1U * (uint32_t)4U;
          uint64_t *r2 = block_state1.fst + (uint32_t)2U * (uint32_t)4U;
          uint64_t *r3 = block_state1.fst + (uint32_t)3U * (uint32_t)4U;
          uint64_t *r11 = r14;
          uint64_t x03 = r11[3U];
          uint64_t x13 = r11[((uint32_t)3U + (uint32_t)1U) % (uint32_t)4U];
          uint64_t x23 = r11[((uint32_t)3U + (uint32_t)2U) % (uint32_t)4U];
          uint64_t x33 = r11[((uint32_t)3U + (uint32_t)3U) % (uint32_t)4U];
          r11[0U] = x03;
          r11[1U] = x13;
          r11[2U] = x23;
          r11[3U] = x33;
          uint64_t *r1111 = r2;
          uint64_t x04 = r1111[2U];
          uint64_t x14 = r1111[((uint32_t)2U + (uint32_t)1U) % (uint32_t)4U];
          uint64_t x24 = r1111[((uint32_t)2U + (uint32_t)2U) % (uint32_t)4U];
          uint64_t x34 = r1111[((uint32_t)2U + (uint32_t)3U) % (uint32_t)4U];
          r1111[0U] = x04;
          r1111[1U] = x14;
          r1111[2U] = x24;
          r1111[3U] = x34;
          uint64_t *r1112 = r3;
          uint64_t x0 = r1112[1U];
          uint64_t x1 = r1112[((uint32_t)1U + (uint32_t)1U) % (uint32_t)4U];
          uint64_t x2 = r1112[((uint32_t)1U + (uint32_t)2U) % (uint32_t)4U];
          uint64_t x3 = r1112[((uint32_t)1U + (uint32_t)3U) % (uint32_t)4U];
          r1112[0U] = x0;
          r1112[1U] = x1;
          r1112[2U] = x2;
          r1112[3U] = x3;
        }
        uint64_t *s0 = block_state1.snd + (uint32_t)0U * (uint32_t)4U;
        uint64_t *s11 = block_state1.snd + (uint32_t)1U * (uint32_t)4U;
        uint64_t *r0 = block_state1.fst + (uint32_t)0U * (uint32_t)4U;
        uint64_t *r1 = block_state1.fst + (uint32_t)1U * (uint32_t)4U;
        uint64_t *r2 = block_state1.fst + (uint32_t)2U * (uint32_t)4U;
        uint64_t *r3 = block_state1.fst + (uint32_t)3U * (uint32_t)4U;
        for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
        {
          uint64_t *os = s0;
          uint64_t x = s0[i] ^ r0[i];
          os[i] = x;
        }
        for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
        {
          uint64_t *os = s0;
          uint64_t x = s0[i] ^ r2[i];
          os[i] = x;
        }
        for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
        {
          uint64_t *os = s11;
          uint64_t x = s11[i] ^ r1[i];
          os[i] = x;
        }
        for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
        {
          uint64_t *os = s11;
          uint64_t x = s11[i] ^ r3[i];
          os[i] = x;
        }
      }
    }
    uint32_t ite0;
    if ((uint64_t)len % (uint64_t)(uint32_t)128U == (uint64_t)0U && (uint64_t)len > (uint64_t)0U)
    {
      ite0 = (uint32_t)128U;
    }
    else
    {
      ite0 = (uint32_t)((uint64_t)len % (uint64_t)(uint32_t)128U);
    }
    uint32_t n_blocks = (len - ite0) / (uint32_t)128U;
    uint32_t data1_len = n_blocks * (uint32_t)128U;
    uint32_t data2_len = len - data1_len;
    uint8_t *data1 = data;
    uint8_t *data2 = data + data1_len;
    uint32_t nb = data1_len / (uint32_t)128U;
    for (uint32_t i0 = (uint32_t)0U; i0 < nb; i0++)
    {
      uint64_t ite;
      if (key_size == (uint32_t)0U)
      {
        ite = total_len1;
      }
      else
      {
        ite = total_len1 + (uint64_t)(uint32_t)128U;
      }
      FStar_UInt128_uint128
      totlen =
        FStar_UInt128_add_mod(FStar_UInt128_uint64_to_uint128(ite),
          FStar_UInt128_uint64_to_uint128((uint64_t)((i0 + (uint32_t)1U) * (uint32_t)128U)));
      uint8_t *b = data1 + i0 * (uint32_t)128U;
      uint64_t m_w[16U] = { 0U };
      for (uint32_t i = (uint32_t)0U; i < (uint32_t)16U; i++)
      {
        uint64_t *os = m_w;
        uint8_t *bj = b + i * (uint32_t)8U;
        uint64_t u = load64_le(bj);
        uint64_t r = u;
        uint64_t x = r;
        os[i] = x;
      }
      uint64_t mask[4U] = { 0U };
      uint64_t wv_14 = (uint64_t)0U;
      uint64_t wv_15 = (uint64_t)0U;
      mask[0U] = FStar_UInt128_uint128_to_uint64(totlen);
      mask[1U] = FStar_UInt128_uint128_to_uint64(FStar_UInt128_shift_right(totlen, (uint32_t)64U));
      mask[2U] = wv_14;
      mask[3U] = wv_15;
      memcpy(block_state1.fst,
        block_state1.snd,
        (uint32_t)4U * (uint32_t)4U * sizeof (block_state1.snd[0U]));
      uint64_t *wv3 = block_state1.fst + (uint32_t)3U * (uint32_t)4U;
      for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
      {
        uint64_t *os = wv3;
        uint64_t x = wv3[i] ^ mask[i];
        os[i] = x;
      }
      for (uint32_t i1 = (uint32_t)0U; i1 < (uint32_t)12U; i1++)
      {
        uint32_t start_idx = i1 % (uint32_t)10U * (uint32_t)16U;
        KRML_CHECK_SIZE(sizeof (uint64_t), (uint32_t)4U * (uint32_t)4U);
        uint64_t m_st[(uint32_t)4U * (uint32_t)4U];
        memset(m_st, 0U, (uint32_t)4U * (uint32_t)4U * sizeof (m_st[0U]));
        uint64_t *r00 = m_st + (uint32_t)0U * (uint32_t)4U;
        uint64_t *r10 = m_st + (uint32_t)1U * (uint32_t)4U;
        uint64_t *r20 = m_st + (uint32_t)2U * (uint32_t)4U;
        uint64_t *r30 = m_st + (uint32_t)3U * (uint32_t)4U;
        uint32_t s0 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx];
        uint32_t s11 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)1U];
        uint32_t s21 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)2U];
        uint32_t s3 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)3U];
        uint32_t s4 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)4U];
        uint32_t s5 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)5U];
        uint32_t s6 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)6U];
        uint32_t s7 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)7U];
        uint32_t s8 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)8U];
        uint32_t s9 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)9U];
        uint32_t s10 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)10U];
        uint32_t s111 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)11U];
        uint32_t s12 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)12U];
        uint32_t s13 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)13U];
        uint32_t s14 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)14U];
        uint32_t s15 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)15U];
        uint64_t uu____12 = m_w[s21];
        uint64_t uu____13 = m_w[s4];
        uint64_t uu____14 = m_w[s6];
        r00[0U] = m_w[s0];
        r00[1U] = uu____12;
        r00[2U] = uu____13;
        r00[3U] = uu____14;
        uint64_t uu____15 = m_w[s3];
        uint64_t uu____16 = m_w[s5];
        uint64_t uu____17 = m_w[s7];
        r10[0U] = m_w[s11];
        r10[1U] = uu____15;
        r10[2U] = uu____16;
        r10[3U] = uu____17;
        uint64_t uu____18 = m_w[s10];
        uint64_t uu____19 = m_w[s12];
        uint64_t uu____20 = m_w[s14];
        r20[0U] = m_w[s8];
        r20[1U] = uu____18;
        r20[2U] = uu____19;
        r20[3U] = uu____20;
        uint64_t uu____21 = m_w[s111];
        uint64_t uu____22 = m_w[s13];
        uint64_t uu____23 = m_w[s15];
        r30[0U] = m_w[s9];
        r30[1U] = uu____21;
        r30[2U] = uu____22;
        r30[3U] = uu____23;
        uint64_t *x = m_st + (uint32_t)0U * (uint32_t)4U;
        uint64_t *y = m_st + (uint32_t)1U * (uint32_t)4U;
        uint64_t *z = m_st + (uint32_t)2U * (uint32_t)4U;
        uint64_t *w = m_st + (uint32_t)3U * (uint32_t)4U;
        uint32_t a = (uint32_t)0U;
        uint32_t b10 = (uint32_t)1U;
        uint32_t c0 = (uint32_t)2U;
        uint32_t d0 = (uint32_t)3U;
        uint32_t r01 = Hacl_Impl_Blake2_Constants_rTable_B[0U];
        uint32_t r12 = Hacl_Impl_Blake2_Constants_rTable_B[1U];
        uint32_t r21 = Hacl_Impl_Blake2_Constants_rTable_B[2U];
        uint32_t r31 = Hacl_Impl_Blake2_Constants_rTable_B[3U];
        uint64_t *wv_a0 = block_state1.fst + a * (uint32_t)4U;
        uint64_t *wv_b0 = block_state1.fst + b10 * (uint32_t)4U;
        for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
        {
          uint64_t *os = wv_a0;
          uint64_t x1 = wv_a0[i] + wv_b0[i];
          os[i] = x1;
        }
        for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
        {
          uint64_t *os = wv_a0;
          uint64_t x1 = wv_a0[i] + x[i];
          os[i] = x1;
        }
        uint64_t *wv_a1 = block_state1.fst + d0 * (uint32_t)4U;
        uint64_t *wv_b1 = block_state1.fst + a * (uint32_t)4U;
        for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
        {
          uint64_t *os = wv_a1;
          uint64_t x1 = wv_a1[i] ^ wv_b1[i];
          os[i] = x1;
        }
        uint64_t *r110 = wv_a1;
        for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
        {
          uint64_t *os = r110;
          uint64_t x1 = r110[i];
          uint64_t x10 = x1 >> r01 | x1 << ((uint32_t)64U - r01);
          os[i] = x10;
        }
        uint64_t *wv_a2 = block_state1.fst + c0 * (uint32_t)4U;
        uint64_t *wv_b2 = block_state1.fst + d0 * (uint32_t)4U;
        for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
        {
          uint64_t *os = wv_a2;
          uint64_t x1 = wv_a2[i] + wv_b2[i];
          os[i] = x1;
        }
        uint64_t *wv_a3 = block_state1.fst + b10 * (uint32_t)4U;
        uint64_t *wv_b3 = block_state1.fst + c0 * (uint32_t)4U;
        for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
        {
          uint64_t *os = wv_a3;
          uint64_t x1 = wv_a3[i] ^ wv_b3[i];
          os[i] = x1;
        }
        uint64_t *r111 = wv_a3;
        for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
        {
          uint64_t *os = r111;
          uint64_t x1 = r111[i];
          uint64_t x10 = x1 >> r12 | x1 << ((uint32_t)64U - r12);
          os[i] = x10;
        }
        uint64_t *wv_a4 = block_state1.fst + a * (uint32_t)4U;
        uint64_t *wv_b4 = block_state1.fst + b10 * (uint32_t)4U;
        for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
        {
          uint64_t *os = wv_a4;
          uint64_t x1 = wv_a4[i] + wv_b4[i];
          os[i] = x1;
        }
        for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
        {
          uint64_t *os = wv_a4;
          uint64_t x1 = wv_a4[i] + y[i];
          os[i] = x1;
        }
        uint64_t *wv_a5 = block_state1.fst + d0 * (uint32_t)4U;
        uint64_t *wv_b5 = block_state1.fst + a * (uint32_t)4U;
        for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
        {
          uint64_t *os = wv_a5;
          uint64_t x1 = wv_a5[i] ^ wv_b5[i];
          os[i] = x1;
        }
        uint64_t *r112 = wv_a5;
        for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
        {
          uint64_t *os = r112;
          uint64_t x1 = r112[i];
          uint64_t x10 = x1 >> r21 | x1 << ((uint32_t)64U - r21);
          os[i] = x10;
        }
        uint64_t *wv_a6 = block_state1.fst + c0 * (uint32_t)4U;
        uint64_t *wv_b6 = block_state1.fst + d0 * (uint32_t)4U;
        for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
        {
          uint64_t *os = wv_a6;
          uint64_t x1 = wv_a6[i] + wv_b6[i];
          os[i] = x1;
        }
        uint64_t *wv_a7 = block_state1.fst + b10 * (uint32_t)4U;
        uint64_t *wv_b7 = block_state1.fst + c0 * (uint32_t)4U;
        for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
        {
          uint64_t *os = wv_a7;
          uint64_t x1 = wv_a7[i] ^ wv_b7[i];
          os[i] = x1;
        }
        uint64_t *r113 = wv_a7;
        for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
        {
          uint64_t *os = r113;
          uint64_t x1 = r113[i];
          uint64_t x10 = x1 >> r31 | x1 << ((uint32_t)64U - r31);
          os[i] = x10;
        }
        uint64_t *r13 = block_state1.fst + (uint32_t)1U * (uint32_t)4U;
        uint64_t *r22 = block_state1.fst + (uint32_t)2U * (uint32_t)4U;
        uint64_t *r32 = block_state1.fst + (uint32_t)3U * (uint32_t)4U;
        uint64_t *r114 = r13;
        uint64_t x00 = r114[1U];
        uint64_t x10 = r114[((uint32_t)1U + (uint32_t)1U) % (uint32_t)4U];
        uint64_t x20 = r114[((uint32_t)1U + (uint32_t)2U) % (uint32_t)4U];
        uint64_t x30 = r114[((uint32_t)1U + (uint32_t)3U) % (uint32_t)4U];
        r114[0U] = x00;
        r114[1U] = x10;
        r114[2U] = x20;
        r114[3U] = x30;
        uint64_t *r115 = r22;
        uint64_t x01 = r115[2U];
        uint64_t x11 = r115[((uint32_t)2U + (uint32_t)1U) % (uint32_t)4U];
        uint64_t x21 = r115[((uint32_t)2U + (uint32_t)2U) % (uint32_t)4U];
        uint64_t x31 = r115[((uint32_t)2U + (uint32_t)3U) % (uint32_t)4U];
        r115[0U] = x01;
        r115[1U] = x11;
        r115[2U] = x21;
        r115[3U] = x31;
        uint64_t *r116 = r32;
        uint64_t x02 = r116[3U];
        uint64_t x12 = r116[((uint32_t)3U + (uint32_t)1U) % (uint32_t)4U];
        uint64_t x22 = r116[((uint32_t)3U + (uint32_t)2U) % (uint32_t)4U];
        uint64_t x32 = r116[((uint32_t)3U + (uint32_t)3U) % (uint32_t)4U];
        r116[0U] = x02;
        r116[1U] = x12;
        r116[2U] = x22;
        r116[3U] = x32;
        uint32_t a0 = (uint32_t)0U;
        uint32_t b1 = (uint32_t)1U;
        uint32_t c = (uint32_t)2U;
        uint32_t d = (uint32_t)3U;
        uint32_t r0 = Hacl_Impl_Blake2_Constants_rTable_B[0U];
        uint32_t r1 = Hacl_Impl_Blake2_Constants_rTable_B[1U];
        uint32_t r23 = Hacl_Impl_Blake2_Constants_rTable_B[2U];
        uint32_t r33 = Hacl_Impl_Blake2_Constants_rTable_B[3U];
        uint64_t *wv_a = block_state1.fst + a0 * (uint32_t)4U;
        uint64_t *wv_b8 = block_state1.fst + b1 * (uint32_t)4U;
        for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
        {
          uint64_t *os = wv_a;
          uint64_t x1 = wv_a[i] + wv_b8[i];
          os[i] = x1;
        }
        for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
        {
          uint64_t *os = wv_a;
          uint64_t x1 = wv_a[i] + z[i];
          os[i] = x1;
        }
        uint64_t *wv_a8 = block_state1.fst + d * (uint32_t)4U;
        uint64_t *wv_b9 = block_state1.fst + a0 * (uint32_t)4U;
        for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
        {
          uint64_t *os = wv_a8;
          uint64_t x1 = wv_a8[i] ^ wv_b9[i];
          os[i] = x1;
        }
        uint64_t *r117 = wv_a8;
        for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
        {
          uint64_t *os = r117;
          uint64_t x1 = r117[i];
          uint64_t x13 = x1 >> r0 | x1 << ((uint32_t)64U - r0);
          os[i] = x13;
        }
        uint64_t *wv_a9 = block_state1.fst + c * (uint32_t)4U;
        uint64_t *wv_b10 = block_state1.fst + d * (uint32_t)4U;
        for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
        {
          uint64_t *os = wv_a9;
          uint64_t x1 = wv_a9[i] + wv_b10[i];
          os[i] = x1;
        }
        uint64_t *wv_a10 = block_state1.fst + b1 * (uint32_t)4U;
        uint64_t *wv_b11 = block_state1.fst + c * (uint32_t)4U;
        for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
        {
          uint64_t *os = wv_a10;
          uint64_t x1 = wv_a10[i] ^ wv_b11[i];
          os[i] = x1;
        }
        uint64_t *r118 = wv_a10;
        for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
        {
          uint64_t *os = r118;
          uint64_t x1 = r118[i];
          uint64_t x13 = x1 >> r1 | x1 << ((uint32_t)64U - r1);
          os[i] = x13;
        }
        uint64_t *wv_a11 = block_state1.fst + a0 * (uint32_t)4U;
        uint64_t *wv_b12 = block_state1.fst + b1 * (uint32_t)4U;
        for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
        {
          uint64_t *os = wv_a11;
          uint64_t x1 = wv_a11[i] + wv_b12[i];
          os[i] = x1;
        }
        for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
        {
          uint64_t *os = wv_a11;
          uint64_t x1 = wv_a11[i] + w[i];
          os[i] = x1;
        }
        uint64_t *wv_a12 = block_state1.fst + d * (uint32_t)4U;
        uint64_t *wv_b13 = block_state1.fst + a0 * (uint32_t)4U;
        for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
        {
          uint64_t *os = wv_a12;
          uint64_t x1 = wv_a12[i] ^ wv_b13[i];
          os[i] = x1;
        }
        uint64_t *r119 = wv_a12;
        for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
        {
          uint64_t *os = r119;
          uint64_t x1 = r119[i];
          uint64_t x13 = x1 >> r23 | x1 << ((uint32_t)64U - r23);
          os[i] = x13;
        }
        uint64_t *wv_a13 = block_state1.fst + c * (uint32_t)4U;
        uint64_t *wv_b14 = block_state1.fst + d * (uint32_t)4U;
        for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
        {
          uint64_t *os = wv_a13;
          uint64_t x1 = wv_a13[i] + wv_b14[i];
          os[i] = x1;
        }
        uint64_t *wv_a14 = block_state1.fst + b1 * (uint32_t)4U;
        uint64_t *wv_b = block_state1.fst + c * (uint32_t)4U;
        for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
        {
          uint64_t *os = wv_a14;
          uint64_t x1 = wv_a14[i] ^ wv_b[i];
          os[i] = x1;
        }
        uint64_t *r1110 = wv_a14;
        for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
        {
          uint64_t *os = r1110;
          uint64_t x1 = r1110[i];
          uint64_t x13 = x1 >> r33 | x1 << ((uint32_t)64U - r33);
          os[i] = x13;
        }
        uint64_t *r14 = block_state1.fst + (uint32_t)1U * (uint32_t)4U;
        uint64_t *r2 = block_state1.fst + (uint32_t)2U * (uint32_t)4U;
        uint64_t *r3 = block_state1.fst + (uint32_t)3U * (uint32_t)4U;
        uint64_t *r11 = r14;
        uint64_t x03 = r11[3U];
        uint64_t x13 = r11[((uint32_t)3U + (uint32_t)1U) % (uint32_t)4U];
        uint64_t x23 = r11[((uint32_t)3U + (uint32_t)2U) % (uint32_t)4U];
        uint64_t x33 = r11[((uint32_t)3U + (uint32_t)3U) % (uint32_t)4U];
        r11[0U] = x03;
        r11[1U] = x13;
        r11[2U] = x23;
        r11[3U] = x33;
        uint64_t *r1111 = r2;
        uint64_t x04 = r1111[2U];
        uint64_t x14 = r1111[((uint32_t)2U + (uint32_t)1U) % (uint32_t)4U];
        uint64_t x24 = r1111[((uint32_t)2U + (uint32_t)2U) % (uint32_t)4U];
        uint64_t x34 = r1111[((uint32_t)2U + (uint32_t)3U) % (uint32_t)4U];
        r1111[0U] = x04;
        r1111[1U] = x14;
        r1111[2U] = x24;
        r1111[3U] = x34;
        uint64_t *r1112 = r3;
        uint64_t x0 = r1112[1U];
        uint64_t x1 = r1112[((uint32_t)1U + (uint32_t)1U) % (uint32_t)4U];
        uint64_t x2 = r1112[((uint32_t)1U + (uint32_t)2U) % (uint32_t)4U];
        uint64_t x3 = r1112[((uint32_t)1U + (uint32_t)3U) % (uint32_t)4U];
        r1112[0U] = x0;
        r1112[1U] = x1;
        r1112[2U] = x2;
        r1112[3U] = x3;
      }
      uint64_t *s0 = block_state1.snd + (uint32_t)0U * (uint32_t)4U;
      uint64_t *s11 = block_state1.snd + (uint32_t)1U * (uint32_t)4U;
      uint64_t *r0 = block_state1.fst + (uint32_t)0U * (uint32_t)4U;
      uint64_t *r1 = block_state1.fst + (uint32_t)1U * (uint32_t)4U;
      uint64_t *r2 = block_state1.fst + (uint32_t)2U * (uint32_t)4U;
      uint64_t *r3 = block_state1.fst + (uint32_t)3U * (uint32_t)4U;
      for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
      {
        uint64_t *os = s0;
        uint64_t x = s0[i] ^ r0[i];
        os[i] = x;
      }
      for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
      {
        uint64_t *os = s0;
        uint64_t x = s0[i] ^ r2[i];
        os[i] = x;
      }
      for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
      {
        uint64_t *os = s11;
        uint64_t x = s11[i] ^ r1[i];
        os[i] = x;
      }
      for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
      {
        uint64_t *os = s11;
        uint64_t x = s11[i] ^ r3[i];
        os[i] = x;
      }
    }
    uint8_t *dst = buf;
    memcpy(dst, data2, data2_len * sizeof (data2[0U]));
    *p
    =
      (
        (Hacl_Streaming_Functor_state_s__K____uint64_t___uint64_t____){
          .block_state = block_state1,
          .buf = buf,
          .total_len = total_len1 + (uint64_t)len
        }
      );
    return;
  }
  uint32_t diff = (uint32_t)128U - sz;
  uint8_t *data1 = data;
  uint8_t *data2 = data + diff;
  Hacl_Streaming_Functor_state_s__K____uint64_t___uint64_t____ s2 = *p;
  K____uint64_t___uint64_t_ block_state10 = s2.block_state;
  uint8_t *buf0 = s2.buf;
  uint64_t total_len10 = s2.total_len;
  uint32_t sz10;
  if (total_len10 % (uint64_t)(uint32_t)128U == (uint64_t)0U && total_len10 > (uint64_t)0U)
  {
    sz10 = (uint32_t)128U;
  }
  else
  {
    sz10 = (uint32_t)(total_len10 % (uint64_t)(uint32_t)128U);
  }
  uint8_t *buf2 = buf0 + sz10;
  memcpy(buf2, data1, diff * sizeof (data1[0U]));
  uint64_t total_len2 = total_len10 + (uint64_t)diff;
  *p
  =
    (
      (Hacl_Streaming_Functor_state_s__K____uint64_t___uint64_t____){
        .block_state = block_state10,
        .buf = buf0,
        .total_len = total_len2
      }
    );
  Hacl_Streaming_Functor_state_s__K____uint64_t___uint64_t____ s20 = *p;
  K____uint64_t___uint64_t_ block_state1 = s20.block_state;
  uint8_t *buf = s20.buf;
  uint64_t total_len1 = s20.total_len;
  uint32_t sz1;
  if (total_len1 % (uint64_t)(uint32_t)128U == (uint64_t)0U && total_len1 > (uint64_t)0U)
  {
    sz1 = (uint32_t)128U;
  }
  else
  {
    sz1 = (uint32_t)(total_len1 % (uint64_t)(uint32_t)128U);
  }
  if (!(sz1 == (uint32_t)0U))
  {
    uint64_t prevlen = total_len1 - (uint64_t)sz1;
    uint32_t nb = (uint32_t)1U;
    for (uint32_t i0 = (uint32_t)0U; i0 < nb; i0++)
    {
      uint64_t ite;
      if (key_size == (uint32_t)0U)
      {
        ite = prevlen;
      }
      else
      {
        ite = prevlen + (uint64_t)(uint32_t)128U;
      }
      FStar_UInt128_uint128
      totlen =
        FStar_UInt128_add_mod(FStar_UInt128_uint64_to_uint128(ite),
          FStar_UInt128_uint64_to_uint128((uint64_t)((i0 + (uint32_t)1U) * (uint32_t)128U)));
      uint8_t *b = buf + i0 * (uint32_t)128U;
      uint64_t m_w[16U] = { 0U };
      for (uint32_t i = (uint32_t)0U; i < (uint32_t)16U; i++)
      {
        uint64_t *os = m_w;
        uint8_t *bj = b + i * (uint32_t)8U;
        uint64_t u = load64_le(bj);
        uint64_t r = u;
        uint64_t x = r;
        os[i] = x;
      }
      uint64_t mask[4U] = { 0U };
      uint64_t wv_14 = (uint64_t)0U;
      uint64_t wv_15 = (uint64_t)0U;
      mask[0U] = FStar_UInt128_uint128_to_uint64(totlen);
      mask[1U] = FStar_UInt128_uint128_to_uint64(FStar_UInt128_shift_right(totlen, (uint32_t)64U));
      mask[2U] = wv_14;
      mask[3U] = wv_15;
      memcpy(block_state1.fst,
        block_state1.snd,
        (uint32_t)4U * (uint32_t)4U * sizeof (block_state1.snd[0U]));
      uint64_t *wv3 = block_state1.fst + (uint32_t)3U * (uint32_t)4U;
      for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
      {
        uint64_t *os = wv3;
        uint64_t x = wv3[i] ^ mask[i];
        os[i] = x;
      }
      for (uint32_t i1 = (uint32_t)0U; i1 < (uint32_t)12U; i1++)
      {
        uint32_t start_idx = i1 % (uint32_t)10U * (uint32_t)16U;
        KRML_CHECK_SIZE(sizeof (uint64_t), (uint32_t)4U * (uint32_t)4U);
        uint64_t m_st[(uint32_t)4U * (uint32_t)4U];
        memset(m_st, 0U, (uint32_t)4U * (uint32_t)4U * sizeof (m_st[0U]));
        uint64_t *r00 = m_st + (uint32_t)0U * (uint32_t)4U;
        uint64_t *r10 = m_st + (uint32_t)1U * (uint32_t)4U;
        uint64_t *r20 = m_st + (uint32_t)2U * (uint32_t)4U;
        uint64_t *r30 = m_st + (uint32_t)3U * (uint32_t)4U;
        uint32_t s0 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx];
        uint32_t s11 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)1U];
        uint32_t s21 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)2U];
        uint32_t s3 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)3U];
        uint32_t s4 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)4U];
        uint32_t s5 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)5U];
        uint32_t s6 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)6U];
        uint32_t s7 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)7U];
        uint32_t s8 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)8U];
        uint32_t s9 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)9U];
        uint32_t s10 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)10U];
        uint32_t s111 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)11U];
        uint32_t s12 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)12U];
        uint32_t s13 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)13U];
        uint32_t s14 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)14U];
        uint32_t s15 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)15U];
        uint64_t uu____24 = m_w[s21];
        uint64_t uu____25 = m_w[s4];
        uint64_t uu____26 = m_w[s6];
        r00[0U] = m_w[s0];
        r00[1U] = uu____24;
        r00[2U] = uu____25;
        r00[3U] = uu____26;
        uint64_t uu____27 = m_w[s3];
        uint64_t uu____28 = m_w[s5];
        uint64_t uu____29 = m_w[s7];
        r10[0U] = m_w[s11];
        r10[1U] = uu____27;
        r10[2U] = uu____28;
        r10[3U] = uu____29;
        uint64_t uu____30 = m_w[s10];
        uint64_t uu____31 = m_w[s12];
        uint64_t uu____32 = m_w[s14];
        r20[0U] = m_w[s8];
        r20[1U] = uu____30;
        r20[2U] = uu____31;
        r20[3U] = uu____32;
        uint64_t uu____33 = m_w[s111];
        uint64_t uu____34 = m_w[s13];
        uint64_t uu____35 = m_w[s15];
        r30[0U] = m_w[s9];
        r30[1U] = uu____33;
        r30[2U] = uu____34;
        r30[3U] = uu____35;
        uint64_t *x = m_st + (uint32_t)0U * (uint32_t)4U;
        uint64_t *y = m_st + (uint32_t)1U * (uint32_t)4U;
        uint64_t *z = m_st + (uint32_t)2U * (uint32_t)4U;
        uint64_t *w = m_st + (uint32_t)3U * (uint32_t)4U;
        uint32_t a = (uint32_t)0U;
        uint32_t b10 = (uint32_t)1U;
        uint32_t c0 = (uint32_t)2U;
        uint32_t d0 = (uint32_t)3U;
        uint32_t r01 = Hacl_Impl_Blake2_Constants_rTable_B[0U];
        uint32_t r12 = Hacl_Impl_Blake2_Constants_rTable_B[1U];
        uint32_t r21 = Hacl_Impl_Blake2_Constants_rTable_B[2U];
        uint32_t r31 = Hacl_Impl_Blake2_Constants_rTable_B[3U];
        uint64_t *wv_a0 = block_state1.fst + a * (uint32_t)4U;
        uint64_t *wv_b0 = block_state1.fst + b10 * (uint32_t)4U;
        for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
        {
          uint64_t *os = wv_a0;
          uint64_t x1 = wv_a0[i] + wv_b0[i];
          os[i] = x1;
        }
        for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
        {
          uint64_t *os = wv_a0;
          uint64_t x1 = wv_a0[i] + x[i];
          os[i] = x1;
        }
        uint64_t *wv_a1 = block_state1.fst + d0 * (uint32_t)4U;
        uint64_t *wv_b1 = block_state1.fst + a * (uint32_t)4U;
        for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
        {
          uint64_t *os = wv_a1;
          uint64_t x1 = wv_a1[i] ^ wv_b1[i];
          os[i] = x1;
        }
        uint64_t *r110 = wv_a1;
        for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
        {
          uint64_t *os = r110;
          uint64_t x1 = r110[i];
          uint64_t x10 = x1 >> r01 | x1 << ((uint32_t)64U - r01);
          os[i] = x10;
        }
        uint64_t *wv_a2 = block_state1.fst + c0 * (uint32_t)4U;
        uint64_t *wv_b2 = block_state1.fst + d0 * (uint32_t)4U;
        for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
        {
          uint64_t *os = wv_a2;
          uint64_t x1 = wv_a2[i] + wv_b2[i];
          os[i] = x1;
        }
        uint64_t *wv_a3 = block_state1.fst + b10 * (uint32_t)4U;
        uint64_t *wv_b3 = block_state1.fst + c0 * (uint32_t)4U;
        for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
        {
          uint64_t *os = wv_a3;
          uint64_t x1 = wv_a3[i] ^ wv_b3[i];
          os[i] = x1;
        }
        uint64_t *r111 = wv_a3;
        for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
        {
          uint64_t *os = r111;
          uint64_t x1 = r111[i];
          uint64_t x10 = x1 >> r12 | x1 << ((uint32_t)64U - r12);
          os[i] = x10;
        }
        uint64_t *wv_a4 = block_state1.fst + a * (uint32_t)4U;
        uint64_t *wv_b4 = block_state1.fst + b10 * (uint32_t)4U;
        for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
        {
          uint64_t *os = wv_a4;
          uint64_t x1 = wv_a4[i] + wv_b4[i];
          os[i] = x1;
        }
        for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
        {
          uint64_t *os = wv_a4;
          uint64_t x1 = wv_a4[i] + y[i];
          os[i] = x1;
        }
        uint64_t *wv_a5 = block_state1.fst + d0 * (uint32_t)4U;
        uint64_t *wv_b5 = block_state1.fst + a * (uint32_t)4U;
        for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
        {
          uint64_t *os = wv_a5;
          uint64_t x1 = wv_a5[i] ^ wv_b5[i];
          os[i] = x1;
        }
        uint64_t *r112 = wv_a5;
        for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
        {
          uint64_t *os = r112;
          uint64_t x1 = r112[i];
          uint64_t x10 = x1 >> r21 | x1 << ((uint32_t)64U - r21);
          os[i] = x10;
        }
        uint64_t *wv_a6 = block_state1.fst + c0 * (uint32_t)4U;
        uint64_t *wv_b6 = block_state1.fst + d0 * (uint32_t)4U;
        for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
        {
          uint64_t *os = wv_a6;
          uint64_t x1 = wv_a6[i] + wv_b6[i];
          os[i] = x1;
        }
        uint64_t *wv_a7 = block_state1.fst + b10 * (uint32_t)4U;
        uint64_t *wv_b7 = block_state1.fst + c0 * (uint32_t)4U;
        for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
        {
          uint64_t *os = wv_a7;
          uint64_t x1 = wv_a7[i] ^ wv_b7[i];
          os[i] = x1;
        }
        uint64_t *r113 = wv_a7;
        for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
        {
          uint64_t *os = r113;
          uint64_t x1 = r113[i];
          uint64_t x10 = x1 >> r31 | x1 << ((uint32_t)64U - r31);
          os[i] = x10;
        }
        uint64_t *r13 = block_state1.fst + (uint32_t)1U * (uint32_t)4U;
        uint64_t *r22 = block_state1.fst + (uint32_t)2U * (uint32_t)4U;
        uint64_t *r32 = block_state1.fst + (uint32_t)3U * (uint32_t)4U;
        uint64_t *r114 = r13;
        uint64_t x00 = r114[1U];
        uint64_t x10 = r114[((uint32_t)1U + (uint32_t)1U) % (uint32_t)4U];
        uint64_t x20 = r114[((uint32_t)1U + (uint32_t)2U) % (uint32_t)4U];
        uint64_t x30 = r114[((uint32_t)1U + (uint32_t)3U) % (uint32_t)4U];
        r114[0U] = x00;
        r114[1U] = x10;
        r114[2U] = x20;
        r114[3U] = x30;
        uint64_t *r115 = r22;
        uint64_t x01 = r115[2U];
        uint64_t x11 = r115[((uint32_t)2U + (uint32_t)1U) % (uint32_t)4U];
        uint64_t x21 = r115[((uint32_t)2U + (uint32_t)2U) % (uint32_t)4U];
        uint64_t x31 = r115[((uint32_t)2U + (uint32_t)3U) % (uint32_t)4U];
        r115[0U] = x01;
        r115[1U] = x11;
        r115[2U] = x21;
        r115[3U] = x31;
        uint64_t *r116 = r32;
        uint64_t x02 = r116[3U];
        uint64_t x12 = r116[((uint32_t)3U + (uint32_t)1U) % (uint32_t)4U];
        uint64_t x22 = r116[((uint32_t)3U + (uint32_t)2U) % (uint32_t)4U];
        uint64_t x32 = r116[((uint32_t)3U + (uint32_t)3U) % (uint32_t)4U];
        r116[0U] = x02;
        r116[1U] = x12;
        r116[2U] = x22;
        r116[3U] = x32;
        uint32_t a0 = (uint32_t)0U;
        uint32_t b1 = (uint32_t)1U;
        uint32_t c = (uint32_t)2U;
        uint32_t d = (uint32_t)3U;
        uint32_t r0 = Hacl_Impl_Blake2_Constants_rTable_B[0U];
        uint32_t r1 = Hacl_Impl_Blake2_Constants_rTable_B[1U];
        uint32_t r23 = Hacl_Impl_Blake2_Constants_rTable_B[2U];
        uint32_t r33 = Hacl_Impl_Blake2_Constants_rTable_B[3U];
        uint64_t *wv_a = block_state1.fst + a0 * (uint32_t)4U;
        uint64_t *wv_b8 = block_state1.fst + b1 * (uint32_t)4U;
        for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
        {
          uint64_t *os = wv_a;
          uint64_t x1 = wv_a[i] + wv_b8[i];
          os[i] = x1;
        }
        for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
        {
          uint64_t *os = wv_a;
          uint64_t x1 = wv_a[i] + z[i];
          os[i] = x1;
        }
        uint64_t *wv_a8 = block_state1.fst + d * (uint32_t)4U;
        uint64_t *wv_b9 = block_state1.fst + a0 * (uint32_t)4U;
        for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
        {
          uint64_t *os = wv_a8;
          uint64_t x1 = wv_a8[i] ^ wv_b9[i];
          os[i] = x1;
        }
        uint64_t *r117 = wv_a8;
        for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
        {
          uint64_t *os = r117;
          uint64_t x1 = r117[i];
          uint64_t x13 = x1 >> r0 | x1 << ((uint32_t)64U - r0);
          os[i] = x13;
        }
        uint64_t *wv_a9 = block_state1.fst + c * (uint32_t)4U;
        uint64_t *wv_b10 = block_state1.fst + d * (uint32_t)4U;
        for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
        {
          uint64_t *os = wv_a9;
          uint64_t x1 = wv_a9[i] + wv_b10[i];
          os[i] = x1;
        }
        uint64_t *wv_a10 = block_state1.fst + b1 * (uint32_t)4U;
        uint64_t *wv_b11 = block_state1.fst + c * (uint32_t)4U;
        for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
        {
          uint64_t *os = wv_a10;
          uint64_t x1 = wv_a10[i] ^ wv_b11[i];
          os[i] = x1;
        }
        uint64_t *r118 = wv_a10;
        for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
        {
          uint64_t *os = r118;
          uint64_t x1 = r118[i];
          uint64_t x13 = x1 >> r1 | x1 << ((uint32_t)64U - r1);
          os[i] = x13;
        }
        uint64_t *wv_a11 = block_state1.fst + a0 * (uint32_t)4U;
        uint64_t *wv_b12 = block_state1.fst + b1 * (uint32_t)4U;
        for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
        {
          uint64_t *os = wv_a11;
          uint64_t x1 = wv_a11[i] + wv_b12[i];
          os[i] = x1;
        }
        for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
        {
          uint64_t *os = wv_a11;
          uint64_t x1 = wv_a11[i] + w[i];
          os[i] = x1;
        }
        uint64_t *wv_a12 = block_state1.fst + d * (uint32_t)4U;
        uint64_t *wv_b13 = block_state1.fst + a0 * (uint32_t)4U;
        for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
        {
          uint64_t *os = wv_a12;
          uint64_t x1 = wv_a12[i] ^ wv_b13[i];
          os[i] = x1;
        }
        uint64_t *r119 = wv_a12;
        for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
        {
          uint64_t *os = r119;
          uint64_t x1 = r119[i];
          uint64_t x13 = x1 >> r23 | x1 << ((uint32_t)64U - r23);
          os[i] = x13;
        }
        uint64_t *wv_a13 = block_state1.fst + c * (uint32_t)4U;
        uint64_t *wv_b14 = block_state1.fst + d * (uint32_t)4U;
        for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
        {
          uint64_t *os = wv_a13;
          uint64_t x1 = wv_a13[i] + wv_b14[i];
          os[i] = x1;
        }
        uint64_t *wv_a14 = block_state1.fst + b1 * (uint32_t)4U;
        uint64_t *wv_b = block_state1.fst + c * (uint32_t)4U;
        for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
        {
          uint64_t *os = wv_a14;
          uint64_t x1 = wv_a14[i] ^ wv_b[i];
          os[i] = x1;
        }
        uint64_t *r1110 = wv_a14;
        for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
        {
          uint64_t *os = r1110;
          uint64_t x1 = r1110[i];
          uint64_t x13 = x1 >> r33 | x1 << ((uint32_t)64U - r33);
          os[i] = x13;
        }
        uint64_t *r14 = block_state1.fst + (uint32_t)1U * (uint32_t)4U;
        uint64_t *r2 = block_state1.fst + (uint32_t)2U * (uint32_t)4U;
        uint64_t *r3 = block_state1.fst + (uint32_t)3U * (uint32_t)4U;
        uint64_t *r11 = r14;
        uint64_t x03 = r11[3U];
        uint64_t x13 = r11[((uint32_t)3U + (uint32_t)1U) % (uint32_t)4U];
        uint64_t x23 = r11[((uint32_t)3U + (uint32_t)2U) % (uint32_t)4U];
        uint64_t x33 = r11[((uint32_t)3U + (uint32_t)3U) % (uint32_t)4U];
        r11[0U] = x03;
        r11[1U] = x13;
        r11[2U] = x23;
        r11[3U] = x33;
        uint64_t *r1111 = r2;
        uint64_t x04 = r1111[2U];
        uint64_t x14 = r1111[((uint32_t)2U + (uint32_t)1U) % (uint32_t)4U];
        uint64_t x24 = r1111[((uint32_t)2U + (uint32_t)2U) % (uint32_t)4U];
        uint64_t x34 = r1111[((uint32_t)2U + (uint32_t)3U) % (uint32_t)4U];
        r1111[0U] = x04;
        r1111[1U] = x14;
        r1111[2U] = x24;
        r1111[3U] = x34;
        uint64_t *r1112 = r3;
        uint64_t x0 = r1112[1U];
        uint64_t x1 = r1112[((uint32_t)1U + (uint32_t)1U) % (uint32_t)4U];
        uint64_t x2 = r1112[((uint32_t)1U + (uint32_t)2U) % (uint32_t)4U];
        uint64_t x3 = r1112[((uint32_t)1U + (uint32_t)3U) % (uint32_t)4U];
        r1112[0U] = x0;
        r1112[1U] = x1;
        r1112[2U] = x2;
        r1112[3U] = x3;
      }
      uint64_t *s0 = block_state1.snd + (uint32_t)0U * (uint32_t)4U;
      uint64_t *s11 = block_state1.snd + (uint32_t)1U * (uint32_t)4U;
      uint64_t *r0 = block_state1.fst + (uint32_t)0U * (uint32_t)4U;
      uint64_t *r1 = block_state1.fst + (uint32_t)1U * (uint32_t)4U;
      uint64_t *r2 = block_state1.fst + (uint32_t)2U * (uint32_t)4U;
      uint64_t *r3 = block_state1.fst + (uint32_t)3U * (uint32_t)4U;
      for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
      {
        uint64_t *os = s0;
        uint64_t x = s0[i] ^ r0[i];
        os[i] = x;
      }
      for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
      {
        uint64_t *os = s0;
        uint64_t x = s0[i] ^ r2[i];
        os[i] = x;
      }
      for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
      {
        uint64_t *os = s11;
        uint64_t x = s11[i] ^ r1[i];
        os[i] = x;
      }
      for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
      {
        uint64_t *os = s11;
        uint64_t x = s11[i] ^ r3[i];
        os[i] = x;
      }
    }
  }
  uint32_t ite0;
  if
  (
    (uint64_t)(len - diff)
    % (uint64_t)(uint32_t)128U
    == (uint64_t)0U
    && (uint64_t)(len - diff) > (uint64_t)0U
  )
  {
    ite0 = (uint32_t)128U;
  }
  else
  {
    ite0 = (uint32_t)((uint64_t)(len - diff) % (uint64_t)(uint32_t)128U);
  }
  uint32_t n_blocks = (len - diff - ite0) / (uint32_t)128U;
  uint32_t data1_len = n_blocks * (uint32_t)128U;
  uint32_t data2_len = len - diff - data1_len;
  uint8_t *data11 = data2;
  uint8_t *data21 = data2 + data1_len;
  uint32_t nb = data1_len / (uint32_t)128U;
  for (uint32_t i0 = (uint32_t)0U; i0 < nb; i0++)
  {
    uint64_t ite;
    if (key_size == (uint32_t)0U)
    {
      ite = total_len1;
    }
    else
    {
      ite = total_len1 + (uint64_t)(uint32_t)128U;
    }
    FStar_UInt128_uint128
    totlen =
      FStar_UInt128_add_mod(FStar_UInt128_uint64_to_uint128(ite),
        FStar_UInt128_uint64_to_uint128((uint64_t)((i0 + (uint32_t)1U) * (uint32_t)128U)));
    uint8_t *b = data11 + i0 * (uint32_t)128U;
    uint64_t m_w[16U] = { 0U };
    for (uint32_t i = (uint32_t)0U; i < (uint32_t)16U; i++)
    {
      uint64_t *os = m_w;
      uint8_t *bj = b + i * (uint32_t)8U;
      uint64_t u = load64_le(bj);
      uint64_t r = u;
      uint64_t x = r;
      os[i] = x;
    }
    uint64_t mask[4U] = { 0U };
    uint64_t wv_14 = (uint64_t)0U;
    uint64_t wv_15 = (uint64_t)0U;
    mask[0U] = FStar_UInt128_uint128_to_uint64(totlen);
    mask[1U] = FStar_UInt128_uint128_to_uint64(FStar_UInt128_shift_right(totlen, (uint32_t)64U));
    mask[2U] = wv_14;
    mask[3U] = wv_15;
    memcpy(block_state1.fst,
      block_state1.snd,
      (uint32_t)4U * (uint32_t)4U * sizeof (block_state1.snd[0U]));
    uint64_t *wv3 = block_state1.fst + (uint32_t)3U * (uint32_t)4U;
    for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
    {
      uint64_t *os = wv3;
      uint64_t x = wv3[i] ^ mask[i];
      os[i] = x;
    }
    for (uint32_t i1 = (uint32_t)0U; i1 < (uint32_t)12U; i1++)
    {
      uint32_t start_idx = i1 % (uint32_t)10U * (uint32_t)16U;
      KRML_CHECK_SIZE(sizeof (uint64_t), (uint32_t)4U * (uint32_t)4U);
      uint64_t m_st[(uint32_t)4U * (uint32_t)4U];
      memset(m_st, 0U, (uint32_t)4U * (uint32_t)4U * sizeof (m_st[0U]));
      uint64_t *r00 = m_st + (uint32_t)0U * (uint32_t)4U;
      uint64_t *r10 = m_st + (uint32_t)1U * (uint32_t)4U;
      uint64_t *r20 = m_st + (uint32_t)2U * (uint32_t)4U;
      uint64_t *r30 = m_st + (uint32_t)3U * (uint32_t)4U;
      uint32_t s0 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx];
      uint32_t s11 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)1U];
      uint32_t s21 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)2U];
      uint32_t s3 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)3U];
      uint32_t s4 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)4U];
      uint32_t s5 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)5U];
      uint32_t s6 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)6U];
      uint32_t s7 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)7U];
      uint32_t s8 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)8U];
      uint32_t s9 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)9U];
      uint32_t s10 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)10U];
      uint32_t s111 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)11U];
      uint32_t s12 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)12U];
      uint32_t s13 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)13U];
      uint32_t s14 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)14U];
      uint32_t s15 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)15U];
      uint64_t uu____36 = m_w[s21];
      uint64_t uu____37 = m_w[s4];
      uint64_t uu____38 = m_w[s6];
      r00[0U] = m_w[s0];
      r00[1U] = uu____36;
      r00[2U] = uu____37;
      r00[3U] = uu____38;
      uint64_t uu____39 = m_w[s3];
      uint64_t uu____40 = m_w[s5];
      uint64_t uu____41 = m_w[s7];
      r10[0U] = m_w[s11];
      r10[1U] = uu____39;
      r10[2U] = uu____40;
      r10[3U] = uu____41;
      uint64_t uu____42 = m_w[s10];
      uint64_t uu____43 = m_w[s12];
      uint64_t uu____44 = m_w[s14];
      r20[0U] = m_w[s8];
      r20[1U] = uu____42;
      r20[2U] = uu____43;
      r20[3U] = uu____44;
      uint64_t uu____45 = m_w[s111];
      uint64_t uu____46 = m_w[s13];
      uint64_t uu____47 = m_w[s15];
      r30[0U] = m_w[s9];
      r30[1U] = uu____45;
      r30[2U] = uu____46;
      r30[3U] = uu____47;
      uint64_t *x = m_st + (uint32_t)0U * (uint32_t)4U;
      uint64_t *y = m_st + (uint32_t)1U * (uint32_t)4U;
      uint64_t *z = m_st + (uint32_t)2U * (uint32_t)4U;
      uint64_t *w = m_st + (uint32_t)3U * (uint32_t)4U;
      uint32_t a = (uint32_t)0U;
      uint32_t b10 = (uint32_t)1U;
      uint32_t c0 = (uint32_t)2U;
      uint32_t d0 = (uint32_t)3U;
      uint32_t r01 = Hacl_Impl_Blake2_Constants_rTable_B[0U];
      uint32_t r12 = Hacl_Impl_Blake2_Constants_rTable_B[1U];
      uint32_t r21 = Hacl_Impl_Blake2_Constants_rTable_B[2U];
      uint32_t r31 = Hacl_Impl_Blake2_Constants_rTable_B[3U];
      uint64_t *wv_a0 = block_state1.fst + a * (uint32_t)4U;
      uint64_t *wv_b0 = block_state1.fst + b10 * (uint32_t)4U;
      for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
      {
        uint64_t *os = wv_a0;
        uint64_t x1 = wv_a0[i] + wv_b0[i];
        os[i] = x1;
      }
      for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
      {
        uint64_t *os = wv_a0;
        uint64_t x1 = wv_a0[i] + x[i];
        os[i] = x1;
      }
      uint64_t *wv_a1 = block_state1.fst + d0 * (uint32_t)4U;
      uint64_t *wv_b1 = block_state1.fst + a * (uint32_t)4U;
      for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
      {
        uint64_t *os = wv_a1;
        uint64_t x1 = wv_a1[i] ^ wv_b1[i];
        os[i] = x1;
      }
      uint64_t *r110 = wv_a1;
      for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
      {
        uint64_t *os = r110;
        uint64_t x1 = r110[i];
        uint64_t x10 = x1 >> r01 | x1 << ((uint32_t)64U - r01);
        os[i] = x10;
      }
      uint64_t *wv_a2 = block_state1.fst + c0 * (uint32_t)4U;
      uint64_t *wv_b2 = block_state1.fst + d0 * (uint32_t)4U;
      for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
      {
        uint64_t *os = wv_a2;
        uint64_t x1 = wv_a2[i] + wv_b2[i];
        os[i] = x1;
      }
      uint64_t *wv_a3 = block_state1.fst + b10 * (uint32_t)4U;
      uint64_t *wv_b3 = block_state1.fst + c0 * (uint32_t)4U;
      for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
      {
        uint64_t *os = wv_a3;
        uint64_t x1 = wv_a3[i] ^ wv_b3[i];
        os[i] = x1;
      }
      uint64_t *r111 = wv_a3;
      for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
      {
        uint64_t *os = r111;
        uint64_t x1 = r111[i];
        uint64_t x10 = x1 >> r12 | x1 << ((uint32_t)64U - r12);
        os[i] = x10;
      }
      uint64_t *wv_a4 = block_state1.fst + a * (uint32_t)4U;
      uint64_t *wv_b4 = block_state1.fst + b10 * (uint32_t)4U;
      for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
      {
        uint64_t *os = wv_a4;
        uint64_t x1 = wv_a4[i] + wv_b4[i];
        os[i] = x1;
      }
      for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
      {
        uint64_t *os = wv_a4;
        uint64_t x1 = wv_a4[i] + y[i];
        os[i] = x1;
      }
      uint64_t *wv_a5 = block_state1.fst + d0 * (uint32_t)4U;
      uint64_t *wv_b5 = block_state1.fst + a * (uint32_t)4U;
      for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
      {
        uint64_t *os = wv_a5;
        uint64_t x1 = wv_a5[i] ^ wv_b5[i];
        os[i] = x1;
      }
      uint64_t *r112 = wv_a5;
      for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
      {
        uint64_t *os = r112;
        uint64_t x1 = r112[i];
        uint64_t x10 = x1 >> r21 | x1 << ((uint32_t)64U - r21);
        os[i] = x10;
      }
      uint64_t *wv_a6 = block_state1.fst + c0 * (uint32_t)4U;
      uint64_t *wv_b6 = block_state1.fst + d0 * (uint32_t)4U;
      for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
      {
        uint64_t *os = wv_a6;
        uint64_t x1 = wv_a6[i] + wv_b6[i];
        os[i] = x1;
      }
      uint64_t *wv_a7 = block_state1.fst + b10 * (uint32_t)4U;
      uint64_t *wv_b7 = block_state1.fst + c0 * (uint32_t)4U;
      for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
      {
        uint64_t *os = wv_a7;
        uint64_t x1 = wv_a7[i] ^ wv_b7[i];
        os[i] = x1;
      }
      uint64_t *r113 = wv_a7;
      for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
      {
        uint64_t *os = r113;
        uint64_t x1 = r113[i];
        uint64_t x10 = x1 >> r31 | x1 << ((uint32_t)64U - r31);
        os[i] = x10;
      }
      uint64_t *r13 = block_state1.fst + (uint32_t)1U * (uint32_t)4U;
      uint64_t *r22 = block_state1.fst + (uint32_t)2U * (uint32_t)4U;
      uint64_t *r32 = block_state1.fst + (uint32_t)3U * (uint32_t)4U;
      uint64_t *r114 = r13;
      uint64_t x00 = r114[1U];
      uint64_t x10 = r114[((uint32_t)1U + (uint32_t)1U) % (uint32_t)4U];
      uint64_t x20 = r114[((uint32_t)1U + (uint32_t)2U) % (uint32_t)4U];
      uint64_t x30 = r114[((uint32_t)1U + (uint32_t)3U) % (uint32_t)4U];
      r114[0U] = x00;
      r114[1U] = x10;
      r114[2U] = x20;
      r114[3U] = x30;
      uint64_t *r115 = r22;
      uint64_t x01 = r115[2U];
      uint64_t x11 = r115[((uint32_t)2U + (uint32_t)1U) % (uint32_t)4U];
      uint64_t x21 = r115[((uint32_t)2U + (uint32_t)2U) % (uint32_t)4U];
      uint64_t x31 = r115[((uint32_t)2U + (uint32_t)3U) % (uint32_t)4U];
      r115[0U] = x01;
      r115[1U] = x11;
      r115[2U] = x21;
      r115[3U] = x31;
      uint64_t *r116 = r32;
      uint64_t x02 = r116[3U];
      uint64_t x12 = r116[((uint32_t)3U + (uint32_t)1U) % (uint32_t)4U];
      uint64_t x22 = r116[((uint32_t)3U + (uint32_t)2U) % (uint32_t)4U];
      uint64_t x32 = r116[((uint32_t)3U + (uint32_t)3U) % (uint32_t)4U];
      r116[0U] = x02;
      r116[1U] = x12;
      r116[2U] = x22;
      r116[3U] = x32;
      uint32_t a0 = (uint32_t)0U;
      uint32_t b1 = (uint32_t)1U;
      uint32_t c = (uint32_t)2U;
      uint32_t d = (uint32_t)3U;
      uint32_t r0 = Hacl_Impl_Blake2_Constants_rTable_B[0U];
      uint32_t r1 = Hacl_Impl_Blake2_Constants_rTable_B[1U];
      uint32_t r23 = Hacl_Impl_Blake2_Constants_rTable_B[2U];
      uint32_t r33 = Hacl_Impl_Blake2_Constants_rTable_B[3U];
      uint64_t *wv_a = block_state1.fst + a0 * (uint32_t)4U;
      uint64_t *wv_b8 = block_state1.fst + b1 * (uint32_t)4U;
      for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
      {
        uint64_t *os = wv_a;
        uint64_t x1 = wv_a[i] + wv_b8[i];
        os[i] = x1;
      }
      for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
      {
        uint64_t *os = wv_a;
        uint64_t x1 = wv_a[i] + z[i];
        os[i] = x1;
      }
      uint64_t *wv_a8 = block_state1.fst + d * (uint32_t)4U;
      uint64_t *wv_b9 = block_state1.fst + a0 * (uint32_t)4U;
      for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
      {
        uint64_t *os = wv_a8;
        uint64_t x1 = wv_a8[i] ^ wv_b9[i];
        os[i] = x1;
      }
      uint64_t *r117 = wv_a8;
      for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
      {
        uint64_t *os = r117;
        uint64_t x1 = r117[i];
        uint64_t x13 = x1 >> r0 | x1 << ((uint32_t)64U - r0);
        os[i] = x13;
      }
      uint64_t *wv_a9 = block_state1.fst + c * (uint32_t)4U;
      uint64_t *wv_b10 = block_state1.fst + d * (uint32_t)4U;
      for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
      {
        uint64_t *os = wv_a9;
        uint64_t x1 = wv_a9[i] + wv_b10[i];
        os[i] = x1;
      }
      uint64_t *wv_a10 = block_state1.fst + b1 * (uint32_t)4U;
      uint64_t *wv_b11 = block_state1.fst + c * (uint32_t)4U;
      for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
      {
        uint64_t *os = wv_a10;
        uint64_t x1 = wv_a10[i] ^ wv_b11[i];
        os[i] = x1;
      }
      uint64_t *r118 = wv_a10;
      for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
      {
        uint64_t *os = r118;
        uint64_t x1 = r118[i];
        uint64_t x13 = x1 >> r1 | x1 << ((uint32_t)64U - r1);
        os[i] = x13;
      }
      uint64_t *wv_a11 = block_state1.fst + a0 * (uint32_t)4U;
      uint64_t *wv_b12 = block_state1.fst + b1 * (uint32_t)4U;
      for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
      {
        uint64_t *os = wv_a11;
        uint64_t x1 = wv_a11[i] + wv_b12[i];
        os[i] = x1;
      }
      for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
      {
        uint64_t *os = wv_a11;
        uint64_t x1 = wv_a11[i] + w[i];
        os[i] = x1;
      }
      uint64_t *wv_a12 = block_state1.fst + d * (uint32_t)4U;
      uint64_t *wv_b13 = block_state1.fst + a0 * (uint32_t)4U;
      for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
      {
        uint64_t *os = wv_a12;
        uint64_t x1 = wv_a12[i] ^ wv_b13[i];
        os[i] = x1;
      }
      uint64_t *r119 = wv_a12;
      for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
      {
        uint64_t *os = r119;
        uint64_t x1 = r119[i];
        uint64_t x13 = x1 >> r23 | x1 << ((uint32_t)64U - r23);
        os[i] = x13;
      }
      uint64_t *wv_a13 = block_state1.fst + c * (uint32_t)4U;
      uint64_t *wv_b14 = block_state1.fst + d * (uint32_t)4U;
      for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
      {
        uint64_t *os = wv_a13;
        uint64_t x1 = wv_a13[i] + wv_b14[i];
        os[i] = x1;
      }
      uint64_t *wv_a14 = block_state1.fst + b1 * (uint32_t)4U;
      uint64_t *wv_b = block_state1.fst + c * (uint32_t)4U;
      for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
      {
        uint64_t *os = wv_a14;
        uint64_t x1 = wv_a14[i] ^ wv_b[i];
        os[i] = x1;
      }
      uint64_t *r1110 = wv_a14;
      for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
      {
        uint64_t *os = r1110;
        uint64_t x1 = r1110[i];
        uint64_t x13 = x1 >> r33 | x1 << ((uint32_t)64U - r33);
        os[i] = x13;
      }
      uint64_t *r14 = block_state1.fst + (uint32_t)1U * (uint32_t)4U;
      uint64_t *r2 = block_state1.fst + (uint32_t)2U * (uint32_t)4U;
      uint64_t *r3 = block_state1.fst + (uint32_t)3U * (uint32_t)4U;
      uint64_t *r11 = r14;
      uint64_t x03 = r11[3U];
      uint64_t x13 = r11[((uint32_t)3U + (uint32_t)1U) % (uint32_t)4U];
      uint64_t x23 = r11[((uint32_t)3U + (uint32_t)2U) % (uint32_t)4U];
      uint64_t x33 = r11[((uint32_t)3U + (uint32_t)3U) % (uint32_t)4U];
      r11[0U] = x03;
      r11[1U] = x13;
      r11[2U] = x23;
      r11[3U] = x33;
      uint64_t *r1111 = r2;
      uint64_t x04 = r1111[2U];
      uint64_t x14 = r1111[((uint32_t)2U + (uint32_t)1U) % (uint32_t)4U];
      uint64_t x24 = r1111[((uint32_t)2U + (uint32_t)2U) % (uint32_t)4U];
      uint64_t x34 = r1111[((uint32_t)2U + (uint32_t)3U) % (uint32_t)4U];
      r1111[0U] = x04;
      r1111[1U] = x14;
      r1111[2U] = x24;
      r1111[3U] = x34;
      uint64_t *r1112 = r3;
      uint64_t x0 = r1112[1U];
      uint64_t x1 = r1112[((uint32_t)1U + (uint32_t)1U) % (uint32_t)4U];
      uint64_t x2 = r1112[((uint32_t)1U + (uint32_t)2U) % (uint32_t)4U];
      uint64_t x3 = r1112[((uint32_t)1U + (uint32_t)3U) % (uint32_t)4U];
      r1112[0U] = x0;
      r1112[1U] = x1;
      r1112[2U] = x2;
      r1112[3U] = x3;
    }
    uint64_t *s0 = block_state1.snd + (uint32_t)0U * (uint32_t)4U;
    uint64_t *s11 = block_state1.snd + (uint32_t)1U * (uint32_t)4U;
    uint64_t *r0 = block_state1.fst + (uint32_t)0U * (uint32_t)4U;
    uint64_t *r1 = block_state1.fst + (uint32_t)1U * (uint32_t)4U;
    uint64_t *r2 = block_state1.fst + (uint32_t)2U * (uint32_t)4U;
    uint64_t *r3 = block_state1.fst + (uint32_t)3U * (uint32_t)4U;
    for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
    {
      uint64_t *os = s0;
      uint64_t x = s0[i] ^ r0[i];
      os[i] = x;
    }
    for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
    {
      uint64_t *os = s0;
      uint64_t x = s0[i] ^ r2[i];
      os[i] = x;
    }
    for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
    {
      uint64_t *os = s11;
      uint64_t x = s11[i] ^ r1[i];
      os[i] = x;
    }
    for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
    {
      uint64_t *os = s11;
      uint64_t x = s11[i] ^ r3[i];
      os[i] = x;
    }
  }
  uint8_t *dst = buf;
  memcpy(dst, data21, data2_len * sizeof (data21[0U]));
  *p
  =
    (
      (Hacl_Streaming_Functor_state_s__K____uint64_t___uint64_t____){
        .block_state = block_state1,
        .buf = buf,
        .total_len = total_len1 + (uint64_t)(len - diff)
      }
    );
}

/* SNIPPET_END: Hacl_Streaming_Blake2_blake2b_32_with_key_update */

/* SNIPPET_START: Hacl_Streaming_Blake2_blake2b_32_with_key_finish */

/*
  Finish function when using a (potentially null) key
*/
void
Hacl_Streaming_Blake2_blake2b_32_with_key_finish(
  uint32_t key_size,
  Hacl_Streaming_Functor_state_s__K____uint64_t___uint64_t____ *p,
  uint8_t *dst
)
{
  Hacl_Streaming_Functor_state_s__K____uint64_t___uint64_t____ scrut = *p;
  K____uint64_t___uint64_t_ block_state = scrut.block_state;
  uint8_t *buf_ = scrut.buf;
  uint64_t total_len = scrut.total_len;
  uint32_t r;
  if (total_len % (uint64_t)(uint32_t)128U == (uint64_t)0U && total_len > (uint64_t)0U)
  {
    r = (uint32_t)128U;
  }
  else
  {
    r = (uint32_t)(total_len % (uint64_t)(uint32_t)128U);
  }
  uint8_t *buf_1 = buf_;
  KRML_CHECK_SIZE(sizeof (uint64_t), (uint32_t)4U * (uint32_t)4U);
  uint64_t wv[(uint32_t)4U * (uint32_t)4U];
  memset(wv, 0U, (uint32_t)4U * (uint32_t)4U * sizeof (wv[0U]));
  KRML_CHECK_SIZE(sizeof (uint64_t), (uint32_t)4U * (uint32_t)4U);
  uint64_t b0[(uint32_t)4U * (uint32_t)4U];
  memset(b0, 0U, (uint32_t)4U * (uint32_t)4U * sizeof (b0[0U]));
  K____uint64_t___uint64_t_ tmp_block_state = { .fst = wv, .snd = b0 };
  uint64_t *src_b = block_state.snd;
  uint64_t *dst_b = tmp_block_state.snd;
  memcpy(dst_b, src_b, (uint32_t)16U * sizeof (src_b[0U]));
  uint64_t prev_len = total_len - (uint64_t)r;
  uint8_t b2[128U] = { 0U };
  uint8_t *last = buf_1 + r - r;
  memcpy(b2, last, r * sizeof (last[0U]));
  uint64_t ite;
  if (key_size == (uint32_t)0U)
  {
    ite = prev_len;
  }
  else
  {
    ite = prev_len + (uint64_t)(uint32_t)128U;
  }
  FStar_UInt128_uint128
  totlen =
    FStar_UInt128_add_mod(FStar_UInt128_uint64_to_uint128(ite),
      FStar_UInt128_uint64_to_uint128((uint64_t)r));
  uint64_t m_w[16U] = { 0U };
  for (uint32_t i = (uint32_t)0U; i < (uint32_t)16U; i++)
  {
    uint64_t *os = m_w;
    uint8_t *bj = b2 + i * (uint32_t)8U;
    uint64_t u = load64_le(bj);
    uint64_t r1 = u;
    uint64_t x = r1;
    os[i] = x;
  }
  uint64_t mask[4U] = { 0U };
  uint64_t wv_14 = (uint64_t)0xFFFFFFFFFFFFFFFFU;
  uint64_t wv_15 = (uint64_t)0U;
  mask[0U] = FStar_UInt128_uint128_to_uint64(totlen);
  mask[1U] = FStar_UInt128_uint128_to_uint64(FStar_UInt128_shift_right(totlen, (uint32_t)64U));
  mask[2U] = wv_14;
  mask[3U] = wv_15;
  memcpy(tmp_block_state.fst,
    tmp_block_state.snd,
    (uint32_t)4U * (uint32_t)4U * sizeof (tmp_block_state.snd[0U]));
  uint64_t *wv3 = tmp_block_state.fst + (uint32_t)3U * (uint32_t)4U;
  for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
  {
    uint64_t *os = wv3;
    uint64_t x = wv3[i] ^ mask[i];
    os[i] = x;
  }
  for (uint32_t i0 = (uint32_t)0U; i0 < (uint32_t)12U; i0++)
  {
    uint32_t start_idx = i0 % (uint32_t)10U * (uint32_t)16U;
    KRML_CHECK_SIZE(sizeof (uint64_t), (uint32_t)4U * (uint32_t)4U);
    uint64_t m_st[(uint32_t)4U * (uint32_t)4U];
    memset(m_st, 0U, (uint32_t)4U * (uint32_t)4U * sizeof (m_st[0U]));
    uint64_t *r00 = m_st + (uint32_t)0U * (uint32_t)4U;
    uint64_t *r10 = m_st + (uint32_t)1U * (uint32_t)4U;
    uint64_t *r20 = m_st + (uint32_t)2U * (uint32_t)4U;
    uint64_t *r30 = m_st + (uint32_t)3U * (uint32_t)4U;
    uint32_t s0 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx];
    uint32_t s1 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)1U];
    uint32_t s2 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)2U];
    uint32_t s3 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)3U];
    uint32_t s4 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)4U];
    uint32_t s5 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)5U];
    uint32_t s6 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)6U];
    uint32_t s7 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)7U];
    uint32_t s8 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)8U];
    uint32_t s9 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)9U];
    uint32_t s10 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)10U];
    uint32_t s11 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)11U];
    uint32_t s12 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)12U];
    uint32_t s13 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)13U];
    uint32_t s14 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)14U];
    uint32_t s15 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)15U];
    uint64_t uu____0 = m_w[s2];
    uint64_t uu____1 = m_w[s4];
    uint64_t uu____2 = m_w[s6];
    r00[0U] = m_w[s0];
    r00[1U] = uu____0;
    r00[2U] = uu____1;
    r00[3U] = uu____2;
    uint64_t uu____3 = m_w[s3];
    uint64_t uu____4 = m_w[s5];
    uint64_t uu____5 = m_w[s7];
    r10[0U] = m_w[s1];
    r10[1U] = uu____3;
    r10[2U] = uu____4;
    r10[3U] = uu____5;
    uint64_t uu____6 = m_w[s10];
    uint64_t uu____7 = m_w[s12];
    uint64_t uu____8 = m_w[s14];
    r20[0U] = m_w[s8];
    r20[1U] = uu____6;
    r20[2U] = uu____7;
    r20[3U] = uu____8;
    uint64_t uu____9 = m_w[s11];
    uint64_t uu____10 = m_w[s13];
    uint64_t uu____11 = m_w[s15];
    r30[0U] = m_w[s9];
    r30[1U] = uu____9;
    r30[2U] = uu____10;
    r30[3U] = uu____11;
    uint64_t *x = m_st + (uint32_t)0U * (uint32_t)4U;
    uint64_t *y = m_st + (uint32_t)1U * (uint32_t)4U;
    uint64_t *z = m_st + (uint32_t)2U * (uint32_t)4U;
    uint64_t *w = m_st + (uint32_t)3U * (uint32_t)4U;
    uint32_t a = (uint32_t)0U;
    uint32_t b10 = (uint32_t)1U;
    uint32_t c0 = (uint32_t)2U;
    uint32_t d0 = (uint32_t)3U;
    uint32_t r01 = Hacl_Impl_Blake2_Constants_rTable_B[0U];
    uint32_t r12 = Hacl_Impl_Blake2_Constants_rTable_B[1U];
    uint32_t r21 = Hacl_Impl_Blake2_Constants_rTable_B[2U];
    uint32_t r31 = Hacl_Impl_Blake2_Constants_rTable_B[3U];
    uint64_t *wv_a0 = tmp_block_state.fst + a * (uint32_t)4U;
    uint64_t *wv_b0 = tmp_block_state.fst + b10 * (uint32_t)4U;
    for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
    {
      uint64_t *os = wv_a0;
      uint64_t x1 = wv_a0[i] + wv_b0[i];
      os[i] = x1;
    }
    for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
    {
      uint64_t *os = wv_a0;
      uint64_t x1 = wv_a0[i] + x[i];
      os[i] = x1;
    }
    uint64_t *wv_a1 = tmp_block_state.fst + d0 * (uint32_t)4U;
    uint64_t *wv_b1 = tmp_block_state.fst + a * (uint32_t)4U;
    for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
    {
      uint64_t *os = wv_a1;
      uint64_t x1 = wv_a1[i] ^ wv_b1[i];
      os[i] = x1;
    }
    uint64_t *r110 = wv_a1;
    for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
    {
      uint64_t *os = r110;
      uint64_t x1 = r110[i];
      uint64_t x10 = x1 >> r01 | x1 << ((uint32_t)64U - r01);
      os[i] = x10;
    }
    uint64_t *wv_a2 = tmp_block_state.fst + c0 * (uint32_t)4U;
    uint64_t *wv_b2 = tmp_block_state.fst + d0 * (uint32_t)4U;
    for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
    {
      uint64_t *os = wv_a2;
      uint64_t x1 = wv_a2[i] + wv_b2[i];
      os[i] = x1;
    }
    uint64_t *wv_a3 = tmp_block_state.fst + b10 * (uint32_t)4U;
    uint64_t *wv_b3 = tmp_block_state.fst + c0 * (uint32_t)4U;
    for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
    {
      uint64_t *os = wv_a3;
      uint64_t x1 = wv_a3[i] ^ wv_b3[i];
      os[i] = x1;
    }
    uint64_t *r111 = wv_a3;
    for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
    {
      uint64_t *os = r111;
      uint64_t x1 = r111[i];
      uint64_t x10 = x1 >> r12 | x1 << ((uint32_t)64U - r12);
      os[i] = x10;
    }
    uint64_t *wv_a4 = tmp_block_state.fst + a * (uint32_t)4U;
    uint64_t *wv_b4 = tmp_block_state.fst + b10 * (uint32_t)4U;
    for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
    {
      uint64_t *os = wv_a4;
      uint64_t x1 = wv_a4[i] + wv_b4[i];
      os[i] = x1;
    }
    for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
    {
      uint64_t *os = wv_a4;
      uint64_t x1 = wv_a4[i] + y[i];
      os[i] = x1;
    }
    uint64_t *wv_a5 = tmp_block_state.fst + d0 * (uint32_t)4U;
    uint64_t *wv_b5 = tmp_block_state.fst + a * (uint32_t)4U;
    for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
    {
      uint64_t *os = wv_a5;
      uint64_t x1 = wv_a5[i] ^ wv_b5[i];
      os[i] = x1;
    }
    uint64_t *r112 = wv_a5;
    for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
    {
      uint64_t *os = r112;
      uint64_t x1 = r112[i];
      uint64_t x10 = x1 >> r21 | x1 << ((uint32_t)64U - r21);
      os[i] = x10;
    }
    uint64_t *wv_a6 = tmp_block_state.fst + c0 * (uint32_t)4U;
    uint64_t *wv_b6 = tmp_block_state.fst + d0 * (uint32_t)4U;
    for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
    {
      uint64_t *os = wv_a6;
      uint64_t x1 = wv_a6[i] + wv_b6[i];
      os[i] = x1;
    }
    uint64_t *wv_a7 = tmp_block_state.fst + b10 * (uint32_t)4U;
    uint64_t *wv_b7 = tmp_block_state.fst + c0 * (uint32_t)4U;
    for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
    {
      uint64_t *os = wv_a7;
      uint64_t x1 = wv_a7[i] ^ wv_b7[i];
      os[i] = x1;
    }
    uint64_t *r113 = wv_a7;
    for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
    {
      uint64_t *os = r113;
      uint64_t x1 = r113[i];
      uint64_t x10 = x1 >> r31 | x1 << ((uint32_t)64U - r31);
      os[i] = x10;
    }
    uint64_t *r13 = tmp_block_state.fst + (uint32_t)1U * (uint32_t)4U;
    uint64_t *r22 = tmp_block_state.fst + (uint32_t)2U * (uint32_t)4U;
    uint64_t *r32 = tmp_block_state.fst + (uint32_t)3U * (uint32_t)4U;
    uint64_t *r114 = r13;
    uint64_t x00 = r114[1U];
    uint64_t x10 = r114[((uint32_t)1U + (uint32_t)1U) % (uint32_t)4U];
    uint64_t x20 = r114[((uint32_t)1U + (uint32_t)2U) % (uint32_t)4U];
    uint64_t x30 = r114[((uint32_t)1U + (uint32_t)3U) % (uint32_t)4U];
    r114[0U] = x00;
    r114[1U] = x10;
    r114[2U] = x20;
    r114[3U] = x30;
    uint64_t *r115 = r22;
    uint64_t x01 = r115[2U];
    uint64_t x11 = r115[((uint32_t)2U + (uint32_t)1U) % (uint32_t)4U];
    uint64_t x21 = r115[((uint32_t)2U + (uint32_t)2U) % (uint32_t)4U];
    uint64_t x31 = r115[((uint32_t)2U + (uint32_t)3U) % (uint32_t)4U];
    r115[0U] = x01;
    r115[1U] = x11;
    r115[2U] = x21;
    r115[3U] = x31;
    uint64_t *r116 = r32;
    uint64_t x02 = r116[3U];
    uint64_t x12 = r116[((uint32_t)3U + (uint32_t)1U) % (uint32_t)4U];
    uint64_t x22 = r116[((uint32_t)3U + (uint32_t)2U) % (uint32_t)4U];
    uint64_t x32 = r116[((uint32_t)3U + (uint32_t)3U) % (uint32_t)4U];
    r116[0U] = x02;
    r116[1U] = x12;
    r116[2U] = x22;
    r116[3U] = x32;
    uint32_t a0 = (uint32_t)0U;
    uint32_t b1 = (uint32_t)1U;
    uint32_t c = (uint32_t)2U;
    uint32_t d = (uint32_t)3U;
    uint32_t r0 = Hacl_Impl_Blake2_Constants_rTable_B[0U];
    uint32_t r1 = Hacl_Impl_Blake2_Constants_rTable_B[1U];
    uint32_t r23 = Hacl_Impl_Blake2_Constants_rTable_B[2U];
    uint32_t r33 = Hacl_Impl_Blake2_Constants_rTable_B[3U];
    uint64_t *wv_a = tmp_block_state.fst + a0 * (uint32_t)4U;
    uint64_t *wv_b8 = tmp_block_state.fst + b1 * (uint32_t)4U;
    for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
    {
      uint64_t *os = wv_a;
      uint64_t x1 = wv_a[i] + wv_b8[i];
      os[i] = x1;
    }
    for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
    {
      uint64_t *os = wv_a;
      uint64_t x1 = wv_a[i] + z[i];
      os[i] = x1;
    }
    uint64_t *wv_a8 = tmp_block_state.fst + d * (uint32_t)4U;
    uint64_t *wv_b9 = tmp_block_state.fst + a0 * (uint32_t)4U;
    for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
    {
      uint64_t *os = wv_a8;
      uint64_t x1 = wv_a8[i] ^ wv_b9[i];
      os[i] = x1;
    }
    uint64_t *r117 = wv_a8;
    for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
    {
      uint64_t *os = r117;
      uint64_t x1 = r117[i];
      uint64_t x13 = x1 >> r0 | x1 << ((uint32_t)64U - r0);
      os[i] = x13;
    }
    uint64_t *wv_a9 = tmp_block_state.fst + c * (uint32_t)4U;
    uint64_t *wv_b10 = tmp_block_state.fst + d * (uint32_t)4U;
    for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
    {
      uint64_t *os = wv_a9;
      uint64_t x1 = wv_a9[i] + wv_b10[i];
      os[i] = x1;
    }
    uint64_t *wv_a10 = tmp_block_state.fst + b1 * (uint32_t)4U;
    uint64_t *wv_b11 = tmp_block_state.fst + c * (uint32_t)4U;
    for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
    {
      uint64_t *os = wv_a10;
      uint64_t x1 = wv_a10[i] ^ wv_b11[i];
      os[i] = x1;
    }
    uint64_t *r118 = wv_a10;
    for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
    {
      uint64_t *os = r118;
      uint64_t x1 = r118[i];
      uint64_t x13 = x1 >> r1 | x1 << ((uint32_t)64U - r1);
      os[i] = x13;
    }
    uint64_t *wv_a11 = tmp_block_state.fst + a0 * (uint32_t)4U;
    uint64_t *wv_b12 = tmp_block_state.fst + b1 * (uint32_t)4U;
    for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
    {
      uint64_t *os = wv_a11;
      uint64_t x1 = wv_a11[i] + wv_b12[i];
      os[i] = x1;
    }
    for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
    {
      uint64_t *os = wv_a11;
      uint64_t x1 = wv_a11[i] + w[i];
      os[i] = x1;
    }
    uint64_t *wv_a12 = tmp_block_state.fst + d * (uint32_t)4U;
    uint64_t *wv_b13 = tmp_block_state.fst + a0 * (uint32_t)4U;
    for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
    {
      uint64_t *os = wv_a12;
      uint64_t x1 = wv_a12[i] ^ wv_b13[i];
      os[i] = x1;
    }
    uint64_t *r119 = wv_a12;
    for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
    {
      uint64_t *os = r119;
      uint64_t x1 = r119[i];
      uint64_t x13 = x1 >> r23 | x1 << ((uint32_t)64U - r23);
      os[i] = x13;
    }
    uint64_t *wv_a13 = tmp_block_state.fst + c * (uint32_t)4U;
    uint64_t *wv_b14 = tmp_block_state.fst + d * (uint32_t)4U;
    for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
    {
      uint64_t *os = wv_a13;
      uint64_t x1 = wv_a13[i] + wv_b14[i];
      os[i] = x1;
    }
    uint64_t *wv_a14 = tmp_block_state.fst + b1 * (uint32_t)4U;
    uint64_t *wv_b = tmp_block_state.fst + c * (uint32_t)4U;
    for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
    {
      uint64_t *os = wv_a14;
      uint64_t x1 = wv_a14[i] ^ wv_b[i];
      os[i] = x1;
    }
    uint64_t *r1110 = wv_a14;
    for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
    {
      uint64_t *os = r1110;
      uint64_t x1 = r1110[i];
      uint64_t x13 = x1 >> r33 | x1 << ((uint32_t)64U - r33);
      os[i] = x13;
    }
    uint64_t *r14 = tmp_block_state.fst + (uint32_t)1U * (uint32_t)4U;
    uint64_t *r2 = tmp_block_state.fst + (uint32_t)2U * (uint32_t)4U;
    uint64_t *r3 = tmp_block_state.fst + (uint32_t)3U * (uint32_t)4U;
    uint64_t *r11 = r14;
    uint64_t x03 = r11[3U];
    uint64_t x13 = r11[((uint32_t)3U + (uint32_t)1U) % (uint32_t)4U];
    uint64_t x23 = r11[((uint32_t)3U + (uint32_t)2U) % (uint32_t)4U];
    uint64_t x33 = r11[((uint32_t)3U + (uint32_t)3U) % (uint32_t)4U];
    r11[0U] = x03;
    r11[1U] = x13;
    r11[2U] = x23;
    r11[3U] = x33;
    uint64_t *r1111 = r2;
    uint64_t x04 = r1111[2U];
    uint64_t x14 = r1111[((uint32_t)2U + (uint32_t)1U) % (uint32_t)4U];
    uint64_t x24 = r1111[((uint32_t)2U + (uint32_t)2U) % (uint32_t)4U];
    uint64_t x34 = r1111[((uint32_t)2U + (uint32_t)3U) % (uint32_t)4U];
    r1111[0U] = x04;
    r1111[1U] = x14;
    r1111[2U] = x24;
    r1111[3U] = x34;
    uint64_t *r1112 = r3;
    uint64_t x0 = r1112[1U];
    uint64_t x1 = r1112[((uint32_t)1U + (uint32_t)1U) % (uint32_t)4U];
    uint64_t x2 = r1112[((uint32_t)1U + (uint32_t)2U) % (uint32_t)4U];
    uint64_t x3 = r1112[((uint32_t)1U + (uint32_t)3U) % (uint32_t)4U];
    r1112[0U] = x0;
    r1112[1U] = x1;
    r1112[2U] = x2;
    r1112[3U] = x3;
  }
  uint64_t *s0 = tmp_block_state.snd + (uint32_t)0U * (uint32_t)4U;
  uint64_t *s1 = tmp_block_state.snd + (uint32_t)1U * (uint32_t)4U;
  uint64_t *r0 = tmp_block_state.fst + (uint32_t)0U * (uint32_t)4U;
  uint64_t *r1 = tmp_block_state.fst + (uint32_t)1U * (uint32_t)4U;
  uint64_t *r2 = tmp_block_state.fst + (uint32_t)2U * (uint32_t)4U;
  uint64_t *r3 = tmp_block_state.fst + (uint32_t)3U * (uint32_t)4U;
  for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
  {
    uint64_t *os = s0;
    uint64_t x = s0[i] ^ r0[i];
    os[i] = x;
  }
  for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
  {
    uint64_t *os = s0;
    uint64_t x = s0[i] ^ r2[i];
    os[i] = x;
  }
  for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
  {
    uint64_t *os = s1;
    uint64_t x = s1[i] ^ r1[i];
    os[i] = x;
  }
  for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
  {
    uint64_t *os = s1;
    uint64_t x = s1[i] ^ r3[i];
    os[i] = x;
  }
  Lib_Memzero0_memzero(b2, (uint32_t)128U * sizeof (b2[0U]));
  uint32_t double_row = (uint32_t)2U * (uint32_t)4U * (uint32_t)8U;
  KRML_CHECK_SIZE(sizeof (uint8_t), double_row);
  uint8_t b[double_row];
  memset(b, 0U, double_row * sizeof (b[0U]));
  uint8_t *first = b;
  uint8_t *second = b + (uint32_t)4U * (uint32_t)8U;
  uint64_t *row0 = tmp_block_state.snd + (uint32_t)0U * (uint32_t)4U;
  uint64_t *row1 = tmp_block_state.snd + (uint32_t)1U * (uint32_t)4U;
  for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
  {
    store64_le(first + i * (uint32_t)8U, row0[i]);
  }
  for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
  {
    store64_le(second + i * (uint32_t)8U, row1[i]);
  }
  uint8_t *final = b;
  memcpy(dst, final, (uint32_t)64U * sizeof (final[0U]));
  Lib_Memzero0_memzero(b, double_row * sizeof (b[0U]));
}

/* SNIPPET_END: Hacl_Streaming_Blake2_blake2b_32_with_key_finish */

/* SNIPPET_START: Hacl_Streaming_Blake2_blake2b_32_with_key_free */

/*
  Free state function when using a (potentially null) key
*/
void
Hacl_Streaming_Blake2_blake2b_32_with_key_free(
  uint32_t key_size,
  Hacl_Streaming_Functor_state_s__K____uint64_t___uint64_t____ *s1
)
{
  Hacl_Streaming_Functor_state_s__K____uint64_t___uint64_t____ scrut = *s1;
  uint8_t *buf = scrut.buf;
  K____uint64_t___uint64_t_ block_state = scrut.block_state;
  uint64_t *wv = block_state.fst;
  uint64_t *b = block_state.snd;
  KRML_HOST_FREE(wv);
  KRML_HOST_FREE(b);
  KRML_HOST_FREE(buf);
  KRML_HOST_FREE(s1);
}

/* SNIPPET_END: Hacl_Streaming_Blake2_blake2b_32_with_key_free */

/* SNIPPET_START: Hacl_Streaming_Blake2_blake2b_256_with_key_create_in */

/*
  State allocation function when using a (potentially null) key
*/
Hacl_Streaming_Functor_state_s__K____Lib_IntVector_Intrinsics_vec256___Lib_IntVector_Intrinsics_vec256____
*Hacl_Streaming_Blake2_blake2b_256_with_key_create_in(uint32_t key_size, uint8_t *k1)
{
  uint8_t *buf = KRML_HOST_CALLOC((uint32_t)128U, sizeof (uint8_t));
  Lib_IntVector_Intrinsics_vec256
  *wv = KRML_HOST_MALLOC(sizeof (Lib_IntVector_Intrinsics_vec256) * (uint32_t)4U);
  for (uint32_t _i = 0U; _i < (uint32_t)4U; ++_i)
    wv[_i] = Lib_IntVector_Intrinsics_vec256_zero;
  Lib_IntVector_Intrinsics_vec256
  *b0 = KRML_HOST_MALLOC(sizeof (Lib_IntVector_Intrinsics_vec256) * (uint32_t)4U);
  for (uint32_t _i = 0U; _i < (uint32_t)4U; ++_i)
    b0[_i] = Lib_IntVector_Intrinsics_vec256_zero;
  K____Lib_IntVector_Intrinsics_vec256___Lib_IntVector_Intrinsics_vec256_
  block_state = { .fst = wv, .snd = b0 };
  Hacl_Streaming_Functor_state_s__K____Lib_IntVector_Intrinsics_vec256___Lib_IntVector_Intrinsics_vec256____
  s1 = { .block_state = block_state, .buf = buf, .total_len = (uint64_t)0U };
  KRML_CHECK_SIZE(sizeof (
      Hacl_Streaming_Functor_state_s__K____Lib_IntVector_Intrinsics_vec256___Lib_IntVector_Intrinsics_vec256____
    ),
    (uint32_t)1U);
  Hacl_Streaming_Functor_state_s__K____Lib_IntVector_Intrinsics_vec256___Lib_IntVector_Intrinsics_vec256____
  *p =
    KRML_HOST_MALLOC(sizeof (
        Hacl_Streaming_Functor_state_s__K____Lib_IntVector_Intrinsics_vec256___Lib_IntVector_Intrinsics_vec256____
      ));
  p[0U] = s1;
  uint8_t b[128U] = { 0U };
  Lib_IntVector_Intrinsics_vec256 *r00 = block_state.snd + (uint32_t)0U * (uint32_t)1U;
  Lib_IntVector_Intrinsics_vec256 *r10 = block_state.snd + (uint32_t)1U * (uint32_t)1U;
  Lib_IntVector_Intrinsics_vec256 *r20 = block_state.snd + (uint32_t)2U * (uint32_t)1U;
  Lib_IntVector_Intrinsics_vec256 *r30 = block_state.snd + (uint32_t)3U * (uint32_t)1U;
  uint64_t iv0 = Hacl_Impl_Blake2_Constants_ivTable_B[0U];
  uint64_t iv1 = Hacl_Impl_Blake2_Constants_ivTable_B[1U];
  uint64_t iv2 = Hacl_Impl_Blake2_Constants_ivTable_B[2U];
  uint64_t iv3 = Hacl_Impl_Blake2_Constants_ivTable_B[3U];
  uint64_t iv4 = Hacl_Impl_Blake2_Constants_ivTable_B[4U];
  uint64_t iv5 = Hacl_Impl_Blake2_Constants_ivTable_B[5U];
  uint64_t iv6 = Hacl_Impl_Blake2_Constants_ivTable_B[6U];
  uint64_t iv7 = Hacl_Impl_Blake2_Constants_ivTable_B[7U];
  r20[0U] = Lib_IntVector_Intrinsics_vec256_load64s(iv0, iv1, iv2, iv3);
  r30[0U] = Lib_IntVector_Intrinsics_vec256_load64s(iv4, iv5, iv6, iv7);
  uint64_t kk_shift_8 = (uint64_t)key_size << (uint32_t)8U;
  uint64_t iv0_ = iv0 ^ ((uint64_t)0x01010000U ^ (kk_shift_8 ^ (uint64_t)(uint32_t)64U));
  r00[0U] = Lib_IntVector_Intrinsics_vec256_load64s(iv0_, iv1, iv2, iv3);
  r10[0U] = Lib_IntVector_Intrinsics_vec256_load64s(iv4, iv5, iv6, iv7);
  if (!(key_size == (uint32_t)0U))
  {
    memcpy(b, k1, key_size * sizeof (k1[0U]));
    FStar_UInt128_uint128
    totlen =
      FStar_UInt128_add_mod(FStar_UInt128_uint64_to_uint128((uint64_t)(uint32_t)0U),
        FStar_UInt128_uint64_to_uint128((uint64_t)(uint32_t)128U));
    uint8_t *b1 = b + (uint32_t)0U * (uint32_t)128U;
    uint64_t m_w[16U] = { 0U };
    for (uint32_t i = (uint32_t)0U; i < (uint32_t)16U; i++)
    {
      uint64_t *os = m_w;
      uint8_t *bj = b1 + i * (uint32_t)8U;
      uint64_t u = load64_le(bj);
      uint64_t r1 = u;
      uint64_t x = r1;
      os[i] = x;
    }
    Lib_IntVector_Intrinsics_vec256 mask = Lib_IntVector_Intrinsics_vec256_zero;
    uint64_t wv_14 = (uint64_t)0U;
    uint64_t wv_15 = (uint64_t)0U;
    mask =
      Lib_IntVector_Intrinsics_vec256_load64s(FStar_UInt128_uint128_to_uint64(totlen),
        FStar_UInt128_uint128_to_uint64(FStar_UInt128_shift_right(totlen, (uint32_t)64U)),
        wv_14,
        wv_15);
    memcpy(block_state.fst,
      block_state.snd,
      (uint32_t)4U * (uint32_t)1U * sizeof (block_state.snd[0U]));
    Lib_IntVector_Intrinsics_vec256 *wv3 = block_state.fst + (uint32_t)3U * (uint32_t)1U;
    wv3[0U] = Lib_IntVector_Intrinsics_vec256_xor(wv3[0U], mask);
    for (uint32_t i = (uint32_t)0U; i < (uint32_t)12U; i++)
    {
      uint32_t start_idx = i % (uint32_t)10U * (uint32_t)16U;
      KRML_CHECK_SIZE(sizeof (Lib_IntVector_Intrinsics_vec256), (uint32_t)4U * (uint32_t)1U);
      Lib_IntVector_Intrinsics_vec256 m_st[(uint32_t)4U * (uint32_t)1U];
      for (uint32_t _i = 0U; _i < (uint32_t)4U * (uint32_t)1U; ++_i)
        m_st[_i] = Lib_IntVector_Intrinsics_vec256_zero;
      Lib_IntVector_Intrinsics_vec256 *r01 = m_st + (uint32_t)0U * (uint32_t)1U;
      Lib_IntVector_Intrinsics_vec256 *r11 = m_st + (uint32_t)1U * (uint32_t)1U;
      Lib_IntVector_Intrinsics_vec256 *r21 = m_st + (uint32_t)2U * (uint32_t)1U;
      Lib_IntVector_Intrinsics_vec256 *r31 = m_st + (uint32_t)3U * (uint32_t)1U;
      uint32_t s0 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx];
      uint32_t s11 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)1U];
      uint32_t s2 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)2U];
      uint32_t s3 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)3U];
      uint32_t s4 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)4U];
      uint32_t s5 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)5U];
      uint32_t s6 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)6U];
      uint32_t s7 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)7U];
      uint32_t s8 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)8U];
      uint32_t s9 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)9U];
      uint32_t s10 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)10U];
      uint32_t s111 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)11U];
      uint32_t s12 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)12U];
      uint32_t s13 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)13U];
      uint32_t s14 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)14U];
      uint32_t s15 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)15U];
      r01[0U] = Lib_IntVector_Intrinsics_vec256_load64s(m_w[s0], m_w[s2], m_w[s4], m_w[s6]);
      r11[0U] = Lib_IntVector_Intrinsics_vec256_load64s(m_w[s11], m_w[s3], m_w[s5], m_w[s7]);
      r21[0U] = Lib_IntVector_Intrinsics_vec256_load64s(m_w[s8], m_w[s10], m_w[s12], m_w[s14]);
      r31[0U] = Lib_IntVector_Intrinsics_vec256_load64s(m_w[s9], m_w[s111], m_w[s13], m_w[s15]);
      Lib_IntVector_Intrinsics_vec256 *x = m_st + (uint32_t)0U * (uint32_t)1U;
      Lib_IntVector_Intrinsics_vec256 *y = m_st + (uint32_t)1U * (uint32_t)1U;
      Lib_IntVector_Intrinsics_vec256 *z = m_st + (uint32_t)2U * (uint32_t)1U;
      Lib_IntVector_Intrinsics_vec256 *w = m_st + (uint32_t)3U * (uint32_t)1U;
      uint32_t a = (uint32_t)0U;
      uint32_t b20 = (uint32_t)1U;
      uint32_t c0 = (uint32_t)2U;
      uint32_t d0 = (uint32_t)3U;
      uint32_t r02 = Hacl_Impl_Blake2_Constants_rTable_B[0U];
      uint32_t r12 = Hacl_Impl_Blake2_Constants_rTable_B[1U];
      uint32_t r22 = Hacl_Impl_Blake2_Constants_rTable_B[2U];
      uint32_t r32 = Hacl_Impl_Blake2_Constants_rTable_B[3U];
      Lib_IntVector_Intrinsics_vec256 *wv_a0 = block_state.fst + a * (uint32_t)1U;
      Lib_IntVector_Intrinsics_vec256 *wv_b0 = block_state.fst + b20 * (uint32_t)1U;
      wv_a0[0U] = Lib_IntVector_Intrinsics_vec256_add64(wv_a0[0U], wv_b0[0U]);
      wv_a0[0U] = Lib_IntVector_Intrinsics_vec256_add64(wv_a0[0U], x[0U]);
      Lib_IntVector_Intrinsics_vec256 *wv_a1 = block_state.fst + d0 * (uint32_t)1U;
      Lib_IntVector_Intrinsics_vec256 *wv_b1 = block_state.fst + a * (uint32_t)1U;
      wv_a1[0U] = Lib_IntVector_Intrinsics_vec256_xor(wv_a1[0U], wv_b1[0U]);
      wv_a1[0U] = Lib_IntVector_Intrinsics_vec256_rotate_right64(wv_a1[0U], r02);
      Lib_IntVector_Intrinsics_vec256 *wv_a2 = block_state.fst + c0 * (uint32_t)1U;
      Lib_IntVector_Intrinsics_vec256 *wv_b2 = block_state.fst + d0 * (uint32_t)1U;
      wv_a2[0U] = Lib_IntVector_Intrinsics_vec256_add64(wv_a2[0U], wv_b2[0U]);
      Lib_IntVector_Intrinsics_vec256 *wv_a3 = block_state.fst + b20 * (uint32_t)1U;
      Lib_IntVector_Intrinsics_vec256 *wv_b3 = block_state.fst + c0 * (uint32_t)1U;
      wv_a3[0U] = Lib_IntVector_Intrinsics_vec256_xor(wv_a3[0U], wv_b3[0U]);
      wv_a3[0U] = Lib_IntVector_Intrinsics_vec256_rotate_right64(wv_a3[0U], r12);
      Lib_IntVector_Intrinsics_vec256 *wv_a4 = block_state.fst + a * (uint32_t)1U;
      Lib_IntVector_Intrinsics_vec256 *wv_b4 = block_state.fst + b20 * (uint32_t)1U;
      wv_a4[0U] = Lib_IntVector_Intrinsics_vec256_add64(wv_a4[0U], wv_b4[0U]);
      wv_a4[0U] = Lib_IntVector_Intrinsics_vec256_add64(wv_a4[0U], y[0U]);
      Lib_IntVector_Intrinsics_vec256 *wv_a5 = block_state.fst + d0 * (uint32_t)1U;
      Lib_IntVector_Intrinsics_vec256 *wv_b5 = block_state.fst + a * (uint32_t)1U;
      wv_a5[0U] = Lib_IntVector_Intrinsics_vec256_xor(wv_a5[0U], wv_b5[0U]);
      wv_a5[0U] = Lib_IntVector_Intrinsics_vec256_rotate_right64(wv_a5[0U], r22);
      Lib_IntVector_Intrinsics_vec256 *wv_a6 = block_state.fst + c0 * (uint32_t)1U;
      Lib_IntVector_Intrinsics_vec256 *wv_b6 = block_state.fst + d0 * (uint32_t)1U;
      wv_a6[0U] = Lib_IntVector_Intrinsics_vec256_add64(wv_a6[0U], wv_b6[0U]);
      Lib_IntVector_Intrinsics_vec256 *wv_a7 = block_state.fst + b20 * (uint32_t)1U;
      Lib_IntVector_Intrinsics_vec256 *wv_b7 = block_state.fst + c0 * (uint32_t)1U;
      wv_a7[0U] = Lib_IntVector_Intrinsics_vec256_xor(wv_a7[0U], wv_b7[0U]);
      wv_a7[0U] = Lib_IntVector_Intrinsics_vec256_rotate_right64(wv_a7[0U], r32);
      Lib_IntVector_Intrinsics_vec256 *r13 = block_state.fst + (uint32_t)1U * (uint32_t)1U;
      Lib_IntVector_Intrinsics_vec256 *r23 = block_state.fst + (uint32_t)2U * (uint32_t)1U;
      Lib_IntVector_Intrinsics_vec256 *r33 = block_state.fst + (uint32_t)3U * (uint32_t)1U;
      Lib_IntVector_Intrinsics_vec256 v00 = r13[0U];
      Lib_IntVector_Intrinsics_vec256
      v1 = Lib_IntVector_Intrinsics_vec256_rotate_right_lanes64(v00, (uint32_t)1U);
      r13[0U] = v1;
      Lib_IntVector_Intrinsics_vec256 v01 = r23[0U];
      Lib_IntVector_Intrinsics_vec256
      v10 = Lib_IntVector_Intrinsics_vec256_rotate_right_lanes64(v01, (uint32_t)2U);
      r23[0U] = v10;
      Lib_IntVector_Intrinsics_vec256 v02 = r33[0U];
      Lib_IntVector_Intrinsics_vec256
      v11 = Lib_IntVector_Intrinsics_vec256_rotate_right_lanes64(v02, (uint32_t)3U);
      r33[0U] = v11;
      uint32_t a0 = (uint32_t)0U;
      uint32_t b2 = (uint32_t)1U;
      uint32_t c = (uint32_t)2U;
      uint32_t d = (uint32_t)3U;
      uint32_t r0 = Hacl_Impl_Blake2_Constants_rTable_B[0U];
      uint32_t r1 = Hacl_Impl_Blake2_Constants_rTable_B[1U];
      uint32_t r24 = Hacl_Impl_Blake2_Constants_rTable_B[2U];
      uint32_t r34 = Hacl_Impl_Blake2_Constants_rTable_B[3U];
      Lib_IntVector_Intrinsics_vec256 *wv_a = block_state.fst + a0 * (uint32_t)1U;
      Lib_IntVector_Intrinsics_vec256 *wv_b8 = block_state.fst + b2 * (uint32_t)1U;
      wv_a[0U] = Lib_IntVector_Intrinsics_vec256_add64(wv_a[0U], wv_b8[0U]);
      wv_a[0U] = Lib_IntVector_Intrinsics_vec256_add64(wv_a[0U], z[0U]);
      Lib_IntVector_Intrinsics_vec256 *wv_a8 = block_state.fst + d * (uint32_t)1U;
      Lib_IntVector_Intrinsics_vec256 *wv_b9 = block_state.fst + a0 * (uint32_t)1U;
      wv_a8[0U] = Lib_IntVector_Intrinsics_vec256_xor(wv_a8[0U], wv_b9[0U]);
      wv_a8[0U] = Lib_IntVector_Intrinsics_vec256_rotate_right64(wv_a8[0U], r0);
      Lib_IntVector_Intrinsics_vec256 *wv_a9 = block_state.fst + c * (uint32_t)1U;
      Lib_IntVector_Intrinsics_vec256 *wv_b10 = block_state.fst + d * (uint32_t)1U;
      wv_a9[0U] = Lib_IntVector_Intrinsics_vec256_add64(wv_a9[0U], wv_b10[0U]);
      Lib_IntVector_Intrinsics_vec256 *wv_a10 = block_state.fst + b2 * (uint32_t)1U;
      Lib_IntVector_Intrinsics_vec256 *wv_b11 = block_state.fst + c * (uint32_t)1U;
      wv_a10[0U] = Lib_IntVector_Intrinsics_vec256_xor(wv_a10[0U], wv_b11[0U]);
      wv_a10[0U] = Lib_IntVector_Intrinsics_vec256_rotate_right64(wv_a10[0U], r1);
      Lib_IntVector_Intrinsics_vec256 *wv_a11 = block_state.fst + a0 * (uint32_t)1U;
      Lib_IntVector_Intrinsics_vec256 *wv_b12 = block_state.fst + b2 * (uint32_t)1U;
      wv_a11[0U] = Lib_IntVector_Intrinsics_vec256_add64(wv_a11[0U], wv_b12[0U]);
      wv_a11[0U] = Lib_IntVector_Intrinsics_vec256_add64(wv_a11[0U], w[0U]);
      Lib_IntVector_Intrinsics_vec256 *wv_a12 = block_state.fst + d * (uint32_t)1U;
      Lib_IntVector_Intrinsics_vec256 *wv_b13 = block_state.fst + a0 * (uint32_t)1U;
      wv_a12[0U] = Lib_IntVector_Intrinsics_vec256_xor(wv_a12[0U], wv_b13[0U]);
      wv_a12[0U] = Lib_IntVector_Intrinsics_vec256_rotate_right64(wv_a12[0U], r24);
      Lib_IntVector_Intrinsics_vec256 *wv_a13 = block_state.fst + c * (uint32_t)1U;
      Lib_IntVector_Intrinsics_vec256 *wv_b14 = block_state.fst + d * (uint32_t)1U;
      wv_a13[0U] = Lib_IntVector_Intrinsics_vec256_add64(wv_a13[0U], wv_b14[0U]);
      Lib_IntVector_Intrinsics_vec256 *wv_a14 = block_state.fst + b2 * (uint32_t)1U;
      Lib_IntVector_Intrinsics_vec256 *wv_b = block_state.fst + c * (uint32_t)1U;
      wv_a14[0U] = Lib_IntVector_Intrinsics_vec256_xor(wv_a14[0U], wv_b[0U]);
      wv_a14[0U] = Lib_IntVector_Intrinsics_vec256_rotate_right64(wv_a14[0U], r34);
      Lib_IntVector_Intrinsics_vec256 *r14 = block_state.fst + (uint32_t)1U * (uint32_t)1U;
      Lib_IntVector_Intrinsics_vec256 *r2 = block_state.fst + (uint32_t)2U * (uint32_t)1U;
      Lib_IntVector_Intrinsics_vec256 *r3 = block_state.fst + (uint32_t)3U * (uint32_t)1U;
      Lib_IntVector_Intrinsics_vec256 v0 = r14[0U];
      Lib_IntVector_Intrinsics_vec256
      v12 = Lib_IntVector_Intrinsics_vec256_rotate_right_lanes64(v0, (uint32_t)3U);
      r14[0U] = v12;
      Lib_IntVector_Intrinsics_vec256 v03 = r2[0U];
      Lib_IntVector_Intrinsics_vec256
      v13 = Lib_IntVector_Intrinsics_vec256_rotate_right_lanes64(v03, (uint32_t)2U);
      r2[0U] = v13;
      Lib_IntVector_Intrinsics_vec256 v04 = r3[0U];
      Lib_IntVector_Intrinsics_vec256
      v14 = Lib_IntVector_Intrinsics_vec256_rotate_right_lanes64(v04, (uint32_t)1U);
      r3[0U] = v14;
    }
    Lib_IntVector_Intrinsics_vec256 *s0 = block_state.snd + (uint32_t)0U * (uint32_t)1U;
    Lib_IntVector_Intrinsics_vec256 *s11 = block_state.snd + (uint32_t)1U * (uint32_t)1U;
    Lib_IntVector_Intrinsics_vec256 *r0 = block_state.fst + (uint32_t)0U * (uint32_t)1U;
    Lib_IntVector_Intrinsics_vec256 *r1 = block_state.fst + (uint32_t)1U * (uint32_t)1U;
    Lib_IntVector_Intrinsics_vec256 *r2 = block_state.fst + (uint32_t)2U * (uint32_t)1U;
    Lib_IntVector_Intrinsics_vec256 *r3 = block_state.fst + (uint32_t)3U * (uint32_t)1U;
    s0[0U] = Lib_IntVector_Intrinsics_vec256_xor(s0[0U], r0[0U]);
    s0[0U] = Lib_IntVector_Intrinsics_vec256_xor(s0[0U], r2[0U]);
    s11[0U] = Lib_IntVector_Intrinsics_vec256_xor(s11[0U], r1[0U]);
    s11[0U] = Lib_IntVector_Intrinsics_vec256_xor(s11[0U], r3[0U]);
  }
  Lib_Memzero0_memzero(b, (uint32_t)128U * sizeof (b[0U]));
  return p;
}

/* SNIPPET_END: Hacl_Streaming_Blake2_blake2b_256_with_key_create_in */

/* SNIPPET_START: Hacl_Streaming_Blake2_blake2b_256_with_key_update */

/*
  Update function when using a (potentially null) key
*/
void
Hacl_Streaming_Blake2_blake2b_256_with_key_update(
  uint32_t key_size,
  Hacl_Streaming_Functor_state_s__K____Lib_IntVector_Intrinsics_vec256___Lib_IntVector_Intrinsics_vec256____
  *p,
  uint8_t *data,
  uint32_t len
)
{
  Hacl_Streaming_Functor_state_s__K____Lib_IntVector_Intrinsics_vec256___Lib_IntVector_Intrinsics_vec256____
  s1 = *p;
  uint64_t total_len = s1.total_len;
  uint32_t sz;
  if (total_len % (uint64_t)(uint32_t)128U == (uint64_t)0U && total_len > (uint64_t)0U)
  {
    sz = (uint32_t)128U;
  }
  else
  {
    sz = (uint32_t)(total_len % (uint64_t)(uint32_t)128U);
  }
  if (len <= (uint32_t)128U - sz)
  {
    Hacl_Streaming_Functor_state_s__K____Lib_IntVector_Intrinsics_vec256___Lib_IntVector_Intrinsics_vec256____
    s2 = *p;
    K____Lib_IntVector_Intrinsics_vec256___Lib_IntVector_Intrinsics_vec256_
    block_state1 = s2.block_state;
    uint8_t *buf = s2.buf;
    uint64_t total_len1 = s2.total_len;
    uint32_t sz1;
    if (total_len1 % (uint64_t)(uint32_t)128U == (uint64_t)0U && total_len1 > (uint64_t)0U)
    {
      sz1 = (uint32_t)128U;
    }
    else
    {
      sz1 = (uint32_t)(total_len1 % (uint64_t)(uint32_t)128U);
    }
    uint8_t *buf2 = buf + sz1;
    memcpy(buf2, data, len * sizeof (data[0U]));
    uint64_t total_len2 = total_len1 + (uint64_t)len;
    *p
    =
      (
        (Hacl_Streaming_Functor_state_s__K____Lib_IntVector_Intrinsics_vec256___Lib_IntVector_Intrinsics_vec256____){
          .block_state = block_state1,
          .buf = buf,
          .total_len = total_len2
        }
      );
    return;
  }
  if (sz == (uint32_t)0U)
  {
    Hacl_Streaming_Functor_state_s__K____Lib_IntVector_Intrinsics_vec256___Lib_IntVector_Intrinsics_vec256____
    s2 = *p;
    K____Lib_IntVector_Intrinsics_vec256___Lib_IntVector_Intrinsics_vec256_
    block_state1 = s2.block_state;
    uint8_t *buf = s2.buf;
    uint64_t total_len1 = s2.total_len;
    uint32_t sz1;
    if (total_len1 % (uint64_t)(uint32_t)128U == (uint64_t)0U && total_len1 > (uint64_t)0U)
    {
      sz1 = (uint32_t)128U;
    }
    else
    {
      sz1 = (uint32_t)(total_len1 % (uint64_t)(uint32_t)128U);
    }
    if (!(sz1 == (uint32_t)0U))
    {
      uint64_t prevlen = total_len1 - (uint64_t)sz1;
      uint32_t nb = (uint32_t)1U;
      for (uint32_t i0 = (uint32_t)0U; i0 < nb; i0++)
      {
        uint64_t ite;
        if (key_size == (uint32_t)0U)
        {
          ite = prevlen;
        }
        else
        {
          ite = prevlen + (uint64_t)(uint32_t)128U;
        }
        FStar_UInt128_uint128
        totlen =
          FStar_UInt128_add_mod(FStar_UInt128_uint64_to_uint128(ite),
            FStar_UInt128_uint64_to_uint128((uint64_t)((i0 + (uint32_t)1U) * (uint32_t)128U)));
        uint8_t *b = buf + i0 * (uint32_t)128U;
        uint64_t m_w[16U] = { 0U };
        for (uint32_t i = (uint32_t)0U; i < (uint32_t)16U; i++)
        {
          uint64_t *os = m_w;
          uint8_t *bj = b + i * (uint32_t)8U;
          uint64_t u = load64_le(bj);
          uint64_t r = u;
          uint64_t x = r;
          os[i] = x;
        }
        Lib_IntVector_Intrinsics_vec256 mask = Lib_IntVector_Intrinsics_vec256_zero;
        uint64_t wv_14 = (uint64_t)0U;
        uint64_t wv_15 = (uint64_t)0U;
        mask =
          Lib_IntVector_Intrinsics_vec256_load64s(FStar_UInt128_uint128_to_uint64(totlen),
            FStar_UInt128_uint128_to_uint64(FStar_UInt128_shift_right(totlen, (uint32_t)64U)),
            wv_14,
            wv_15);
        memcpy(block_state1.fst,
          block_state1.snd,
          (uint32_t)4U * (uint32_t)1U * sizeof (block_state1.snd[0U]));
        Lib_IntVector_Intrinsics_vec256 *wv3 = block_state1.fst + (uint32_t)3U * (uint32_t)1U;
        wv3[0U] = Lib_IntVector_Intrinsics_vec256_xor(wv3[0U], mask);
        for (uint32_t i = (uint32_t)0U; i < (uint32_t)12U; i++)
        {
          uint32_t start_idx = i % (uint32_t)10U * (uint32_t)16U;
          KRML_CHECK_SIZE(sizeof (Lib_IntVector_Intrinsics_vec256), (uint32_t)4U * (uint32_t)1U);
          Lib_IntVector_Intrinsics_vec256 m_st[(uint32_t)4U * (uint32_t)1U];
          for (uint32_t _i = 0U; _i < (uint32_t)4U * (uint32_t)1U; ++_i)
            m_st[_i] = Lib_IntVector_Intrinsics_vec256_zero;
          Lib_IntVector_Intrinsics_vec256 *r00 = m_st + (uint32_t)0U * (uint32_t)1U;
          Lib_IntVector_Intrinsics_vec256 *r10 = m_st + (uint32_t)1U * (uint32_t)1U;
          Lib_IntVector_Intrinsics_vec256 *r20 = m_st + (uint32_t)2U * (uint32_t)1U;
          Lib_IntVector_Intrinsics_vec256 *r30 = m_st + (uint32_t)3U * (uint32_t)1U;
          uint32_t s0 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx];
          uint32_t s11 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)1U];
          uint32_t s21 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)2U];
          uint32_t s3 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)3U];
          uint32_t s4 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)4U];
          uint32_t s5 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)5U];
          uint32_t s6 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)6U];
          uint32_t s7 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)7U];
          uint32_t s8 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)8U];
          uint32_t s9 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)9U];
          uint32_t s10 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)10U];
          uint32_t s111 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)11U];
          uint32_t s12 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)12U];
          uint32_t s13 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)13U];
          uint32_t s14 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)14U];
          uint32_t s15 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)15U];
          r00[0U] = Lib_IntVector_Intrinsics_vec256_load64s(m_w[s0], m_w[s21], m_w[s4], m_w[s6]);
          r10[0U] = Lib_IntVector_Intrinsics_vec256_load64s(m_w[s11], m_w[s3], m_w[s5], m_w[s7]);
          r20[0U] = Lib_IntVector_Intrinsics_vec256_load64s(m_w[s8], m_w[s10], m_w[s12], m_w[s14]);
          r30[0U] = Lib_IntVector_Intrinsics_vec256_load64s(m_w[s9], m_w[s111], m_w[s13], m_w[s15]);
          Lib_IntVector_Intrinsics_vec256 *x = m_st + (uint32_t)0U * (uint32_t)1U;
          Lib_IntVector_Intrinsics_vec256 *y = m_st + (uint32_t)1U * (uint32_t)1U;
          Lib_IntVector_Intrinsics_vec256 *z = m_st + (uint32_t)2U * (uint32_t)1U;
          Lib_IntVector_Intrinsics_vec256 *w = m_st + (uint32_t)3U * (uint32_t)1U;
          uint32_t a = (uint32_t)0U;
          uint32_t b10 = (uint32_t)1U;
          uint32_t c0 = (uint32_t)2U;
          uint32_t d0 = (uint32_t)3U;
          uint32_t r01 = Hacl_Impl_Blake2_Constants_rTable_B[0U];
          uint32_t r11 = Hacl_Impl_Blake2_Constants_rTable_B[1U];
          uint32_t r21 = Hacl_Impl_Blake2_Constants_rTable_B[2U];
          uint32_t r31 = Hacl_Impl_Blake2_Constants_rTable_B[3U];
          Lib_IntVector_Intrinsics_vec256 *wv_a0 = block_state1.fst + a * (uint32_t)1U;
          Lib_IntVector_Intrinsics_vec256 *wv_b0 = block_state1.fst + b10 * (uint32_t)1U;
          wv_a0[0U] = Lib_IntVector_Intrinsics_vec256_add64(wv_a0[0U], wv_b0[0U]);
          wv_a0[0U] = Lib_IntVector_Intrinsics_vec256_add64(wv_a0[0U], x[0U]);
          Lib_IntVector_Intrinsics_vec256 *wv_a1 = block_state1.fst + d0 * (uint32_t)1U;
          Lib_IntVector_Intrinsics_vec256 *wv_b1 = block_state1.fst + a * (uint32_t)1U;
          wv_a1[0U] = Lib_IntVector_Intrinsics_vec256_xor(wv_a1[0U], wv_b1[0U]);
          wv_a1[0U] = Lib_IntVector_Intrinsics_vec256_rotate_right64(wv_a1[0U], r01);
          Lib_IntVector_Intrinsics_vec256 *wv_a2 = block_state1.fst + c0 * (uint32_t)1U;
          Lib_IntVector_Intrinsics_vec256 *wv_b2 = block_state1.fst + d0 * (uint32_t)1U;
          wv_a2[0U] = Lib_IntVector_Intrinsics_vec256_add64(wv_a2[0U], wv_b2[0U]);
          Lib_IntVector_Intrinsics_vec256 *wv_a3 = block_state1.fst + b10 * (uint32_t)1U;
          Lib_IntVector_Intrinsics_vec256 *wv_b3 = block_state1.fst + c0 * (uint32_t)1U;
          wv_a3[0U] = Lib_IntVector_Intrinsics_vec256_xor(wv_a3[0U], wv_b3[0U]);
          wv_a3[0U] = Lib_IntVector_Intrinsics_vec256_rotate_right64(wv_a3[0U], r11);
          Lib_IntVector_Intrinsics_vec256 *wv_a4 = block_state1.fst + a * (uint32_t)1U;
          Lib_IntVector_Intrinsics_vec256 *wv_b4 = block_state1.fst + b10 * (uint32_t)1U;
          wv_a4[0U] = Lib_IntVector_Intrinsics_vec256_add64(wv_a4[0U], wv_b4[0U]);
          wv_a4[0U] = Lib_IntVector_Intrinsics_vec256_add64(wv_a4[0U], y[0U]);
          Lib_IntVector_Intrinsics_vec256 *wv_a5 = block_state1.fst + d0 * (uint32_t)1U;
          Lib_IntVector_Intrinsics_vec256 *wv_b5 = block_state1.fst + a * (uint32_t)1U;
          wv_a5[0U] = Lib_IntVector_Intrinsics_vec256_xor(wv_a5[0U], wv_b5[0U]);
          wv_a5[0U] = Lib_IntVector_Intrinsics_vec256_rotate_right64(wv_a5[0U], r21);
          Lib_IntVector_Intrinsics_vec256 *wv_a6 = block_state1.fst + c0 * (uint32_t)1U;
          Lib_IntVector_Intrinsics_vec256 *wv_b6 = block_state1.fst + d0 * (uint32_t)1U;
          wv_a6[0U] = Lib_IntVector_Intrinsics_vec256_add64(wv_a6[0U], wv_b6[0U]);
          Lib_IntVector_Intrinsics_vec256 *wv_a7 = block_state1.fst + b10 * (uint32_t)1U;
          Lib_IntVector_Intrinsics_vec256 *wv_b7 = block_state1.fst + c0 * (uint32_t)1U;
          wv_a7[0U] = Lib_IntVector_Intrinsics_vec256_xor(wv_a7[0U], wv_b7[0U]);
          wv_a7[0U] = Lib_IntVector_Intrinsics_vec256_rotate_right64(wv_a7[0U], r31);
          Lib_IntVector_Intrinsics_vec256 *r12 = block_state1.fst + (uint32_t)1U * (uint32_t)1U;
          Lib_IntVector_Intrinsics_vec256 *r22 = block_state1.fst + (uint32_t)2U * (uint32_t)1U;
          Lib_IntVector_Intrinsics_vec256 *r32 = block_state1.fst + (uint32_t)3U * (uint32_t)1U;
          Lib_IntVector_Intrinsics_vec256 v00 = r12[0U];
          Lib_IntVector_Intrinsics_vec256
          v1 = Lib_IntVector_Intrinsics_vec256_rotate_right_lanes64(v00, (uint32_t)1U);
          r12[0U] = v1;
          Lib_IntVector_Intrinsics_vec256 v01 = r22[0U];
          Lib_IntVector_Intrinsics_vec256
          v10 = Lib_IntVector_Intrinsics_vec256_rotate_right_lanes64(v01, (uint32_t)2U);
          r22[0U] = v10;
          Lib_IntVector_Intrinsics_vec256 v02 = r32[0U];
          Lib_IntVector_Intrinsics_vec256
          v11 = Lib_IntVector_Intrinsics_vec256_rotate_right_lanes64(v02, (uint32_t)3U);
          r32[0U] = v11;
          uint32_t a0 = (uint32_t)0U;
          uint32_t b1 = (uint32_t)1U;
          uint32_t c = (uint32_t)2U;
          uint32_t d = (uint32_t)3U;
          uint32_t r0 = Hacl_Impl_Blake2_Constants_rTable_B[0U];
          uint32_t r1 = Hacl_Impl_Blake2_Constants_rTable_B[1U];
          uint32_t r23 = Hacl_Impl_Blake2_Constants_rTable_B[2U];
          uint32_t r33 = Hacl_Impl_Blake2_Constants_rTable_B[3U];
          Lib_IntVector_Intrinsics_vec256 *wv_a = block_state1.fst + a0 * (uint32_t)1U;
          Lib_IntVector_Intrinsics_vec256 *wv_b8 = block_state1.fst + b1 * (uint32_t)1U;
          wv_a[0U] = Lib_IntVector_Intrinsics_vec256_add64(wv_a[0U], wv_b8[0U]);
          wv_a[0U] = Lib_IntVector_Intrinsics_vec256_add64(wv_a[0U], z[0U]);
          Lib_IntVector_Intrinsics_vec256 *wv_a8 = block_state1.fst + d * (uint32_t)1U;
          Lib_IntVector_Intrinsics_vec256 *wv_b9 = block_state1.fst + a0 * (uint32_t)1U;
          wv_a8[0U] = Lib_IntVector_Intrinsics_vec256_xor(wv_a8[0U], wv_b9[0U]);
          wv_a8[0U] = Lib_IntVector_Intrinsics_vec256_rotate_right64(wv_a8[0U], r0);
          Lib_IntVector_Intrinsics_vec256 *wv_a9 = block_state1.fst + c * (uint32_t)1U;
          Lib_IntVector_Intrinsics_vec256 *wv_b10 = block_state1.fst + d * (uint32_t)1U;
          wv_a9[0U] = Lib_IntVector_Intrinsics_vec256_add64(wv_a9[0U], wv_b10[0U]);
          Lib_IntVector_Intrinsics_vec256 *wv_a10 = block_state1.fst + b1 * (uint32_t)1U;
          Lib_IntVector_Intrinsics_vec256 *wv_b11 = block_state1.fst + c * (uint32_t)1U;
          wv_a10[0U] = Lib_IntVector_Intrinsics_vec256_xor(wv_a10[0U], wv_b11[0U]);
          wv_a10[0U] = Lib_IntVector_Intrinsics_vec256_rotate_right64(wv_a10[0U], r1);
          Lib_IntVector_Intrinsics_vec256 *wv_a11 = block_state1.fst + a0 * (uint32_t)1U;
          Lib_IntVector_Intrinsics_vec256 *wv_b12 = block_state1.fst + b1 * (uint32_t)1U;
          wv_a11[0U] = Lib_IntVector_Intrinsics_vec256_add64(wv_a11[0U], wv_b12[0U]);
          wv_a11[0U] = Lib_IntVector_Intrinsics_vec256_add64(wv_a11[0U], w[0U]);
          Lib_IntVector_Intrinsics_vec256 *wv_a12 = block_state1.fst + d * (uint32_t)1U;
          Lib_IntVector_Intrinsics_vec256 *wv_b13 = block_state1.fst + a0 * (uint32_t)1U;
          wv_a12[0U] = Lib_IntVector_Intrinsics_vec256_xor(wv_a12[0U], wv_b13[0U]);
          wv_a12[0U] = Lib_IntVector_Intrinsics_vec256_rotate_right64(wv_a12[0U], r23);
          Lib_IntVector_Intrinsics_vec256 *wv_a13 = block_state1.fst + c * (uint32_t)1U;
          Lib_IntVector_Intrinsics_vec256 *wv_b14 = block_state1.fst + d * (uint32_t)1U;
          wv_a13[0U] = Lib_IntVector_Intrinsics_vec256_add64(wv_a13[0U], wv_b14[0U]);
          Lib_IntVector_Intrinsics_vec256 *wv_a14 = block_state1.fst + b1 * (uint32_t)1U;
          Lib_IntVector_Intrinsics_vec256 *wv_b = block_state1.fst + c * (uint32_t)1U;
          wv_a14[0U] = Lib_IntVector_Intrinsics_vec256_xor(wv_a14[0U], wv_b[0U]);
          wv_a14[0U] = Lib_IntVector_Intrinsics_vec256_rotate_right64(wv_a14[0U], r33);
          Lib_IntVector_Intrinsics_vec256 *r13 = block_state1.fst + (uint32_t)1U * (uint32_t)1U;
          Lib_IntVector_Intrinsics_vec256 *r2 = block_state1.fst + (uint32_t)2U * (uint32_t)1U;
          Lib_IntVector_Intrinsics_vec256 *r3 = block_state1.fst + (uint32_t)3U * (uint32_t)1U;
          Lib_IntVector_Intrinsics_vec256 v0 = r13[0U];
          Lib_IntVector_Intrinsics_vec256
          v12 = Lib_IntVector_Intrinsics_vec256_rotate_right_lanes64(v0, (uint32_t)3U);
          r13[0U] = v12;
          Lib_IntVector_Intrinsics_vec256 v03 = r2[0U];
          Lib_IntVector_Intrinsics_vec256
          v13 = Lib_IntVector_Intrinsics_vec256_rotate_right_lanes64(v03, (uint32_t)2U);
          r2[0U] = v13;
          Lib_IntVector_Intrinsics_vec256 v04 = r3[0U];
          Lib_IntVector_Intrinsics_vec256
          v14 = Lib_IntVector_Intrinsics_vec256_rotate_right_lanes64(v04, (uint32_t)1U);
          r3[0U] = v14;
        }
        Lib_IntVector_Intrinsics_vec256 *s0 = block_state1.snd + (uint32_t)0U * (uint32_t)1U;
        Lib_IntVector_Intrinsics_vec256 *s11 = block_state1.snd + (uint32_t)1U * (uint32_t)1U;
        Lib_IntVector_Intrinsics_vec256 *r0 = block_state1.fst + (uint32_t)0U * (uint32_t)1U;
        Lib_IntVector_Intrinsics_vec256 *r1 = block_state1.fst + (uint32_t)1U * (uint32_t)1U;
        Lib_IntVector_Intrinsics_vec256 *r2 = block_state1.fst + (uint32_t)2U * (uint32_t)1U;
        Lib_IntVector_Intrinsics_vec256 *r3 = block_state1.fst + (uint32_t)3U * (uint32_t)1U;
        s0[0U] = Lib_IntVector_Intrinsics_vec256_xor(s0[0U], r0[0U]);
        s0[0U] = Lib_IntVector_Intrinsics_vec256_xor(s0[0U], r2[0U]);
        s11[0U] = Lib_IntVector_Intrinsics_vec256_xor(s11[0U], r1[0U]);
        s11[0U] = Lib_IntVector_Intrinsics_vec256_xor(s11[0U], r3[0U]);
      }
    }
    uint32_t ite0;
    if ((uint64_t)len % (uint64_t)(uint32_t)128U == (uint64_t)0U && (uint64_t)len > (uint64_t)0U)
    {
      ite0 = (uint32_t)128U;
    }
    else
    {
      ite0 = (uint32_t)((uint64_t)len % (uint64_t)(uint32_t)128U);
    }
    uint32_t n_blocks = (len - ite0) / (uint32_t)128U;
    uint32_t data1_len = n_blocks * (uint32_t)128U;
    uint32_t data2_len = len - data1_len;
    uint8_t *data1 = data;
    uint8_t *data2 = data + data1_len;
    uint32_t nb = data1_len / (uint32_t)128U;
    for (uint32_t i0 = (uint32_t)0U; i0 < nb; i0++)
    {
      uint64_t ite;
      if (key_size == (uint32_t)0U)
      {
        ite = total_len1;
      }
      else
      {
        ite = total_len1 + (uint64_t)(uint32_t)128U;
      }
      FStar_UInt128_uint128
      totlen =
        FStar_UInt128_add_mod(FStar_UInt128_uint64_to_uint128(ite),
          FStar_UInt128_uint64_to_uint128((uint64_t)((i0 + (uint32_t)1U) * (uint32_t)128U)));
      uint8_t *b = data1 + i0 * (uint32_t)128U;
      uint64_t m_w[16U] = { 0U };
      for (uint32_t i = (uint32_t)0U; i < (uint32_t)16U; i++)
      {
        uint64_t *os = m_w;
        uint8_t *bj = b + i * (uint32_t)8U;
        uint64_t u = load64_le(bj);
        uint64_t r = u;
        uint64_t x = r;
        os[i] = x;
      }
      Lib_IntVector_Intrinsics_vec256 mask = Lib_IntVector_Intrinsics_vec256_zero;
      uint64_t wv_14 = (uint64_t)0U;
      uint64_t wv_15 = (uint64_t)0U;
      mask =
        Lib_IntVector_Intrinsics_vec256_load64s(FStar_UInt128_uint128_to_uint64(totlen),
          FStar_UInt128_uint128_to_uint64(FStar_UInt128_shift_right(totlen, (uint32_t)64U)),
          wv_14,
          wv_15);
      memcpy(block_state1.fst,
        block_state1.snd,
        (uint32_t)4U * (uint32_t)1U * sizeof (block_state1.snd[0U]));
      Lib_IntVector_Intrinsics_vec256 *wv3 = block_state1.fst + (uint32_t)3U * (uint32_t)1U;
      wv3[0U] = Lib_IntVector_Intrinsics_vec256_xor(wv3[0U], mask);
      for (uint32_t i = (uint32_t)0U; i < (uint32_t)12U; i++)
      {
        uint32_t start_idx = i % (uint32_t)10U * (uint32_t)16U;
        KRML_CHECK_SIZE(sizeof (Lib_IntVector_Intrinsics_vec256), (uint32_t)4U * (uint32_t)1U);
        Lib_IntVector_Intrinsics_vec256 m_st[(uint32_t)4U * (uint32_t)1U];
        for (uint32_t _i = 0U; _i < (uint32_t)4U * (uint32_t)1U; ++_i)
          m_st[_i] = Lib_IntVector_Intrinsics_vec256_zero;
        Lib_IntVector_Intrinsics_vec256 *r00 = m_st + (uint32_t)0U * (uint32_t)1U;
        Lib_IntVector_Intrinsics_vec256 *r10 = m_st + (uint32_t)1U * (uint32_t)1U;
        Lib_IntVector_Intrinsics_vec256 *r20 = m_st + (uint32_t)2U * (uint32_t)1U;
        Lib_IntVector_Intrinsics_vec256 *r30 = m_st + (uint32_t)3U * (uint32_t)1U;
        uint32_t s0 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx];
        uint32_t s11 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)1U];
        uint32_t s21 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)2U];
        uint32_t s3 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)3U];
        uint32_t s4 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)4U];
        uint32_t s5 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)5U];
        uint32_t s6 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)6U];
        uint32_t s7 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)7U];
        uint32_t s8 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)8U];
        uint32_t s9 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)9U];
        uint32_t s10 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)10U];
        uint32_t s111 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)11U];
        uint32_t s12 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)12U];
        uint32_t s13 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)13U];
        uint32_t s14 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)14U];
        uint32_t s15 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)15U];
        r00[0U] = Lib_IntVector_Intrinsics_vec256_load64s(m_w[s0], m_w[s21], m_w[s4], m_w[s6]);
        r10[0U] = Lib_IntVector_Intrinsics_vec256_load64s(m_w[s11], m_w[s3], m_w[s5], m_w[s7]);
        r20[0U] = Lib_IntVector_Intrinsics_vec256_load64s(m_w[s8], m_w[s10], m_w[s12], m_w[s14]);
        r30[0U] = Lib_IntVector_Intrinsics_vec256_load64s(m_w[s9], m_w[s111], m_w[s13], m_w[s15]);
        Lib_IntVector_Intrinsics_vec256 *x = m_st + (uint32_t)0U * (uint32_t)1U;
        Lib_IntVector_Intrinsics_vec256 *y = m_st + (uint32_t)1U * (uint32_t)1U;
        Lib_IntVector_Intrinsics_vec256 *z = m_st + (uint32_t)2U * (uint32_t)1U;
        Lib_IntVector_Intrinsics_vec256 *w = m_st + (uint32_t)3U * (uint32_t)1U;
        uint32_t a = (uint32_t)0U;
        uint32_t b10 = (uint32_t)1U;
        uint32_t c0 = (uint32_t)2U;
        uint32_t d0 = (uint32_t)3U;
        uint32_t r01 = Hacl_Impl_Blake2_Constants_rTable_B[0U];
        uint32_t r11 = Hacl_Impl_Blake2_Constants_rTable_B[1U];
        uint32_t r21 = Hacl_Impl_Blake2_Constants_rTable_B[2U];
        uint32_t r31 = Hacl_Impl_Blake2_Constants_rTable_B[3U];
        Lib_IntVector_Intrinsics_vec256 *wv_a0 = block_state1.fst + a * (uint32_t)1U;
        Lib_IntVector_Intrinsics_vec256 *wv_b0 = block_state1.fst + b10 * (uint32_t)1U;
        wv_a0[0U] = Lib_IntVector_Intrinsics_vec256_add64(wv_a0[0U], wv_b0[0U]);
        wv_a0[0U] = Lib_IntVector_Intrinsics_vec256_add64(wv_a0[0U], x[0U]);
        Lib_IntVector_Intrinsics_vec256 *wv_a1 = block_state1.fst + d0 * (uint32_t)1U;
        Lib_IntVector_Intrinsics_vec256 *wv_b1 = block_state1.fst + a * (uint32_t)1U;
        wv_a1[0U] = Lib_IntVector_Intrinsics_vec256_xor(wv_a1[0U], wv_b1[0U]);
        wv_a1[0U] = Lib_IntVector_Intrinsics_vec256_rotate_right64(wv_a1[0U], r01);
        Lib_IntVector_Intrinsics_vec256 *wv_a2 = block_state1.fst + c0 * (uint32_t)1U;
        Lib_IntVector_Intrinsics_vec256 *wv_b2 = block_state1.fst + d0 * (uint32_t)1U;
        wv_a2[0U] = Lib_IntVector_Intrinsics_vec256_add64(wv_a2[0U], wv_b2[0U]);
        Lib_IntVector_Intrinsics_vec256 *wv_a3 = block_state1.fst + b10 * (uint32_t)1U;
        Lib_IntVector_Intrinsics_vec256 *wv_b3 = block_state1.fst + c0 * (uint32_t)1U;
        wv_a3[0U] = Lib_IntVector_Intrinsics_vec256_xor(wv_a3[0U], wv_b3[0U]);
        wv_a3[0U] = Lib_IntVector_Intrinsics_vec256_rotate_right64(wv_a3[0U], r11);
        Lib_IntVector_Intrinsics_vec256 *wv_a4 = block_state1.fst + a * (uint32_t)1U;
        Lib_IntVector_Intrinsics_vec256 *wv_b4 = block_state1.fst + b10 * (uint32_t)1U;
        wv_a4[0U] = Lib_IntVector_Intrinsics_vec256_add64(wv_a4[0U], wv_b4[0U]);
        wv_a4[0U] = Lib_IntVector_Intrinsics_vec256_add64(wv_a4[0U], y[0U]);
        Lib_IntVector_Intrinsics_vec256 *wv_a5 = block_state1.fst + d0 * (uint32_t)1U;
        Lib_IntVector_Intrinsics_vec256 *wv_b5 = block_state1.fst + a * (uint32_t)1U;
        wv_a5[0U] = Lib_IntVector_Intrinsics_vec256_xor(wv_a5[0U], wv_b5[0U]);
        wv_a5[0U] = Lib_IntVector_Intrinsics_vec256_rotate_right64(wv_a5[0U], r21);
        Lib_IntVector_Intrinsics_vec256 *wv_a6 = block_state1.fst + c0 * (uint32_t)1U;
        Lib_IntVector_Intrinsics_vec256 *wv_b6 = block_state1.fst + d0 * (uint32_t)1U;
        wv_a6[0U] = Lib_IntVector_Intrinsics_vec256_add64(wv_a6[0U], wv_b6[0U]);
        Lib_IntVector_Intrinsics_vec256 *wv_a7 = block_state1.fst + b10 * (uint32_t)1U;
        Lib_IntVector_Intrinsics_vec256 *wv_b7 = block_state1.fst + c0 * (uint32_t)1U;
        wv_a7[0U] = Lib_IntVector_Intrinsics_vec256_xor(wv_a7[0U], wv_b7[0U]);
        wv_a7[0U] = Lib_IntVector_Intrinsics_vec256_rotate_right64(wv_a7[0U], r31);
        Lib_IntVector_Intrinsics_vec256 *r12 = block_state1.fst + (uint32_t)1U * (uint32_t)1U;
        Lib_IntVector_Intrinsics_vec256 *r22 = block_state1.fst + (uint32_t)2U * (uint32_t)1U;
        Lib_IntVector_Intrinsics_vec256 *r32 = block_state1.fst + (uint32_t)3U * (uint32_t)1U;
        Lib_IntVector_Intrinsics_vec256 v00 = r12[0U];
        Lib_IntVector_Intrinsics_vec256
        v1 = Lib_IntVector_Intrinsics_vec256_rotate_right_lanes64(v00, (uint32_t)1U);
        r12[0U] = v1;
        Lib_IntVector_Intrinsics_vec256 v01 = r22[0U];
        Lib_IntVector_Intrinsics_vec256
        v10 = Lib_IntVector_Intrinsics_vec256_rotate_right_lanes64(v01, (uint32_t)2U);
        r22[0U] = v10;
        Lib_IntVector_Intrinsics_vec256 v02 = r32[0U];
        Lib_IntVector_Intrinsics_vec256
        v11 = Lib_IntVector_Intrinsics_vec256_rotate_right_lanes64(v02, (uint32_t)3U);
        r32[0U] = v11;
        uint32_t a0 = (uint32_t)0U;
        uint32_t b1 = (uint32_t)1U;
        uint32_t c = (uint32_t)2U;
        uint32_t d = (uint32_t)3U;
        uint32_t r0 = Hacl_Impl_Blake2_Constants_rTable_B[0U];
        uint32_t r1 = Hacl_Impl_Blake2_Constants_rTable_B[1U];
        uint32_t r23 = Hacl_Impl_Blake2_Constants_rTable_B[2U];
        uint32_t r33 = Hacl_Impl_Blake2_Constants_rTable_B[3U];
        Lib_IntVector_Intrinsics_vec256 *wv_a = block_state1.fst + a0 * (uint32_t)1U;
        Lib_IntVector_Intrinsics_vec256 *wv_b8 = block_state1.fst + b1 * (uint32_t)1U;
        wv_a[0U] = Lib_IntVector_Intrinsics_vec256_add64(wv_a[0U], wv_b8[0U]);
        wv_a[0U] = Lib_IntVector_Intrinsics_vec256_add64(wv_a[0U], z[0U]);
        Lib_IntVector_Intrinsics_vec256 *wv_a8 = block_state1.fst + d * (uint32_t)1U;
        Lib_IntVector_Intrinsics_vec256 *wv_b9 = block_state1.fst + a0 * (uint32_t)1U;
        wv_a8[0U] = Lib_IntVector_Intrinsics_vec256_xor(wv_a8[0U], wv_b9[0U]);
        wv_a8[0U] = Lib_IntVector_Intrinsics_vec256_rotate_right64(wv_a8[0U], r0);
        Lib_IntVector_Intrinsics_vec256 *wv_a9 = block_state1.fst + c * (uint32_t)1U;
        Lib_IntVector_Intrinsics_vec256 *wv_b10 = block_state1.fst + d * (uint32_t)1U;
        wv_a9[0U] = Lib_IntVector_Intrinsics_vec256_add64(wv_a9[0U], wv_b10[0U]);
        Lib_IntVector_Intrinsics_vec256 *wv_a10 = block_state1.fst + b1 * (uint32_t)1U;
        Lib_IntVector_Intrinsics_vec256 *wv_b11 = block_state1.fst + c * (uint32_t)1U;
        wv_a10[0U] = Lib_IntVector_Intrinsics_vec256_xor(wv_a10[0U], wv_b11[0U]);
        wv_a10[0U] = Lib_IntVector_Intrinsics_vec256_rotate_right64(wv_a10[0U], r1);
        Lib_IntVector_Intrinsics_vec256 *wv_a11 = block_state1.fst + a0 * (uint32_t)1U;
        Lib_IntVector_Intrinsics_vec256 *wv_b12 = block_state1.fst + b1 * (uint32_t)1U;
        wv_a11[0U] = Lib_IntVector_Intrinsics_vec256_add64(wv_a11[0U], wv_b12[0U]);
        wv_a11[0U] = Lib_IntVector_Intrinsics_vec256_add64(wv_a11[0U], w[0U]);
        Lib_IntVector_Intrinsics_vec256 *wv_a12 = block_state1.fst + d * (uint32_t)1U;
        Lib_IntVector_Intrinsics_vec256 *wv_b13 = block_state1.fst + a0 * (uint32_t)1U;
        wv_a12[0U] = Lib_IntVector_Intrinsics_vec256_xor(wv_a12[0U], wv_b13[0U]);
        wv_a12[0U] = Lib_IntVector_Intrinsics_vec256_rotate_right64(wv_a12[0U], r23);
        Lib_IntVector_Intrinsics_vec256 *wv_a13 = block_state1.fst + c * (uint32_t)1U;
        Lib_IntVector_Intrinsics_vec256 *wv_b14 = block_state1.fst + d * (uint32_t)1U;
        wv_a13[0U] = Lib_IntVector_Intrinsics_vec256_add64(wv_a13[0U], wv_b14[0U]);
        Lib_IntVector_Intrinsics_vec256 *wv_a14 = block_state1.fst + b1 * (uint32_t)1U;
        Lib_IntVector_Intrinsics_vec256 *wv_b = block_state1.fst + c * (uint32_t)1U;
        wv_a14[0U] = Lib_IntVector_Intrinsics_vec256_xor(wv_a14[0U], wv_b[0U]);
        wv_a14[0U] = Lib_IntVector_Intrinsics_vec256_rotate_right64(wv_a14[0U], r33);
        Lib_IntVector_Intrinsics_vec256 *r13 = block_state1.fst + (uint32_t)1U * (uint32_t)1U;
        Lib_IntVector_Intrinsics_vec256 *r2 = block_state1.fst + (uint32_t)2U * (uint32_t)1U;
        Lib_IntVector_Intrinsics_vec256 *r3 = block_state1.fst + (uint32_t)3U * (uint32_t)1U;
        Lib_IntVector_Intrinsics_vec256 v0 = r13[0U];
        Lib_IntVector_Intrinsics_vec256
        v12 = Lib_IntVector_Intrinsics_vec256_rotate_right_lanes64(v0, (uint32_t)3U);
        r13[0U] = v12;
        Lib_IntVector_Intrinsics_vec256 v03 = r2[0U];
        Lib_IntVector_Intrinsics_vec256
        v13 = Lib_IntVector_Intrinsics_vec256_rotate_right_lanes64(v03, (uint32_t)2U);
        r2[0U] = v13;
        Lib_IntVector_Intrinsics_vec256 v04 = r3[0U];
        Lib_IntVector_Intrinsics_vec256
        v14 = Lib_IntVector_Intrinsics_vec256_rotate_right_lanes64(v04, (uint32_t)1U);
        r3[0U] = v14;
      }
      Lib_IntVector_Intrinsics_vec256 *s0 = block_state1.snd + (uint32_t)0U * (uint32_t)1U;
      Lib_IntVector_Intrinsics_vec256 *s11 = block_state1.snd + (uint32_t)1U * (uint32_t)1U;
      Lib_IntVector_Intrinsics_vec256 *r0 = block_state1.fst + (uint32_t)0U * (uint32_t)1U;
      Lib_IntVector_Intrinsics_vec256 *r1 = block_state1.fst + (uint32_t)1U * (uint32_t)1U;
      Lib_IntVector_Intrinsics_vec256 *r2 = block_state1.fst + (uint32_t)2U * (uint32_t)1U;
      Lib_IntVector_Intrinsics_vec256 *r3 = block_state1.fst + (uint32_t)3U * (uint32_t)1U;
      s0[0U] = Lib_IntVector_Intrinsics_vec256_xor(s0[0U], r0[0U]);
      s0[0U] = Lib_IntVector_Intrinsics_vec256_xor(s0[0U], r2[0U]);
      s11[0U] = Lib_IntVector_Intrinsics_vec256_xor(s11[0U], r1[0U]);
      s11[0U] = Lib_IntVector_Intrinsics_vec256_xor(s11[0U], r3[0U]);
    }
    uint8_t *dst = buf;
    memcpy(dst, data2, data2_len * sizeof (data2[0U]));
    *p
    =
      (
        (Hacl_Streaming_Functor_state_s__K____Lib_IntVector_Intrinsics_vec256___Lib_IntVector_Intrinsics_vec256____){
          .block_state = block_state1,
          .buf = buf,
          .total_len = total_len1 + (uint64_t)len
        }
      );
    return;
  }
  uint32_t diff = (uint32_t)128U - sz;
  uint8_t *data1 = data;
  uint8_t *data2 = data + diff;
  Hacl_Streaming_Functor_state_s__K____Lib_IntVector_Intrinsics_vec256___Lib_IntVector_Intrinsics_vec256____
  s2 = *p;
  K____Lib_IntVector_Intrinsics_vec256___Lib_IntVector_Intrinsics_vec256_
  block_state10 = s2.block_state;
  uint8_t *buf0 = s2.buf;
  uint64_t total_len10 = s2.total_len;
  uint32_t sz10;
  if (total_len10 % (uint64_t)(uint32_t)128U == (uint64_t)0U && total_len10 > (uint64_t)0U)
  {
    sz10 = (uint32_t)128U;
  }
  else
  {
    sz10 = (uint32_t)(total_len10 % (uint64_t)(uint32_t)128U);
  }
  uint8_t *buf2 = buf0 + sz10;
  memcpy(buf2, data1, diff * sizeof (data1[0U]));
  uint64_t total_len2 = total_len10 + (uint64_t)diff;
  *p
  =
    (
      (Hacl_Streaming_Functor_state_s__K____Lib_IntVector_Intrinsics_vec256___Lib_IntVector_Intrinsics_vec256____){
        .block_state = block_state10,
        .buf = buf0,
        .total_len = total_len2
      }
    );
  Hacl_Streaming_Functor_state_s__K____Lib_IntVector_Intrinsics_vec256___Lib_IntVector_Intrinsics_vec256____
  s20 = *p;
  K____Lib_IntVector_Intrinsics_vec256___Lib_IntVector_Intrinsics_vec256_
  block_state1 = s20.block_state;
  uint8_t *buf = s20.buf;
  uint64_t total_len1 = s20.total_len;
  uint32_t sz1;
  if (total_len1 % (uint64_t)(uint32_t)128U == (uint64_t)0U && total_len1 > (uint64_t)0U)
  {
    sz1 = (uint32_t)128U;
  }
  else
  {
    sz1 = (uint32_t)(total_len1 % (uint64_t)(uint32_t)128U);
  }
  if (!(sz1 == (uint32_t)0U))
  {
    uint64_t prevlen = total_len1 - (uint64_t)sz1;
    uint32_t nb = (uint32_t)1U;
    for (uint32_t i0 = (uint32_t)0U; i0 < nb; i0++)
    {
      uint64_t ite;
      if (key_size == (uint32_t)0U)
      {
        ite = prevlen;
      }
      else
      {
        ite = prevlen + (uint64_t)(uint32_t)128U;
      }
      FStar_UInt128_uint128
      totlen =
        FStar_UInt128_add_mod(FStar_UInt128_uint64_to_uint128(ite),
          FStar_UInt128_uint64_to_uint128((uint64_t)((i0 + (uint32_t)1U) * (uint32_t)128U)));
      uint8_t *b = buf + i0 * (uint32_t)128U;
      uint64_t m_w[16U] = { 0U };
      for (uint32_t i = (uint32_t)0U; i < (uint32_t)16U; i++)
      {
        uint64_t *os = m_w;
        uint8_t *bj = b + i * (uint32_t)8U;
        uint64_t u = load64_le(bj);
        uint64_t r = u;
        uint64_t x = r;
        os[i] = x;
      }
      Lib_IntVector_Intrinsics_vec256 mask = Lib_IntVector_Intrinsics_vec256_zero;
      uint64_t wv_14 = (uint64_t)0U;
      uint64_t wv_15 = (uint64_t)0U;
      mask =
        Lib_IntVector_Intrinsics_vec256_load64s(FStar_UInt128_uint128_to_uint64(totlen),
          FStar_UInt128_uint128_to_uint64(FStar_UInt128_shift_right(totlen, (uint32_t)64U)),
          wv_14,
          wv_15);
      memcpy(block_state1.fst,
        block_state1.snd,
        (uint32_t)4U * (uint32_t)1U * sizeof (block_state1.snd[0U]));
      Lib_IntVector_Intrinsics_vec256 *wv3 = block_state1.fst + (uint32_t)3U * (uint32_t)1U;
      wv3[0U] = Lib_IntVector_Intrinsics_vec256_xor(wv3[0U], mask);
      for (uint32_t i = (uint32_t)0U; i < (uint32_t)12U; i++)
      {
        uint32_t start_idx = i % (uint32_t)10U * (uint32_t)16U;
        KRML_CHECK_SIZE(sizeof (Lib_IntVector_Intrinsics_vec256), (uint32_t)4U * (uint32_t)1U);
        Lib_IntVector_Intrinsics_vec256 m_st[(uint32_t)4U * (uint32_t)1U];
        for (uint32_t _i = 0U; _i < (uint32_t)4U * (uint32_t)1U; ++_i)
          m_st[_i] = Lib_IntVector_Intrinsics_vec256_zero;
        Lib_IntVector_Intrinsics_vec256 *r00 = m_st + (uint32_t)0U * (uint32_t)1U;
        Lib_IntVector_Intrinsics_vec256 *r10 = m_st + (uint32_t)1U * (uint32_t)1U;
        Lib_IntVector_Intrinsics_vec256 *r20 = m_st + (uint32_t)2U * (uint32_t)1U;
        Lib_IntVector_Intrinsics_vec256 *r30 = m_st + (uint32_t)3U * (uint32_t)1U;
        uint32_t s0 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx];
        uint32_t s11 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)1U];
        uint32_t s21 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)2U];
        uint32_t s3 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)3U];
        uint32_t s4 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)4U];
        uint32_t s5 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)5U];
        uint32_t s6 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)6U];
        uint32_t s7 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)7U];
        uint32_t s8 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)8U];
        uint32_t s9 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)9U];
        uint32_t s10 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)10U];
        uint32_t s111 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)11U];
        uint32_t s12 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)12U];
        uint32_t s13 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)13U];
        uint32_t s14 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)14U];
        uint32_t s15 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)15U];
        r00[0U] = Lib_IntVector_Intrinsics_vec256_load64s(m_w[s0], m_w[s21], m_w[s4], m_w[s6]);
        r10[0U] = Lib_IntVector_Intrinsics_vec256_load64s(m_w[s11], m_w[s3], m_w[s5], m_w[s7]);
        r20[0U] = Lib_IntVector_Intrinsics_vec256_load64s(m_w[s8], m_w[s10], m_w[s12], m_w[s14]);
        r30[0U] = Lib_IntVector_Intrinsics_vec256_load64s(m_w[s9], m_w[s111], m_w[s13], m_w[s15]);
        Lib_IntVector_Intrinsics_vec256 *x = m_st + (uint32_t)0U * (uint32_t)1U;
        Lib_IntVector_Intrinsics_vec256 *y = m_st + (uint32_t)1U * (uint32_t)1U;
        Lib_IntVector_Intrinsics_vec256 *z = m_st + (uint32_t)2U * (uint32_t)1U;
        Lib_IntVector_Intrinsics_vec256 *w = m_st + (uint32_t)3U * (uint32_t)1U;
        uint32_t a = (uint32_t)0U;
        uint32_t b10 = (uint32_t)1U;
        uint32_t c0 = (uint32_t)2U;
        uint32_t d0 = (uint32_t)3U;
        uint32_t r01 = Hacl_Impl_Blake2_Constants_rTable_B[0U];
        uint32_t r11 = Hacl_Impl_Blake2_Constants_rTable_B[1U];
        uint32_t r21 = Hacl_Impl_Blake2_Constants_rTable_B[2U];
        uint32_t r31 = Hacl_Impl_Blake2_Constants_rTable_B[3U];
        Lib_IntVector_Intrinsics_vec256 *wv_a0 = block_state1.fst + a * (uint32_t)1U;
        Lib_IntVector_Intrinsics_vec256 *wv_b0 = block_state1.fst + b10 * (uint32_t)1U;
        wv_a0[0U] = Lib_IntVector_Intrinsics_vec256_add64(wv_a0[0U], wv_b0[0U]);
        wv_a0[0U] = Lib_IntVector_Intrinsics_vec256_add64(wv_a0[0U], x[0U]);
        Lib_IntVector_Intrinsics_vec256 *wv_a1 = block_state1.fst + d0 * (uint32_t)1U;
        Lib_IntVector_Intrinsics_vec256 *wv_b1 = block_state1.fst + a * (uint32_t)1U;
        wv_a1[0U] = Lib_IntVector_Intrinsics_vec256_xor(wv_a1[0U], wv_b1[0U]);
        wv_a1[0U] = Lib_IntVector_Intrinsics_vec256_rotate_right64(wv_a1[0U], r01);
        Lib_IntVector_Intrinsics_vec256 *wv_a2 = block_state1.fst + c0 * (uint32_t)1U;
        Lib_IntVector_Intrinsics_vec256 *wv_b2 = block_state1.fst + d0 * (uint32_t)1U;
        wv_a2[0U] = Lib_IntVector_Intrinsics_vec256_add64(wv_a2[0U], wv_b2[0U]);
        Lib_IntVector_Intrinsics_vec256 *wv_a3 = block_state1.fst + b10 * (uint32_t)1U;
        Lib_IntVector_Intrinsics_vec256 *wv_b3 = block_state1.fst + c0 * (uint32_t)1U;
        wv_a3[0U] = Lib_IntVector_Intrinsics_vec256_xor(wv_a3[0U], wv_b3[0U]);
        wv_a3[0U] = Lib_IntVector_Intrinsics_vec256_rotate_right64(wv_a3[0U], r11);
        Lib_IntVector_Intrinsics_vec256 *wv_a4 = block_state1.fst + a * (uint32_t)1U;
        Lib_IntVector_Intrinsics_vec256 *wv_b4 = block_state1.fst + b10 * (uint32_t)1U;
        wv_a4[0U] = Lib_IntVector_Intrinsics_vec256_add64(wv_a4[0U], wv_b4[0U]);
        wv_a4[0U] = Lib_IntVector_Intrinsics_vec256_add64(wv_a4[0U], y[0U]);
        Lib_IntVector_Intrinsics_vec256 *wv_a5 = block_state1.fst + d0 * (uint32_t)1U;
        Lib_IntVector_Intrinsics_vec256 *wv_b5 = block_state1.fst + a * (uint32_t)1U;
        wv_a5[0U] = Lib_IntVector_Intrinsics_vec256_xor(wv_a5[0U], wv_b5[0U]);
        wv_a5[0U] = Lib_IntVector_Intrinsics_vec256_rotate_right64(wv_a5[0U], r21);
        Lib_IntVector_Intrinsics_vec256 *wv_a6 = block_state1.fst + c0 * (uint32_t)1U;
        Lib_IntVector_Intrinsics_vec256 *wv_b6 = block_state1.fst + d0 * (uint32_t)1U;
        wv_a6[0U] = Lib_IntVector_Intrinsics_vec256_add64(wv_a6[0U], wv_b6[0U]);
        Lib_IntVector_Intrinsics_vec256 *wv_a7 = block_state1.fst + b10 * (uint32_t)1U;
        Lib_IntVector_Intrinsics_vec256 *wv_b7 = block_state1.fst + c0 * (uint32_t)1U;
        wv_a7[0U] = Lib_IntVector_Intrinsics_vec256_xor(wv_a7[0U], wv_b7[0U]);
        wv_a7[0U] = Lib_IntVector_Intrinsics_vec256_rotate_right64(wv_a7[0U], r31);
        Lib_IntVector_Intrinsics_vec256 *r12 = block_state1.fst + (uint32_t)1U * (uint32_t)1U;
        Lib_IntVector_Intrinsics_vec256 *r22 = block_state1.fst + (uint32_t)2U * (uint32_t)1U;
        Lib_IntVector_Intrinsics_vec256 *r32 = block_state1.fst + (uint32_t)3U * (uint32_t)1U;
        Lib_IntVector_Intrinsics_vec256 v00 = r12[0U];
        Lib_IntVector_Intrinsics_vec256
        v1 = Lib_IntVector_Intrinsics_vec256_rotate_right_lanes64(v00, (uint32_t)1U);
        r12[0U] = v1;
        Lib_IntVector_Intrinsics_vec256 v01 = r22[0U];
        Lib_IntVector_Intrinsics_vec256
        v10 = Lib_IntVector_Intrinsics_vec256_rotate_right_lanes64(v01, (uint32_t)2U);
        r22[0U] = v10;
        Lib_IntVector_Intrinsics_vec256 v02 = r32[0U];
        Lib_IntVector_Intrinsics_vec256
        v11 = Lib_IntVector_Intrinsics_vec256_rotate_right_lanes64(v02, (uint32_t)3U);
        r32[0U] = v11;
        uint32_t a0 = (uint32_t)0U;
        uint32_t b1 = (uint32_t)1U;
        uint32_t c = (uint32_t)2U;
        uint32_t d = (uint32_t)3U;
        uint32_t r0 = Hacl_Impl_Blake2_Constants_rTable_B[0U];
        uint32_t r1 = Hacl_Impl_Blake2_Constants_rTable_B[1U];
        uint32_t r23 = Hacl_Impl_Blake2_Constants_rTable_B[2U];
        uint32_t r33 = Hacl_Impl_Blake2_Constants_rTable_B[3U];
        Lib_IntVector_Intrinsics_vec256 *wv_a = block_state1.fst + a0 * (uint32_t)1U;
        Lib_IntVector_Intrinsics_vec256 *wv_b8 = block_state1.fst + b1 * (uint32_t)1U;
        wv_a[0U] = Lib_IntVector_Intrinsics_vec256_add64(wv_a[0U], wv_b8[0U]);
        wv_a[0U] = Lib_IntVector_Intrinsics_vec256_add64(wv_a[0U], z[0U]);
        Lib_IntVector_Intrinsics_vec256 *wv_a8 = block_state1.fst + d * (uint32_t)1U;
        Lib_IntVector_Intrinsics_vec256 *wv_b9 = block_state1.fst + a0 * (uint32_t)1U;
        wv_a8[0U] = Lib_IntVector_Intrinsics_vec256_xor(wv_a8[0U], wv_b9[0U]);
        wv_a8[0U] = Lib_IntVector_Intrinsics_vec256_rotate_right64(wv_a8[0U], r0);
        Lib_IntVector_Intrinsics_vec256 *wv_a9 = block_state1.fst + c * (uint32_t)1U;
        Lib_IntVector_Intrinsics_vec256 *wv_b10 = block_state1.fst + d * (uint32_t)1U;
        wv_a9[0U] = Lib_IntVector_Intrinsics_vec256_add64(wv_a9[0U], wv_b10[0U]);
        Lib_IntVector_Intrinsics_vec256 *wv_a10 = block_state1.fst + b1 * (uint32_t)1U;
        Lib_IntVector_Intrinsics_vec256 *wv_b11 = block_state1.fst + c * (uint32_t)1U;
        wv_a10[0U] = Lib_IntVector_Intrinsics_vec256_xor(wv_a10[0U], wv_b11[0U]);
        wv_a10[0U] = Lib_IntVector_Intrinsics_vec256_rotate_right64(wv_a10[0U], r1);
        Lib_IntVector_Intrinsics_vec256 *wv_a11 = block_state1.fst + a0 * (uint32_t)1U;
        Lib_IntVector_Intrinsics_vec256 *wv_b12 = block_state1.fst + b1 * (uint32_t)1U;
        wv_a11[0U] = Lib_IntVector_Intrinsics_vec256_add64(wv_a11[0U], wv_b12[0U]);
        wv_a11[0U] = Lib_IntVector_Intrinsics_vec256_add64(wv_a11[0U], w[0U]);
        Lib_IntVector_Intrinsics_vec256 *wv_a12 = block_state1.fst + d * (uint32_t)1U;
        Lib_IntVector_Intrinsics_vec256 *wv_b13 = block_state1.fst + a0 * (uint32_t)1U;
        wv_a12[0U] = Lib_IntVector_Intrinsics_vec256_xor(wv_a12[0U], wv_b13[0U]);
        wv_a12[0U] = Lib_IntVector_Intrinsics_vec256_rotate_right64(wv_a12[0U], r23);
        Lib_IntVector_Intrinsics_vec256 *wv_a13 = block_state1.fst + c * (uint32_t)1U;
        Lib_IntVector_Intrinsics_vec256 *wv_b14 = block_state1.fst + d * (uint32_t)1U;
        wv_a13[0U] = Lib_IntVector_Intrinsics_vec256_add64(wv_a13[0U], wv_b14[0U]);
        Lib_IntVector_Intrinsics_vec256 *wv_a14 = block_state1.fst + b1 * (uint32_t)1U;
        Lib_IntVector_Intrinsics_vec256 *wv_b = block_state1.fst + c * (uint32_t)1U;
        wv_a14[0U] = Lib_IntVector_Intrinsics_vec256_xor(wv_a14[0U], wv_b[0U]);
        wv_a14[0U] = Lib_IntVector_Intrinsics_vec256_rotate_right64(wv_a14[0U], r33);
        Lib_IntVector_Intrinsics_vec256 *r13 = block_state1.fst + (uint32_t)1U * (uint32_t)1U;
        Lib_IntVector_Intrinsics_vec256 *r2 = block_state1.fst + (uint32_t)2U * (uint32_t)1U;
        Lib_IntVector_Intrinsics_vec256 *r3 = block_state1.fst + (uint32_t)3U * (uint32_t)1U;
        Lib_IntVector_Intrinsics_vec256 v0 = r13[0U];
        Lib_IntVector_Intrinsics_vec256
        v12 = Lib_IntVector_Intrinsics_vec256_rotate_right_lanes64(v0, (uint32_t)3U);
        r13[0U] = v12;
        Lib_IntVector_Intrinsics_vec256 v03 = r2[0U];
        Lib_IntVector_Intrinsics_vec256
        v13 = Lib_IntVector_Intrinsics_vec256_rotate_right_lanes64(v03, (uint32_t)2U);
        r2[0U] = v13;
        Lib_IntVector_Intrinsics_vec256 v04 = r3[0U];
        Lib_IntVector_Intrinsics_vec256
        v14 = Lib_IntVector_Intrinsics_vec256_rotate_right_lanes64(v04, (uint32_t)1U);
        r3[0U] = v14;
      }
      Lib_IntVector_Intrinsics_vec256 *s0 = block_state1.snd + (uint32_t)0U * (uint32_t)1U;
      Lib_IntVector_Intrinsics_vec256 *s11 = block_state1.snd + (uint32_t)1U * (uint32_t)1U;
      Lib_IntVector_Intrinsics_vec256 *r0 = block_state1.fst + (uint32_t)0U * (uint32_t)1U;
      Lib_IntVector_Intrinsics_vec256 *r1 = block_state1.fst + (uint32_t)1U * (uint32_t)1U;
      Lib_IntVector_Intrinsics_vec256 *r2 = block_state1.fst + (uint32_t)2U * (uint32_t)1U;
      Lib_IntVector_Intrinsics_vec256 *r3 = block_state1.fst + (uint32_t)3U * (uint32_t)1U;
      s0[0U] = Lib_IntVector_Intrinsics_vec256_xor(s0[0U], r0[0U]);
      s0[0U] = Lib_IntVector_Intrinsics_vec256_xor(s0[0U], r2[0U]);
      s11[0U] = Lib_IntVector_Intrinsics_vec256_xor(s11[0U], r1[0U]);
      s11[0U] = Lib_IntVector_Intrinsics_vec256_xor(s11[0U], r3[0U]);
    }
  }
  uint32_t ite0;
  if
  (
    (uint64_t)(len - diff)
    % (uint64_t)(uint32_t)128U
    == (uint64_t)0U
    && (uint64_t)(len - diff) > (uint64_t)0U
  )
  {
    ite0 = (uint32_t)128U;
  }
  else
  {
    ite0 = (uint32_t)((uint64_t)(len - diff) % (uint64_t)(uint32_t)128U);
  }
  uint32_t n_blocks = (len - diff - ite0) / (uint32_t)128U;
  uint32_t data1_len = n_blocks * (uint32_t)128U;
  uint32_t data2_len = len - diff - data1_len;
  uint8_t *data11 = data2;
  uint8_t *data21 = data2 + data1_len;
  uint32_t nb = data1_len / (uint32_t)128U;
  for (uint32_t i0 = (uint32_t)0U; i0 < nb; i0++)
  {
    uint64_t ite;
    if (key_size == (uint32_t)0U)
    {
      ite = total_len1;
    }
    else
    {
      ite = total_len1 + (uint64_t)(uint32_t)128U;
    }
    FStar_UInt128_uint128
    totlen =
      FStar_UInt128_add_mod(FStar_UInt128_uint64_to_uint128(ite),
        FStar_UInt128_uint64_to_uint128((uint64_t)((i0 + (uint32_t)1U) * (uint32_t)128U)));
    uint8_t *b = data11 + i0 * (uint32_t)128U;
    uint64_t m_w[16U] = { 0U };
    for (uint32_t i = (uint32_t)0U; i < (uint32_t)16U; i++)
    {
      uint64_t *os = m_w;
      uint8_t *bj = b + i * (uint32_t)8U;
      uint64_t u = load64_le(bj);
      uint64_t r = u;
      uint64_t x = r;
      os[i] = x;
    }
    Lib_IntVector_Intrinsics_vec256 mask = Lib_IntVector_Intrinsics_vec256_zero;
    uint64_t wv_14 = (uint64_t)0U;
    uint64_t wv_15 = (uint64_t)0U;
    mask =
      Lib_IntVector_Intrinsics_vec256_load64s(FStar_UInt128_uint128_to_uint64(totlen),
        FStar_UInt128_uint128_to_uint64(FStar_UInt128_shift_right(totlen, (uint32_t)64U)),
        wv_14,
        wv_15);
    memcpy(block_state1.fst,
      block_state1.snd,
      (uint32_t)4U * (uint32_t)1U * sizeof (block_state1.snd[0U]));
    Lib_IntVector_Intrinsics_vec256 *wv3 = block_state1.fst + (uint32_t)3U * (uint32_t)1U;
    wv3[0U] = Lib_IntVector_Intrinsics_vec256_xor(wv3[0U], mask);
    for (uint32_t i = (uint32_t)0U; i < (uint32_t)12U; i++)
    {
      uint32_t start_idx = i % (uint32_t)10U * (uint32_t)16U;
      KRML_CHECK_SIZE(sizeof (Lib_IntVector_Intrinsics_vec256), (uint32_t)4U * (uint32_t)1U);
      Lib_IntVector_Intrinsics_vec256 m_st[(uint32_t)4U * (uint32_t)1U];
      for (uint32_t _i = 0U; _i < (uint32_t)4U * (uint32_t)1U; ++_i)
        m_st[_i] = Lib_IntVector_Intrinsics_vec256_zero;
      Lib_IntVector_Intrinsics_vec256 *r00 = m_st + (uint32_t)0U * (uint32_t)1U;
      Lib_IntVector_Intrinsics_vec256 *r10 = m_st + (uint32_t)1U * (uint32_t)1U;
      Lib_IntVector_Intrinsics_vec256 *r20 = m_st + (uint32_t)2U * (uint32_t)1U;
      Lib_IntVector_Intrinsics_vec256 *r30 = m_st + (uint32_t)3U * (uint32_t)1U;
      uint32_t s0 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx];
      uint32_t s11 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)1U];
      uint32_t s21 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)2U];
      uint32_t s3 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)3U];
      uint32_t s4 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)4U];
      uint32_t s5 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)5U];
      uint32_t s6 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)6U];
      uint32_t s7 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)7U];
      uint32_t s8 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)8U];
      uint32_t s9 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)9U];
      uint32_t s10 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)10U];
      uint32_t s111 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)11U];
      uint32_t s12 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)12U];
      uint32_t s13 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)13U];
      uint32_t s14 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)14U];
      uint32_t s15 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)15U];
      r00[0U] = Lib_IntVector_Intrinsics_vec256_load64s(m_w[s0], m_w[s21], m_w[s4], m_w[s6]);
      r10[0U] = Lib_IntVector_Intrinsics_vec256_load64s(m_w[s11], m_w[s3], m_w[s5], m_w[s7]);
      r20[0U] = Lib_IntVector_Intrinsics_vec256_load64s(m_w[s8], m_w[s10], m_w[s12], m_w[s14]);
      r30[0U] = Lib_IntVector_Intrinsics_vec256_load64s(m_w[s9], m_w[s111], m_w[s13], m_w[s15]);
      Lib_IntVector_Intrinsics_vec256 *x = m_st + (uint32_t)0U * (uint32_t)1U;
      Lib_IntVector_Intrinsics_vec256 *y = m_st + (uint32_t)1U * (uint32_t)1U;
      Lib_IntVector_Intrinsics_vec256 *z = m_st + (uint32_t)2U * (uint32_t)1U;
      Lib_IntVector_Intrinsics_vec256 *w = m_st + (uint32_t)3U * (uint32_t)1U;
      uint32_t a = (uint32_t)0U;
      uint32_t b10 = (uint32_t)1U;
      uint32_t c0 = (uint32_t)2U;
      uint32_t d0 = (uint32_t)3U;
      uint32_t r01 = Hacl_Impl_Blake2_Constants_rTable_B[0U];
      uint32_t r11 = Hacl_Impl_Blake2_Constants_rTable_B[1U];
      uint32_t r21 = Hacl_Impl_Blake2_Constants_rTable_B[2U];
      uint32_t r31 = Hacl_Impl_Blake2_Constants_rTable_B[3U];
      Lib_IntVector_Intrinsics_vec256 *wv_a0 = block_state1.fst + a * (uint32_t)1U;
      Lib_IntVector_Intrinsics_vec256 *wv_b0 = block_state1.fst + b10 * (uint32_t)1U;
      wv_a0[0U] = Lib_IntVector_Intrinsics_vec256_add64(wv_a0[0U], wv_b0[0U]);
      wv_a0[0U] = Lib_IntVector_Intrinsics_vec256_add64(wv_a0[0U], x[0U]);
      Lib_IntVector_Intrinsics_vec256 *wv_a1 = block_state1.fst + d0 * (uint32_t)1U;
      Lib_IntVector_Intrinsics_vec256 *wv_b1 = block_state1.fst + a * (uint32_t)1U;
      wv_a1[0U] = Lib_IntVector_Intrinsics_vec256_xor(wv_a1[0U], wv_b1[0U]);
      wv_a1[0U] = Lib_IntVector_Intrinsics_vec256_rotate_right64(wv_a1[0U], r01);
      Lib_IntVector_Intrinsics_vec256 *wv_a2 = block_state1.fst + c0 * (uint32_t)1U;
      Lib_IntVector_Intrinsics_vec256 *wv_b2 = block_state1.fst + d0 * (uint32_t)1U;
      wv_a2[0U] = Lib_IntVector_Intrinsics_vec256_add64(wv_a2[0U], wv_b2[0U]);
      Lib_IntVector_Intrinsics_vec256 *wv_a3 = block_state1.fst + b10 * (uint32_t)1U;
      Lib_IntVector_Intrinsics_vec256 *wv_b3 = block_state1.fst + c0 * (uint32_t)1U;
      wv_a3[0U] = Lib_IntVector_Intrinsics_vec256_xor(wv_a3[0U], wv_b3[0U]);
      wv_a3[0U] = Lib_IntVector_Intrinsics_vec256_rotate_right64(wv_a3[0U], r11);
      Lib_IntVector_Intrinsics_vec256 *wv_a4 = block_state1.fst + a * (uint32_t)1U;
      Lib_IntVector_Intrinsics_vec256 *wv_b4 = block_state1.fst + b10 * (uint32_t)1U;
      wv_a4[0U] = Lib_IntVector_Intrinsics_vec256_add64(wv_a4[0U], wv_b4[0U]);
      wv_a4[0U] = Lib_IntVector_Intrinsics_vec256_add64(wv_a4[0U], y[0U]);
      Lib_IntVector_Intrinsics_vec256 *wv_a5 = block_state1.fst + d0 * (uint32_t)1U;
      Lib_IntVector_Intrinsics_vec256 *wv_b5 = block_state1.fst + a * (uint32_t)1U;
      wv_a5[0U] = Lib_IntVector_Intrinsics_vec256_xor(wv_a5[0U], wv_b5[0U]);
      wv_a5[0U] = Lib_IntVector_Intrinsics_vec256_rotate_right64(wv_a5[0U], r21);
      Lib_IntVector_Intrinsics_vec256 *wv_a6 = block_state1.fst + c0 * (uint32_t)1U;
      Lib_IntVector_Intrinsics_vec256 *wv_b6 = block_state1.fst + d0 * (uint32_t)1U;
      wv_a6[0U] = Lib_IntVector_Intrinsics_vec256_add64(wv_a6[0U], wv_b6[0U]);
      Lib_IntVector_Intrinsics_vec256 *wv_a7 = block_state1.fst + b10 * (uint32_t)1U;
      Lib_IntVector_Intrinsics_vec256 *wv_b7 = block_state1.fst + c0 * (uint32_t)1U;
      wv_a7[0U] = Lib_IntVector_Intrinsics_vec256_xor(wv_a7[0U], wv_b7[0U]);
      wv_a7[0U] = Lib_IntVector_Intrinsics_vec256_rotate_right64(wv_a7[0U], r31);
      Lib_IntVector_Intrinsics_vec256 *r12 = block_state1.fst + (uint32_t)1U * (uint32_t)1U;
      Lib_IntVector_Intrinsics_vec256 *r22 = block_state1.fst + (uint32_t)2U * (uint32_t)1U;
      Lib_IntVector_Intrinsics_vec256 *r32 = block_state1.fst + (uint32_t)3U * (uint32_t)1U;
      Lib_IntVector_Intrinsics_vec256 v00 = r12[0U];
      Lib_IntVector_Intrinsics_vec256
      v1 = Lib_IntVector_Intrinsics_vec256_rotate_right_lanes64(v00, (uint32_t)1U);
      r12[0U] = v1;
      Lib_IntVector_Intrinsics_vec256 v01 = r22[0U];
      Lib_IntVector_Intrinsics_vec256
      v10 = Lib_IntVector_Intrinsics_vec256_rotate_right_lanes64(v01, (uint32_t)2U);
      r22[0U] = v10;
      Lib_IntVector_Intrinsics_vec256 v02 = r32[0U];
      Lib_IntVector_Intrinsics_vec256
      v11 = Lib_IntVector_Intrinsics_vec256_rotate_right_lanes64(v02, (uint32_t)3U);
      r32[0U] = v11;
      uint32_t a0 = (uint32_t)0U;
      uint32_t b1 = (uint32_t)1U;
      uint32_t c = (uint32_t)2U;
      uint32_t d = (uint32_t)3U;
      uint32_t r0 = Hacl_Impl_Blake2_Constants_rTable_B[0U];
      uint32_t r1 = Hacl_Impl_Blake2_Constants_rTable_B[1U];
      uint32_t r23 = Hacl_Impl_Blake2_Constants_rTable_B[2U];
      uint32_t r33 = Hacl_Impl_Blake2_Constants_rTable_B[3U];
      Lib_IntVector_Intrinsics_vec256 *wv_a = block_state1.fst + a0 * (uint32_t)1U;
      Lib_IntVector_Intrinsics_vec256 *wv_b8 = block_state1.fst + b1 * (uint32_t)1U;
      wv_a[0U] = Lib_IntVector_Intrinsics_vec256_add64(wv_a[0U], wv_b8[0U]);
      wv_a[0U] = Lib_IntVector_Intrinsics_vec256_add64(wv_a[0U], z[0U]);
      Lib_IntVector_Intrinsics_vec256 *wv_a8 = block_state1.fst + d * (uint32_t)1U;
      Lib_IntVector_Intrinsics_vec256 *wv_b9 = block_state1.fst + a0 * (uint32_t)1U;
      wv_a8[0U] = Lib_IntVector_Intrinsics_vec256_xor(wv_a8[0U], wv_b9[0U]);
      wv_a8[0U] = Lib_IntVector_Intrinsics_vec256_rotate_right64(wv_a8[0U], r0);
      Lib_IntVector_Intrinsics_vec256 *wv_a9 = block_state1.fst + c * (uint32_t)1U;
      Lib_IntVector_Intrinsics_vec256 *wv_b10 = block_state1.fst + d * (uint32_t)1U;
      wv_a9[0U] = Lib_IntVector_Intrinsics_vec256_add64(wv_a9[0U], wv_b10[0U]);
      Lib_IntVector_Intrinsics_vec256 *wv_a10 = block_state1.fst + b1 * (uint32_t)1U;
      Lib_IntVector_Intrinsics_vec256 *wv_b11 = block_state1.fst + c * (uint32_t)1U;
      wv_a10[0U] = Lib_IntVector_Intrinsics_vec256_xor(wv_a10[0U], wv_b11[0U]);
      wv_a10[0U] = Lib_IntVector_Intrinsics_vec256_rotate_right64(wv_a10[0U], r1);
      Lib_IntVector_Intrinsics_vec256 *wv_a11 = block_state1.fst + a0 * (uint32_t)1U;
      Lib_IntVector_Intrinsics_vec256 *wv_b12 = block_state1.fst + b1 * (uint32_t)1U;
      wv_a11[0U] = Lib_IntVector_Intrinsics_vec256_add64(wv_a11[0U], wv_b12[0U]);
      wv_a11[0U] = Lib_IntVector_Intrinsics_vec256_add64(wv_a11[0U], w[0U]);
      Lib_IntVector_Intrinsics_vec256 *wv_a12 = block_state1.fst + d * (uint32_t)1U;
      Lib_IntVector_Intrinsics_vec256 *wv_b13 = block_state1.fst + a0 * (uint32_t)1U;
      wv_a12[0U] = Lib_IntVector_Intrinsics_vec256_xor(wv_a12[0U], wv_b13[0U]);
      wv_a12[0U] = Lib_IntVector_Intrinsics_vec256_rotate_right64(wv_a12[0U], r23);
      Lib_IntVector_Intrinsics_vec256 *wv_a13 = block_state1.fst + c * (uint32_t)1U;
      Lib_IntVector_Intrinsics_vec256 *wv_b14 = block_state1.fst + d * (uint32_t)1U;
      wv_a13[0U] = Lib_IntVector_Intrinsics_vec256_add64(wv_a13[0U], wv_b14[0U]);
      Lib_IntVector_Intrinsics_vec256 *wv_a14 = block_state1.fst + b1 * (uint32_t)1U;
      Lib_IntVector_Intrinsics_vec256 *wv_b = block_state1.fst + c * (uint32_t)1U;
      wv_a14[0U] = Lib_IntVector_Intrinsics_vec256_xor(wv_a14[0U], wv_b[0U]);
      wv_a14[0U] = Lib_IntVector_Intrinsics_vec256_rotate_right64(wv_a14[0U], r33);
      Lib_IntVector_Intrinsics_vec256 *r13 = block_state1.fst + (uint32_t)1U * (uint32_t)1U;
      Lib_IntVector_Intrinsics_vec256 *r2 = block_state1.fst + (uint32_t)2U * (uint32_t)1U;
      Lib_IntVector_Intrinsics_vec256 *r3 = block_state1.fst + (uint32_t)3U * (uint32_t)1U;
      Lib_IntVector_Intrinsics_vec256 v0 = r13[0U];
      Lib_IntVector_Intrinsics_vec256
      v12 = Lib_IntVector_Intrinsics_vec256_rotate_right_lanes64(v0, (uint32_t)3U);
      r13[0U] = v12;
      Lib_IntVector_Intrinsics_vec256 v03 = r2[0U];
      Lib_IntVector_Intrinsics_vec256
      v13 = Lib_IntVector_Intrinsics_vec256_rotate_right_lanes64(v03, (uint32_t)2U);
      r2[0U] = v13;
      Lib_IntVector_Intrinsics_vec256 v04 = r3[0U];
      Lib_IntVector_Intrinsics_vec256
      v14 = Lib_IntVector_Intrinsics_vec256_rotate_right_lanes64(v04, (uint32_t)1U);
      r3[0U] = v14;
    }
    Lib_IntVector_Intrinsics_vec256 *s0 = block_state1.snd + (uint32_t)0U * (uint32_t)1U;
    Lib_IntVector_Intrinsics_vec256 *s11 = block_state1.snd + (uint32_t)1U * (uint32_t)1U;
    Lib_IntVector_Intrinsics_vec256 *r0 = block_state1.fst + (uint32_t)0U * (uint32_t)1U;
    Lib_IntVector_Intrinsics_vec256 *r1 = block_state1.fst + (uint32_t)1U * (uint32_t)1U;
    Lib_IntVector_Intrinsics_vec256 *r2 = block_state1.fst + (uint32_t)2U * (uint32_t)1U;
    Lib_IntVector_Intrinsics_vec256 *r3 = block_state1.fst + (uint32_t)3U * (uint32_t)1U;
    s0[0U] = Lib_IntVector_Intrinsics_vec256_xor(s0[0U], r0[0U]);
    s0[0U] = Lib_IntVector_Intrinsics_vec256_xor(s0[0U], r2[0U]);
    s11[0U] = Lib_IntVector_Intrinsics_vec256_xor(s11[0U], r1[0U]);
    s11[0U] = Lib_IntVector_Intrinsics_vec256_xor(s11[0U], r3[0U]);
  }
  uint8_t *dst = buf;
  memcpy(dst, data21, data2_len * sizeof (data21[0U]));
  *p
  =
    (
      (Hacl_Streaming_Functor_state_s__K____Lib_IntVector_Intrinsics_vec256___Lib_IntVector_Intrinsics_vec256____){
        .block_state = block_state1,
        .buf = buf,
        .total_len = total_len1 + (uint64_t)(len - diff)
      }
    );
}

/* SNIPPET_END: Hacl_Streaming_Blake2_blake2b_256_with_key_update */

/* SNIPPET_START: Hacl_Streaming_Blake2_blake2b_256_with_key_finish */

/*
  Finish function when using a (potentially null) key
*/
void
Hacl_Streaming_Blake2_blake2b_256_with_key_finish(
  uint32_t key_size,
  Hacl_Streaming_Functor_state_s__K____Lib_IntVector_Intrinsics_vec256___Lib_IntVector_Intrinsics_vec256____
  *p,
  uint8_t *dst
)
{
  Hacl_Streaming_Functor_state_s__K____Lib_IntVector_Intrinsics_vec256___Lib_IntVector_Intrinsics_vec256____
  scrut = *p;
  K____Lib_IntVector_Intrinsics_vec256___Lib_IntVector_Intrinsics_vec256_
  block_state = scrut.block_state;
  uint8_t *buf_ = scrut.buf;
  uint64_t total_len = scrut.total_len;
  uint32_t r;
  if (total_len % (uint64_t)(uint32_t)128U == (uint64_t)0U && total_len > (uint64_t)0U)
  {
    r = (uint32_t)128U;
  }
  else
  {
    r = (uint32_t)(total_len % (uint64_t)(uint32_t)128U);
  }
  uint8_t *buf_1 = buf_;
  KRML_CHECK_SIZE(sizeof (Lib_IntVector_Intrinsics_vec256), (uint32_t)4U * (uint32_t)1U);
  Lib_IntVector_Intrinsics_vec256 wv[(uint32_t)4U * (uint32_t)1U];
  for (uint32_t _i = 0U; _i < (uint32_t)4U * (uint32_t)1U; ++_i)
    wv[_i] = Lib_IntVector_Intrinsics_vec256_zero;
  KRML_CHECK_SIZE(sizeof (Lib_IntVector_Intrinsics_vec256), (uint32_t)4U * (uint32_t)1U);
  Lib_IntVector_Intrinsics_vec256 b0[(uint32_t)4U * (uint32_t)1U];
  for (uint32_t _i = 0U; _i < (uint32_t)4U * (uint32_t)1U; ++_i)
    b0[_i] = Lib_IntVector_Intrinsics_vec256_zero;
  K____Lib_IntVector_Intrinsics_vec256___Lib_IntVector_Intrinsics_vec256_
  tmp_block_state = { .fst = wv, .snd = b0 };
  Lib_IntVector_Intrinsics_vec256 *src_b = block_state.snd;
  Lib_IntVector_Intrinsics_vec256 *dst_b = tmp_block_state.snd;
  memcpy(dst_b, src_b, (uint32_t)4U * sizeof (src_b[0U]));
  uint64_t prev_len = total_len - (uint64_t)r;
  uint8_t b2[128U] = { 0U };
  uint8_t *last = buf_1 + r - r;
  memcpy(b2, last, r * sizeof (last[0U]));
  uint64_t ite;
  if (key_size == (uint32_t)0U)
  {
    ite = prev_len;
  }
  else
  {
    ite = prev_len + (uint64_t)(uint32_t)128U;
  }
  FStar_UInt128_uint128
  totlen =
    FStar_UInt128_add_mod(FStar_UInt128_uint64_to_uint128(ite),
      FStar_UInt128_uint64_to_uint128((uint64_t)r));
  uint64_t m_w[16U] = { 0U };
  for (uint32_t i = (uint32_t)0U; i < (uint32_t)16U; i++)
  {
    uint64_t *os = m_w;
    uint8_t *bj = b2 + i * (uint32_t)8U;
    uint64_t u = load64_le(bj);
    uint64_t r1 = u;
    uint64_t x = r1;
    os[i] = x;
  }
  Lib_IntVector_Intrinsics_vec256 mask = Lib_IntVector_Intrinsics_vec256_zero;
  uint64_t wv_14 = (uint64_t)0xFFFFFFFFFFFFFFFFU;
  uint64_t wv_15 = (uint64_t)0U;
  mask =
    Lib_IntVector_Intrinsics_vec256_load64s(FStar_UInt128_uint128_to_uint64(totlen),
      FStar_UInt128_uint128_to_uint64(FStar_UInt128_shift_right(totlen, (uint32_t)64U)),
      wv_14,
      wv_15);
  memcpy(tmp_block_state.fst,
    tmp_block_state.snd,
    (uint32_t)4U * (uint32_t)1U * sizeof (tmp_block_state.snd[0U]));
  Lib_IntVector_Intrinsics_vec256 *wv3 = tmp_block_state.fst + (uint32_t)3U * (uint32_t)1U;
  wv3[0U] = Lib_IntVector_Intrinsics_vec256_xor(wv3[0U], mask);
  for (uint32_t i = (uint32_t)0U; i < (uint32_t)12U; i++)
  {
    uint32_t start_idx = i % (uint32_t)10U * (uint32_t)16U;
    KRML_CHECK_SIZE(sizeof (Lib_IntVector_Intrinsics_vec256), (uint32_t)4U * (uint32_t)1U);
    Lib_IntVector_Intrinsics_vec256 m_st[(uint32_t)4U * (uint32_t)1U];
    for (uint32_t _i = 0U; _i < (uint32_t)4U * (uint32_t)1U; ++_i)
      m_st[_i] = Lib_IntVector_Intrinsics_vec256_zero;
    Lib_IntVector_Intrinsics_vec256 *r00 = m_st + (uint32_t)0U * (uint32_t)1U;
    Lib_IntVector_Intrinsics_vec256 *r10 = m_st + (uint32_t)1U * (uint32_t)1U;
    Lib_IntVector_Intrinsics_vec256 *r20 = m_st + (uint32_t)2U * (uint32_t)1U;
    Lib_IntVector_Intrinsics_vec256 *r30 = m_st + (uint32_t)3U * (uint32_t)1U;
    uint32_t s0 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx];
    uint32_t s1 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)1U];
    uint32_t s2 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)2U];
    uint32_t s3 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)3U];
    uint32_t s4 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)4U];
    uint32_t s5 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)5U];
    uint32_t s6 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)6U];
    uint32_t s7 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)7U];
    uint32_t s8 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)8U];
    uint32_t s9 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)9U];
    uint32_t s10 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)10U];
    uint32_t s11 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)11U];
    uint32_t s12 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)12U];
    uint32_t s13 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)13U];
    uint32_t s14 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)14U];
    uint32_t s15 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)15U];
    r00[0U] = Lib_IntVector_Intrinsics_vec256_load64s(m_w[s0], m_w[s2], m_w[s4], m_w[s6]);
    r10[0U] = Lib_IntVector_Intrinsics_vec256_load64s(m_w[s1], m_w[s3], m_w[s5], m_w[s7]);
    r20[0U] = Lib_IntVector_Intrinsics_vec256_load64s(m_w[s8], m_w[s10], m_w[s12], m_w[s14]);
    r30[0U] = Lib_IntVector_Intrinsics_vec256_load64s(m_w[s9], m_w[s11], m_w[s13], m_w[s15]);
    Lib_IntVector_Intrinsics_vec256 *x = m_st + (uint32_t)0U * (uint32_t)1U;
    Lib_IntVector_Intrinsics_vec256 *y = m_st + (uint32_t)1U * (uint32_t)1U;
    Lib_IntVector_Intrinsics_vec256 *z = m_st + (uint32_t)2U * (uint32_t)1U;
    Lib_IntVector_Intrinsics_vec256 *w = m_st + (uint32_t)3U * (uint32_t)1U;
    uint32_t a = (uint32_t)0U;
    uint32_t b10 = (uint32_t)1U;
    uint32_t c0 = (uint32_t)2U;
    uint32_t d0 = (uint32_t)3U;
    uint32_t r01 = Hacl_Impl_Blake2_Constants_rTable_B[0U];
    uint32_t r11 = Hacl_Impl_Blake2_Constants_rTable_B[1U];
    uint32_t r21 = Hacl_Impl_Blake2_Constants_rTable_B[2U];
    uint32_t r31 = Hacl_Impl_Blake2_Constants_rTable_B[3U];
    Lib_IntVector_Intrinsics_vec256 *wv_a0 = tmp_block_state.fst + a * (uint32_t)1U;
    Lib_IntVector_Intrinsics_vec256 *wv_b0 = tmp_block_state.fst + b10 * (uint32_t)1U;
    wv_a0[0U] = Lib_IntVector_Intrinsics_vec256_add64(wv_a0[0U], wv_b0[0U]);
    wv_a0[0U] = Lib_IntVector_Intrinsics_vec256_add64(wv_a0[0U], x[0U]);
    Lib_IntVector_Intrinsics_vec256 *wv_a1 = tmp_block_state.fst + d0 * (uint32_t)1U;
    Lib_IntVector_Intrinsics_vec256 *wv_b1 = tmp_block_state.fst + a * (uint32_t)1U;
    wv_a1[0U] = Lib_IntVector_Intrinsics_vec256_xor(wv_a1[0U], wv_b1[0U]);
    wv_a1[0U] = Lib_IntVector_Intrinsics_vec256_rotate_right64(wv_a1[0U], r01);
    Lib_IntVector_Intrinsics_vec256 *wv_a2 = tmp_block_state.fst + c0 * (uint32_t)1U;
    Lib_IntVector_Intrinsics_vec256 *wv_b2 = tmp_block_state.fst + d0 * (uint32_t)1U;
    wv_a2[0U] = Lib_IntVector_Intrinsics_vec256_add64(wv_a2[0U], wv_b2[0U]);
    Lib_IntVector_Intrinsics_vec256 *wv_a3 = tmp_block_state.fst + b10 * (uint32_t)1U;
    Lib_IntVector_Intrinsics_vec256 *wv_b3 = tmp_block_state.fst + c0 * (uint32_t)1U;
    wv_a3[0U] = Lib_IntVector_Intrinsics_vec256_xor(wv_a3[0U], wv_b3[0U]);
    wv_a3[0U] = Lib_IntVector_Intrinsics_vec256_rotate_right64(wv_a3[0U], r11);
    Lib_IntVector_Intrinsics_vec256 *wv_a4 = tmp_block_state.fst + a * (uint32_t)1U;
    Lib_IntVector_Intrinsics_vec256 *wv_b4 = tmp_block_state.fst + b10 * (uint32_t)1U;
    wv_a4[0U] = Lib_IntVector_Intrinsics_vec256_add64(wv_a4[0U], wv_b4[0U]);
    wv_a4[0U] = Lib_IntVector_Intrinsics_vec256_add64(wv_a4[0U], y[0U]);
    Lib_IntVector_Intrinsics_vec256 *wv_a5 = tmp_block_state.fst + d0 * (uint32_t)1U;
    Lib_IntVector_Intrinsics_vec256 *wv_b5 = tmp_block_state.fst + a * (uint32_t)1U;
    wv_a5[0U] = Lib_IntVector_Intrinsics_vec256_xor(wv_a5[0U], wv_b5[0U]);
    wv_a5[0U] = Lib_IntVector_Intrinsics_vec256_rotate_right64(wv_a5[0U], r21);
    Lib_IntVector_Intrinsics_vec256 *wv_a6 = tmp_block_state.fst + c0 * (uint32_t)1U;
    Lib_IntVector_Intrinsics_vec256 *wv_b6 = tmp_block_state.fst + d0 * (uint32_t)1U;
    wv_a6[0U] = Lib_IntVector_Intrinsics_vec256_add64(wv_a6[0U], wv_b6[0U]);
    Lib_IntVector_Intrinsics_vec256 *wv_a7 = tmp_block_state.fst + b10 * (uint32_t)1U;
    Lib_IntVector_Intrinsics_vec256 *wv_b7 = tmp_block_state.fst + c0 * (uint32_t)1U;
    wv_a7[0U] = Lib_IntVector_Intrinsics_vec256_xor(wv_a7[0U], wv_b7[0U]);
    wv_a7[0U] = Lib_IntVector_Intrinsics_vec256_rotate_right64(wv_a7[0U], r31);
    Lib_IntVector_Intrinsics_vec256 *r12 = tmp_block_state.fst + (uint32_t)1U * (uint32_t)1U;
    Lib_IntVector_Intrinsics_vec256 *r22 = tmp_block_state.fst + (uint32_t)2U * (uint32_t)1U;
    Lib_IntVector_Intrinsics_vec256 *r32 = tmp_block_state.fst + (uint32_t)3U * (uint32_t)1U;
    Lib_IntVector_Intrinsics_vec256 v00 = r12[0U];
    Lib_IntVector_Intrinsics_vec256
    v1 = Lib_IntVector_Intrinsics_vec256_rotate_right_lanes64(v00, (uint32_t)1U);
    r12[0U] = v1;
    Lib_IntVector_Intrinsics_vec256 v01 = r22[0U];
    Lib_IntVector_Intrinsics_vec256
    v10 = Lib_IntVector_Intrinsics_vec256_rotate_right_lanes64(v01, (uint32_t)2U);
    r22[0U] = v10;
    Lib_IntVector_Intrinsics_vec256 v02 = r32[0U];
    Lib_IntVector_Intrinsics_vec256
    v11 = Lib_IntVector_Intrinsics_vec256_rotate_right_lanes64(v02, (uint32_t)3U);
    r32[0U] = v11;
    uint32_t a0 = (uint32_t)0U;
    uint32_t b1 = (uint32_t)1U;
    uint32_t c = (uint32_t)2U;
    uint32_t d = (uint32_t)3U;
    uint32_t r0 = Hacl_Impl_Blake2_Constants_rTable_B[0U];
    uint32_t r1 = Hacl_Impl_Blake2_Constants_rTable_B[1U];
    uint32_t r23 = Hacl_Impl_Blake2_Constants_rTable_B[2U];
    uint32_t r33 = Hacl_Impl_Blake2_Constants_rTable_B[3U];
    Lib_IntVector_Intrinsics_vec256 *wv_a = tmp_block_state.fst + a0 * (uint32_t)1U;
    Lib_IntVector_Intrinsics_vec256 *wv_b8 = tmp_block_state.fst + b1 * (uint32_t)1U;
    wv_a[0U] = Lib_IntVector_Intrinsics_vec256_add64(wv_a[0U], wv_b8[0U]);
    wv_a[0U] = Lib_IntVector_Intrinsics_vec256_add64(wv_a[0U], z[0U]);
    Lib_IntVector_Intrinsics_vec256 *wv_a8 = tmp_block_state.fst + d * (uint32_t)1U;
    Lib_IntVector_Intrinsics_vec256 *wv_b9 = tmp_block_state.fst + a0 * (uint32_t)1U;
    wv_a8[0U] = Lib_IntVector_Intrinsics_vec256_xor(wv_a8[0U], wv_b9[0U]);
    wv_a8[0U] = Lib_IntVector_Intrinsics_vec256_rotate_right64(wv_a8[0U], r0);
    Lib_IntVector_Intrinsics_vec256 *wv_a9 = tmp_block_state.fst + c * (uint32_t)1U;
    Lib_IntVector_Intrinsics_vec256 *wv_b10 = tmp_block_state.fst + d * (uint32_t)1U;
    wv_a9[0U] = Lib_IntVector_Intrinsics_vec256_add64(wv_a9[0U], wv_b10[0U]);
    Lib_IntVector_Intrinsics_vec256 *wv_a10 = tmp_block_state.fst + b1 * (uint32_t)1U;
    Lib_IntVector_Intrinsics_vec256 *wv_b11 = tmp_block_state.fst + c * (uint32_t)1U;
    wv_a10[0U] = Lib_IntVector_Intrinsics_vec256_xor(wv_a10[0U], wv_b11[0U]);
    wv_a10[0U] = Lib_IntVector_Intrinsics_vec256_rotate_right64(wv_a10[0U], r1);
    Lib_IntVector_Intrinsics_vec256 *wv_a11 = tmp_block_state.fst + a0 * (uint32_t)1U;
    Lib_IntVector_Intrinsics_vec256 *wv_b12 = tmp_block_state.fst + b1 * (uint32_t)1U;
    wv_a11[0U] = Lib_IntVector_Intrinsics_vec256_add64(wv_a11[0U], wv_b12[0U]);
    wv_a11[0U] = Lib_IntVector_Intrinsics_vec256_add64(wv_a11[0U], w[0U]);
    Lib_IntVector_Intrinsics_vec256 *wv_a12 = tmp_block_state.fst + d * (uint32_t)1U;
    Lib_IntVector_Intrinsics_vec256 *wv_b13 = tmp_block_state.fst + a0 * (uint32_t)1U;
    wv_a12[0U] = Lib_IntVector_Intrinsics_vec256_xor(wv_a12[0U], wv_b13[0U]);
    wv_a12[0U] = Lib_IntVector_Intrinsics_vec256_rotate_right64(wv_a12[0U], r23);
    Lib_IntVector_Intrinsics_vec256 *wv_a13 = tmp_block_state.fst + c * (uint32_t)1U;
    Lib_IntVector_Intrinsics_vec256 *wv_b14 = tmp_block_state.fst + d * (uint32_t)1U;
    wv_a13[0U] = Lib_IntVector_Intrinsics_vec256_add64(wv_a13[0U], wv_b14[0U]);
    Lib_IntVector_Intrinsics_vec256 *wv_a14 = tmp_block_state.fst + b1 * (uint32_t)1U;
    Lib_IntVector_Intrinsics_vec256 *wv_b = tmp_block_state.fst + c * (uint32_t)1U;
    wv_a14[0U] = Lib_IntVector_Intrinsics_vec256_xor(wv_a14[0U], wv_b[0U]);
    wv_a14[0U] = Lib_IntVector_Intrinsics_vec256_rotate_right64(wv_a14[0U], r33);
    Lib_IntVector_Intrinsics_vec256 *r13 = tmp_block_state.fst + (uint32_t)1U * (uint32_t)1U;
    Lib_IntVector_Intrinsics_vec256 *r2 = tmp_block_state.fst + (uint32_t)2U * (uint32_t)1U;
    Lib_IntVector_Intrinsics_vec256 *r3 = tmp_block_state.fst + (uint32_t)3U * (uint32_t)1U;
    Lib_IntVector_Intrinsics_vec256 v0 = r13[0U];
    Lib_IntVector_Intrinsics_vec256
    v12 = Lib_IntVector_Intrinsics_vec256_rotate_right_lanes64(v0, (uint32_t)3U);
    r13[0U] = v12;
    Lib_IntVector_Intrinsics_vec256 v03 = r2[0U];
    Lib_IntVector_Intrinsics_vec256
    v13 = Lib_IntVector_Intrinsics_vec256_rotate_right_lanes64(v03, (uint32_t)2U);
    r2[0U] = v13;
    Lib_IntVector_Intrinsics_vec256 v04 = r3[0U];
    Lib_IntVector_Intrinsics_vec256
    v14 = Lib_IntVector_Intrinsics_vec256_rotate_right_lanes64(v04, (uint32_t)1U);
    r3[0U] = v14;
  }
  Lib_IntVector_Intrinsics_vec256 *s0 = tmp_block_state.snd + (uint32_t)0U * (uint32_t)1U;
  Lib_IntVector_Intrinsics_vec256 *s1 = tmp_block_state.snd + (uint32_t)1U * (uint32_t)1U;
  Lib_IntVector_Intrinsics_vec256 *r0 = tmp_block_state.fst + (uint32_t)0U * (uint32_t)1U;
  Lib_IntVector_Intrinsics_vec256 *r1 = tmp_block_state.fst + (uint32_t)1U * (uint32_t)1U;
  Lib_IntVector_Intrinsics_vec256 *r2 = tmp_block_state.fst + (uint32_t)2U * (uint32_t)1U;
  Lib_IntVector_Intrinsics_vec256 *r3 = tmp_block_state.fst + (uint32_t)3U * (uint32_t)1U;
  s0[0U] = Lib_IntVector_Intrinsics_vec256_xor(s0[0U], r0[0U]);
  s0[0U] = Lib_IntVector_Intrinsics_vec256_xor(s0[0U], r2[0U]);
  s1[0U] = Lib_IntVector_Intrinsics_vec256_xor(s1[0U], r1[0U]);
  s1[0U] = Lib_IntVector_Intrinsics_vec256_xor(s1[0U], r3[0U]);
  Lib_Memzero0_memzero(b2, (uint32_t)128U * sizeof (b2[0U]));
  uint32_t double_row = (uint32_t)2U * (uint32_t)4U * (uint32_t)8U;
  KRML_CHECK_SIZE(sizeof (uint8_t), double_row);
  uint8_t b[double_row];
  memset(b, 0U, double_row * sizeof (b[0U]));
  uint8_t *first = b;
  uint8_t *second = b + (uint32_t)4U * (uint32_t)8U;
  Lib_IntVector_Intrinsics_vec256 *row0 = tmp_block_state.snd + (uint32_t)0U * (uint32_t)1U;
  Lib_IntVector_Intrinsics_vec256 *row1 = tmp_block_state.snd + (uint32_t)1U * (uint32_t)1U;
  Lib_IntVector_Intrinsics_vec256_store_le(first, row0[0U]);
  Lib_IntVector_Intrinsics_vec256_store_le(second, row1[0U]);
  uint8_t *final = b;
  memcpy(dst, final, (uint32_t)64U * sizeof (final[0U]));
  Lib_Memzero0_memzero(b, double_row * sizeof (b[0U]));
}

/* SNIPPET_END: Hacl_Streaming_Blake2_blake2b_256_with_key_finish */

/* SNIPPET_START: Hacl_Streaming_Blake2_blake2b_256_with_key_free */

/*
  Free state function when using a (potentially null) key
*/
void
Hacl_Streaming_Blake2_blake2b_256_with_key_free(
  uint32_t key_size,
  Hacl_Streaming_Functor_state_s__K____Lib_IntVector_Intrinsics_vec256___Lib_IntVector_Intrinsics_vec256____
  *s1
)
{
  Hacl_Streaming_Functor_state_s__K____Lib_IntVector_Intrinsics_vec256___Lib_IntVector_Intrinsics_vec256____
  scrut = *s1;
  uint8_t *buf = scrut.buf;
  K____Lib_IntVector_Intrinsics_vec256___Lib_IntVector_Intrinsics_vec256_
  block_state = scrut.block_state;
  Lib_IntVector_Intrinsics_vec256 *wv = block_state.fst;
  Lib_IntVector_Intrinsics_vec256 *b = block_state.snd;
  KRML_HOST_FREE(wv);
  KRML_HOST_FREE(b);
  KRML_HOST_FREE(buf);
  KRML_HOST_FREE(s1);
}

/* SNIPPET_END: Hacl_Streaming_Blake2_blake2b_256_with_key_free */
