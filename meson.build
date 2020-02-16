project(
  'tosh',
  'c',
  version: '0.0.1',
  default_options: [
    'warning_level=3',
    'werror=true',
  ]
)

add_project_arguments(
  '-DVERSION="' + meson.project_version() + '"',
  language: 'c'
)

cc = meson.get_compiler('c')

libft_proj = subproject('libft')
libft_deb = libft_proj.get_variable('libft_deb')

libftprintf_proj = subproject('libftprintf')
libftprintf_deb = libftprintf_proj.get_variable('libftprintf_deb')

libcurses_deb = cc.find_library('curses', required: false)
if not libcurses_deb.found()
	libcurses_deb = dependency('ncurses')
endif

src_files = files([
  'src/bootstrap/tosh.c',
  'src/error/errorf.c',
  'src/error/is_error.c',
  'src/term/configure.c',
  'src/term/getcursor.c',
  'src/term/init.c',
  'src/term/send.c',
])

main_file = files('src/bootstrap/main.c')

executable(
  'tosh',
  sources: src_files + main_file,
  dependencies: [libft_deb, libftprintf_deb, libcurses_deb],
)

libcriterion_deb = dependency('criterion', required: false)

if libcriterion_deb.found()
  test_files = src_files + files([
    'src/error/errorf_test.c',
    'src/error/is_error_test.c',
  ])

  tester = executable('test-tosh',
    sources: test_files,
    dependencies: [libft_deb, libftprintf_deb, libcurses_deb, libcriterion_deb])

  test('tosh', tester)
endif
