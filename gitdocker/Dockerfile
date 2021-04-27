FROM ubuntu:20.04
ADD ./data /mnt/files
EXPOSE 8801
RUN apt update
RUN apt install -y cowsay python3 && cd /usr/bin && ln -s python3 python
CMD ["python", "-m", "http.server", "-d", "/mnt/files/", "8801"]


