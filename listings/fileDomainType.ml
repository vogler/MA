type loc = location list
type mode = Read | Write
type state = Open of string*mode | Closed | Error
type record = { var: varinfo; loc: loc; state: state }
type t = record Set.t * record Set.t (* must, may *)
