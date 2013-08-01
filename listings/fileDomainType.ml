type loc = location list
type mode = Read | Write
type state = Open of string*mode | Close
type record = { var: varinfo; loc: loc; state: state }
type t = Must of record | May of record Set.t