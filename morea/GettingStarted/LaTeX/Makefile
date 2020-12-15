LECTURENOTES = $(shell find . -name "*slides.tex" | sed "s/.tex/.pdf/")


TARGETS = $(LECTURENOTES)

default: $(TARGETS)

TEXINPUTS_VAR = :../../LaTeXStyleFiles/

%.pdf: %.tex
	export TEXINPUTS=$(TEXINPUTS_VAR) && pdflatex $< 
	export TEXINPUTS=$(TEXINPUTS_VAR) && pdflatex $< 
	make cleanup


clean: cleanup
	/bin/rm -f $(LECTURENOTES)

cleanup:
	/bin/rm -f *.aux *.nav *.out *.log *.toc *.snm *.vrb *.bak 
