inherit ROOM;

void create()
{
	set("short", "ɽ�����");

	set("long", @LONG
���������ģ������ȥ�����������Լ�����ָ�����¿Ŀİ��Ҳ��֪��
��ȵ�ʲô�������������Ǿ���������·�ĺá�������ľ����ïʢ����ï������
�������ɡ�����һ���΢�⣬���ƺ������������и�Сľ���ӡ�
LONG);
	set("outdoors", "fugui");
	set("type","road");
	set("exits",([
		"east":__DIR__"shanlin",
		"south":__DIR__"shanlin1",
		"west":__DIR__"shanlin2",
		"north":__DIR__"shanlin3",
	]) );
	set("item_desc", ([
                "����": "����������бб��д�ţ�[��������ץ���������ؼң���������ż��...����]��\n����������������������⣩\n",
                "paizi": "����������бб��д�ţ�[��������ץ���������ؼң���������ż��...����]��\n����������������������⣩\n"
        ]) );
	set("coor/x",10);
	set("coor/y",180);
	set("coor/z",40);
	setup();
}

void init()
{
        add_action("climbing", "climb");
}

int climbing()
{
        object me;
        
        me = this_player();
        message_vision("$Nץ�ŷ�ï�����٣�������˳���������������ȥ��\n", me);
        me->start_busy(2);
        call_out("fliping",2,me);
        me->stop_busy();
        return 1;
}

void fliping(object me)
{
	object room;
	if( !me->is_ghost()) {
		if (me->query("class") == "fugui") {
			room =find_object(__DIR__"damen");
			if(!objectp(room)) {
				room = load_object(__DIR__"damen");
       		}
       	} else {
       		room =find_object(__DIR__"shanlin");
			if(!objectp(room)) {
				room = load_object(__DIR__"shanlin");
			}
		}
		me->move(room);     
		message_vision("$N˳����������������\n", me);  
	}
        return;
}