import requests
import requests_cache
from bs4 import BeautifulSoup
from utils import *

requests_cache.install_cache('db_cache')


def main():
    clear_terminal()

    while True:
        page_url = input(
            'Digite a URL de uma página WEB (E - Para encerrar): ')

        if (page_url.lower() == 'e'):
            clear_terminal()
            break

        page_url_removed_white_spaces = remove_white_spaces(page_url)

        if not is_url_valid(page_url):
            print('\nERRO: URL inválida')
            break

        response = None

        try:
            response = requests.get(page_url)
        except:
            print('\nERRO: Falha na requisição')
            break

        if is_status_code_valid(response.status_code):
            soup = BeautifulSoup(response.text, 'html.parser')

            formatted_text = ''

            try:
                formatted_text = clear_string(soup.body.get_text())
            except:
                print('ERRO: Não foi possível extrair texto dessa página')
                break

            formatted_text_lower_case = formatted_text.lower()

            tags_a_all = soup.find_all('a')
            tags_a_href_valid = get_tags_a_href_is_valid(tags_a_all)

            print_links(tags_a_href_valid)

            number_selected_link = -1

            try:
                number_selected_link = int(
                    input('Digite um número referente a um link (1 a 10): '))
            except:
                print('\nERRO: O valor deve ser um número entre 1 e 10')
                break

            OPTION_START_NUMBER = 1
            OPTION_END_NUMBER = 10

            if (is_valid_number_selected_link(number_selected_link, OPTION_START_NUMBER, OPTION_END_NUMBER)):
                selected_link = tags_a_href_valid[number_selected_link - 1]
                print(f'Você escolheu {selected_link}')

                response = requests.get(selected_link)
                soup = BeautifulSoup(response.text, 'html.parser')

                formatted_text = ''

                try:
                    formatted_text = clear_string(soup.body.get_text())
                except:
                    print('ERRO: Não foi possível extrair texto dessa página')
                    break

                formatted_text_lower_case = formatted_text.lower()

                keyword = input('\nDigite uma palavra chave: ')
                formatted_keyword = clear_string(keyword).lower()

                if (formatted_keyword == ''):
                    print('\nERRO: Palavra chave inválida')
                    break

                positions_keyword_in_text = get_positions_substring_in_string(
                    formatted_keyword, formatted_text_lower_case)
                amount_occurrences_keyword_in_text = len(
                    positions_keyword_in_text)
                length_keyword = len(formatted_keyword)
                AMOUNT_CHARACTERS_AFTER = 15
                AMOUNT_CHARACTERS_BEFORE = 15

                occurrences = get_occurrences(formatted_text_lower_case, positions_keyword_in_text,
                                              length_keyword, AMOUNT_CHARACTERS_AFTER, AMOUNT_CHARACTERS_BEFORE)

                print(
                    f'\nForam encontradas {amount_occurrences_keyword_in_text} ocorrências de {formatted_keyword}\n')

                print_occurrences(occurrences)
            else:
                print('\nERRO: Opção inválida!')
                break

        else:
            print('\nERRO: URL não está acessível no momento')
            raise Exception()


if __name__ == '__main__':
    main()
