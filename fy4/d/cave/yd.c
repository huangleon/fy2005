// Copyright (C) FengYun Workshop
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ROOM;
string ring();
void create()
{
        set("short", "������");
        set("long", @LONG
���߷�Բ�������¶��൱�Ĵ�����������ŵ�һ�����������˼���վ����
ס�������Լÿʮ������һյ�͵ƣ����в������൱�ĺڰ���������������Ҳ��
ʪ��ż���㻹�о��õ���΢΢�Ŀ���������
LONG
        );
    set("exits", ([ /* sizeof() == 4 */
  		"south" : __DIR__"td",
	]));
	set("item_desc", ([
		"����" : (: ring :),
		"tiehuan" : (: ring :),
		"ring" : (: ring :),
	]));	
        set("indoors", "cave");
	set("coor/x",-5);
	set("coor/y",20);
	set("coor/z",0);
	setup();
}

string ring(){
	object me;
	me = this_player();
	tell_object(me, "��ע�⵽����ͷ��һ�������ƺ����������������죩��\n");
	add_action("do_pull", "pull");
	return "";
}

int do_pull(string arg){
	object me, room;
	me = this_player();
	if(!arg || (arg != "ring" && arg != "tiehuan" && arg != "����")){
		return notify_fail("��Ҫ��ʲô��\n");
	}
        message_vision("$N����б�£���������һ�¾�ͷ��������\n", me);
//	        if(!query("exits/up")){
		message_vision("ֻ����֨֨һ�������ʶ���������¶����һ�����ϵĶ��ڡ�\n", me);
//		set("exits/up", "/d/fycycle/road3");	
		room = find_object("/d/fycycle/road3");
		if(!objectp(room)){
			room = load_object("/d/fycycle/road3");
		}
		message_vision("$Nһ�����������ɵ�Ծ�����ڡ�\n\n",me);
		me->move("d/fycycle/road3");
//		room->set("exits/down", "/d/cave/yd");
//		call_out("close_path", 5, room);
//	}
	return 1;	
}

int close_path(object room){
	write("�����������ʶ����������й����ˡ�\n");
	room->delete("exits/down");
	delete("exits/up");
	return 1;
}
