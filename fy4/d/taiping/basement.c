#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "��Ѩ");
        set("long", @LONG
��ǰ����һƬ�ڰ���ʲôҲ��������û�к�����û�����棬Ҳû����������
�綼�Ѿ�ֹ��������ȥ�����־��������ĸо�������ͬʱ���ᵽ�˳�ʪ��������ζ��
���ﲢ������Ũ�μ��ա�������ʲô�ط���
LONG
        );
        set("exits", ([ 
		"east":  __DIR__"basement2",
	]));
	set("objects", ([
               	
    	]) );
        set("no_fly",1);
        set("item_desc", ([
	
	 ]));
	set("coor/x",0);
	set("coor/y",0);
	set("coor/z",0);
	setup();
}

