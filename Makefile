
default: development

development:
	reasonbuild -package flow_parser Interop.byte
	./Interop.byte libs/bom.js > output/bom-output.re
	./Interop.byte libs/core.js > output/core-output.re
	./Interop.byte libs/cssom.js > output/cssom-output.re
	./Interop.byte libs/dom.js > output/dom-output.re
	./Interop.byte libs/indexeddb.js > output/indexeddb-output.re
	./Interop.byte libs/node.js > output/node-output.re
	./Interop.byte libs/react.js > output/react-output.re
	cat output/core-output.re
	refmt -parse re -print ml output/bom-output.re > output/bom-output.ml
	refmt -parse re -print ml output/core-output.re > output/core-output.ml
	refmt -parse re -print ml output/cssom-output.re > output/cssom-output.ml
	refmt -parse re -print ml output/dom-output.re > output/dom-output.ml
	refmt -parse re -print ml output/indexeddb-output.re > output/indexeddb-output.ml
	refmt -parse re -print ml output/node-output.re > output/node-output.ml
	refmt -parse re -print ml output/react-output.re > output/react-output.ml
.PHONY: test default
