# flatconfig

A super simple header-only library for reading flat config files that look like:

```
some_foo: 4
barbarbar: bar bar, bar!

# you choose whether it's a float or double by calling getFloat() or getDouble()
some_float_or_double: 3.1416
```

Usage looks like:
```
farfetchd::ConfigReader config;
if (!config.parseFile("test.cfg")) // could also parseStringBlob()
  cout << "it failed somehow. we're too simple to care about details." << endl;

std::optional<int> foo = config.getInt("some_foo");
std::optional<std::string> bar = config.getString("barbarbar");
std::optional<double> baz = config.getDouble("some_float_or_double");
```

Comments are supported (start line with #). Inline comments are ok for numeric
values, but getString() will happily include any #s it sees on that line.

flatconfig is very laid back about malformed lines. If it doesn't like a line -
missing colon, numeric conversion throws an exception - it just skips it, as if
the line wasn't there, and goes on parsing the rest. No exceptions thrown (or
propagated), no other indication anything went wrong.
