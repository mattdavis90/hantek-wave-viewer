from decimal import Decimal

import click

from . import conversions
from .hantek import Hantek

_large_units = ["", "K", "M", "G", "T", "P"]
_small_units = ["", "m", "u", "n", "p", "f"]


def format_large(v, units=""):
    d = Decimal(v)

    if d == 0:
        return f"0{units}"

    sign = ""
    if d < 0:
        d *= -1
        sign = "-"

    i = 0
    while d >= 1000 and i < len(_large_units) - 1:
        d /= 1000
        i += 1
    return f"{sign}{d}{_large_units[i]}{units}"


def format_small(v, units=""):
    d = Decimal(v)

    if d == 0:
        return f"0{units}"

    sign = ""
    if d < 0:
        d *= -1
        sign = "-"

    i = 0
    while d < 1 and i < len(_small_units) - 1:
        d *= 1000
        i += 1
    d = d.to_integral_value()
    return f"{sign}{d}{_small_units[i]}{units}"


def format_number(v, units=""):
    if abs(Decimal(v)) > 1:
        return format_large(v, units)
    return format_small(v, units)


def print_channel(n: int, channel: Hantek.Channel):
    click.secho(f"Channel {n}", fg="magenta")
    if channel.enabled:
        timebase = conversions.TIMEBASE[channel.timebase]
        volts_per_div = conversions.VOLTS_PER_DIV[channel.volts_per_div]
        volts_per_div_str = format_number(volts_per_div * (10**channel.mode), "V")

        click.echo(f"\tTimebase: {format_number(timebase, 's')} [{channel.timebase}]")
        click.echo(f"\tSampling Depth: {channel.sampling_depth}")
        click.echo(f"\tSample Count: {channel.sample_count}")
        click.echo(f"\tSamples per Second: {channel.samples_per_second}")
        click.echo(
            f"\tTrigger Type: {conversions.TRIGGER_NAME[channel.trigger_type]}"
            f" [{channel.trigger_type}]"
        )
        click.echo(f"\tTrigger Channel: {channel.trigger_channel}")
        click.echo(f"\tTrigger Level: {channel.trigger_level}")
        click.echo(f"\tHorizontal Offset: {channel.horizontal_offset}")
        click.echo(f"\tOffset: {channel.offset}")
        click.echo(
            f"\tVots per Division: {volts_per_div_str} [{channel.volts_per_div}]"
        )
        click.echo(f"\tProbe Mode: {10 ** channel.mode}x [{channel.mode}]")
        click.echo(f"\tMaybe Const: {channel.maybe_const}")

        click.echo(
            "\tAcquisition Mode:"
            f" {conversions.ACQUISITION_MODE[channel.acquisition_mode]}"
            f" [{channel.acquisition_mode}]"
        )
        click.echo(f"\tUnamed5: {channel._unnamed5}")
        click.echo(f"\tTrigger Unknown: {channel._unnamed10}")
        click.echo(f"\tUnamed15: {channel._unnamed15}")
        click.echo(f"\tUnamed17: {channel._unnamed17}")
    else:
        click.echo("\tDisabled")
