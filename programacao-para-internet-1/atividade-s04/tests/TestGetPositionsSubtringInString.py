import unittest
from utils import get_positions_substring_in_string


class TestGetPositionsSubstringInString(unittest.TestCase):

    def test_first(self):
        string = 'CSS é sensacional. CSS é vida'
        substring = 'CSS'

        function_result = get_positions_substring_in_string(substring, string)
        expected_result = [0, 19]

        self.assertListEqual(expected_result, function_result)

    def test_second(self):
        string = 'Olá, tudo bem Marcos?'
        substring = 'bem'

        function_result = get_positions_substring_in_string(substring, string)
        expected_result = [10]

        self.assertListEqual(expected_result, function_result)
