#include <room.h>
inherit ROOM;

void create()
{
  set("short","����");
  set("long",@LONG
���ܵ������л��Ȱټ䣬���ʰ�������Ķ����������������»���ʮ��������
ʮ��˾�������ڣ���������ʮ��麺����ʯ�������г����䡢������赡�������
����԰��ˡ��������С�������Ϸ��˫�����¡�����������ͼ�������ǳ�����̩
ɽ�����ĺ�Ĺ�С�
LONG
  );
  	set("exits",([
        	 "east":__DIR__"xibei",
         	 "south":__DIR__"chuxun",
        ]));
        set("objects", ([
                __DIR__"npc/di" : 1,
       	]) );
        set("item_desc", ([
                
        ]) );
	set("coor/x",-20);
	set("coor/y",-20);
	set("coor/z",0);
	setup();
  	
}
