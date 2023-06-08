FROM alpine

RUN apk update && apk add \
    git \
    g++ \
    cmake \
    make

COPY ./ /Snippets/Make

WORKDIR /Snippets/Make