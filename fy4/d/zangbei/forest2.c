inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "����");
        set("long", @LONG
���������ߣ���һ���ߴ�ï�ܵ�ɭ�֣�������������ȴ��ļž������ţ���Ŀ
���ǽ�Ҷ�Ϳݲݡ�Ұ�޴�������ţ��е����Ļţ�������������޷����ܣ��·�
��ɭ�ֵĽ��ɫ����ɪ�У���һ�������������Ȼ�����ڴ��������� 
LONG
        );
        set("exits", ([ 
		"northwest" : __DIR__"forest1",
	]));
        set("objects", ([
	]) );
	set("item_desc",([
		"grass": "���ϵĿ�Ҷ���������Ҳ��֪�Ѿ����˶������ˡ�\n",
		"�ݲ�": "���ϵĿ�Ҷ���������Ҳ��֪�Ѿ����˶������ˡ�\n",
		"��Ҷ": "���ϵĿ�Ҷ���������Ҳ��֪�Ѿ����˶������ˡ�\n",
	
	]) );
	set("outdoors", "zangbei");
        set("coor/x",-1580);
        set("coor/y",660);
        set("coor/z",0);
	set("map","zbwest");
	setup();

}


void init() {
	add_action("do_listen","listen");
	add_action("do_look","look");
	add_action("do_south","go");
}

int do_listen() {
	object me;
	me=this_player();
	tell_object(me,"���������������������ء�������\n");
	tell_object(me,"��ֻ��֪���Ķ����Ȼ������󴩹����굽����������ﲻ���ˡ�\n");
	me->set_temp("marks/listen_milin",1);
	return 1;
}


int do_look(string arg) {
	object me;
	me=this_player();
	if (me->query_temp("marks/listen_milin"))
	if (arg=="south" || arg =="����" || arg =="��" || arg =="���������") {
		tell_object(me,"��ϸ����Ұ����ʧ�ķ���ȥ���㷢���������ľ�Ƚ�ϡ�裬�ƺ����˾����߹���\n");
		me->set_temp("marks/enter_milin",1);
		return 1;
	}
	return 0;
}


int do_south (string arg)
{
   	object me, room;
   	me = this_player();
	
	if (arg == "south")
   	if(me->query_temp("marks/enter_milin")) {
   		tell_object(me, "�㲦����֦����������������ȥ��\n\n");
   		message("vision", me->name(me)+"��������ת�˼�ת��ʧȥ����Ӱ��\n", environment(me),me );
   		room = find_object(__DIR__"forest3");
   		if(!objectp(room)) room=load_object(__DIR__"forest3");
      		me->move(room);
      		return 1;
   	}
   	return 0;
}