inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "����������");
        set("long", @LONG
���๱�����ɹ���������ǰ�������㿴��������֦��һ���ޱ��޼ʵ�ɡ����ס
�����⣬��ס����գ����ó�ʪ����Ҷ�ڽ��·�����֨�����������ܵ���֦������
��Ұ�ݲ�ʱ��סȥ·������ÿ��һ��·��Ҫͣ����ЪһЪ����������Ũ�ص���ʪ��
Ϣ������������
LONG
        );
        set("exits", ([ 
		"west" : __DIR__"diyugu",
		"eastup":  __DIR__"nianqing",
	]));
        set("objects", ([
	]) );
	set("outdoors", "zangbei");
        set("coor/x",-1710);
        set("coor/y",620);
        set("coor/z",0);
	set("map","zbwest");
	setup();

}
