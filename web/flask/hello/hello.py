from flask import Flask, request, url_for, render_template

app = Flask(__name__)

@app.route('/')
def index():
	    return 'Index Page'

@app.route('/hello/')
@app.route('/hello/<name>')
def hello(name=None):
	return render_template('hello.html', name=name)

@app.route('/user/<username>')
def show_user_profile(username):
	# show the user profile for that user
	return 'User %s' % username

@app.route('/post/<int:post_id>')
def show_post(post_id):
	# show the post with the given id, the id is an integer
	return 'Post %d' % post_id

@app.route('/projects/')
def projects():
	return 'The project page'

@app.route('/about')
def about():
	return 'The about page'

@app.route('/func/<func>')
def run_func(func):
	return 'func name: %s' % func

@app.route('/login', methods=['GET', 'POST'])
def login():
	print 'login entry'
	if request.method == 'POST':
		print 'calling do_the_login'
		do_the_login()
	else:
		print 'calling show_the_login_form'
		show_the_login_form()
	return 'login process done'

def do_the_login():
	"""doc for do_the_login"""
	print 'do_the_login'

def show_the_login_form():
	"""doc for show_the_login_form"""
	print 'show_the_login_form'

with app.test_request_context():
	print url_for('static', filename='style.css')

if __name__ == '__main__':
	app.run(debug=True)
