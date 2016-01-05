inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "����");
        set("long", @LONG
������һƬ��ڣ�������Ҷ������������Ҳ������ҹ�����ְ�����������⡣
�ߴ�������������衣��ή���ӵİ������ֱ�϶����ɪɪ�����������Ұ���ں���
�������Ƶ������ζ�����ç������չ����������˳��ۣ���צ���ˡ�
LONG
        );
        set("exits", ([ 
		"northwest" : __DIR__"forest3",
		"southeast":	__DIR__"v_gate",
	]));
        set("objects", ([
	]) );
	set("item_desc", ([
		"tree": "�ߴ����ľ��û��һ���Ĺ�������������ȥ��\n",
		"����":  "�ߴ����ľ��û��һ���Ĺ�������������ȥ��\n",
		"��":   "�ߴ����ľ��û��һ���Ĺ�������������ȥ��\n",
		"����": "ï�ܵİ������ڵ��Ͻ�֯������ʹ�˼����������Ų���\n",
		"bush": "ï�ܵİ������ڵ��Ͻ�֯������ʹ�˼����������Ų���\n",
		"vine": "ï�ܵİ������ڵ��Ͻ�֯������ʹ�˼����������Ų���\n",
	
	]) );
	set("outdoors", "zangbei");
        set("coor/x",-1560);
        set("coor/y",620);
        set("coor/z",0);
	set("map","zbwest");
	set("bandit",2);
	setup();
}


void init(){

	add_action("do_climb","climb");
}

void reset()
{
	object killer;
        ::reset();
        set("bandit",2);
        killer = present("bandit", this_object());
        if (killer && !userp(killer))
        if (!killer->is_fighting()) {
        	destruct(killer);
	}
}


int do_climb(string arg){

	object me,room;
	me=this_player();
	if (!arg || (arg!="tree" && arg!="��")) 
		return 0;
	if (me->is_busy())
		return notify_fail("��������æ��\n");
	room=find_object(__DIR__"tree1");
	if (!objectp(room)) room=load_object(__DIR__"tree1");
	message_vision("$N�ֽŲ��ã����������������ȥ��\n",me);
        tell_room(room, this_player()->name() + "����������������\n");
        this_player()->move(room);
        return 1;
}


int valid_leave(object obj, string dir){
	object another;
	seteuid(getuid());
	
	if(dir == "southeast"){
		if (present("bandit", this_object()))
		{
			another = present("bandit", this_object());
			return notify_fail(another->name()+"����ס�����·��\n");
		} else if (random(10)>5 && query("bandit")>0) {
			another = new(__DIR__"npc/bandit1");
			another->move(environment(obj));
			message_vision(HIB"��Ҷ������һ�����죬����һ��������\n"NOR, obj);	
			add("bandit",-1);
			return notify_fail(another->name()+"�ȵ���ʲô�˸�˽��������կ����������\n");
		}
	}	
	return 1;
}