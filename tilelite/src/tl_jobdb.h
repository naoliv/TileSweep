#pragma once

#include <memory>
#include <vector>
#include "tl_math.h"

typedef struct tl_jobdb tl_jobdb;
struct tl_job {
  std::vector<vec2d> coordinates;
};

struct tl_jobdb {
  sqlite3* db = nullptr;
  sqlite3_stmt* query_jobs = nullptr;
  ~tl_jobdb();
};

tl_jobdb* tl_jobdb_open(const char* file_name);
std::vector<tl_job> tl_jobdb_unfinished_jobs(tl_jobdb* db);