import unittest
from unittest.mock import patch
from unittest.mock import Mock
import urllib.request
import urllib.parse
import json
import io

class CreateForm:

    def __init__(self):
        self.data = {
                "name" : "Ellsworth Branch Finder Survey",
                "db" : "0",
                "num_columns" : "4",
                "disabled_message" : "This form is currently inactive.",
                "notifications" : [ "doug.axtell@gmail.com" ],
                "confirmation" : [ "doug.axtell@gmail.com" ],
            }
        json_data = json.dumps(self.data)
        self.binary_data = bytes(json_data, "UTF-8")
        self.create_form_url = "https://www.formstack.com/api/v2/form.json"
        self.header = bytes(urllib.parse.urlencode(
            {
                "Content-Length" : str(len(json_data)),
                "Content-Type" : " application/x-www-form-urlencoded;charset=utf-8",
                "Authorization" : "Bearer 6F4D60849DE3A0E43758867E882D1AB6",
            }), "UTF-8")
        self.urlRequest = urllib.request.Request(self.create_form_url, self.header)

    def Create(self):
        return urllib.request.urlopen(self.urlRequest, self.binary_data)
        

class CreateFormTest(unittest.TestCase):

    def setUp(self):
        self.cf = CreateForm()
        

    def test_CreateForm_OneUrlReqMade(self):
        with patch.object(urllib.request, 'urlopen', return_value=None) as mock_method:
            self.cf.Create()
        mock_method.assert_called_once_with(self.cf.urlRequest, self.cf.binary_data)


def main():
    cf = CreateForm()
    print(json.loads(cf.Create()))

if __name__ == '__main__':
    main()
