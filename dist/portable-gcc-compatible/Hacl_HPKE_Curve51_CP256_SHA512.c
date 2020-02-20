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


#include "Hacl_HPKE_Curve51_CP256_SHA512.h"

/* SNIPPET_START: Hacl_HPKE_Curve51_CP256_SHA512_setupBaseI */

uint32_t
Hacl_HPKE_Curve51_CP256_SHA512_setupBaseI(
  uint8_t *o_pkE,
  uint8_t *o_k,
  uint8_t *o_n,
  uint8_t *skE,
  uint8_t *pkR,
  uint32_t infolen,
  uint8_t *info
)
{
  uint8_t zz[32U] = { 0U };
  Hacl_Curve25519_51_secret_to_public(o_pkE, skE);
  uint32_t res1 = (uint32_t)0U;
  uint8_t zeros1[32U] = { 0U };
  Hacl_Curve25519_51_scalarmult(zz, skE, pkR);
  uint8_t res0 = (uint8_t)255U;
  for (uint32_t i = (uint32_t)0U; i < (uint32_t)32U; i++)
  {
    uint8_t uu____0 = FStar_UInt8_eq_mask(zz[i], zeros1[i]);
    res0 = uu____0 & res0;
  }
  uint8_t z = res0;
  uint32_t res;
  if (z == (uint8_t)255U)
  {
    res = (uint32_t)1U;
  }
  else
  {
    res = (uint32_t)0U;
  }
  uint32_t res2 = res;
  uint32_t res3 = res1 | res2;
  uint8_t default_psk1[64U] = { 0U };
  uint8_t default_pkI1[32U] = { 0U };
  uint32_t
  context_len = (uint32_t)9U + (uint32_t)3U * (uint32_t)32U + (uint32_t)2U * (uint32_t)64U;
  KRML_CHECK_SIZE(sizeof (uint8_t), context_len);
  uint8_t context[context_len];
  memset(context, 0U, context_len * sizeof (context[0U]));
  uint8_t
  label_key1[8U] =
    {
      (uint8_t)0x68U, (uint8_t)0x70U, (uint8_t)0x6bU, (uint8_t)0x65U, (uint8_t)0x20U, (uint8_t)0x6bU,
      (uint8_t)0x65U, (uint8_t)0x79U
    };
  uint8_t
  label_nonce1[10U] =
    {
      (uint8_t)0x68U, (uint8_t)0x70U, (uint8_t)0x6bU, (uint8_t)0x65U, (uint8_t)0x20U, (uint8_t)0x6eU,
      (uint8_t)0x6fU, (uint8_t)0x6eU, (uint8_t)0x63U, (uint8_t)0x65U
    };
  KRML_CHECK_SIZE(sizeof (uint8_t), (uint32_t)10U + context_len);
  uint8_t tmp[(uint32_t)10U + context_len];
  memset(tmp, 0U, ((uint32_t)10U + context_len) * sizeof (tmp[0U]));
  uint8_t secret1[64U] = { 0U };
  uint8_t *info_hash = tmp;
  uint8_t *pskID_hash = tmp + (uint32_t)64U;
  Hacl_Hash_SHA2_hash_512(info, infolen, info_hash);
  uint8_t *empty_b = info;
  Hacl_Hash_SHA2_hash_512(empty_b, (uint32_t)0U, pskID_hash);
  context[0U] = (uint8_t)0U;
  uint8_t *uu____1 = context + (uint32_t)1U;
  uu____1[0U] = (uint8_t)7U;
  uu____1[1U] = (uint8_t)7U;
  uu____1[2U] = (uint8_t)7U;
  uu____1[3U] = (uint8_t)7U;
  uu____1[4U] = (uint8_t)7U;
  uu____1[5U] = (uint8_t)7U;
  memcpy(context + (uint32_t)7U, o_pkE, (uint32_t)32U * sizeof (o_pkE[0U]));
  memcpy(context + (uint32_t)7U + (uint32_t)32U, pkR, (uint32_t)32U * sizeof (pkR[0U]));
  memcpy(context + (uint32_t)7U + (uint32_t)32U + (uint32_t)32U,
    default_pkI1,
    (uint32_t)32U * sizeof (default_pkI1[0U]));
  uint8_t *psklen_b = context + (uint32_t)7U + (uint32_t)32U + (uint32_t)32U + (uint32_t)32U;
  psklen_b[0U] = (uint8_t)64U;
  uint8_t
  *pskhash_b =
    context
    + (uint32_t)7U + (uint32_t)32U + (uint32_t)32U + (uint32_t)32U + (uint32_t)1U;
  memcpy(pskhash_b, pskID_hash, (uint32_t)64U * sizeof (pskID_hash[0U]));
  uint8_t
  *infolen_b =
    context
    + (uint32_t)7U + (uint32_t)32U + (uint32_t)32U + (uint32_t)32U + (uint32_t)1U + (uint32_t)64U;
  infolen_b[0U] = (uint8_t)64U;
  uint8_t
  *output_info =
    context
    + (uint32_t)7U + (uint32_t)32U + (uint32_t)32U + (uint32_t)32U + (uint32_t)2U + (uint32_t)64U;
  memcpy(output_info, info_hash, (uint32_t)64U * sizeof (info_hash[0U]));
  Hacl_HKDF_extract_sha2_512(secret1, default_psk1, (uint32_t)64U, zz, (uint32_t)32U);
  uint8_t *info_key = tmp + (uint32_t)2U;
  memcpy(info_key, label_key1, (uint32_t)8U * sizeof (label_key1[0U]));
  memcpy(info_key + (uint32_t)8U, context, context_len * sizeof (context[0U]));
  Hacl_HKDF_expand_sha2_512(o_k,
    secret1,
    (uint32_t)64U,
    info_key,
    (uint32_t)8U + context_len,
    (uint32_t)32U);
  memcpy(tmp, label_nonce1, (uint32_t)10U * sizeof (label_nonce1[0U]));
  Hacl_HKDF_expand_sha2_512(o_n,
    secret1,
    (uint32_t)64U,
    tmp,
    (uint32_t)10U + context_len,
    (uint32_t)12U);
  return res3;
}

/* SNIPPET_END: Hacl_HPKE_Curve51_CP256_SHA512_setupBaseI */

/* SNIPPET_START: Hacl_HPKE_Curve51_CP256_SHA512_setupBaseR */

uint32_t
Hacl_HPKE_Curve51_CP256_SHA512_setupBaseR(
  uint8_t *o_key_aead,
  uint8_t *o_nonce_aead,
  uint8_t *pkE,
  uint8_t *skR,
  uint32_t infolen,
  uint8_t *info
)
{
  uint8_t pkR[32U] = { 0U };
  uint8_t zz[32U] = { 0U };
  Hacl_Curve25519_51_secret_to_public(pkR, skR);
  uint32_t res1 = (uint32_t)0U;
  uint8_t zeros1[32U] = { 0U };
  Hacl_Curve25519_51_scalarmult(zz, skR, pkE);
  uint8_t res0 = (uint8_t)255U;
  for (uint32_t i = (uint32_t)0U; i < (uint32_t)32U; i++)
  {
    uint8_t uu____0 = FStar_UInt8_eq_mask(zz[i], zeros1[i]);
    res0 = uu____0 & res0;
  }
  uint8_t z = res0;
  uint32_t res;
  if (z == (uint8_t)255U)
  {
    res = (uint32_t)1U;
  }
  else
  {
    res = (uint32_t)0U;
  }
  uint32_t res2 = res;
  uint8_t default_psk1[64U] = { 0U };
  uint8_t default_pkI1[32U] = { 0U };
  uint32_t
  context_len = (uint32_t)9U + (uint32_t)3U * (uint32_t)32U + (uint32_t)2U * (uint32_t)64U;
  KRML_CHECK_SIZE(sizeof (uint8_t), context_len);
  uint8_t context[context_len];
  memset(context, 0U, context_len * sizeof (context[0U]));
  uint8_t
  label_key1[8U] =
    {
      (uint8_t)0x68U, (uint8_t)0x70U, (uint8_t)0x6bU, (uint8_t)0x65U, (uint8_t)0x20U, (uint8_t)0x6bU,
      (uint8_t)0x65U, (uint8_t)0x79U
    };
  uint8_t
  label_nonce1[10U] =
    {
      (uint8_t)0x68U, (uint8_t)0x70U, (uint8_t)0x6bU, (uint8_t)0x65U, (uint8_t)0x20U, (uint8_t)0x6eU,
      (uint8_t)0x6fU, (uint8_t)0x6eU, (uint8_t)0x63U, (uint8_t)0x65U
    };
  KRML_CHECK_SIZE(sizeof (uint8_t), (uint32_t)10U + context_len);
  uint8_t tmp[(uint32_t)10U + context_len];
  memset(tmp, 0U, ((uint32_t)10U + context_len) * sizeof (tmp[0U]));
  uint8_t secret1[64U] = { 0U };
  uint8_t *info_hash = tmp;
  uint8_t *pskID_hash = tmp + (uint32_t)64U;
  Hacl_Hash_SHA2_hash_512(info, infolen, info_hash);
  uint8_t *empty_b = info;
  Hacl_Hash_SHA2_hash_512(empty_b, (uint32_t)0U, pskID_hash);
  context[0U] = (uint8_t)0U;
  uint8_t *uu____1 = context + (uint32_t)1U;
  uu____1[0U] = (uint8_t)7U;
  uu____1[1U] = (uint8_t)7U;
  uu____1[2U] = (uint8_t)7U;
  uu____1[3U] = (uint8_t)7U;
  uu____1[4U] = (uint8_t)7U;
  uu____1[5U] = (uint8_t)7U;
  memcpy(context + (uint32_t)7U, pkE, (uint32_t)32U * sizeof (pkE[0U]));
  memcpy(context + (uint32_t)7U + (uint32_t)32U, pkR, (uint32_t)32U * sizeof (pkR[0U]));
  memcpy(context + (uint32_t)7U + (uint32_t)32U + (uint32_t)32U,
    default_pkI1,
    (uint32_t)32U * sizeof (default_pkI1[0U]));
  uint8_t *psklen_b = context + (uint32_t)7U + (uint32_t)32U + (uint32_t)32U + (uint32_t)32U;
  psklen_b[0U] = (uint8_t)64U;
  uint8_t
  *pskhash_b =
    context
    + (uint32_t)7U + (uint32_t)32U + (uint32_t)32U + (uint32_t)32U + (uint32_t)1U;
  memcpy(pskhash_b, pskID_hash, (uint32_t)64U * sizeof (pskID_hash[0U]));
  uint8_t
  *infolen_b =
    context
    + (uint32_t)7U + (uint32_t)32U + (uint32_t)32U + (uint32_t)32U + (uint32_t)1U + (uint32_t)64U;
  infolen_b[0U] = (uint8_t)64U;
  uint8_t
  *output_info =
    context
    + (uint32_t)7U + (uint32_t)32U + (uint32_t)32U + (uint32_t)32U + (uint32_t)2U + (uint32_t)64U;
  memcpy(output_info, info_hash, (uint32_t)64U * sizeof (info_hash[0U]));
  Hacl_HKDF_extract_sha2_512(secret1, default_psk1, (uint32_t)64U, zz, (uint32_t)32U);
  uint8_t *info_key = tmp + (uint32_t)2U;
  memcpy(info_key, label_key1, (uint32_t)8U * sizeof (label_key1[0U]));
  memcpy(info_key + (uint32_t)8U, context, context_len * sizeof (context[0U]));
  Hacl_HKDF_expand_sha2_512(o_key_aead,
    secret1,
    (uint32_t)64U,
    info_key,
    (uint32_t)8U + context_len,
    (uint32_t)32U);
  memcpy(tmp, label_nonce1, (uint32_t)10U * sizeof (label_nonce1[0U]));
  Hacl_HKDF_expand_sha2_512(o_nonce_aead,
    secret1,
    (uint32_t)64U,
    tmp,
    (uint32_t)10U + context_len,
    (uint32_t)12U);
  return res1 | res2;
}

/* SNIPPET_END: Hacl_HPKE_Curve51_CP256_SHA512_setupBaseR */

/* SNIPPET_START: Hacl_HPKE_Curve51_CP256_SHA512_sealBase */

uint32_t
Hacl_HPKE_Curve51_CP256_SHA512_sealBase(
  uint8_t *skE,
  uint8_t *pkR,
  uint32_t mlen,
  uint8_t *m,
  uint32_t infolen,
  uint8_t *info,
  uint8_t *output
)
{
  uint8_t zz[32U] = { 0U };
  uint8_t k1[32U] = { 0U };
  uint8_t n1[12U] = { 0U };
  uint8_t *pkE = output;
  uint32_t res = Hacl_HPKE_Curve51_CP256_SHA512_setupBaseI(pkE, k1, n1, skE, pkR, infolen, info);
  uint8_t *dec = output + (uint32_t)32U;
  Hacl_Chacha20Poly1305_256_aead_encrypt(k1, n1, infolen, info, mlen, m, dec, dec + mlen);
  uint32_t res0 = res;
  return res0;
}

/* SNIPPET_END: Hacl_HPKE_Curve51_CP256_SHA512_sealBase */

/* SNIPPET_START: Hacl_HPKE_Curve51_CP256_SHA512_openBase */

uint32_t
Hacl_HPKE_Curve51_CP256_SHA512_openBase(
  uint8_t *pkE,
  uint8_t *skR,
  uint32_t mlen,
  uint8_t *m,
  uint32_t infolen,
  uint8_t *info,
  uint8_t *output
)
{
  uint8_t zz[32U] = { 0U };
  uint8_t k1[32U] = { 0U };
  uint8_t n1[12U] = { 0U };
  uint8_t *pkE1 = m;
  uint32_t clen = mlen - (uint32_t)32U;
  uint8_t *c = m + (uint32_t)32U;
  uint32_t res1 = Hacl_HPKE_Curve51_CP256_SHA512_setupBaseR(k1, n1, pkE1, skR, infolen, info);
  uint32_t
  res2 =
    Hacl_Chacha20Poly1305_256_aead_decrypt(k1,
      n1,
      infolen,
      info,
      clen - (uint32_t)16U,
      output,
      c,
      c + clen - (uint32_t)16U);
  uint32_t z = res1 | res2;
  return z;
}

/* SNIPPET_END: Hacl_HPKE_Curve51_CP256_SHA512_openBase */
