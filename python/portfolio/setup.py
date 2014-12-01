from setuptools import setup

setup(
	name = 'Portfolio',
	version = '0.1',
	py_modules = ['port'],
	include_package_data = True,
	install_requires = [
		'Click',
	],
	entry_points = '''
		[console_scripts]
		port = port:cli
	''',
)
