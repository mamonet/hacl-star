module Spec.HKDF

open FStar.Mul

open Lib.IntTypes
open Lib.Sequence
open Lib.ByteSequence
open Lib.LoopCombinators

module Hash = Spec.Hash
module HMAC = Spec.HMAC


(* val hkdf_extract: *)
(*     a:Hash.algorithm *)
(*   -> salt: bytes{length salt <= HA.max_input_length a} *)
(*   -> ikm: bytes{length salt + length ikm + HA.block_length a <= HA.max_input_length a *)
(*         /\ HA.hash_length a + length ikm + HA.block_length a <= HA.max_input_length a} -> *)
(*   Tot (lbytes (HA.hash_length a)) *)

let hkdf_extract a salt ikm =
  let slen = length salt in
  if slen = 0 then
    let salt0 = create (HA.hash_length a) (u8 0) in
    HMAC.hmac a salt0 ikm
  else
    HMAC.hmac a salt ikm


val hkdf_round0:
    a: HA.hash_alg
  -> prk: bytes{length prk < HA.max_input_length a}
  -> info: bytes{length info + HA.hash_length a + 1 <= max_size_t (* BB. FIXME, this is required by create *)
              /\ length prk + length info + 1 + HA.hash_length a + HA.block_length a < HA.max_input_length a} ->
  Tot (lbytes (HA.hash_length a))

let hkdf_round0 a prk info =
  let ilen = length info in
  let input = create (ilen + 1) (u8 0) in
  let input = update_sub input 0 ilen info in
  let input = input.[ilen] <- u8 1 in
  HMAC.hmac a prk input


val hkdf_round:
    a: HA.hash_alg
  -> prk: bytes{length prk < HA.max_input_length a}
  -> info: bytes{length info + HA.hash_length a + 1 <= max_size_t (* BB. FIXME, this is required by create *)
              /\ length prk + length info + 1 + HA.hash_length a + HA.block_length a < HA.max_input_length a}
  -> i:nat{1 < i /\ i <= 255}
  -> ti:lbytes (HA.hash_length a) ->
  Tot (lbytes (HA.hash_length a))

let hkdf_round a prk info i ti =
  let ilen = length info in
  let input = create (HA.hash_length a + ilen + 1) (u8 0) in
  let input = update_sub input 0 (HA.hash_length a) ti in
  let input = update_sub input (HA.hash_length a) ilen info in
  let input = input.[(HA.hash_length a) + ilen] <- u8 i in
  HMAC.hmac a prk input

#set-options "--z3rlimit 200"
let hkdf_expand a prk info len =
  let n : size_nat = len / (HA.hash_length a) + 1 in
  let t = create #uint8 (n * HA.hash_length a) (u8 0) in
  (* Compute T(0) *)
  let t0 = hkdf_round0 a prk info in
  let t = update_sub t 0 (HA.hash_length a) t0 in
  (* Compute T(1) ... T(N)*)
  let t =
    repeat_range 2 (n + 1)
      (fun i t ->
        let ti = sub t ((i - 2) * HA.hash_length a) (HA.hash_length a) in
        let r = hkdf_round a prk info i ti in
        update_sub t ((i - 1) * HA.hash_length a) (HA.hash_length a) r
      ) t in
  let res = sub t 0 len in
  res


let hkdf_build_label secret label context len =
  let llen = length label in
  let clen = length context in
  let size_hkdf_label : size_nat = numbytes U16 + numbytes U8 + llen + numbytes U8 + clen in
  let hkdf_label = create size_hkdf_label (u8 0) in
  let hkdf_label = update_sub hkdf_label 0 (numbytes U16) (uint_to_bytes_be (u16 len)) in
  let hkdf_label = update_sub hkdf_label (numbytes U16) (numbytes U8) (uint_to_bytes_be #U8 (u8 llen)) in
  let hkdf_label = update_sub hkdf_label (numbytes U16 + numbytes U8) llen label in
  let hkdf_label = update_sub hkdf_label (numbytes U16 + numbytes U8 + llen) (numbytes U8) (uint_to_bytes_be #U8 (u8 clen)) in
  let hkdf_label = update_sub hkdf_label (numbytes U16 + numbytes U8 + llen + numbytes U8) clen context in
  hkdf_label


let hkdf_expand_label a secret label context len =
  let hkdf_label = hkdf_build_label secret label context len in
  hkdf_expand a secret hkdf_label len


let hkdf_expand_derive_secret a secret label context =
  let loghash = Hash.hash a context in
  hkdf_expand_label a secret label loghash (HA.hash_length a)
