inherit ROOM;
#include <ansi.h>

string view(string room);
string *rooms = ({__DIR__"e_wall1",__DIR__"e_wall2",__DIR__"e_wall3",__DIR__"w_wall1",
		__DIR__"w_wall2",__DIR__"w_wall3",__DIR__"village",__DIR__"v_gate" });
string *rooms2 = ({__DIR__"e_wall1",__DIR__"e_wall2",__DIR__"e_wall3",__DIR__"w_wall1",
		__DIR__"w_wall2",__DIR__"w_wall3",__DIR__"v_gate" });
		
void create()

{
        set("short", "ï�ܵĴ�����");
        set("long", @LONG
��ʹ�����̵ľ��������ϵ��������������ܸߣ�Ҳ���ܣ��˶��������ڵ�����
ʵʵ���������Ͽ������������������ǧ���ˣ������绪�ǣ�������ʮ�׼�������
�����۴�ϸ�������������ϴ������棬���ٴ��������������ν��ľ���֡�������
Ҷ�����濴ȥ����ϡ�����и�կ�ӣ����ﵹ����죨����������ĺõط���
LONG
        );
        set("exits", ([ 
		"down" : __DIR__"forest4",
	]));
        set("objects", ([
	]) );
	set("item_desc", ([
		"����":  "�����������ɣ��е�����ͨ����կ�ӵ��Ϸ����������������ȥ�Ļ�������\n",
		"����":  "�����������ɣ��е�����ͨ����կ�ӵ��Ϸ����������������ȥ�Ļ�������\n",
		"trunk": "�����������ɣ��е�����ͨ����կ�ӵ��Ϸ����������������ȥ�Ļ�������\n",
		"����": "�����������ɣ��е�����ͨ����կ�ӵ��Ϸ����������������ȥ�Ļ�������\n",
	]) );
	set("outdoors", "zangbei");
    set("coor/x",-1560);
    set("coor/y",620);
    set("coor/z",20);
	setup();
}


void init(){

	add_action("do_jump","jump");
	add_action("do_scout","scout");
}


int do_jump(string arg) {
	
	object me;
	
	me=this_player();
	if (arg=="down" || arg == "����" || arg== "����" || arg == "����" ||arg=="trunk") {
		if (me->query_temp("zangbei/treejump_1"))
			return notify_fail("�����ڿ��У��޴�������\n");
		message_vision("$N˳���������ĵ�����կǽ�Ϸ���һ����������ȥ��\n\n",me);
		call_out("pass_river",5,me);
		me->start_busy(3);
		me->set_temp("zangbei/treejump_1",1);
		return 1;
	}
	tell_object(me,"��Ҫ���Ķ�����\n");
	return 1;
}


int pass_river(object me) {
	object room;
	string room_name;
	if (!objectp(me) || me->is_ghost()) return 0;
	room_name=rooms2[random(sizeof(rooms2))];
	room=find_object(room_name);
	if (!objectp(room)) room=load_object(room_name);
	tell_object(me,"���ڰ����һ�����������ɵ����¡�\n");
	message("vision",me->name()+"�ӿ�������������\n",room);
	me->move(room);
	me->delete_temp("zangbei/treejump_1");
	return 1;
}

int do_scout(){
	object me;
	string room;
	
	me = this_player();
	message_vision(HIG"$N������֦��С�����������������\n"NOR, me);
	room = rooms[random(sizeof(rooms))];
	tell_object(me, view(room));
	if (room == __DIR__"village")
		QUESTS_D->special_reward(me,"����կ��ʵ");
	
	return 1;
}

string view(string room) {
	int i;
	object *inv,env;
	mapping exits;
	string roomdesc, str, *dirs;
	
	env = find_object(room);

	if(!env) env=load_object(room);	
	
	str = "���������ؿ���������\n\n";
	
	// room descriptions.
	str += sprintf( "%s\n    %s \n    %s",
			env->query("short"),
			env->query("long"),
			env->query("outdoors")? NATURE_D->outdoor_room_description() : "" );

	// all things in the room.
	inv = all_inventory(env);
	for(i=0; i<sizeof(inv); i++) {
		if( inv[i]->query("no_shown") ) {
			continue;
		}
		str += "  " + inv[i]->short() + "\n";
	}
	return str;
}

