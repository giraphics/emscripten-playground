# !/bin/bash

EMSDK_URL="https://github.com/emscripten-core/emsdk.git"

# Get location of the script itself
SOURCE="${BASH_SOURCE[0]}"
while [ -h "$SOURCE" ]; do # resolve $SOURCE until the file is no longer a symlink
    DIR="$( cd -P "$( dirname "$SOURCE" )" && pwd )"
    SOURCE="$(readlink "$SOURCE")"
    [[ $SOURCE != /* ]] && SOURCE="$DIR/$SOURCE" # if $SOURCE was a relative symlink, we need to resolve it relative to the path where the symlink file was located
done
PROJECT_ROOT="$( cd -P "$( dirname "$SOURCE" )" && pwd )"

# Set the destination paths
EMSDK_ROOT="$PROJECT_ROOT/third-party/emsdk"

pull_install_latest_emscripten_sdk() {
    WORKING_DIR=`pwd`

    # Either clone or get latest emscripten
    if [ ! -d "$EMSDK_ROOT" ]
    then
        echo 'Make directory for emscripten'
        mkdir -p "$EMSDK_ROOT"

        echo "Cloing.. emscripten"
        git clone $EMSDK_URL $EMSDK_ROOT
    else
        echo "Change directory into the emscripten"
        cd "$EMSDK_ROOT"

        echo "Pull the emscripten down to the latest"
        git pull
    fi

    pushd $EMSDK_ROOT 
        # Download and install the latest SDK tools.
        ./emsdk install latest

        # Make the "latest" SDK "active" for the current user. (writes .emscripten file)
        ./emsdk activate latest

        # Activate PATH and other environment variables in the current terminal
        source ./emsdk_env.sh
    popd

    # Navigate back
    cd "$WORKING_DIR"
}

pull_install_latest_emscripten_sdk
