w1 "file handle is not saved!"
w2 "closeing unopened file handle $"
w3 "writing to unopened file handle $"
w4 "writing to read-only file handle $"
w5 "closeing already closed file handle $"
w6 "writing to closed file handle $"
w7 "overwriting still opened file handle $"
w8 "unrecognized file open mode for file handle $"

1          -> w1            fopen(_)
1          -> w2            fclose($fp)
1          -> w3            fprintf($fp, _)
1          -> open_read     $fp = fopen($path, "r")
1          -> open_write    $fp = fopen($path, r"[wa]") // see OCaml doc for details (e.g. \\| for alternatives)
1          -> w8            $fp = fopen($path, _)

open_read  -> w4            fprintf($fp, _)

open_read  -w7>> 1          $fp = fopen($path, _)
open_write -w7>> 1          $fp = fopen($path, _)

open_read  -> closed        fclose($fp)
open_write -> closed        fclose($fp)

closed     -> w5            fclose($fp)
closed     -> w6            fprintf($fp, _)
closed     ->> 1            _ // let state 1 handle the rest

// setup which states are end states
1          -> end           _
closed     -> end           _
// warning for all entries that are not in an end state
_end "file is never closed"
_END "unclosed files: $"