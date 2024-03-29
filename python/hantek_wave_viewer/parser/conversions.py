TIMEBASE = {
    32: 100,
    31: 50,
    30: 20,
    29: 10,
    28: 5,
    27: 2,
    26: 1,
    25: 500e-3,
    24: 200e-3,
    23: 100e-3,
    22: 50e-3,
    21: 20e-3,
    20: 10e-3,
    19: 5e-3,
    18: 2e-3,
    17: 1e-3,
    16: 500e-6,
    15: 200e-6,
    14: 100e-6,
    13: 50e-6,
    12: 20e-6,
    11: 10e-6,
    10: 5e-6,
    9: 2e-6,
    8: 1e-6,
    7: 500e-9,
    6: 200e-9,
    5: 100e-9,
    4: 50e-9,
    3: 20e-9,
    2: 10e-9,
    1: 5e-9,
    0: 2e-9,
}

VOLTS_PER_DIV = {
    13: 10,
    12: 5,
    11: 2,
    10: 1,
    9: 500e-3,
    8: 200e-3,
    7: 100e-3,
    6: 50e-3,
    5: 20e-3,
    4: 10e-3,
    3: 5e-3,
    2: 2e-3,
    1: 1e-3,  # Not available on DSO2C10
    0: 500e-6,  # Not available on DSO2C10
}

TRIGGER_NAME = [
    "Edge",
    "Pulse",
    "Video",
    "Slope",
    "Overtime",
    "Window",
    "Pattern",
    "Interval",
    "Under Amp",
    "UART",
    "LIN",
    "CAN",
    "SPI",
    "IIC",
]

ACQUISITION_MODE = [
    "Normal",
    "Average",
    "Peak",
    "HR",
]

CHANNEL_COLOUR = {
    0: "#f8f601",
    1: "#00f401",
    2: "red",
    3: "green",
}
