import socket

def main():
    host = '127.0.0.1'
    port = 9000

    with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
        s.connect((host, port))
        print(f"Connected to server at {host}:{port}")

        while True:
            data = s.recv(4096)
            if not data:
                break
            print("Received:", data.decode().strip())

if __name__ == '__main__':
    main()
