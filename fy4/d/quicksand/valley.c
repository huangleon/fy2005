
inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
������һ��������ʵ�����أ������ͱ���������ݲ����������м�ֻ����ӿ�
���ӹ�����������������ȫ�����������˾�����ǣ������Ȼ��һ��СС��é�ݣ�
�����Ȼ������ס�š�
LONG
        );
        set("outdoors", "quicksand");
        set("objects", ([
                __DIR__"npc/redlama" : 1,
        ]) );

	set("coor/x",-1130);
	set("coor/y",-20);
	set("coor/z",-10);
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
        if( arg == "valley" || arg == "up" || arg == "����")
        {
        me = this_player();
        if (me->query_temp("climbup")) {
	        	write("���Ѿ������ˡ�\n");
	        	return 1;
	        	}
        message_vision("$Nץ��ͻ����ʯ�ǣ�������˳�Źȱ�������ȥ��\n", me);
        me->start_busy(2);
        call_out("fliping",2,me);
//      me->stop_busy();
	me->set_temp("climbup",1);
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
        room = find_object(__DIR__"cliff");
	if(!objectp(room)) room= load_object(__DIR__"cliff");
	me->move(room);     
	message_vision("$N˳�Źȱ�����������\n", me);  
	}
        me->delete_temp("climbup");
        return;
}

