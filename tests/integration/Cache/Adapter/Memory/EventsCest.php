<?php

/**
 * This file is part of the Phalcon Framework.
 * (c) Phalcon Team <team@phalcon.io>
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Tests\Integration\Cache\Adapter\Memory;

use Codeception\Example;
use IntegrationTester;
use Phalcon\Cache\Adapter\Memory;
use Phalcon\Events\Event;
use Phalcon\Events\Manager;
use Phalcon\Storage\SerializerFactory;

class EventsCest
{
    /**
     * Tests Cache\Adapter\Memory :: getEventsManager()
     *
     * @author n[oO]ne <lominum@protonmail.com>
     * @since  2024-06-07
     */
    public function cacheAdapterMemoryGetEventsManagerNotSet(IntegrationTester $I): void
    {
        $I->wantToTest('Cache\Adapter\Memory - getEventsManager() - not set');

        $serializer = new SerializerFactory();
        $adapter = new Memory($serializer);

        $I->assertNull($adapter->getEventsManager());
    }

    /**
     * Tests Cache\Adapter\Memory :: getEventsManager()
     *
     * @author n[oO]ne <lominum@protonmail.com>
     * @since  2024-06-07
     */
    public function cacheAdapterMemoryGetEventsManagerSet(IntegrationTester $I): void
    {
        $I->wantToTest('Cache\Adapter\Memory - getEventsManager() - set');

        $serializer = new SerializerFactory();
        $adapter = new Memory($serializer);

        $adapter->setEventsManager(new Manager());

        $I->assertInstanceOf(Manager::class, $adapter->getEventsManager());
    }

    /**
     * Tests Cache\Adapter\Memory :: trigger cache events
     *
     * @dataProvider getEvents
     * @author n[oO]ne <lominum@protonmail.com>
     * @since  2024-06-07
     */
    public function cacheCacheEventTriggers(IntegrationTester $I, Example $example): void
    {
        $I->wantToTest('Cache\Adapter\Memory - triggered ' . $example->offsetGet(0));

        $serializer = new SerializerFactory();
        $adapter = new Memory($serializer);

        $counter = 0;
        $manager = new Manager();
        $adapter->setEventsManager(new Manager());

        // Avoid unset warning
        $adapter->set('test', 'test');

        $manager->attach(
            'cache:' . $example->offsetGet(0),
            static function (Event $event) use (&$counter, $example): void {
                $counter++;
                $data = $event->getData();
                $data === 'test' ?: throw new \RuntimeException('wrong key');
            }
        );

        $adapter->setEventsManager($manager);

        $I->assertInstanceOf($manager::class, $adapter->getEventsManager());

        call_user_func_array([$adapter, $example->offsetGet(1)], $example->offsetGet(2));
        call_user_func_array([$adapter, $example->offsetGet(1)], $example->offsetGet(2));
        $I->assertEquals(2, $counter);
    }

    public function getEvents(): array
    {
        // Event, Method, Data
        return [
            ['beforeDelete', 'delete', ['test']],
            ['afterDelete', 'delete', ['test']],
            ['beforeIncrement', 'increment', ['test']],
            ['afterIncrement', 'increment', ['test']],
            ['beforeGet', 'get', ['test']],
            ['afterGet', 'get', ['test']],
            ['beforeDecrement', 'decrement', ['test']],
            ['afterDecrement', 'decrement', ['test']],
            ['beforeHas', 'has', ['test']],
            ['afterHas', 'has', ['test']],
            ['beforeSet', 'set', ['test', 'test']],
            ['afterSet', 'set', ['test', 'test']],
        ];
    }
}
