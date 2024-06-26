module Hacl.Gf128.CT64

open FStar.HyperStack
open FStar.HyperStack.All

open Lib.IntTypes
open Lib.Buffer
open Lib.IntVector

open Hacl.Impl.Gf128.Fields
open Hacl.Impl.Gf128.Generic

module ST = FStar.HyperStack.ST
module Vec = Hacl.Spec.GF128.Vec


#reset-options "--z3rlimit 50 --max_fuel 0 --max_ifuel 1"

inline_for_extraction noextract
let gcm_ctx_elem = uint64
inline_for_extraction noextract
let gcm_ctx_len = 18ul

inline_for_extraction noextract
let gcm_ctx_elem_zero = u64 0
inline_for_extraction noextract
let gcm_ctx = lbuffer gcm_ctx_elem gcm_ctx_len


[@CInline]
let gcm_init : gf128_init_st Vec.CT64 =
  gf128_init #Vec.CT64


[@CInline]
let gcm_update_blocks: gf128_update_st Vec.CT64 =
  gf128_update #Vec.CT64


[@CInline]
let gcm_update_blocks_padded: gf128_update_st Vec.CT64 =
  gcm_update_blocks


[@CInline]
let gcm_emit: gf128_emit_st Vec.CT64 =
  gf128_emit #Vec.CT64


[@CInline]
let ghash: ghash_st Vec.CT64 =
  ghash #Vec.CT64