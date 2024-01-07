// This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild

use std::option::Option;
use std::boxed::Box;
use std::io::Result;
use std::io::Cursor;
use std::vec::Vec;
use std::default::Default;
use kaitai_struct::KaitaiStream;
use kaitai_struct::KaitaiStruct;

#[derive(Default)]
pub struct Hantek {
    pub header: Box<Hantek__Header>,
    pub data1: Vec<i16>,
    pub data2: Vec<i16>,
    pub data3: Vec<i16>,
    pub data4: Vec<i16>,
    pub footer: Box<Hantek__Footer>,
}

impl KaitaiStruct for Hantek {
    fn new<S: KaitaiStream>(stream: &mut S,
                            _parent: &Option<Box<KaitaiStruct>>,
                            _root: &Option<Box<KaitaiStruct>>)
                            -> Result<Self>
        where Self: Sized {
        let mut s: Self = Default::default();

        s.stream = stream;
        s.read(stream, _parent, _root)?;

        Ok(s)
    }


    fn read<S: KaitaiStream>(&mut self,
                             stream: &mut S,
                             _parent: &Option<Box<KaitaiStruct>>,
                             _root: &Option<Box<KaitaiStruct>>)
                             -> Result<()>
        where Self: Sized {
        self.header = Box::new(Hantek__Header::new(self.stream, self, _root)?);
        self.data1 = vec!();
        for i in 0..self.header.channel1.sample_count {
            self.data1.append(self.stream.read_s2le()?);
        }
        self.data2 = vec!();
        for i in 0..self.header.channel2.sample_count {
            self.data2.append(self.stream.read_s2le()?);
        }
        self.data3 = vec!();
        for i in 0..self.header.channel3.sample_count {
            self.data3.append(self.stream.read_s2le()?);
        }
        self.data4 = vec!();
        for i in 0..self.header.channel4.sample_count {
            self.data4.append(self.stream.read_s2le()?);
        }
        self.footer = Box::new(Hantek__Footer::new(self.stream, self, _root)?);
    }
}

impl Hantek {
}
#[derive(Default)]
pub struct Hantek__Header {
    pub magic: Vec<u8>,
    pub version: u32,
    pub _unnamed2: Box<Hantek__Channel>,
    pub channel1: Box<Hantek__Channel>,
    pub channel2: Box<Hantek__Channel>,
    pub channel3: Box<Hantek__Channel>,
    pub channel4: Box<Hantek__Channel>,
    pub thumbnail: Vec<i8>,
}

impl KaitaiStruct for Hantek__Header {
    fn new<S: KaitaiStream>(stream: &mut S,
                            _parent: &Option<Box<KaitaiStruct>>,
                            _root: &Option<Box<KaitaiStruct>>)
                            -> Result<Self>
        where Self: Sized {
        let mut s: Self = Default::default();

        s.stream = stream;
        s.read(stream, _parent, _root)?;

        Ok(s)
    }


    fn read<S: KaitaiStream>(&mut self,
                             stream: &mut S,
                             _parent: &Option<Box<KaitaiStruct>>,
                             _root: &Option<Box<KaitaiStruct>>)
                             -> Result<()>
        where Self: Sized {
        self.magic = self.stream.read_bytes(4)?;
        self.version = self.stream.read_u4le()?;
        self._unnamed2 = Box::new(Hantek__Channel::new(self.stream, self, _root)?);
        self.channel1 = Box::new(Hantek__Channel::new(self.stream, self, _root)?);
        self.channel2 = Box::new(Hantek__Channel::new(self.stream, self, _root)?);
        self.channel3 = Box::new(Hantek__Channel::new(self.stream, self, _root)?);
        self.channel4 = Box::new(Hantek__Channel::new(self.stream, self, _root)?);
        self.thumbnail = vec!();
        for i in 0..16 {
            self.thumbnail.append(self.stream.read_s1()?);
        }
    }
}

impl Hantek__Header {
}
#[derive(Default)]
pub struct Hantek__Channel {
    pub acquisitionMode: u16,
    pub enabled: u8,
    pub timebase: u8,
    pub samplingDepth: u32,
    pub sampleCount: u32,
    pub _unnamed5: u32,
    pub samplesPerSecond: f64,
    pub triggerType: u32,
    pub triggerChannel: u32,
    pub triggerLevel: i32,
    pub _unnamed10: u32,
    pub horizontalOffset: i64,
    pub offset: i32,
    pub voltsPerDiv: u8,
    pub mode: u8,
    pub _unnamed15: u16,
    pub maybeConst: u32,
    pub _unnamed17: u32,
}

impl KaitaiStruct for Hantek__Channel {
    fn new<S: KaitaiStream>(stream: &mut S,
                            _parent: &Option<Box<KaitaiStruct>>,
                            _root: &Option<Box<KaitaiStruct>>)
                            -> Result<Self>
        where Self: Sized {
        let mut s: Self = Default::default();

        s.stream = stream;
        s.read(stream, _parent, _root)?;

        Ok(s)
    }


    fn read<S: KaitaiStream>(&mut self,
                             stream: &mut S,
                             _parent: &Option<Box<KaitaiStruct>>,
                             _root: &Option<Box<KaitaiStruct>>)
                             -> Result<()>
        where Self: Sized {
        self.acquisitionMode = self.stream.read_u2le()?;
        self.enabled = self.stream.read_u1()?;
        self.timebase = self.stream.read_u1()?;
        self.samplingDepth = self.stream.read_u4le()?;
        self.sampleCount = self.stream.read_u4le()?;
        self._unnamed5 = self.stream.read_u4le()?;
        self.samplesPerSecond = self.stream.read_f8le()?;
        self.triggerType = self.stream.read_u4le()?;
        self.triggerChannel = self.stream.read_u4le()?;
        self.triggerLevel = self.stream.read_s4le()?;
        self._unnamed10 = self.stream.read_u4le()?;
        self.horizontalOffset = self.stream.read_s8le()?;
        self.offset = self.stream.read_s4le()?;
        self.voltsPerDiv = self.stream.read_u1()?;
        self.mode = self.stream.read_u1()?;
        self._unnamed15 = self.stream.read_u2le()?;
        self.maybeConst = self.stream.read_u4le()?;
        self._unnamed17 = self.stream.read_u4le()?;
    }
}

impl Hantek__Channel {
}
#[derive(Default)]
pub struct Hantek__Footer {
    pub magic: Vec<u8>,
}

impl KaitaiStruct for Hantek__Footer {
    fn new<S: KaitaiStream>(stream: &mut S,
                            _parent: &Option<Box<KaitaiStruct>>,
                            _root: &Option<Box<KaitaiStruct>>)
                            -> Result<Self>
        where Self: Sized {
        let mut s: Self = Default::default();

        s.stream = stream;
        s.read(stream, _parent, _root)?;

        Ok(s)
    }


    fn read<S: KaitaiStream>(&mut self,
                             stream: &mut S,
                             _parent: &Option<Box<KaitaiStruct>>,
                             _root: &Option<Box<KaitaiStruct>>)
                             -> Result<()>
        where Self: Sized {
        self.magic = self.stream.read_bytes(4)?;
    }
}

impl Hantek__Footer {
}
