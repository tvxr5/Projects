DOCs = debugger.tex instr.tex link-load.tex machine.tex
DVIs = debugger.dvi instr.dvi link-load.dvi machine.dvi
PDFs = debugger.pdf instr.pdf link-load.pdf machine.pdf
PSs  = debugger.ps  instr.ps  link-load.ps  machine.ps 

all: $(PSs) $(DVIs) $(PDFs)

clean:
	rm *.dvi *.ps *.pdf

.SUFFIXES: .tex .dvi .ps .pdf
.tex.dvi:
	latex $<
	@ rm $*.aux $*.log
.tex.pdf:
	pdflatex $<
	@ rm $*.aux $*.log
.dvi.ps:
	dvips $< -o
