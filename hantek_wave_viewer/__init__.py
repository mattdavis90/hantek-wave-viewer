import click
import matplotlib.pyplot as plt
import matplotlib.transforms as transforms
import numpy as np
from kaitaistruct import KaitaiStructError
from matplotlib.ticker import MultipleLocator, NullFormatter

from .parser.hantek import Hantek
from .parser import conversions, utils


@click.argument("filename", type=click.Path(exists=True, file_okay=True, dir_okay=False, readable=True))
@click.command()
def main(filename):
    try:
        wave = Hantek.from_file(filename)
    except KaitaiStructError as exc:
        raise click.ClickException(str(exc))

    # Build the data array for each channel
    data1 = np.array(wave.data1)
    data2 = np.array(wave.data2)
    data3 = np.array(wave.data3)
    data4 = np.array(wave.data4)

    # Time axis we just use channel 1 because the info. is the same for every channel
    timebase = conversions.TIMEBASE[wave.header.channel1.timebase]
    timebase_str = utils.format_number(timebase, "s")
    seconds_per_sample = 1 / wave.header.channel1.samples_per_second
    time = np.arange(0, wave.header.channel1.sampling_depth * seconds_per_sample, seconds_per_sample)

    # Darkmode to simulate oscilloscope
    plt.style.use('dark_background')
    fig, ax = plt.subplots()

    # Setup the graph like an oscilloscope graticule
    ax.set_ylim(-100, 100)
    ax.xaxis.set_major_locator(MultipleLocator(timebase))
    ax.xaxis.set_major_formatter(NullFormatter())
    ax.xaxis.set_minor_locator(MultipleLocator(timebase / 5))
    ax.yaxis.set_major_formatter(NullFormatter())
    ax.grid(which="major", axis="both", color="0.5")
    ax.grid(which="minor", axis="both", color="0.2")
    ax.minorticks_on()

    # Plot the channels
    ytrans = transforms.blended_transform_factory(ax.get_yticklabels()[0].get_transform(), ax.transData)
    if len(data1) > 0:
        vpd = conversions.VOLTS_PER_DIV[wave.header.channel1.volts_per_div]
        vpd_str = utils.format_number(vpd * (10 ** wave.header.channel1.mode), "V")
        col = conversions.CHANNEL_COLOUR[0]

        ax.plot(time, data1, color=col, label=f"Ch1: {vpd_str}")
        ax.axhline(y=wave.header.channel1.offset, color=col, lw=0.8, ls="-")
        ax.text(0, wave.header.channel1.offset, "1>", color=col, transform=ytrans, ha="right", va="center")
    if len(data2) > 0:
        vpd = conversions.VOLTS_PER_DIV[wave.header.channel2.volts_per_div]
        vpd_str = utils.format_number(vpd * (10 ** wave.header.channel1.mode), "V")
        col = conversions.CHANNEL_COLOUR[1]

        ax.plot(time, data2, color=col, label=f"Ch2: {vpd_str}")
        ax.axhline(y=wave.header.channel2.offset, color=col, lw=0.8, ls="-")
        ax.text(0, wave.header.channel2.offset, "2>", color=col, transform=ytrans, ha="right", va="center")
    if len(data3) > 0:
        vpd = conversions.VOLTS_PER_DIV[wave.header.channel3.volts_per_div]
        vpd_str = utils.format_number(vpd * (10 ** wave.header.channel1.mode), "V")
        col = conversions.CHANNEL_COLOUR[2]

        ax.plot(time, data3, color=col, label=f"Ch3: {vpd_str}")
        ax.axhline(y=wave.header.channel3.offset, color=col, lw=0.8, ls="-")
        ax.text(0, wave.header.channel3.offset, "3>", color=col, transform=ytrans, ha="right", va="center")
    if len(data4) > 0:
        vpd = conversions.VOLTS_PER_DIV[wave.header.channel4.volts_per_div]
        vpd_str = utils.format_number(vpd * (10 ** wave.header.channel1.mode), "V")
        col = conversions.CHANNEL_COLOUR[3]

        ax.plot(time, data4, color=col, label=f"Ch4: {vpd_str}")
        ax.axhline(y=wave.header.channel4.offset, color=col, lw=0.8, ls="-")
        ax.text(0, wave.header.channel4.offset, "4>", color=col, transform=ytrans, ha="right", va="center")

    # Trigger line
    trigger_level = wave.header.channel1.trigger_level
    trigger_channel = wave.header.channel1.trigger_channel
    col = conversions.CHANNEL_COLOUR[trigger_channel]
    ax.axhline(y=trigger_level, color=col, lw=0.8, ls="-")
    ax.text(0, trigger_level, "T", color=col, transform=ytrans, ha="right", va="center")

    # Timebase Text
    samples_per_second = utils.format_number(wave.header.channel1.samples_per_second)
    sampling_depth = utils.format_number(wave.header.channel1.sampling_depth)
    plt.title(f"Timebase: {timebase_str}, {samples_per_second}Sa/s, {sampling_depth}Pt")

    # Display it
    ax.legend()
    plt.show()
