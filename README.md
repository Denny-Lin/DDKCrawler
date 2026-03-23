# ai-crawlflow

ai-crawlflow is a web crawler framework written in C/C++ with a modular and extensible architecture. The design focuses on simplicity, modularity, and building a foundation for AI-ready data pipelines.

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
   +--> CleanStage
   |
   +--> FilterStage
   |
   +--> ChunkStage (optional AI)
   |
   +--> EmbeddingStage (optional AI)
   │
   ▼
Storage
```

---

## Project Structure
```
DDKCrawler
├── CMakeLists.txt
│
├── include
│   └── ddkcrawler
│       ├── spider.h
│       ├── scheduler.h
│       ├── downloader.h
│       ├── parser.h
│       ├── pipeline.h
│       └── storage.h
│
├── src
│   ├── main.cpp
│   └── core
│       ├── spider.cpp
│       ├── scheduler.cpp
│       ├── downloader.cpp
│       ├── parser.cpp
│       ├── pipeline.cpp
│       └── storage.cpp
│
├── tests
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
Processes Documents through a series of modular stages.  
Supports optional AI-related stages such as text cleaning, chunking, and embedding.

### Storage
Stores processed Documents with support for structured data formats.  
Designed to be extensible for future storage backends (e.g., JSON, databases, vector storage).

---

## Features

- Modular crawler architecture  
- URL queue system  
- Parallel downloading support  
- Extensible and pluggable pipeline design  
- AI-ready data processing pipeline  

---

## Roadmap

The project is evolving towards an AI-ready data pipeline framework:

- [x] Core crawler architecture  
- [ ] Data processing pipeline enhancements  
- [ ] AI-ready pipeline stages (chunking, embedding)  
- [ ] Vector storage integration  
- [ ] Semantic search support  

---

## Language

C / C++

---

## Status

Work in progress. Actively evolving towards an AI-ready data pipeline framework.
