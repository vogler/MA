...
// go to unchecked states first
1           -> u_open_read  $fp = fopen(_, "r")
1           -> u_open_write $fp = fopen(_, r"[wa]") // regex, see OCaml doc for details
1           -w8> 1          $fp = fopen(_, _)

// define possible branches
u_open_read  -> 1           branch($fp==0, true)
u_open_read  -> open_read   branch($fp==0, false)
u_open_write -> 1           branch($fp==0, true)
u_open_write -> open_write  branch($fp==0, false)
...
