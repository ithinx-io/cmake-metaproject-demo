#!/bin/bash
set -eou pipefail
basedir="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"

LD_LIBRARY_PATH="${basedir}/sysroot/usr/lib" "${basedir}/sysroot/usr/bin/myapp"
