# API Usage

[TOC]

## Table of Contents
+ Introduction
+ How to get started
+ Starting with an example
+ Important points to note
+ Some of the API functions explained in detail
+ How to profile
+ How to use editor for development
+ Do's and Don't's

## Introduction

## How to get Started

This project is designed to be linked to your project with cmake. To link with cmake, install the dependencies as described [here](docs/build.md).
  After that, link it to cmake as follows using the following code as an example.
  ```cmake
  cmake_minimum_required(VERSION 3.13)
  project(YourProject)
  set(CMAKE_CXX_STANDARD 20)
  set(CHRONOS_INCLUDE_DIR path/to/Chronos/include)
  include_directories(BEFORE ${CHRONOS_INCLUDE_DIR})
  
  #add your stuff here
  
  add_subdirectory(path/to/Chronos)
  target_link_libraries(YourProject Chronos)
  ```


## Starting with an example

## Important points to note

## Some of the API functions explained in detail

## How to profile

## How to use editor for development

## Do's and Don't's
