#include <room.h>
inherit ROOM;

void create()
{
  set("short","�����躮");
  set("long",@LONG
����Ժһ��ԭ���ǰ��ֵأ���˵����۷�̩ɽʱ������ֲ�˶�ǧ�����������
����ǧ������д����ꡣ�Ű�֦��Ť�����ʣ�������������Ȼ�����Ŀݣ�ȴ�ּ�
����֦���ԹŴ���������Ϊ���˾�֮һ�ġ������躮����
LONG
  );
  	set("exits",([
        	 "north":__DIR__"hanbai",
         	
        ]));
        set("objects", ([
                
       	]) );
        set("item_desc", ([
                
        ]) );
	set("coor/x",20);
	set("coor/y",-45);
	set("coor/z",0);
	setup();
  	
}
