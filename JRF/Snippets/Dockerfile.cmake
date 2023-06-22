FROM alpine

RUN apk update && apk add \
    git \
    g++ \
    cmake \
    make \
    clang-extra-tools \
    doxygen

COPY ./ /Snippets

WORKDIR /Snippets