inherit ROOM;

void create()
{
	set("short", "��ʯ��");

	set("long", @LONG
����������ʯ���ɵ�С����������С�ֿ��˲��٣���Ҳ����ƽ����·
������[37m�ľ��[32m�޼����������룬ʱ��ʱ���м������ֵ�����·�ɿ�ĳ������ӡ�
LONG);
	set("outdoors", "fugui");
	set("type","road");
	set("exits",([
		"west":__DIR__"xiaojie4",
		"northeast":__DIR__"shilu2",
	]) );
   	set("item_desc", ([
		"tree": "���ǿøߴ���ľ����֦Ҷïʢ���ƺ�������˽��˧����\n",
		"�ľ��": "���ǿøߴ���ľ����֦Ҷïʢ���ƺ�������˽��˧����\n",
				
    ]) );
	set("coor/x",30);
	set("coor/y",80);
	set("coor/z",0);
	setup();
}

void init ()
{
        add_action ("do_climb", "climb");
}

int do_climb (string arg)
{
	object me,room;
	int move;
	if (!arg || (arg != "tree" && arg != "��"))
		return notify_fail("��Ҫ��ʲô��\n");
	me = this_player();
	move = me->query_skill("move",1);
	if (move < 40)
		return notify_fail("��̫���ˣ���������ȥ������40���Ṧ��\n");
	
	message_vision("$N���˿��������㲢�ã�����������·�ߵĴ�����\n",me);
	room = find_object(__DIR__"tree");
	if(!room)
		room=load_object(__DIR__"tree");
	me->move(room);
        message("vision",me->name()+"����������������",room,me);
	return 1;
}
