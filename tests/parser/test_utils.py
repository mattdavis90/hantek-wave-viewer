import unittest

from hantek_wave_viewer.parser import utils

class UtilsTestCase(unittest.TestCase):
    def test_format_small(self):
        self.assertEqual(utils.format_small("100"), "100")
        self.assertEqual(utils.format_small("10"), "10")
        self.assertEqual(utils.format_small("1"), "1")
        self.assertEqual(utils.format_small("0.1"), "100m")
        self.assertEqual(utils.format_small("0.01"), "10m")
        self.assertEqual(utils.format_small("0.001"), "1m")
        self.assertEqual(utils.format_small("0.0001"), "100u")
        self.assertEqual(utils.format_small("0.00001"), "10u")
        self.assertEqual(utils.format_small("0.000001"), "1u")
        self.assertEqual(utils.format_small("0.0000001"), "100n")
        self.assertEqual(utils.format_small("0.00000001"), "10n")

        self.assertEqual(utils.format_small("0.000000016"), "16n")

    def test_format_large(self):
        self.assertEqual(utils.format_large("1"), "1")
        self.assertEqual(utils.format_large("10"), "10")
        self.assertEqual(utils.format_large("100"), "100")
        self.assertEqual(utils.format_large("1000"), "1K")
        self.assertEqual(utils.format_large("10000"), "10K")
        self.assertEqual(utils.format_large("100000"), "100K")
        self.assertEqual(utils.format_large("1000000"), "1M")
        self.assertEqual(utils.format_large("10000000"), "10M")
        self.assertEqual(utils.format_large("100000000"), "100M")
        self.assertEqual(utils.format_large("1000000000"), "1G")
        self.assertEqual(utils.format_large("10000000000"), "10G")

        self.assertEqual(utils.format_large("1250000000"), "1.25G")

    def test_format_number(self):
        self.assertEqual(utils.format_number("1250"), "1.25K")
        self.assertEqual(utils.format_number("0"), "0")
        self.assertEqual(utils.format_number("0.125"), "125m")
