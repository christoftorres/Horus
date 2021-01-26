{
  structLogs: [],

  step: function(log, db) {
    switch(log.op.toString()) {
      case "ADD": case "SUB": case "MUL":
        this.structLogs.push({"op": log.op.toString(), "stack": [log.stack.peek(1), log.stack.peek(0)], "depth": log.getDepth(), "contract": toHex(log.contract.getAddress()), "error": log.getError()});
        break;
      case "SSTORE":
        this.structLogs.push({"op": log.op.toString(), "stack": [log.stack.peek(1), log.stack.peek(0)], "depth": log.getDepth(), "contract": toHex(log.contract.getAddress()), "error": log.getError()});
        break;
      case "SLOAD":
        this.structLogs.push({"op": log.op.toString(), "stack": [log.stack.peek(0)], "depth": log.getDepth(), "contract": toHex(log.contract.getAddress()), "error": log.getError()});
        break;
      case "CREATE": case "CREATE2":
        this.structLogs.push({"op": log.op.toString(), "stack": [log.stack.peek(2), log.stack.peek(1), log.stack.peek(0)], "memory": toHex(log.memory.slice(log.stack.peek(1).valueOf(), log.stack.peek(1).valueOf() + log.stack.peek(2).valueOf())), "depth": log.getDepth(), "contract": toHex(log.contract.getAddress()), "error": log.getError()});
        break;
      case "CALL": case "CALLCODE":
        this.structLogs.push({"op": log.op.toString(), "stack": [log.stack.peek(4), log.stack.peek(3), log.stack.peek(2), toHex(toAddress(log.stack.peek(1).toString(16))), log.stack.peek(0)], "memory": toHex(log.memory.slice(log.stack.peek(3).valueOf(), log.stack.peek(3).valueOf() + log.stack.peek(4).valueOf())), "depth": log.getDepth(), "contract": toHex(log.contract.getAddress()), "error": log.getError()});
        break;
      case "DELEGATECALL": case "STATICCALL":
        this.structLogs.push({"op": log.op.toString(), "stack": [log.stack.peek(3), log.stack.peek(2), toHex(toAddress(log.stack.peek(1).toString(16))), log.stack.peek(0)], "memory": toHex(log.memory.slice(log.stack.peek(2).valueOf(), log.stack.peek(2).valueOf() + log.stack.peek(3).valueOf())), "depth": log.getDepth(), "contract": toHex(log.contract.getAddress()), "error": log.getError()});
        break;
      case "SELFDESTRUCT": case "SUICIDE":
        this.structLogs.push({"op": log.op.toString(), "stack": [db.getBalance(log.contract.getAddress()), toHex(toAddress(log.stack.peek(0).toString(16)))], "depth": log.getDepth(), "contract": toHex(log.contract.getAddress()), "error": log.getError()});
        break;
      case "LOG3":
        this.structLogs.push({"op": log.op.toString(), "stack": [toHex(toAddress(log.stack.peek(4).toString(16))), toHex(toAddress(log.stack.peek(3).toString(16))), log.stack.peek(2).toString(16), log.stack.peek(1), log.stack.peek(0)], "memory": toHex(log.memory.slice(log.stack.peek(0).valueOf(), log.stack.peek(0).valueOf() + log.stack.peek(1).valueOf())), "depth": log.getDepth(), "contract": toHex(log.contract.getAddress()), "error": log.getError()});
        break;
      case "SHA3":
        this.structLogs.push({"op": log.op.toString(), "stack": [log.stack.peek(1), log.stack.peek(0)], "depth": log.getDepth(), "contract": toHex(log.contract.getAddress()), "error": log.getError()});
        break;
      default:
        this.structLogs.push({"op": log.op.toString(), "stack": [log.stack.peek(0)], "depth": log.getDepth(), "contract": toHex(log.contract.getAddress()), "error": log.getError()});
    }
  },

  fault: function(log, db) {},

  result: function(ctx, db) {
    return {"gas": ctx.gasUsed, "structLogs": this.structLogs};
  }
}
