--TEST--
extension_example engine test
--FILE--
<?php

$engine = new \Random\Randomizer(new \Colopl\ExtensionExample\Sodium());

echo $engine->nextInt(), \PHP_EOL;

?>
--EXPECTF--
%d
