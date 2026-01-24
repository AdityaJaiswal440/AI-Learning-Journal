from flask import Flask

app=Flask(__name__)

@app.route("/")
def Welcome():
    return "Welcome to Best Ever Flask app.It would be an amazing app."

@app.route("/index")
def index():
    return "Welcome to Index Page."

if __name__ == "__main__":
    app.run(debug=True)