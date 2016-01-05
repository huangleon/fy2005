inherit ROOM;

void create()
{
	set("short", "ɽ����");
	set("long", @LONG
����Խ��ԽŨ����ʪ������½����ܰ����ɵ����Ա�����������²�����ƽ
����ʯӢ�ң�ɽ���ѵ��˾�ͷ������������Ͽ�ȥ��ɽ�䶸�����������֮������
�ƺ�����������(climb)��ȥ��
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "southdown" : __DIR__"road4",
]));
        set("item_desc", ([
      		"mountain": "ɽ�䶸�����������֮�������ƺ�����������(climb)��ȥ��\n",
      		"ɽ": "ɽ�䶸�����������֮�������ƺ�����������(climb)��ȥ��\n",
      		"up": "ɽ�䶸�����������֮�������ƺ�����������(climb)��ȥ��\n",
        ]) );
	set("outdoors", "taoguan");
	set("coor/x",0);
	set("coor/y",-70);
	set("coor/z",-20);
	setup();
}

void init()
{
	add_action("do_climb", "climb");
}

int do_climb(string arg)
{
        object obj;
        object me;
        if(!arg || arg=="")
        {
                write("��Ҫ��ʲô��\n");
                return 1;
        }
        if( arg == "ɽ" || arg == "mountain" || arg == "up")
        {
        	me = this_player();
        	message_vision("$N��������ɽ����ȥ��\n", me);
        	me->move(__DIR__"ping_tai.c");
        	return 1;
        }
        else
        {
                write("�㲻������"+arg+"\n");
                return 1;
        }
}

