FROM ubuntu:jammy
LABEL author="https://github.com/aBARICHELLO/godot-ci/graphs/contributors"

USER root
ENV DEBIAN_FRONTEND=noninteractive
RUN apt-get update && apt-get install -y \
  build-essential \
  scons \
  pkg-config \
  libx11-dev \
  libxcursor-dev \
  libxinerama-dev \
  libgl1-mesa-dev \
  libglu-dev \
  libasound2-dev \
  libpulse-dev \
  libudev-dev \
  libxi-dev \
  libxrandr-dev \
  git \
  mingw-w64

RUN git clone https://github.com/emscripten-core/emsdk.git
RUN cd emsdk && git pull

RUN cd emsdk && ./emsdk install latest
RUN cd emsdk && ./emsdk activate latest
RUN echo ". /emsdk/emsdk_env.sh" >> /root/.bashrc
RUN echo "export EM_CONFIG=/emsdk/.emscripten " >> ~/.bashrc
# RUN cd emsdk && . ./emsdk_env.sh


  
ARG GODOT_VERSION="4.1"
ARG RELEASE_NAME="stable"
ARG SUBDIR=""
ARG GODOT_TEST_ARGS=""
ARG GODOT_PLATFORM="linux.x86_64"

