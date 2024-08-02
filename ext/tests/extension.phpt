--TEST--
Check if extension_example is loaded
--FILE--
<?php
if (\extension_loaded('extension_example')) {
	echo 'The extension "extension_example" is available';
}
?>
--EXPECT--
The extension "extension_example" is available
