FROM gcc:latest

COPY . /usr/local/project_folder

WORKDIR /usr/local/project_folder

RUN make

CMD [ ./main ]