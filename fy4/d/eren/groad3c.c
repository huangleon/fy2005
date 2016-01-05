inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "С��");
        set("long", @LONG
һ������������С·�������м��úܸߴ��ɼ��������ɫ�������ϣ��ܿ���͹
������˰�һ���Ͱ���ȥ�����۾�һ�������ڣ�֦Ҷïʢ�����������˸�����Ժ��
�С���ֻ����֨���������֦�ϴ��ţ�һ�ξͲ����ˡ�С·��ͷ�����֡� 
LONG
        );
        set("exits", ([ 
		"west" : __DIR__"groad3b",
		"east" : __DIR__"groad4",
		]));
        set("objects", ([
        	__DIR__"npc/boy1": 1,
		]) );
		set("item_desc", ([
        	"ɼ��":	"�ܸߴ��ɼ����֦Ҷïʢ�����������˸�����Ժ���С�\n",
		]) );
		set("outdoors", "eren");
        set("coor/x",80);
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
        object me;
        
        me= this_player();
        
        if( arg!="tree" && arg!="ɼ��") {
        	tell_object(this_player(),"��Ҫ��ʲô��\n");
        	return 1;
        }

		if (me->query_skill("move",1)< 50) {
        	tell_object(me,"�������ԣ�û��������ȥ������50���Ṧ��\n");
        	return 1;
        }
        
        if (me->is_busy()|| me->is_fighting()){
        	tell_object(me,"��������æ��\n");
        	return 1;
        }
        	
        message_vision("$N�ֽŲ��ã����ݵ�������·�Ե�ɼ����\n",this_player());
        tell_room(__DIR__"tree", this_player()->name() + "����������������\n");
        me->move(__DIR__"tree");
        
        return 1;
}
