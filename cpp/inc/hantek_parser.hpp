#pragma once

// This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild

#include "kaitai/kaitaistruct.h"
#include <stdint.h>
#include <memory>
#include <vector>

#if KAITAI_STRUCT_VERSION < 9000L
#error "Incompatible Kaitai Struct C++/STL API: version 0.9 or later is required"
#endif

class hantek_t : public kaitai::kstruct {

public:
    class header_t;
    class channel_t;
    class footer_t;

    hantek_t(kaitai::kstream* p__io, kaitai::kstruct* p__parent = nullptr, hantek_t* p__root = nullptr);

private:
    void _read();
    void _clean_up();

public:
    ~hantek_t();

    class header_t : public kaitai::kstruct {

    public:

        header_t(kaitai::kstream* p__io, hantek_t* p__parent = nullptr, hantek_t* p__root = nullptr);

    private:
        void _read();
        void _clean_up();

    public:
        ~header_t();

    private:
        std::string m_magic;
        uint32_t m_version;
        std::unique_ptr<channel_t> m__unnamed2;
        std::unique_ptr<channel_t> m_channel1;
        std::unique_ptr<channel_t> m_channel2;
        std::unique_ptr<channel_t> m_channel3;
        std::unique_ptr<channel_t> m_channel4;
        std::unique_ptr<std::vector<int8_t>> m_thumbnail;
        hantek_t* m__root;
        hantek_t* m__parent;

    public:
        std::string magic() const { return m_magic; }
        uint32_t version() const { return m_version; }
        channel_t* _unnamed2() const { return m__unnamed2.get(); }
        channel_t* channel1() const { return m_channel1.get(); }
        channel_t* channel2() const { return m_channel2.get(); }
        channel_t* channel3() const { return m_channel3.get(); }
        channel_t* channel4() const { return m_channel4.get(); }
        std::vector<int8_t>* thumbnail() const { return m_thumbnail.get(); }
        hantek_t* _root() const { return m__root; }
        hantek_t* _parent() const { return m__parent; }
    };

    class channel_t : public kaitai::kstruct {

    public:

        channel_t(kaitai::kstream* p__io, hantek_t::header_t* p__parent = nullptr, hantek_t* p__root = nullptr);

    private:
        void _read();
        void _clean_up();

    public:
        ~channel_t();

    private:
        uint16_t m_acquisition_mode;
        uint8_t m_enabled;
        uint8_t m_timebase;
        uint32_t m_sampling_depth;
        uint32_t m_sample_count;
        uint32_t m__unnamed5;
        double m_samples_per_second;
        uint32_t m_trigger_type;
        uint32_t m_trigger_channel;
        int32_t m_trigger_level;
        uint32_t m__unnamed10;
        int64_t m_horizontal_offset;
        int32_t m_offset;
        uint8_t m_volts_per_div;
        uint8_t m_mode;
        uint16_t m__unnamed15;
        uint32_t m_maybe_const;
        uint32_t m__unnamed17;
        hantek_t* m__root;
        hantek_t::header_t* m__parent;

    public:
        uint16_t acquisition_mode() const { return m_acquisition_mode; }
        uint8_t enabled() const { return m_enabled; }
        uint8_t timebase() const { return m_timebase; }
        uint32_t sampling_depth() const { return m_sampling_depth; }
        uint32_t sample_count() const { return m_sample_count; }
        uint32_t _unnamed5() const { return m__unnamed5; }
        double samples_per_second() const { return m_samples_per_second; }
        uint32_t trigger_type() const { return m_trigger_type; }
        uint32_t trigger_channel() const { return m_trigger_channel; }
        int32_t trigger_level() const { return m_trigger_level; }
        uint32_t _unnamed10() const { return m__unnamed10; }
        int64_t horizontal_offset() const { return m_horizontal_offset; }
        int32_t offset() const { return m_offset; }
        uint8_t volts_per_div() const { return m_volts_per_div; }
        uint8_t mode() const { return m_mode; }
        uint16_t _unnamed15() const { return m__unnamed15; }
        uint32_t maybe_const() const { return m_maybe_const; }
        uint32_t _unnamed17() const { return m__unnamed17; }
        hantek_t* _root() const { return m__root; }
        hantek_t::header_t* _parent() const { return m__parent; }
    };

    class footer_t : public kaitai::kstruct {

    public:

        footer_t(kaitai::kstream* p__io, hantek_t* p__parent = nullptr, hantek_t* p__root = nullptr);

    private:
        void _read();
        void _clean_up();

    public:
        ~footer_t();

    private:
        std::string m_magic;
        hantek_t* m__root;
        hantek_t* m__parent;

    public:
        std::string magic() const { return m_magic; }
        hantek_t* _root() const { return m__root; }
        hantek_t* _parent() const { return m__parent; }
    };

private:
    std::unique_ptr<header_t> m_header;
    std::unique_ptr<std::vector<int16_t>> m_data1;
    std::unique_ptr<std::vector<int16_t>> m_data2;
    std::unique_ptr<std::vector<int16_t>> m_data3;
    std::unique_ptr<std::vector<int16_t>> m_data4;
    std::unique_ptr<footer_t> m_footer;
    hantek_t* m__root;
    kaitai::kstruct* m__parent;

public:
    header_t* header() const { return m_header.get(); }
    std::vector<int16_t>* data1() const { return m_data1.get(); }
    std::vector<int16_t>* data2() const { return m_data2.get(); }
    std::vector<int16_t>* data3() const { return m_data3.get(); }
    std::vector<int16_t>* data4() const { return m_data4.get(); }
    footer_t* footer() const { return m_footer.get(); }
    hantek_t* _root() const { return m__root; }
    kaitai::kstruct* _parent() const { return m__parent; }
};
