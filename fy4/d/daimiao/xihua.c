#include <room.h>
inherit ROOM;

void create()
{
  	set("short","������");
  	set("long",@LONG
������ܸ�ǽΧ�ƣ����С������š����ֳơ������������С������š�����
�ơ��ؾ������ǰ�������۶�Ϊ��ۡ���Ϊ�׵۶������ġ�
LONG
  );
  	set("exits",([
		"north": __DIR__"w_wall_2",
         	"south":__DIR__"w_wall_1",
         	"east": __DIR__"chuxun",
        ]));
        set("objects", ([
		__DIR__"npc/guard2a": 2,
       	]) );
        set("item_desc", ([
                
        ]) );
	set("coor/x",-30);
	set("coor/y",-30);
	set("coor/z",0);
	setup();
  	
}
