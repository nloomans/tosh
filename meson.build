project(
  'libftprintf',
  'c',
  license: 'GPLv3',
  default_options: [
    'c_std=c99',
    'warning_level=3',
    'werror=true',
  ]
)

inc_dir = include_directories('inc')
src_files = files([
  'src/fmt_color.c',
  'src/fmt_ntoa.c',
  'src/fmt_padding.c',
  'src/fmt_printmemory.c',
  'src/fmt_putflt.c',
  'src/fmt_puthex.c',
  'src/fmt_putnbr.c',
  'src/fmt_putoct.c',
  'src/fmt_putpercent.c',
  'src/fmt_putptr.c',
  'src/fmt_putstr.c',
  'src/fmt_putuns.c',
  'src/fmt_read.c',
  'src/fmt_utils.c',
  'src/ft_dprintf.c',
  'src/ft_fprintf.c',
  'src/ft_printf.c',
  'src/ft_sprintf.c',
  'src/parse_utils.c',
  'src/parser.c',
  'src/parser_checkers.c',
  'src/parser_segments.c',
  'src/runner.c',
  'src/std_memory.c',
  'src/std_misc.c',
  'src/std_string.c',
  'src/writer.c',
  'src/writer_utils.c',
])

test_files = files([
  'test/spec/printf_float.spec.c',
  'test/spec/printf_hex.spec.c',
  'test/spec/printf_multi.spec.c',
  'test/spec/printf_number.spec.c',
  'test/spec/printf_octal.spec.c',
  'test/spec/printf_pointer.spec.c',
  'test/spec/printf_should_fail.spec.c',
  'test/spec/printf_string.spec.c',
  'test/spec/printf_unsigned_number.spec.c',
  'test/spec/sprintf.spec.c',
  'test/spec/token_parser.spec.c',
])

libcriterion = dependency('criterion', required: false)

libftprintf = static_library(
  'ftprintf',
  sources: src_files,
  include_directories: inc_dir,
)

external_inc_dir = include_directories('.')
libftprintf_deb = declare_dependency(
  link_with: libftprintf,
  include_directories: external_inc_dir,
)

if libcriterion.found()
  tester = executable(
    'test-libfrprintf',
    sources: test_files,
    dependencies: [libcriterion],
    link_with: [libftprintf],
    include_directories: inc_dir,
  )

  test('libftprintf', tester)
endif
