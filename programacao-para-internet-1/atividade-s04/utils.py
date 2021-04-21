import os


def clear_terminal():
    os.system('clear')


def download_page(page_url):
    command_terminal = f"curl {pageURL} -o index.html"

    os.system(command_terminal)


def is_url_valid(url):
    if (url.count('http://') == 1):
        if url.index('http://') == 0:
            return True
    if (url.count('https://') == 1):
        if url.index('https://') == 0:
            return True

    return False


def remove_white_spaces(string):
    return string.strip()


def is_status_code_valid(status_code):
    return (status_code >= 200) and (status_code < 400)


def clear_string(string):
    string_removed_white_spaces = remove_white_spaces(string)
    string_list = string_removed_white_spaces.split()
    string_formatted = ' '.join(string_list)

    return string_formatted


def get_tags_a_href_is_valid(tags_a_all):
    tags_a_href_valid = []
    counter = 0

    while len(tags_a_href_valid) < 10:
        href = tags_a_all[counter].get('href') or ''

        if (is_url_valid(href)):
            tags_a_href_valid.append(href)

        counter += 1

    return tags_a_href_valid


def print_links(tags_a=[]):
    print()
    print("================ SELECIONE UM LINK ================\n")

    for i in range(len(tags_a)):
        print(f'{i+1}: {tags_a[i]}')

    print()


def is_valid_number_selected_link(number_selected_link, start_number, end_number):
    return (number_selected_link >= start_number) and (number_selected_link <= end_number)


def get_positions_substring_in_string(substring, string):
    return [i for i in range(len(string)) if string.startswith(substring, i)]


def get_occurrence(string, length_substring, position_substring, amount_characters_before, amount_characters_after):
    position_start = position_substring - amount_characters_before
    position_end = position_substring + length_substring + amount_characters_after

    if position_substring == 0:
        position_start = position_substring
        return string[position_start:position_end]

    if position_substring < amount_characters_before:
        return string[:position_end]

    return string[position_start:position_end]


def get_occurrences(formatted_text_lower_case, positions_keyword_in_text, length_keyword, AMOUNT_CHARACTERS_AFTER, AMOUNT_CHARACTERS_BEFORE):
    occurrences = []
    amount_occurrences_keyword_in_text = len(
        positions_keyword_in_text)

    for i in range(amount_occurrences_keyword_in_text):
        occurrence = get_occurrence(formatted_text_lower_case, length_keyword,
                                    positions_keyword_in_text[i], AMOUNT_CHARACTERS_BEFORE, AMOUNT_CHARACTERS_AFTER)
        occurrences.append(occurrence)

    return occurrences


def print_occurrences(occurrences):
    print()
    print("================ OCORRÊNCIAS ================\n")

    for i in range(len(occurrences)):
        print(f'{i+1}. {occurrences[i]}')

    print()
