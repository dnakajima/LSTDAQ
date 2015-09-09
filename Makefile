all:LSTDAQ DataChecker

LSTDAQ:
	clang -o LSTDAQ Master.cpp RingBuffer.cpp TCPClientSocket.cpp DAQtimer.cpp -lrt -lpthread

DataChecker:
	clang -o DataChecker DataChecker.cpp


clean:
	rm LSTDAQ DataChecker
