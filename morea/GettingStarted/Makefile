KEYNOTES = $(shell find . -name '*.key' | sed "s/.key/.pdf/")
PAGES = $(shell find . -name '*.pages' | sed "s/.pages/.pdf/")

TARGETS = $(KEYNOTES) $(PAGES) IGNORE LATEX_SLIDES

default: $(TARGETS)

IGNORE:
	@if [ -f "_ignore/Makefile" ]; then  \
	   cd _ignore; make ;\
	fi \

LATEX_SLIDES:
	cd LaTeX; make 

%.pdf: %.key
	keynotetopdf $< 

%.pdf: %.pages
	pagestopdf $<

clean:
	/bin/rm -f $(TARGETS)
