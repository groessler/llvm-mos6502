set(LLVM_TARGET_DEFINITIONS MOS6502.td)

tablegen(LLVM MOS6502GenRegisterInfo.inc -gen-register-info)
tablegen(LLVM MOS6502GenInstrInfo.inc -gen-instr-info)
tablegen(LLVM MOS6502GenAsmWriter.inc -gen-asm-writer)
tablegen(LLVM MOS6502GenDAGISel.inc -gen-dag-isel)
tablegen(LLVM MOS6502GenCallingConv.inc -gen-callingconv)
tablegen(LLVM MOS6502GenSubtargetInfo.inc -gen-subtarget)
add_public_tablegen_target(MOS6502CommonTableGen)

add_llvm_target(MOS6502CodeGen
  MOS6502BranchSelector.cpp
  MOS6502ISelDAGToDAG.cpp
  MOS6502ISelLowering.cpp
  MOS6502InstrInfo.cpp
  MOS6502FrameLowering.cpp
  MOS6502MachineFunctionInfo.cpp
  MOS6502RegisterInfo.cpp
  MOS6502Subtarget.cpp
  MOS6502TargetMachine.cpp
  MOS6502SelectionDAGInfo.cpp
  MOS6502AsmPrinter.cpp
  MOS6502MCInstLower.cpp
  )

add_subdirectory(InstPrinter)
add_subdirectory(TargetInfo)
add_subdirectory(MCTargetDesc)
