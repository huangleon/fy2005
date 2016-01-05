// work.c
//#include "/feature/damage.c"

inherit ROOM;

void create()
{
        set("short", "ʯ��");
        set("long", @LONG
ǡ�˲���ɽʢ�������ϵ�ʯ�ϡ����������������ܶ��˶���������Ͷ��š���
�Լ��ĺ�ˮȥ��ȡһЩ���롣ÿ�������﹤�����˶������õ�һ�ݺܹ�ƽ�ı��ꡣ
���������ææµµ�Ĺ����ţ��ſڹ���һ������[37m(sign)[32m��
LONG
        );

    set("exits", ([ /* sizeof() == 1 */
		"west" : __DIR__"stoneroad",
		"north" : __DIR__"octo5",
		"south" : __DIR__"birdroad",
	]));
        set("outdoors", "guanwai");

        set("item_desc", ([
                "sign": @TEXT
��������ȱ���֣������Ӷһ���̹����ɻ

work     ��ʼ������

TEXT
		
        ]) );
	set("coor/x",0);
	set("coor/y",-30);
	set("coor/z",0);
	setup();
}


void init()
{
        add_action("do_work", "work");
}

void	reset() {
		set("worked",0);
		::reset();
}

int do_work(string arg)
{
        object ob;
        object me;

		if (query("worked")> 20)
			return notify_fail("����ʯͷ�����ˣ��������ɡ�\n");
			
        me = this_player();
		if(me->is_busy()) return notify_fail("��Ķ�����û����ɣ����ܹ�����\n");
		message_vision("$N����Ĺ������ڽ����ˣ�����Ҳ�۵�Ҫ����\n", me);
		add("worked",1);
		me->receive_wound("gin",30,me);
		me->receive_wound("sen",30, me);
//		me->status_msg("all");
		me->set_temp("last_damage_from","��ǡ�˲���ɽ��ʯ���ɻ����۹��ȶ�����\n");
		ob = new("/obj/money/silver");
		if (!ob->move(me))
			ob->move(environment(me));
		message_vision("�ϰ��$N˵��������Ĺ�Ǯ��\n", me);
		me->perform_busy(2);
		return 1;
}
