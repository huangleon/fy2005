//Sinny@fengyun
//All Rights Reserved
#include <ansi.h>
inherit ROOM;
void create()
{
    set("short", HIW"���Ƴ�"NOR);
    set("long", @LONG
ԶԶ��ȥ����ǽ�������������һ����ˮ�������Ƴǣ�ȽȽ���С���ԫ֮�ϣ�
����¥ͤ������֮�����Ʋ�����׭�����������֣�

                    ��        ��         ��

LONG
    );
    set("exits", 
      ([ 
	"out" : __DIR__"hillroad2",
	"south" : __DIR__"skystreet",
	// 	     "west"  : __DIR__"beach1",
	// 	     "east"  : __DIR__"beach2",
      ]));
    set("objects", 
      ([ 
	__DIR__"npc/guard5" : 1,
	__DIR__"npc/guard4" : 1,
      ]));
    set("outdoors", "baiyun");
    set("coor/x",0);
    set("coor/y",-120);
    set("coor/z",30);
    setup();

}


int valid_leave(object me, string dir)
{
   	if (QUESTS_D->verify_quest(me,"������ʤ"))
		QUESTS_D->special_reward(me,"������ʤ");
	return ::valid_leave(me, dir);		
	
}

