# code7bit by katahiromz

This tool is dirty 8-bit characters converter.

This tool converts dirty 8-bit characters into 3-digit octal
escape sequences (`\OOO`) or universal character name escape
sequences (`\uXXXX`), and vice versa.

If a dirty character exists in `L"..."`, then it will be
converted to an universal character name.

If a dirty character exists out of `L"..."`, then it will
be converted to a 3-digit octal escape sequence.

For more details, execute `code7bit --help`.

katayama.hirofumi.mz@gmail.com
