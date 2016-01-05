inherit ROOM;
#include <ansi.h>
void create()
{
    set("short",HIG"������"NOR);
    set("long", @LONG
���������Ƕ������ˣ���������ͨ��ɽ���һ��·�����ź������ĳ���û��ʲ
ô��ͬ�����������˸�ʾ��ͨ�����˵���������������ڶ��ű��˷��֣�����
�˹ٸ���ץס�ġ��������м��������۵ĺ췿���ǳ����ؾ�����Ӫ��
LONG
    );
    set("exits", ([ /* sizeof() == 4 */
	"east" : __DIR__"egate",
	"west" : __DIR__"ecloud4",
	"south" : __DIR__"barracks1",
      ]));
    set("objects", ([
	__DIR__"npc/dtz": 2,
      ]) );

    set("outdoors", "fengyun");
    set("coor/x",280);
    set("coor/y",0);
    set("coor/z",0);
    set("map","fyeast");
    setup();
}



int valid_leave(object me, string dir)
{
    object *inv, ob;
    int i;

    if( userp(me))
    {
	if (dir == "east" && me->query_temp("annie/xiangsi_enterance") == 3)
	    me->set_temp("annie/xiangsi_enterance",4);
	else
	    me->delete_temp("annie/xiangsi_enterance");
    }
    return 1;
}
