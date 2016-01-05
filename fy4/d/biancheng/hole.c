inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "����");
        set("long", @LONG
����������ָ���㣬������һ�������ң�Ҳ�����Ҳ�����ط�����ʵ���Ǹ���
����ĵط�������ǵ��оƣ���Ȼ�����źܸɾ��Ĵ����ܾ��µ�ױ̨��ױ̨�Ͼ�Ȼ
�������ʻ����ھƵ������ϣ���Ȼ���м����ܾ��µ�С�ˡ����������������俴
һ�۶���ǽ�ϵĺ�ᣣ������Ҳ����������������һ���ˣ���Ϊ�Ǻ����͸������
�޾������޺ͱ�����
LONG
        );
        set("exits", ([ 
		"up" : __DIR__"grassland7",
	]));
        set("item_desc", ([
        	"curtain":	"��ڵĲ�����ڶ�ǽ�ϣ����ܸе�����͸�������޾������޺ͱ�����\n",
        	"���":		"��ڵĲ�����ڶ�ǽ�ϣ����ܸе�����͸�������޾������޺ͱ�����\n",
        ]) );
        set("objects", ([
	]) );
	set("outdoors", "biancheng");
        set("coor/x",120);
        set("coor/y",90);
        set("coor/z",-10);
	set("map","zbwest");
	setup();

}

void init() {
        add_action("do_open", "open");
        if (this_player()->query("marks/wanma/Ѱ�ض�")) 
        	this_player()->set_temp("marks/wanma/������",1);
}

int do_open(string arg)	{
        object obj;
        object me;
        if(!arg || arg=="" || (arg!= "curtain" && arg != "���") ) {
                return notify_fail("��Ҫ��ʲô��\n");
        }else {
		me = this_player();
        	message_vision("$N����ǽ�ϵĺ�ᣣ�һ�Ȱ���ͨ����ĺ��ݡ�\n", me);
        	if( !query("exits/east") ) {
        		set("exits/east", __DIR__"hole2");
        		call_out("close_path", 1);
        	}
        }
        return 1;
}


void close_path() {
        if( !query("exits/east") ) return;
        message("vision","��ᣴ�������������ס�˰��š�\n",this_object() );
        delete("exits/east");
}


int valid_leave(object me, string arg){
	object blade;
	if (arg!="east")	return 1;
	if (me->query_temp("marks/wanma/������")) return 1;
	
	tell_object(me,BLU"һ�����ε�ѹ����ס�����ȥ·��\n"NOR);
	if (me->query("marks/wanma/ɱ����ѩ") && blade=present("black blade",me)) {
		message_vision("$N�����е�����������Ϊ�˸���ѩ�����ӣ��м����������\n");
		tell_object(me,CYN"���ڵ����ƺ���ԥ��һ�£�����ǰ��ѹ�������ˡ�\n"NOR);
		me->set_temp("marks/wanma/������",1);
	}
	return notify_fail("");
}