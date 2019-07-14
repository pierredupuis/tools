## bash

### vl

Automates volatility tasks by removing the need to specify profile and memory dump file each time. It can also produce a summary by running a selection of plugins and outputing the results in corresponding files.

```bash
# Initialize case in current directory
vl

# Create a summary
vl -s

# Run a specific plugin
vl [-t] <plugin> <options>
```

For further details, run `vl -h`

---

### ctx

Uses dd to output 200 preceeding and following bytes from an offset of a file.
This value can be modified. It is also possible to specify different values for the number of bytes to output before and after the offset.

```bash
ctx <file> <offset>
ctx <file> <offset> -C <nb>
ctx <file> <offset> -A <nb_after> -B <nb_before>
```
For further details, run `ctx -h`

---

### set-wifi

Sets up WiFi connection and VPN (optional).

```bash
set-wifi <SSID>
set-wifi <SSID> -p <ovpn_file>i
```

For further details, run `set-wifi -h`