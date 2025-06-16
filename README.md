# BLE-IPC Framework

An industrial-grade C++ backend framework for BLE device control systems.

This project provides a clean and scalable backend architecture for managing BLE devices, parsing communication protocols, and enabling cross-platform communication with frontend clients.

---

## 🚀 Key Features

* ✅ Modular BLE Device Management (`BLEManager`)
* ✅ Protocol Parsing Abstraction Layer (`ProtocolParser`)
* ✅ Multi-threaded TCP IPC Server (`IPCServer`)
* ✅ High-performance Logging System (`spdlog`)
* ✅ JSON Data Format via `nlohmann-json`
* ✅ Cross-platform CMake build system
* ✅ Python-based frontend demo client

---

## 🚀 Project Structure

```
ble_ipc_framework/
├── src/                # Core source code
│   ├── main.cpp
│   ├── BLEManager.*
│   ├── ProtocolParser.*
│   ├── IPCServer.*
│   └── Utils/Logger.* / JsonHelper.*
├── third_party/        # External dependencies (spdlog / nlohmann-json)
├── python_client_demo/ # Python demo frontend client
├── build/              # (Local build directory - ignored by Git)
└── README.md
```

---

## 🚀 Build Instructions

### Dependencies

* CMake 3.20+
* C++20 compatible compiler (MSVC / GCC / Clang)
* spdlog
* nlohmann-json

### Example Build (Windows)

```
# Navigate to project root
mkdir build
cd build

# Generate build files
cmake ..

# Build Release version
cmake --build . --config Release
```

---

## 🚀 Running the Framework

### Start the backend server

```
cd build/Release
./ble_ipc_framework.exe
```

### Run frontend test client

```
cd python_client_demo
python client.py
```

The backend server listens by default on `127.0.0.1:9000` and streams decoded protocol data to the frontend.

---

## 🚀 Future Extensions

* ✅ Implement real BLE device logic in `BLEManager` and `ProtocolParser`
* ✅ Integrate WinRT BLE backend (Windows BLE stack)
* ✅ Support multi-device BLE connections
* ✅ Full protocol abstraction layer
* ✅ Develop cross-platform Qt + OpenGL GUI for real-time signal visualization

---

## 🚀 License

This framework is designed as a long-term reusable BLE control system backend.

---

## 🧑‍💻 Developer

* **Yihang Zhang**
* Focused on BLE, embedded systems, and biomedical signal processing platforms.

---

## 🚀 Current Status

> Version: `v1.0 - Core Architecture Complete`
>
> `v1.1 Industrial Enhanced Version` is under active development and refactoring.
