#include <ansi.h>
inherit ROOM;

string view(string room_name);

void create()
{
        set("short", "��¥");
        set("long", @LONG
�������û�д���һ��Ҳû�У���¥��һ�����ı���ڣ�ֻ�������ϣ���Ȼ��
���������һƬ�Ұס��ǻҰ׵�ǽ�Ϻ�Ȼ�Ļ���һֻ�����ӵļ�β���۷�Ķ��룬
��߳����𣬰�߳�أӥ�������ë��ȸ�������ë��ˡ��⣬�ѵ����Ǵ�˵�е�
Ѫū��
LONG
        );
        set("exits", ([ 
		"down": __DIR__"songhouse",
	]));
        set("objects", ([
        	__DIR__"npc/brick": 1,
        ]));
        
        set("item_desc", ([
		"ǽ": "�Ұ׵�ǽ�Ϻ�Ȼ�Ļ���һֻ����ϸ��ȥ��ԼĪ�����糤��ͻ������ڵ�ǽ��֮�⡣\n",
		"��":"�Ұ׵�ǽ�Ϻ�Ȼ�Ļ���һֻ����ϸ��ȥ��ԼĪ�����糤��ͻ������ڵ�ǽ��֮�⡣\n",
		"wall":"�Ұ׵�ǽ�Ϻ�Ȼ�Ļ���һֻ����ϸ��ȥ��ԼĪ�����糤��ͻ������ڵ�ǽ��֮�⡣\n",
		"bird":"�Ұ׵�ǽ�Ϻ�Ȼ�Ļ���һֻ����ϸ��ȥ��ԼĪ�����糤��ͻ������ڵ�ǽ��֮�⡣\n",
		"Ѫū":"�Ұ׵�ǽ�Ϻ�Ȼ�Ļ���һֻ����ϸ��ȥ��ԼĪ�����糤��ͻ������ڵ�ǽ��֮�⡣\n",
	 ]));
	set("brick_out",0);
	set("coor/x",-60);
	set("coor/y",-60);
	set("coor/z",10);
	set("map","taiping");
	setup();
}


void init () {
	add_action("do_pull","pull");
	add_action("do_peep","peep");
}

int do_pull(string arg){
	object me;
	me=this_player();
	if ( arg == "ǽ" || arg =="wall" || arg =="��" || arg =="bird"
		|| arg =="brick" || arg =="ש") {
		message_vision("$Nץ��שҡ��ҡ����������ǽ��֮�ϰ��˳���������֮���������һ�أ�
��ͷȴ�ǰ�߼���һƬѩ�ף�ɢ�������µİ׷���ζ����Ȼ��ˢ���׷۲��á�\n",me);
		message_vision("�Ƿ���ڰγ���֮����ڵ�ǽ��֮�ϱ㿪��һ��������͸��΢���ĵƹ⡣
���̲�ס��չ�ȥ����һ�ۣ�����𣩡�\n",me);
		set("brick_out",1);
		return 1;
	}
	tell_object(me,"��Ҫ��/��ʲô��\n");
	return 1;
}

int do_peep(string arg){
	object me;
	me=this_player();
	if ( !arg || arg == "����" || arg =="��" || arg =="hole") {
		if (!query("brick_out")) {
			tell_object(me,"���뿴ʲô��\n");
			return 1;
		}
		tell_object(me,CYN"ԭ�����������¥Ѫū�����������ŵģ�����\n"NOR);
		tell_object(me, view(__DIR__"birdhouse2"));
		me->set("marks/parrot/�����������",1);
		return 1;
	}
	return 0;
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


void reset()
{

	::reset();
	set("brick_out",0);
	
} 