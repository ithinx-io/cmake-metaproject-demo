#!/bin/bash
set -eou pipefail
basedir="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"

cd "${basedir}"

# cleanup
./cleanup.sh

# prepare (out of source) build
echo 'Preparing...'
mkdir workdir && cd workdir
cmake ../source

# build
echo 'Building...'
#cmake --build .
make -j$(nproc)
