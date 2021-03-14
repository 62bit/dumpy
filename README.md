# dumpy
pepegalized implementation of hexdump

# Quick Start
Initialize environment variables: <br/>
`$ vcvarsall.bat x64` <br/>
Build: <br/>
`$ .\build.bat`

# Example Usage

`$ dumpy` <br/>
```
$ dumpy [bytes per line ([1-99] default 16)] [file path]

Example:
dumpy a.png
dumpy 8 ./pass.txt
```

`$ dumpy lol.txt` <br/>
```
00000  25  24  21  7E  5E  60  23  54  45  53  54  0D  0A  64  73  61 |%$!~^`#TEST..dsa|
00010  52  52  52  0D  0A  4C  6F  72  65  6D  20  49  70  73  75  6D |RRR..Lorem.Ipsum|
00020  20  69  73  20  73  69  6D  70  6C  79  20  64  75  6D  6D  79 |.is.simply.dummy|
00030  20  74  65  78  74  20  6F  66  20  74  68  65  20  70  72  69 |.text.of.the.pri|
00040  6E  74  69  6E  67  20  61  6E  64  20  74  79  70  65  73  65 |nting.and.typese|
00050  74  74  69  6E  67  20  69  6E  64  75  73  74  72  79  2E  0D |tting.industry..|
00060  0A  4C  6F  72  65  6D  20  49  70  73  75  6D  20  68  61  73 |.Lorem.Ipsum.has|
00070  20  62  65  65  2A  2A  6E  20  74  68  65  20  69  6E  64  75 |.bee**n.the.indu|
00080  73  74  72  79  27  73  20  73  74  61  6E  64  61  72  64  20 |stry's.standard.|
00090  64  75  6D  6D  79  20  74  65  78  74  20  65  76  65  72  20 |dummy.text.ever.|
000a0  73  69  6E  63  65  20  74  68  65  20  31  35  30  30  73  2C |since.the.1500s,|
000b0  20  77  68  65  6E  20  61  6E  0D  0A  75  6E  6B  6E  6F  32 |.when.an..unkno2|
000c0  33  31  31  77  6E  20  70  72  69  6E  74  65  72  20  74  6F |311wn.printer.to|
000d0  6F  6B  20  61  20  67  61  6C  6C  65  79  20  6F  66  20  74 |ok.a.galley.of.t|
000e0  79  70  65  20  61  6E  64  20  73  63  72  61  6D  62  6C  65 |ype.and.scramble|
000f0  64  20  69  74  20  74  6F  20  6D  61  6B  65  20  61  20  74 |d.it.to.make.a.t|
00100  79  70  65  20  73  70  65  63  69  6D  65  6E  20  62  6F  6F |ype.specimen.boo|
00110  6B  2E  0D  0A |k...|
```

`$ dumpy 8 lol.txt` <br/>
```
00000  25  24  21  7E  5E  60  23  54 |%$!~^`#T|
00008  45  53  54  0D  0A  64  73  61 |EST..dsa|
00010  52  52  52  0D  0A  4C  6F  72 |RRR..Lor|
00018  65  6D  20  49  70  73  75  6D |em.Ipsum|
00020  20  69  73  20  73  69  6D  70 |.is.simp|
00028  6C  79  20  64  75  6D  6D  79 |ly.dummy|
00030  20  74  65  78  74  20  6F  66 |.text.of|
00038  20  74  68  65  20  70  72  69 |.the.pri|
00040  6E  74  69  6E  67  20  61  6E |nting.an|
00048  64  20  74  79  70  65  73  65 |d.typese|
00050  74  74  69  6E  67  20  69  6E |tting.in|
00058  64  75  73  74  72  79  2E  0D |dustry..|
00060  0A  4C  6F  72  65  6D  20  49 |.Lorem.I|
00068  70  73  75  6D  20  68  61  73 |psum.has|
00070  20  62  65  65  2A  2A  6E  20 |.bee**n.|
00078  74  68  65  20  69  6E  64  75 |the.indu|
00080  73  74  72  79  27  73  20  73 |stry's.s|
00088  74  61  6E  64  61  72  64  20 |tandard.|
00090  64  75  6D  6D  79  20  74  65 |dummy.te|
00098  78  74  20  65  76  65  72  20 |xt.ever.|
000a0  73  69  6E  63  65  20  74  68 |since.th|
000a8  65  20  31  35  30  30  73  2C |e.1500s,|
000b0  20  77  68  65  6E  20  61  6E |.when.an|
000b8  0D  0A  75  6E  6B  6E  6F  32 |..unkno2|
000c0  33  31  31  77  6E  20  70  72 |311wn.pr|
000c8  69  6E  74  65  72  20  74  6F |inter.to|
000d0  6F  6B  20  61  20  67  61  6C |ok.a.gal|
000d8  6C  65  79  20  6F  66  20  74 |ley.of.t|
000e0  79  70  65  20  61  6E  64  20 |ype.and.|
000e8  73  63  72  61  6D  62  6C  65 |scramble|
000f0  64  20  69  74  20  74  6F  20 |d.it.to.|
000f8  6D  61  6B  65  20  61  20  74 |make.a.t|
00100  79  70  65  20  73  70  65  63 |ype.spec|
00108  69  6D  65  6E  20  62  6F  6F |imen.boo|
00110  6B  2E  0D  0A |k...|
```