#include <room.h>
inherit ROOM;

void create()
{
  set("short","ǽ��С��");
  set("long",@LONG
���Բ������ܽ��г�ǽ��ǽ�����������н�¥����¥��ǽ����Ұ�ݵأ�
����������죬���ǻ�����ԭ������������ֻ�ǽ���������������������̳��
Ѱ���˵����Խ��룬����̩ɽҲֻ�дӳ�ǽ����·�ˡ�
LONG
  );
  	set("exits",([
        	"north":__DIR__"w_wall_3",
         	"south":__DIR__ "xihua",
        ]));
        set("objects", ([
        	__DIR__"npc/daoshi":	3,
                
       	]) );
        set("item_desc", ([
                
        ]) );
	set("coor/x",-30);
	set("coor/y",-10);
	set("coor/z",0);
	setup();
  	
}
