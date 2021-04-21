import unittest
from utils import get_positions_substring_in_string, get_occurrence


class TestGetOccurrence(unittest.TestCase):

    def test_first(self):
        string = 'Olá, Marcos e como está seu emprego?'
        substring = 'Marcos'

        substring_positions = get_positions_substring_in_string(
            substring, string)
        substring_position = substring_positions[0]
        length_substring = len(substring)

        AMOUNT_CHARACTERS_AFTER = 5
        AMOUNT_CHARACTERS_BEFORE = 5

        function_result = get_occurrence(string, length_substring, substring_position,
                                         AMOUNT_CHARACTERS_BEFORE, AMOUNT_CHARACTERS_AFTER)
        expected_result = 'Olá, Marcos e co'

        self.assertEqual(expected_result, function_result)

    def test_second(self):
        string = 'Marcos e como está seu emprego?'
        substring = 'Marcos'

        substring_positions = get_positions_substring_in_string(
            substring, string)
        substring_position = substring_positions[0]
        length_substring = len(substring)

        AMOUNT_CHARACTERS_AFTER = 5
        AMOUNT_CHARACTERS_BEFORE = 5

        function_result = get_occurrence(string, length_substring, substring_position,
                                         AMOUNT_CHARACTERS_BEFORE, AMOUNT_CHARACTERS_AFTER)
        expected_result = 'Marcos e co'

        self.assertEqual(expected_result, function_result)

    def test_thirty(self):
        string = 'Oi Marcos e como está seu emprego?'
        substring = 'Marcos'

        substring_positions = get_positions_substring_in_string(
            substring, string)
        substring_position = substring_positions[0]
        length_substring = len(substring)

        AMOUNT_CHARACTERS_AFTER = 5
        AMOUNT_CHARACTERS_BEFORE = 5

        function_result = get_occurrence(string, length_substring, substring_position,
                                         AMOUNT_CHARACTERS_BEFORE, AMOUNT_CHARACTERS_AFTER)
        expected_result = 'Oi Marcos e co'

        self.assertEqual(expected_result, function_result)

    def test_fourth(self):
        string = 'Oi, Marcos'
        substring = 'Marcos'

        substring_positions = get_positions_substring_in_string(
            substring, string)
        substring_position = substring_positions[0]
        length_substring = len(substring)

        AMOUNT_CHARACTERS_AFTER = 5
        AMOUNT_CHARACTERS_BEFORE = 5

        function_result = get_occurrence(string, length_substring, substring_position,
                                         AMOUNT_CHARACTERS_BEFORE, AMOUNT_CHARACTERS_AFTER)
        expected_result = 'Oi, Marcos'

        self.assertEqual(expected_result, function_result)

    def test_fifth(self):
        string = 'Oi, Marcos do'
        substring = 'Marcos'

        substring_positions = get_positions_substring_in_string(
            substring, string)
        substring_position = substring_positions[0]
        length_substring = len(substring)

        AMOUNT_CHARACTERS_AFTER = 5
        AMOUNT_CHARACTERS_BEFORE = 5

        function_result = get_occurrence(string, length_substring, substring_position,
                                         AMOUNT_CHARACTERS_BEFORE, AMOUNT_CHARACTERS_AFTER)
        expected_result = 'Oi, Marcos do'

        self.assertEqual(expected_result, function_result)
