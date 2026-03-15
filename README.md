# DDKCrawler

DDKCrawler is a **web crawler framework written in C/C++** designed with a modular architecture.

The design focuses on a simple and modular architecture inspired by modern crawler frameworks.

---

## Architecture
```
Spider
   │
   ▼
Scheduler
   │
   ▼
Downloader
   │
   ▼
Parser
   │
   ▼
Pipeline
   │
   ▼
Storage
```

---

## Project Structure
```
DDKCrawler
├── include
│ ├── spider.h
│ ├── scheduler.h
│ ├── downloader.h
│ ├── parser.h
│ ├── pipeline.h
│ └── storage.h
│
├── src
│ ├── main.cpp
│ └── core
│ ├── spider.cpp
│ ├── scheduler.cpp
│ ├── downloader.cpp
│ ├── parser.cpp
│ ├── pipeline.cpp
│ └── storage.cpp
│
├── legacy
│
├── README.md
└── .gitignore
```
---

## Modules

### Spider
Defines crawling logic and starting URLs.

### Scheduler
Manages the queue of URLs waiting to be crawled.

### Downloader
Handles network connections and downloads web pages or resources.

### Parser
Extracts links or data from downloaded content.

### Pipeline
Processes extracted data.

### Storage
Stores the final results.

---

## Features

- Modular crawler architecture  
- URL queue system  
- Parallel downloading support  

---

## Language

C / C++

---

## Status

Work in progress.
