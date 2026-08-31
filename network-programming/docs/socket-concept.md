# 소캣 개념

소켓은 파일이고 갯수가 정해져있다.  
  
파일에는 OS 커널에 구현되어있는 추상화된 인터페이스로도 사용된다.
  
TCP 스택에 대한 추상화된 인터페이스를 제공하는 파일을 TCP 소켓이라한다.
  
주체인 프로세스가 파일인 TCP 소켓을 Open, Read, Write, Excute, Close 할수있다.
  
소켓에서 Read는 Receive라고 부르고 Write는 Send라고 부른다.
  
파일은 Stream형태 이므로 소켓을 통한 TCP 통신도 Stream 형태이다.
  
Stream 형태의 데이터를 단편화해서 잘라내는 작업을 Segmentation이라고 하며 
  
해당 작업으로 잘린 조각을 Segment라고 부른다. 그리고 해당 조각을 인터넷 통신을 위해 패킹하것을 패킷이라고 부른다.