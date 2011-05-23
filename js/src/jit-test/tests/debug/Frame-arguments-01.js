// |jit-test| debug
// Frame.prototype.arguments with primitive values

var g = newGlobal('new-compartment');
g.args = null;
var dbg = new Debug(g);
var hits;
var v;
dbg.hooks = {
    debuggerHandler: function (frame) {
        hits++;
        var args = frame.arguments;
        assertEq(args, frame.arguments);
        assertEq(args.length, g.args.length);
        for (var i = 0; i < args.length; i++)
            assertEq(args[i], g.args[i]);
    }
};

// no formal parameters
g.eval("function f() { debugger; }");

hits = 0;
g.eval("args = []; f();");
g.eval("this.f();");
g.eval("args = ['hello', 3.14, true, false, null, undefined]; " +
       "f('hello', 3.14, true, false, null, undefined);");
g.eval("args = [-0, NaN, -1/0]; this.f(-0, NaN, -1/0);");
assertEq(hits, 4);

// with formal parameters
g.eval("function f(a, b) { debugger; }");

hits = 0;
g.eval("args = []; f();");
g.eval("this.f();");
g.eval("args = ['a', 'b']; f('a', 'b');");
g.eval("this.f('a', 'b');");
g.eval("f.bind(null, 'a')('b');");
assertEq(hits, 5);