FROM gcc:latest

COPY . /usr/local/project_folder

WORKDIR /usr/local/project_folder

RUN apt-get update && apt-get install -y make

RUN make

CMD [ "./main" ]