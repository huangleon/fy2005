
inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
���������Ϲ�ͺͺ�ģ�����һ���ľ�ʯʲôҲû�С��������ɫ�ƺ�Ҳ�ر�
������������ʹ�˸е������ĻҰ�����������һ���޵ף��������ɵ����ȡ�
LONG
        );
        set("exits", ([ 
  "north" : __DIR__"mroad2",
]));
        set("outdoors", "quicksand");
        set("objects", ([
                __DIR__"npc/poslave" : 2,
        ]) );
        set("item_desc", ([
                "����": "�ȱڲ����ܹ⻬�����ƺ���һ��ϣ��������(climb)��ȥ��\n"
        ]) );


	set("coor/x",-1130);
	set("coor/y",-20);
	set("coor/z",0);
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
        if( arg == "valley" || arg == "down" || arg == "����")
        {
	        me = this_player();
	        if (me->query_temp("climbing")) {
	        	write("���Ѿ������ˡ�\n");
	        	return 1;
	        	}
	        
	        message_vision("$Nץ��ͻ����ʯ�ǣ�������˳�Źȱ�������ȥ��\n", me);
	        me->start_busy(4);
	        call_out("fliping",7,me);
		me->set_temp("climbing",1);
	//      me->stop_busy();
	        return 1;
        }
        else
        {
                write("�㲻������"+arg+"\n");
                return 1;
        }
}
void fliping(object me)
{
	object room;
	if( !me->is_ghost()) {
		room = find_object(__DIR__"valley");
		if(!objectp(room)) room= load_object(__DIR__"valley");
		me->move(room);      
		message_vision("$N˳�Źȱ�����������\n", me); 
	}
	me->delete_temp("climbing");
        return;
}

