#include <room.h>
inherit ROOM;

void create()
{
  set("short","��Ҵ��");
  set("long",@LONG
�����������С����Ҵ�š������Ժ����Χ����ǽ���ܻ�������а˸��ţ�
�������ţ���Ϊ����������ΪҴ�ţ�Ҵ�����࣬��Ϊ���ߣ���Ϊ���󡣶�����������
�ֳ��������������������ֳ��ؾ������Žк��ء�
LONG
  );
  	set("exits",([
        	"west":__DIR__"zhengyan",
         	"east":__DIR__ "yanggao",
         	"southwest": __DIR__"daimiao",
        ]));
        set("objects", ([
        
        ]) );
        set("item_desc", ([
                
        ]) );
	set("coor/x",20);
	set("coor/y",-50);
	set("coor/z",0);
	setup();
  	
}