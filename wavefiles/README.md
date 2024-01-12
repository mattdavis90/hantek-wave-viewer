# Wavefile Samples

To determine the header structure I made some sample captures on a DSO2C10 and observed differences in the header using the [Kaitai Web IDE](https://ide.kaitai.io).

From this it can be seen that there is a consistent 348 Bytes header. Further inspection of the larger files shows that it is actually 344 Bytes header with a 4 Byte footer (constant 0x78563412 - which implies the file is little-endian). Also of note is that the scope was set to 4000 samples and the file grows by 8000 Bytes per channel, indicating `16-bit signed integer` as the data type.

I used [Kaitai Struct](https://kaitai.io) to analyse the files and mark the various bytes in the header that aligned to the parameters that I had changes. The `ksy` file is available in the [repo](https://github.com/mattdavis90/hantek-wave-viewer/blob/master/hantek_wave_viewer/kaitai/hantek.ksy). From this file Kaitai generates Python and C++ bindings.

### Included Sample Files

filename | Ch1 VpD, offset | Ch2 VpD, Offset |  Timebase  | Trigger | Comments                 | filesize
---------|-----------------|-----------------|------------|---------|--------------------------|----------
 26_0    |      Off, 1V,0V |       Off,1V,0V |   2m,   0  |  Ch1,0V |                          |    348
 26_1    |      Off, 1V,0V |       Off,1V,0V |   1m,   0  |  Ch1,0V |                          |    348
 26_2    |      Off, 1V,0V |       Off,1V,0V | 500u,   0  |  Ch1,0V |                          |    348
 26_3    |      Off, 1V,0V |       Off,1V,0V | 200u,   0  |  Ch1,0V |                          |    348
 26_4    |      Off, 1V,0V |       Off,1V,0V | 100u,   0  |  Ch1,0V |                          |    348
 26_5    |       On, 1V,0V |       Off,1V,0V | 200u,   0  |  Ch1,0V |                          |   8348
 26_6    |       On, 2V,0V |       Off,1V,0V | 200u,   0  |  Ch1,0V |                          |   8348
 26_7    |       On, 5V,0V |       Off,1V,0V | 200u,   0  |  Ch1,0V |                          |   8348
 26_8    |       On,10V,0V |       Off,1V,0V | 200u,   0  |  Ch1,0V |                          |   8348
 26_9    |       On, 2V,2V |       Off,1V,0V | 200u,   0  |  Ch1,0V |                          |   8348
26_10    |       On, 2V,4V |       Off,1V,0V | 200u,   0  |  Ch1,0V |                          |   8348
26_11    |       On, 2V,6V |       Off,1V,0V | 200u,   0  |  Ch1,0V |                          |   8348
26_12    |       On, 2V,0V |       Off,1V,0V | 200u,   0  |  Ch1,0V | 5V:1KHz Square on Ch1    |   8348
26_13    |       On, 2V,0V |       Off,1V,0V | 200u,   0  |  Ch1,2V | 5V:1KHz Square on Ch1    |   8348
26_14    |      Off, 2V,0V |        On,2V,0V | 200u,   0  |  Ch1,0V | 5V:1KHz Square on Ch2    |   8348
26_15    |      Off, 2V,0V |        On,2V,0V | 200u,   0  |  Ch2,2V | 5V:1KHz Square on Ch2    |   8348
26_16    |      Off, 2V,0V |        On,5V,0V | 200u,   0  |  Ch2,2V | 5V:1KHz Square on Ch2    |   8348
26_17    |      Off, 2V,0V |        On,2V,2V | 200u,   0  |  Ch2,2V | 5V:1KHz Square on Ch2    |   8348
26_18    |       On, 2V,0V |        On,2V,0V | 200u,   0  |  Ch1,2V | 5V:1KHz Square on Ch1    |  16348
26_19    |       On, 2V,0V |        On,2V,0V | 200u,   0  |  Ch2,2V | 5V:1KHz Square on Ch2    |  16348
29_0     |       On, 2V,0V |       Off,2V,0V | 200u,   0  |  Ch1,2V |                          |   8348
29_1     |       On, 2V,0V |       Off,2V,0V | 200u,-200u |  Ch1,2V |                          |   8348
29_2     |       On, 2V,0V |       Off,2V,0V | 200u,-400u |  Ch1,2V |                          |   8348
29_3     |       On, 2V,0V |       Off,2V,0V | 200u, 200u |  Ch1,2V |                          |   8348
30_1     |       On, 2V,0V |       Off,2V,0V |   1u,   0  |  Ch1,2V |                          |   8348
30_2     |       On, 2V,0V |       Off,2V,0V | 200u,   0  |  Ch1,2V | Gnd Coupling - No change |   8348
30_3     |       On, 2V,0V |       Off,2V,0V | 200u,   0  |  Ch1,2V | AC coupling - No change  |   8348
30_4     |       On, 2V,0V |       Off,2V,0V | 200u,   0  |  Ch1,2V | Pulse trigger            |   8348
30_5     |       On, 2V,0V |       Off,2V,0V | 200u,   0  |  Ch1,2V | Falling edge - No change |   8348
30_6     |       On, 2V,0V |       Off,2V,0V | 200u,   0  |  Ch1,2V | Either edge - No change  |   8348
30_7     |       On, 2V,0V |       Off,2V,0V | 200u,   0  |  Ch1,2V | Normal mode - No change  |   8348
30_8     |       On, 2V,0V |       Off,2V,0V | 200u,   0  |  Ch1,2V | 16ns holdoff - No change |   8348
