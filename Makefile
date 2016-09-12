
default: development

development:
	reasonbuild -package flow_parser Interop.byte
	./Interop.byte libs/bom.js > output/bom-output.txt
	./Interop.byte libs/core.js > output/core-output.txt
	./Interop.byte libs/cssom.js > output/cssom-output.txt
	./Interop.byte libs/dom.js > output/dom-output.txt
	./Interop.byte libs/indexeddb.js > output/indexeddb-output.txt
	./Interop.byte libs/node.js > output/node-output.txt
	./Interop.byte libs/react.js > output/react-output.txt
	cat output/core-output.txt

.PHONY: test default
