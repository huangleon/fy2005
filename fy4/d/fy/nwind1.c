#include <ansi.h>
inherit ROOM;

void create()
{
    set("short", HIY"���������"NOR);
    set("long", @LONG
��̳�����ǿ����ĺ�����֣����Ե�̨ͤ��Է�ûʻ�������ͷ�����Ͻ��ǣ���
����������Ӻ�ݣ���ɫ�ư����ټҵĴ�δ���Ϣ�����漰�ڽ��������¶����˵�
ʥ�ع�Ժ�����������ϴ��أ�ˮɫī�̣��ټ������Ľ�ʿ�����ڴ��������̡�
LONG
    );
    set("exits", ([ /* sizeof() == 4 */
	"south" : __DIR__"tiandoor",
	"north" : __DIR__"nwind2",
	"east" : __DIR__"ponder",
	"west" : __DIR__"jidijie",
      ]));
    set("outdoors", "fengyun");
    set("objects", ([
	__DIR__"npc/zhu": 1,
	//	__DIR__"npc/xiwei": 4,
      ]) );

    set("coor/x",0);
    set("coor/y",80);
    set("coor/z",0);
    set("map","fynorth");
    setup();
}
