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
        	"west":__DIR__"houzai",
         	"east":__DIR__ "e_wall_3",
        ]));
        set("objects", ([
        
        ]) );
        set("item_desc", ([
                
        ]) );
	set("coor/x",15);
	set("coor/y",20);
	set("coor/z",0);
	setup();
  	
}
