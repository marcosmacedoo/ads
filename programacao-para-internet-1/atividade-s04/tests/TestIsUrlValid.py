import unittest
from utils import is_url_valid, remove_white_spaces


class TestIsUrlValid(unittest.TestCase):

    def test_first(self):
        url = 'https'
        result_function = is_url_valid(url)

        self.assertFalse(result_function)

    def test_second(self):
        url = ''
        result_function = is_url_valid(url)

        self.assertFalse(result_function)

    def test_third(self):
        url = 'https:/'
        result_function = is_url_valid(url)

        self.assertFalse(result_function)

    def test_fourth(self):
        url = 'http://'
        result_function = is_url_valid(url)

        self.assertTrue(result_function)

    def test_fifth(self):
        url = '   http:  /   /'
        result_function = is_url_valid(url)

        self.assertFalse(result_function)

    def test_sixth(self):
        url = 'https://github.com'
        result_function = is_url_valid(url)

        self.assertTrue(result_function)

    def test_seventh(self):
        url = 'https://github.comhttps://'
        result_function = is_url_valid(url)

        self.assertFalse(result_function)

    def test_eighth(self):
        url = 'asd      http://'
        result_function = is_url_valid(url)

        self.assertFalse(result_function)

    def test_ninth(self):
        url = remove_white_spaces(' http://www.google.com  ')
        result_function = is_url_valid(url)

        self.assertTrue(result_function)
