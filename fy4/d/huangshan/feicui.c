// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "����");
        set("long", @LONG
���ɹ�Ϫ�ߣ������岼��������̶��ƽʱ̶ˮ�峺ƽ����ÿ��΢�紵��������
΢�����������ۣ����Խ���̶������ˮɫ��Ϊ�࣬�࣬�ڣ��ף��ϣ�����һ̶��ˮ
�����������Ա���Ϊ���ء�����ʯ����ʯ����������̣�Ӧ�о��У����з�ζ��
��˵�������µ�����������������̶�����Ҳ��֪��١�
LONG
        );
    set("exits", ([ 
		"east" : __DIR__"sroad",
	]));
    set("objects", ([
        __DIR__"obj/pond1" : 1,
        __DIR__"obj/pond2" : 1,
        __DIR__"obj/pond3" : 1,
        __DIR__"obj/pond4" : 1,
        __DIR__"obj/pond5" : 1,
        __DIR__"obj/pond6" : 1,
    ]) );
	set("turtle_home", 1);
    set("outdoors", "huangshan");
	set("coor/x",-150);
	set("coor/y",-30);
	set("coor/z",30);
	setup();
}

int release_turtle(object turtle) {
	if(turtle->name() != "��ëС�ڹ�") {
		return 0;
	}
	call_out("turtle_return", random(30) + 10, this_player());
	return 1;
}

void turtle_return(object me) {
	object ob;
	
	if(environment(me) == this_object()) {
		message("vision", "\n\n��ëС�ڹ�������������������Ͼ�Ȼ����һ�����ӡ� \n", this_object());
		message("vision", "��ëС�ڹ�Ѻ����������رߣ�Ȼ��Ǳ��ˮ�ﲻ���ˡ� \n", this_object());
		me->delete_temp("marks/search_turtle");		// If they don't get the box, let them search again.
		ob = new(__DIR__"obj/box");
		if(objectp(ob)) {
			ob->set("box_owner", me);
			ob->move(this_object());
		}	
		REWARD_D->riddle_done(me,"����֮��",50,1);
		log_file("riddle/RIDDLE_LOG",
			sprintf("%s(%s) �ҿ���ëС�ڹꡣ %s \n",
				me->name(1), geteuid(me), ctime(time()) ));
	}
}

