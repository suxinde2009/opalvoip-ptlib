#include "vidinput_names.h"

void  V4LXNames::ReadDeviceDirectory(PDirectory devdir, POrdinalToString & vid)
{
  if (!devdir.Open())
    return;

  do {
    PString filename = devdir.GetEntryName();
    PString devname = devdir + filename;
    if (devdir.IsSubDir())
      ReadDeviceDirectory(devname, vid);
    else {

      PFileInfo info;
      if (devdir.GetInfo(info) && info.type == PFileInfo::CharDevice) {
	struct stat s;
	if (lstat(devname, &s) == 0) {
	 
	  static const int deviceNumbers[] = { 81 };
	  for (PINDEX i = 0; i < PARRAYSIZE(deviceNumbers); i++) {
	    if (MAJOR(s.st_rdev) == deviceNumbers[i]) {

	      PINDEX num = MINOR(s.st_rdev);
	      if (num <= 63 && num >= 0) {
		vid.SetAt(num, devname);
	      }
	    }
	  }
	}
      }
    }
  } while (devdir.Next());
}

void V4LXNames::PopulateDictionary()
{
  PINDEX i, j;
  PStringToString tempList;

  for (i = 0; i < inputDeviceNames.GetSize(); i++) {
    PString ufname = BuildUserFriendly(inputDeviceNames[i]);
    tempList.SetAt(inputDeviceNames[i], ufname);
  }

  //Now, we need to cope with the case where there are two video
  //devices available, which both have the same user friendly name.
  //Matching user friendly names have a (X) appended to the name.
  for (i = 0; i < tempList.GetSize(); i++) {
    PString userName = tempList.GetDataAt(i); 

    PINDEX matches = 1;    
    for (j = i + 1; j < tempList.GetSize(); j++) {
      if (tempList.GetDataAt(j) == userName) {
	matches++;
        PStringStream revisedUserName;
        revisedUserName << userName << " (" << matches << ")";
        tempList.SetDataAt(j, revisedUserName);
      }
    }
  }

  //At this stage, we have correctly modified the temp list of names.
  for (j = 0; j < tempList.GetSize(); j++)
    AddUserDeviceName(tempList.GetDataAt(j), tempList.GetKeyAt(j));  
}

PString V4LXNames::GetUserFriendly(PString devName)
{
  PWaitAndSignal m(mutex);

  
  PString result= deviceKey(devName);
  if (result.IsEmpty())
    return devName;

  return result;
}

PString V4LXNames::GetDeviceName(PString userName)
{
  PWaitAndSignal m(mutex);

  for (PINDEX i = 0; i < userKey.GetSize(); i++)
    if (userKey.GetKeyAt(i).Find(userName) != P_MAX_INDEX)
      return userKey.GetDataAt(i);

  return userName;
}

void V4LXNames::AddUserDeviceName(PString userName, PString devName)
{
  if (userName != devName) { // must be a real userName!
    userKey.SetAt(userName, devName);
    deviceKey.SetAt(devName, userName);
  } else { // we didn't find a good userName
    if (!deviceKey.Contains (devName)) { // never met before: fallback
      userKey.SetAt(userName, devName);
      deviceKey.SetAt(devName, userName);
    } // no else: we already know the pair
  }
}


/*
  There is a duplication in the list of names.
  Consequently, opening the device as "ov511++" or "/dev/video0" will work.
*/
PStringList V4LXNames::GetInputDeviceNames()
{
  PWaitAndSignal m(mutex);
  PStringList result;
  for (PINDEX i = 0; i < inputDeviceNames.GetSize(); i++) {
    result += GetUserFriendly (inputDeviceNames[i]);
    result += inputDeviceNames[i];
  }
  return result;
}
