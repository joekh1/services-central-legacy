// |jit-test| debug
// Direct eval code under evalWithbindings sees both the bindings and the enclosing scope.

var g = newGlobal('new-compartment');
var dbg = new Debug(g);
var hits = 0;
dbg.hooks = {
    debuggerHandler: function (frame) {
	var code =
	    "assertEq(a, 1234);\n" +
	    "assertEq(b, null);\n" +
	    "assertEq(c, 'ok');\n";
	assertEq(frame.evalWithBindings("eval(s)", {s: code, a: 1234}).return, undefined);
	hits++;
    }
};
g.eval("function f(b) { var c = 'ok'; debugger; }");
g.f(null);
assertEq(hits, 1);