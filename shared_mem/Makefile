include ../Makefile.inc

EXE = ${svshm_xfr_reader svshm_xfr_writer}

all : ${EXE}


clean : 
	${RM} ${EXE} *.o

svshm_xfr_reader.o svshm_xfr_writer.o: svshm_xfr.h

showall :
	@ echo ${EXE}

${EXE} : ${TLPI_LIB}		# True as a rough approximation
