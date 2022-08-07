
docker-build:
	docker build . -t game-dev-builder:latest

compile:
	docker run -v $(shell pwd):/app -w /app/build game-dev-builder:latest /bin/bash -c "cmake .. && make"

run:
	build/game-dev