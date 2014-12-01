import click

class Config(object):

	def __init(self):
		self.debug = False

pass_config = click.make_pass_decorator(Config, ensure=True)

@click.group()
@click.option('--debug', is_flag = True)
@click.option('--path', type = click.Path())
@pass_config
def cli(opt, debug, path):
	'''This script calculates portfolio.'''
	opt.debug = debug
	if path is None:
		path = '.'
	opt.path = path

@cli.command()
@click.option('--string', default = 'm',
		help = 'This is the thing that is greeted.')
@click.option('-f', default = 1.0,
		help = 'initial fund')
@click.option('-g', default = 0.0,
		help = 'growth')
@click.argument('out', type = click.File('w'), default = '-',
		required = False)
@pass_config
def eval(opt, string, f, g, out):
	'''This command evaluates portfolio.'''
	if opt.debug:
		click.echo('opt path: %s' %opt.path)
		click.echo('string: %s' %string)
		click.echo('f: %f' %f)
		click.echo('g: %f' %g)
		click.echo('out: %s' %out)
	click.echo('Hello %s!' %string, file = out)
	r = pow(1.0 + g, 12)
	click.echo('y: %f' %r)
