inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "С��");
        set("long", @LONG
һ������������С·�������м��úܸߴ��ɼ��������ɫ�������ϣ��ܿ���͹
������˰�һ���Ͱ���ȥ�����۾�һ�������ڣ�֦Ҷïʢ�����������˸�����Ժ��
�С���ֻ����֨���������֦�ϴ��ţ�һ�ξͲ����ˡ�С·�����Ǵ�ӡ� 
LONG
        );
        set("exits", ([ 
	"west" : __DIR__"groad3a",
	"east" : __DIR__"groad3c",
	"north": __DIR__"vhouse2",
	]));
        set("item_desc", ([
        	"ɼ��":	"�ܸߴ��ɼ����֦Ҷïʢ�����������˸�����Ժ���С�\n",
	]) );
	set("outdoors", "eren");
        set("coor/x",70);
        set("coor/y",90);
        set("coor/z",0);
	set("map","eren");
	setup();
}


void init()
{
        add_action("do_climb", "climb");
}

int do_climb(string arg)
{
        if( arg!="tree" && arg!="ɼ��") {
        	tell_object(this_player(),"��Ҫ��ʲô��\n");
        	return 1;
        }
       	return notify_fail("��̫�ߣ��������ԣ�û��������ȥ��\n");

}

