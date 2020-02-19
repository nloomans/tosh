# Macrosoft TOSH

tosh (Twenty One SHell), is our [Codam] project for [21sh].

[Codam]: https://www.codam.nl/en/
[21sh]: https://web.archive.org/web/20200219161628/https://cdn.intra.42.fr/pdf/pdf/3512/21sh.en.pdf

## Compiling

To compile this project, install the following packages:

- `meson`
- `ninja`
- `pkg-config`

Then build the project using:

```
meson build
cd build
ninja
./tosh
```

## Tests

To run the tests, run `ninja test` from within the build directory. Install
[`criterion`](https://github.com/Snaipe/Criterion) if you also want to run the
unit tests.

## Utilities

The are a few useful utilities in the `scripts` directory.
- `addheader`: Automatically adds header to .c and .h files which don't have
  one.
- `mkmod`: Create the boilerplate files for a new module.
