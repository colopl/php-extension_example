<?php

/**
 * @generate-class-entries
 * @undocumentable
 */

namespace Colopl\ExtensionExample {
    /**
     * @strict-properties
     * @not-serializable
     */
	final class Sodium implements \Random\Engine
	{
		public function generate(): string {}
		public function getCallCount(): int {}
	}

	function get_sodium_version(): string {}
}
