inherit ROOM;

void create()
{
        set("short", "�ľ����");
        set("long", @LONG
�����������ܿ����������һ�ж������۵ס������ƺ��Ǹ�[37mԺ��[32m��
LONG
        );
        set("outdoors", "fugui");
        set("objects", ([
        	__DIR__"npc/bird":2,
        ]) );
        set("exits", ([ 
  		"down" : __DIR__"shilu1",
	]));
	set("item_desc", ([
        "��": "��Ҷ��ס��������ߣ������ƺ��Ǹ�Ժ�ӡ�\n",
        "tree": "��Ҷ��ס��������ߣ������ƺ��Ǹ�Ժ�ӡ�\n",
        "Ժ��": "��Ҷ��ס��������ߣ�ֻ��ʩչ�Ṧײײ�����ˡ�����������\n",
        "yard": "��Ҷ��ס��������ߣ�ֻ��ʩչ�Ṧײײ�����ˡ�����������\n",
	]) );
	set("coor/x",30);
	set("coor/y",80);
	set("coor/z",10);
        setup();
}

void init ()
{
        add_action ("do_jumpto", "jumpto");
}

int do_jumpto (string arg)
{
        object me,room;
		int dodge;
		if (!arg || (arg != "yard" && arg != "Ժ��"))
			return notify_fail("��Ҫ����������\n");
		
		me = this_player();
		dodge = me->query_skill("move",1);
		message_vision("\n$N���������������۾����͵��������˳�ȥ....\n",me); 
		if(!room)
			room = find_object(__DIR__"jinyuan");
			room=load_object(__DIR__"jinyuan");
		if (dodge < 50)
		{
			message_vision("\nֻ��һ������˺�Ѻ���֦�۶ϵ�������Ȼ��$N���ص�ˤ���˵���...\n\n",me);
			me->move(room);
			me->unconcious();
		}
		else
		{
			message_vision("\n$N������֦����֮������Խ�˴Դ���Ҷ��һ�������˽𸮴�Ժ��\n\n",me);
	        me->move(room);
	        me->start_busy(1);
		}
		return 1;
}
