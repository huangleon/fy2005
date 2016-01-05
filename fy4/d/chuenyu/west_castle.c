
inherit ROOM;

void create()
{
        set("short", "���ɳǱ�������");
        set("long", @LONG
��վ�ں���ɽ�������ɳǱ������ࡣ���ʵĳ�ǽ�ϳ�������ɫ�����١����ٴ�
ǽ��һֱ������Ľ��¡��������ǵ�������������¡��������ǳǱ������š�
LONG
        );
        set("exits", ([
                "east" : __DIR__"gate_castle",
        ]));
        set("item_desc", ([
                "wall": "��ǽ�䶸�������������١����ƺ�����������(climb)��ȥ��\n",
		"��ǽ": "��ǽ�䶸�������������١����ƺ�����������(climb)��ȥ��\n",
		"����": "���ٳ����˳�ǽ�����ƺ�����������(climb)��ȥ��\n"	
        ]) );
       set("outdoors", "chuenyu");

	set("coor/x",-10);
	set("coor/y",-10);
	set("coor/z",10);
	setup();
}

void init()
{
	add_action("climbing", "climb");
}

int climbing(string arg)
{
	object obj;
	object me;
	if(!arg || arg=="")
	{
		write("��Ҫ��ʲô��\n");
		return 1;
	}
	if( arg == "wall" || arg == "����" || arg == "��ǽ")
	{
		me = this_player();
		if (me->query_temp("climbup"))
			{
				write("���Ѿ������ˡ�\n");
				return 1;
			}	
	        message_vision("$Nץ�����٣�������˳�ų�ǽ������ȥ��\n", me);
		me->start_busy(3);
		call_out("fliping",3,me);
		me->set_temp("climbup",1);
//		me->stop_busy();
		return 1;
	}
	else
	{
		write("�㲻������"+arg+"\n");
		return 1;
	}
}

int fliping(object me)
{
	if(!me->is_ghost()){
	        me->move(__DIR__"west_garden.c");
	        message_vision("$N����һ��ǽͷ�������ɵ����˹�����\n", me);
	}
	me->delete_temp("climbup");
	return 1;
}
