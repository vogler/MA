// warnings
w1  "file handle is not saved"
w2  "closeing unopened file handle"

// edges
a   -w1>    a   fopen(_)
a   -w2>    a   fclose($fp)
a   ->      b   $fp = fopen(_)
...
