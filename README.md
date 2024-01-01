# Hantek Wave Viewer
This is a Python based wave viewer for the Hantek series of Oscilloscopes which use the `lwf` file format.
I couldn't find any documentation for the format or previous projects so created this one by reverse engineering samples. I hope it works for you.

**Note:** All tests conducted on a Hantek DSO2C10

## How to use
```bash
git clone https://github.com/mattdavis90/hantek-wave-viewer.git
cd hantek-wave-viewer
pip install -r requirements.txt
python -m hantek_wave_viewer <lwf file>
```
### Screenshots
This is a screenshot of the Python based viewer

![Screenshot of Python viewer](wavefiles/scope_wave_35_4_py.png)

and the same waves on the Oscilloscope for comparison

![Screenshot from Oscilloscope](wavefiles/scope_wave_35_4.png)

## Testing the parser
I captured a number of wavefiles with known parameters, all files used are in `wavefiles`. You can read more about each sample in `wavefiles/README.md`


## Other Programming Languages
This project is licensed as MIT so feel free to use and modify as you wish. The Kaitai file is included and, as per their docs, could be used to generate a parser in other languages.
