#include <ansi.h>
inherit ROOM;

void create()
{
    set("short", "�����");
    set("long", @LONG
��¥���ű���һ�����磬����һ���ֳ����ȡ������ҵ������������鰸����
������ضѷ���˿�ᣬ�Ǹ��ص�ͼ����־������Ϲ��Ÿ����ӣ�
    ;��ǣ��������ʯ֮��	���󲻻ڣ�����ࢲ�ľ֮ʵ
LONG
    );
    set("exits", ([ /* sizeof() == 4 */
	"down" : __DIR__"jssju",
	"up" : 	__DIR__"jssju2",
      ]));
    set("objects", ([
	__DIR__"npc/mapseller" : 1,
      ]) );

    set("coor/x",-40);
    set("coor/y",80);
    set("coor/z",10);
    set("map","fynorth");
    setup();
    replace_program(ROOM);
}

