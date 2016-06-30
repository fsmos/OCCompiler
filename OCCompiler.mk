##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=OCCompiler
ConfigurationName      :=Debug
WorkspacePath          := "C:\Users\AlteR\Documents\compiler"
ProjectPath            := "C:\123\OCCompiler"
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=AlteR
Date                   :=30/06/2016
CodeLitePath           :="C:\Program Files\CodeLite"
LinkerName             :=gcc
SharedObjectLinkerName :=gcc -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.o.i
DebugSwitch            :=-g 
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=$(IntermediateDirectory)/$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E 
ObjectsFileList        :="OCCompiler.txt"
PCHCompileFlags        :=
MakeDirCommand         :=makedir
RcCmpOptions           := 
RcCompilerName         :=windres
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := ar rcus
CXX      := gcc
CC       := gcc
CXXFLAGS :=  -g -O0 -Wall $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := as


##
## User defined environment variables
##
CodeLiteDir:=C:\Program Files\CodeLite
Objects0=$(IntermediateDirectory)/main.c$(ObjectSuffix) $(IntermediateDirectory)/gstruct_gpio.c$(ObjectSuffix) $(IntermediateDirectory)/gstruct_clk.c$(ObjectSuffix) $(IntermediateDirectory)/gstruct_ssp.c$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@$(MakeDirCommand) "./Debug"


$(IntermediateDirectory)/.d:
	@$(MakeDirCommand) "./Debug"

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/main.c$(ObjectSuffix): main.c $(IntermediateDirectory)/main.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/123/OCCompiler/main.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/main.c$(DependSuffix): main.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/main.c$(ObjectSuffix) -MF$(IntermediateDirectory)/main.c$(DependSuffix) -MM "main.c"

$(IntermediateDirectory)/main.c$(PreprocessSuffix): main.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/main.c$(PreprocessSuffix) "main.c"

$(IntermediateDirectory)/gstruct_gpio.c$(ObjectSuffix): gstruct_gpio.c $(IntermediateDirectory)/gstruct_gpio.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/123/OCCompiler/gstruct_gpio.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/gstruct_gpio.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/gstruct_gpio.c$(DependSuffix): gstruct_gpio.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/gstruct_gpio.c$(ObjectSuffix) -MF$(IntermediateDirectory)/gstruct_gpio.c$(DependSuffix) -MM "gstruct_gpio.c"

$(IntermediateDirectory)/gstruct_gpio.c$(PreprocessSuffix): gstruct_gpio.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/gstruct_gpio.c$(PreprocessSuffix) "gstruct_gpio.c"

$(IntermediateDirectory)/gstruct_clk.c$(ObjectSuffix): gstruct_clk.c $(IntermediateDirectory)/gstruct_clk.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/123/OCCompiler/gstruct_clk.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/gstruct_clk.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/gstruct_clk.c$(DependSuffix): gstruct_clk.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/gstruct_clk.c$(ObjectSuffix) -MF$(IntermediateDirectory)/gstruct_clk.c$(DependSuffix) -MM "gstruct_clk.c"

$(IntermediateDirectory)/gstruct_clk.c$(PreprocessSuffix): gstruct_clk.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/gstruct_clk.c$(PreprocessSuffix) "gstruct_clk.c"

$(IntermediateDirectory)/gstruct_ssp.c$(ObjectSuffix): gstruct_ssp.c $(IntermediateDirectory)/gstruct_ssp.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/123/OCCompiler/gstruct_ssp.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/gstruct_ssp.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/gstruct_ssp.c$(DependSuffix): gstruct_ssp.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/gstruct_ssp.c$(ObjectSuffix) -MF$(IntermediateDirectory)/gstruct_ssp.c$(DependSuffix) -MM "gstruct_ssp.c"

$(IntermediateDirectory)/gstruct_ssp.c$(PreprocessSuffix): gstruct_ssp.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/gstruct_ssp.c$(PreprocessSuffix) "gstruct_ssp.c"


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Debug/


