open Ctypes
module Bindings(F:Cstubs.FOREIGN) =
  struct
    open F
    let hacl_AES_128_NI_aes128_ctr_encrypt =
      foreign "Hacl_AES_128_NI_aes128_ctr_encrypt"
        (uint32_t @->
           (ocaml_bytes @->
              (ocaml_bytes @->
                 (ocaml_bytes @->
                    (ocaml_bytes @-> (uint32_t @-> (returning void)))))))
    let hacl_AES_128_NI_aes128_ctr_decrypt =
      foreign "Hacl_AES_128_NI_aes128_ctr_decrypt"
        (uint32_t @->
           (ocaml_bytes @->
              (ocaml_bytes @->
                 (ocaml_bytes @->
                    (ocaml_bytes @-> (uint32_t @-> (returning void)))))))
  end