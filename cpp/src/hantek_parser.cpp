// This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler
// to rebuild

#include "hantek_parser.hpp"
#include "kaitai/exceptions.h"

hantek_t::hantek_t(
    kaitai::kstream* p__io, kaitai::kstruct* p__parent, hantek_t* p__root)
    : kaitai::kstruct(p__io)
{
    m__parent = p__parent;
    m__root   = this;
    m_header  = nullptr;
    m_data1   = nullptr;
    m_data2   = nullptr;
    m_data3   = nullptr;
    m_data4   = nullptr;
    m_footer  = nullptr;
    _read();
}

void hantek_t::_read()
{
    m_header = std::unique_ptr<header_t>(new header_t(m__io, this, m__root));
    m_data1  = std::unique_ptr<std::vector<int16_t>>(new std::vector<int16_t>());
    const int l_data1 = header()->channel1()->sample_count();
    for (int i = 0; i < l_data1; i++) {
        m_data1->push_back(std::move(m__io->read_s2le()));
    }
    m_data2 = std::unique_ptr<std::vector<int16_t>>(new std::vector<int16_t>());
    const int l_data2 = header()->channel2()->sample_count();
    for (int i = 0; i < l_data2; i++) {
        m_data2->push_back(std::move(m__io->read_s2le()));
    }
    m_data3 = std::unique_ptr<std::vector<int16_t>>(new std::vector<int16_t>());
    const int l_data3 = header()->channel3()->sample_count();
    for (int i = 0; i < l_data3; i++) {
        m_data3->push_back(std::move(m__io->read_s2le()));
    }
    m_data4 = std::unique_ptr<std::vector<int16_t>>(new std::vector<int16_t>());
    const int l_data4 = header()->channel4()->sample_count();
    for (int i = 0; i < l_data4; i++) {
        m_data4->push_back(std::move(m__io->read_s2le()));
    }
    m_footer = std::unique_ptr<footer_t>(new footer_t(m__io, this, m__root));
}

hantek_t::~hantek_t() { _clean_up(); }

void hantek_t::_clean_up() { }

hantek_t::header_t::header_t(
    kaitai::kstream* p__io, hantek_t* p__parent, hantek_t* p__root)
    : kaitai::kstruct(p__io)
{
    m__parent   = p__parent;
    m__root     = p__root;
    m__unnamed2 = nullptr;
    m_channel1  = nullptr;
    m_channel2  = nullptr;
    m_channel3  = nullptr;
    m_channel4  = nullptr;
    m_thumbnail = nullptr;
    _read();
}

void hantek_t::header_t::_read()
{
    m_magic = m__io->read_bytes(4);
    if (!(magic() == std::string("\x6C\x77\x66\x00", 4))) {
        throw kaitai::validation_not_equal_error<std::string>(
            std::string("\x6C\x77\x66\x00", 4), magic(), _io(),
            std::string("/types/header/seq/0"));
    }
    m_version   = m__io->read_u4le();
    m__unnamed2 = std::unique_ptr<channel_t>(new channel_t(m__io, this, m__root));
    m_channel1  = std::unique_ptr<channel_t>(new channel_t(m__io, this, m__root));
    m_channel2  = std::unique_ptr<channel_t>(new channel_t(m__io, this, m__root));
    m_channel3  = std::unique_ptr<channel_t>(new channel_t(m__io, this, m__root));
    m_channel4  = std::unique_ptr<channel_t>(new channel_t(m__io, this, m__root));
    m_thumbnail = std::unique_ptr<std::vector<int8_t>>(new std::vector<int8_t>());
    const int l_thumbnail = 16;
    for (int i = 0; i < l_thumbnail; i++) {
        m_thumbnail->push_back(std::move(m__io->read_s1()));
    }
}

hantek_t::header_t::~header_t() { _clean_up(); }

void hantek_t::header_t::_clean_up() { }

hantek_t::channel_t::channel_t(
    kaitai::kstream* p__io, hantek_t::header_t* p__parent, hantek_t* p__root)
    : kaitai::kstruct(p__io)
{
    m__parent = p__parent;
    m__root   = p__root;
    _read();
}

void hantek_t::channel_t::_read()
{
    m_acquisition_mode   = m__io->read_u2le();
    m_enabled            = m__io->read_u1();
    m_timebase           = m__io->read_u1();
    m_sampling_depth     = m__io->read_u4le();
    m_sample_count       = m__io->read_u4le();
    m__unnamed5          = m__io->read_u4le();
    m_samples_per_second = m__io->read_f8le();
    m_trigger_type       = m__io->read_u4le();
    m_trigger_channel    = m__io->read_u4le();
    m_trigger_level      = m__io->read_s4le();
    m__unnamed10         = m__io->read_u4le();
    m_horizontal_offset  = m__io->read_s8le();
    m_offset             = m__io->read_s4le();
    m_volts_per_div      = m__io->read_u1();
    m_mode               = m__io->read_u1();
    m__unnamed15         = m__io->read_u2le();
    m_maybe_const        = m__io->read_u4le();
    m__unnamed17         = m__io->read_u4le();
}

hantek_t::channel_t::~channel_t() { _clean_up(); }

void hantek_t::channel_t::_clean_up() { }

hantek_t::footer_t::footer_t(
    kaitai::kstream* p__io, hantek_t* p__parent, hantek_t* p__root)
    : kaitai::kstruct(p__io)
{
    m__parent = p__parent;
    m__root   = p__root;
    _read();
}

void hantek_t::footer_t::_read()
{
    m_magic = m__io->read_bytes(4);
    if (!(magic() == std::string("\x78\x56\x34\x12", 4))) {
        throw kaitai::validation_not_equal_error<std::string>(
            std::string("\x78\x56\x34\x12", 4), magic(), _io(),
            std::string("/types/footer/seq/0"));
    }
}

hantek_t::footer_t::~footer_t() { _clean_up(); }

void hantek_t::footer_t::_clean_up() { }
