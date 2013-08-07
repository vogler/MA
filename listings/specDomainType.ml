type state = string
type record = {var: Lval.CilLval.t; loc: location list; state: state}
type t = record Set.t * record Set.t (* must, may *)
