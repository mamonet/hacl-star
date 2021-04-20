module Spec.Frodo.Test

open FStar.Mul

open Lib.IntTypes
open Lib.RawIntTypes
open Lib.Sequence
open Lib.ByteSequence

open Spec.Frodo.KEM
open Spec.Frodo.KEM.KeyGen
open Spec.Frodo.KEM.Encaps
open Spec.Frodo.KEM.Decaps
open Spec.Frodo.Params

open FStar.All

#set-options "--z3rlimit 50 --fuel 0 --ifuel 1"

let print_and_compare (#len: size_nat) (test_expected: lbytes len) (test_result: lbytes len)
  : ML bool =
  IO.print_string "\nResult:   ";
  List.iter (fun a -> IO.print_string (UInt8.to_string (u8_to_UInt8 a))) (to_list test_result);
  IO.print_string "\nExpected: ";
  List.iter (fun a -> IO.print_string (UInt8.to_string (u8_to_UInt8 a))) (to_list test_expected);
  for_all2 (fun a b -> uint_to_nat #U8 a = uint_to_nat #U8 b) test_expected test_result


let compare (#len: size_nat) (test_expected: lbytes len) (test_result: lbytes len) =
  for_all2 (fun a b -> uint_to_nat #U8 a = uint_to_nat #U8 b) test_expected test_result


let test_frodo
  (a:frodo_alg)
  (gen_a:frodo_gen_a)
  (keypaircoins: list uint8 {List.Tot.length keypaircoins == 2 * crypto_bytes a + bytes_seed_a})
  (enccoins: list uint8 {List.Tot.length enccoins == bytes_mu a})
  (ss_expected: list uint8 {List.Tot.length ss_expected == crypto_bytes a})
  (pk_expected: list uint8 {List.Tot.length pk_expected == crypto_publickeybytes a})
  (ct_expected: list uint8 {List.Tot.length ct_expected == crypto_ciphertextbytes a})
  (sk_expected: list uint8 {List.Tot.length sk_expected == crypto_secretkeybytes a})
  : ML bool =
  let keypaircoins = createL keypaircoins in
  let enccoins = createL enccoins in
  let ss_expected = createL ss_expected in
  let pk_expected = createL pk_expected in
  let ct_expected = createL ct_expected in
  let sk_expected = createL sk_expected in
  let pk, sk = crypto_kem_keypair_ a gen_a keypaircoins in
  let ct, ss1 = crypto_kem_enc_ a gen_a enccoins pk in
  let ss2 = crypto_kem_dec a gen_a ct sk in
  let r_pk = compare pk_expected pk in
  let r_sk = compare sk_expected sk in
  let r_ct = compare ct_expected ct in
  let r_ss = print_and_compare ss1 ss2 in
  let r_ss1 = print_and_compare ss_expected ss2 in
  r_pk && r_sk && r_ct && r_ss && r_ss1

//
// Test1. FrodoKEM-64. SHAKE128
//
let test1_keypaircoins =
  List.Tot.map u8_from_UInt8
    [
      0xa6uy; 0x65uy; 0x65uy; 0x9fuy; 0xfbuy; 0xe4uy; 0x06uy; 0x5cuy; 0xcauy; 0x81uy; 0x5auy; 0x45uy;
      0xe4uy; 0x94uy; 0xd8uy; 0x01uy; 0x90uy; 0x30uy; 0x33uy; 0x55uy; 0x33uy; 0x84uy; 0x2euy; 0xe4uy;
      0x4cuy; 0x55uy; 0x8fuy; 0xd8uy; 0xaeuy; 0x4buy; 0x4euy; 0x91uy; 0x62uy; 0xfeuy; 0xc7uy; 0x9auy;
      0xc5uy; 0xcduy; 0x1fuy; 0xe2uy; 0xd2uy; 0x00uy; 0x63uy; 0x39uy; 0xaauy; 0xb1uy; 0xf3uy; 0x17uy
    ]

let test1_enccoins =
  List.Tot.map u8_from_UInt8
    [
      0x8duy; 0xf3uy; 0xfauy; 0xe3uy; 0x83uy; 0x27uy; 0xc5uy; 0x3cuy; 0xc1uy; 0xc4uy; 0x8cuy; 0x60uy;
      0xb2uy; 0x52uy; 0x2buy; 0xb5uy
    ]

let test1_ss_expected =
  List.Tot.map u8_from_UInt8
    [
      0xf8uy; 0x96uy; 0x15uy; 0x94uy; 0x80uy; 0x9fuy; 0xebuy; 0x77uy; 0x56uy; 0xbeuy; 0x37uy; 0x69uy;
      0xa0uy; 0xeauy; 0x60uy; 0x16uy
    ]

let test1_pk_expected =
  List.Tot.map u8_from_UInt8
    [
      0x0duy; 0xacuy; 0x6fuy; 0x83uy; 0x94uy; 0x00uy; 0x1auy; 0xcauy; 0x97uy; 0xa1uy; 0xaauy; 0x42uy;
      0x80uy; 0x9duy; 0x6buy; 0xa5uy; 0xfcuy; 0x64uy; 0x43uy; 0xdbuy; 0xbeuy; 0x6fuy; 0x12uy; 0x2auy;
      0x94uy; 0x58uy; 0x36uy; 0xf2uy; 0xb1uy; 0xf8uy; 0xe5uy; 0xf0uy; 0x57uy; 0x4buy; 0x35uy; 0x51uy;
      0xdduy; 0x8cuy; 0x36uy; 0x28uy; 0x34uy; 0x46uy; 0xd6uy; 0xafuy; 0x5duy; 0x49uy; 0x0euy; 0x27uy;
      0xd8uy; 0xd3uy; 0xaduy; 0xe1uy; 0xeduy; 0x8buy; 0x2duy; 0x13uy; 0xf5uy; 0x5auy; 0xb6uy; 0xdduy;
      0xc0uy; 0x54uy; 0x76uy; 0x09uy; 0xa6uy; 0xa4uy; 0x01uy; 0xb9uy; 0xb7uy; 0xd1uy; 0x26uy; 0xd5uy;
      0x1euy; 0xa8uy; 0x20uy; 0x4duy; 0xe8uy; 0xefuy; 0xaduy; 0xb9uy; 0xf0uy; 0x65uy; 0xe9uy; 0xc4uy;
      0xf4uy; 0x11uy; 0x98uy; 0x99uy; 0xf0uy; 0x2cuy; 0x63uy; 0x7buy; 0x98uy; 0xd7uy; 0x60uy; 0x43uy;
      0x5duy; 0x8cuy; 0x85uy; 0xe9uy; 0xc5uy; 0x83uy; 0x83uy; 0x62uy; 0xe2uy; 0x13uy; 0x33uy; 0x54uy;
      0x4buy; 0x71uy; 0xaeuy; 0x63uy; 0xbauy; 0x5auy; 0x4euy; 0x32uy; 0x59uy; 0x78uy; 0x6buy; 0x4duy;
      0x39uy; 0xcfuy; 0xe1uy; 0x82uy; 0x58uy; 0x0auy; 0xc3uy; 0x61uy; 0x6auy; 0x89uy; 0x2fuy; 0x1buy;
      0x70uy; 0xdduy; 0x16uy; 0x3euy; 0x96uy; 0xb1uy; 0x4cuy; 0x71uy; 0xb1uy; 0x79uy; 0x0cuy; 0x3fuy;
      0xe2uy; 0xeduy; 0x05uy; 0x07uy; 0x72uy; 0xf3uy; 0x89uy; 0x08uy; 0x8cuy; 0x22uy; 0xa7uy; 0x36uy;
      0x40uy; 0xcauy; 0x52uy; 0x70uy; 0x1buy; 0x09uy; 0xcbuy; 0xabuy; 0x3buy; 0x64uy; 0x61uy; 0x6duy;
      0x5duy; 0xf7uy; 0x15uy; 0x69uy; 0x71uy; 0x3buy; 0x3auy; 0x2euy; 0x53uy; 0x33uy; 0x26uy; 0xe6uy;
      0x29uy; 0x5cuy; 0xfbuy; 0x0duy; 0xc6uy; 0xe4uy; 0xbduy; 0x9cuy; 0x43uy; 0xffuy; 0xa6uy; 0x5buy;
      0x49uy; 0x47uy; 0x93uy; 0x1cuy; 0x81uy; 0x6fuy; 0xd4uy; 0xaauy; 0x3duy; 0xaduy; 0x86uy; 0xf5uy;
      0x94uy; 0x16uy; 0x7fuy; 0x31uy; 0x91uy; 0x30uy; 0x97uy; 0xc4uy; 0xa3uy; 0xe4uy; 0x01uy; 0x2buy;
      0x06uy; 0xcfuy; 0x69uy; 0xfbuy; 0x69uy; 0x35uy; 0xaauy; 0x81uy; 0xeduy; 0x90uy; 0x0cuy; 0x3auy;
      0xc0uy; 0xa6uy; 0x06uy; 0xabuy; 0x51uy; 0x3fuy; 0x39uy; 0xb2uy; 0x1euy; 0xb0uy; 0x4buy; 0xbcuy;
      0xd0uy; 0xd0uy; 0x3auy; 0xdauy; 0x89uy; 0x88uy; 0xa6uy; 0x56uy; 0xd8uy; 0x02uy; 0x98uy; 0xeeuy;
      0xa2uy; 0xf5uy; 0x0euy; 0xbauy; 0x7cuy; 0x52uy; 0xafuy; 0xf4uy; 0xbbuy; 0xe7uy; 0x36uy; 0x4auy;
      0xdduy; 0x90uy; 0x93uy; 0xe9uy; 0x5duy; 0xbeuy; 0x68uy; 0x99uy; 0xc2uy; 0xaduy; 0x4duy; 0x79uy;
      0x25uy; 0x0buy; 0x69uy; 0x79uy; 0x7buy; 0xe2uy; 0x3duy; 0xa8uy; 0xe7uy; 0xf1uy; 0x42uy; 0x0cuy;
      0x22uy; 0x85uy; 0x95uy; 0xf0uy; 0xd5uy; 0x5cuy; 0x96uy; 0x35uy; 0xb6uy; 0x19uy; 0xaeuy; 0xb3uy;
      0xcfuy; 0x22uy; 0xcauy; 0xbauy; 0x28uy; 0xd6uy; 0xdduy; 0xd5uy; 0x8euy; 0xe8uy; 0xd6uy; 0x90uy;
      0x23uy; 0x8euy; 0x97uy; 0x37uy; 0xe9uy; 0xcduy; 0xabuy; 0xdcuy; 0x08uy; 0x04uy; 0xe1uy; 0x32uy;
      0x02uy; 0xffuy; 0x7fuy; 0x82uy; 0x41uy; 0xf3uy; 0x9buy; 0x1duy; 0x42uy; 0x8auy; 0x98uy; 0x80uy;
      0x81uy; 0xaauy; 0xbeuy; 0x7duy; 0x3buy; 0x83uy; 0x30uy; 0x4duy; 0x4auy; 0x22uy; 0x2duy; 0xafuy;
      0x61uy; 0xd1uy; 0xa0uy; 0x66uy; 0xd4uy; 0x48uy; 0x0fuy; 0xe1uy; 0xd9uy; 0x77uy; 0x82uy; 0xc5uy;
      0xa1uy; 0x2auy; 0x03uy; 0x1fuy; 0xd0uy; 0x7auy; 0xccuy; 0x77uy; 0x09uy; 0x4auy; 0xbduy; 0xaduy;
      0xf7uy; 0x76uy; 0xdcuy; 0x10uy; 0xeduy; 0x5buy; 0xdfuy; 0x89uy; 0xfbuy; 0x52uy; 0x60uy; 0x5cuy;
      0x08uy; 0x42uy; 0x50uy; 0xd1uy; 0xdauy; 0x24uy; 0xbbuy; 0x59uy; 0x3euy; 0x14uy; 0xf4uy; 0xf0uy;
      0xf4uy; 0xdauy; 0xb8uy; 0x00uy; 0xe2uy; 0x0buy; 0xfauy; 0xc3uy; 0xf6uy; 0x28uy; 0x8duy; 0x20uy;
      0x26uy; 0xe9uy; 0x5buy; 0x25uy; 0xa8uy; 0x80uy; 0x4cuy; 0xeeuy; 0xc9uy; 0xb6uy; 0x7auy; 0x8buy;
      0x87uy; 0x21uy; 0xfduy; 0xaeuy; 0xd5uy; 0xa8uy; 0x49uy; 0x33uy; 0x58uy; 0x90uy; 0x2cuy; 0x0auy;
      0xcauy; 0xb0uy; 0x9duy; 0xbeuy; 0xcduy; 0xe0uy; 0xa4uy; 0x99uy; 0x76uy; 0x01uy; 0x80uy; 0xdduy;
      0x66uy; 0x76uy; 0x70uy; 0x05uy; 0xf3uy; 0xd6uy; 0x31uy; 0xa1uy; 0x9euy; 0xd5uy; 0x5fuy; 0x1buy;
      0xdduy; 0x7fuy; 0x81uy; 0x6duy; 0x5cuy; 0xe9uy; 0xa3uy; 0x1auy; 0x6auy; 0x87uy; 0x93uy; 0xaduy;
      0x1duy; 0x73uy; 0x44uy; 0xbcuy; 0xe4uy; 0x42uy; 0x78uy; 0x6auy; 0x71uy; 0x58uy; 0x9buy; 0x73uy;
      0x55uy; 0x63uy; 0xa5uy; 0x32uy; 0xf6uy; 0x55uy; 0x68uy; 0x05uy; 0xcfuy; 0xeduy; 0x5fuy; 0x86uy;
      0xe2uy; 0x65uy; 0xefuy; 0xf1uy; 0xb9uy; 0x69uy; 0xbbuy; 0x79uy; 0xb1uy; 0xf4uy; 0x7fuy; 0xa5uy;
      0xfauy; 0x62uy; 0xbcuy; 0x68uy; 0xe7uy; 0xf6uy; 0xf8uy; 0xf0uy; 0x55uy; 0xf4uy; 0x93uy; 0x47uy;
      0x06uy; 0xf0uy; 0x3euy; 0x94uy; 0x4auy; 0x95uy; 0xc8uy; 0x0cuy; 0xb0uy; 0x04uy; 0x4euy; 0x3fuy;
      0x67uy; 0x14uy; 0xeduy; 0xbbuy; 0xbeuy; 0xf0uy; 0xabuy; 0xdduy; 0x6cuy; 0x23uy; 0x4euy; 0x07uy;
      0x66uy; 0x41uy; 0x55uy; 0xbeuy; 0x22uy; 0x59uy; 0xd5uy; 0xdauy; 0xd4uy; 0xd8uy; 0x3duy; 0xb0uy;
      0x74uy; 0xc4uy; 0x4fuy; 0x9buy; 0x43uy; 0xe5uy; 0x75uy; 0xfbuy; 0x33uy; 0x0euy; 0xdfuy; 0xe1uy;
      0xe3uy; 0x7duy; 0x2euy; 0x80uy; 0x10uy; 0x79uy; 0x17uy; 0xeauy; 0xd3uy; 0x18uy; 0x98uy; 0x08uy;
      0xeduy; 0x79uy; 0x4cuy; 0xb9uy; 0x66uy; 0x03uy; 0x04uy; 0x50uy; 0xfeuy; 0x62uy; 0x0duy; 0x48uy;
      0x1auy; 0x6cuy; 0xeeuy; 0xb7uy; 0x03uy; 0x15uy; 0x92uy; 0x41uy; 0x1euy; 0xa1uy; 0x88uy; 0x46uy;
      0x1auy; 0x43uy; 0x49uy; 0xf5uy; 0x93uy; 0x33uy; 0x00uy; 0x65uy; 0x69uy; 0xa8uy; 0x82uy; 0xbduy;
      0xbeuy; 0x5cuy; 0x56uy; 0xa3uy; 0x06uy; 0x00uy; 0x8buy; 0x2fuy; 0x7duy; 0xecuy; 0xa4uy; 0x9auy;
      0x2auy; 0xaeuy; 0x66uy; 0x07uy; 0x46uy; 0xb3uy; 0xbeuy; 0xf8uy; 0x07uy; 0x08uy; 0x10uy; 0x87uy;
      0xd5uy; 0x6cuy; 0x6auy; 0xa5uy; 0xa6uy; 0x07uy; 0x4buy; 0x00uy; 0xc1uy; 0x5auy; 0xeduy; 0x7fuy;
      0x14uy; 0x4buy; 0x60uy; 0x02uy; 0xc2uy; 0x67uy; 0x0cuy; 0xa4uy; 0x64uy; 0x54uy; 0x3euy; 0x22uy;
      0xfeuy; 0x21uy; 0xcduy; 0x0duy; 0xcbuy; 0x60uy; 0x3buy; 0x13uy; 0xb0uy; 0x8euy; 0x36uy; 0xcauy;
      0xcduy; 0x78uy; 0x8duy; 0x08uy; 0x2auy; 0xf1uy; 0x9cuy; 0x17uy; 0x11uy; 0x14uy; 0x57uy; 0x57uy;
      0xe8uy; 0x3buy; 0x84uy; 0xe8uy; 0x59uy; 0xdbuy; 0x5buy; 0x77uy; 0x2euy; 0x54uy; 0x3buy; 0x6euy;
      0x9cuy; 0x5euy; 0x7fuy; 0x52uy; 0xe5uy; 0x06uy; 0x8auy; 0x2duy; 0xc3uy; 0xbfuy; 0x30uy; 0x34uy;
      0x8cuy; 0xaauy; 0x3buy; 0x23uy; 0x59uy; 0x32uy; 0x5fuy; 0xf7uy; 0xc9uy; 0xb2uy; 0xeeuy; 0xb2uy;
      0x72uy; 0x75uy; 0x33uy; 0x8euy; 0xa9uy; 0x68uy; 0x6euy; 0xf5uy; 0x61uy; 0x7auy; 0x20uy; 0x01uy;
      0xecuy; 0xabuy; 0x19uy; 0x26uy; 0xbeuy; 0x38uy; 0x49uy; 0xe2uy; 0x16uy; 0xceuy; 0x17uy; 0xafuy;
      0xcauy; 0xe3uy; 0x06uy; 0xeauy; 0x37uy; 0x98uy; 0xf2uy; 0x8fuy; 0x04uy; 0x9buy; 0xabuy; 0xd8uy;
      0xbduy; 0x78uy; 0x68uy; 0xacuy; 0xefuy; 0xb9uy; 0x28uy; 0x6fuy; 0x0buy; 0x37uy; 0x90uy; 0xb3uy;
      0x74uy; 0x0cuy; 0x38uy; 0x12uy; 0x70uy; 0xa2uy; 0xbeuy; 0xdcuy; 0xa7uy; 0x18uy; 0xdfuy; 0x5euy;
      0xd2uy; 0x62uy; 0xccuy; 0x43uy; 0x24uy; 0x32uy; 0x58uy; 0x45uy; 0x18uy; 0x0auy; 0xe1uy; 0x0duy;
      0x82uy; 0xbcuy; 0x08uy; 0xb1uy; 0xa9uy; 0x7euy; 0x63uy; 0x09uy; 0xc6uy; 0x83uy; 0xa1uy; 0xe6uy;
      0x5cuy; 0x9cuy; 0xefuy; 0x57uy; 0xecuy; 0xc7uy; 0x73uy; 0x19uy; 0xfbuy; 0x5cuy; 0x20uy; 0xe1uy;
      0xdfuy; 0x85uy; 0x76uy; 0xabuy; 0x89uy; 0xb7uy; 0x96uy; 0x8duy; 0xd9uy; 0x8euy; 0xb7uy; 0x00uy;
      0xa8uy; 0xc6uy; 0x98uy; 0x47uy; 0x03uy; 0xafuy; 0x56uy; 0x1fuy; 0x35uy; 0x49uy; 0x75uy; 0x4cuy;
      0xa2uy; 0xa2uy; 0xdcuy; 0x98uy; 0xbfuy; 0x87uy; 0xeduy; 0x73uy; 0x5fuy; 0x9buy; 0xabuy; 0x3euy;
      0x02uy; 0xdcuy; 0xa1uy; 0x4buy; 0x6cuy; 0xacuy; 0x10uy; 0xb2uy; 0x0buy; 0x99uy; 0xeeuy; 0xc8uy;
      0xc2uy; 0x82uy; 0xa9uy; 0xf9uy; 0xa9uy; 0xa5uy; 0x4duy; 0xc9uy; 0x39uy; 0x41uy; 0x89uy; 0x0cuy;
      0xc6uy; 0xe3uy; 0xaauy; 0x76uy; 0xe7uy; 0x11uy; 0x16uy; 0x8auy; 0x28uy; 0x6buy; 0x22uy; 0x3auy;
      0x1euy; 0x7duy; 0xe6uy; 0xf7uy; 0x55uy; 0x85uy; 0x8cuy; 0x36uy; 0x57uy; 0x0buy; 0xdbuy; 0xe6uy;
      0xefuy; 0xd9uy; 0xf6uy; 0x94uy; 0x48uy; 0x31uy; 0x7euy; 0xaauy; 0x13uy; 0xd4uy; 0x58uy; 0x9buy;
      0xebuy; 0x7cuy; 0x2auy; 0x39uy; 0xdduy; 0xa3uy; 0x3fuy; 0x70uy; 0xfduy; 0x7fuy; 0x30uy; 0xa3uy;
      0x34uy; 0xe6uy; 0xacuy; 0x64uy; 0x9buy; 0xf8uy; 0xbbuy; 0x1euy; 0x51uy; 0xe1uy; 0xaduy; 0x61uy;
      0xf6uy; 0xffuy; 0xd4uy; 0x4auy; 0x5euy; 0x12uy; 0x40uy; 0xdcuy; 0x07uy; 0x8buy; 0xb2uy; 0xe0uy;
      0xb9uy; 0x29uy; 0xaauy; 0x4euy; 0x85uy; 0xf5uy; 0xbduy; 0x5buy; 0x43uy; 0x77uy; 0xc7uy; 0x0buy;
      0xfeuy; 0x66uy; 0x49uy; 0xccuy; 0xb5uy; 0x92uy; 0x4auy; 0x14uy; 0x1euy; 0xe2uy; 0xe5uy; 0x20uy;
      0xfauy; 0xecuy; 0x0fuy; 0xc9uy
  ]

let test1_ct_expected =
  List.Tot.map u8_from_UInt8
    [
      0xebuy; 0x01uy; 0x36uy; 0x7duy; 0xe9uy; 0xdauy; 0x51uy; 0x3fuy; 0x8duy; 0xc7uy; 0x53uy; 0xdeuy;
      0xfcuy; 0xa2uy; 0x2cuy; 0xacuy; 0x2duy; 0xbcuy; 0x9buy; 0xacuy; 0x9cuy; 0xc0uy; 0xc5uy; 0x08uy;
      0x9duy; 0x0duy; 0x07uy; 0xbcuy; 0xd8uy; 0x69uy; 0x20uy; 0xccuy; 0x18uy; 0x0cuy; 0xbcuy; 0x7buy;
      0x49uy; 0x23uy; 0x06uy; 0x8cuy; 0x9cuy; 0xc4uy; 0x1fuy; 0xffuy; 0x53uy; 0x91uy; 0x9cuy; 0x7fuy;
      0xb4uy; 0xa7uy; 0x28uy; 0xdfuy; 0x30uy; 0x5euy; 0x9euy; 0x19uy; 0xd1uy; 0xbbuy; 0xe7uy; 0xacuy;
      0x0cuy; 0xb2uy; 0xbduy; 0x58uy; 0xd6uy; 0x96uy; 0x8buy; 0x04uy; 0x66uy; 0xf6uy; 0xbeuy; 0x58uy;
      0x25uy; 0xf9uy; 0xfbuy; 0xe1uy; 0x13uy; 0x7auy; 0x88uy; 0x57uy; 0xb6uy; 0xb5uy; 0x71uy; 0xe6uy;
      0xe2uy; 0x63uy; 0xd2uy; 0x85uy; 0x8duy; 0x07uy; 0x37uy; 0xe9uy; 0xaduy; 0xe9uy; 0x3duy; 0x95uy;
      0xccuy; 0x7euy; 0x56uy; 0x2duy; 0xaauy; 0x0buy; 0x13uy; 0xdfuy; 0xe8uy; 0x19uy; 0x7euy; 0x52uy;
      0x8duy; 0x7buy; 0xaauy; 0x09uy; 0x10uy; 0xb2uy; 0x32uy; 0x9cuy; 0x91uy; 0xf3uy; 0x14uy; 0x49uy;
      0x4auy; 0x9fuy; 0x38uy; 0xc0uy; 0xf5uy; 0xf4uy; 0x44uy; 0xc6uy; 0xf6uy; 0xf8uy; 0xd0uy; 0xb0uy;
      0x4fuy; 0xc1uy; 0xc3uy; 0xd7uy; 0x71uy; 0x18uy; 0xe3uy; 0xc0uy; 0xf5uy; 0x7auy; 0xd0uy; 0x04uy;
      0x4fuy; 0xcfuy; 0x76uy; 0xdcuy; 0xeeuy; 0x35uy; 0x21uy; 0xe0uy; 0x9euy; 0x41uy; 0x10uy; 0x06uy;
      0x2duy; 0xb8uy; 0x0cuy; 0xabuy; 0x1duy; 0x3duy; 0x60uy; 0xefuy; 0xaduy; 0xc5uy; 0x80uy; 0x09uy;
      0x56uy; 0xeeuy; 0xcbuy; 0x53uy; 0x1buy; 0x50uy; 0x95uy; 0x34uy; 0x47uy; 0xaeuy; 0x70uy; 0x96uy;
      0xbauy; 0x19uy; 0x55uy; 0x99uy; 0xd1uy; 0xb1uy; 0xe6uy; 0x32uy; 0xf0uy; 0x19uy; 0x3buy; 0x2buy;
      0xc7uy; 0x9cuy; 0xf7uy; 0xcauy; 0xa7uy; 0x3auy; 0xd3uy; 0xdcuy; 0xecuy; 0xf2uy; 0x49uy; 0x43uy;
      0x64uy; 0x7cuy; 0xfduy; 0x35uy; 0xe8uy; 0xfauy; 0xa5uy; 0x98uy; 0x01uy; 0x6buy; 0x4euy; 0xe5uy;
      0x84uy; 0x03uy; 0x24uy; 0xb6uy; 0xc7uy; 0x30uy; 0x13uy; 0x44uy; 0xd3uy; 0xe6uy; 0x97uy; 0xefuy;
      0xf7uy; 0x13uy; 0xefuy; 0x0euy; 0x9fuy; 0x12uy; 0x75uy; 0x76uy; 0x69uy; 0x7cuy; 0x91uy; 0x15uy;
      0x6cuy; 0xc0uy; 0xc2uy; 0x60uy; 0x8cuy; 0x63uy; 0xa7uy; 0xfauy; 0xc2uy; 0xf4uy; 0x17uy; 0xbauy;
      0x8buy; 0xd4uy; 0xcfuy; 0x4auy; 0x8duy; 0x63uy; 0xb8uy; 0xa4uy; 0x6buy; 0x9cuy; 0x87uy; 0x94uy;
      0x37uy; 0x05uy; 0x9duy; 0xc4uy; 0x76uy; 0x24uy; 0x77uy; 0x79uy; 0x4duy; 0x93uy; 0x62uy; 0x0buy;
      0xbcuy; 0x72uy; 0x7euy; 0xb2uy; 0xefuy; 0x3cuy; 0x00uy; 0x1cuy; 0x18uy; 0x18uy; 0xbbuy; 0xe8uy;
      0x60uy; 0x6euy; 0xc5uy; 0x9buy; 0x47uy; 0x93uy; 0x77uy; 0xd8uy; 0xf0uy; 0x45uy; 0x16uy; 0x97uy;
      0x15uy; 0xc0uy; 0xd3uy; 0x4euy; 0x6duy; 0xe9uy; 0xfeuy; 0x89uy; 0xc3uy; 0x87uy; 0x3auy; 0x49uy;
      0xfbuy; 0x9duy; 0x86uy; 0xffuy; 0xcauy; 0xa1uy; 0x3fuy; 0x15uy; 0x37uy; 0xd8uy; 0x98uy; 0xeeuy;
      0xd9uy; 0x36uy; 0x06uy; 0x33uy; 0xd8uy; 0xdauy; 0x82uy; 0xeeuy; 0x60uy; 0x8cuy; 0xc7uy; 0xf3uy;
      0x19uy; 0x47uy; 0x15uy; 0x7fuy; 0xd3uy; 0xf1uy; 0x30uy; 0xa2uy; 0xc6uy; 0xc4uy; 0x04uy; 0x5cuy;
      0x50uy; 0xa3uy; 0x48uy; 0xc8uy; 0x1buy; 0x35uy; 0xfeuy; 0xa5uy; 0xeauy; 0x8auy; 0x4auy; 0x8cuy;
      0x9cuy; 0x85uy; 0x8cuy; 0x1fuy; 0xbbuy; 0x3duy; 0xafuy; 0x2euy; 0x3auy; 0xaduy; 0x34uy; 0x6cuy;
      0x5duy; 0x87uy; 0xc9uy; 0xc9uy; 0x7fuy; 0x30uy; 0xc1uy; 0x8duy; 0x4cuy; 0xd6uy; 0xbfuy; 0xc0uy;
      0xf8uy; 0xa7uy; 0xb2uy; 0x91uy; 0x9buy; 0xe7uy; 0x85uy; 0x96uy; 0xe8uy; 0xb3uy; 0xaeuy; 0x89uy;
      0x53uy; 0x41uy; 0x48uy; 0x0euy; 0xd0uy; 0x6auy; 0x4euy; 0x0cuy; 0x7duy; 0x10uy; 0xa1uy; 0xe8uy;
      0x9duy; 0x7cuy; 0xdcuy; 0x76uy; 0x91uy; 0x86uy; 0x70uy; 0x67uy; 0xe1uy; 0x76uy; 0x4duy; 0x23uy;
      0xeauy; 0x55uy; 0x62uy; 0xb9uy; 0x61uy; 0x7fuy; 0x24uy; 0xd3uy; 0x06uy; 0xd8uy; 0x15uy; 0x88uy;
      0x52uy; 0x92uy; 0x8auy; 0xc1uy; 0x8auy; 0x1cuy; 0x7buy; 0x40uy; 0xfauy; 0x03uy; 0xe0uy; 0x93uy;
      0xf7uy; 0x2duy; 0xf1uy; 0xdcuy; 0x27uy; 0x10uy; 0xd4uy; 0x28uy; 0x0auy; 0x61uy; 0x87uy; 0xbfuy;
      0x09uy; 0xfbuy; 0xb1uy; 0xc7uy; 0xd8uy; 0xe9uy; 0xfauy; 0xa5uy; 0xa8uy; 0x6buy; 0x6duy; 0xa0uy;
      0x64uy; 0xb7uy; 0xe4uy; 0x86uy; 0x79uy; 0x6euy; 0x85uy; 0x93uy; 0x94uy; 0xc9uy; 0xdeuy; 0xa9uy;
      0x40uy; 0xb3uy; 0x6euy; 0xa0uy; 0xa6uy; 0xc8uy; 0xc9uy; 0x84uy; 0x3euy; 0xdbuy; 0x1duy; 0xa8uy;
      0xbcuy; 0x04uy; 0x1cuy; 0xa4uy; 0x4fuy; 0x70uy; 0x77uy; 0xafuy; 0x98uy; 0x71uy; 0xc6uy; 0xbeuy;
      0x24uy; 0x58uy; 0xc9uy; 0x53uy; 0x20uy; 0xd2uy; 0xeauy; 0x3duy; 0xe7uy; 0x3fuy; 0x8cuy; 0x44uy;
      0xc8uy; 0x3fuy; 0x14uy; 0x50uy; 0xcduy; 0xc8uy; 0x45uy; 0x99uy; 0xf8uy; 0xb6uy; 0xd5uy; 0x99uy;
      0x5auy; 0x77uy; 0x61uy; 0x48uy; 0x9fuy; 0x1auy; 0xb0uy; 0x6fuy; 0x1cuy; 0x27uy; 0x35uy; 0x80uy;
      0xe6uy; 0x1euy; 0xe2uy; 0x75uy; 0xafuy; 0xf8uy; 0x10uy; 0x6duy; 0x0euy; 0xe6uy; 0x8auy; 0xb5uy;
      0xffuy; 0x6cuy; 0x1euy; 0x41uy; 0x60uy; 0x93uy; 0xebuy; 0xffuy; 0x9fuy; 0xffuy; 0xf7uy; 0xcauy;
      0x77uy; 0x2fuy; 0xc2uy; 0x44uy; 0xe8uy; 0x86uy; 0x23uy; 0x8auy; 0x2euy; 0xa7uy; 0x1buy; 0xb2uy;
      0x8auy; 0x6cuy; 0x79uy; 0x0euy; 0x4duy; 0xe2uy; 0x09uy; 0xa7uy; 0xdauy; 0x60uy; 0x54uy; 0x55uy;
      0x36uy; 0xb9uy; 0x06uy; 0x51uy; 0xd9uy; 0x1duy; 0x6cuy; 0xaauy; 0x0buy; 0x03uy; 0xb1uy; 0x38uy;
      0x63uy; 0xd7uy; 0x29uy; 0x76uy; 0xf6uy; 0xc5uy; 0x73uy; 0x0auy; 0x0euy; 0x1duy; 0xf7uy; 0xc9uy;
      0x5auy; 0xdauy; 0xdcuy; 0x64uy; 0xd5uy; 0x9fuy; 0x51uy; 0xc8uy; 0x8euy; 0x6fuy; 0xf6uy; 0xb9uy;
      0x0cuy; 0xd4uy; 0x57uy; 0x5duy; 0x82uy; 0x4euy; 0xeeuy; 0xc6uy; 0x8auy; 0xf5uy; 0x7fuy; 0x59uy;
      0xe1uy; 0x0cuy; 0xb8uy; 0xe7uy; 0xf6uy; 0xc6uy; 0x2auy; 0xb1uy; 0x5auy; 0xbauy; 0x77uy; 0xa0uy;
      0x30uy; 0x19uy; 0x10uy; 0xe6uy; 0x5auy; 0x90uy; 0x03uy; 0x21uy; 0x3euy; 0xd8uy; 0xc1uy; 0xc5uy;
      0xc5uy; 0x81uy; 0xf7uy; 0xc1uy; 0x6auy; 0xfauy; 0xecuy; 0xf6uy; 0x31uy; 0x0duy; 0xf6uy; 0x85uy;
      0x9fuy; 0xb5uy; 0x34uy; 0x38uy; 0xf8uy; 0xc1uy; 0xe6uy; 0x7euy; 0x67uy; 0x8buy; 0x14uy; 0x01uy;
      0x3buy; 0x32uy; 0xb6uy; 0xb1uy; 0x90uy; 0x91uy; 0xbcuy; 0x40uy; 0x90uy; 0x72uy; 0x55uy; 0x76uy;
      0x2buy; 0x34uy; 0x3buy; 0x05uy; 0x65uy; 0x87uy; 0x0euy; 0x4buy; 0xb5uy; 0xcduy; 0x94uy; 0x88uy;
      0x60uy; 0xf0uy; 0x7duy; 0xc9uy; 0x21uy; 0x71uy; 0xe2uy; 0x55uy; 0x43uy; 0x06uy; 0x1cuy; 0x84uy;
      0x02uy; 0xd0uy; 0x4euy; 0xcbuy; 0x1buy; 0x38uy; 0x6duy; 0x58uy; 0x62uy; 0xabuy; 0x50uy; 0xcfuy;
      0xb5uy; 0x47uy; 0x24uy; 0xb8uy; 0x6cuy; 0x00uy; 0xa4uy; 0xf2uy; 0x97uy; 0x9fuy; 0xf3uy; 0x98uy;
      0x2euy; 0xf9uy; 0x4fuy; 0x02uy; 0xdcuy; 0x1duy; 0xc6uy; 0x08uy; 0x35uy; 0x57uy; 0xe5uy; 0x9buy;
      0xd7uy; 0xf4uy; 0xd7uy; 0x28uy; 0x50uy; 0x39uy; 0xfduy; 0xd8uy; 0xe6uy; 0xbfuy; 0xcauy; 0x61uy;
      0x65uy; 0xe3uy; 0xd0uy; 0x95uy; 0x65uy; 0x68uy; 0xb1uy; 0x41uy; 0x65uy; 0x1auy; 0x62uy; 0xceuy;
      0x65uy; 0x8fuy; 0xeeuy; 0xe7uy; 0x7auy; 0x3cuy; 0x04uy; 0x95uy; 0x01uy; 0xd1uy; 0x31uy; 0x75uy;
      0x80uy; 0x69uy; 0x1euy; 0x4buy; 0xb3uy; 0x4fuy; 0xb9uy; 0x5buy; 0x5cuy; 0x8euy; 0x16uy; 0x01uy;
      0x99uy; 0x02uy; 0x55uy; 0x94uy; 0x0buy; 0xa9uy; 0x49uy; 0x7cuy; 0x10uy; 0xd4uy; 0xc9uy; 0xdduy;
      0x2buy; 0xabuy; 0x8buy; 0x4cuy; 0x21uy; 0x7auy; 0x7duy; 0x53uy; 0x7buy; 0xd0uy; 0x69uy; 0x45uy;
      0xcauy; 0x9auy; 0x91uy; 0x40uy; 0x54uy; 0x03uy; 0xb3uy; 0x56uy; 0x0euy; 0xc6uy; 0x68uy; 0x30uy;
      0xdcuy; 0xb1uy; 0xffuy; 0xe4uy; 0x3fuy; 0x0euy; 0x1euy; 0xc0uy; 0x56uy; 0xb2uy; 0xe1uy; 0xfcuy;
      0x58uy; 0xf5uy; 0xabuy; 0x39uy; 0x4euy; 0xdduy; 0x33uy; 0xbcuy; 0x12uy; 0xc5uy; 0xdcuy; 0x77uy;
      0x46uy; 0x84uy; 0x82uy; 0xb2uy; 0x7fuy; 0xa2uy; 0xf6uy; 0x06uy; 0x24uy; 0xd6uy; 0x3cuy; 0xe3uy;
      0xc5uy; 0xc2uy; 0x18uy; 0xc4uy; 0xc9uy; 0xf5uy; 0xa3uy; 0x2auy; 0x56uy; 0x5buy; 0x59uy; 0xe7uy;
      0x00uy; 0x92uy; 0xb4uy; 0xd6uy; 0xf9uy; 0x96uy; 0x7cuy; 0x01uy; 0x26uy; 0x1euy; 0x5fuy; 0x27uy;
      0x9cuy; 0x1buy; 0xb7uy; 0xf7uy; 0x36uy; 0xebuy; 0x7auy; 0xf3uy; 0xa7uy; 0x5euy; 0x38uy; 0xb2uy;
      0x7buy; 0x7fuy; 0xd1uy; 0x4euy; 0x68uy; 0xb9uy; 0xa9uy; 0xf8uy; 0x7auy; 0x06uy; 0xb4uy; 0xe8uy;
      0x42uy; 0xd8uy; 0xc7uy; 0x5auy; 0x08uy; 0xd5uy; 0x67uy; 0xa7uy; 0x30uy; 0xb6uy; 0x2euy; 0x80uy;
      0xacuy; 0xa9uy; 0x07uy; 0xbbuy; 0x18uy; 0x54uy; 0xc3uy; 0x81uy; 0x6euy; 0x8auy; 0x24uy; 0xc0uy;
      0x7fuy; 0xd0uy; 0x54uy; 0xb2uy; 0xe7uy; 0x1auy; 0x11uy; 0xf4uy; 0x9duy; 0x2cuy; 0x75uy; 0x37uy;
      0x2euy; 0xc6uy; 0xfcuy; 0x85uy; 0x5duy; 0x46uy; 0x44uy; 0x7auy; 0x36uy; 0xe5uy; 0x62uy; 0xa4uy;
      0x26uy; 0xdduy; 0x4cuy; 0x20uy; 0x33uy; 0x7auy; 0x8auy; 0x41uy; 0x8auy; 0x0fuy; 0xa4uy; 0xf8uy;
      0x74uy; 0x45uy; 0x98uy; 0xe3uy; 0x73uy; 0xa1uy; 0x4euy; 0x40uy; 0x10uy; 0x5buy; 0x0fuy; 0xa0uy;
      0xe4uy; 0x5euy; 0x97uy; 0x40uy; 0xdcuy; 0x68uy; 0x79uy; 0xd7uy; 0xfeuy; 0xfduy; 0x34uy; 0xd0uy;
      0xb7uy; 0xcbuy; 0x4auy; 0xf3uy; 0xb0uy; 0xc7uy; 0xf5uy; 0xbauy; 0x6cuy; 0xa9uy; 0xf0uy; 0x82uy;
      0x01uy; 0xb2uy; 0x3fuy; 0x9euy; 0x56uy; 0x9cuy; 0x86uy; 0x05uy; 0x03uy; 0x99uy; 0x2euy; 0xe7uy;
      0xeduy; 0xdfuy; 0xfeuy; 0x05uy; 0x3buy; 0xdbuy; 0x3cuy; 0x30uy; 0x98uy; 0xa2uy; 0x23uy; 0x86uy;
      0xefuy; 0x80uy; 0xe4uy; 0x2fuy; 0xdeuy; 0x8cuy; 0x7duy; 0x2euy; 0x78uy; 0xdbuy; 0xd6uy; 0xcauy;
      0x7fuy; 0x79uy; 0x7auy; 0x3buy; 0xafuy; 0x2auy; 0xeduy; 0xf3uy; 0x03uy; 0x15uy; 0xccuy; 0x3duy;
      0x52uy; 0x50uy; 0x1duy; 0x08uy; 0x93uy; 0xa2uy; 0xd8uy; 0x63uy; 0x91uy; 0xa0uy; 0x6cuy; 0xccuy
  ]

let test1_sk_expected =
  List.Tot.map u8_from_UInt8
    [
      0xa6uy; 0x65uy; 0x65uy; 0x9fuy; 0xfbuy; 0xe4uy; 0x06uy; 0x5cuy; 0xcauy; 0x81uy; 0x5auy; 0x45uy;
      0xe4uy; 0x94uy; 0xd8uy; 0x01uy; 0x0duy; 0xacuy; 0x6fuy; 0x83uy; 0x94uy; 0x00uy; 0x1auy; 0xcauy;
      0x97uy; 0xa1uy; 0xaauy; 0x42uy; 0x80uy; 0x9duy; 0x6buy; 0xa5uy; 0xfcuy; 0x64uy; 0x43uy; 0xdbuy;
      0xbeuy; 0x6fuy; 0x12uy; 0x2auy; 0x94uy; 0x58uy; 0x36uy; 0xf2uy; 0xb1uy; 0xf8uy; 0xe5uy; 0xf0uy;
      0x57uy; 0x4buy; 0x35uy; 0x51uy; 0xdduy; 0x8cuy; 0x36uy; 0x28uy; 0x34uy; 0x46uy; 0xd6uy; 0xafuy;
      0x5duy; 0x49uy; 0x0euy; 0x27uy; 0xd8uy; 0xd3uy; 0xaduy; 0xe1uy; 0xeduy; 0x8buy; 0x2duy; 0x13uy;
      0xf5uy; 0x5auy; 0xb6uy; 0xdduy; 0xc0uy; 0x54uy; 0x76uy; 0x09uy; 0xa6uy; 0xa4uy; 0x01uy; 0xb9uy;
      0xb7uy; 0xd1uy; 0x26uy; 0xd5uy; 0x1euy; 0xa8uy; 0x20uy; 0x4duy; 0xe8uy; 0xefuy; 0xaduy; 0xb9uy;
      0xf0uy; 0x65uy; 0xe9uy; 0xc4uy; 0xf4uy; 0x11uy; 0x98uy; 0x99uy; 0xf0uy; 0x2cuy; 0x63uy; 0x7buy;
      0x98uy; 0xd7uy; 0x60uy; 0x43uy; 0x5duy; 0x8cuy; 0x85uy; 0xe9uy; 0xc5uy; 0x83uy; 0x83uy; 0x62uy;
      0xe2uy; 0x13uy; 0x33uy; 0x54uy; 0x4buy; 0x71uy; 0xaeuy; 0x63uy; 0xbauy; 0x5auy; 0x4euy; 0x32uy;
      0x59uy; 0x78uy; 0x6buy; 0x4duy; 0x39uy; 0xcfuy; 0xe1uy; 0x82uy; 0x58uy; 0x0auy; 0xc3uy; 0x61uy;
      0x6auy; 0x89uy; 0x2fuy; 0x1buy; 0x70uy; 0xdduy; 0x16uy; 0x3euy; 0x96uy; 0xb1uy; 0x4cuy; 0x71uy;
      0xb1uy; 0x79uy; 0x0cuy; 0x3fuy; 0xe2uy; 0xeduy; 0x05uy; 0x07uy; 0x72uy; 0xf3uy; 0x89uy; 0x08uy;
      0x8cuy; 0x22uy; 0xa7uy; 0x36uy; 0x40uy; 0xcauy; 0x52uy; 0x70uy; 0x1buy; 0x09uy; 0xcbuy; 0xabuy;
      0x3buy; 0x64uy; 0x61uy; 0x6duy; 0x5duy; 0xf7uy; 0x15uy; 0x69uy; 0x71uy; 0x3buy; 0x3auy; 0x2euy;
      0x53uy; 0x33uy; 0x26uy; 0xe6uy; 0x29uy; 0x5cuy; 0xfbuy; 0x0duy; 0xc6uy; 0xe4uy; 0xbduy; 0x9cuy;
      0x43uy; 0xffuy; 0xa6uy; 0x5buy; 0x49uy; 0x47uy; 0x93uy; 0x1cuy; 0x81uy; 0x6fuy; 0xd4uy; 0xaauy;
      0x3duy; 0xaduy; 0x86uy; 0xf5uy; 0x94uy; 0x16uy; 0x7fuy; 0x31uy; 0x91uy; 0x30uy; 0x97uy; 0xc4uy;
      0xa3uy; 0xe4uy; 0x01uy; 0x2buy; 0x06uy; 0xcfuy; 0x69uy; 0xfbuy; 0x69uy; 0x35uy; 0xaauy; 0x81uy;
      0xeduy; 0x90uy; 0x0cuy; 0x3auy; 0xc0uy; 0xa6uy; 0x06uy; 0xabuy; 0x51uy; 0x3fuy; 0x39uy; 0xb2uy;
      0x1euy; 0xb0uy; 0x4buy; 0xbcuy; 0xd0uy; 0xd0uy; 0x3auy; 0xdauy; 0x89uy; 0x88uy; 0xa6uy; 0x56uy;
      0xd8uy; 0x02uy; 0x98uy; 0xeeuy; 0xa2uy; 0xf5uy; 0x0euy; 0xbauy; 0x7cuy; 0x52uy; 0xafuy; 0xf4uy;
      0xbbuy; 0xe7uy; 0x36uy; 0x4auy; 0xdduy; 0x90uy; 0x93uy; 0xe9uy; 0x5duy; 0xbeuy; 0x68uy; 0x99uy;
      0xc2uy; 0xaduy; 0x4duy; 0x79uy; 0x25uy; 0x0buy; 0x69uy; 0x79uy; 0x7buy; 0xe2uy; 0x3duy; 0xa8uy;
      0xe7uy; 0xf1uy; 0x42uy; 0x0cuy; 0x22uy; 0x85uy; 0x95uy; 0xf0uy; 0xd5uy; 0x5cuy; 0x96uy; 0x35uy;
      0xb6uy; 0x19uy; 0xaeuy; 0xb3uy; 0xcfuy; 0x22uy; 0xcauy; 0xbauy; 0x28uy; 0xd6uy; 0xdduy; 0xd5uy;
      0x8euy; 0xe8uy; 0xd6uy; 0x90uy; 0x23uy; 0x8euy; 0x97uy; 0x37uy; 0xe9uy; 0xcduy; 0xabuy; 0xdcuy;
      0x08uy; 0x04uy; 0xe1uy; 0x32uy; 0x02uy; 0xffuy; 0x7fuy; 0x82uy; 0x41uy; 0xf3uy; 0x9buy; 0x1duy;
      0x42uy; 0x8auy; 0x98uy; 0x80uy; 0x81uy; 0xaauy; 0xbeuy; 0x7duy; 0x3buy; 0x83uy; 0x30uy; 0x4duy;
      0x4auy; 0x22uy; 0x2duy; 0xafuy; 0x61uy; 0xd1uy; 0xa0uy; 0x66uy; 0xd4uy; 0x48uy; 0x0fuy; 0xe1uy;
      0xd9uy; 0x77uy; 0x82uy; 0xc5uy; 0xa1uy; 0x2auy; 0x03uy; 0x1fuy; 0xd0uy; 0x7auy; 0xccuy; 0x77uy;
      0x09uy; 0x4auy; 0xbduy; 0xaduy; 0xf7uy; 0x76uy; 0xdcuy; 0x10uy; 0xeduy; 0x5buy; 0xdfuy; 0x89uy;
      0xfbuy; 0x52uy; 0x60uy; 0x5cuy; 0x08uy; 0x42uy; 0x50uy; 0xd1uy; 0xdauy; 0x24uy; 0xbbuy; 0x59uy;
      0x3euy; 0x14uy; 0xf4uy; 0xf0uy; 0xf4uy; 0xdauy; 0xb8uy; 0x00uy; 0xe2uy; 0x0buy; 0xfauy; 0xc3uy;
      0xf6uy; 0x28uy; 0x8duy; 0x20uy; 0x26uy; 0xe9uy; 0x5buy; 0x25uy; 0xa8uy; 0x80uy; 0x4cuy; 0xeeuy;
      0xc9uy; 0xb6uy; 0x7auy; 0x8buy; 0x87uy; 0x21uy; 0xfduy; 0xaeuy; 0xd5uy; 0xa8uy; 0x49uy; 0x33uy;
      0x58uy; 0x90uy; 0x2cuy; 0x0auy; 0xcauy; 0xb0uy; 0x9duy; 0xbeuy; 0xcduy; 0xe0uy; 0xa4uy; 0x99uy;
      0x76uy; 0x01uy; 0x80uy; 0xdduy; 0x66uy; 0x76uy; 0x70uy; 0x05uy; 0xf3uy; 0xd6uy; 0x31uy; 0xa1uy;
      0x9euy; 0xd5uy; 0x5fuy; 0x1buy; 0xdduy; 0x7fuy; 0x81uy; 0x6duy; 0x5cuy; 0xe9uy; 0xa3uy; 0x1auy;
      0x6auy; 0x87uy; 0x93uy; 0xaduy; 0x1duy; 0x73uy; 0x44uy; 0xbcuy; 0xe4uy; 0x42uy; 0x78uy; 0x6auy;
      0x71uy; 0x58uy; 0x9buy; 0x73uy; 0x55uy; 0x63uy; 0xa5uy; 0x32uy; 0xf6uy; 0x55uy; 0x68uy; 0x05uy;
      0xcfuy; 0xeduy; 0x5fuy; 0x86uy; 0xe2uy; 0x65uy; 0xefuy; 0xf1uy; 0xb9uy; 0x69uy; 0xbbuy; 0x79uy;
      0xb1uy; 0xf4uy; 0x7fuy; 0xa5uy; 0xfauy; 0x62uy; 0xbcuy; 0x68uy; 0xe7uy; 0xf6uy; 0xf8uy; 0xf0uy;
      0x55uy; 0xf4uy; 0x93uy; 0x47uy; 0x06uy; 0xf0uy; 0x3euy; 0x94uy; 0x4auy; 0x95uy; 0xc8uy; 0x0cuy;
      0xb0uy; 0x04uy; 0x4euy; 0x3fuy; 0x67uy; 0x14uy; 0xeduy; 0xbbuy; 0xbeuy; 0xf0uy; 0xabuy; 0xdduy;
      0x6cuy; 0x23uy; 0x4euy; 0x07uy; 0x66uy; 0x41uy; 0x55uy; 0xbeuy; 0x22uy; 0x59uy; 0xd5uy; 0xdauy;
      0xd4uy; 0xd8uy; 0x3duy; 0xb0uy; 0x74uy; 0xc4uy; 0x4fuy; 0x9buy; 0x43uy; 0xe5uy; 0x75uy; 0xfbuy;
      0x33uy; 0x0euy; 0xdfuy; 0xe1uy; 0xe3uy; 0x7duy; 0x2euy; 0x80uy; 0x10uy; 0x79uy; 0x17uy; 0xeauy;
      0xd3uy; 0x18uy; 0x98uy; 0x08uy; 0xeduy; 0x79uy; 0x4cuy; 0xb9uy; 0x66uy; 0x03uy; 0x04uy; 0x50uy;
      0xfeuy; 0x62uy; 0x0duy; 0x48uy; 0x1auy; 0x6cuy; 0xeeuy; 0xb7uy; 0x03uy; 0x15uy; 0x92uy; 0x41uy;
      0x1euy; 0xa1uy; 0x88uy; 0x46uy; 0x1auy; 0x43uy; 0x49uy; 0xf5uy; 0x93uy; 0x33uy; 0x00uy; 0x65uy;
      0x69uy; 0xa8uy; 0x82uy; 0xbduy; 0xbeuy; 0x5cuy; 0x56uy; 0xa3uy; 0x06uy; 0x00uy; 0x8buy; 0x2fuy;
      0x7duy; 0xecuy; 0xa4uy; 0x9auy; 0x2auy; 0xaeuy; 0x66uy; 0x07uy; 0x46uy; 0xb3uy; 0xbeuy; 0xf8uy;
      0x07uy; 0x08uy; 0x10uy; 0x87uy; 0xd5uy; 0x6cuy; 0x6auy; 0xa5uy; 0xa6uy; 0x07uy; 0x4buy; 0x00uy;
      0xc1uy; 0x5auy; 0xeduy; 0x7fuy; 0x14uy; 0x4buy; 0x60uy; 0x02uy; 0xc2uy; 0x67uy; 0x0cuy; 0xa4uy;
      0x64uy; 0x54uy; 0x3euy; 0x22uy; 0xfeuy; 0x21uy; 0xcduy; 0x0duy; 0xcbuy; 0x60uy; 0x3buy; 0x13uy;
      0xb0uy; 0x8euy; 0x36uy; 0xcauy; 0xcduy; 0x78uy; 0x8duy; 0x08uy; 0x2auy; 0xf1uy; 0x9cuy; 0x17uy;
      0x11uy; 0x14uy; 0x57uy; 0x57uy; 0xe8uy; 0x3buy; 0x84uy; 0xe8uy; 0x59uy; 0xdbuy; 0x5buy; 0x77uy;
      0x2euy; 0x54uy; 0x3buy; 0x6euy; 0x9cuy; 0x5euy; 0x7fuy; 0x52uy; 0xe5uy; 0x06uy; 0x8auy; 0x2duy;
      0xc3uy; 0xbfuy; 0x30uy; 0x34uy; 0x8cuy; 0xaauy; 0x3buy; 0x23uy; 0x59uy; 0x32uy; 0x5fuy; 0xf7uy;
      0xc9uy; 0xb2uy; 0xeeuy; 0xb2uy; 0x72uy; 0x75uy; 0x33uy; 0x8euy; 0xa9uy; 0x68uy; 0x6euy; 0xf5uy;
      0x61uy; 0x7auy; 0x20uy; 0x01uy; 0xecuy; 0xabuy; 0x19uy; 0x26uy; 0xbeuy; 0x38uy; 0x49uy; 0xe2uy;
      0x16uy; 0xceuy; 0x17uy; 0xafuy; 0xcauy; 0xe3uy; 0x06uy; 0xeauy; 0x37uy; 0x98uy; 0xf2uy; 0x8fuy;
      0x04uy; 0x9buy; 0xabuy; 0xd8uy; 0xbduy; 0x78uy; 0x68uy; 0xacuy; 0xefuy; 0xb9uy; 0x28uy; 0x6fuy;
      0x0buy; 0x37uy; 0x90uy; 0xb3uy; 0x74uy; 0x0cuy; 0x38uy; 0x12uy; 0x70uy; 0xa2uy; 0xbeuy; 0xdcuy;
      0xa7uy; 0x18uy; 0xdfuy; 0x5euy; 0xd2uy; 0x62uy; 0xccuy; 0x43uy; 0x24uy; 0x32uy; 0x58uy; 0x45uy;
      0x18uy; 0x0auy; 0xe1uy; 0x0duy; 0x82uy; 0xbcuy; 0x08uy; 0xb1uy; 0xa9uy; 0x7euy; 0x63uy; 0x09uy;
      0xc6uy; 0x83uy; 0xa1uy; 0xe6uy; 0x5cuy; 0x9cuy; 0xefuy; 0x57uy; 0xecuy; 0xc7uy; 0x73uy; 0x19uy;
      0xfbuy; 0x5cuy; 0x20uy; 0xe1uy; 0xdfuy; 0x85uy; 0x76uy; 0xabuy; 0x89uy; 0xb7uy; 0x96uy; 0x8duy;
      0xd9uy; 0x8euy; 0xb7uy; 0x00uy; 0xa8uy; 0xc6uy; 0x98uy; 0x47uy; 0x03uy; 0xafuy; 0x56uy; 0x1fuy;
      0x35uy; 0x49uy; 0x75uy; 0x4cuy; 0xa2uy; 0xa2uy; 0xdcuy; 0x98uy; 0xbfuy; 0x87uy; 0xeduy; 0x73uy;
      0x5fuy; 0x9buy; 0xabuy; 0x3euy; 0x02uy; 0xdcuy; 0xa1uy; 0x4buy; 0x6cuy; 0xacuy; 0x10uy; 0xb2uy;
      0x0buy; 0x99uy; 0xeeuy; 0xc8uy; 0xc2uy; 0x82uy; 0xa9uy; 0xf9uy; 0xa9uy; 0xa5uy; 0x4duy; 0xc9uy;
      0x39uy; 0x41uy; 0x89uy; 0x0cuy; 0xc6uy; 0xe3uy; 0xaauy; 0x76uy; 0xe7uy; 0x11uy; 0x16uy; 0x8auy;
      0x28uy; 0x6buy; 0x22uy; 0x3auy; 0x1euy; 0x7duy; 0xe6uy; 0xf7uy; 0x55uy; 0x85uy; 0x8cuy; 0x36uy;
      0x57uy; 0x0buy; 0xdbuy; 0xe6uy; 0xefuy; 0xd9uy; 0xf6uy; 0x94uy; 0x48uy; 0x31uy; 0x7euy; 0xaauy;
      0x13uy; 0xd4uy; 0x58uy; 0x9buy; 0xebuy; 0x7cuy; 0x2auy; 0x39uy; 0xdduy; 0xa3uy; 0x3fuy; 0x70uy;
      0xfduy; 0x7fuy; 0x30uy; 0xa3uy; 0x34uy; 0xe6uy; 0xacuy; 0x64uy; 0x9buy; 0xf8uy; 0xbbuy; 0x1euy;
      0x51uy; 0xe1uy; 0xaduy; 0x61uy; 0xf6uy; 0xffuy; 0xd4uy; 0x4auy; 0x5euy; 0x12uy; 0x40uy; 0xdcuy;
      0x07uy; 0x8buy; 0xb2uy; 0xe0uy; 0xb9uy; 0x29uy; 0xaauy; 0x4euy; 0x85uy; 0xf5uy; 0xbduy; 0x5buy;
      0x43uy; 0x77uy; 0xc7uy; 0x0buy; 0xfeuy; 0x66uy; 0x49uy; 0xccuy; 0xb5uy; 0x92uy; 0x4auy; 0x14uy;
      0x1euy; 0xe2uy; 0xe5uy; 0x20uy; 0xfauy; 0xecuy; 0x0fuy; 0xc9uy; 0x02uy; 0x00uy; 0xffuy; 0xffuy;
      0xfeuy; 0xffuy; 0x01uy; 0x00uy; 0x00uy; 0x00uy; 0xfduy; 0xffuy; 0x02uy; 0x00uy; 0x05uy; 0x00uy;
      0x04uy; 0x00uy; 0xfauy; 0xffuy; 0xffuy; 0xffuy; 0x02uy; 0x00uy; 0xfduy; 0xffuy; 0xfduy; 0xffuy;
      0x00uy; 0x00uy; 0x01uy; 0x00uy; 0x03uy; 0x00uy; 0xffuy; 0xffuy; 0x00uy; 0x00uy; 0xfbuy; 0xffuy;
      0xfeuy; 0xffuy; 0xfeuy; 0xffuy; 0x00uy; 0x00uy; 0xffuy; 0xffuy; 0x00uy; 0x00uy; 0xffuy; 0xffuy;
      0xfauy; 0xffuy; 0xfduy; 0xffuy; 0x04uy; 0x00uy; 0xffuy; 0xffuy; 0x05uy; 0x00uy; 0x05uy; 0x00uy;
      0xfeuy; 0xffuy; 0x03uy; 0x00uy; 0x00uy; 0x00uy; 0xffuy; 0xffuy; 0xfduy; 0xffuy; 0x02uy; 0x00uy;
      0xffuy; 0xffuy; 0xfduy; 0xffuy; 0x01uy; 0x00uy; 0xfeuy; 0xffuy; 0xffuy; 0xffuy; 0xffuy; 0xffuy;
      0x06uy; 0x00uy; 0xffuy; 0xffuy; 0x03uy; 0x00uy; 0x03uy; 0x00uy; 0xfduy; 0xffuy; 0x04uy; 0x00uy;
      0x01uy; 0x00uy; 0x00uy; 0x00uy; 0xffuy; 0xffuy; 0x07uy; 0x00uy; 0xfcuy; 0xffuy; 0x05uy; 0x00uy;
      0x04uy; 0x00uy; 0x04uy; 0x00uy; 0xfeuy; 0xffuy; 0xfduy; 0xffuy; 0xfeuy; 0xffuy; 0xfduy; 0xffuy;
      0xfeuy; 0xffuy; 0xfeuy; 0xffuy; 0x00uy; 0x00uy; 0x03uy; 0x00uy; 0x02uy; 0x00uy; 0x02uy; 0x00uy;
      0x03uy; 0x00uy; 0x06uy; 0x00uy; 0x00uy; 0x00uy; 0xfeuy; 0xffuy; 0xfeuy; 0xffuy; 0x06uy; 0x00uy;
      0x02uy; 0x00uy; 0xffuy; 0xffuy; 0x00uy; 0x00uy; 0x00uy; 0x00uy; 0x01uy; 0x00uy; 0xffuy; 0xffuy;
      0x04uy; 0x00uy; 0xffuy; 0xffuy; 0x03uy; 0x00uy; 0xfduy; 0xffuy; 0xfduy; 0xffuy; 0xffuy; 0xffuy;
      0x03uy; 0x00uy; 0xfduy; 0xffuy; 0xfduy; 0xffuy; 0x03uy; 0x00uy; 0x04uy; 0x00uy; 0x03uy; 0x00uy;
      0xfduy; 0xffuy; 0x02uy; 0x00uy; 0x01uy; 0x00uy; 0x02uy; 0x00uy; 0xffuy; 0xffuy; 0x04uy; 0x00uy;
      0xfeuy; 0xffuy; 0xffuy; 0xffuy; 0xfcuy; 0xffuy; 0xfeuy; 0xffuy; 0xfeuy; 0xffuy; 0x00uy; 0x00uy;
      0xfduy; 0xffuy; 0x02uy; 0x00uy; 0x00uy; 0x00uy; 0xffuy; 0xffuy; 0xffuy; 0xffuy; 0x02uy; 0x00uy;
      0x00uy; 0x00uy; 0xffuy; 0xffuy; 0x01uy; 0x00uy; 0xfeuy; 0xffuy; 0x00uy; 0x00uy; 0xfduy; 0xffuy;
      0xffuy; 0xffuy; 0x01uy; 0x00uy; 0x02uy; 0x00uy; 0xfbuy; 0xffuy; 0x03uy; 0x00uy; 0xfcuy; 0xffuy;
      0x04uy; 0x00uy; 0xfbuy; 0xffuy; 0xffuy; 0xffuy; 0x02uy; 0x00uy; 0x00uy; 0x00uy; 0x00uy; 0x00uy;
      0x02uy; 0x00uy; 0x04uy; 0x00uy; 0xffuy; 0xffuy; 0xffuy; 0xffuy; 0x00uy; 0x00uy; 0x02uy; 0x00uy;
      0xffuy; 0xffuy; 0xfcuy; 0xffuy; 0x06uy; 0x00uy; 0x02uy; 0x00uy; 0x03uy; 0x00uy; 0xfeuy; 0xffuy;
      0xffuy; 0xffuy; 0xfduy; 0xffuy; 0xfeuy; 0xffuy; 0x02uy; 0x00uy; 0xfeuy; 0xffuy; 0x04uy; 0x00uy;
      0x04uy; 0x00uy; 0xfcuy; 0xffuy; 0xfcuy; 0xffuy; 0x02uy; 0x00uy; 0x05uy; 0x00uy; 0x01uy; 0x00uy;
      0x00uy; 0x00uy; 0x01uy; 0x00uy; 0xfauy; 0xffuy; 0x00uy; 0x00uy; 0x02uy; 0x00uy; 0x02uy; 0x00uy;
      0x01uy; 0x00uy; 0xfeuy; 0xffuy; 0x04uy; 0x00uy; 0x00uy; 0x00uy; 0x01uy; 0x00uy; 0x07uy; 0x00uy;
      0x04uy; 0x00uy; 0x03uy; 0x00uy; 0x01uy; 0x00uy; 0xffuy; 0xffuy; 0xffuy; 0xffuy; 0x01uy; 0x00uy;
      0xfeuy; 0xffuy; 0xfduy; 0xffuy; 0x04uy; 0x00uy; 0x01uy; 0x00uy; 0x03uy; 0x00uy; 0xffuy; 0xffuy;
      0x02uy; 0x00uy; 0xfcuy; 0xffuy; 0x02uy; 0x00uy; 0xfcuy; 0xffuy; 0x02uy; 0x00uy; 0xffuy; 0xffuy;
      0x02uy; 0x00uy; 0xffuy; 0xffuy; 0x00uy; 0x00uy; 0x01uy; 0x00uy; 0xfbuy; 0xffuy; 0x04uy; 0x00uy;
      0x02uy; 0x00uy; 0xfduy; 0xffuy; 0xffuy; 0xffuy; 0xffuy; 0xffuy; 0x00uy; 0x00uy; 0x01uy; 0x00uy;
      0xffuy; 0xffuy; 0xffuy; 0xffuy; 0xfeuy; 0xffuy; 0x01uy; 0x00uy; 0x01uy; 0x00uy; 0xffuy; 0xffuy;
      0x03uy; 0x00uy; 0xfcuy; 0xffuy; 0xfduy; 0xffuy; 0x01uy; 0x00uy; 0x02uy; 0x00uy; 0x03uy; 0x00uy;
      0xffuy; 0xffuy; 0x04uy; 0x00uy; 0x00uy; 0x00uy; 0x01uy; 0x00uy; 0x04uy; 0x00uy; 0x01uy; 0x00uy;
      0xfeuy; 0xffuy; 0x00uy; 0x00uy; 0xffuy; 0xffuy; 0x00uy; 0x00uy; 0xffuy; 0xffuy; 0x02uy; 0x00uy;
      0x00uy; 0x00uy; 0x04uy; 0x00uy; 0x00uy; 0x00uy; 0xffuy; 0xffuy; 0x08uy; 0x00uy; 0xfduy; 0xffuy;
      0x03uy; 0x00uy; 0xfcuy; 0xffuy; 0x02uy; 0x00uy; 0x02uy; 0x00uy; 0xffuy; 0xffuy; 0xfbuy; 0xffuy;
      0x00uy; 0x00uy; 0xfbuy; 0xffuy; 0x00uy; 0x00uy; 0xffuy; 0xffuy; 0x04uy; 0x00uy; 0x01uy; 0x00uy;
      0x03uy; 0x00uy; 0x01uy; 0x00uy; 0xfduy; 0xffuy; 0x02uy; 0x00uy; 0xfeuy; 0xffuy; 0xffuy; 0xffuy;
      0x01uy; 0x00uy; 0xfcuy; 0xffuy; 0xfeuy; 0xffuy; 0x01uy; 0x00uy; 0xfcuy; 0xffuy; 0xfauy; 0xffuy;
      0xfauy; 0xffuy; 0xfcuy; 0xffuy; 0xfbuy; 0xffuy; 0xfeuy; 0xffuy; 0xffuy; 0xffuy; 0xfduy; 0xffuy;
      0x01uy; 0x00uy; 0x05uy; 0x00uy; 0xfbuy; 0xffuy; 0xfduy; 0xffuy; 0xfcuy; 0xffuy; 0x05uy; 0x00uy;
      0xfduy; 0xffuy; 0xfbuy; 0xffuy; 0xfduy; 0xffuy; 0xfbuy; 0xffuy; 0x03uy; 0x00uy; 0x03uy; 0x00uy;
      0xfcuy; 0xffuy; 0xfduy; 0xffuy; 0x02uy; 0x00uy; 0x01uy; 0x00uy; 0x02uy; 0x00uy; 0x01uy; 0x00uy;
      0x00uy; 0x00uy; 0xfeuy; 0xffuy; 0xfeuy; 0xffuy; 0xfbuy; 0xffuy; 0xfeuy; 0xffuy; 0xfeuy; 0xffuy;
      0xfeuy; 0xffuy; 0x01uy; 0x00uy; 0x02uy; 0x00uy; 0x02uy; 0x00uy; 0xfduy; 0xffuy; 0xfeuy; 0xffuy;
      0xfeuy; 0xffuy; 0x02uy; 0x00uy; 0xfduy; 0xffuy; 0x04uy; 0x00uy; 0x00uy; 0x00uy; 0x01uy; 0x00uy;
      0x01uy; 0x00uy; 0xffuy; 0xffuy; 0x02uy; 0x00uy; 0xfeuy; 0xffuy; 0x06uy; 0x00uy; 0x04uy; 0x00uy;
      0xfauy; 0xffuy; 0xfeuy; 0xffuy; 0x00uy; 0x00uy; 0x02uy; 0x00uy; 0x05uy; 0x00uy; 0xffuy; 0xffuy;
      0x00uy; 0x00uy; 0x01uy; 0x00uy; 0xfeuy; 0xffuy; 0x04uy; 0x00uy; 0xfcuy; 0xffuy; 0xfduy; 0xffuy;
      0xfduy; 0xffuy; 0x01uy; 0x00uy; 0xfeuy; 0xffuy; 0xffuy; 0xffuy; 0x00uy; 0x00uy; 0xfduy; 0xffuy;
      0xfeuy; 0xffuy; 0x01uy; 0x00uy; 0xfeuy; 0xffuy; 0x01uy; 0x00uy; 0xfeuy; 0xffuy; 0x00uy; 0x00uy;
      0x01uy; 0x00uy; 0x00uy; 0x00uy; 0x02uy; 0x00uy; 0x01uy; 0x00uy; 0x01uy; 0x00uy; 0xfcuy; 0xffuy;
      0x03uy; 0x00uy; 0x08uy; 0x00uy; 0x00uy; 0x00uy; 0x01uy; 0x00uy; 0xffuy; 0xffuy; 0xffuy; 0xffuy;
      0xffuy; 0xffuy; 0x00uy; 0x00uy; 0x01uy; 0x00uy; 0x06uy; 0x00uy; 0xfeuy; 0xffuy; 0x02uy; 0x00uy;
      0x09uy; 0x00uy; 0xffuy; 0xffuy; 0xfeuy; 0xffuy; 0x01uy; 0x00uy; 0xfauy; 0xffuy; 0xfduy; 0xffuy;
      0x01uy; 0x00uy; 0x06uy; 0x00uy; 0x03uy; 0x00uy; 0x01uy; 0x00uy; 0x01uy; 0x00uy; 0x01uy; 0x00uy;
      0xfbuy; 0xffuy; 0xffuy; 0xffuy; 0x02uy; 0x00uy; 0xfeuy; 0xffuy; 0xffuy; 0xffuy; 0xffuy; 0xffuy;
      0xfcuy; 0xffuy; 0xfbuy; 0xffuy; 0x04uy; 0x00uy; 0xfduy; 0xffuy; 0x00uy; 0x00uy; 0x05uy; 0x00uy;
      0xfduy; 0xffuy; 0xffuy; 0xffuy; 0x00uy; 0x00uy; 0xfcuy; 0xffuy; 0xffuy; 0xffuy; 0xffuy; 0xffuy;
      0x04uy; 0x00uy; 0xfeuy; 0xffuy; 0xffuy; 0xffuy; 0xfcuy; 0xffuy; 0x00uy; 0x00uy; 0xfeuy; 0xffuy;
      0x01uy; 0x00uy; 0x01uy; 0x00uy; 0xfbuy; 0xffuy; 0xfcuy; 0xffuy; 0xfcuy; 0xffuy; 0x02uy; 0x00uy;
      0x00uy; 0x00uy; 0xfeuy; 0xffuy; 0xffuy; 0xffuy; 0x01uy; 0x00uy; 0xfduy; 0xffuy; 0x01uy; 0x00uy;
      0x02uy; 0x00uy; 0xfeuy; 0xffuy; 0xffuy; 0xffuy; 0x03uy; 0x00uy; 0x00uy; 0x00uy; 0x00uy; 0x00uy;
      0xffuy; 0xffuy; 0x00uy; 0x00uy; 0x01uy; 0x00uy; 0x01uy; 0x00uy; 0x01uy; 0x00uy; 0x01uy; 0x00uy;
      0xffuy; 0xffuy; 0x03uy; 0x00uy; 0xfeuy; 0xffuy; 0x02uy; 0x00uy; 0x03uy; 0x00uy; 0xfbuy; 0xffuy;
      0x00uy; 0x00uy; 0xfduy; 0xffuy; 0xf9uy; 0xffuy; 0x04uy; 0x00uy; 0x02uy; 0x00uy; 0x02uy; 0x00uy;
      0xfcuy; 0xffuy; 0x03uy; 0x00uy; 0xfduy; 0xffuy; 0x03uy; 0x00uy; 0x01uy; 0x00uy; 0x01uy; 0x00uy;
      0xf7uy; 0xffuy; 0xfduy; 0xffuy; 0xffuy; 0xffuy; 0x02uy; 0x00uy; 0x04uy; 0x00uy; 0x04uy; 0x00uy;
      0xfduy; 0xffuy; 0xffuy; 0xffuy; 0x00uy; 0x00uy; 0xfeuy; 0xffuy; 0x03uy; 0x00uy; 0x03uy; 0x00uy;
      0x04uy; 0x00uy; 0x05uy; 0x00uy; 0xfduy; 0xffuy; 0xfauy; 0xffuy; 0x01uy; 0x00uy; 0xf8uy; 0xffuy;
      0x01uy; 0x00uy; 0x01uy; 0x00uy; 0x00uy; 0x00uy; 0xfduy; 0xffuy; 0xfbuy; 0xffuy; 0x00uy; 0x00uy;
      0x02uy; 0x00uy; 0xfauy; 0xffuy; 0x01uy; 0x00uy; 0x00uy; 0x00uy; 0x02uy; 0x00uy; 0x03uy; 0x00uy;
      0x04uy; 0x00uy; 0xfeuy; 0xffuy; 0x01uy; 0x00uy; 0x03uy; 0x00uy; 0xffuy; 0xffuy; 0x02uy; 0x00uy;
      0xfbuy; 0xffuy; 0xffuy; 0xffuy; 0xffuy; 0xffuy; 0xfduy; 0xffuy; 0x02uy; 0x00uy; 0xfcuy; 0xffuy;
      0x01uy; 0x00uy; 0x02uy; 0x00uy; 0x00uy; 0x00uy; 0x00uy; 0x00uy; 0x03uy; 0x00uy; 0x02uy; 0x00uy;
      0x01uy; 0x00uy; 0x04uy; 0x00uy; 0xfeuy; 0xffuy; 0xfcuy; 0xffuy; 0xfcuy; 0xffuy; 0x01uy; 0x00uy;
      0xffuy; 0xffuy; 0xffuy; 0xffuy; 0x00uy; 0x00uy; 0xffuy; 0xffuy; 0xffuy; 0xffuy; 0x03uy; 0x00uy;
      0xfeuy; 0xffuy; 0xffuy; 0xffuy; 0xfduy; 0xffuy; 0xfeuy; 0xffuy; 0xfduy; 0xffuy; 0x03uy; 0x00uy;
      0xffuy; 0xffuy; 0xfeuy; 0xffuy; 0xfduy; 0xffuy; 0x01uy; 0x00uy; 0x00uy; 0x00uy; 0xffuy; 0xffuy;
      0x02uy; 0x00uy; 0xfeuy; 0xffuy; 0x05uy; 0x00uy; 0xffuy; 0xffuy; 0x02uy; 0x00uy; 0xfduy; 0xffuy;
      0xfduy; 0xffuy; 0xffuy; 0xffuy; 0x02uy; 0x00uy; 0x00uy; 0x00uy; 0xfeuy; 0xffuy; 0xffuy; 0xffuy;
      0x04uy; 0x00uy; 0x00uy; 0x00uy; 0x04uy; 0x00uy; 0x04uy; 0x00uy; 0xfeuy; 0xffuy; 0x02uy; 0x00uy;
      0xf9uy; 0xffuy; 0x02uy; 0x00uy; 0x08uy; 0x00uy; 0x00uy; 0x00uy; 0xffuy; 0xffuy; 0x00uy; 0x00uy;
      0xb6uy; 0x27uy; 0xd5uy; 0x5euy; 0x52uy; 0xfduy; 0x89uy; 0x2euy; 0x92uy; 0x59uy; 0x69uy; 0xe7uy;
      0x32uy; 0xb2uy; 0xacuy; 0x21uy
  ]



let test () : ML bool =
  [@inline_let] let a = Frodo64 in
  assert_norm (List.Tot.length test1_enccoins == 16);
  assert_norm (List.Tot.length test1_keypaircoins == 2 * crypto_bytes a + bytes_seed_a);
  assert_norm (List.Tot.length test1_enccoins == bytes_mu a);
  assert_norm (List.Tot.length test1_ss_expected == crypto_bytes a);
  assert_norm (List.Tot.length test1_pk_expected == crypto_publickeybytes a);
  assert_norm (List.Tot.length test1_ct_expected == crypto_ciphertextbytes a);
  assert_norm (List.Tot.length test1_sk_expected == crypto_secretkeybytes a);
  IO.print_string "\nTest1. SHAKE128";
  let res1 =
    test_frodo a SHAKE128 test1_keypaircoins
      test1_enccoins
      test1_ss_expected
      test1_pk_expected
      test1_ct_expected
      test1_sk_expected
  in

  let result = res1 in
  if result
  then IO.print_string "\n\nFrodoKEM : Success!\n"
  else IO.print_string "\n\nFrodoKEM: Failure :(\n";
  result