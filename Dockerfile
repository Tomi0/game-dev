FROM gcc:12-bullseye

RUN apt-get update && apt-get install -y libsdl2-dev cmake