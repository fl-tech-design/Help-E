# led_control.py

import requests

class LedControl:
    def __init__(self, base_url):
        self.base_url = base_url

    def send_request(self, endpoint):
        url = f'{self.base_url}{endpoint}'
        try:
            response = requests.get(url)
            response.raise_for_status()
            print(f'Successfully sent request to {url}')
        except requests.exceptions.HTTPError as http_err:
            print(f'HTTP error occurred: {http_err}')
        except requests.exceptions.RequestException as req_err:
            print(f'Request error occurred: {req_err}')
    
    def all_led_on(self):
        self.send_request('/all_on')

    def all_led_off(self):
        self.send_request('/all_off')

    def blink_right(self):
        self.send_request('/blink_R')

    def blink_left(self):
        self.send_request('/blink_L')

