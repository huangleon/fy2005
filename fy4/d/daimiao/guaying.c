#include <room.h>
inherit ROOM;

void create()
{
  set("short","��ӡ���");
  set("long",@LONG
���������·����ĹŰ�����˵�Ǻ��أ�����ͦ�Σ�֦��Ҷï���������֦��
���Ӵ�֮�ϳ���һ�����ص�������Խ��Խ��һֻ��Ƥ�ĺ����ں�ͷ���Եص���������
��ǰ������һ����Բ�Ʒ���ӡ�ƣ���������˾�֮һ�ġ���ӡ��(��)������
�����������Ǻ���Ժ��
LONG
  );
  	set("exits",([
        	 "north":__DIR__"sanling",
         	
        ]));
        set("objects", ([
                
       	]) );
        set("item_desc", ([
                
        ]) );
	set("coor/x",10);
	set("coor/y",-45);
	set("coor/z",0);
	setup();
  	
}
