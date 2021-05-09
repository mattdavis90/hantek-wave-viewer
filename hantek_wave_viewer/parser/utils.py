import math
from decimal import Decimal

_large_units = ['', 'K', 'M', 'G', 'T', 'P']
_small_units = ['', 'm', 'u', 'n', 'p', 'f']

def format_large(v, units=''):
    d = Decimal(v)

    if d == 0:
        return f'0{units}'

    sign = ''
    if d < 0:
        d *= -1
        sign = '-'

    i = 0
    while d >= 1000 and i < len(_large_units) - 1:
        d /= 1000
        i += 1
    return f'{sign}{d}{_large_units[i]}{units}'

def format_small(v, units=''):
    d = Decimal(v)

    if d == 0:
        return f'0{units}'

    sign = ''
    if d < 0:
        d *= -1
        sign = '-'

    i = 0
    while d < 1 and i < len(_small_units) - 1:
        d *= 1000
        i += 1
    d = d.to_integral_value()
    return f'{sign}{d}{_small_units[i]}{units}'

def format_number(v, units=''):
    if abs(Decimal(v)) > 1:
        return format_large(v, units)
    return format_small(v, units)
