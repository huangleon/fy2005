//mac's zhengyan
#include <room.h>
inherit ROOM;
void create()
{
  	set("short","������");
  	set("long",@LONG
���������������ţ�Ҳ�ǵ���֮�ţ��������ߣ��Ϸ�����֮��Ҳ��������һ
�����͵ĵ��۴��ţ����ɸߵ���שΧǽ�����������������ߴ��ʵ�����������
����Ȼ�𾴣�С�ݵ��һ����ң������š�
LONG
  );
  	set("exits",([
        	"north":__DIR__"peitian",
         	"south":__DIR__"daimiao",
         	"west" :__DIR__"w_yemen",
         	"east" :__DIR__"e_yemen",
         	"up":	__DIR__"wufenglou",
               ]));
        set("objects", ([
		__DIR__"npc/guard2c":	2,
                
       	]) );
	set("coor/x",0);
	set("coor/y",-50);
	set("coor/z",0);
	setup();
}
