COM		:= g++
COM_FLAGS	:= -c

SFML_PATH	:= ./SFML-2.5.1

EXEC_FILE	:= sseabottle
MAIN_FILE	:= main


all: clean compile execute

execute:
	@echo "🚀 Executing ..."
	export LD_LIBRARY_PATH=$(SFML_PATH)/lib && ./$(EXEC_FILE)

compile: $(MAIN_FILE).o
	@echo "🚧 Building ..."
	$(COM) $(MAIN_FILE).o -o $(EXEC_FILE) -L$(SFML_PATH)/lib -lsfml-graphics -lsfml-window -lsfml-system

$(MAIN_FILE).o:
	$(COM) $(COM_FLAGS) $(MAIN_FILE).cpp -I$(SFML_PATH)/include

clean:
	@echo "🧹 Cleaning ..."
	-rm $(MAIN_FILE).o  $(EXEC_FILE)
