--TEST--
extension_example basic test
--FILE--
<?php

$test = new \Colopl\ExtensionExample\Sodium();
echo $test->getCallCount(), \PHP_EOL;
$test->generate();

echo $test->getCallCount(), \PHP_EOL;
$test->generate();

echo $test->getCallCount(), \PHP_EOL;
$test->generate();

$test = new \Colopl\ExtensionExample\Sodium();
echo $test->getCallCount(), \PHP_EOL;
$test->generate();

echo \Colopl\ExtensionExample\get_sodium_version(), \PHP_EOL;

try {
	\serialize(new \Colopl\ExtensionExample\Sodium());
} catch (\Exception $e) {
	echo $e->getMessage(), \PHP_EOL;
}

?>
--EXPECTF--
0
1
2
0
%d.%d.%d
Serialization of 'Colopl\ExtensionExample\Sodium' is not allowed
