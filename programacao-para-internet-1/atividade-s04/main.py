import requests
import requests_cache
from bs4 import BeautifulSoup
from utils import *

requests_cache.install_cache('db_cache')


def main():
    clear_terminal()

    while True:
        page_url = input(
            'Digite a URL de uma página WEB (S - Para encerrar): ')

        if (page_url.lower() == 's'):
            clear_terminal()
            break

        page_url_removed_white_spaces = remove_white_spaces(page_url)

        if not is_url_valid(page_url):
            print('\nERRO: URL inválida')
            print('Digite um URL válida, por favor.')
        else:
            response = None
            try:
                response = requests.get(page_url)
            except:
                print('\nERRO: Falha na requisição')
                print('Digite um URL válida, por favor.')
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

                if (len(tags_a_href_valid) > 0):
                    word_key = input('Digite uma palavra chave para busca: ')
                    formatted_word_key = clear_string(word_key).lower()

                    if (formatted_word_key == ''):
                        print('ERRO: Palavra chave inválida')
                    else:
                        amount_of_occurrences_word_key_in_text_html = formatted_text_lower_case.count(
                            formatted_word_key)
                        print(
                            f'Foram {amount_of_occurrences_word_key_in_text_html} ocorrências de {word_key}\n')

                else:
                    print("ERRO: Nenhum link válido foi encontrado nessa página")
                    break

            else:
                print('\nERRO: URL não está acessível no momento')
                raise Exception()


if __name__ == '__main__':
    main()
