#include <ansi.h>
#include <ansi.h>
inherit ROOM;

void create()
{
    set("short", HIC"���ƽ�"NOR);
    set("long", @LONG
���ƽֵ�������������쿪ȥ���ƻ��Ƶ���������һЩС���ݣ������̣�����
��ȣ������ǹ����ƴ���ү�Ƕ���������Ľ����ã��͵������ֵ�һ��������Ҫȥ��
���Ƴ������˲�����佻��ã�����������ǧ��¥���Դӽ�Ǯ�������̻ᣬ�ķ�����
ҵ�Ժ�ǧ��¥��ͽ�Ǯ��һ�������˷��ƳǺʹ��ϱ����еļ�կ��¥��
LONG
    );
    set("exits", ([ /* sizeof() == 4 */
	"south" : __DIR__"swind31",
	"north" : __DIR__"swind2",
	"east" : __DIR__"huanyun6",
	"west" : __DIR__"huanyun1",
      ]));


    set("outdoors", "fengyun");
    set("coor/x",0);
    set("coor/y",-120);
    set("coor/z",0);
    set("map","fysouth");
    setup();
    replace_program(ROOM);
}

