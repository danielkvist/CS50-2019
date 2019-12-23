import cs50
import csv

from flask import Flask, jsonify, redirect, render_template, request

# Configure application
app = Flask(__name__)

# Reload templates when they are changed
app.config["TEMPLATES_AUTO_RELOAD"] = True


@app.after_request
def after_request(response):
    """Disable caching"""
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response


@app.route("/", methods=["GET"])
def get_index():
    return redirect("/form")


@app.route("/form", methods=["GET"])
def get_form():
    return render_template("form.html")


@app.route("/form", methods=["POST"])
def post_form():
    if request.form.get("name") == "":
        return render_template("error.html", message="You need to provide a name")
    if request.form.get("gender") == "":
        return render_template("error.html", message="You need to select a gender")
    if request.form.get("language") == "":
        return render_template("error.html", message="You need to select a programming language")
    if request.form.get("agree") == "":
        return render_template("error.html", message="You need to agree")

    with open("./survey.csv", "a") as file:
        csv_file = csv.writer(file, delimiter=",")
        csv_file.writerow([
            request.form.get("name"),
            request.form.get("gender"),
            request.form.get("language"),
            request.form.get("agree")
        ])

    return redirect("/sheet")


@app.route("/sheet", methods=["GET"])
def get_sheet():
    records = []
    with open("./survey.csv", "r") as file:
        csv_file = csv.reader(file)
        for row in csv_file:
            records.append(row)

    return render_template("sheet.html", records=records)
