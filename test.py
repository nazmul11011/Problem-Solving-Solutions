import requests
import csv
import json
import re

url = "http://103.84.159.55:9092/course-registrations/create"

headers = {
    'Host': "103.84.159.55:9092",
    'User-Agent': "Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/138.0.0.0 Safari/537.36",
    'Accept': "text/x-component",
    'Accept-Encoding': "gzip, deflate",
    'Content-Type': "text/plain;charset=UTF-8",
    'Next-Action': "6164afd79455923a14fe2c36e4512ab6e751c4aa",
    'Next-Router-State-Tree': "%5B%22%22%2C%7B%22children%22%3A%5B%22(dashboard)%22%2C%7B%22children%22%3A%5B%22course-registrations%22%2C%7B%22children%22%3A%5B%22create%22%2C%7B%22children%22%3A%5B%22__PAGE__%22%2C%7B%7D%5D%7D%5D%7D%5D%7D%2Cnull%2Cnull%2Ctrue%5D%7D%2Cnull%2Cnull%2Ctrue%5D",
    'Origin': "http://103.84.159.55:9092",
    'Referer': "http://103.84.159.55:9092/course-registrations/create",
    'Accept-Language': "en-US,en;q=0.9,bn;q=0.8",
    'Cookie': "token="
}

with open('students_info.csv', mode='w', newline='', encoding='utf-8') as file:
    writer = csv.writer(file)
    # Write header for student info
    writer.writerow([
        'Registration No', 'Name', 'Mobile', 'Email', 
        'Session', 'Degree',
        'Semester Code', 'Semester Name'
    ])

    # Loop over registration numbers
    for reg in range(2022831001, 2022831053):
        payload = f'["{reg}"]'
        try:
            response = requests.post(url, data=payload, headers=headers)
            response_text = response.text
            match = re.search(r'1:(\{.*\})', response_text, re.DOTALL)

            if not match:
                print(f"{reg}: No valid JSON found, skipping.")
                continue

            json_str = match.group(1)
            json_data = json.loads(json_str)

            student_info = json_data['data']['studentInfo']
            semesters = json_data['data']['semesters']

            for semester in semesters:
                writer.writerow([
                    student_info['registrationNo'],
                    student_info['name'],
                    student_info['mobile'],
                    student_info['email'],
                    student_info['session']['name'],
                    student_info['degree']['name'],
                    semester['code'],
                    semester['name'],
                ])

            print(f"{reg}: Saved successfully.")
        except Exception as e:
            print(f"{reg}: Error occurred -> {e}")
