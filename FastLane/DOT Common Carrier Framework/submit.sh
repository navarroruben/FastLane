#!/bin/bash

VERSION_NUMBER="3.0"

#ansi codes
RED='\e[1;31m'
GREEN='\e[1;32m'
BLUE='\e[1;34m'
#HIGHLITE='\e[1;33;41m'
HIGHLITE='\e[1m\e[36m\e[45m'
NC='\e[0m' # No Color

echo -e   "  ${BLUE}Running submit script version ${VERSION_NUMBER}${NC}"
THISHOST=$(hostname -s)
if ! [ $THISHOST = "shell" ] && ! [ $THISHOST = "quake" ] && ! [ $THISHOST = "diablo" ] ; then
  echo -e "  ${RED}host = $THISHOST - check your login"
  echo -e "  submit script failure${NC}"
  exit 1
else
  echo -e "  ${BLUE}host = $THISHOST${NC}"
fi

if [ $# -lt 1 ]; then
  DELIVERABLES="deliverables.sh"
  echo -e "  ${BLUE}no argument supplied for configuration file name - using default name 'deliverables.sh'${NC}"
else 
  DELIVERABLES=$1
fi

if [ ! -f $DELIVERABLES ] ; then
  echo -e "  ${RED} ** Error - cannot find file '$DELIVERABLES'${NC}"
  exit 1
fi

source $DELIVERABLES

# these variables should now be defined:
#COURSE_HOME=cop0000p
#ASSIGNMENT=projectX
#FILES="xxx yyy zzz"

echo -e "\nSubmission script configured for:"
echo -e "\n  Course home:   $COURSE_HOME"
echo -e "  Assignment:    $ASSIGNMENT"
echo -e "  Deliverables:  $FILES"
echo -n -e "\nto continue press <enter>, to exit press Ctrl-C"
read

echo -n " 1: Archiving..."

if [ -f Makefile ]; then
  mv Makefile makefile
fi

tar -cvf $ASSIGNMENT.tar $FILES >& /dev/null
declare -i tarcode=$?

if [ "$tarcode" -gt 0 ]
then
  echo -e "\n${RED} ** Archiving failure - likely due to missing deliverables${NC}"
  echo -e "    ${RED}Deliverables expected: $FILES${NC}"
else
  echo " successful"
fi

echo -n " 2: Mailing ..."

gzip $ASSIGNMENT.tar
uuencode $ASSIGNMENT.tar.gz < $ASSIGNMENT.tar.gz > $ASSIGNMENT
cat $ASSIGNMENT | tr -d \\r | mail -s "$ASSIGNMENT submission" $COURSE_HOME
elmcode=$?

if [ "$elmcode" -gt 0 ]
then
  echo -e "\n${RED} ** Mailing failure - check your 'mail' services at this login${NC}"
  # exit 1
else
  echo " successful"
fi

echo -n " 3: Cleaning up ..."
rm -f ./$ASSIGNMENT
rm -f ./$ASSIGNMENT.tar.gz
echo -e " successful\nDone"

#echo -e "  tar return code: $tarcode"
#echo -e "  elm return code: $elmcode"

exit 0

# below is used for assignment 0 only

if [ "$ASSIGNMENT" == "assign0" ]; then
  grep -m 1 -i 'fsu username:' info.txt >& /dev/null
  grepcode=$?
  if [ "$grepcode" -gt 0 ]
  then
    echo -e "${RED}\n ** info.txt is incomplete\n    Failed to locate fsu username${NC}"
  fi
else
  grepcode=0
fi

#echo -e " grep return code: $grepcode"
