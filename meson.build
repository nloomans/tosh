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

libft_proj = subproject('libft')
libft_deb = libft_proj.get_variable('libft_deb')

libftprintf_proj = subproject('libftprintf')
libftprintf_deb = libftprintf_proj.get_variable('libftprintf_deb')

src_files = files([
  'src/bootstrap/main.c',
  'src/bootstrap/tosh.c',
])

executable(
  'tosh',
  sources: src_files,
  dependencies: [libft_deb, libftprintf_deb],
)
