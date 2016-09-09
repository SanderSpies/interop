
default: development

development:
	ocamlbuild -package flow_parser Interop.byte
	./Interop.byte declaration-test.js

.PHONY: test default
