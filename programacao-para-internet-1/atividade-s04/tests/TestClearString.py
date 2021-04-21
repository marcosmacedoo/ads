import unittest
from utils import clear_string


class TestClearString(unittest.TestCase):

    def test_first(self):
        text = "   ALo"

        function_result = clear_string(text)
        expected_result = "ALo"

        self.assertEqual(expected_result, function_result)

    def test_second(self):
        text = ""

        function_result = clear_string(text)
        expected_result = ""

        self.assertEqual(expected_result, function_result)

    def test_thirty(self):
        text = "css   e  java    "

        function_result = clear_string(text)
        expected_result = "css e java"

        self.assertEqual(expected_result, function_result)
