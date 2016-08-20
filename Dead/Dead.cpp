//Got many headers with same name like CFG.h ,IntinsicInst.h,...

#include "llvm/Transforms/Scalar.h"
#include "llvm/IR/BasicBlock.h"
#include "llvm/IR/Instructions.h"
#include "llvm/IR/IntrinsicInst.h"
#include "llvm/Pass.h"
#include "llvm/IR/CFG.h"
#include "llvm/Support/Compiler.h"
#include "llvm/IR/InstIterator.h"
#include "llvm/ADT/DepthFirstIterator.h"
#include "llvm/ADT/SmallPtrSet.h"
#include "llvm/ADT/SmallVector.h"
#include "llvm/ADT/Statistic.h"

using namespace llvm;


#define DEBUG_TYPE "newdce"      //for debuging
STATISTIC(NumRemoved, "Number of instructions removed");    // compute no of instructions removed


namespace {
  struct NEWDCE : public FunctionPass {
    static char ID;
    NEWDCE() : FunctionPass(ID) {}      // constructor for initializing new pass with id
    
    virtual bool runOnFunction(Function& F);
    
    virtual void getAnalysisUsage(AnalysisUsage& AU) const {
      //AU.addRequired<livevars>
      AU.setPreservesCFG();    //not modifying cgf
    }
    
  };
}



char NEWDCE::ID = 0;
static RegisterPass<NEWDCE> X("newdce", "New Dead Code Elimination");      // registering pass with name newdce.





//overriding runOnFunction() wich will perform 
bool NEWDCE::runOnFunction(Function& F) {

  SmallPtrSet<Instruction*, 32> alive;          //set for keeping alive instruction
  SmallVector<Instruction*, 128> worklist;      
  
  //Collect here the set of instructions that are live.....
  
  // use  this set to remove dead instructions.......
  

}



