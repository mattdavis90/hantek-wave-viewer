meta:
  id: hantek
  file-extension: lwf
  endian: le
seq:
  - id: header
    type: header
  - id: data1
    type: s2
    repeat: expr
    repeat-expr: header.channel1.sample_count
  - id: data2
    type: s2
    repeat: expr
    repeat-expr: header.channel2.sample_count
  - id: data3
    type: s2
    repeat: expr
    repeat-expr: header.channel3.sample_count
  - id: data4
    type: s2
    repeat: expr
    repeat-expr: header.channel4.sample_count
  - id: footer
    type: footer
types:
  header:
    seq:
      - id: magic
        contents:
          - l
          - w
          - f
          - 0
      - id: version
        type: u4
      - type: channel  # Unused channel?
      - id: channel1
        type: channel
      - id: channel2
        type: channel
      - id: channel3
        type: channel
      - id: channel4
        type: channel
      - id: thumbnail
        type: s1
        repeat: expr
        repeat-expr: 16
  channel:
    seq:
      - type: u2
      - id: enabled
        type: u1
      - id: timebase
        type: u1
      - id: sampling_depth
        type: u4
      - id: sample_count
        type: u4
      - type: u4  # Unknown 4B
      - id: samples_per_second
        type: f8
      - id: trigger_type
        type: u4
      - id: trigger_channel
        type: u4
      - id: trigger_level
        type: s4
      - type: u4  # Unknown 4B
      - id: horizontal_offset
        type: s8
      - id: offset
        type: s4
      - id: volts_per_div
        type: u1
      - id: mode
        type: u1
      - type: u2  # Unknown 2B (sometimes 0x0032)
      - id: maybe_const
        type: u4
      - type: u4  # Unknown 4B
  footer:
    seq:
      - id: magic
        contents:
          - 0x78
          - 0x56
          - 0x34
          - 0x12
