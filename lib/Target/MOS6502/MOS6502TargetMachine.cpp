#include "MOS6502TargetMachine.h"

using namespace llvm;

extern "C" void LLVMInitializeMOS6502Target() {
  // Register the target.
  RegisterTargetMachine<MOS6502TargetMachine> X(TheMOS6502Target);
}

extern "C" void LLVMInitializeSparcAsmPrinter() {
  // Register printing assembly code.
  // FIXME: Implement this goodness
  // RegisterAsmPrinter<SparcAsmPrinter> X(TheSparcTarget);
}

MOS6502TargetMachine::MOS6502TargetMachine(const Target &T, StringRef TT,
      StringRef CPU, StringRef FS,
      const TargetOptions &Options,
      Reloc::Model RM, CodeModel::Model CM,
      CodeGenOpt::Level OL)
    : LLVMTargetMachine(T, TT, CPU, FS, Options, RM, CM, OL),
    Subtarget(TT, CPU, FS, *this) {
  initAsmInfo();
}


MOS6502TargetMachine::MOS6502TargetMachine(const Module &M, const std::string &FS)
  // FIXME: No idea about the ABI alignment of the C64 kernel. Guessing 8 for now.
  // FIXME: I don't actually think we have an ABI... Are these needed?
  : DataLayout("e-p:16:8-i8"),
  // NOTE: The stack pointer decrements.
  FrameInfo(TargetFrameInfo::StackGrowsUp, 8, 0)  {}




/** Stuff I still have yet to implement
class MOS6502TargetMachine : public LLVMTargetMachine {
  const DataLayout DataLayout;       // Calculates type size & alignment
  MOS6502Subtarget Subtarget;
  MOS6502InstrInfo InstrInfo;
  TargetFrameInfo FrameInfo;

protected:
  virtual const TargetAsmInfo *createTargetAsmInfo() const;

public:
  MOS6502TargetMachine(const Module &M, const std::string &FS);

  virtual const MOS6502InstrInfo *getInstrInfo() const {return &InstrInfo; }
  virtual const TargetFrameInfo *getFrameInfo() const {return &FrameInfo; }
  virtual const TargetSubtarget *getSubtargetImpl() const{return &Subtarget; }
  virtual const TargetRegisterInfo *getRegisterInfo() const {
    return &InstrInfo.getRegisterInfo();
  }
  virtual const DataLayout *getDataLayout() const { return &DataLayout; }
  static unsigned getModuleMatchQuality(const Module &M);

  // Pass Pipeline Configuration
  virtual bool addInstSelector(PassManagerBase &PM, bool Fast);
  virtual bool addPreEmitPass(PassManagerBase &PM, bool Fast);
};
*/

} // end namespace llvm
