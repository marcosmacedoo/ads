import unittest
from utils import remove_white_spaces


class TestRemoveWhiteSpaces(unittest.TestCase):

    def first_test(self):
        url = '      http://      '

        function_result = remove_white_spaces(url)
        expected_result = 'http://'

        self.assertEqual(expected_result, function_result)

    def second_test(self):
        url = '   '

        function_result = remove_white_spaces(url)
        expected_result = ''

        self.assertEqual(expected_result, function_result)

    def third_test(self):
        url = '   a'

        function_result = remove_white_spaces(url)
        expected_result = 'a'

        self.assertEqual(expected_result, function_result)

    def fourth_test(self):
        url = '  a  d '

        function_result = remove_white_spaces(url)
        expected_result = 'a  d'

        self.assertEqual(expected_result, function_result)
