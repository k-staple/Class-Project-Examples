
CMP = g++ -std=c++11
CLASS = othboard
MAIN = othello
EXEC = runit

$(EXEC): $(CLASS).o $(MAIN).o
	$(CMP) $(CLASS).o $(MAIN).o -o $(EXEC)

$(CLASS).o: $(CLASS).cpp $(CLASS).h
	$(CMP) -c $(CLASS).cpp -o $(CLASS).o

$(MAIN).o: $(MAIN).cpp $(CLASS).h
	$(CMP) -c $(MAIN).cpp -o $(MAIN).o

clean:
	rm $(MAIN).o
	rm $(CLASS).o
	rm $(EXEC)

