# data_sanitizer
# Data Sanitization & Type Handling Drills

**Objective:** To demonstrate robust handling of unstructured, messy data across both dynamically typed (Python) and statically typed (C++) environments.

**Why this matters for AI Training:** Large Language Models (LLMs) and automated pipelines frequently ingest unpredictable user inputs. These scripts demonstrate how to programmatically guard against bad data, prevent runtime crashes, and enforce strict type safety before passing data to larger systems.

## 🐍 Python Implementation (`data_sanitizer.py`)
Python allows lists to contain mixed data types natively, which can lead to silent errors in production. This script uses strict type-checking and guard clauses to sanitize inputs safely.

* **Time Complexity:** **O(n)**, where *n* is the number of items in the list. The loop processes each item exactly once.
* **Space Complexity:** **O(n)** in the worst-case scenario.
* **Highlights:** * Implemented `isinstance()` for strict type-checking rather than relying on broad `try/except` blocks.
  * Included early-return guard clauses to handle empty inputs efficiently.

## ⚙️ C++ Implementation (`data_sanitizer.cpp`)
C++ is statically typed and does not natively support "mixed lists." To mirror the Python logic, this script utilizes modern C++ features to safely parse and store mixed data.

* **Time Complexity:** **O(n * m)**, where *n* is the number of strings and *m* is the length of the string (for trimming and capitalization operations).
* **Space Complexity:** **O(n)** for the resulting vector.
* **Highlights:**
  * Uses **C++17 `std::variant`** to safely hold either integers or strings within a single vector.
  * Implements custom helper functions for whitespace trimming and numeric validation (`std::isdigit`).
  * Demonstrates memory-safe string parsing without relying on external libraries.
