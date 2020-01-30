module Lib.IntTypes.Intrinsics

module ST = FStar.HyperStack.ST
open FStar.HyperStack
open FStar.HyperStack.All
open Lib.IntTypes
open Lib.Buffer

open FStar.Mul
noextract
val add_carry_u64: cin: uint64 -> x: uint64 -> y: uint64 -> r: lbuffer uint64 (size 1) -> 
  Stack uint64 
    (requires fun h -> live h r)
    (ensures fun h0 c h1 -> modifies1 r h0 h1 /\ uint_v c <= 2 /\
      (
	let r = Seq.index (as_seq h1 r) 0 in 
	uint_v r + uint_v c * pow2 64 == uint_v x + uint_v y + uint_v cin)
    )

noextract
val sub_borrow_u64: cin: uint64{uint_v cin <= 1} -> x: uint64 -> y: uint64 -> r: lbuffer uint64 (size 1) -> 
  Stack uint64
    (requires fun h -> live h r)
    (ensures fun h0 c h1 -> modifies1 r h0 h1 /\ 
      (let r = Seq.index (as_seq h1 r) 0 in v r - v c * pow2 64 == v x - v y - v cin))
