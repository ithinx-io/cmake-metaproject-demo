#!/bin/bash
set -eou pipefail
basedir="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"

cd "${basedir}"

# cleanup
echo 'Cleaning up...'
rm -rf sysroot build workdir
