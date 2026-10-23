{
  structLogs: [],

  step: function(log, db) {
    switch(log.op.toString()) {
      case "ADD": case "SUB": case "MUL":
        this.structLogs.push({"op": log.op.toString(), "stack": [log.stack.peek(1), log.stack.peek(0)], "depth": log.getDepth(), "contract": toHex(log.contract.getAddress()), "error": log.getError(), "pc": log.getPC()});
        break;
      case "SSTORE":
        /* "old": the slot's value before this write, read from live EVM state (step runs before the opcode executes). */
        this.structLogs.push({"op": log.op.toString(), "stack": [log.stack.peek(1), log.stack.peek(0)], "old": toHex(db.getState(log.contract.getAddress(), toWord(log.stack.peek(0).toString(16)))), "depth": log.getDepth(), "contract": toHex(log.contract.getAddress()), "error": log.getError(), "pc": log.getPC()});
        break;
      case "SLOAD":
        this.structLogs.push({"op": log.op.toString(), "stack": [log.stack.peek(0)], "depth": log.getDepth(), "contract": toHex(log.contract.getAddress()), "error": log.getError(), "pc": log.getPC()});
        break;
      case "CREATE": case "CREATE2":
        this.structLogs.push({"op": log.op.toString(), "stack": [log.stack.peek(2), log.stack.peek(1), log.stack.peek(0)], "memory": log.stack.peek(2).valueOf() > 0 ? toHex(log.memory.slice(log.stack.peek(1).valueOf(), log.stack.peek(1).valueOf() + log.stack.peek(2).valueOf())) : "", "depth": log.getDepth(), "contract": toHex(log.contract.getAddress()), "error": log.getError(), "pc": log.getPC()});
        break;
      case "CALL": case "CALLCODE":
        this.structLogs.push({"op": log.op.toString(), "stack": [log.stack.peek(4), log.stack.peek(3), log.stack.peek(2), log.stack.peek(1), log.stack.peek(0)], "memory": log.stack.peek(4).valueOf() > 0 ? toHex(log.memory.slice(log.stack.peek(3).valueOf(), log.stack.peek(3).valueOf() + log.stack.peek(4).valueOf())) : "", "depth": log.getDepth(), "contract": toHex(log.contract.getAddress()), "error": log.getError(), "pc": log.getPC()});
        break;
      case "DELEGATECALL": case "STATICCALL":
        this.structLogs.push({"op": log.op.toString(), "stack": [log.stack.peek(3), log.stack.peek(2), log.stack.peek(1), log.stack.peek(0)], "memory": log.stack.peek(3).valueOf() > 0 ? toHex(log.memory.slice(log.stack.peek(2).valueOf(), log.stack.peek(2).valueOf() + log.stack.peek(3).valueOf())) : "", "depth": log.getDepth(), "contract": toHex(log.contract.getAddress()), "error": log.getError(), "pc": log.getPC()});
        break;
      case "SELFDESTRUCT": case "SUICIDE":
        this.structLogs.push({"op": log.op.toString(), "stack": [db.getBalance(log.contract.getAddress()), log.stack.peek(0)], "depth": log.getDepth(), "contract": toHex(log.contract.getAddress()), "error": log.getError(), "pc": log.getPC()});
        break;
      case "LOG3":
        this.structLogs.push({"op": log.op.toString(), "stack": [log.stack.peek(4), log.stack.peek(3), log.stack.peek(2), log.stack.peek(1), log.stack.peek(0)], "memory": log.stack.peek(1).valueOf() > 0 ? toHex(log.memory.slice(log.stack.peek(0).valueOf(), log.stack.peek(0).valueOf() + log.stack.peek(1).valueOf())) : "", "depth": log.getDepth(), "contract": toHex(log.contract.getAddress()), "error": log.getError(), "pc": log.getPC()});
        break;
      case "SHA3":
        this.structLogs.push({"op": log.op.toString(), "stack": [log.stack.peek(1), log.stack.peek(0)], "depth": log.getDepth(), "contract": toHex(log.contract.getAddress()), "error": log.getError(), "pc": log.getPC()});
        break;
      default:
        this.structLogs.push({"op": log.op.toString(), "stack": log.stack.length() > 0 ? [log.stack.peek(0)] : [], "depth": log.getDepth(), "contract": toHex(log.contract.getAddress()), "error": log.getError(), "pc": log.getPC()});
    }
  },

  fault: function(log, db) {},

  result: function(ctx, db) {
    return {"gas": ctx.gasUsed, "structLogs": this.structLogs};
  }
}
