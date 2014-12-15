#!/usr/bin/env python

import click
import pycurl
import time
from StringIO import StringIO
try:
	# python 3
	from urllib.parse import urlencode
except ImportError:
	# python 2
	from urllib import urlencode

def curl_get(url):
	buf = StringIO()
	c = pycurl.Curl()
	c.setopt(c.URL, url)
	c.setopt(c.WRITEDATA, buf)
	c.perform()
	c.close()
	body = buf.getvalue()
	return body

def curl_post(url):
	c = pycurl.Curl()
	c.setopt(c.URL, url)
	c.setopt(c.HTTPHEADER, ['Phant-Private-Key: gzgnB4VazkIg7GN1g1qA'])
	post_data = {'brewTemp':'33.4 from librae ' + str(time.time())}
	postfields = urlencode(post_data)
	c.setopt(c.POSTFIELDS, postfields)
	return c.perform()

class conf(object):

	def __init(self):
		self.debug = False

pass_config = click.make_pass_decorator(conf, ensure=True)

@click.group()
@click.option('--debug', is_flag = True)
@pass_config
def cli(opt, debug):
	'''This script get/post data.\n
	e.g.\n
	python pycurl_test.py get -k PUBLICK_KEY\n
	python pycurl_test.py post -k PUBLICK_KEY -p PRIVATE_KEY\n
	'''
	opt.debug = debug

@cli.command()
@click.option('-k', default = 'Jxyjr7DmxwTD5dG1D1Kv', help = 'public key')
@click.argument('out', type = click.File('w'), default = '-', required = False)
@pass_config
def get(opt, k, out):
	'''This command gets data.'''
	if opt.debug:
		click.echo('out: %s' %out)

	print '---- in -----'
	click.echo('k: %s' %k)

	url_base = 'http://data.sparkfun.com/output/'
	url = url_base + k + '.json'
	print curl_get(url)

@cli.command()
@click.option('-k', default = 'Jxyjr7DmxwTD5dG1D1Kv', help = 'public key')
@click.option('-p', default = 'gzgnB4VazkIg7GN1g1qA', help = 'private key')
@pass_config
def post(opt, k, p):
	'''This command posts data.'''
	if opt.debug:
		click.echo('debug')

	print '---- in -----'
	click.echo('k: %s' %k)
	click.echo('p: %s' %p)

	url_base = 'http://data.sparkfun.com/input/'
	url = url_base + k
	print curl_post(url)

# Below lines are used to run this script directly in python env:
if __name__ == '__main__':
	cli()
