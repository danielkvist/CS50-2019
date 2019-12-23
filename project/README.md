# RECOMMMEND - A project to CS50 2019

## What is RECOMMMEND

RECOMMMEND is a simple webapp that enables users recommend anonymously his favorite artists and get random recommendations from others users.

## Where did the idea come from

The idea came to me while I was watching a video non-related to CS50 about APIs like the ones provided by companies like Spotify and Twilio.

## Stack used

I'm using the Go programming language for the backend, PostgreSQL as the database and almost pure HTML, CSS3 and JS for the frontend.

Instead of write things like the database management I'm using a framework for Go called Buffalo. Which provides useful tools to start web-based projects like this.

## Why I'm not using Python

I like Python but I prefer Go. For me is easier to start coding my ideas in Go than in Python.

Maybe in the future I will redo this project in Python only for learning for the moment I have prefered to used only Go.

## How it works

The functionality of the webapp is very simple. It offers the user two options when he enters the site. The first one is to do a recommendation, which in this case consist in a very simple form to insert the name of his favourite artist.

Once the user submits the form a request is made to the Spotify's API to check if the received artist exists or not. If it does, it adds it to the database for future recommendations and notifies the user that everything went well after redirect him to the home page. If the artist did not exist an alert notifies the user about the issue.
If what the user wants is to get a recommendation he can go to another page where he will receive the latest recommended artist as a recommendation with a link to its Spotify's profile.

## Source code and other links

* The source code can be found [here](https://github.com/danielkvist/recommmend).
* The homepage for the Go programming language can be found [here](https://golang.org/).
* The Buffalo project homepage [here](https://gobuffalo.io/en).
* And more information about the Spotify API [here](https://developer.spotify.com/).