// Setting a breakpoint in a script we are no longer debugging is an error.

load(libdir + "asserts.js");

var g = newGlobal('new-compartment');
var dbg = Debug();
var gobj = dbg.addDebuggee(g);
g.eval("function f() { return 2; }");

var s;
dbg.hooks = {debuggerHandler: function (frame) { s = frame.eval("f").return.script; }};
g.eval("debugger;");
assertEq(s.live, true);
s.setBreakpoint(0, {});  // ok

dbg.removeDebuggee(gobj);
assertThrowsInstanceOf(function () { s.setBreakpoint(0, {}); }, Error);