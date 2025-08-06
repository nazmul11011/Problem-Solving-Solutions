import requests

# Encrypted values assumed for now — replace after analyzing i.n()
encrypted_phone = "VM1J3fgmpnfZiDe7NFnwPCJdGoMuMJtWEzQpQL2NP340cEmTnDAeemyvmWo7gLfzzhTknCICiAI7jtZ8qgTInEJKepqCj5PKWBpHJIyRYWYMWKb5+6xE6xufkCipBunYAsqRdqu03eKDqe/KrF4bO25zrK6PDw4XzWO1ZVhid1/2STqT9eVPmGFxRVy7/BL4IuBGwduJOOROyCnvMiyV4r0nQp/kx5pc2S17yQbM6G+VSSMt+638/WSQZfX2KXcYjXkf1AQH9vwpXgy11wcvoxbbs2KdwrpuoWVxXAI4wLC+ZcbGKy7NWeqM06H1z7u81UM7+I2/2r/2CdymLThFVg=="
encrypted_password = "XKf9693Jv3yfeHJuv3bj6x4DNp4JyDVfoZAQMILGH5BP9uDPKesi6VR0gNK9y6pL5R7mlWGnamr087s6qfIgPF1g7AOSvYtZRiwahBgs1SHpaw39HcFUiHyo3JTO/qD1+qm31/JXVoPk2c/UZshsH1tNxE8I+SywDNk4Rqpw1gvMHPgfQdf5/IGO16wHeiY8h9xOr6CKIf+tCKJH59BzdMPrEt2Zpo40PcsIy47jiuSZJV4o7kHszq0RW5cZjsnPJD8YCOg0bkOZspWBxkUyMZHaVnpoLFkiSjHLErFJieLHtCF+k3cto++645z1ICXoG8bkPK62U4KVXfWjhbm6yQ=="

url = "https://mt.teletalk.com.bd/auth/app/user/login/"

data = {
    "phone_number": encrypted_phone,
    # "otp": "otp",  # constant in this app
    "password": encrypted_password
}

headers = {
    "Content-Type": "application/x-www-form-urlencoded",
    "User-Agent": "TeletalkCustomerApp/1.0"
}

response = requests.post(url, data=data, headers=headers)

print("Status:", response.status_code)
print("Body:", response.text)
