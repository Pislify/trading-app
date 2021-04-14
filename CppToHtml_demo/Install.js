var WshShell   = WScript.CreateObject("WScript.Shell");
var strDesktop = WshShell.SpecialFolders("Desktop");
var oShellLink = WshShell.CreateShortcut(strDesktop + "\\cpp2tml.lnk");


var scriptFullName = WScript.ScriptFullName;
var lastBackslash  = scriptFullName.lastIndexOf("\\");
var fullpath       = scriptFullName.substr(0, lastBackslash + 1);
var fullExeName    = fullpath + "cpptohtml.exe";

oShellLink.TargetPath       = fullExeName;
oShellLink.WindowStyle      = 1;
oShellLink.Arguments        = "/C";
oShellLink.Hotkey           = "CTRL+ALT+T";
oShellLink.Description      = "Shortcut to cpp2html.exe";
oShellLink.WorkingDirectory = fullpath;
oShellLink.Save();
