all: main3

testFetch:
				g++ -o fetch fetch.cpp

main3:
				g++ -Wall -std=c++17 -o main  main.cpp vectorProcessor.cpp fetch.cpp decoder.cpp \
				execute.cpp alu.cpp fetch_decoder_register.cpp decoder_execute_register.cpp  \
				register_exe_mem.cpp memory.cpp register_mem_wb.cpp write_back.cpp parser.cpp

main2:
				g++ -Wall -std=c++17 -o main2 main2.cpp vectorProcessor.cpp fetch.cpp decoder.cpp execute.cpp alu.cpp fetch_decoder_register.cpp decoder_execute_register.cpp register_exe_mem.cpp memory.cpp register_mem_wb.cpp

main1:
				g++ -Wall -std=c++17 -o main1  main1.cpp vectorProcessor.cpp fetch.cpp decoder.cpp execute.cpp alu.cpp fetch_decoder_register.cpp decoder_execute_register.cpp register_exe_mem.cpp memory.cpp register_mem_wb.cpp write_back.cpp

clean:
				rm main main2
