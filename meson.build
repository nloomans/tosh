project(
	'tosh',
	'c',
	version: '0.0.1',
	default_options: [
		'warning_level=3',
		'werror=true',
	]
)

src_files = files()
test_files = files()

subdir('src/bootstrap')
subdir('src/env')
subdir('src/error')
subdir('src/lexer')
subdir('src/parser')
subdir('src/term')

main_file = files('src/bootstrap/main.c')

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

executable(
	'tosh',
	sources: src_files + main_file,
	dependencies: [libft_deb, libftprintf_deb, libcurses_deb],
)

libcriterion_deb = dependency('criterion', required: false)

if libcriterion_deb.found()
	tester = executable('test-tosh',
		sources: src_files + test_files,
		dependencies:
			[libft_deb, libftprintf_deb, libcurses_deb, libcriterion_deb])

	test('tosh', tester)
endif

norminette = find_program('norminette', required: false)

if norminette.found()
	test('norm',
		find_program('scripts/meson-norminette'),
		args: src_files + main_file)
endif

test('header',
	find_program('scripts/addheader'),
	args: '-n')
