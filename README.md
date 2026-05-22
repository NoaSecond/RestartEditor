# RestartEditor

Unreal Engine plugin for quickly restarting the editor from inside a project.

## Overview

RestartEditor is an Unreal Engine plugin that helps developers restart the editor without manually closing and reopening the project.

## Features

- Restart the Unreal Editor from the current session

## Requirements

- An Unreal Engine project
- A compatible Unreal Engine version for this plugin
- Access to the project’s `Plugins` directory

Supported Platforms

- Windows (Win64)
- macOS
- Linux

## Installation

1. Copy the `RestartEditor` plugin folder into your project’s `Plugins` directory.
	- Example: `YourProject/Plugins/RestartEditor`
2. Open the project in Unreal Engine.
3. If prompted, enable the plugin and rebuild the project.
4. Restart the editor if Unreal requests it.

## Setup

1. Open your project in Unreal Engine.
2. Navigate to **Edit > Plugins**.
3. Search for **RestartEditor**.
4. Enable the plugin.
5. Restart Unreal Engine if required.

## Usage

After installation, use the restart action exposed by the plugin from the editor. The exact location may vary depending on your project integration, but the typical workflow is:

1. Save any open work.
2. Trigger the plugin’s restart command.
3. Confirm restart prompt.
4. Wait for the editor to close and relaunch the project.

## Troubleshooting

### Plugin does not appear in the Plugins window

- Verify the plugin is located in the correct `Plugins` folder.
- Verify the plugin archive has been fully extracted (unzipped).
- Confirm the `.uplugin` file exists.
- Remove the `Binaries` and `Intermediate` folders from the plugin directory.
- Regenerate project files and reopen the project.


### Unreal asks to rebuild

- Make sure the plugin version matches your Unreal Engine version.
- Rebuild the project from your IDE or the Unreal Editor.

### Restart does not happen

- Confirm the plugin is enabled.
- Check the Unreal output log for errors.
- Save all files before retrying.

## License

This plugin is distributed under the Fab Standard License.

## Support

For issues, feature requests or support, please open an issue on the
project repository or contact the author:

- Repository: https://github.com/NoaSecond/RestartEditor
- Author: Noa Second — https://noasecond.com