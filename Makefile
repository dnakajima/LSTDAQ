all:LSTDAQ DataChecker

LSTDAQ:
	g++ -o LSTDAQ Master.cpp RingBuffer.cpp TCPClientSocket.cpp DAQtimer.cpp -lrt -lpthread


DataChecker:
	g++ -o DataChecker DataChecker.cpp


clean:
	rm LSTDAQ DataChecker
