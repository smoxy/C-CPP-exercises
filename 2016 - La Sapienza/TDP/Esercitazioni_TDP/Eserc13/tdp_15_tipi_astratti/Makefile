#make variables
COMMON_OBJS=stack_main.o list_functions.o  
LIST_OBJS=stack_list.o  
ARRAY_OBJS=stack_array.o
ALL_OBJS=$(COMMON_OBJS) $(LIST_OBJS) $(ALL_OBJS)
CXXFLAGS=-Wall
CXX=g++
EXECS=stack_main_array stack_main_list
#default rules
.phony:	clean all

all:	stack_main_array stack_main_list

#each .o depends on the corresponding .c
%.o:	%.c
	$(CXX) -c $(CXXFLAGS) $< -o $@

#the main is the same!!
#we just link different things
stack_main_list: $(COMMON_OBJS) $(LIST_OBJS) 
	$(CXX) $(CXXFLAGS) -o $@ $^

stack_main_array:	$(COMMON_OBJS) $(ARRAY_OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^ 

#polishes
clean:	
	rm -rf $(COMMON_OBJS) $(ARRAY_OBJS) $(LIST_OBJS) $(EXECS) *~
