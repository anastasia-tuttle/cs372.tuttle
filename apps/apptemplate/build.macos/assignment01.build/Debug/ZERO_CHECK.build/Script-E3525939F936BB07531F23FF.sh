#!/bin/sh
set -e
if test "$CONFIGURATION" = "Debug"; then :
  cd /Users/alewis/projects/cs372.lewis.sp22v2/apps/apptemplate/build.macos
  make -f /Users/alewis/projects/cs372.lewis.sp22v2/apps/apptemplate/build.macos/CMakeScripts/ReRunCMake.make
fi
if test "$CONFIGURATION" = "Release"; then :
  cd /Users/alewis/projects/cs372.lewis.sp22v2/apps/apptemplate/build.macos
  make -f /Users/alewis/projects/cs372.lewis.sp22v2/apps/apptemplate/build.macos/CMakeScripts/ReRunCMake.make
fi
if test "$CONFIGURATION" = "MinSizeRel"; then :
  cd /Users/alewis/projects/cs372.lewis.sp22v2/apps/apptemplate/build.macos
  make -f /Users/alewis/projects/cs372.lewis.sp22v2/apps/apptemplate/build.macos/CMakeScripts/ReRunCMake.make
fi
if test "$CONFIGURATION" = "RelWithDebInfo"; then :
  cd /Users/alewis/projects/cs372.lewis.sp22v2/apps/apptemplate/build.macos
  make -f /Users/alewis/projects/cs372.lewis.sp22v2/apps/apptemplate/build.macos/CMakeScripts/ReRunCMake.make
fi

