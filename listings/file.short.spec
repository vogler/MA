...
// go to unchecked states first
1          -> u_open_read  $fp = fopen($path, "r")
1          -> u_open_write $fp = fopen($path, r"[wa]") // regex, see OCaml doc for details
1          -> w8           $fp = fopen($path, _)

// define possible branches
u_open_read  -> 1           branch($key==0, true)
u_open_read  -> open_read   branch($key==0, false)
u_open_write -> 1           branch($key==0, true)
u_open_write -> open_write  branch($key==0, false)
...
