#
# OMNeT++/OMNEST Makefile for CastaliaBin
#
# This file was generated with the command:
#  opp_makemake -f -r --deep -o CastaliaBin -u Cmdenv -P /home/francesco/Desktop/x-frameworks/asfpp -M release -X Simulations -X out -X bin -I/usr/include/libxml2 -I/usr/include/glibmm-2.4 -I/usr/lib/x86_64-linux-gnu/glibmm-2.4/include -I/usr/include/sigc++-2.0 -I/usr/lib/x86_64-linux-gnu/sigc++-2.0/include -I/usr/include/glib-2.0 -I/usr/lib/x86_64-linux-gnu/glib-2.0/include -I/usr/include/libxml++-2.6 -I/usr/lib/libxml++-2.6/include -lxml++-2.6 -lxml2 -lglibmm-2.4 -lgobject-2.0 -lsigc-2.0 -lglib-2.0
#

# Name of target to be created (-o option)
TARGET = CastaliaBin$(EXE_SUFFIX)

# User interface (uncomment one) (-u option)
#USERIF_LIBS = $(ALL_ENV_LIBS) # that is, $(TKENV_LIBS) $(CMDENV_LIBS)
USERIF_LIBS = $(CMDENV_LIBS)
#USERIF_LIBS = $(TKENV_LIBS)

# C++ include paths (with -I)
INCLUDE_PATH = \
    -I/usr/include/libxml2 \
    -I/usr/include/glibmm-2.4 \
    -I/usr/lib/x86_64-linux-gnu/glibmm-2.4/include \
    -I/usr/include/sigc++-2.0 \
    -I/usr/lib/x86_64-linux-gnu/sigc++-2.0/include \
    -I/usr/include/glib-2.0 \
    -I/usr/lib/x86_64-linux-gnu/glib-2.0/include \
    -I/usr/include/libxml++-2.6 \
    -I/usr/lib/libxml++-2.6/include \
    -I. \
    -Iinterpreter \
    -Iinterpreter/examples \
    -Iinterpreter/examples/advanced-packet-filter \
    -Iinterpreter/examples/change \
    -Iinterpreter/examples/clone \
    -Iinterpreter/examples/conditional-attacks \
    -Iinterpreter/examples/create \
    -Iinterpreter/examples/destroy \
    -Iinterpreter/examples/disable \
    -Iinterpreter/examples/drop \
    -Iinterpreter/examples/expression \
    -Iinterpreter/examples/fakeread \
    -Iinterpreter/examples/move \
    -Iinterpreter/examples/physical-attacks \
    -Iinterpreter/examples/put \
    -Iinterpreter/examples/retrieve \
    -Iinterpreter/examples/send \
    -Iinterpreter/examples/unconditional-attacks \
    -Iinterpreter/interpreter \
    -Iinterpreter/interpreter/attacks \
    -Iinterpreter/interpreter/engine \
    -Iinterpreter/interpreter/grammar \
    -Iinterpreter/interpreter/lexer \
    -Iinterpreter/interpreter/primitives \
    -Isrc \
    -Isrc/actions \
    -Isrc/actions/actionbase \
    -Isrc/actions/asfexpression \
    -Isrc/actions/change \
    -Isrc/actions/clone \
    -Isrc/actions/create \
    -Isrc/actions/destroy \
    -Isrc/actions/disable \
    -Isrc/actions/drop \
    -Isrc/actions/fakeread \
    -Isrc/actions/move \
    -Isrc/actions/put \
    -Isrc/actions/retrieve \
    -Isrc/actions/send \
    -Isrc/attack \
    -Isrc/attack/attackbase \
    -Isrc/attack/conditionalattack \
    -Isrc/attack/conditionalattack/conditionalattack \
    -Isrc/attack/conditionalattack/packetfilter \
    -Isrc/attack/entry \
    -Isrc/attack/phyiscalattack \
    -Isrc/attack/unconditionalattack \
    -Isrc/globalfilter \
    -Isrc/helpStructures \
    -Isrc/logger \
    -Isrc/node \
    -Isrc/node/application \
    -Isrc/node/application/bridgeTest \
    -Isrc/node/application/clusterAggregator \
    -Isrc/node/application/connectivityMap \
    -Isrc/node/application/distanceTest \
    -Isrc/node/application/dummyApplication \
    -Isrc/node/application/roomMonitoring \
    -Isrc/node/application/simpleAggregation \
    -Isrc/node/application/throughputTest \
    -Isrc/node/application/valuePropagation \
    -Isrc/node/application/valueReporting \
    -Isrc/node/communication \
    -Isrc/node/communication/mac \
    -Isrc/node/communication/mac/baselineBanMac \
    -Isrc/node/communication/mac/bypassMac \
    -Isrc/node/communication/mac/mac802154 \
    -Isrc/node/communication/mac/tMac \
    -Isrc/node/communication/mac/tunableMac \
    -Isrc/node/communication/radio \
    -Isrc/node/communication/routing \
    -Isrc/node/communication/routing/aodvRouting \
    -Isrc/node/communication/routing/bypassRouting \
    -Isrc/node/communication/routing/multipathRingsRouting \
    -Isrc/node/localfilter \
    -Isrc/node/mobilityManager \
    -Isrc/node/mobilityManager/lineMobilityManager \
    -Isrc/node/mobilityManager/noMobilityManager \
    -Isrc/node/resourceManager \
    -Isrc/node/sensorManager \
    -Isrc/parser \
    -Isrc/physicalProcess \
    -Isrc/physicalProcess/carsPhysicalProcess \
    -Isrc/physicalProcess/customizablePhysicalProcess \
    -Isrc/utils \
    -Isrc/utils/asfpputils \
    -Isrc/utils/exprtk \
    -Isrc/variable \
    -Isrc/wirelessChannel

# Additional object and library files to link with
EXTRA_OBJS =

# Additional libraries (-L, -l options)
LIBS =  -lxml++-2.6 -lxml2 -lglibmm-2.4 -lgobject-2.0 -lsigc-2.0 -lglib-2.0

# Output directory
PROJECT_OUTPUT_DIR = out
PROJECTRELATIVE_PATH =
O = $(PROJECT_OUTPUT_DIR)/$(CONFIGNAME)/$(PROJECTRELATIVE_PATH)

# Object files for local .cc and .msg files
OBJS = \
    $O/src/PacketTypes.o \
    $O/src/actions/actionbase/Action.o \
    $O/src/actions/asfexpression/ASFExpression.o \
    $O/src/actions/change/Change.o \
    $O/src/actions/clone/Clone.o \
    $O/src/actions/create/Create.o \
    $O/src/actions/destroy/Destroy.o \
    $O/src/actions/disable/Disable.o \
    $O/src/actions/drop/Drop.o \
    $O/src/actions/fakeread/Fakeread.o \
    $O/src/actions/move/Move.o \
    $O/src/actions/put/Put.o \
    $O/src/actions/put/PutMessages.o \
    $O/src/actions/retrieve/Retrieve.o \
    $O/src/actions/send/Send.o \
    $O/src/attack/attackbase/Attack.o \
    $O/src/attack/conditionalattack/conditionalattack/ConditionalAttack.o \
    $O/src/attack/conditionalattack/packetfilter/CompoundBlock.o \
    $O/src/attack/conditionalattack/packetfilter/ElementaryBlock.o \
    $O/src/attack/conditionalattack/packetfilter/FilterBlock.o \
    $O/src/attack/conditionalattack/packetfilter/PacketFilter.o \
    $O/src/attack/entry/Entry.o \
    $O/src/attack/entry/EntryWrapper.o \
    $O/src/attack/phyiscalattack/PhysicalAttack.o \
    $O/src/attack/phyiscalattack/PhysicalAttackWrapper.o \
    $O/src/attack/unconditionalattack/UnconditionalAttack.o \
    $O/src/globalfilter/GlobalFilter.o \
    $O/src/helpStructures/CastaliaModule.o \
    $O/src/helpStructures/DebugInfoWriter.o \
    $O/src/helpStructures/GlobalFilterMessage.o \
    $O/src/helpStructures/LoggerMessage.o \
    $O/src/helpStructures/TimerService.o \
    $O/src/logger/Logger.o \
    $O/src/node/application/VirtualApplication.o \
    $O/src/node/application/bridgeTest/BridgeTest.o \
    $O/src/node/application/clusterAggregator/ClusterAggregator.o \
    $O/src/node/application/connectivityMap/ConnectivityMap.o \
    $O/src/node/application/distanceTest/DistanceTest.o \
    $O/src/node/application/dummyApplication/DummyApplication.o \
    $O/src/node/application/roomMonitoring/RoomMonitoring.o \
    $O/src/node/application/simpleAggregation/SimpleAggregation.o \
    $O/src/node/application/throughputTest/ThroughputTest.o \
    $O/src/node/application/valuePropagation/ValuePropagation.o \
    $O/src/node/application/valueReporting/ValueReporting.o \
    $O/src/node/communication/mac/VirtualMac.o \
    $O/src/node/communication/mac/baselineBanMac/BaselineBANMac.o \
    $O/src/node/communication/mac/bypassMac/BypassMAC.o \
    $O/src/node/communication/mac/mac802154/Mac802154.o \
    $O/src/node/communication/mac/tMac/TMAC.o \
    $O/src/node/communication/mac/tunableMac/TunableMAC.o \
    $O/src/node/communication/radio/Radio.o \
    $O/src/node/communication/radio/RadioSupportFunctions.o \
    $O/src/node/communication/routing/VirtualRouting.o \
    $O/src/node/communication/routing/aodvRouting/AodvRouting.o \
    $O/src/node/communication/routing/aodvRouting/RoutingTable_rt.o \
    $O/src/node/communication/routing/bypassRouting/BypassRouting.o \
    $O/src/node/communication/routing/multipathRingsRouting/MultipathRingsRouting.o \
    $O/src/node/localfilter/LocalFilter.o \
    $O/src/node/mobilityManager/VirtualMobilityManager.o \
    $O/src/node/mobilityManager/lineMobilityManager/LineMobilityManager.o \
    $O/src/node/mobilityManager/noMobilityManager/NoMobilityManager.o \
    $O/src/node/resourceManager/ResourceManager.o \
    $O/src/node/sensorManager/SensorManager.o \
    $O/src/parser/Parser.o \
    $O/src/physicalProcess/carsPhysicalProcess/CarsPhysicalProcess.o \
    $O/src/physicalProcess/customizablePhysicalProcess/CustomizablePhysicalProcess.o \
    $O/src/utils/asfpputils/utils.o \
    $O/src/variable/Variable.o \
    $O/src/wirelessChannel/WirelessChannel.o \
    $O/src/wirelessChannel/WirelessChannelTemporal.o \
    $O/src/actions/destroy/DestroyRequest_m.o \
    $O/src/globalfilter/DestroyFireMessage_m.o \
    $O/src/globalfilter/UnconditionalFireMessage_m.o \
    $O/src/helpStructures/TimerServiceMessage_m.o \
    $O/src/node/application/ApplicationPacket_m.o \
    $O/src/node/application/clusterAggregator/ClusterAggregatorPacket_m.o \
    $O/src/node/application/distanceTest/DistanceTestPacket_m.o \
    $O/src/node/application/roomMonitoring/RoomMonitoringPacket_m.o \
    $O/src/node/application/valueReporting/ValueReportingPacket_m.o \
    $O/src/node/communication/mac/MacPacket_m.o \
    $O/src/node/communication/mac/baselineBanMac/BaselineMacPacket_m.o \
    $O/src/node/communication/mac/mac802154/Mac802154Packet_m.o \
    $O/src/node/communication/mac/tMac/TMacPacket_m.o \
    $O/src/node/communication/mac/tunableMac/TunableMacControl_m.o \
    $O/src/node/communication/mac/tunableMac/TunableMacPacket_m.o \
    $O/src/node/communication/radio/RadioControlMessage_m.o \
    $O/src/node/communication/routing/RoutingPacket_m.o \
    $O/src/node/communication/routing/aodvRouting/AodvRoutingDataPacket_m.o \
    $O/src/node/communication/routing/aodvRouting/AodvRoutingPacket_m.o \
    $O/src/node/communication/routing/aodvRouting/AodvRoutingRrepPacket_m.o \
    $O/src/node/communication/routing/aodvRouting/PacketId_m.o \
    $O/src/node/communication/routing/bypassRouting/BypassRoutingPacket_m.o \
    $O/src/node/communication/routing/multipathRingsRouting/MultipathRingsRoutingControl_m.o \
    $O/src/node/communication/routing/multipathRingsRouting/MultipathRingsRoutingPacket_m.o \
    $O/src/node/mobilityManager/MobilityManagerMessage_m.o \
    $O/src/node/resourceManager/ResourceManagerMessage_m.o \
    $O/src/node/sensorManager/SensorManagerMessage_m.o \
    $O/src/physicalProcess/PhysicalProcessMessage_m.o \
    $O/src/wirelessChannel/WirelessChannelMessages_m.o

# Message files
MSGFILES = \
    src/actions/destroy/DestroyRequest.msg \
    src/globalfilter/DestroyFireMessage.msg \
    src/globalfilter/UnconditionalFireMessage.msg \
    src/helpStructures/TimerServiceMessage.msg \
    src/node/application/ApplicationPacket.msg \
    src/node/application/clusterAggregator/ClusterAggregatorPacket.msg \
    src/node/application/distanceTest/DistanceTestPacket.msg \
    src/node/application/roomMonitoring/RoomMonitoringPacket.msg \
    src/node/application/valueReporting/ValueReportingPacket.msg \
    src/node/communication/mac/MacPacket.msg \
    src/node/communication/mac/baselineBanMac/BaselineMacPacket.msg \
    src/node/communication/mac/mac802154/Mac802154Packet.msg \
    src/node/communication/mac/tMac/TMacPacket.msg \
    src/node/communication/mac/tunableMac/TunableMacControl.msg \
    src/node/communication/mac/tunableMac/TunableMacPacket.msg \
    src/node/communication/radio/RadioControlMessage.msg \
    src/node/communication/routing/RoutingPacket.msg \
    src/node/communication/routing/aodvRouting/AodvRoutingDataPacket.msg \
    src/node/communication/routing/aodvRouting/AodvRoutingPacket.msg \
    src/node/communication/routing/aodvRouting/AodvRoutingRrepPacket.msg \
    src/node/communication/routing/aodvRouting/PacketId.msg \
    src/node/communication/routing/bypassRouting/BypassRoutingPacket.msg \
    src/node/communication/routing/multipathRingsRouting/MultipathRingsRoutingControl.msg \
    src/node/communication/routing/multipathRingsRouting/MultipathRingsRoutingPacket.msg \
    src/node/mobilityManager/MobilityManagerMessage.msg \
    src/node/resourceManager/ResourceManagerMessage.msg \
    src/node/sensorManager/SensorManagerMessage.msg \
    src/physicalProcess/PhysicalProcessMessage.msg \
    src/wirelessChannel/WirelessChannelMessages.msg

# Default mode (-M option); can be overridden with make MODE=debug (or =release)
ifndef MODE
MODE = release
endif

#------------------------------------------------------------------------------

# Pull in OMNeT++ configuration (Makefile.inc or configuser.vc)

ifneq ("$(OMNETPP_CONFIGFILE)","")
CONFIGFILE = $(OMNETPP_CONFIGFILE)
else
ifneq ("$(OMNETPP_ROOT)","")
CONFIGFILE = $(OMNETPP_ROOT)/Makefile.inc
else
CONFIGFILE = $(shell opp_configfilepath)
endif
endif

ifeq ("$(wildcard $(CONFIGFILE))","")
$(error Config file '$(CONFIGFILE)' does not exist -- add the OMNeT++ bin directory to the path so that opp_configfilepath can be found, or set the OMNETPP_CONFIGFILE variable to point to Makefile.inc)
endif

include $(CONFIGFILE)

# Simulation kernel and user interface libraries
OMNETPP_LIB_SUBDIR = $(OMNETPP_LIB_DIR)/$(TOOLCHAIN_NAME)
OMNETPP_LIBS = -L"$(OMNETPP_LIB_SUBDIR)" -L"$(OMNETPP_LIB_DIR)" -loppmain$D $(USERIF_LIBS) $(KERNEL_LIBS) $(SYS_LIBS)

COPTS = $(CFLAGS)  $(INCLUDE_PATH) -I$(OMNETPP_INCL_DIR)
MSGCOPTS = $(INCLUDE_PATH)

# we want to recompile everything if COPTS changes,
# so we store COPTS into $COPTS_FILE and have object
# files depend on it (except when "make depend" was called)
COPTS_FILE = $O/.last-copts
ifneq ($(MAKECMDGOALS),depend)
ifneq ("$(COPTS)","$(shell cat $(COPTS_FILE) 2>/dev/null || echo '')")
$(shell $(MKPATH) "$O" && echo "$(COPTS)" >$(COPTS_FILE))
endif
endif

#------------------------------------------------------------------------------
# User-supplied makefile fragment(s)
# >>>
# <<<
#------------------------------------------------------------------------------

# Main target
all: $O/$(TARGET)
	$(Q)$(LN) $O/$(TARGET) .

$O/$(TARGET): $(OBJS)  $(wildcard $(EXTRA_OBJS)) Makefile
	@$(MKPATH) $O
	@echo Creating executable: $@
	$(Q)$(CXX) $(LDFLAGS) -o $O/$(TARGET)  $(OBJS) $(EXTRA_OBJS) $(AS_NEEDED_OFF) $(WHOLE_ARCHIVE_ON) $(LIBS) $(WHOLE_ARCHIVE_OFF) $(OMNETPP_LIBS)

.PHONY: all clean cleanall depend msgheaders

.SUFFIXES: .cc

$O/%.o: %.cc $(COPTS_FILE)
	@$(MKPATH) $(dir $@)
	$(qecho) "$<"
	$(Q)$(CXX) -c $(CXXFLAGS) $(COPTS) -o $@ $<

%_m.cc %_m.h: %.msg
	$(qecho) MSGC: $<
	$(Q)$(MSGC) -s _m.cc $(MSGCOPTS) $?

msgheaders: $(MSGFILES:.msg=_m.h)

clean:
	$(qecho) Cleaning...
	$(Q)-rm -rf $O
	$(Q)-rm -f CastaliaBin CastaliaBin.exe libCastaliaBin.so libCastaliaBin.a libCastaliaBin.dll libCastaliaBin.dylib
	$(Q)-rm -f ./*_m.cc ./*_m.h
	$(Q)-rm -f interpreter/*_m.cc interpreter/*_m.h
	$(Q)-rm -f interpreter/examples/*_m.cc interpreter/examples/*_m.h
	$(Q)-rm -f interpreter/examples/advanced-packet-filter/*_m.cc interpreter/examples/advanced-packet-filter/*_m.h
	$(Q)-rm -f interpreter/examples/change/*_m.cc interpreter/examples/change/*_m.h
	$(Q)-rm -f interpreter/examples/clone/*_m.cc interpreter/examples/clone/*_m.h
	$(Q)-rm -f interpreter/examples/conditional-attacks/*_m.cc interpreter/examples/conditional-attacks/*_m.h
	$(Q)-rm -f interpreter/examples/create/*_m.cc interpreter/examples/create/*_m.h
	$(Q)-rm -f interpreter/examples/destroy/*_m.cc interpreter/examples/destroy/*_m.h
	$(Q)-rm -f interpreter/examples/disable/*_m.cc interpreter/examples/disable/*_m.h
	$(Q)-rm -f interpreter/examples/drop/*_m.cc interpreter/examples/drop/*_m.h
	$(Q)-rm -f interpreter/examples/expression/*_m.cc interpreter/examples/expression/*_m.h
	$(Q)-rm -f interpreter/examples/fakeread/*_m.cc interpreter/examples/fakeread/*_m.h
	$(Q)-rm -f interpreter/examples/move/*_m.cc interpreter/examples/move/*_m.h
	$(Q)-rm -f interpreter/examples/physical-attacks/*_m.cc interpreter/examples/physical-attacks/*_m.h
	$(Q)-rm -f interpreter/examples/put/*_m.cc interpreter/examples/put/*_m.h
	$(Q)-rm -f interpreter/examples/retrieve/*_m.cc interpreter/examples/retrieve/*_m.h
	$(Q)-rm -f interpreter/examples/send/*_m.cc interpreter/examples/send/*_m.h
	$(Q)-rm -f interpreter/examples/unconditional-attacks/*_m.cc interpreter/examples/unconditional-attacks/*_m.h
	$(Q)-rm -f interpreter/interpreter/*_m.cc interpreter/interpreter/*_m.h
	$(Q)-rm -f interpreter/interpreter/attacks/*_m.cc interpreter/interpreter/attacks/*_m.h
	$(Q)-rm -f interpreter/interpreter/engine/*_m.cc interpreter/interpreter/engine/*_m.h
	$(Q)-rm -f interpreter/interpreter/grammar/*_m.cc interpreter/interpreter/grammar/*_m.h
	$(Q)-rm -f interpreter/interpreter/lexer/*_m.cc interpreter/interpreter/lexer/*_m.h
	$(Q)-rm -f interpreter/interpreter/primitives/*_m.cc interpreter/interpreter/primitives/*_m.h
	$(Q)-rm -f src/*_m.cc src/*_m.h
	$(Q)-rm -f src/actions/*_m.cc src/actions/*_m.h
	$(Q)-rm -f src/actions/actionbase/*_m.cc src/actions/actionbase/*_m.h
	$(Q)-rm -f src/actions/asfexpression/*_m.cc src/actions/asfexpression/*_m.h
	$(Q)-rm -f src/actions/change/*_m.cc src/actions/change/*_m.h
	$(Q)-rm -f src/actions/clone/*_m.cc src/actions/clone/*_m.h
	$(Q)-rm -f src/actions/create/*_m.cc src/actions/create/*_m.h
	$(Q)-rm -f src/actions/destroy/*_m.cc src/actions/destroy/*_m.h
	$(Q)-rm -f src/actions/disable/*_m.cc src/actions/disable/*_m.h
	$(Q)-rm -f src/actions/drop/*_m.cc src/actions/drop/*_m.h
	$(Q)-rm -f src/actions/fakeread/*_m.cc src/actions/fakeread/*_m.h
	$(Q)-rm -f src/actions/move/*_m.cc src/actions/move/*_m.h
	$(Q)-rm -f src/actions/put/*_m.cc src/actions/put/*_m.h
	$(Q)-rm -f src/actions/retrieve/*_m.cc src/actions/retrieve/*_m.h
	$(Q)-rm -f src/actions/send/*_m.cc src/actions/send/*_m.h
	$(Q)-rm -f src/attack/*_m.cc src/attack/*_m.h
	$(Q)-rm -f src/attack/attackbase/*_m.cc src/attack/attackbase/*_m.h
	$(Q)-rm -f src/attack/conditionalattack/*_m.cc src/attack/conditionalattack/*_m.h
	$(Q)-rm -f src/attack/conditionalattack/conditionalattack/*_m.cc src/attack/conditionalattack/conditionalattack/*_m.h
	$(Q)-rm -f src/attack/conditionalattack/packetfilter/*_m.cc src/attack/conditionalattack/packetfilter/*_m.h
	$(Q)-rm -f src/attack/entry/*_m.cc src/attack/entry/*_m.h
	$(Q)-rm -f src/attack/phyiscalattack/*_m.cc src/attack/phyiscalattack/*_m.h
	$(Q)-rm -f src/attack/unconditionalattack/*_m.cc src/attack/unconditionalattack/*_m.h
	$(Q)-rm -f src/globalfilter/*_m.cc src/globalfilter/*_m.h
	$(Q)-rm -f src/helpStructures/*_m.cc src/helpStructures/*_m.h
	$(Q)-rm -f src/logger/*_m.cc src/logger/*_m.h
	$(Q)-rm -f src/node/*_m.cc src/node/*_m.h
	$(Q)-rm -f src/node/application/*_m.cc src/node/application/*_m.h
	$(Q)-rm -f src/node/application/bridgeTest/*_m.cc src/node/application/bridgeTest/*_m.h
	$(Q)-rm -f src/node/application/clusterAggregator/*_m.cc src/node/application/clusterAggregator/*_m.h
	$(Q)-rm -f src/node/application/connectivityMap/*_m.cc src/node/application/connectivityMap/*_m.h
	$(Q)-rm -f src/node/application/distanceTest/*_m.cc src/node/application/distanceTest/*_m.h
	$(Q)-rm -f src/node/application/dummyApplication/*_m.cc src/node/application/dummyApplication/*_m.h
	$(Q)-rm -f src/node/application/roomMonitoring/*_m.cc src/node/application/roomMonitoring/*_m.h
	$(Q)-rm -f src/node/application/simpleAggregation/*_m.cc src/node/application/simpleAggregation/*_m.h
	$(Q)-rm -f src/node/application/throughputTest/*_m.cc src/node/application/throughputTest/*_m.h
	$(Q)-rm -f src/node/application/valuePropagation/*_m.cc src/node/application/valuePropagation/*_m.h
	$(Q)-rm -f src/node/application/valueReporting/*_m.cc src/node/application/valueReporting/*_m.h
	$(Q)-rm -f src/node/communication/*_m.cc src/node/communication/*_m.h
	$(Q)-rm -f src/node/communication/mac/*_m.cc src/node/communication/mac/*_m.h
	$(Q)-rm -f src/node/communication/mac/baselineBanMac/*_m.cc src/node/communication/mac/baselineBanMac/*_m.h
	$(Q)-rm -f src/node/communication/mac/bypassMac/*_m.cc src/node/communication/mac/bypassMac/*_m.h
	$(Q)-rm -f src/node/communication/mac/mac802154/*_m.cc src/node/communication/mac/mac802154/*_m.h
	$(Q)-rm -f src/node/communication/mac/tMac/*_m.cc src/node/communication/mac/tMac/*_m.h
	$(Q)-rm -f src/node/communication/mac/tunableMac/*_m.cc src/node/communication/mac/tunableMac/*_m.h
	$(Q)-rm -f src/node/communication/radio/*_m.cc src/node/communication/radio/*_m.h
	$(Q)-rm -f src/node/communication/routing/*_m.cc src/node/communication/routing/*_m.h
	$(Q)-rm -f src/node/communication/routing/aodvRouting/*_m.cc src/node/communication/routing/aodvRouting/*_m.h
	$(Q)-rm -f src/node/communication/routing/bypassRouting/*_m.cc src/node/communication/routing/bypassRouting/*_m.h
	$(Q)-rm -f src/node/communication/routing/multipathRingsRouting/*_m.cc src/node/communication/routing/multipathRingsRouting/*_m.h
	$(Q)-rm -f src/node/localfilter/*_m.cc src/node/localfilter/*_m.h
	$(Q)-rm -f src/node/mobilityManager/*_m.cc src/node/mobilityManager/*_m.h
	$(Q)-rm -f src/node/mobilityManager/lineMobilityManager/*_m.cc src/node/mobilityManager/lineMobilityManager/*_m.h
	$(Q)-rm -f src/node/mobilityManager/noMobilityManager/*_m.cc src/node/mobilityManager/noMobilityManager/*_m.h
	$(Q)-rm -f src/node/resourceManager/*_m.cc src/node/resourceManager/*_m.h
	$(Q)-rm -f src/node/sensorManager/*_m.cc src/node/sensorManager/*_m.h
	$(Q)-rm -f src/parser/*_m.cc src/parser/*_m.h
	$(Q)-rm -f src/physicalProcess/*_m.cc src/physicalProcess/*_m.h
	$(Q)-rm -f src/physicalProcess/carsPhysicalProcess/*_m.cc src/physicalProcess/carsPhysicalProcess/*_m.h
	$(Q)-rm -f src/physicalProcess/customizablePhysicalProcess/*_m.cc src/physicalProcess/customizablePhysicalProcess/*_m.h
	$(Q)-rm -f src/utils/*_m.cc src/utils/*_m.h
	$(Q)-rm -f src/utils/asfpputils/*_m.cc src/utils/asfpputils/*_m.h
	$(Q)-rm -f src/utils/exprtk/*_m.cc src/utils/exprtk/*_m.h
	$(Q)-rm -f src/variable/*_m.cc src/variable/*_m.h
	$(Q)-rm -f src/wirelessChannel/*_m.cc src/wirelessChannel/*_m.h

cleanall: clean
	$(Q)-rm -rf $(PROJECT_OUTPUT_DIR)

depend:
	$(qecho) Creating dependencies...
	$(Q)$(MAKEDEPEND) $(INCLUDE_PATH) -f Makefile -P\$$O/ -- $(MSG_CC_FILES)  ./*.cc interpreter/*.cc interpreter/examples/*.cc interpreter/examples/advanced-packet-filter/*.cc interpreter/examples/change/*.cc interpreter/examples/clone/*.cc interpreter/examples/conditional-attacks/*.cc interpreter/examples/create/*.cc interpreter/examples/destroy/*.cc interpreter/examples/disable/*.cc interpreter/examples/drop/*.cc interpreter/examples/expression/*.cc interpreter/examples/fakeread/*.cc interpreter/examples/move/*.cc interpreter/examples/physical-attacks/*.cc interpreter/examples/put/*.cc interpreter/examples/retrieve/*.cc interpreter/examples/send/*.cc interpreter/examples/unconditional-attacks/*.cc interpreter/interpreter/*.cc interpreter/interpreter/attacks/*.cc interpreter/interpreter/engine/*.cc interpreter/interpreter/grammar/*.cc interpreter/interpreter/lexer/*.cc interpreter/interpreter/primitives/*.cc src/*.cc src/actions/*.cc src/actions/actionbase/*.cc src/actions/asfexpression/*.cc src/actions/change/*.cc src/actions/clone/*.cc src/actions/create/*.cc src/actions/destroy/*.cc src/actions/disable/*.cc src/actions/drop/*.cc src/actions/fakeread/*.cc src/actions/move/*.cc src/actions/put/*.cc src/actions/retrieve/*.cc src/actions/send/*.cc src/attack/*.cc src/attack/attackbase/*.cc src/attack/conditionalattack/*.cc src/attack/conditionalattack/conditionalattack/*.cc src/attack/conditionalattack/packetfilter/*.cc src/attack/entry/*.cc src/attack/phyiscalattack/*.cc src/attack/unconditionalattack/*.cc src/globalfilter/*.cc src/helpStructures/*.cc src/logger/*.cc src/node/*.cc src/node/application/*.cc src/node/application/bridgeTest/*.cc src/node/application/clusterAggregator/*.cc src/node/application/connectivityMap/*.cc src/node/application/distanceTest/*.cc src/node/application/dummyApplication/*.cc src/node/application/roomMonitoring/*.cc src/node/application/simpleAggregation/*.cc src/node/application/throughputTest/*.cc src/node/application/valuePropagation/*.cc src/node/application/valueReporting/*.cc src/node/communication/*.cc src/node/communication/mac/*.cc src/node/communication/mac/baselineBanMac/*.cc src/node/communication/mac/bypassMac/*.cc src/node/communication/mac/mac802154/*.cc src/node/communication/mac/tMac/*.cc src/node/communication/mac/tunableMac/*.cc src/node/communication/radio/*.cc src/node/communication/routing/*.cc src/node/communication/routing/aodvRouting/*.cc src/node/communication/routing/bypassRouting/*.cc src/node/communication/routing/multipathRingsRouting/*.cc src/node/localfilter/*.cc src/node/mobilityManager/*.cc src/node/mobilityManager/lineMobilityManager/*.cc src/node/mobilityManager/noMobilityManager/*.cc src/node/resourceManager/*.cc src/node/sensorManager/*.cc src/parser/*.cc src/physicalProcess/*.cc src/physicalProcess/carsPhysicalProcess/*.cc src/physicalProcess/customizablePhysicalProcess/*.cc src/utils/*.cc src/utils/asfpputils/*.cc src/utils/exprtk/*.cc src/variable/*.cc src/wirelessChannel/*.cc

# DO NOT DELETE THIS LINE -- make depend depends on it.
$O/src/PacketTypes.o: src/PacketTypes.cc \
  src/PacketTypes.h \
  src/node/communication/routing/RoutingPacket_m.h \
  src/node/communication/routing/aodvRouting/AodvRoutingDataPacket_m.h \
  src/node/application/roomMonitoring/RoomMonitoringPacket_m.h \
  src/node/communication/mac/tunableMac/TunableMacPacket_m.h \
  src/node/communication/routing/multipathRingsRouting/MultipathRingsRoutingPacket_m.h \
  src/node/communication/mac/baselineBanMac/BaselineMacPacket_m.h \
  src/node/communication/mac/tMac/TMacPacket_m.h \
  src/node/communication/mac/MacPacket_m.h \
  src/node/application/ApplicationPacket_m.h \
  src/node/communication/routing/aodvRouting/AodvRoutingRrepPacket_m.h \
  src/node/communication/routing/aodvRouting/AodvRoutingPacket_m.h \
  src/node/communication/routing/bypassRouting/BypassRoutingPacket_m.h \
  src/node/communication/mac/mac802154/Mac802154Packet_m.h \
  src/node/application/distanceTest/DistanceTestPacket_m.h \
  src/node/application/valueReporting/ValueReportingPacket_m.h \
  src/node/application/clusterAggregator/ClusterAggregatorPacket_m.h \
  src/node/communication/routing/aodvRouting/PacketId_m.h
$O/src/actions/actionbase/Action.o: src/actions/actionbase/Action.cc \
  src/helpStructures/CastaliaModule.h \
  src/CastaliaMessages.h \
  src/helpStructures/DebugInfoWriter.h \
  src/actions/actionbase/Action.h \
  src/node/resourceManager/ResourceManagerMessage_m.h
$O/src/actions/asfexpression/ASFExpression.o: src/actions/asfexpression/ASFExpression.cc \
  src/helpStructures/CastaliaModule.h \
  src/actions/asfexpression/ASFExpression.h \
  src/node/communication/mac/mac802154/Mac802154Packet_m.h \
  src/variable/Variable.h \
  src/utils/asfpputils/utils.h \
  src/node/communication/routing/RoutingPacket_m.h \
  src/node/resourceManager/ResourceManagerMessage_m.h \
  src/actions/actionbase/Action.h \
  src/node/communication/routing/multipathRingsRouting/MultipathRingsRoutingPacket_m.h \
  src/CastaliaMessages.h \
  src/node/communication/mac/MacPacket_m.h \
  src/helpStructures/DebugInfoWriter.h
$O/src/actions/change/Change.o: src/actions/change/Change.cc \
  src/node/communication/routing/multipathRingsRouting/MultipathRingsRoutingPacket_m.h \
  src/node/mobilityManager/VirtualMobilityManager.h \
  src/wirelessChannel/WirelessChannelMessages_m.h \
  src/helpStructures/DebugInfoWriter.h \
  src/node/communication/mac/MacPacket_m.h \
  src/CastaliaMessages.h \
  src/node/resourceManager/ResourceManagerMessage_m.h \
  src/node/communication/routing/RoutingPacket_m.h \
  src/physicalProcess/PhysicalProcessMessage_m.h \
  src/actions/actionbase/Action.h \
  src/node/sensorManager/SensorManager.h \
  src/actions/change/Change.h \
  src/utils/asfpputils/utils.h \
  src/node/sensorManager/SensorManagerMessage_m.h \
  src/helpStructures/CastaliaModule.h \
  src/node/communication/mac/mac802154/Mac802154Packet_m.h
$O/src/actions/clone/Clone.o: src/actions/clone/Clone.cc \
  src/CastaliaMessages.h \
  src/node/communication/mac/MacPacket_m.h \
  src/helpStructures/DebugInfoWriter.h \
  src/node/communication/routing/multipathRingsRouting/MultipathRingsRoutingPacket_m.h \
  src/actions/actionbase/Action.h \
  src/node/resourceManager/ResourceManagerMessage_m.h \
  src/node/communication/routing/RoutingPacket_m.h \
  src/actions/clone/Clone.h \
  src/utils/asfpputils/utils.h \
  src/node/communication/mac/mac802154/Mac802154Packet_m.h \
  src/helpStructures/CastaliaModule.h
$O/src/actions/create/Create.o: src/actions/create/Create.cc \
  src/PacketTypes.h \
  src/node/resourceManager/ResourceManagerMessage_m.h \
  src/node/communication/routing/RoutingPacket_m.h \
  src/node/communication/routing/aodvRouting/AodvRoutingDataPacket_m.h \
  src/node/application/roomMonitoring/RoomMonitoringPacket_m.h \
  src/actions/actionbase/Action.h \
  src/node/communication/mac/tunableMac/TunableMacPacket_m.h \
  src/node/communication/mac/baselineBanMac/BaselineMacPacket_m.h \
  src/node/communication/routing/multipathRingsRouting/MultipathRingsRoutingPacket_m.h \
  src/node/communication/mac/tMac/TMacPacket_m.h \
  src/node/application/ApplicationPacket_m.h \
  src/node/communication/mac/MacPacket_m.h \
  src/CastaliaMessages.h \
  src/helpStructures/DebugInfoWriter.h \
  src/helpStructures/CastaliaModule.h \
  src/node/communication/routing/aodvRouting/AodvRoutingPacket_m.h \
  src/node/communication/routing/aodvRouting/AodvRoutingRrepPacket_m.h \
  src/node/communication/routing/bypassRouting/BypassRoutingPacket_m.h \
  src/node/communication/mac/mac802154/Mac802154Packet_m.h \
  src/node/application/distanceTest/DistanceTestPacket_m.h \
  src/node/application/valueReporting/ValueReportingPacket_m.h \
  src/node/application/clusterAggregator/ClusterAggregatorPacket_m.h \
  src/node/communication/routing/aodvRouting/PacketId_m.h \
  src/actions/create/Create.h \
  src/utils/asfpputils/utils.h
$O/src/actions/destroy/Destroy.o: src/actions/destroy/Destroy.cc \
  src/helpStructures/CastaliaModule.h \
  src/helpStructures/DebugInfoWriter.h \
  src/CastaliaMessages.h \
  src/actions/destroy/Destroy.h \
  src/actions/actionbase/Action.h \
  src/node/resourceManager/ResourceManagerMessage_m.h
$O/src/actions/disable/Disable.o: src/actions/disable/Disable.cc \
  src/helpStructures/CastaliaModule.h \
  src/actions/disable/Disable.h \
  src/CastaliaMessages.h \
  src/helpStructures/DebugInfoWriter.h \
  src/actions/actionbase/Action.h \
  src/node/resourceManager/ResourceManagerMessage_m.h
$O/src/actions/drop/Drop.o: src/actions/drop/Drop.cc \
  src/CastaliaMessages.h \
  src/helpStructures/DebugInfoWriter.h \
  src/actions/actionbase/Action.h \
  src/node/resourceManager/ResourceManagerMessage_m.h \
  src/actions/drop/Drop.h \
  src/helpStructures/CastaliaModule.h
$O/src/actions/fakeread/Fakeread.o: src/actions/fakeread/Fakeread.cc \
  src/actions/fakeread/Fakeread.h \
  src/helpStructures/CastaliaModule.h \
  src/node/sensorManager/SensorManagerMessage_m.h \
  src/CastaliaMessages.h \
  src/helpStructures/DebugInfoWriter.h \
  src/utils/exprtk/exprtk.hpp \
  src/actions/actionbase/Action.h \
  src/node/resourceManager/ResourceManagerMessage_m.h
$O/src/actions/move/Move.o: src/actions/move/Move.cc \
  src/helpStructures/CastaliaModule.h \
  src/wirelessChannel/WirelessChannelMessages_m.h \
  src/helpStructures/DebugInfoWriter.h \
  src/CastaliaMessages.h \
  src/node/mobilityManager/VirtualMobilityManager.h \
  src/actions/actionbase/Action.h \
  src/actions/move/Move.h \
  src/node/resourceManager/ResourceManagerMessage_m.h
$O/src/actions/put/Put.o: src/actions/put/Put.cc \
  src/utils/asfpputils/utils.h \
  src/actions/put/PutMessages.h \
  src/helpStructures/CastaliaModule.h \
  src/actions/put/Put.h \
  src/node/communication/mac/mac802154/Mac802154Packet_m.h \
  src/node/communication/routing/multipathRingsRouting/MultipathRingsRoutingPacket_m.h \
  src/wirelessChannel/WirelessChannelMessages_m.h \
  src/helpStructures/DebugInfoWriter.h \
  src/node/communication/mac/MacPacket_m.h \
  src/CastaliaMessages.h \
  src/node/resourceManager/ResourceManagerMessage_m.h \
  src/node/communication/routing/RoutingPacket_m.h \
  src/actions/actionbase/Action.h
$O/src/actions/put/PutMessages.o: src/actions/put/PutMessages.cc \
  src/actions/put/PutMessages.h \
  src/utils/asfpputils/utils.h \
  src/node/communication/mac/mac802154/Mac802154Packet_m.h \
  src/helpStructures/CastaliaModule.h \
  src/CastaliaMessages.h \
  src/node/communication/mac/MacPacket_m.h \
  src/helpStructures/DebugInfoWriter.h \
  src/node/communication/routing/multipathRingsRouting/MultipathRingsRoutingPacket_m.h \
  src/node/resourceManager/ResourceManagerMessage_m.h \
  src/node/communication/routing/RoutingPacket_m.h
$O/src/actions/retrieve/Retrieve.o: src/actions/retrieve/Retrieve.cc \
  src/node/communication/mac/mac802154/Mac802154Packet_m.h \
  src/helpStructures/CastaliaModule.h \
  src/variable/Variable.h \
  src/utils/asfpputils/utils.h \
  src/actions/actionbase/Action.h \
  src/node/communication/routing/RoutingPacket_m.h \
  src/node/resourceManager/ResourceManagerMessage_m.h \
  src/actions/retrieve/Retrieve.h \
  src/helpStructures/DebugInfoWriter.h \
  src/CastaliaMessages.h \
  src/node/communication/mac/MacPacket_m.h \
  src/node/communication/routing/multipathRingsRouting/MultipathRingsRoutingPacket_m.h
$O/src/actions/send/Send.o: src/actions/send/Send.cc \
  src/node/mobilityManager/VirtualMobilityManager.h \
  src/node/communication/routing/multipathRingsRouting/MultipathRingsRoutingPacket_m.h \
  src/helpStructures/DebugInfoWriter.h \
  src/wirelessChannel/WirelessChannelMessages_m.h \
  src/CastaliaMessages.h \
  src/node/communication/mac/MacPacket_m.h \
  src/node/communication/routing/RoutingPacket_m.h \
  src/node/resourceManager/ResourceManagerMessage_m.h \
  src/physicalProcess/PhysicalProcessMessage_m.h \
  src/node/sensorManager/SensorManager.h \
  src/actions/actionbase/Action.h \
  src/actions/send/Send.h \
  src/utils/asfpputils/utils.h \
  src/node/sensorManager/SensorManagerMessage_m.h \
  src/helpStructures/CastaliaModule.h \
  src/node/communication/mac/mac802154/Mac802154Packet_m.h
$O/src/attack/attackbase/Attack.o: src/attack/attackbase/Attack.cc \
  src/node/communication/routing/RoutingPacket_m.h \
  src/node/resourceManager/ResourceManagerMessage_m.h \
  src/actions/actionbase/Action.h \
  src/node/communication/routing/multipathRingsRouting/MultipathRingsRoutingPacket_m.h \
  src/node/communication/mac/MacPacket_m.h \
  src/CastaliaMessages.h \
  src/helpStructures/DebugInfoWriter.h \
  src/helpStructures/CastaliaModule.h \
  src/node/communication/mac/mac802154/Mac802154Packet_m.h \
  src/attack/attackbase/Attack.h \
  src/variable/Variable.h \
  src/utils/asfpputils/utils.h
$O/src/attack/conditionalattack/conditionalattack/ConditionalAttack.o: src/attack/conditionalattack/conditionalattack/ConditionalAttack.cc \
  src/attack/conditionalattack/packetfilter/PacketFilter.h \
  src/node/resourceManager/ResourceManagerMessage_m.h \
  src/node/communication/mac/tunableMac/TunableMacPacket_m.h \
  src/node/sensorManager/SensorManager.h \
  src/node/application/roomMonitoring/RoomMonitoringPacket_m.h \
  src/node/mobilityManager/VirtualMobilityManager.h \
  src/node/communication/mac/baselineBanMac/BaselineMacPacket_m.h \
  src/node/communication/routing/multipathRingsRouting/MultipathRingsRoutingPacket_m.h \
  src/wirelessChannel/WirelessChannelMessages_m.h \
  src/CastaliaMessages.h \
  src/node/application/ApplicationPacket_m.h \
  src/node/communication/routing/bypassRouting/BypassRoutingPacket_m.h \
  src/node/sensorManager/SensorManagerMessage_m.h \
  src/node/communication/routing/aodvRouting/AodvRoutingRrepPacket_m.h \
  src/helpStructures/CastaliaModule.h \
  src/actions/put/Put.h \
  src/actions/asfexpression/ASFExpression.h \
  src/node/communication/mac/mac802154/Mac802154Packet_m.h \
  src/actions/drop/Drop.h \
  src/attack/conditionalattack/packetfilter/FilterBlock.h \
  src/actions/send/Send.h \
  src/utils/asfpputils/utils.h \
  src/node/communication/routing/RoutingPacket_m.h \
  src/PacketTypes.h \
  src/physicalProcess/PhysicalProcessMessage_m.h \
  src/actions/retrieve/Retrieve.h \
  src/actions/actionbase/Action.h \
  src/actions/change/Change.h \
  src/node/communication/routing/aodvRouting/AodvRoutingDataPacket_m.h \
  src/node/communication/mac/tMac/TMacPacket_m.h \
  src/helpStructures/DebugInfoWriter.h \
  src/node/communication/mac/MacPacket_m.h \
  src/node/communication/routing/aodvRouting/AodvRoutingPacket_m.h \
  src/node/application/valueReporting/ValueReportingPacket_m.h \
  src/node/application/distanceTest/DistanceTestPacket_m.h \
  src/attack/attackbase/Attack.h \
  src/node/communication/routing/aodvRouting/PacketId_m.h \
  src/node/application/clusterAggregator/ClusterAggregatorPacket_m.h \
  src/actions/clone/Clone.h \
  src/variable/Variable.h \
  src/attack/conditionalattack/conditionalattack/ConditionalAttack.h \
  src/actions/put/PutMessages.h \
  src/actions/create/Create.h
$O/src/attack/conditionalattack/packetfilter/CompoundBlock.o: src/attack/conditionalattack/packetfilter/CompoundBlock.cc \
  src/helpStructures/DebugInfoWriter.h \
  src/node/communication/mac/MacPacket_m.h \
  src/node/communication/routing/RoutingPacket_m.h \
  src/attack/conditionalattack/packetfilter/CompoundBlock.h \
  src/CastaliaMessages.h \
  src/node/communication/routing/multipathRingsRouting/MultipathRingsRoutingPacket_m.h \
  src/node/resourceManager/ResourceManagerMessage_m.h \
  src/attack/conditionalattack/packetfilter/FilterBlock.h \
  src/utils/asfpputils/utils.h \
  src/node/communication/mac/mac802154/Mac802154Packet_m.h \
  src/helpStructures/CastaliaModule.h
$O/src/attack/conditionalattack/packetfilter/ElementaryBlock.o: src/attack/conditionalattack/packetfilter/ElementaryBlock.cc \
  src/helpStructures/DebugInfoWriter.h \
  src/node/communication/mac/MacPacket_m.h \
  src/attack/conditionalattack/packetfilter/ElementaryBlock.h \
  src/node/communication/routing/RoutingPacket_m.h \
  src/utils/asfpputils/utils.h \
  src/attack/conditionalattack/packetfilter/FilterBlock.h \
  src/node/communication/mac/mac802154/Mac802154Packet_m.h \
  src/helpStructures/CastaliaModule.h \
  src/CastaliaMessages.h \
  src/node/communication/routing/multipathRingsRouting/MultipathRingsRoutingPacket_m.h \
  src/node/resourceManager/ResourceManagerMessage_m.h
$O/src/attack/conditionalattack/packetfilter/FilterBlock.o: src/attack/conditionalattack/packetfilter/FilterBlock.cc \
  src/attack/conditionalattack/packetfilter/FilterBlock.h \
  src/helpStructures/CastaliaModule.h \
  src/CastaliaMessages.h \
  src/node/resourceManager/ResourceManagerMessage_m.h \
  src/helpStructures/DebugInfoWriter.h
$O/src/attack/conditionalattack/packetfilter/PacketFilter.o: src/attack/conditionalattack/packetfilter/PacketFilter.cc \
  src/node/communication/mac/MacPacket_m.h \
  src/helpStructures/DebugInfoWriter.h \
  src/attack/conditionalattack/packetfilter/ElementaryBlock.h \
  src/node/communication/routing/RoutingPacket_m.h \
  src/attack/conditionalattack/packetfilter/CompoundBlock.h \
  src/CastaliaMessages.h \
  src/node/communication/routing/multipathRingsRouting/MultipathRingsRoutingPacket_m.h \
  src/attack/conditionalattack/packetfilter/PacketFilter.h \
  src/node/resourceManager/ResourceManagerMessage_m.h \
  src/attack/conditionalattack/packetfilter/FilterBlock.h \
  src/utils/asfpputils/utils.h \
  src/node/communication/mac/mac802154/Mac802154Packet_m.h \
  src/helpStructures/CastaliaModule.h
$O/src/attack/entry/Entry.o: src/attack/entry/Entry.cc \
  src/attack/attackbase/Attack.h \
  src/variable/Variable.h \
  src/actions/actionbase/Action.h \
  src/node/communication/routing/RoutingPacket_m.h \
  src/helpStructures/DebugInfoWriter.h \
  src/node/communication/mac/MacPacket_m.h \
  src/node/communication/mac/mac802154/Mac802154Packet_m.h \
  src/attack/entry/Entry.h \
  src/helpStructures/CastaliaModule.h \
  src/utils/asfpputils/utils.h \
  src/node/resourceManager/ResourceManagerMessage_m.h \
  src/CastaliaMessages.h \
  src/node/communication/routing/multipathRingsRouting/MultipathRingsRoutingPacket_m.h
$O/src/attack/entry/EntryWrapper.o: src/attack/entry/EntryWrapper.cc \
  src/node/resourceManager/ResourceManagerMessage_m.h \
  src/CastaliaMessages.h \
  src/node/communication/routing/multipathRingsRouting/MultipathRingsRoutingPacket_m.h \
  src/node/communication/mac/mac802154/Mac802154Packet_m.h \
  src/helpStructures/CastaliaModule.h \
  src/attack/entry/Entry.h \
  src/utils/asfpputils/utils.h \
  src/actions/actionbase/Action.h \
  src/node/communication/routing/RoutingPacket_m.h \
  src/node/communication/mac/MacPacket_m.h \
  src/helpStructures/DebugInfoWriter.h \
  src/attack/attackbase/Attack.h \
  src/variable/Variable.h \
  src/attack/entry/EntryWrapper.h
$O/src/attack/phyiscalattack/PhysicalAttack.o: src/attack/phyiscalattack/PhysicalAttack.cc \
  src/wirelessChannel/WirelessChannelMessages_m.h \
  src/CastaliaMessages.h \
  src/node/mobilityManager/VirtualMobilityManager.h \
  src/node/communication/routing/multipathRingsRouting/MultipathRingsRoutingPacket_m.h \
  src/actions/destroy/Destroy.h \
  src/node/resourceManager/ResourceManagerMessage_m.h \
  src/utils/asfpputils/utils.h \
  src/node/communication/mac/mac802154/Mac802154Packet_m.h \
  src/actions/disable/Disable.h \
  src/helpStructures/CastaliaModule.h \
  src/helpStructures/DebugInfoWriter.h \
  src/node/communication/mac/MacPacket_m.h \
  src/actions/actionbase/Action.h \
  src/attack/phyiscalattack/PhysicalAttack.h \
  src/node/communication/routing/RoutingPacket_m.h \
  src/actions/move/Move.h \
  src/variable/Variable.h \
  src/attack/attackbase/Attack.h
$O/src/attack/phyiscalattack/PhysicalAttackWrapper.o: src/attack/phyiscalattack/PhysicalAttackWrapper.cc \
  src/node/resourceManager/ResourceManagerMessage_m.h \
  src/CastaliaMessages.h \
  src/node/communication/routing/multipathRingsRouting/MultipathRingsRoutingPacket_m.h \
  src/node/communication/mac/mac802154/Mac802154Packet_m.h \
  src/helpStructures/CastaliaModule.h \
  src/utils/asfpputils/utils.h \
  src/attack/phyiscalattack/PhysicalAttackWrapper.h \
  src/actions/actionbase/Action.h \
  src/attack/phyiscalattack/PhysicalAttack.h \
  src/node/communication/routing/RoutingPacket_m.h \
  src/helpStructures/DebugInfoWriter.h \
  src/node/communication/mac/MacPacket_m.h \
  src/attack/attackbase/Attack.h \
  src/variable/Variable.h
$O/src/attack/unconditionalattack/UnconditionalAttack.o: src/attack/unconditionalattack/UnconditionalAttack.cc \
  src/attack/unconditionalattack/UnconditionalAttack.h \
  src/actions/create/Create.h \
  src/actions/put/PutMessages.h \
  src/actions/clone/Clone.h \
  src/variable/Variable.h \
  src/node/communication/routing/aodvRouting/PacketId_m.h \
  src/node/application/clusterAggregator/ClusterAggregatorPacket_m.h \
  src/node/application/valueReporting/ValueReportingPacket_m.h \
  src/node/application/distanceTest/DistanceTestPacket_m.h \
  src/attack/attackbase/Attack.h \
  src/node/communication/routing/aodvRouting/AodvRoutingPacket_m.h \
  src/node/communication/mac/MacPacket_m.h \
  src/helpStructures/DebugInfoWriter.h \
  src/node/communication/mac/tMac/TMacPacket_m.h \
  src/actions/change/Change.h \
  src/node/communication/routing/aodvRouting/AodvRoutingDataPacket_m.h \
  src/actions/actionbase/Action.h \
  src/physicalProcess/PhysicalProcessMessage_m.h \
  src/actions/retrieve/Retrieve.h \
  src/PacketTypes.h \
  src/node/communication/routing/RoutingPacket_m.h \
  src/actions/send/Send.h \
  src/utils/asfpputils/utils.h \
  src/node/communication/mac/mac802154/Mac802154Packet_m.h \
  src/actions/asfexpression/ASFExpression.h \
  src/actions/drop/Drop.h \
  src/actions/put/Put.h \
  src/helpStructures/CastaliaModule.h \
  src/node/communication/routing/bypassRouting/BypassRoutingPacket_m.h \
  src/node/communication/routing/aodvRouting/AodvRoutingRrepPacket_m.h \
  src/node/sensorManager/SensorManagerMessage_m.h \
  src/CastaliaMessages.h \
  src/node/application/ApplicationPacket_m.h \
  src/wirelessChannel/WirelessChannelMessages_m.h \
  src/node/mobilityManager/VirtualMobilityManager.h \
  src/node/communication/mac/baselineBanMac/BaselineMacPacket_m.h \
  src/node/communication/routing/multipathRingsRouting/MultipathRingsRoutingPacket_m.h \
  src/node/application/roomMonitoring/RoomMonitoringPacket_m.h \
  src/node/communication/mac/tunableMac/TunableMacPacket_m.h \
  src/node/sensorManager/SensorManager.h \
  src/node/resourceManager/ResourceManagerMessage_m.h
$O/src/globalfilter/GlobalFilter.o: src/globalfilter/GlobalFilter.cc \
  /usr/include/glib-2.0/glib/ghook.h \
  /usr/include/glib-2.0/glib/gqsort.h \
  /usr/include/libxml++-2.6/libxml++/nodes/element.h \
  /usr/include/glib-2.0/glib/ghostutils.h \
  /usr/include/libxml++-2.6/libxml++/parsers/textreader.h \
  /usr/include/glib-2.0/glib/gvariant.h \
  /usr/include/glib-2.0/glib/gversionmacros.h \
  /usr/include/glib-2.0/glib/gpattern.h \
  /usr/include/glib-2.0/glib/gerror.h \
  /usr/include/glibmm-2.4/glibmm/unicode.h \
  /usr/include/glib-2.0/glib/gkeyfile.h \
  src/attack/conditionalattack/packetfilter/FilterBlock.h \
  /usr/include/glib-2.0/glib/ghash.h \
  src/node/communication/routing/aodvRouting/AodvRoutingRrepPacket_m.h \
  /usr/include/glib-2.0/glib/gslist.h \
  src/actions/drop/Drop.h \
  src/node/communication/mac/mac802154/Mac802154Packet_m.h \
  src/actions/asfexpression/ASFExpression.h \
  src/node/communication/mac/tMac/TMacPacket_m.h \
  /usr/include/glib-2.0/glib/ggettext.h \
  /usr/include/glib-2.0/glib/gstringchunk.h \
  /usr/include/glib-2.0/glib/deprecated/grel.h \
  /usr/include/libxml++-2.6/libxml++/document.h \
  /usr/include/glib-2.0/glib/gstrfuncs.h \
  /usr/include/glib-2.0/glib/gspawn.h \
  /usr/include/glib-2.0/glib/gpoll.h \
  src/node/communication/routing/RoutingPacket_m.h \
  /usr/include/libxml++-2.6/libxml++/nodes/entityreference.h \
  /usr/include/glibmm-2.4/glibmm/ustring.h \
  /usr/include/glib-2.0/glib/gstring.h \
  /usr/include/glib-2.0/glib/ghmac.h \
  /usr/include/glib-2.0/glib/grand.h \
  /usr/include/glib-2.0/glib/gthreadpool.h \
  src/attack/entry/EntryWrapper.h \
  src/globalfilter/UnconditionalFireMessage_m.h \
  src/actions/put/PutMessages.h \
  src/attack/unconditionalattack/UnconditionalAttack.h \
  /usr/include/libxml++-2.6/libxml++/nodes/contentnode.h \
  /usr/include/libxml++-2.6/libxml++/nodes/processinginstructionnode.h \
  /usr/include/glib-2.0/glib/gtree.h \
  /usr/include/glib-2.0/glib/gdatetime.h \
  /usr/include/libxml++-2.6/libxml++/exceptions/internal_error.h \
  src/node/application/valueReporting/ValueReportingPacket_m.h \
  /usr/include/libxml++-2.6/libxml++/parsers/domparser.h \
  /usr/include/glib-2.0/glib/giochannel.h \
  /usr/include/libxml++-2.6/libxml++/exceptions/exception.h \
  /usr/include/libxml++-2.6/libxml++/noncopyable.h \
  /usr/include/glib-2.0/glib/gdir.h \
  src/wirelessChannel/WirelessChannelMessages_m.h \
  /usr/include/glib-2.0/glib/gmem.h \
  /usr/include/glib-2.0/glib/gqueue.h \
  /usr/include/glib-2.0/glib/gasyncqueue.h \
  /usr/include/libxml++-2.6/libxml++/nodes/entitydeclaration.h \
  src/node/communication/mac/tunableMac/TunableMacPacket_m.h \
  /usr/include/glib-2.0/glib.h \
  /usr/include/glib-2.0/glib/gvarianttype.h \
  /usr/include/glib-2.0/glib/gutils.h \
  /usr/include/glib-2.0/glib/gtimer.h \
  src/actions/send/Send.h \
  /usr/include/glib-2.0/glib/gbytes.h \
  /usr/include/glib-2.0/glib/gtestutils.h \
  /usr/include/libxml++-2.6/libxml++/validators/validator.h \
  /usr/include/libxml++-2.6/libxml++/exceptions/parse_error.h \
  /usr/include/glib-2.0/glib/gslice.h \
  /usr/include/libxml++-2.6/libxml++/attributedeclaration.h \
  src/helpStructures/CastaliaModule.h \
  /usr/lib/x86_64-linux-gnu/glib-2.0/include/glibconfig.h \
  src/node/communication/routing/bypassRouting/BypassRoutingPacket_m.h \
  /usr/include/glib-2.0/glib/gnode.h \
  /usr/include/glib-2.0/glib/goption.h \
  /usr/include/libxml++-2.6/libxml++/attribute.h \
  /usr/lib/libxml++-2.6/include/libxml++config.h \
  /usr/include/glib-2.0/glib/genviron.h \
  src/helpStructures/DebugInfoWriter.h \
  /usr/include/libxml++-2.6/libxml++/libxml++.h \
  /usr/include/libxml++-2.6/libxml++/schema.h \
  /usr/include/glib-2.0/glib/garray.h \
  src/physicalProcess/PhysicalProcessMessage_m.h \
  src/actions/retrieve/Retrieve.h \
  /usr/include/glib-2.0/glib/gsequence.h \
  /usr/include/glib-2.0/glib/deprecated/gthread.h \
  /usr/include/glib-2.0/glib/gchecksum.h \
  src/actions/change/Change.h \
  src/node/communication/routing/aodvRouting/AodvRoutingDataPacket_m.h \
  /usr/include/glib-2.0/glib/gconvert.h \
  /usr/include/glib-2.0/glib/gtypes.h \
  /usr/include/glib-2.0/glib/gshell.h \
  src/attack/conditionalattack/conditionalattack/ConditionalAttack.h \
  src/variable/Variable.h \
  /usr/include/glib-2.0/glib/deprecated/gcache.h \
  src/parser/Parser.h \
  src/node/communication/routing/multipathRingsRouting/MultipathRingsRoutingPacket_m.h \
  src/node/mobilityManager/VirtualMobilityManager.h \
  /usr/include/glib-2.0/glib/gdate.h \
  /usr/include/libxml++-2.6/libxml++/attributenode.h \
  /usr/include/glib-2.0/glib/deprecated/gmain.h \
  /usr/include/glib-2.0/glib/gwin32.h \
  src/node/resourceManager/ResourceManagerMessage_m.h \
  src/actions/destroy/DestroyRequest_m.h \
  src/node/application/roomMonitoring/RoomMonitoringPacket_m.h \
  /usr/include/libxml++-2.6/libxml++/exceptions/validity_error.h \
  /usr/include/glib-2.0/glib/gurifuncs.h \
  src/globalfilter/GlobalFilter.h \
  /usr/include/glib-2.0/glib/gtrashstack.h \
  src/utils/asfpputils/utils.h \
  /usr/include/glib-2.0/glib/gmain.h \
  /usr/include/glib-2.0/glib/deprecated/gallocator.h \
  /usr/include/glib-2.0/glib/gquark.h \
  /usr/include/glib-2.0/glib/galloca.h \
  /usr/include/libxml++-2.6/libxml++/nodes/commentnode.h \
  /usr/include/glib-2.0/glib/gbase64.h \
  /usr/include/glib-2.0/glib/gdataset.h \
  src/PacketTypes.h \
  /usr/include/glib-2.0/glib/gtimezone.h \
  /usr/include/libxml++-2.6/libxml++/nodes/node.h \
  /usr/include/glib-2.0/glib/gprimes.h \
  src/node/communication/routing/aodvRouting/PacketId_m.h \
  src/globalfilter/DestroyFireMessage_m.h \
  src/actions/create/Create.h \
  /usr/include/libxml++-2.6/libxml++/validators/dtdvalidator.h \
  /usr/include/libxml++-2.6/libxml++/validators/schemavalidator.h \
  /usr/include/glib-2.0/glib/gbitlock.h \
  src/actions/clone/Clone.h \
  /usr/include/glib-2.0/glib/gbacktrace.h \
  /usr/include/libxml++-2.6/libxml++/parsers/saxparser.h \
  src/attack/attackbase/Attack.h \
  src/node/communication/mac/baselineBanMac/BaselineMacPacket_m.h \
  src/node/application/ApplicationPacket_m.h \
  src/CastaliaMessages.h \
  src/attack/conditionalattack/packetfilter/PacketFilter.h \
  /usr/include/glib-2.0/glib/gmacros.h \
  /usr/include/glib-2.0/glib/gmappedfile.h \
  src/node/sensorManager/SensorManager.h \
  src/attack/phyiscalattack/PhysicalAttackWrapper.h \
  /usr/include/libxml++-2.6/libxml++/nodes/xincludeend.h \
  /usr/include/glib-2.0/glib/gregex.h \
  /usr/lib/x86_64-linux-gnu/glibmm-2.4/include/glibmmconfig.h \
  /usr/include/glib-2.0/glib/gunicode.h \
  src/attack/entry/Entry.h \
  /usr/include/glib-2.0/glib/gmessages.h \
  src/node/sensorManager/SensorManagerMessage_m.h \
  /usr/include/glib-2.0/glib/gatomic.h \
  /usr/include/glib-2.0/glib/gscanner.h \
  src/actions/put/Put.h \
  /usr/include/libxml++-2.6/libxml++/nodes/xincludestart.h \
  /usr/include/glib-2.0/glib/gfileutils.h \
  src/node/communication/mac/MacPacket_m.h \
  /usr/include/glib-2.0/glib/gmarkup.h \
  src/attack/phyiscalattack/PhysicalAttack.h \
  /usr/include/glib-2.0/glib/glist.h \
  src/actions/actionbase/Action.h \
  /usr/include/libxml++-2.6/libxml++/nodes/textnode.h \
  src/node/application/clusterAggregator/ClusterAggregatorPacket_m.h \
  /usr/include/libxml++-2.6/libxml++/dtd.h \
  /usr/include/glib-2.0/glib/deprecated/gcompletion.h \
  /usr/include/glib-2.0/glib/gversion.h \
  /usr/include/libxml++-2.6/libxml++/nodes/cdatanode.h \
  /usr/include/glib-2.0/glib/gthread.h \
  src/node/communication/routing/aodvRouting/AodvRoutingPacket_m.h \
  /usr/include/glib-2.0/glib/gcharset.h \
  /usr/include/glib-2.0/glib/gbookmarkfile.h \
  /usr/include/libxml++-2.6/libxml++/parsers/parser.h \
  src/node/application/distanceTest/DistanceTestPacket_m.h
$O/src/helpStructures/CastaliaModule.o: src/helpStructures/CastaliaModule.cc \
  src/helpStructures/CastaliaModule.h \
  src/helpStructures/DebugInfoWriter.h \
  src/node/resourceManager/ResourceManagerMessage_m.h \
  src/CastaliaMessages.h
$O/src/helpStructures/DebugInfoWriter.o: src/helpStructures/DebugInfoWriter.cc \
  src/helpStructures/DebugInfoWriter.h
$O/src/helpStructures/GlobalFilterMessage.o: src/helpStructures/GlobalFilterMessage.cc \
  src/helpStructures/GlobalFilterMessage.h
$O/src/helpStructures/LoggerMessage.o: src/helpStructures/LoggerMessage.cc \
  src/helpStructures/LoggerMessage.h
$O/src/helpStructures/TimerService.o: src/helpStructures/TimerService.cc \
  src/helpStructures/TimerServiceMessage_m.h \
  src/helpStructures/TimerService.h \
  src/CastaliaMessages.h
$O/src/logger/Logger.o: src/logger/Logger.cc \
  src/helpStructures/DebugInfoWriter.h \
  src/helpStructures/CastaliaModule.h \
  src/logger/Logger.h \
  src/CastaliaMessages.h \
  src/helpStructures/LoggerMessage.h \
  src/node/resourceManager/ResourceManagerMessage_m.h
$O/src/node/application/VirtualApplication.o: src/node/application/VirtualApplication.cc \
  src/node/communication/mac/mac802154/Mac802154Packet_m.h \
  src/node/application/VirtualApplication.h \
  src/node/communication/routing/RoutingPacket_m.h \
  src/helpStructures/TimerService.h \
  src/wirelessChannel/WirelessChannelMessages_m.h \
  src/helpStructures/CastaliaModule.h \
  src/node/communication/radio/RadioControlMessage_m.h \
  src/node/communication/radio/Radio.h \
  src/helpStructures/DebugInfoWriter.h \
  src/helpStructures/TimerServiceMessage_m.h \
  src/node/resourceManager/ResourceManagerMessage_m.h \
  src/node/mobilityManager/VirtualMobilityManager.h \
  src/node/communication/routing/multipathRingsRouting/MultipathRingsRoutingPacket_m.h \
  src/utils/asfpputils/utils.h \
  src/node/resourceManager/ResourceManager.h \
  src/node/communication/radio/RadioSupportFunctions.h \
  src/CastaliaMessages.h \
  src/node/application/ApplicationPacket_m.h \
  src/node/sensorManager/SensorManagerMessage_m.h \
  src/node/communication/mac/MacPacket_m.h
$O/src/node/application/bridgeTest/BridgeTest.o: src/node/application/bridgeTest/BridgeTest.cc \
  src/wirelessChannel/WirelessChannelMessages_m.h \
  src/helpStructures/CastaliaModule.h \
  src/node/communication/radio/Radio.h \
  src/node/communication/radio/RadioControlMessage_m.h \
  src/helpStructures/TimerServiceMessage_m.h \
  src/helpStructures/DebugInfoWriter.h \
  src/node/communication/mac/mac802154/Mac802154Packet_m.h \
  src/node/communication/routing/RoutingPacket_m.h \
  src/node/application/VirtualApplication.h \
  src/helpStructures/TimerService.h \
  src/node/application/ApplicationPacket_m.h \
  src/CastaliaMessages.h \
  src/node/sensorManager/SensorManagerMessage_m.h \
  src/node/communication/mac/MacPacket_m.h \
  src/node/resourceManager/ResourceManagerMessage_m.h \
  src/node/communication/routing/multipathRingsRouting/MultipathRingsRoutingPacket_m.h \
  src/node/mobilityManager/VirtualMobilityManager.h \
  src/utils/asfpputils/utils.h \
  src/node/resourceManager/ResourceManager.h \
  src/node/communication/radio/RadioSupportFunctions.h \
  src/node/application/bridgeTest/BridgeTest.h
$O/src/node/application/clusterAggregator/ClusterAggregator.o: src/node/application/clusterAggregator/ClusterAggregator.cc \
  src/node/application/clusterAggregator/ClusterAggregatorPacket_m.h \
  src/node/communication/mac/MacPacket_m.h \
  src/node/sensorManager/SensorManagerMessage_m.h \
  src/CastaliaMessages.h \
  src/node/application/ApplicationPacket_m.h \
  src/node/communication/radio/RadioSupportFunctions.h \
  src/node/resourceManager/ResourceManager.h \
  src/utils/asfpputils/utils.h \
  src/node/application/clusterAggregator/ClusterAggregator.h \
  src/node/mobilityManager/VirtualMobilityManager.h \
  src/node/communication/routing/multipathRingsRouting/MultipathRingsRoutingPacket_m.h \
  src/node/resourceManager/ResourceManagerMessage_m.h \
  src/helpStructures/DebugInfoWriter.h \
  src/helpStructures/TimerServiceMessage_m.h \
  src/node/communication/radio/RadioControlMessage_m.h \
  src/node/communication/radio/Radio.h \
  src/helpStructures/CastaliaModule.h \
  src/wirelessChannel/WirelessChannelMessages_m.h \
  src/helpStructures/TimerService.h \
  src/node/application/VirtualApplication.h \
  src/node/communication/routing/RoutingPacket_m.h \
  src/node/communication/mac/mac802154/Mac802154Packet_m.h
$O/src/node/application/connectivityMap/ConnectivityMap.o: src/node/application/connectivityMap/ConnectivityMap.cc \
  src/node/communication/mac/mac802154/Mac802154Packet_m.h \
  src/helpStructures/TimerService.h \
  src/node/application/VirtualApplication.h \
  src/node/communication/routing/RoutingPacket_m.h \
  src/wirelessChannel/WirelessChannelMessages_m.h \
  src/node/communication/radio/RadioControlMessage_m.h \
  src/node/communication/radio/Radio.h \
  src/helpStructures/CastaliaModule.h \
  src/helpStructures/DebugInfoWriter.h \
  src/helpStructures/TimerServiceMessage_m.h \
  src/node/mobilityManager/VirtualMobilityManager.h \
  src/node/communication/routing/multipathRingsRouting/MultipathRingsRoutingPacket_m.h \
  src/node/resourceManager/ResourceManagerMessage_m.h \
  src/utils/asfpputils/utils.h \
  src/node/communication/radio/RadioSupportFunctions.h \
  src/node/application/connectivityMap/ConnectivityMap.h \
  src/node/resourceManager/ResourceManager.h \
  src/CastaliaMessages.h \
  src/node/application/ApplicationPacket_m.h \
  src/node/sensorManager/SensorManagerMessage_m.h \
  src/node/communication/mac/MacPacket_m.h
$O/src/node/application/distanceTest/DistanceTest.o: src/node/application/distanceTest/DistanceTest.cc \
  src/node/sensorManager/SensorManagerMessage_m.h \
  src/CastaliaMessages.h \
  src/node/application/ApplicationPacket_m.h \
  src/node/application/distanceTest/DistanceTestPacket_m.h \
  src/node/application/distanceTest/DistanceTest.h \
  src/node/communication/mac/MacPacket_m.h \
  src/utils/asfpputils/utils.h \
  src/node/resourceManager/ResourceManagerMessage_m.h \
  src/node/mobilityManager/VirtualMobilityManager.h \
  src/node/communication/routing/multipathRingsRouting/MultipathRingsRoutingPacket_m.h \
  src/node/resourceManager/ResourceManager.h \
  src/node/communication/radio/RadioSupportFunctions.h \
  src/helpStructures/CastaliaModule.h \
  src/node/communication/radio/RadioControlMessage_m.h \
  src/node/communication/radio/Radio.h \
  src/wirelessChannel/WirelessChannelMessages_m.h \
  src/helpStructures/DebugInfoWriter.h \
  src/helpStructures/TimerServiceMessage_m.h \
  src/node/communication/mac/mac802154/Mac802154Packet_m.h \
  src/node/application/VirtualApplication.h \
  src/node/communication/routing/RoutingPacket_m.h \
  src/helpStructures/TimerService.h
$O/src/node/application/dummyApplication/DummyApplication.o: src/node/application/dummyApplication/DummyApplication.cc \
  src/node/communication/radio/Radio.h \
  src/node/communication/radio/RadioControlMessage_m.h \
  src/helpStructures/CastaliaModule.h \
  src/wirelessChannel/WirelessChannelMessages_m.h \
  src/helpStructures/DebugInfoWriter.h \
  src/helpStructures/TimerServiceMessage_m.h \
  src/node/communication/mac/mac802154/Mac802154Packet_m.h \
  src/node/application/dummyApplication/DummyApplication.h \
  src/helpStructures/TimerService.h \
  src/node/application/VirtualApplication.h \
  src/node/communication/routing/RoutingPacket_m.h \
  src/node/sensorManager/SensorManagerMessage_m.h \
  src/node/application/ApplicationPacket_m.h \
  src/CastaliaMessages.h \
  src/node/communication/mac/MacPacket_m.h \
  src/utils/asfpputils/utils.h \
  src/node/communication/routing/multipathRingsRouting/MultipathRingsRoutingPacket_m.h \
  src/node/mobilityManager/VirtualMobilityManager.h \
  src/node/resourceManager/ResourceManagerMessage_m.h \
  src/node/communication/radio/RadioSupportFunctions.h \
  src/node/resourceManager/ResourceManager.h
$O/src/node/application/roomMonitoring/RoomMonitoring.o: src/node/application/roomMonitoring/RoomMonitoring.cc \
  src/wirelessChannel/WirelessChannelMessages_m.h \
  src/helpStructures/CastaliaModule.h \
  src/node/communication/radio/Radio.h \
  src/node/communication/radio/RadioControlMessage_m.h \
  src/helpStructures/DebugInfoWriter.h \
  src/helpStructures/TimerServiceMessage_m.h \
  src/node/application/roomMonitoring/RoomMonitoring.h \
  src/node/communication/mac/mac802154/Mac802154Packet_m.h \
  src/node/application/VirtualApplication.h \
  src/node/communication/routing/RoutingPacket_m.h \
  src/helpStructures/TimerService.h \
  src/node/application/ApplicationPacket_m.h \
  src/CastaliaMessages.h \
  src/node/sensorManager/SensorManagerMessage_m.h \
  src/node/communication/mac/MacPacket_m.h \
  src/node/application/roomMonitoring/RoomMonitoringPacket_m.h \
  src/node/resourceManager/ResourceManagerMessage_m.h \
  src/node/communication/routing/multipathRingsRouting/MultipathRingsRoutingPacket_m.h \
  src/node/mobilityManager/VirtualMobilityManager.h \
  src/utils/asfpputils/utils.h \
  src/node/resourceManager/ResourceManager.h \
  src/node/communication/radio/RadioSupportFunctions.h
$O/src/node/application/simpleAggregation/SimpleAggregation.o: src/node/application/simpleAggregation/SimpleAggregation.cc \
  src/node/communication/mac/MacPacket_m.h \
  src/CastaliaMessages.h \
  src/node/application/ApplicationPacket_m.h \
  src/node/sensorManager/SensorManagerMessage_m.h \
  src/node/resourceManager/ResourceManager.h \
  src/node/communication/radio/RadioSupportFunctions.h \
  src/node/resourceManager/ResourceManagerMessage_m.h \
  src/node/mobilityManager/VirtualMobilityManager.h \
  src/node/communication/routing/multipathRingsRouting/MultipathRingsRoutingPacket_m.h \
  src/utils/asfpputils/utils.h \
  src/helpStructures/DebugInfoWriter.h \
  src/helpStructures/TimerServiceMessage_m.h \
  src/wirelessChannel/WirelessChannelMessages_m.h \
  src/helpStructures/CastaliaModule.h \
  src/node/communication/radio/RadioControlMessage_m.h \
  src/node/communication/radio/Radio.h \
  src/node/application/VirtualApplication.h \
  src/node/communication/routing/RoutingPacket_m.h \
  src/helpStructures/TimerService.h \
  src/node/application/simpleAggregation/SimpleAggregation.h \
  src/node/communication/mac/mac802154/Mac802154Packet_m.h
$O/src/node/application/throughputTest/ThroughputTest.o: src/node/application/throughputTest/ThroughputTest.cc \
  src/helpStructures/TimerServiceMessage_m.h \
  src/helpStructures/DebugInfoWriter.h \
  src/wirelessChannel/WirelessChannelMessages_m.h \
  src/node/communication/radio/Radio.h \
  src/node/communication/radio/RadioControlMessage_m.h \
  src/helpStructures/CastaliaModule.h \
  src/node/application/throughputTest/ThroughputTest.h \
  src/helpStructures/TimerService.h \
  src/node/communication/routing/RoutingPacket_m.h \
  src/node/application/VirtualApplication.h \
  src/node/communication/mac/mac802154/Mac802154Packet_m.h \
  src/node/communication/mac/MacPacket_m.h \
  src/node/application/ApplicationPacket_m.h \
  src/CastaliaMessages.h \
  src/node/sensorManager/SensorManagerMessage_m.h \
  src/node/communication/radio/RadioSupportFunctions.h \
  src/node/resourceManager/ResourceManager.h \
  src/node/communication/routing/multipathRingsRouting/MultipathRingsRoutingPacket_m.h \
  src/node/mobilityManager/VirtualMobilityManager.h \
  src/node/resourceManager/ResourceManagerMessage_m.h \
  src/utils/asfpputils/utils.h
$O/src/node/application/valuePropagation/ValuePropagation.o: src/node/application/valuePropagation/ValuePropagation.cc \
  src/node/resourceManager/ResourceManager.h \
  src/node/communication/radio/RadioSupportFunctions.h \
  src/utils/asfpputils/utils.h \
  src/node/resourceManager/ResourceManagerMessage_m.h \
  src/node/mobilityManager/VirtualMobilityManager.h \
  src/node/communication/routing/multipathRingsRouting/MultipathRingsRoutingPacket_m.h \
  src/node/communication/mac/MacPacket_m.h \
  src/node/sensorManager/SensorManagerMessage_m.h \
  src/node/application/valuePropagation/ValuePropagation.h \
  src/CastaliaMessages.h \
  src/node/application/ApplicationPacket_m.h \
  src/node/communication/routing/RoutingPacket_m.h \
  src/node/application/VirtualApplication.h \
  src/helpStructures/TimerService.h \
  src/node/communication/mac/mac802154/Mac802154Packet_m.h \
  src/helpStructures/TimerServiceMessage_m.h \
  src/helpStructures/DebugInfoWriter.h \
  src/helpStructures/CastaliaModule.h \
  src/node/communication/radio/RadioControlMessage_m.h \
  src/node/communication/radio/Radio.h \
  src/wirelessChannel/WirelessChannelMessages_m.h
$O/src/node/application/valueReporting/ValueReporting.o: src/node/application/valueReporting/ValueReporting.cc \
  src/node/resourceManager/ResourceManager.h \
  src/node/communication/radio/RadioSupportFunctions.h \
  src/utils/asfpputils/utils.h \
  src/node/resourceManager/ResourceManagerMessage_m.h \
  src/node/mobilityManager/VirtualMobilityManager.h \
  src/node/communication/routing/multipathRingsRouting/MultipathRingsRoutingPacket_m.h \
  src/node/communication/mac/MacPacket_m.h \
  src/node/sensorManager/SensorManagerMessage_m.h \
  src/CastaliaMessages.h \
  src/node/application/ApplicationPacket_m.h \
  src/node/application/valueReporting/ValueReportingPacket_m.h \
  src/node/communication/routing/RoutingPacket_m.h \
  src/node/application/VirtualApplication.h \
  src/helpStructures/TimerService.h \
  src/node/communication/mac/mac802154/Mac802154Packet_m.h \
  src/helpStructures/TimerServiceMessage_m.h \
  src/helpStructures/DebugInfoWriter.h \
  src/node/application/valueReporting/ValueReporting.h \
  src/helpStructures/CastaliaModule.h \
  src/node/communication/radio/RadioControlMessage_m.h \
  src/node/communication/radio/Radio.h \
  src/wirelessChannel/WirelessChannelMessages_m.h
$O/src/node/communication/mac/VirtualMac.o: src/node/communication/mac/VirtualMac.cc \
  src/node/communication/mac/mac802154/Mac802154Packet_m.h \
  src/node/communication/routing/RoutingPacket_m.h \
  src/helpStructures/TimerService.h \
  src/wirelessChannel/WirelessChannelMessages_m.h \
  src/helpStructures/CastaliaModule.h \
  src/node/communication/radio/RadioControlMessage_m.h \
  src/node/communication/radio/Radio.h \
  src/helpStructures/TimerServiceMessage_m.h \
  src/helpStructures/DebugInfoWriter.h \
  src/node/resourceManager/ResourceManagerMessage_m.h \
  src/node/communication/routing/multipathRingsRouting/MultipathRingsRoutingPacket_m.h \
  src/utils/asfpputils/utils.h \
  src/node/resourceManager/ResourceManager.h \
  src/node/communication/radio/RadioSupportFunctions.h \
  src/node/communication/mac/VirtualMac.h \
  src/CastaliaMessages.h \
  src/node/communication/mac/MacPacket_m.h
$O/src/node/communication/mac/baselineBanMac/BaselineBANMac.o: src/node/communication/mac/baselineBanMac/BaselineBANMac.cc \
  src/node/communication/mac/VirtualMac.h \
  src/node/communication/mac/baselineBanMac/BaselineMacPacket_m.h \
  src/CastaliaMessages.h \
  src/node/communication/mac/MacPacket_m.h \
  src/node/resourceManager/ResourceManagerMessage_m.h \
  src/node/communication/routing/multipathRingsRouting/MultipathRingsRoutingPacket_m.h \
  src/node/communication/mac/baselineBanMac/BaselineBANMac.h \
  src/utils/asfpputils/utils.h \
  src/node/resourceManager/ResourceManager.h \
  src/node/communication/radio/RadioSupportFunctions.h \
  src/wirelessChannel/WirelessChannelMessages_m.h \
  src/helpStructures/CastaliaModule.h \
  src/node/communication/radio/RadioControlMessage_m.h \
  src/node/communication/radio/Radio.h \
  src/helpStructures/TimerServiceMessage_m.h \
  src/helpStructures/DebugInfoWriter.h \
  src/node/communication/mac/mac802154/Mac802154Packet_m.h \
  src/node/communication/routing/RoutingPacket_m.h \
  src/helpStructures/TimerService.h
$O/src/node/communication/mac/bypassMac/BypassMAC.o: src/node/communication/mac/bypassMac/BypassMAC.cc \
  src/node/communication/mac/mac802154/Mac802154Packet_m.h \
  src/node/communication/mac/bypassMac/BypassMAC.h \
  src/node/communication/routing/RoutingPacket_m.h \
  src/helpStructures/TimerService.h \
  src/wirelessChannel/WirelessChannelMessages_m.h \
  src/helpStructures/CastaliaModule.h \
  src/node/communication/radio/Radio.h \
  src/node/communication/radio/RadioControlMessage_m.h \
  src/helpStructures/TimerServiceMessage_m.h \
  src/helpStructures/DebugInfoWriter.h \
  src/node/resourceManager/ResourceManagerMessage_m.h \
  src/node/communication/routing/multipathRingsRouting/MultipathRingsRoutingPacket_m.h \
  src/utils/asfpputils/utils.h \
  src/node/resourceManager/ResourceManager.h \
  src/node/communication/radio/RadioSupportFunctions.h \
  src/node/communication/mac/VirtualMac.h \
  src/CastaliaMessages.h \
  src/node/communication/mac/MacPacket_m.h
$O/src/node/communication/mac/mac802154/Mac802154.o: src/node/communication/mac/mac802154/Mac802154.cc \
  src/utils/asfpputils/utils.h \
  src/node/resourceManager/ResourceManagerMessage_m.h \
  src/node/communication/routing/multipathRingsRouting/MultipathRingsRoutingPacket_m.h \
  src/node/resourceManager/ResourceManager.h \
  src/node/communication/radio/RadioSupportFunctions.h \
  src/node/communication/mac/VirtualMac.h \
  src/CastaliaMessages.h \
  src/node/communication/mac/MacPacket_m.h \
  src/node/communication/mac/mac802154/Mac802154Packet_m.h \
  src/node/communication/routing/RoutingPacket_m.h \
  src/helpStructures/TimerService.h \
  src/helpStructures/CastaliaModule.h \
  src/node/communication/radio/RadioControlMessage_m.h \
  src/node/communication/radio/Radio.h \
  src/node/communication/mac/mac802154/Mac802154.h \
  src/wirelessChannel/WirelessChannelMessages_m.h \
  src/helpStructures/TimerServiceMessage_m.h \
  src/helpStructures/DebugInfoWriter.h
$O/src/node/communication/mac/tMac/TMAC.o: src/node/communication/mac/tMac/TMAC.cc \
  src/node/communication/mac/tMac/TMAC.h \
  src/node/communication/mac/mac802154/Mac802154Packet_m.h \
  src/node/communication/mac/tMac/TMacPacket_m.h \
  src/helpStructures/TimerService.h \
  src/node/communication/routing/RoutingPacket_m.h \
  src/wirelessChannel/WirelessChannelMessages_m.h \
  src/node/communication/radio/Radio.h \
  src/node/communication/radio/RadioControlMessage_m.h \
  src/helpStructures/CastaliaModule.h \
  src/helpStructures/TimerServiceMessage_m.h \
  src/helpStructures/DebugInfoWriter.h \
  src/node/communication/routing/multipathRingsRouting/MultipathRingsRoutingPacket_m.h \
  src/node/resourceManager/ResourceManagerMessage_m.h \
  src/utils/asfpputils/utils.h \
  src/node/communication/radio/RadioSupportFunctions.h \
  src/node/resourceManager/ResourceManager.h \
  src/CastaliaMessages.h \
  src/node/communication/mac/VirtualMac.h \
  src/node/communication/mac/MacPacket_m.h
$O/src/node/communication/mac/tunableMac/TunableMAC.o: src/node/communication/mac/tunableMac/TunableMAC.cc \
  src/utils/asfpputils/utils.h \
  src/node/resourceManager/ResourceManagerMessage_m.h \
  src/node/communication/routing/multipathRingsRouting/MultipathRingsRoutingPacket_m.h \
  src/node/communication/mac/tunableMac/TunableMacControl_m.h \
  src/node/resourceManager/ResourceManager.h \
  src/node/communication/radio/RadioSupportFunctions.h \
  src/node/communication/mac/VirtualMac.h \
  src/node/communication/mac/tunableMac/TunableMAC.h \
  src/CastaliaMessages.h \
  src/node/communication/mac/MacPacket_m.h \
  src/node/communication/mac/mac802154/Mac802154Packet_m.h \
  src/node/communication/routing/RoutingPacket_m.h \
  src/helpStructures/TimerService.h \
  src/helpStructures/CastaliaModule.h \
  src/node/communication/radio/RadioControlMessage_m.h \
  src/node/communication/radio/Radio.h \
  src/node/communication/mac/tunableMac/TunableMacPacket_m.h \
  src/wirelessChannel/WirelessChannelMessages_m.h \
  src/helpStructures/TimerServiceMessage_m.h \
  src/helpStructures/DebugInfoWriter.h
$O/src/node/communication/radio/Radio.o: src/node/communication/radio/Radio.cc \
  src/node/resourceManager/ResourceManagerMessage_m.h \
  src/node/communication/routing/multipathRingsRouting/MultipathRingsRoutingPacket_m.h \
  src/utils/asfpputils/utils.h \
  src/node/resourceManager/ResourceManager.h \
  src/node/communication/radio/RadioSupportFunctions.h \
  src/CastaliaMessages.h \
  src/node/communication/mac/MacPacket_m.h \
  src/node/communication/mac/mac802154/Mac802154Packet_m.h \
  src/node/communication/routing/RoutingPacket_m.h \
  src/wirelessChannel/WirelessChannelMessages_m.h \
  src/helpStructures/CastaliaModule.h \
  src/node/communication/radio/RadioControlMessage_m.h \
  src/node/communication/radio/Radio.h \
  src/helpStructures/DebugInfoWriter.h
$O/src/node/communication/radio/RadioSupportFunctions.o: src/node/communication/radio/RadioSupportFunctions.cc \
  src/node/communication/radio/RadioSupportFunctions.h \
  src/CastaliaMessages.h \
  src/node/communication/radio/RadioControlMessage_m.h
$O/src/node/communication/routing/VirtualRouting.o: src/node/communication/routing/VirtualRouting.cc \
  src/node/communication/mac/mac802154/Mac802154Packet_m.h \
  src/helpStructures/TimerService.h \
  src/node/communication/routing/RoutingPacket_m.h \
  src/node/communication/radio/Radio.h \
  src/node/communication/radio/RadioControlMessage_m.h \
  src/helpStructures/CastaliaModule.h \
  src/wirelessChannel/WirelessChannelMessages_m.h \
  src/helpStructures/TimerServiceMessage_m.h \
  src/helpStructures/DebugInfoWriter.h \
  src/utils/asfpputils/utils.h \
  src/node/communication/routing/multipathRingsRouting/MultipathRingsRoutingPacket_m.h \
  src/node/resourceManager/ResourceManagerMessage_m.h \
  src/node/communication/radio/RadioSupportFunctions.h \
  src/node/resourceManager/ResourceManager.h \
  src/node/application/ApplicationPacket_m.h \
  src/CastaliaMessages.h \
  src/node/communication/routing/VirtualRouting.h \
  src/node/communication/mac/MacPacket_m.h
$O/src/node/communication/routing/aodvRouting/AodvRouting.o: src/node/communication/routing/aodvRouting/AodvRouting.cc \
  src/node/communication/mac/mac802154/Mac802154Packet_m.h \
  src/node/communication/routing/aodvRouting/AodvRoutingRrepPacket_m.h \
  src/node/communication/routing/RoutingPacket_m.h \
  src/helpStructures/TimerService.h \
  src/helpStructures/CastaliaModule.h \
  src/node/communication/radio/Radio.h \
  src/node/communication/radio/RadioControlMessage_m.h \
  src/wirelessChannel/WirelessChannelMessages_m.h \
  src/node/communication/routing/aodvRouting/AodvRoutingDataPacket_m.h \
  src/node/communication/routing/aodvRouting/RoutingTable_rt.h \
  src/helpStructures/DebugInfoWriter.h \
  src/helpStructures/TimerServiceMessage_m.h \
  src/utils/asfpputils/utils.h \
  src/node/communication/routing/aodvRouting/AodvRouting.h \
  src/node/resourceManager/ResourceManagerMessage_m.h \
  src/node/communication/routing/multipathRingsRouting/MultipathRingsRoutingPacket_m.h \
  src/node/communication/routing/aodvRouting/PacketId_m.h \
  src/node/resourceManager/ResourceManager.h \
  src/node/communication/radio/RadioSupportFunctions.h \
  src/node/communication/routing/VirtualRouting.h \
  src/node/application/ApplicationPacket_m.h \
  src/CastaliaMessages.h \
  src/node/communication/routing/aodvRouting/AodvRoutingPacket_m.h \
  src/node/communication/mac/MacPacket_m.h
$O/src/node/communication/routing/aodvRouting/RoutingTable_rt.o: src/node/communication/routing/aodvRouting/RoutingTable_rt.cc \
  src/node/resourceManager/ResourceManagerMessage_m.h \
  src/CastaliaMessages.h \
  src/node/communication/routing/aodvRouting/RoutingTable_rt.h \
  src/helpStructures/DebugInfoWriter.h \
  src/helpStructures/CastaliaModule.h
$O/src/node/communication/routing/bypassRouting/BypassRouting.o: src/node/communication/routing/bypassRouting/BypassRouting.cc \
  src/node/resourceManager/ResourceManager.h \
  src/node/communication/radio/RadioSupportFunctions.h \
  src/utils/asfpputils/utils.h \
  src/node/resourceManager/ResourceManagerMessage_m.h \
  src/node/communication/routing/multipathRingsRouting/MultipathRingsRoutingPacket_m.h \
  src/node/communication/routing/bypassRouting/BypassRouting.h \
  src/node/communication/mac/MacPacket_m.h \
  src/node/communication/routing/VirtualRouting.h \
  src/node/application/ApplicationPacket_m.h \
  src/CastaliaMessages.h \
  src/node/communication/routing/RoutingPacket_m.h \
  src/helpStructures/TimerService.h \
  src/node/communication/mac/mac802154/Mac802154Packet_m.h \
  src/helpStructures/TimerServiceMessage_m.h \
  src/helpStructures/DebugInfoWriter.h \
  src/helpStructures/CastaliaModule.h \
  src/node/communication/routing/bypassRouting/BypassRoutingPacket_m.h \
  src/node/communication/radio/Radio.h \
  src/node/communication/radio/RadioControlMessage_m.h \
  src/wirelessChannel/WirelessChannelMessages_m.h
$O/src/node/communication/routing/multipathRingsRouting/MultipathRingsRouting.o: src/node/communication/routing/multipathRingsRouting/MultipathRingsRouting.cc \
  src/helpStructures/TimerServiceMessage_m.h \
  src/helpStructures/DebugInfoWriter.h \
  src/wirelessChannel/WirelessChannelMessages_m.h \
  src/node/communication/radio/RadioControlMessage_m.h \
  src/node/communication/radio/Radio.h \
  src/helpStructures/CastaliaModule.h \
  src/helpStructures/TimerService.h \
  src/node/communication/routing/RoutingPacket_m.h \
  src/node/communication/mac/mac802154/Mac802154Packet_m.h \
  src/node/communication/mac/MacPacket_m.h \
  src/CastaliaMessages.h \
  src/node/application/ApplicationPacket_m.h \
  src/node/communication/routing/VirtualRouting.h \
  src/node/communication/radio/RadioSupportFunctions.h \
  src/node/communication/routing/multipathRingsRouting/MultipathRingsRouting.h \
  src/node/resourceManager/ResourceManager.h \
  src/node/communication/routing/multipathRingsRouting/MultipathRingsRoutingControl_m.h \
  src/node/communication/routing/multipathRingsRouting/MultipathRingsRoutingPacket_m.h \
  src/node/resourceManager/ResourceManagerMessage_m.h \
  src/utils/asfpputils/utils.h
$O/src/node/localfilter/LocalFilter.o: src/node/localfilter/LocalFilter.cc \
  src/attack/phyiscalattack/PhysicalAttack.h \
  /usr/include/glib-2.0/glib/glist.h \
  src/actions/actionbase/Action.h \
  /usr/include/libxml++-2.6/libxml++/nodes/textnode.h \
  src/node/communication/mac/MacPacket_m.h \
  /usr/include/glib-2.0/glib/gmarkup.h \
  /usr/include/libxml++-2.6/libxml++/nodes/xincludestart.h \
  /usr/include/glib-2.0/glib/gfileutils.h \
  /usr/include/libxml++-2.6/libxml++/parsers/parser.h \
  src/node/application/distanceTest/DistanceTestPacket_m.h \
  /usr/include/glib-2.0/glib/gthread.h \
  /usr/include/glib-2.0/glib/gbookmarkfile.h \
  /usr/include/glib-2.0/glib/gcharset.h \
  src/node/communication/routing/aodvRouting/AodvRoutingPacket_m.h \
  src/actions/fakeread/Fakeread.h \
  /usr/include/glib-2.0/glib/gversion.h \
  /usr/include/libxml++-2.6/libxml++/nodes/cdatanode.h \
  /usr/include/libxml++-2.6/libxml++/dtd.h \
  src/node/application/clusterAggregator/ClusterAggregatorPacket_m.h \
  /usr/include/glib-2.0/glib/deprecated/gcompletion.h \
  src/node/communication/mac/VirtualMac.h \
  /usr/include/glib-2.0/glib/gmacros.h \
  /usr/include/glib-2.0/glib/gmappedfile.h \
  src/node/sensorManager/SensorManager.h \
  src/node/communication/routing/VirtualRouting.h \
  src/attack/conditionalattack/packetfilter/PacketFilter.h \
  src/node/application/ApplicationPacket_m.h \
  src/CastaliaMessages.h \
  src/node/communication/mac/baselineBanMac/BaselineMacPacket_m.h \
  src/actions/put/Put.h \
  /usr/include/glib-2.0/glib/gscanner.h \
  src/attack/entry/Entry.h \
  src/node/sensorManager/SensorManagerMessage_m.h \
  /usr/include/glib-2.0/glib/gmessages.h \
  /usr/include/glib-2.0/glib/gatomic.h \
  /usr/include/glib-2.0/glib/gregex.h \
  /usr/lib/x86_64-linux-gnu/glibmm-2.4/include/glibmmconfig.h \
  /usr/include/glib-2.0/glib/gunicode.h \
  /usr/include/libxml++-2.6/libxml++/nodes/xincludeend.h \
  /usr/include/glib-2.0/glib/gtimezone.h \
  /usr/include/libxml++-2.6/libxml++/nodes/node.h \
  src/node/resourceManager/ResourceManager.h \
  src/PacketTypes.h \
  src/node/communication/radio/RadioSupportFunctions.h \
  /usr/include/glib-2.0/glib/gdataset.h \
  /usr/include/glib-2.0/glib/gbase64.h \
  /usr/include/glib-2.0/glib/gbacktrace.h \
  /usr/include/libxml++-2.6/libxml++/parsers/saxparser.h \
  src/attack/attackbase/Attack.h \
  src/actions/create/Create.h \
  /usr/include/libxml++-2.6/libxml++/validators/dtdvalidator.h \
  src/actions/clone/Clone.h \
  /usr/include/glib-2.0/glib/gbitlock.h \
  /usr/include/libxml++-2.6/libxml++/validators/schemavalidator.h \
  src/node/communication/routing/aodvRouting/PacketId_m.h \
  /usr/include/glib-2.0/glib/gprimes.h \
  src/actions/destroy/DestroyRequest_m.h \
  src/node/localfilter/LocalFilter.h \
  src/node/application/roomMonitoring/RoomMonitoringPacket_m.h \
  /usr/include/libxml++-2.6/libxml++/exceptions/validity_error.h \
  /usr/include/glib-2.0/glib/gurifuncs.h \
  /usr/include/glib-2.0/glib/deprecated/gmain.h \
  /usr/include/libxml++-2.6/libxml++/attributenode.h \
  /usr/include/glib-2.0/glib/gwin32.h \
  src/node/resourceManager/ResourceManagerMessage_m.h \
  src/node/communication/routing/multipathRingsRouting/MultipathRingsRoutingPacket_m.h \
  src/node/mobilityManager/VirtualMobilityManager.h \
  /usr/include/glib-2.0/glib/gdate.h \
  /usr/include/libxml++-2.6/libxml++/nodes/commentnode.h \
  /usr/include/glib-2.0/glib/galloca.h \
  /usr/include/glib-2.0/glib/gquark.h \
  /usr/include/glib-2.0/glib/gtrashstack.h \
  src/helpStructures/LoggerMessage.h \
  src/utils/asfpputils/utils.h \
  /usr/include/glib-2.0/glib/gmain.h \
  /usr/include/glib-2.0/glib/deprecated/gallocator.h \
  src/node/communication/routing/aodvRouting/AodvRoutingDataPacket_m.h \
  /usr/include/glib-2.0/glib/gconvert.h \
  src/actions/change/Change.h \
  src/utils/exprtk/exprtk.hpp \
  /usr/include/glib-2.0/glib/garray.h \
  src/physicalProcess/PhysicalProcessMessage_m.h \
  src/actions/retrieve/Retrieve.h \
  /usr/include/glib-2.0/glib/gsequence.h \
  /usr/include/glib-2.0/glib/gchecksum.h \
  /usr/include/glib-2.0/glib/deprecated/gthread.h \
  src/helpStructures/DebugInfoWriter.h \
  /usr/include/libxml++-2.6/libxml++/libxml++.h \
  /usr/include/libxml++-2.6/libxml++/schema.h \
  src/helpStructures/TimerServiceMessage_m.h \
  /usr/include/libxml++-2.6/libxml++/attribute.h \
  /usr/lib/libxml++-2.6/include/libxml++config.h \
  /usr/include/glib-2.0/glib/genviron.h \
  /usr/include/glib-2.0/glib/deprecated/gcache.h \
  src/parser/Parser.h \
  src/attack/conditionalattack/conditionalattack/ConditionalAttack.h \
  src/variable/Variable.h \
  /usr/include/glib-2.0/glib/gtypes.h \
  /usr/include/glib-2.0/glib/gshell.h \
  /usr/include/glib-2.0/glib/gasyncqueue.h \
  /usr/include/libxml++-2.6/libxml++/nodes/entitydeclaration.h \
  src/node/communication/mac/tunableMac/TunableMacPacket_m.h \
  /usr/include/glib-2.0/glib/gqueue.h \
  /usr/include/libxml++-2.6/libxml++/noncopyable.h \
  /usr/include/glib-2.0/glib/gdir.h \
  src/wirelessChannel/WirelessChannelMessages_m.h \
  /usr/include/glib-2.0/glib/gmem.h \
  /usr/include/libxml++-2.6/libxml++/parsers/domparser.h \
  /usr/include/glib-2.0/glib/giochannel.h \
  /usr/include/libxml++-2.6/libxml++/exceptions/exception.h \
  /usr/include/glib-2.0/glib/gnode.h \
  /usr/include/glib-2.0/glib/goption.h \
  /usr/include/libxml++-2.6/libxml++/validators/validator.h \
  /usr/include/libxml++-2.6/libxml++/exceptions/parse_error.h \
  /usr/include/glib-2.0/glib/gslice.h \
  src/helpStructures/CastaliaModule.h \
  /usr/include/libxml++-2.6/libxml++/attributedeclaration.h \
  src/node/communication/routing/bypassRouting/BypassRoutingPacket_m.h \
  /usr/lib/x86_64-linux-gnu/glib-2.0/include/glibconfig.h \
  src/node/communication/radio/Radio.h \
  src/node/communication/radio/RadioControlMessage_m.h \
  /usr/include/glib-2.0/glib/gtimer.h \
  /usr/include/glib-2.0/glib/gbytes.h \
  /usr/include/glib-2.0/glib/gtestutils.h \
  src/actions/send/Send.h \
  /usr/include/glib-2.0/glib/gvarianttype.h \
  /usr/include/glib-2.0/glib.h \
  /usr/include/glib-2.0/glib/gutils.h \
  /usr/include/glibmm-2.4/glibmm/ustring.h \
  /usr/include/glib-2.0/glib/gstring.h \
  /usr/include/glib-2.0/glib/ghmac.h \
  /usr/include/glib-2.0/glib/gspawn.h \
  /usr/include/glib-2.0/glib/gpoll.h \
  src/node/communication/routing/RoutingPacket_m.h \
  /usr/include/libxml++-2.6/libxml++/nodes/entityreference.h \
  /usr/include/libxml++-2.6/libxml++/document.h \
  /usr/include/glib-2.0/glib/deprecated/grel.h \
  src/helpStructures/TimerService.h \
  /usr/include/glib-2.0/glib/gstrfuncs.h \
  /usr/include/glib-2.0/glib/gstringchunk.h \
  /usr/include/glib-2.0/glib/ggettext.h \
  src/node/communication/mac/tMac/TMacPacket_m.h \
  /usr/include/libxml++-2.6/libxml++/exceptions/internal_error.h \
  src/node/application/valueReporting/ValueReportingPacket_m.h \
  /usr/include/libxml++-2.6/libxml++/nodes/contentnode.h \
  /usr/include/libxml++-2.6/libxml++/nodes/processinginstructionnode.h \
  /usr/include/glib-2.0/glib/gtree.h \
  /usr/include/glib-2.0/glib/gdatetime.h \
  src/actions/put/PutMessages.h \
  src/attack/unconditionalattack/UnconditionalAttack.h \
  /usr/include/glib-2.0/glib/grand.h \
  /usr/include/glib-2.0/glib/gthreadpool.h \
  src/attack/entry/EntryWrapper.h \
  src/helpStructures/GlobalFilterMessage.h \
  /usr/include/glib-2.0/glib/gvariant.h \
  /usr/include/glib-2.0/glib/gpattern.h \
  /usr/include/glib-2.0/glib/gversionmacros.h \
  /usr/include/glib-2.0/glib/gqsort.h \
  /usr/include/libxml++-2.6/libxml++/nodes/element.h \
  /usr/include/glib-2.0/glib/ghostutils.h \
  /usr/include/libxml++-2.6/libxml++/parsers/textreader.h \
  /usr/include/glib-2.0/glib/ghook.h \
  src/actions/drop/Drop.h \
  src/node/communication/mac/mac802154/Mac802154Packet_m.h \
  src/actions/asfexpression/ASFExpression.h \
  src/node/communication/routing/aodvRouting/AodvRoutingRrepPacket_m.h \
  /usr/include/glib-2.0/glib/gslist.h \
  /usr/include/glib-2.0/glib/gkeyfile.h \
  /usr/include/glib-2.0/glib/ghash.h \
  src/attack/conditionalattack/packetfilter/FilterBlock.h \
  /usr/include/glib-2.0/glib/gerror.h \
  /usr/include/glibmm-2.4/glibmm/unicode.h
$O/src/node/mobilityManager/VirtualMobilityManager.o: src/node/mobilityManager/VirtualMobilityManager.cc \
  src/wirelessChannel/WirelessChannelMessages_m.h \
  src/helpStructures/CastaliaModule.h \
  src/helpStructures/DebugInfoWriter.h \
  src/node/resourceManager/ResourceManagerMessage_m.h \
  src/node/mobilityManager/VirtualMobilityManager.h \
  src/CastaliaMessages.h
$O/src/node/mobilityManager/lineMobilityManager/LineMobilityManager.o: src/node/mobilityManager/lineMobilityManager/LineMobilityManager.cc \
  src/node/mobilityManager/MobilityManagerMessage_m.h \
  src/node/mobilityManager/VirtualMobilityManager.h \
  src/node/resourceManager/ResourceManagerMessage_m.h \
  src/node/mobilityManager/lineMobilityManager/LineMobilityManager.h \
  src/CastaliaMessages.h \
  src/helpStructures/DebugInfoWriter.h \
  src/helpStructures/CastaliaModule.h \
  src/wirelessChannel/WirelessChannelMessages_m.h
$O/src/node/mobilityManager/noMobilityManager/NoMobilityManager.o: src/node/mobilityManager/noMobilityManager/NoMobilityManager.cc \
  src/CastaliaMessages.h \
  src/node/mobilityManager/VirtualMobilityManager.h \
  src/node/resourceManager/ResourceManagerMessage_m.h \
  src/helpStructures/DebugInfoWriter.h \
  src/helpStructures/CastaliaModule.h \
  src/wirelessChannel/WirelessChannelMessages_m.h \
  src/node/mobilityManager/noMobilityManager/NoMobilityManager.h
$O/src/node/resourceManager/ResourceManager.o: src/node/resourceManager/ResourceManager.cc \
  src/node/resourceManager/ResourceManager.h \
  src/node/resourceManager/ResourceManagerMessage_m.h \
  src/CastaliaMessages.h \
  src/helpStructures/DebugInfoWriter.h \
  src/helpStructures/CastaliaModule.h
$O/src/node/sensorManager/SensorManager.o: src/node/sensorManager/SensorManager.cc \
  src/node/sensorManager/SensorManager.h \
  src/CastaliaMessages.h \
  src/node/sensorManager/SensorManagerMessage_m.h \
  src/node/resourceManager/ResourceManagerMessage_m.h \
  src/node/mobilityManager/VirtualMobilityManager.h \
  src/wirelessChannel/WirelessChannelMessages_m.h \
  src/helpStructures/CastaliaModule.h \
  src/physicalProcess/PhysicalProcessMessage_m.h \
  src/helpStructures/DebugInfoWriter.h
$O/src/parser/Parser.o: src/parser/Parser.cc \
  /usr/include/glib-2.0/glib/gregex.h \
  /usr/lib/x86_64-linux-gnu/glibmm-2.4/include/glibmmconfig.h \
  /usr/include/glib-2.0/glib/gunicode.h \
  /usr/include/libxml++-2.6/libxml++/nodes/xincludeend.h \
  src/actions/put/Put.h \
  /usr/include/glib-2.0/glib/gscanner.h \
  src/attack/entry/Entry.h \
  /usr/include/glib-2.0/glib/gmessages.h \
  src/node/sensorManager/SensorManagerMessage_m.h \
  /usr/include/glib-2.0/glib/gatomic.h \
  src/node/application/ApplicationPacket_m.h \
  src/CastaliaMessages.h \
  src/node/communication/mac/baselineBanMac/BaselineMacPacket_m.h \
  /usr/include/glib-2.0/glib/gmacros.h \
  /usr/include/glib-2.0/glib/gmappedfile.h \
  src/node/sensorManager/SensorManager.h \
  src/attack/conditionalattack/packetfilter/PacketFilter.h \
  src/actions/fakeread/Fakeread.h \
  /usr/include/glib-2.0/glib/gversion.h \
  /usr/include/libxml++-2.6/libxml++/nodes/cdatanode.h \
  src/node/application/clusterAggregator/ClusterAggregatorPacket_m.h \
  /usr/include/libxml++-2.6/libxml++/dtd.h \
  /usr/include/glib-2.0/glib/deprecated/gcompletion.h \
  /usr/include/libxml++-2.6/libxml++/parsers/parser.h \
  src/node/application/distanceTest/DistanceTestPacket_m.h \
  /usr/include/glib-2.0/glib/gthread.h \
  /usr/include/glib-2.0/glib/gcharset.h \
  /usr/include/glib-2.0/glib/gbookmarkfile.h \
  src/node/communication/routing/aodvRouting/AodvRoutingPacket_m.h \
  src/node/communication/mac/MacPacket_m.h \
  /usr/include/glib-2.0/glib/gmarkup.h \
  /usr/include/libxml++-2.6/libxml++/nodes/xincludestart.h \
  /usr/include/glib-2.0/glib/gfileutils.h \
  src/attack/phyiscalattack/PhysicalAttack.h \
  src/actions/actionbase/Action.h \
  /usr/include/glib-2.0/glib/glist.h \
  /usr/include/libxml++-2.6/libxml++/nodes/textnode.h \
  src/actions/move/Move.h \
  /usr/include/glib-2.0/glib/gtrashstack.h \
  src/utils/asfpputils/utils.h \
  /usr/include/glib-2.0/glib/deprecated/gallocator.h \
  /usr/include/glib-2.0/glib/gmain.h \
  /usr/include/libxml++-2.6/libxml++/nodes/commentnode.h \
  /usr/include/glib-2.0/glib/gquark.h \
  /usr/include/glib-2.0/glib/galloca.h \
  src/node/communication/routing/multipathRingsRouting/MultipathRingsRoutingPacket_m.h \
  src/node/mobilityManager/VirtualMobilityManager.h \
  /usr/include/glib-2.0/glib/gdate.h \
  src/node/application/roomMonitoring/RoomMonitoringPacket_m.h \
  /usr/include/libxml++-2.6/libxml++/exceptions/validity_error.h \
  /usr/include/glib-2.0/glib/gurifuncs.h \
  src/actions/destroy/Destroy.h \
  /usr/include/libxml++-2.6/libxml++/attributenode.h \
  /usr/include/glib-2.0/glib/deprecated/gmain.h \
  /usr/include/glib-2.0/glib/gwin32.h \
  src/node/resourceManager/ResourceManagerMessage_m.h \
  src/actions/create/Create.h \
  /usr/include/libxml++-2.6/libxml++/validators/dtdvalidator.h \
  /usr/include/libxml++-2.6/libxml++/validators/schemavalidator.h \
  /usr/include/glib-2.0/glib/gbitlock.h \
  src/actions/clone/Clone.h \
  /usr/include/glib-2.0/glib/gprimes.h \
  src/node/communication/routing/aodvRouting/PacketId_m.h \
  /usr/include/libxml++-2.6/libxml++/parsers/saxparser.h \
  /usr/include/glib-2.0/glib/gbacktrace.h \
  src/attack/attackbase/Attack.h \
  /usr/include/glib-2.0/glib/gdataset.h \
  /usr/include/glib-2.0/glib/gbase64.h \
  /usr/include/glib-2.0/glib/gtimezone.h \
  /usr/include/libxml++-2.6/libxml++/nodes/node.h \
  src/PacketTypes.h \
  /usr/include/glib-2.0/glib/gtimer.h \
  src/actions/send/Send.h \
  /usr/include/glib-2.0/glib/gbytes.h \
  /usr/include/glib-2.0/glib/gtestutils.h \
  /usr/include/glib-2.0/glib.h \
  /usr/include/glib-2.0/glib/gvarianttype.h \
  /usr/include/glib-2.0/glib/gutils.h \
  /usr/include/glib-2.0/glib/gnode.h \
  /usr/include/glib-2.0/glib/goption.h \
  /usr/include/glib-2.0/glib/gslice.h \
  /usr/include/libxml++-2.6/libxml++/exceptions/parse_error.h \
  /usr/include/libxml++-2.6/libxml++/validators/validator.h \
  src/helpStructures/CastaliaModule.h \
  /usr/include/libxml++-2.6/libxml++/attributedeclaration.h \
  src/node/communication/routing/bypassRouting/BypassRoutingPacket_m.h \
  /usr/lib/x86_64-linux-gnu/glib-2.0/include/glibconfig.h \
  /usr/include/libxml++-2.6/libxml++/noncopyable.h \
  /usr/include/glib-2.0/glib/gdir.h \
  src/wirelessChannel/WirelessChannelMessages_m.h \
  /usr/include/glib-2.0/glib/gmem.h \
  /usr/include/libxml++-2.6/libxml++/parsers/domparser.h \
  /usr/include/glib-2.0/glib/giochannel.h \
  /usr/include/libxml++-2.6/libxml++/exceptions/exception.h \
  /usr/include/glib-2.0/glib/gasyncqueue.h \
  /usr/include/libxml++-2.6/libxml++/nodes/entitydeclaration.h \
  src/node/communication/mac/tunableMac/TunableMacPacket_m.h \
  /usr/include/glib-2.0/glib/gqueue.h \
  src/attack/conditionalattack/conditionalattack/ConditionalAttack.h \
  src/variable/Variable.h \
  /usr/include/glib-2.0/glib/gtypes.h \
  /usr/include/glib-2.0/glib/gshell.h \
  /usr/include/glib-2.0/glib/deprecated/gcache.h \
  src/parser/Parser.h \
  /usr/include/libxml++-2.6/libxml++/schema.h \
  src/helpStructures/DebugInfoWriter.h \
  /usr/include/libxml++-2.6/libxml++/libxml++.h \
  /usr/include/libxml++-2.6/libxml++/attribute.h \
  /usr/lib/libxml++-2.6/include/libxml++config.h \
  /usr/include/glib-2.0/glib/genviron.h \
  src/actions/change/Change.h \
  /usr/include/glib-2.0/glib/gconvert.h \
  src/node/communication/routing/aodvRouting/AodvRoutingDataPacket_m.h \
  src/utils/exprtk/exprtk.hpp \
  /usr/include/glib-2.0/glib/garray.h \
  src/physicalProcess/PhysicalProcessMessage_m.h \
  src/actions/retrieve/Retrieve.h \
  /usr/include/glib-2.0/glib/gsequence.h \
  /usr/include/glib-2.0/glib/deprecated/gthread.h \
  /usr/include/glib-2.0/glib/gchecksum.h \
  /usr/include/glib-2.0/glib/gkeyfile.h \
  /usr/include/glib-2.0/glib/ghash.h \
  src/attack/conditionalattack/packetfilter/FilterBlock.h \
  /usr/include/glib-2.0/glib/gerror.h \
  /usr/include/glibmm-2.4/glibmm/unicode.h \
  src/actions/drop/Drop.h \
  src/actions/asfexpression/ASFExpression.h \
  src/node/communication/mac/mac802154/Mac802154Packet_m.h \
  src/node/communication/routing/aodvRouting/AodvRoutingRrepPacket_m.h \
  src/actions/disable/Disable.h \
  /usr/include/glib-2.0/glib/gslist.h \
  /usr/include/glib-2.0/glib/gqsort.h \
  /usr/include/libxml++-2.6/libxml++/nodes/element.h \
  /usr/include/glib-2.0/glib/ghostutils.h \
  /usr/include/libxml++-2.6/libxml++/parsers/textreader.h \
  /usr/include/glib-2.0/glib/ghook.h \
  /usr/include/glib-2.0/glib/gvariant.h \
  /usr/include/glib-2.0/glib/gpattern.h \
  /usr/include/glib-2.0/glib/gversionmacros.h \
  src/actions/put/PutMessages.h \
  src/attack/unconditionalattack/UnconditionalAttack.h \
  /usr/include/glib-2.0/glib/gthreadpool.h \
  /usr/include/glib-2.0/glib/grand.h \
  /usr/include/libxml++-2.6/libxml++/exceptions/internal_error.h \
  src/node/application/valueReporting/ValueReportingPacket_m.h \
  /usr/include/libxml++-2.6/libxml++/nodes/contentnode.h \
  /usr/include/libxml++-2.6/libxml++/nodes/processinginstructionnode.h \
  /usr/include/glib-2.0/glib/gdatetime.h \
  /usr/include/glib-2.0/glib/gtree.h \
  /usr/include/glib-2.0/glib/deprecated/grel.h \
  /usr/include/libxml++-2.6/libxml++/document.h \
  /usr/include/glib-2.0/glib/gstrfuncs.h \
  /usr/include/glib-2.0/glib/gstringchunk.h \
  /usr/include/glib-2.0/glib/ggettext.h \
  src/node/communication/mac/tMac/TMacPacket_m.h \
  /usr/include/glibmm-2.4/glibmm/ustring.h \
  /usr/include/glib-2.0/glib/gstring.h \
  /usr/include/glib-2.0/glib/ghmac.h \
  /usr/include/glib-2.0/glib/gspawn.h \
  /usr/include/glib-2.0/glib/gpoll.h \
  src/node/communication/routing/RoutingPacket_m.h \
  /usr/include/libxml++-2.6/libxml++/nodes/entityreference.h
$O/src/physicalProcess/carsPhysicalProcess/CarsPhysicalProcess.o: src/physicalProcess/carsPhysicalProcess/CarsPhysicalProcess.cc \
  src/node/resourceManager/ResourceManagerMessage_m.h \
  src/CastaliaMessages.h \
  src/physicalProcess/PhysicalProcessMessage_m.h \
  src/helpStructures/DebugInfoWriter.h \
  src/physicalProcess/carsPhysicalProcess/CarsPhysicalProcess.h \
  src/helpStructures/CastaliaModule.h
$O/src/physicalProcess/customizablePhysicalProcess/CustomizablePhysicalProcess.o: src/physicalProcess/customizablePhysicalProcess/CustomizablePhysicalProcess.cc \
  src/node/resourceManager/ResourceManagerMessage_m.h \
  src/physicalProcess/customizablePhysicalProcess/CustomizablePhysicalProcess.h \
  src/CastaliaMessages.h \
  src/helpStructures/DebugInfoWriter.h \
  src/physicalProcess/PhysicalProcessMessage_m.h \
  src/helpStructures/CastaliaModule.h
$O/src/utils/asfpputils/utils.o: src/utils/asfpputils/utils.cc \
  src/node/communication/routing/RoutingPacket_m.h \
  src/node/communication/mac/mac802154/Mac802154Packet_m.h \
  src/helpStructures/DebugInfoWriter.h \
  src/helpStructures/CastaliaModule.h \
  src/utils/asfpputils/utils.h \
  src/node/communication/routing/multipathRingsRouting/MultipathRingsRoutingPacket_m.h \
  src/node/resourceManager/ResourceManagerMessage_m.h \
  src/node/communication/mac/MacPacket_m.h \
  src/CastaliaMessages.h
$O/src/variable/Variable.o: src/variable/Variable.cc \
  src/node/communication/mac/mac802154/Mac802154Packet_m.h \
  src/node/communication/routing/RoutingPacket_m.h \
  src/helpStructures/CastaliaModule.h \
  src/helpStructures/DebugInfoWriter.h \
  src/variable/Variable.h \
  src/node/resourceManager/ResourceManagerMessage_m.h \
  src/node/communication/routing/multipathRingsRouting/MultipathRingsRoutingPacket_m.h \
  src/utils/asfpputils/utils.h \
  src/CastaliaMessages.h \
  src/node/communication/mac/MacPacket_m.h
$O/src/wirelessChannel/WirelessChannel.o: src/wirelessChannel/WirelessChannel.cc \
  src/CastaliaMessages.h \
  src/node/mobilityManager/VirtualMobilityManager.h \
  src/node/resourceManager/ResourceManagerMessage_m.h \
  src/wirelessChannel/WirelessChannelMessages_m.h \
  src/helpStructures/CastaliaModule.h \
  src/helpStructures/DebugInfoWriter.h \
  src/wirelessChannel/WirelessChannel.h \
  src/wirelessChannel/WirelessChannelTemporal.h
$O/src/wirelessChannel/WirelessChannelTemporal.o: src/wirelessChannel/WirelessChannelTemporal.cc \
  src/wirelessChannel/WirelessChannelTemporal.h
