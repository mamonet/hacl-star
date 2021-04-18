module Hacl.Impl.EC.Math

open FStar.Math.Lemmas
open FStar.Math
open FStar.Mul

open Spec.ECC
open Spec.ECC.Curves
open Hacl.Lemmas.P256

#set-options "--fuel 0 --ifuel 0 --z3rlimit 200"

val mod_sub: n:pos -> a:int -> b:int -> Lemma
  (requires a % n = b % n)
  (ensures  (a - b) % n = 0)
let mod_sub n a b =
  mod_add_both a b (-b) n

val sub_mod: n:pos -> a:int -> b:int -> Lemma
  (requires (a - b) % n = 0)
  (ensures  a % n = b % n)
let sub_mod n a b =
  mod_add_both (a - b) 0 b n

val mod_same: n:pos -> Lemma (n % n = 0)
let mod_same n = ()

val euclid: n:pos -> a:int -> b:int -> r:int -> s:int -> Lemma
  (requires (a * b) % n = 0 /\ r * n + s * a = 1)
  (ensures  b % n = 0)

let euclid n a b r s =
  calc (==) {
    b % n;
    == { FStar.Math.Lemmas.distributivity_add_left (r * n) (s * a) b }
    (r * n * b + s * a * b) % n;
    == { FStar.Math.Lemmas.paren_mul_right s a b }    
    (r * n * b + s * (a * b)) % n;
    == { FStar.Math.Lemmas.modulo_distributivity (r * n * b) (s * (a * b)) n }
    ((r * n * b) % n + s * (a * b) % n) % n;
    == { FStar.Math.Lemmas.lemma_mod_mul_distr_r s (a * b) n }
    ((r * n * b) % n + s * ((a * b) % n) % n) % n;  
    == { assert (a * b % n = 0) }
    ((r * n * b) % n + s * 0 % n) % n;
    == { assert (s * 0 == 0) }
    ((r * n * b) % n + 0 % n) % n;
    == { FStar.Math.Lemmas.modulo_lemma 0 n }
    ((r * n * b) % n) % n;
    == { FStar.Math.Lemmas.lemma_mod_twice (r * n * b) n }
    (r * n * b) % n;
    == { FStar.Math.Lemmas.swap_mul r n; FStar.Math.Lemmas.paren_mul_right n r b }
    (n * (r * b)) % n;
    == { FStar.Math.Lemmas.lemma_mod_mul_distr_l n (r * b) n}
    n % n * (r * b) % n;
    == { mod_same n }
    (0 * (r * b)) % n;
    == { assert (0 * (r * b) == 0) }
    0 % n;
    == { FStar.Math.Lemmas.modulo_lemma 0 n }
    0;
  }


val lemma_modular_multiplication_p256_2_left:
  a:nat{a < prime256} -> b:nat{b < prime256} -> Lemma
  (requires a * pow2 256 % prime256 = b * pow2 256 % prime256)
  (ensures  a == b)

let lemma_modular_multiplication_p256_2_left a b =
  mod_sub prime256 (a * pow2 256) (b * pow2 256);
  assert (pow2 256 * (a - b) % prime256 = 0);
  let r = 26959946654596436323893653559348051827142583427821597254581997273087 in
  let s = -26959946648319334592891477706824406424704094582978235142356758167551 in
  assert_norm (r * prime256 + s * pow2 256 = 1);
  euclid prime256 (pow2 256) (a - b) r s;
  assert ((a - b) % prime256 = 0);
  sub_mod prime256 a b;
  assert (a % prime256 = b % prime256);
  FStar.Math.Lemmas.modulo_lemma a prime256;
  FStar.Math.Lemmas.modulo_lemma b prime256


val lemma_modular_multiplication_p384_2_left:
  a: nat{ a < prime384} -> b: nat {b < prime384} -> Lemma
  (requires a * pow2 384 % prime384 = b * pow2 384 % prime384)
  (ensures a == b)

let lemma_modular_multiplication_p384_2_left a b =
  admit()
  
val lemma_modular_multiplication_p256_2: a: nat{a < prime256} -> b: nat{b < prime256} ->
  Lemma
  (a * pow2 256 % prime256 = b * pow2 256 % prime256 <==> a == b)

let lemma_modular_multiplication_p256_2 a b =
  Classical.move_requires_2 lemma_modular_multiplication_p256_2_left a b


val lemma_modular_multiplication_p384_2: a: nat {a < prime384} -> b: nat {b < prime384} ->
  Lemma
    (a * pow2 384 % prime384 = b * pow2 384 % prime384 <==> a == b)

let lemma_modular_multiplication_p384_2 a b = 
  Classical.move_requires_2 lemma_modular_multiplication_p384_2_left a b


noextract
let prime_p256_order:pos =
  assert_norm (115792089210356248762697446949407573529996955224135760342422259061068512044369> 0);
  115792089210356248762697446949407573529996955224135760342422259061068512044369


(* Fermat's Little Theorem
   applied to r = modp_inv2_prime (pow2 256) prime_p256_order

  Verified in Sage:
   prime256 = Zmod(Integer(115792089210356248762697446949407573530086143415290314195533631308867097853951))
   p = 41058363725152142129326129780047268409114441015993725554835256314039467401291
   C = EllipticCurve(prime256, [-3, p])
   prime_p256_order =/ C.cardinality()
   Z = Integers(prime_p256_order)
   r = Z(inverse_mod(2**256, prime_p256_order))
   r ^ (prime_p256_order - 1)
*)
val lemma_l_ferm: unit -> Lemma
  (let r = modp_inv2_prime (pow2 256) prime_p256_order in
  (pow r (prime_p256_order - 1) % prime_p256_order == 1))

let lemma_l_ferm () =
  let r = modp_inv2_prime (pow2 256) prime_p256_order in
  assert_norm (exp #prime_p256_order (modp_inv2_prime (pow2 256) prime_p256_order) (prime_p256_order - 1)  == 1);
  lemma_pow_mod_n_is_fpow prime_p256_order r (prime_p256_order - 1)
  

private val lemma_a_not_zero_b_not_zero_mod_not_zero_: p: nat {Math.Euclid.is_prime p} -> a: nat {a % p <> 0} -> b: nat {b % p <> 0} ->
  Lemma (requires a * b <> 0)
  (ensures a * b % p <> 0)

private let lemma_a_not_zero_b_not_zero_mod_not_zero_ p a b = 
  if a * b % p = 0 then begin
    FStar.Math.Euclid.euclid_prime p a b;
    assert False
  end

val lemma_a_not_zero_b_not_zero_mod_not_zero: p: nat {Math.Euclid.is_prime p} -> a: nat {a % p <> 0} -> b: nat {b % p <> 0} ->
  Lemma (requires a * b <> 0)
  (ensures a * b % p <> 0)

let lemma_a_not_zero_b_not_zero_mod_not_zero p a b = lemma_a_not_zero_b_not_zero_mod_not_zero_ p a b


val lemma_0: p: nat {Math.Euclid.is_prime p} -> a: nat {a % p <> 0} -> k: pos -> Lemma 
  (requires (pow (a % p) (k - 1) % p <> 0 /\ pow (a % p) (k - 1) * pow (a % p) 1 <> 0))  
  (ensures (pow (a % p) (k - 1) * pow (a % p) 1 % p <> 0))
  
let lemma_0 p a k = 
  power_one_2 (a % p);
  lemma_a_not_zero_b_not_zero_mod_not_zero p (pow (a % p) (k - 1)) (pow (a % p) 1)



val lemma_exp_not_zero: p: nat {Math.Euclid.is_prime p} -> a: nat {a % p <> 0} -> k: pos ->
  Lemma (Spec.ECC.Curves.exp #p (a % p) k % p <> 0)

let rec lemma_exp_not_zero p a k = 
  match k with 
  |1 -> 
    lemma_pow_mod_n_is_fpow p (a % p) 1;
    let b = Spec.ECC.Curves.exp #p (a % p) 1 % p in 
    power_one_2 (a % p)
  | _ -> 
    lemma_exp_not_zero p a (k - 1);
    lemma_pow_mod_n_is_fpow p (a % p) k;
    lemma_pow_mod_n_is_fpow p (a % p) (k - 1);
    power_one_2 (a % p);
    pow_plus (a % p) 1 (k - 1);
    lemma_0 p a k


val lemma_multiplication_not_mod_prime: #c: curve -> a: nat {a < getPrime c} -> 
  Lemma (a * (modp_inv2 #c (pow2 (getPower c))) % getPrime c == 0 <==> a == 0)

let lemma_multiplication_not_mod_prime #c a = 
  let prime = getPrime c in 
  let pow = pow2 (getPower c) in 
  
  lemma_exp_not_zero prime pow (prime - 2);
  lemma_exp_not_zero (getPrime c) (pow2 (getPower c)) (getPrime c - 2);
  
  assert (if a * modp_inv2_prime pow prime % prime = 0 then begin 
    FStar.Math.Euclid.euclid_prime prime a (modp_inv2_prime pow prime);
    (a % prime == 0) end else True);

  small_mod a prime

(* 
val lemma_modular_multiplication_p256: a:nat{a < prime256} -> b:nat{b < prime256} -> Lemma
  (requires a * modp_inv2 #P256 (pow2 256) % prime256 == b * modp_inv2 #P256 (pow2 256) % prime256)
  (ensures  a == b)

let lemma_modular_multiplication_p256 a b =
  let c = modp_inv2 #P256 (pow2 256) in
  mod_sub prime256 (a * c) (b * c);
  assert (c * (a - b) % prime256 = 0);
  let r = -26959946654596436328278158470660195847911760999080590586820792680449 in
  let s = 26959946660873538059280334323183841250350249843923952699046031785985 in
  assert_norm (r * prime256 + s * c = 1);
  euclid prime256 c (a - b) r s;
  assert ((a - b) % prime256 = 0);
  sub_mod prime256 a b;
  assert (a % prime256 == b % prime256);
  FStar.Math.Lemmas.modulo_lemma a prime256;
  FStar.Math.Lemmas.modulo_lemma b prime256 *)


val lemma_modular_multiplication: #c: curve -> a: nat {a < getPrime c} -> b: nat {b < getPrime c} -> 
  Lemma (a == b <==> a * modp_inv2 #c (pow2 (getPower c)) % getPrime c == b * modp_inv2 #c (pow2 (getPower c)) % getPrime c)

let lemma_modular_multiplication #c a b = 
  let prime = getPrime c in 
  let d = modp_inv2 #c (pow2 (getPower c)) in 
  small_mod d prime;

  lemma_exp_not_zero prime (pow2 (getPower c) % prime) (prime - 2);
  if a * d % prime = b * d % prime then begin
    FStar.Math.Fermat.mod_mult_congr prime a b d;
    small_mod a prime;
    small_mod b prime
    end
  