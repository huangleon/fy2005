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
         	"south":__DIR__"e_wall_1",
         	"west": __DIR__"chuihua",
         	"north": __DIR__"e_wall_2",
        ]));
        set("objects", ([
                __DIR__"npc/guard2b": 2,
       	]) );
        set("item_desc", ([
                
        ]) );
	set("coor/x",30);
	set("coor/y",-30);
	set("coor/z",0);
	setup();
  	
}
