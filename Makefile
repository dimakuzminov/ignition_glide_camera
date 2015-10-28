export PWD=$(shell pwd)

config:
	cp $(PWD)/scripts/ignition_defconfig $(PWD)/buildroot/configs
	cd $(PWD)/buildroot; make ignition_defconfig

full_build:
	cd $(PWD)/buildroot; make
	cd $(PWD)/ignition; ../buildroot/output/host/usr/bin/qmake
	cd $(PWD)/ignition; make clean
	cd $(PWD)/ignition; make
	cp ignition/ignition buildroot/output/target/usr/bin
	cd $(PWD)/buildroot; make

ignition:
	cd $(PWD)/ignition; make


build:
	cd $(PWD)/buildroot; make
