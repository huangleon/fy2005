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
        	"north":__DIR__"donghua",
         	"south":__DIR__ "yanggao",
        ]));
        set("objects", ([
        
        ]) );
        set("item_desc", ([
                
        ]) );
	set("coor/x",30);
	set("coor/y",-40);
	set("coor/z",0);
	setup();
  	
}
