# Amethyst Prebuilt Libraries

This repository stores the libraries amethyst uses.

## Why?

Because having all this stuff in the app repo bloats buildtimes, makes the repo clone huge, and just looks ugly for now. This makes debugging harder but the modularity makes it worth it

## Directories

The root directory contains the root project which takes all the AAR outputs of all the subprojects and puts it into `build/outputs/aar`.

Any mesa based AAR should be put under `renderers/mesa-libs/libs/<subproject_name>` for organization. Everything else should be self-explanatory, renderers go in the renderers, if you need to add a non-renderer, give it a folder.
