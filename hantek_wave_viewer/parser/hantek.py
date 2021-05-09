# This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild

from pkg_resources import parse_version
import kaitaistruct
from kaitaistruct import KaitaiStruct, KaitaiStream, BytesIO


if parse_version(kaitaistruct.__version__) < parse_version('0.9'):
    raise Exception("Incompatible Kaitai Struct Python API: 0.9 or later is required, but you have %s" % (kaitaistruct.__version__))

class Hantek(KaitaiStruct):
    def __init__(self, _io, _parent=None, _root=None):
        self._io = _io
        self._parent = _parent
        self._root = _root if _root else self
        self._read()

    def _read(self):
        self.header = Hantek.Header(self._io, self, self._root)
        self.data1 = [None] * (self.header.channel1.sample_count)
        for i in range(self.header.channel1.sample_count):
            self.data1[i] = self._io.read_s2le()

        self.data2 = [None] * (self.header.channel2.sample_count)
        for i in range(self.header.channel2.sample_count):
            self.data2[i] = self._io.read_s2le()

        self.data3 = [None] * (self.header.channel3.sample_count)
        for i in range(self.header.channel3.sample_count):
            self.data3[i] = self._io.read_s2le()

        self.data4 = [None] * (self.header.channel4.sample_count)
        for i in range(self.header.channel4.sample_count):
            self.data4[i] = self._io.read_s2le()

        self.footer = Hantek.Footer(self._io, self, self._root)

    class Header(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.magic = self._io.read_bytes(4)
            if not self.magic == b"\x6C\x77\x66\x00":
                raise kaitaistruct.ValidationNotEqualError(b"\x6C\x77\x66\x00", self.magic, self._io, u"/types/header/seq/0")
            self.version = self._io.read_u4le()
            self._unnamed2 = Hantek.Channel(self._io, self, self._root)
            self.channel1 = Hantek.Channel(self._io, self, self._root)
            self.channel2 = Hantek.Channel(self._io, self, self._root)
            self.channel3 = Hantek.Channel(self._io, self, self._root)
            self.channel4 = Hantek.Channel(self._io, self, self._root)
            self.thumbnail = [None] * (16)
            for i in range(16):
                self.thumbnail[i] = self._io.read_s1()



    class Channel(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self._unnamed0 = self._io.read_u2le()
            self.enabled = self._io.read_u1()
            self.timebase = self._io.read_u1()
            self.sampling_depth = self._io.read_u4le()
            self.sample_count = self._io.read_u4le()
            self._unnamed5 = self._io.read_u4le()
            self.samples_per_second = self._io.read_f8le()
            self.trigger_type = self._io.read_u4le()
            self.trigger_channel = self._io.read_u4le()
            self.trigger_level = self._io.read_s4le()
            self._unnamed10 = self._io.read_u4le()
            self.horizontal_offset = self._io.read_s8le()
            self.offset = self._io.read_s4le()
            self.volts_per_div = self._io.read_u1()
            self.mode = self._io.read_u1()
            self._unnamed15 = self._io.read_u2le()
            self.maybe_const = self._io.read_u4le()
            self._unnamed17 = self._io.read_u4le()


    class Footer(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.magic = self._io.read_bytes(4)
            if not self.magic == b"\x78\x56\x34\x12":
                raise kaitaistruct.ValidationNotEqualError(b"\x78\x56\x34\x12", self.magic, self._io, u"/types/footer/seq/0")



