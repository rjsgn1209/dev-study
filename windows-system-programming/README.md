# Windows System Programming

Windows 시스템 프로그래밍 학습을 위한 Visual Studio 솔루션입니다.

Windows의 프로세스, 스레드, 동기화, 메모리, IPC 등 주요 시스템 프로그래밍 개념을 학습하고, 개념에 대한 정리와 실습 코드를 함께 관리합니다.

## Directory Structure

```text
WindowsSystemProgramming/
│
├── WindowsSystemProgramming.sln
│
├── src/                          # 학습한 개념을 활용한 실습 코드
│   ├── Process/
│   ├── Security/
│   ├── Thread/
│   ├── Memory/
│   ├── IPC/
│   ├── DLL/
│   └── Examples/
│
├── docs/                         # Windows 시스템 프로그래밍 학습 내용
│   ├── Architecture/
│   ├── Process/
│   ├── Security/
│   ├── Thread/
│   ├── Memory/
│   ├── IPC/
│   └── DLL/
│
└── README.md
```

### `src`

학습한 Windows 시스템 프로그래밍 개념을 실제 코드로 구현한 프로젝트를 관리합니다.

각 프로젝트는 독립적으로 실행할 수 있는 Visual Studio 프로젝트로 구성되어 있으며, 하나의 솔루션에서 여러 학습 예제를 관리합니다.

### `docs`

Windows 시스템 프로그래밍을 학습하면서 정리한 개념과 관련 내용을 Markdown(`.md`) 파일로 관리합니다.

실습 코드가 존재하지 않는 개념적인 내용도 `docs`에서 별도로 정리합니다.

---

## Documentation

### Architecture

* [User-Kenel Mode](docs/architecture/user-kernel-mode.md)

### Process

* [Process Inheritance](docs/process/process-access-token-inheritance.md)

### Security

* [Security Object](docs/security/security-object.md)

### Thread

* [Thread Basic](docs/thread/thread-basic.md)
* [Thread Control](docs/thread/thread-control.md)
* [Sleep](docs/thread/sleep.md)
* [TLS](docs/thread/TLS.md)
* [Thread Synchronization](docs/thread/thread-synchronization.md)
* [Critical Section](docs/thread/critical-section.md)
* [Event](docs/thread/event.md)
* [Semaphore](docs/thread/semaphore.md)

### Memory

### IPC

### DLL
